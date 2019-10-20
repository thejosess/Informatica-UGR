// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// EXAMEN PRACTICA 2 realizado por Jose Santos Salvador
//
// archivo: santossalvadorjose-ex-p2.cpp
// Examen Practica 2
//
// Historial:
// Creado en Noviembre de 2018
// -----------------------------------------------------------------------------

/* g++ -std=c++11 -pthread -Wfatal-errors -o santossalvadorjose-ex-p2_exe santossalvadorjose-ex-p2.cpp
HoareMonitor.cpp Semaphore.cpp*/

#include <iostream>
#include <iomanip>
#include <random>
#include "HoareMonitor.h"

using namespace std ;
using namespace HM ;

//**********************************************************************
// función para generar un entero aleatorio uniformemente
//----------------------------------------------------------------------

template< int min, int max > int aleatorio()
{
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}

// *****************************************************************************
// clase para monitor Barrera semántica SU

class MBarreraParSU : public HoareMonitor
{
   private:
   int      cont_A,             // contador de hebras en cita A
	    cont_B,		// contador de hebras en cita B
            num_hebras_citaA , // número total de hebras citaA
	    num_hebras_citaB;  // número total de hebras citaB

   CondVar  cola_A, cola_B ;            // cola de hebras esperando en cita

   public:
   MBarreraParSU(int p_num_hebras_tipoA, int p_num_hebras_tipoB);
   MBarreraParSU( int p_num_hebras_cita ) ; // constructor
   void citaA(int num_hebra);		    //metodo cita A
   void citaB(int num_hebra);		    // metodo cita B
} ;
// -----------------------------------------------------------------------------

MBarreraParSU::MBarreraParSU(int p_num_hebras_tipoA, int p_num_hebras_tipoB)
{
   num_hebras_citaA = p_num_hebras_tipoA ;
   num_hebras_citaB = p_num_hebras_tipoB;
   cont_B            = 0 ;
   cont_A            = 0 ;
   cola_A            = newCondVar();
   cola_B           = newCondVar();
}
// -----------------------------------------------------------------------------

void MBarreraParSU::citaA( int num_hebra )
{
   cont_A ++ ;
   const int orden = cont_A ;

   cout <<  "Llega hebra tipo A " <<setw(2) << num_hebra << " (" <<setw(2) << orden << ")." << endl ;
   if (cont_B != 10 )
   {
      cout << "Proceso numero " << cont_A << " del tipo A queda en espera" << endl;
      cola_A.wait(); // cola de espera de la cita A
   }
   else
   {
      for( int i = 0 ; i < num_hebras_citaB-1 ; i++)
	{
	 cout << "Sale proceso de cita B numero " << i << endl;
         cola_B.signal() ; //si ya hay 10 procesos del tipo B despertar la cola cita B
	}

      cont_A -- ;	//habra un proceso menos de tipo A
   }
   cout << "              Sale hebra tipo A " <<setw(2) << num_hebra << " (" <<setw(2) << orden << ")." << endl ;
   //cout << "Sale proceso cita A" << endl;
}

void MBarreraParSU::citaB( int num_hebra )
{
   cont_B ++ ;
   const int orden = cont_B ;

   cout <<  "Llega hebra tipo B " <<setw(2) << num_hebra << " (" <<setw(2) << orden << ")." << endl ;
   if ( cont_A != 1 && cont_B != 10)
   {
      cout << "Proceso numero " << cont_B << " del tipo B queda en espera" << endl;
      cola_B.wait(); //cola de espera de los procesos tipo B
   }
   else
   {
      cout << "Se desbloquea un proceso del tipo A" <<endl;
      cola_A.signal();
      for( int i = 0 ; i < num_hebras_citaB-1 ; i++ )
	{
	 cout << "Se desbloquea proceso tipo B numero " << i << endl;
         cola_B.signal() ;
	}
      cont_B--;
   }
   cout << "              Sale hebra tipo B " <<setw(2) << num_hebra << " (" <<setw(2) << orden << ")." << endl ;
}
// -----------------------------------------------------------------------------

void funcion_hebra_A( MRef<MBarreraParSU> monitor, int num_hebra )
{
   while( true )
   {
      const int ms = aleatorio<0,30>();
      this_thread::sleep_for( chrono::milliseconds(ms) );
      monitor->citaA( num_hebra );
   }

}

void funcion_hebra_B( MRef<MBarreraParSU> monitor, int num_hebra )
{
   while( true )
   {
      const int ms = aleatorio<0,30>();
      this_thread::sleep_for( chrono::milliseconds(ms) );
      monitor->citaB( num_hebra );
   }

}
// *****************************************************************************

int main()
{
   cout <<  "Examen Practica 2: Jose Santos Salvador" << endl ;

   // declarar el número total de hebras
   const int num_hebras      = 1000,
             num_hebras_cita_A = 10,
	     num_hebras_cita_B = 10;

   // crear monitor  ('monitor' es una referencia al mismo, de tipo MRef<...>)
   MRef<MBarreraParSU> monitor = Create<MBarreraParSU>( num_hebras_cita_A,num_hebras_cita_B);

   // crear y lanzar hebras
   thread hebra_A[num_hebras];
   for( unsigned i = 0 ; i < num_hebras ; i++ )
      hebra_A[i] = thread( funcion_hebra_A, monitor, i );

   thread hebra_B[num_hebras];
   for( unsigned i = 0 ; i < num_hebras ; i++ )
      hebra_B[i] = thread( funcion_hebra_B, monitor, i );

   // espera por las hebras que no ocurre nunca
   for( unsigned i = 0 ; i < num_hebras ; i++ )
      hebra_A[i].join();

   for( unsigned i = 0 ; i < num_hebras ; i++ )
      hebra_B[i].join();
}
