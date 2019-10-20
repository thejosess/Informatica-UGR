/*

	Problema del estanquero y los fumadores

	Realizado por: JOSE SANTOS SALVADOR	
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

mutex mtx;

unsigned s_0 = 0, s_1 = 1, suma = 0;


template< int min, int max > int aleatorio()
{
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}

void escribir_termino(unsigned t1)
{
	chrono::milliseconds duracion_escribir( aleatorio<20,200>() );
	this_thread::sleep_for( duracion_escribir );

	cout << "Nuevo termino: " << t1 << endl;
}

//----------------------------------------------------------------------
// 

void funcion_hebra_sucesion()
{
	escribir_termino(s_0) ;
	escribir_termino(s_1) ;

	for( int i = 0 ; i < n ; i++)
	{
		suma = escribir_termino(s_0, s_1) ;
		s_0 = s_1 ;
		s_1 = suma ;
		sem_signal(p1);
	}
}


void escribir_suma(unsigned suma)
{
	chrono::milliseconds duracion_suamando( aleatorio<20,100>() );

	this_thread::sleep_for( duracion_sumando );


}

//-------------------------------------------------------------------------
// 

int escribir_termino( unsigned t1, unsigned t2 )
{
	chrono::milliseconds duracion_sumar( aleatorio<20,100>() );

	this_thread::sleep_for( duracion_sumar );

	return t1 + t2;
}

//----------------------------------------------------------------------
// 


void  funcion_hebra_suma()
{
	int suma_termino = 0 ; // variable estatica
	for( int i  = 0 ; i < n / 2 ; i ++)
	{
		sem_wait(p1) ;
		int dato ;
		suma_termino += suma ;
		escribir_suma(suma_termino);
	}
}

//----------------------------------------------------------------------

int main()
{



}
