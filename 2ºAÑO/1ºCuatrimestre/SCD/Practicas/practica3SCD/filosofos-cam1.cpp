// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// Práctica 3. Implementación de algoritmos distribuidos con MPI
//
// Archivo: filosofos-cam.cpp
// Implementación del problema de los filósofos con camarero.
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
   num_procesos  = 2*num_filosofos + 1 ,  // Ese más uno es el camarero

   //Etiquetas:
   etiq_soltar = 0,
   etiq_coger = 1,
   etiq_sentarse = 2,
   etiq_levantarse = 3;

template< int min, int max > int aleatorio()
{
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}

// ---------------------------------------------------------------------

void funcion_filosofos( int id )
{

  const int 
    id_ten_izq = (id+1)              % (num_procesos - 1), //id. tenedor izq, el -1 es porque ahora hay 11 procesos
    id_ten_der = (id+num_procesos-2) % (num_procesos - 1), //id. tenedor der, el -1 es porque ahora hay 11 procesos
    id_camarero = 10;

  MPI_Status estado;

  while ( true )
  {

    cout <<"Filósofo " <<id <<" solicita sentarse."<<endl;
    MPI_Ssend(NULL, 0, MPI_INT, id_camarero, etiq_sentarse, MPI_COMM_WORLD);

    MPI_Recv(NULL, 0, MPI_INT, id_camarero, etiq_sentarse, MPI_COMM_WORLD, &estado);
    cout <<"Filósofo " <<id << " se sienta. "<<endl;

    cout <<"Filósofo " <<id << " solicita ten. izq." <<id_ten_izq <<endl;
    MPI_Ssend(NULL, 0, MPI_INT, id_ten_izq, etiq_coger, MPI_COMM_WORLD);

    cout <<"Filósofo " <<id <<" solicita ten. der." <<id_ten_der <<endl;
    MPI_Ssend(NULL, 0, MPI_INT, id_ten_der, etiq_coger, MPI_COMM_WORLD);

    cout <<"Filósofo " <<id <<" comienza a comer" <<endl ;
    sleep_for( milliseconds( aleatorio<10,100>() ) );


    cout <<"Filósofo " <<id <<" suelta ten. izq. " <<id_ten_izq <<endl;
    MPI_Ssend(NULL, 0, MPI_INT, id_ten_izq, etiq_soltar, MPI_COMM_WORLD);

    cout<< "Filósofo " <<id <<" suelta ten. der. " <<id_ten_der <<endl;
    MPI_Ssend(NULL, 0, MPI_INT, id_ten_der, etiq_soltar, MPI_COMM_WORLD);


    cout <<"Filósofo " <<id <<" se levanta."<<endl;
    MPI_Ssend(NULL, 0, MPI_INT, id_camarero, etiq_levantarse, MPI_COMM_WORLD);


    cout << "Filosofo " << id << " comienza a pensar" << endl;
    sleep_for( milliseconds( aleatorio<10,100>() ) );
 }
}
// ---------------------------------------------------------------------

void funcion_camarero( int n)
{
  int id, sentados;
  sentados = 0;
  MPI_Status estado;

  while( true )
  {

    if(sentados < 4)
    {
      MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &estado);
    }

    else
    {
      MPI_Probe(MPI_ANY_SOURCE, etiq_levantarse, MPI_COMM_WORLD, &estado);
    }

    if(estado.MPI_TAG == etiq_sentarse) //Si se le deja sentarse
    {
      id = estado.MPI_SOURCE;
      MPI_Recv(NULL, 0, MPI_INT, id, etiq_sentarse, MPI_COMM_WORLD, &estado );

      sentados++;

      MPI_Ssend(NULL, 0, MPI_INT, id, etiq_sentarse, MPI_COMM_WORLD);
      cout <<"Filósofo "<< id<< "se sienta. (Número de filosofos sentados: "<< sentados << endl;
    }

    if(estado.MPI_TAG == etiq_levantarse)
    {
      id = estado.MPI_SOURCE;
      MPI_Recv(NULL, 0, MPI_INT, id, etiq_levantarse, MPI_COMM_WORLD, &estado);
      sentados--;
      cout <<"Filósofo "<< id<< "se levanta. (Número de filosofos sentados: "<< sentados << endl;
    }
  }
}

// ---------------------------------------------------------------------

void funcion_tenedores( int id )
{
  int valor, id_filosofo ;  
  MPI_Status estado ;       

  while ( true )
  {

     MPI_Recv(&valor, 1, MPI_INT, MPI_ANY_SOURCE, etiq_coger, MPI_COMM_WORLD, &estado);

     id_filosofo = estado.MPI_SOURCE;
     cout <<"Ten. " <<id <<" ha sido cogido por filo. " <<id_filosofo <<endl;

     MPI_Recv(&id_filosofo, 1, MPI_INT, id_filosofo, etiq_soltar, MPI_COMM_WORLD, &estado);     
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
      if ( id_propio == 10 )               // si es 10    
            funcion_camarero( id_propio ); // es camarero
      else{
          if( id_propio % 2 == 0)           // si es par filosofo
            funcion_filosofos( id_propio ); 
          else                              // si es impar tenedor                      
            funcion_tenedores( id_propio ); 
      }
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