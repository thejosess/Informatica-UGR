/*

	Problema del estanquero y los fumadores

	Realizado por: Jose Santos Salvador
	Grupo: B3



*/


#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include "Semaphore.h"

using namespace std ;
using namespace SEM ;

const int num_fumador=3;

// Semaforo del estanquero que permite o no generar un nuevo ingrediente. Vale inicialmente 1,
//  que significa que puede generar ingrediente para así poder generar el primer ingrediente.

Semaphore mostrador_libre=1,
	  ingrediente[num_fumador] = {0,0,0} ,
    proveedor = 1 ,
    recibe[num_fumador] = {0,0,0} ;

// Vector de semaforos para los fumadores, tiene 3 espacios (num_fumador) y están 
//   inicializados a 0 para que no puedan fumar hasta que cambie a 1.

mutex mtx;

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

int producir()
{

   // calcular milisegundos aleatorios de duración de la acción de producir)
   chrono::milliseconds duracion_producir( aleatorio<20,200>() );

   int ingrediente = aleatorio<0,num_fumador-1>();

   // informa de que comienza a fumar
    mtx.lock();

    cout << "\nEstanquero empieza a producir ingrediente "<<ingrediente << " durante " << duracion_producir.count() << " milisegundos" << endl;

    mtx.unlock();

   // espera bloqueada un tiempo igual a ''duracion_producir' milisegundos
   this_thread::sleep_for( duracion_producir );

   // informa de que ha terminado de producir

    mtx.lock();

    cout << "\nEstanquero termina de producir " << endl;

    mtx.unlock();

    return ingrediente ;
}

void funcion_proveedor()
{
  sem_wait(proveedor);

  while(true)
  {
    int i =producir();
  }

  sem_signal(recibe[i]) ;

}

//----------------------------------------------------------------------
// función que ejecuta la hebra del estanquero

void funcion_hebra_estanquero(int num_fumador)
{
	while( true )
	{

  sem_wait(recibe[num_fumador]) ;

	sem_wait(mostrador_libre); 

	mtx.lock();

		cout << "\nPuesto el ingrediente: " << num_fumador << "\n";

	mtx.unlock();

	sem_signal(ingrediente[num_fumador]);

	}

}

void fumar( int num_fumador )
{

   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_fumar( aleatorio<20,200>() );

   // informa de que comienza a fumar
    mtx.lock();

    cout << "\nFumador " << num_fumador << "  :"
          << " empieza a fumar (" << duracion_fumar.count() << " milisegundos)" << endl;

    mtx.unlock();

   // espera bloqueada un tiempo igual a ''duracion_fumar' milisegundos
   this_thread::sleep_for( duracion_fumar );

   // informa de que ha terminado de fumar

    mtx.lock();

    cout << "\nFumador " << num_fumador << "  : termina de fumar, comienza espera de ingrediente." << endl;

    mtx.unlock();

}

//----------------------------------------------------------------------
// función que ejecuta la hebra del fumador
void  funcion_hebra_fumador( int num_fumador )
{
   while( true )
   {

	sem_wait(ingrediente[num_fumador]);

	sem_signal(mostrador_libre);
  sem_signal(proveedor);

        mtx.lock();

	cout << "\nEl fumador " <<num_fumador << " ha retirado el ingrediente" << endl ;

        mtx.unlock();

	fumar(num_fumador);

   }
}

//----------------------------------------------------------------------

int main()
{

   cout << "--------------------------------------------------------" << endl 
        << "Problema de los fumadores-estanquero." << endl
        << "--------------------------------------------------------" << endl;


	thread hebra_estanquero [num_fumador];
  for(int i=0; i < num_fumador; i++){
    hebra_estanquero[i]= thread (funcion_hebra_estanquero,i);
  }
  thread hebra_proveedor (funcion_proveedor) ;
	thread hebra_fumador[num_fumador];
	for(int i=0; i < num_fumador; i++){
		hebra_fumador[i]= thread (funcion_hebra_fumador,i);
	}


  for(int i=0; i < num_fumador; i++){
    hebra_estanquero[i].join();
  }
  hebra_estanquero[num_fumador].join();
  
  	for(int i=0; i < num_fumador; i++){
		hebra_fumador[i].join();
	}
	hebra_fumador[num_fumador].join();
	
}
