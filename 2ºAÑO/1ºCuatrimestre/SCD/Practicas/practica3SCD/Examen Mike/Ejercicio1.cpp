/*
  Numero de procesos por pantalla la cantidad(MAL)
  numero de procesos par y mayor igual que 10
  si lo hace mal y no mete eso pues que uno de los procesos y de un error
  otra funcion nueva que se llama controlador y este recibe una peticion de consumido
  y producto y los mensajes de ahi cout los hace el controlador
  el numero de productores tiene que ser num_procesos -2 /2
  el numoer de consumidor igual al numero de productor 
  el numero  de items tiene que ser el numero de prod * consumidores
  el productor despues de producir llama al controlador y luego al buffer
  consumidor justo antes de consumir lo mismo que arriba
  tanto el producor como el consudmir despues de enviarle al controlador
  y haga el cout no puede hacer nada hasta que el controlador lo mande
  PROBE

  utilizando el ejercicio 2 el eje 3 el contorlador tiene que llevar la cuneta de cuantos prod
  y consumidr y la cuenta y si la cuenta de prod - cons es menor igual o 3 solo puede
  aceptar productores y si no cualquiera

  el controlador hace un bucle finito hasta el numero de item * 2

  utilizando el 2 haces el 4 como el controlador tiene que comprobar que lo que le mande
  comprobar que si hya peticiones del consumidr y si hay las pillas antes del productor
  IPROBE

  funcion buffer 
  poner numero de productores + numero de consumidores y mirar 
*/


//FIFO

#define GREEN    "\033[32m"
#define BLUE     "\033[34m"
#define YELLOW   "\033[33m"
#define WHITE    "\033[37m"
#define RED      "\033[31m"
#define MAGENTA  "\033[35m"

#include <iostream>
#include <thread> // this_thread::sleep_for
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include <mpi.h>

using namespace std;
using namespace std::this_thread ;
using namespace std::chrono ;

int 
num_productores = 0,
num_consumidores = 0 ,
num_procesos_esperado = 0 ;

 int		//constantes configurables
	tam_vector	 = 10,
  num_items = 0 ;

const  int
	etiq_productores     = 1,
  etiq_consumidores   = 2;

 int
	id_productor_min,
	id_productor_max,	
	id_buffer,	
	id_consumidor_min,	
	id_consumidor_max,
  id_controlador;

//**********************************************************************
// plantilla de función para generar un entero aleatorio uniformemente
// distribuido entre dos valores enteros, ambos incluidos
// (ambos tienen que ser dos constantes, conocidas en tiempo de compilación)
//----------------------------------------------------------------------

template< int min, int max > int aleatorio()
{
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}
// ---------------------------------------------------------------------
// ptoducir produce los numeros en secuencia (1,2,3,....)
// y lleva espera aleatorio
int producir(int numero)
{
   int valor_cada_productor = num_items/num_productores;
   static int contador = numero * valor_cada_productor ;
   //productor empiza con valor distinto
   sleep_for( milliseconds( aleatorio<10,100>()) );
   contador++ ;
   cout << MAGENTA << "Productor ha producido valor " << contador << endl << flush;
   return contador ;
}
// ---------------------------------------------------------------------

void funcion_productor(int num_productor)
{
  MPI_Status estado;

   for ( unsigned int i= 0 ; i < num_items /num_productores ; i++ )  //duda en num_items
   {
      // producir valor
      int valor_prod = producir(num_productor);
      // enviar valor
      MPI_Ssend( &valor_prod, 1, MPI_INT, id_controlador, etiq_productores, MPI_COMM_WORLD);
      MPI_Probe(MPI_ANY_SOURCE, etiq_productores, MPI_COMM_WORLD, &estado);
      //    MPI_Recv ( &valor_prod, 1, MPI_INT, id_controlador, etiq_prod, MPI_COMM_WORLD, &estado );
      cout << BLUE << "Productor " << num_productor << endl << flush;

      MPI_Ssend( &valor_prod, 1, MPI_INT, id_buffer, etiq_productores, MPI_COMM_WORLD );
   }
}
// ---------------------------------------------------------------------

void consumir( int valor_cons )
{
   // espera bloqueada
   sleep_for( milliseconds( aleatorio<110,200>()) );
   cout << WHITE <<  "Consumidor ha consumido valor " << valor_cons << endl << flush ;
}
// ---------------------------------------------------------------------

void funcion_consumidor(int num_consumidor)   
{
   int         peticion,
               valor_rec = 1 ;
   MPI_Status  estado ;

   for( unsigned int i=0 ; i < num_items / num_consumidores; i++ ) //duda en num_items
   {

      //en el send no le envias nada con peticion ya que solo lo usas para avisarlo
      MPI_Ssend( &peticion,  1, MPI_INT, id_buffer, etiq_consumidores, MPI_COMM_WORLD);
      MPI_Probe(MPI_ANY_SOURCE, etiq_consumidores, MPI_COMM_WORLD, &estado);
      cout << YELLOW << "Consumidor " << num_consumidor << endl << flush ;


      MPI_Recv ( &valor_rec, 1, MPI_INT, id_buffer, 0, MPI_COMM_WORLD,&estado ); // donde pone 0 ponerMPI_ANY_SOURCE duda
      MPI_Ssend( &valor_rec, 1, MPI_INT, id_controlador, etiq_consumidores, MPI_COMM_WORLD);
      consumir( valor_rec );
   }
}

