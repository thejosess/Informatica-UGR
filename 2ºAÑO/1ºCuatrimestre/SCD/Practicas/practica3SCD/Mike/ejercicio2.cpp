

#include <iostream>
#include <thread> // this_thread::sleep_for
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include <mpi.h>

using namespace std;
using namespace std::this_thread ;
using namespace std::chrono ;

const int		//constantes
	tam_vector	= 10 ,
	etiq_prod	= 1 ,
	etiq_cons	= 2 ;

int 			// variables globales no constantes
	num_procesos 	= 10,
	num_prod	= (num_procesos - 2) / 2,	// número de procesos productores
	num_cons	= num_prod ,			// número de procesos consumidores
	num_items	= num_prod * num_cons ,		// número de items
	id_buffer	= num_prod + num_cons - 1 ,	// id del proceso buffer
	id_controlador	= id_buffer + 1 ;		// id del proceso controlador

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
// producir produce los numeros en secuencia (1,2,3,....)
// y lleva espera aleatorio
int producir(int numero_orden)
{
	int valor_cada_productor = num_items / num_prod;	// Número de items para cada productor
	static int contador = numero_orden * valor_cada_productor;	
	// Cada productor empieza su contador en un valor distinto (ik)
	sleep_for( milliseconds( aleatorio<10,100>()) );
	contador++ ;
	cout << "Productor ha producido valor " << contador << endl << flush;
	return contador ;
}
// ---------------------------------------------------------------------

void funcion_productor(int numero_orden)
{

	MPI_Status estado ;
	for ( int i= 0 ; i < num_items / num_prod ; i++ )
	{
		// producir valor
		int valor_prod = producir(numero_orden);
		// envío al controlador mensaje de que ha producido un dato
		MPI_Ssend( &valor_prod, 1, MPI_INT, id_controlador, etiq_prod, MPI_COMM_WORLD);
		//recibe mensaje del controlador de que ha recibido el dato
		MPI_Recv ( &valor_prod, 1, MPI_INT, id_controlador, etiq_prod, MPI_COMM_WORLD, &estado );

		// enviar valor al buffer
		MPI_Ssend( &valor_prod, 1, MPI_INT, id_buffer, etiq_prod, MPI_COMM_WORLD );
	}
}
// ---------------------------------------------------------------------

void consumir( int valor_cons )
{
	// espera bloqueada
	sleep_for( milliseconds( aleatorio<110,200>()) );
	cout << "Consumidor ha consumido valor " << valor_cons << endl << flush ;
}
// ---------------------------------------------------------------------

void funcion_consumidor(int numero_orden)
{
	int	peticion,
		valor_rec = 1 , 
		valor_prod = 0;
	MPI_Status estado ;

	for( int i=0 ; i < num_items / num_cons; i++ )
	{
		// envía petición para consumir
		MPI_Ssend( &peticion,  1, MPI_INT, id_buffer, etiq_cons, MPI_COMM_WORLD);
		// recibe el dato a consumir
		MPI_Recv ( &valor_rec, 1, MPI_INT, id_buffer, etiq_cons, MPI_COMM_WORLD, &estado );

		// envío al controlador mensaje de que ha recibido un dato
		MPI_Ssend( &valor_prod, 1, MPI_INT, id_controlador, etiq_cons, MPI_COMM_WORLD);
		
		consumir( valor_rec );
	}
}
// ---------------------------------------------------------------------

