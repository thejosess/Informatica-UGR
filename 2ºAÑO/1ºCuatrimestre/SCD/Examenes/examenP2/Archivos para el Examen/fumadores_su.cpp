// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// Seminario 2. Introducción a los monitores en C++11.
//
// archivo: fumadores_su.cpp
// Ejemplo de un monitor en C++11 con semántica SU, para el problema
// de los fumadores.
//
// Historial:
// Creado en Noviembre de 2018
// -----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <random>
#include "HoareMonitor.h"

using namespace std ;
using namespace HM;

constexpr int numFumadores = 3;  // constante núm. de entradas del buffer

//**********************************************************************
// plantilla de función para generar un entero aleatorio uniformemente
// distribuido entre dos valores enteros, ambos incluidos
// (ambos tienen que ser dos constantes, conocidas en tiempo de compilación)
//----------------------------------------------------------------------

template< int min, int max > int aleatorio(){
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}

// -----------------------------------------------------------------------------

void fumar( int num_fumador ){
   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_fumar( aleatorio<20,200>() );

   // informa de que comienza a fumar
    cout << "\tFumador " << num_fumador << "  :"
         << " empieza a fumar (" << duracion_fumar.count() << " milisegundos)" << endl;

   // espera bloqueada un tiempo igual a 'duracion_fumar' milisegundos
   this_thread::sleep_for( duracion_fumar );

   // informa de que ha terminado de fumar
    cout << "\tFumador " << num_fumador << "  : termina de fumar, comienza espera de ingrediente." 
         << endl;
}

//-------------------------------------------------------------------------
// Función que simula la acción de producir un ingrediente con un retardo aleatorio de la hebra

int producirIngrediente(){
   // calcular milisegundos aleatorios de duración de la acción de producir)
   chrono::milliseconds duracion_producir( aleatorio<20,200>() );

   // espera bloqueada un tiempo igual a 'duracion_producir' milisegundos
   this_thread::sleep_for( duracion_producir );
		
   return	aleatorio<0,numFumadores-1>();		//produccion del valor 0...2
}

// *****************************************************************************
// clase para monitor fumadores

class Estanco : public HoareMonitor{
 private:
 int 
   ing_en_mostrador;		  // valor del ingrediente que está en el mostrador
 CondVar         	  	  // colas condicion:
   estanquero, 		  	  // cola donde espera el estanquero
   fumador[numFumadores];  	  // cola donde espera que haya un ingrediente de su tipo

 public:                    	  // constructor y métodos públicos
   Estanco();
   void obtenerIngrediente( int num_fum );
   void ponerIngrediente( int num_ingrediente );
   void esperarRecogidaIngrediente( );
   
};

// -----------------------------------------------------------------------------

Estanco::Estanco( ){
   ing_en_mostrador = -1; 		   // -1 simboliza que está vacío
   estanquero = newCondVar();		   // Inicializamos estanquero
   for(int i=0; i<numFumadores; i++)
   	fumador[i] = newCondVar();         // Inicializamos cada fumador
}

// -----------------------------------------------------------------------------

void Estanco::obtenerIngrediente( int num_fum ){
	if (ing_en_mostrador != num_fum)	//Comprueba que el ingrediente no esté en el mostrador
		fumador[num_fum].wait();        //Si eno está disponible, su fumador espera.

	cout << "Se ha retirado el ingrediente " << num_fum << endl;
	
	ing_en_mostrador = -1;		// ing_en_mostrador queda a -1 porque está vacío el mostrador

	estanquero.signal();		//Avisamos al estanquero de que el mostrador está vacío.
}

// -----------------------------------------------------------------------------

void Estanco::ponerIngrediente( int num_ingrediente ){
	ing_en_mostrador = num_ingrediente;		//Ponemos el valor del ingrediente

	cout << "Se ha puesto el ingrediente " << num_ingrediente << endl;
	
	fumador[num_ingrediente].signal();	//Avisamos al fumador de que tiene su ingr.
}

// -----------------------------------------------------------------------------

void Estanco::esperarRecogidaIngrediente( ){
	if (ing_en_mostrador != -1)  //Comprueba que el mostrador no esté vacío
		estanquero.wait();   //Si en el mostrador hay algún ingrediente, el estanquero espera.
}

// *****************************************************************************
// funciones de hebras

void funcion_hebra_fumador( MRef<Estanco> monitor, int num_fumador ){
   while(true){ 
	monitor->obtenerIngrediente( num_fumador );
	fumar( num_fumador );
   }
}
// -----------------------------------------------------------------------------

void funcion_hebra_estanquero( MRef<Estanco> monitor ){
   int ingrediente;
   while(true){
	ingrediente = producirIngrediente();
	monitor->ponerIngrediente( ingrediente );
	monitor->esperarRecogidaIngrediente();
   }
}
// -----------------------------------------------------------------------------

int main()
{
   cout << "-----------------------------------------------------------" << endl
        << "---------------  Problema de los fumadores  ---------------" << endl
        << "-----------------------------------------------------------" << endl
        << flush ;

   // crear monitor  ('monitor' es una referencia al mismo, de tipo MRef<...>)
   MRef<Estanco> monitor = Create<Estanco>();

   // crear y lanzar hebras
   thread estanquero(funcion_hebra_estanquero, monitor);
   thread fumadores[numFumadores];
   for (int i = 0; i < numFumadores; i++)
	fumadores[i] = thread (funcion_hebra_fumador, monitor, i);

   // esperar a que terminen las hebras (no pasa nunca)
   estanquero.join() ;
   for (int i = 0; i < numFumadores; i++)
	fumadores[i].join();
   fumadores[numFumadores].join();
}