void funcion_controlador()
{
  MPI_Status estado;
  int tag_emisor_aceptable, valor, etiq;
  int buffer[tam_vector],      // buffer con celdas ocupadas y vacías
      primera_libre       = 0, // índice de primera celda libre
      primera_ocupada     = 0, // índice de primera celda ocupada
      num_celdas_ocupadas = 0; // número de celdas ocupadas

  MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &estado);

  MPI_Recv( &valor, 1, MPI_INT, id_controlador, MPI_ANY_TAG, MPI_COMM_WORLD, &estado );

  switch(estado.MPI_TAG)
  {
    case etiq_consumidores: 
      cout << YELLOW << "Consumidor esta consumiendo el valor  " << valor << endl << flush ;
      MPI_Ssend(&valor, 1, MPI_INT, MPI_ANY_SOURCE, etiq_consumidores, MPI_COMM_WORLD);
      break;
    
    case etiq_productores:
      cout << BLUE << "Productor va a producir el valor " << valor << endl << flush;
      MPI_Ssend(&valor, 1, MPI_INT, MPI_ANY_SOURCE, etiq_productores, MPI_COMM_WORLD);
      break;
  }
}


// ---------------------------------------------------------------------

void funcion_buffer()
{
   int        buffer[tam_vector],      // buffer con celdas ocupadas y vacías
              valor,                   // valor recibido o enviado
              primera_libre       = 0, // índice de primera celda libre
              primera_ocupada     = 0, // índice de primera celda ocupada
              num_celdas_ocupadas = 0, // número de celdas ocupadas
              tag_emisor_aceptable ;    // identificador de emisor aceptable
   MPI_Status estado ;                 // metadatos del mensaje recibido

   for( unsigned int i=0 ; i < num_items*2 ; i++ )
   {
      // 1. determinar si puede enviar solo prod., solo cons, o todos

      if ( num_celdas_ocupadas == 0 )               // si buffer vacío
         tag_emisor_aceptable = etiq_productores ;       // $~~~$ solo prod.
      else if ( num_celdas_ocupadas == tam_vector ) // si buffer lleno
         tag_emisor_aceptable = etiq_consumidores ;      // $~~~$ solo cons.
      else
      {    
        MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &estado);
        tag_emisor_aceptable = estado.MPI_TAG ;  // $~~~$ cualquiera  // $~~~$ cualquiera
      }

      // 2. recibir un mensaje del emisor o emisores aceptables

      MPI_Recv( &valor, 1, MPI_INT, MPI_ANY_SOURCE, tag_emisor_aceptable, MPI_COMM_WORLD, &estado );

      // 3. procesar el mensaje recibido

      switch(tag_emisor_aceptable) // leer emisor del mensaje en metadatos
      {
         case etiq_productores: // si ha sido el productor: insertar en buffer
            buffer[primera_libre] = valor ;
            primera_libre = (primera_libre+1) % tam_vector ;
            num_celdas_ocupadas++ ;
            cout << GREEN << "Buffer ha recibido valor " << valor << endl ;
            break;

         case etiq_consumidores: // si ha sido el consumidor: extraer y enviarle
            valor = buffer[primera_ocupada] ;
            primera_ocupada = (primera_ocupada+1) % tam_vector ;
            num_celdas_ocupadas-- ;
            cout <<  RED <<"Buffer va a enviar valor " << valor << endl ;
            MPI_Ssend( &valor, 1, MPI_INT, estado.MPI_SOURCE, 0, MPI_COMM_WORLD);
            // LA DUDA ES CON EL 0 DE ALGUNOS SSEND EN TAG
            break;
      }
   }
}

// ---------------------------------------------------------------------

int main( int argc, char *argv[] )
{
  int id_propio = 0, num_procesos_actual;
  //num_procesos_esperado = argv[2];


   // inicializar MPI, leer identif. de proceso y número de procesos
   MPI_Init( &argc, &argv );
   MPI_Comm_rank( MPI_COMM_WORLD, &id_propio );
   MPI_Comm_size( MPI_COMM_WORLD, &num_procesos_actual );

  num_procesos_esperado = num_procesos_actual;

  if(id_propio == 0)
  {
     if(num_procesos_esperado % 2 != 0 && num_procesos_esperado < 10)
     {
        cerr << "Error, proceso abortado\n" << endl;
        return 1;
     }  
  }
    //numero procesos = 10( desde 0 hasta 9 )
    num_productores = (num_procesos_esperado - 2) / 2; // 4
    num_consumidores = num_productores ; // 4
    num_items  = num_productores * num_consumidores; // 16

    id_productor_min  = 0; 
    id_productor_max  = id_productor_min + num_productores -1; //3
    id_buffer   = id_productor_max + 1; // 4
    id_consumidor_min = id_buffer + 1; // 5
    id_consumidor_max = id_consumidor_min + num_consumidores - 1; // 8
    id_controlador = id_consumidor_max + 1; //9

      // ejecutar la operación apropiada a 'id_propio'
      if ( id_productor_min <= id_propio && id_propio <= id_productor_max )
         funcion_productor(id_propio);
      else if ( id_consumidor_min  <= id_propio && id_propio <= id_consumidor_max )
         funcion_consumidor(id_propio - id_consumidor_min);
      else
        if(id_propio == id_controlador)
        funcion_controlador();    
      else
        funcion_buffer();     

   // al terminar el proceso, finalizar MPI
   MPI_Finalize( );
   return 0;
}
