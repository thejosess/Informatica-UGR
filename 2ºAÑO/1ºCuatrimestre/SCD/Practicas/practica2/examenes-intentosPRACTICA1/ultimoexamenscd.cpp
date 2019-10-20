/*

	Problema del estanquero y los fumadores

	Realizado por: Samuel Jiménez Piñero 
	Grupo: B3



*/


#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include "Semaphore.h"
#include <cmath>

using namespace std ;
using namespace SEM ;

const int num_fumador=3;

int cost=0;

// Semaforo del estanquero que permite o no generar un nuevo ingrediente. Vale inicialmente 1,
//  que significa que puede generar ingrediente para así poder generar el primer ingrediente.

Semaphore mostrador_libre=1,
			coste=0;

//Semaphore auxiliar=1;

// Vector de semaforos para los fumadores, tiene 3 espacios (num_fumador) y están 
//   inicializados a 0 para que no puedan fumar hasta que cambie a 1.

Semaphore ingrediente[num_fumador]= {0,0,0}; 


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

int Producir()
{

	const int COSTEPRODUCIR=2;

	chrono::milliseconds duracion_producir( aleatorio<20,200>() );

	int i=aleatorio<0,num_fumador-1>();

		cout << "\nEmpieza a producir el ingrediente: " << i << endl;

	this_thread::sleep_for( duracion_producir );

		cout << "\nHa terminado de producir el ingrediente" << endl;

	cost += COSTEPRODUCIR;

	return i;

}

//----------------------------------------------------------------------
// función que ejecuta la hebra del estanquero

void funcion_hebra_estanquero(  )
{
	while( true )
	{
	
	sem_wait(mostrador_libre); 

	int i = Producir();

	mtx.lock();

		cout << "\nPuesto el ingrediente: " << i << "\n";

	mtx.unlock();

	if(cost %3 == 0)
			sem_signal(coste);

	sem_signal(ingrediente[i]);

	}

}



//-------------------------------------------------------------------------
// Función que simula la acción de fumar, como un retardo aleatoria de la hebra

void fumar( int num_fumador )
{

   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_fumar( aleatorio<20,200>() );

   // informa de que comienza a fumar

    cout << "\nFumador " << num_fumador << "  :"
          << " empieza a fumar (" << duracion_fumar.count() << " milisegundos)" << endl;

   // espera bloqueada un tiempo igual a ''duracion_fumar' milisegundos
   this_thread::sleep_for( duracion_fumar );

   // informa de que ha terminado de fumar

    cout << "\nFumador " << num_fumador << "  : termina de fumar, comienza espera de ingrediente." << endl;

}

//----------------------------------------------------------------------
// función que ejecuta la hebra del fumador
void  funcion_hebra_fumador( int num_fumador )
{
   while( true )
   {

	sem_wait(ingrediente[num_fumador]);
	
	mtx.lock();

		cout << "\nEl fumador : " << num_fumador << " ha retirado el ingrediente " << endl;

	mtx.unlock();

	sem_signal(mostrador_libre);

	fumar(num_fumador);
	
   }
}

void funcion_hebra_coste()
{
	while( true )
	{
		sem_wait(coste);

		mtx.lock();

			cout << "\nEl coste es de: " << cost << endl;

		mtx.unlock();

	}

}

//----------------------------------------------------------------------

int main()
{
	thread hebra_coste(funcion_hebra_coste);
	thread hebra_estanquero (funcion_hebra_estanquero); 
	thread hebra_fumador[num_fumador];
	for(int i=0; i < num_fumador; i++){
		hebra_fumador[i]= thread (funcion_hebra_fumador,i);
	}

	hebra_coste.join();
	hebra_estanquero.join();
	for(int i=0; i < num_fumador; i++){
		hebra_fumador[i].join();
	}

	


}
