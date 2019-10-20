#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random>
#include "Semaphore.h"

using namespace std ;
using namespace SEM ;

//**********************************************************************
// variables compartidas

const int num_items = 40 ,   // número de items
	       tam_vec   = 10 ,   // tamaño del buffer
	       COSTE_PRODUCIR = 2,
	       COSTE_CONSUMIR = 1;
unsigned  cont_prod[num_items] = {0}, // contadores de verificación: producidos
          cont_cons[num_items] = {0}; // contadores de verificación: consumidos

int buffer[tam_vec] = {0};
int primera_libre = 0;

Semaphore libres = tam_vec,
	  ocupadas = 0,
	  multiplo3 = 0;

int coste = 0; 

mutex mtx;

//0 <= 10 + L - E <= 10


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

//**********************************************************************
// funciones comunes a las dos soluciones (fifo y lifo)
//----------------------------------------------------------------------

int producir_dato()
{
   static int contador = 0 ;
   this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));
   coste += COSTE_PRODUCIR;
   mtx.lock();
   cout << "producido: " << contador << endl << flush ;
   mtx.unlock();

   if(coste % 3 == 0)
   	sem_signal(multiplo3);
   
   cont_prod[contador] ++ ;
   return contador++ ;
}
//----------------------------------------------------------------------

void consumir_dato( unsigned dato )
{
   assert( dato < num_items );
   cont_cons[dato] ++ ;
   this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));
   coste += COSTE_CONSUMIR;
   mtx.lock();
   cout << "                  consumido: " << dato << endl ;
   mtx.unlock();

  // if(coste % 3 == 0)
   	//sem_signal(multiplo3);
}


//----------------------------------------------------------------------

void test_contadores()
{
   bool ok = true ;
   cout << "comprobando contadores ...." ;
   for( unsigned i = 0 ; i < num_items ; i++ )
   {  if ( cont_prod[i] != 1 )
      {  cout << "error: valor " << i << " producido " << cont_prod[i] << " veces." << endl ;
         ok = false ;
      }
      if ( cont_cons[i] != 1 )
      {  cout << "error: valor " << i << " consumido " << cont_cons[i] << " veces" << endl ;
         ok = false ;
      }
   }
   if (ok)
      cout << endl << flush << "solución (aparentemente) correcta." << endl << flush ;
}

//----------------------------------------------------------------------

void  funcion_hebra_productora(  )
{
   for( unsigned i = 0 ; i < num_items ; i++ )
   {
      int dato = producir_dato() ;
      sem_wait( libres );

      mtx.lock();
      buffer[primera_libre] = dato;
      primera_libre++;
      mtx.unlock();

      sem_signal( ocupadas );
   }
}

//----------------------------------------------------------------------

void funcion_hebra_consumidora(  )
{
   for( unsigned i = 0 ; i < num_items ; i++ )
   {
      sem_wait( ocupadas );

      mtx.lock();
      primera_libre--;
      int dato = buffer[primera_libre];
      mtx.unlock();

      sem_signal( libres );
      consumir_dato( dato ) ;
    }
}
//----------------------------------------------------------------------

void funcion_hebra_coste()
{
	while(true)
	{
		sem_wait(multiplo3);

		mtx.lock();
		cout << "El valor en euros de producir y consumir es x = " << coste << endl;
		mtx.unlock();
	}
}

int main()
{
   cout << "--------------------------------------------------------" << endl
        << "Problema de los productores-consumidores (solución LIFO)." << endl
        << "--------------------------------------------------------" << endl
        << flush ;

   thread hebra_productora ( funcion_hebra_productora ),
          hebra_consumidora( funcion_hebra_consumidora ),
          hebra_coste( funcion_hebra_coste );

   hebra_productora.join() ;
   hebra_consumidora.join() ;
   hebra_coste.join();

   test_contadores();
}