void funcion_buffer()
{
	int	buffer[tam_vector],	// buffer con celdas ocupadas y vacías
		valor,			// valor recibido o enviado
		primera_libre	  = 0 ,	// índice de primera celda libre
		primera_ocupada	  = 0 ,	// índice de primera celda ocupada
		num_celdas_ocupadas = 0,// número de celdas ocupadas
		etiq_emisor ;		// tag del emisor aceptable
	MPI_Status estado ;		// metadatos del mensaje recibido

	for( int i=0 ; i < num_items*2 ; i++ )
	{
		// 1. determinar si puede enviar solo prod., solo cons, o todos

		if ( num_celdas_ocupadas == 0 )					// si buffer vacío
			etiq_emisor = etiq_prod ;					// $~~~$ solo prod.
		else if ( num_celdas_ocupadas == tam_vector ) 	// si buffer lleno
			etiq_emisor = etiq_cons ;					// $~~~$ solo cons.
		else
			etiq_emisor = MPI_ANY_TAG ;					// $~~~$ cualquiera
		

		// 2. recibir un mensaje del emisor o emisores aceptables

		MPI_Recv( &valor, 1, MPI_INT, MPI_ANY_SOURCE, etiq_emisor, MPI_COMM_WORLD, &estado );

		// 3. procesar el mensaje recibido
		switch( estado.MPI_TAG ) // leer emisor del mensaje en metadatos
		{
			case etiq_prod: // si ha sido el productor: insertar en buffer
				buffer[primera_libre] = valor ;
				primera_libre = (primera_libre+1) % tam_vector ;
				num_celdas_ocupadas++ ;
				cout << "Buffer ha recibido valor " << valor << endl ;
				break;

			case etiq_cons: // si ha sido el consumidor: extraer y enviarle
				valor = buffer[primera_ocupada] ;
				primera_ocupada = (primera_ocupada+1) % tam_vector ;
				num_celdas_ocupadas-- ;
				cout << "Buffer va a enviar valor " << valor << endl ;
				MPI_Ssend( &valor, 1, MPI_INT, estado.MPI_SOURCE, etiq_cons, MPI_COMM_WORLD);
				break;
		}
	}
}

// ---------------------------------------------------------------------

void funcion_controlador()
{
	int valor_rec ;
	MPI_Status estado ;

	for ( int i= 0 ; i < num_items * 2 ; i++ )
	{
		// recibe un valor de forma síncrona de un productor o un consumidor
		MPI_Recv( &valor_rec, 1, MPI_INT, id_controlador, MPI_ANY_TAG, MPI_COMM_WORLD, &estado );

		switch( estado.MPI_TAG ) // leer emisor del mensaje en metadatos
		{
			case etiq_prod: // si ha sido el productor
				cout << "Productor (" << estado.MPI_SOURCE << ") va a enviar valor " << valor_rec << endl << flush;
				MPI_Ssend( &valor_rec, 1, MPI_INT, id_controlador, etiq_prod, MPI_COMM_WORLD);
				break;

			case etiq_cons: // si ha sido el consumidor
				cout << "Consumidor (" << estado.MPI_SOURCE << ") ha recibido valor " << valor_rec << endl << flush ;	
				MPI_Ssend( &valor_rec, 1, MPI_INT, id_controlador, etiq_cons, MPI_COMM_WORLD);
				break;
		}
	}
}
// ---------------------------------------------------------------------


int main( int argc, char *argv[] )
{
	int 	id_propio, 
		//N ,		
		num_procesos_actual; 
		

	// inicializar MPI, leer identif. de proceso y número de procesos
	MPI_Init( &argc, &argv );
	MPI_Comm_rank( MPI_COMM_WORLD, &id_propio );
	MPI_Comm_size( MPI_COMM_WORLD, &num_procesos_actual );

	// No funciona la parte de elegir el número de procesos...
	/*cout << "Introduzca el número de procesos (debe ser par y >= 10)" << endl;	
	cin >> N ;
	num_procesos = N ;*/

	if( (num_procesos % 2 == 0) && (num_procesos >= 10) ){
		if ( (num_procesos == num_procesos_actual) )
		{
			// ejecutar la operación apropiada a 'id_propio'
			if ( id_propio < num_prod ){
				funcion_productor(id_propio);
			}
			else if ( id_propio == id_buffer ){
				funcion_buffer();
			}
			else if ( id_propio == id_controlador ){
				funcion_controlador();
			}
			else{
				funcion_consumidor(id_propio - num_prod -2);
			}
			
		}
		else
		{
			if ( id_propio == 0 ){ // solo el primero escribe error, indep. del rol
				cout << "el número de procesos esperados es:    " << num_procesos << endl
				     << "el número de procesos en ejecución es: " << num_procesos_actual << endl
				     << "(programa abortado)" << endl ;
			}
		}
	}
	else{
		if ( id_propio == 0 ){ // solo el primero escribe error, indep. del rol
			cout << "el número de procesos esperados no es par o es menor que 10:    " << num_procesos << endl
			     << "(programa abortado)" << endl ;
		}
	}

	// al terminar el proceso, finalizar MPI
	MPI_Finalize( );
	return 0;
}
