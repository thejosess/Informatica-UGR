#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include "Semaphore.h"

using namespace std ;
using namespace SEM ;

Semaphore mostr_vacio_par = 1,
			 mostr_vacio_impar = 0,
          ingr_disp[] = {0,0,0,0,0};
          
int contador = 1, n = 25;

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

int Producir(){
  chrono::milliseconds duracion_producir(aleatorio<20,200>());
  int dato = aleatorio<0,4>();
  cout << "(Se tardo en producir " << duracion_producir.count() << " milisegundos)" << endl;
  this_thread::sleep_for(duracion_producir);
  return dato;
}

//----------------------------------------------------------------------
// función que ejecuta la hebra del estanquero

void funcion_hebra_estanquero_par(  )
{
  for (int j = 0; j < n; j++){
    int i = Producir();
    while(i % 2 != 0){
    	i = Producir();
	 }
    sem_wait(mostr_vacio_par);
    cout << "puesto ingr.: " << i << endl;
    sem_signal(ingr_disp[i]);
  }
}

void funcion_hebra_estanquero_impar(  )
{
  for (int j = 0; j < n; j++){
    int i = Producir();
    while(i % 2 == 0){
    	i = Producir();
	 }
    sem_wait(mostr_vacio_impar);
    cout << "puesto ingr.: " << i << endl;
    sem_signal(ingr_disp[i]);
  }
}

//-------------------------------------------------------------------------
// Función que simula la acción de fumar, como un retardo aleatoria de la hebra

void fumar( int num_fumador )
{

   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_fumar( aleatorio<20,200>() );

   // informa de que comienza a fumar

    cout << "Fumador " << num_fumador << "  :"
          << " empieza a fumar (" << duracion_fumar.count() << " milisegundos)" << endl;

   // espera bloqueada un tiempo igual a ''duracion_fumar' milisegundos
   this_thread::sleep_for( duracion_fumar );

   // informa de que ha terminado de fumar

    cout << "Fumador " << num_fumador << "  : termina de fumar, comienza espera de ingrediente." << endl;

}

//----------------------------------------------------------------------
// función que ejecuta la hebra del fumador
void  funcion_hebra_fumador( int num_fumador )
{
   for (int i = 0; i < n; i++)
   {
      sem_wait(ingr_disp[num_fumador]);
      cout << "retirado ingr.: " << num_fumador << endl;
      if (num_fumador % 2 == 0 && contador < 2){
   		sem_signal(mostr_vacio_par);
   	} else if (num_fumador % 2 == 0 && contador == 2){
   		sem_signal(mostr_vacio_impar);
   		contador = 0;
		} else if (num_fumador % 2 != 0 && contador < 2){
			sem_signal(mostr_vacio_impar);
		} else if (num_fumador % 2 != 0 && contador == 2){
			sem_signal(mostr_vacio_par);
			contador = 0;
		}
		contador++;
      fumar(num_fumador);
   }
}

//----------------------------------------------------------------------

int main()
{
   // declarar hebras y ponerlas en marcha
  int num_hebras = 5;
  
  thread hebra_estanquero_par (funcion_hebra_estanquero_par);
  thread hebra_estanquero_impar (funcion_hebra_estanquero_impar);
  thread hebra_fumador[num_hebras];
  
  for(int i = 0; i < num_hebras; i++){
    hebra_fumador[i] = thread(funcion_hebra_fumador, i);
  }

  hebra_estanquero_par.join();
  hebra_estanquero_impar.join();
  for(int i = 0; i < num_hebras; i++){
    hebra_fumador[i].join();
  }
}
