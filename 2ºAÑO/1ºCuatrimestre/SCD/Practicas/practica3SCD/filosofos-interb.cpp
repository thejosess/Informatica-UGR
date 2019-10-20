// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// Práctica 3. Implementación de algoritmos distribuidos con MPI
//
// Archivo: filosofos-interb.cpp
// Implementación del problema de los filósofos (sin camarero).
//
// Autor: Jose Santos Salvador
//
// Fecha: 13/12/18
// -----------------------------------------------------------------------------

#include <mpi.h>
#include <thread> 
#include <random> 
#include <chrono> 
#include <iostream>

using namespace std;
using namespace std::this_thread ;
using namespace std::chrono ;

const int
   num_filosofos = 5 ,
   num_procesos  = 2*num_filosofos ;


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

int aleatorio2()
{
    int numero = rand()%9;
    if(numero % 2 == 0)
      return numero;
    else
      return numero + 1;
}

// ---------------------------------------------------------------------

void funcion_filosofos( int id )
{
  int id_ten_izq = (id+1)              % num_procesos, //id. tenedor izq.
      id_ten_der = (id+num_procesos-1) % num_procesos; //id. tenedor der.

  while ( true )
  {

  	if(id == aleatorio2())    //forma de evitar el interblqueo // y que sea justo para todos                                           
  	{
	    cout <<"Filósofo " <<id <<" solicita ten. der." <<id_ten_der <<endl;
	    MPI_Ssend(NULL, 0, MPI_INT,id_ten_der , 1, MPI_COMM_WORLD);

	    sleep_for( milliseconds( aleatorio<10,100>() ) );
	    //provocacion de interbloqueo para comprobar su uso

	    cout <<"Filósofo " <<id << " solicita ten. izq." <<id_ten_izq <<endl;
	    MPI_Ssend(NULL, 0, MPI_INT, id_ten_izq, 1, MPI_COMM_WORLD);
  	}
  	else
  	{
	    cout <<"Filósofo " <<id << " solicita ten. izq." <<id_ten_izq <<endl;
	    MPI_Ssend(NULL, 0, MPI_INT, id_ten_izq, 1, MPI_COMM_WORLD);

	    sleep_for( milliseconds( aleatorio<10,100>() ) );
	    //con esto se provoca el interbloqueo

	    cout <<"Filósofo " <<id <<" solicita ten. der." <<id_ten_der <<endl;
	    MPI_Ssend(NULL, 0, MPI_INT,id_ten_der , 1, MPI_COMM_WORLD);
	 }

    cout <<"Filósofo " <<id <<" comienza a comer" <<endl ;
    sleep_for( milliseconds( aleatorio<10,100>() ) );

    cout <<"Filósofo " <<id <<" suelta ten. izq. " <<id_ten_izq <<endl;
    MPI_Ssend(NULL, 0, MPI_INT, id_ten_izq, 0, MPI_COMM_WORLD);

    cout<< "Filósofo " <<id <<" suelta ten. der. " <<id_ten_der <<endl;
    MPI_Ssend(NULL, 0, MPI_INT, id_ten_der, 0, MPI_COMM_WORLD);

    cout << "Filosofo " << id << " comienza a pensar" << endl;
    sleep_for( milliseconds( aleatorio<10,100>() ) );
 }
}
// ---------------------------------------------------------------------

void funcion_tenedores( int id )
{
  int valor, id_filosofo ;  // valor recibido, identificador del filósofo
  MPI_Status estado ;       // metadatos de las dos recepciones

  while ( true )
  {
     MPI_Recv(&valor, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &estado);
     id_filosofo=estado.MPI_SOURCE; // Obtiene el rank del filosofo
     cout <<"Ten. " <<id <<" ha sido cogido por filo. " <<id_filosofo <<endl;

    MPI_Recv(&id_filosofo, 1, MPI_INT, id_filosofo, 0, MPI_COMM_WORLD, &estado);
     cout <<"Ten. "<< id<< " ha sido liberado por filo. " <<id_filosofo <<endl ;
  }
}
// ---------------------------------------------------------------------

int main( int argc, char** argv )
{
   int id_propio, num_procesos_actual ;

   MPI_Init( &argc, &argv );
   MPI_Comm_rank( MPI_COMM_WORLD, &id_propio );
   MPI_Comm_size( MPI_COMM_WORLD, &num_procesos_actual );


   if ( num_procesos == num_procesos_actual )
   {
      // ejecutar la función correspondiente a 'id_propio'
      if ( id_propio % 2 == 0 )          // si es par
         funcion_filosofos( id_propio ); //   es un filósofo
      else                               // si es impar
         funcion_tenedores( id_propio ); //   es un tenedor
   }
   else
   {
      if ( id_propio == 0 ) // solo el primero escribe error, indep. del rol
      { cout << "el número de procesos esperados es:    " << num_procesos << endl
             << "el número de procesos en ejecución es: " << num_procesos_actual << endl
             << "(programa abortado)" << endl ;
      }
   }

   MPI_Finalize( );
   return 0;
}

// ---------------------------------------------------------------------
