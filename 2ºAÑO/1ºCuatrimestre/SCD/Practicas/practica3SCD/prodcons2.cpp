// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// Práctica 3. Implementación de algoritmos distribuidos con MPI
//
// Archivo: prodcons2.cpp
// Implementación del problema del productor-consumidor con
// un proceso intermedio que gestiona un buffer finito y recibe peticiones
// en orden arbitrario
// (versión con un único productor y un único consumidor)
//
// Historial:
// Actualizado a C++11 en Septiembre de 2017
// -----------------------------------------------------------------------------

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



const int   //constantes configurables
  tam_vector   = 10,
  num_items  = 20,
  num_productores  = 4,
  num_consumidores = 5;

//#define Consumidor  5 

const int
  etiq_productores     = 1,
  etiq_consumidores   = 2;

const int
  id_productor_min  = 0,
  id_productor_max  = id_productor_min + num_productores -1,
  id_buffer   = id_productor_max + 1,
  id_consumidor_min = id_buffer + 1,
  id_consumidor_max = id_consumidor_min + num_consumidores - 1,
  num_procesos_esperado = id_consumidor_max + 1;

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
   for ( unsigned int i= 0 ; i < num_items /num_productores ; i++ )  //duda en num_items
   {
      // producir valor
      int valor_prod = producir(num_productor);
      // enviar valor
      cout << BLUE << "Productor " << num_productor << " va a enviar valor " << valor_prod << endl << flush;
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
      MPI_Ssend( &peticion,  1, MPI_INT, id_buffer, etiq_consumidores, MPI_COMM_WORLD);
      MPI_Recv ( &valor_rec, 1, MPI_INT, id_buffer, 0, MPI_COMM_WORLD,&estado ); // donde pone 0 ponerMPI_ANY_SOURCE duda
      cout << YELLOW << "Consumidor " << num_consumidor <<  " ha recibido valor " << valor_rec << endl << flush ;
      consumir( valor_rec );
   }
}
// ---------------------------------------------------------------------

void funcion_buffer()
{
   int        buffer[tam_vector],      // buffer con celdas ocupadas y vacías
              valor,                   // valor recibido o enviado
              primera_libre       = 0, // índice de primera celda libre
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
            primera_libre++ ;
            num_celdas_ocupadas++ ;
            cout << GREEN << "Buffer ha recibido valor " << valor << endl ;
            break;

         case etiq_consumidores: // si ha sido el consumidor: extraer y enviarle
            valor = buffer[primera_libre - 1] ;
            primera_libre-- ;
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
   int id_propio, num_procesos_actual;

   // inicializar MPI, leer identif. de proceso y número de procesos
   MPI_Init( &argc, &argv );
   MPI_Comm_rank( MPI_COMM_WORLD, &id_propio );
   MPI_Comm_size( MPI_COMM_WORLD, &num_procesos_actual );

   if ( num_procesos_esperado == num_procesos_actual )
   {
      // ejecutar la operación apropiada a 'id_propio'
      if ( id_productor_min <= id_propio && id_propio <= id_productor_max )
         funcion_productor(id_propio);
      else if ( id_consumidor_min  <= id_propio && id_propio <= id_consumidor_max )
         funcion_consumidor(id_propio - id_consumidor_min);
      else
         funcion_buffer();
   }
   else
   {
      if ( id_propio == 0 ) // solo el primero escribe error, indep. del rol
      { cout << "el número de procesos esperados es:    " << num_procesos_esperado << endl
             << "el número de procesos en ejecución es: " << num_procesos_actual << endl
             << "(programa abortado)" << endl ;
      }
   }

   // al terminar el proceso, finalizar MPI
   MPI_Finalize( );
   return 0;
}
