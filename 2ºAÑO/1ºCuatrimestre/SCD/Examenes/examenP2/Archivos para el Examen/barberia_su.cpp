// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// Seminario 2. Introducción a los monitores en C++11.
//
// archivo: barberia_su.cpp
// Ejemplo de un monitor en C++11 con semántica SU, para el problema
// de la barbería.
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

constexpr int numClientes = 3;    // constante número de clientes de la barbería

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

void EsperarFueraBarberia( int num_cliente ){
   // calcular milisegundos aleatorios de duración de la acción de esperar fuera
   chrono::milliseconds duracion_esperar_fuera( aleatorio<20,200>() );

   // informa de que comienza a esperar fuera de la barberia
   cout << "\tCliente " << num_cliente << ": espera fuera de la barberia (" 
        << duracion_esperar_fuera.count() << " milisegundos)" << endl;	

   // espera bloqueada un tiempo igual a 'duracion_esperar_fuera' milisegundos
   this_thread::sleep_for( duracion_esperar_fuera );

   // informa de que ha terminado de fumar
   cout << "\tCliente " << num_cliente << ": ha terminado de esperar y se marcha." << endl;
}

//-------------------------------------------------------------------------
// Función que simula la acción de producir un ingrediente con un retardo aleatorio de la hebra

void CortarPeloACliente(){
   // calcular milisegundos aleatorios de duración de la acción de cortar el pelo)
   chrono::milliseconds duracion_cortar( aleatorio<20,200>() );

   // espera bloqueada un tiempo igual a 'duracion_cortar' milisegundos
   this_thread::sleep_for( duracion_cortar );
}

// *****************************************************************************
// clase para monitor fumadores

class Barberia : public HoareMonitor{
 private:
 int 
   cliente;		  	  // numero del cliente que está en la silla
 CondVar         	  	  // colas condicion:
   barbero, 		  	  // cola donde espera el barbero
   sala_espera,  	 	  // cola donde esperan los clientes para entrar a pelarse
   cliente_en_silla;		  // cola donde espera el cliente que está pelandose

 public:                    	  // constructor y métodos públicos
   Barberia();
   void cortarPelo( int num_cliente );
   void siguienteCliente( );
   void finCliente( );
   
};

// -----------------------------------------------------------------------------

Barberia::Barberia( ){
   cliente_en_silla = newCondVar(); 	   // Inicializamos al cliente en la silla
   barbero = newCondVar();		   // Inicializamos barbero
   sala_espera = newCondVar();         	   // Inicializamos clientes
}

// -----------------------------------------------------------------------------

void Barberia::cortarPelo( int num_cliente ){
	if (barbero.get_nwt() == 0){		//Comprueba que el barbero no esté ocupado
		sala_espera.wait();		//Si está ocupado, el cliente espera dormido en sala.
	}
	else{					//Si la silla está vacía
		cout << "\tEl cliente " << num_cliente << " despierta al barbero" << endl;
		barbero.signal();		//Despierta al barbero
	}
	cout << "Cortando el pelo al cliente " << num_cliente << endl;
	cliente = num_cliente;
	cliente_en_silla.wait();	//Se duerme hasta que acaben de cortarle el pelo
}

// -----------------------------------------------------------------------------

void Barberia::siguienteCliente( ){
	if (sala_espera.get_nwt() == 0){	//Si no hay clientes esperando
		cout << "No hay clientes esperando, el barbero duerme" << endl;
		barbero.wait();		// el barbero duerme
	}
	else{
		cout << "Se ha dado paso a un nuevo cliente" << endl;
		sala_espera.signal();	//Avisamos al siguiente cliente de que puede sentarse
	}
}

// -----------------------------------------------------------------------------

void Barberia::finCliente( ){
	cout << "Barbero despierta al cliente " << cliente << ", ha terminado de pelarlo." 
	     << endl;
	cliente_en_silla.signal();	//Despierta al cliente de la silla.
}

// *****************************************************************************
// funciones de hebras

void funcion_hebra_cliente( MRef<Barberia> monitor, int num_cliente ){
   while(true){ 
	monitor->cortarPelo( num_cliente );
	EsperarFueraBarberia( num_cliente );
   }
}
// -----------------------------------------------------------------------------

void funcion_hebra_barbero( MRef<Barberia> monitor ){
   while(true){
	monitor->siguienteCliente( );
	CortarPeloACliente( );
	monitor->finCliente( );
   }
}
// -----------------------------------------------------------------------------

int main()
{
   cout << "---------------------------------------------------------" << endl
        << "---------------  Problema de la Barberia  ---------------" << endl
        << "---------------------------------------------------------" << endl
        << flush ;

   // crear monitor  ('monitor' es una referencia al mismo, de tipo MRef<...>)
   MRef<Barberia> monitor = Create<Barberia>();

   // crear y lanzar hebras
   thread barbero(funcion_hebra_barbero, monitor);
   thread clientes[numClientes];
   for (int i = 0; i < numClientes; i++)
	clientes[i] = thread (funcion_hebra_cliente, monitor, i);

   // esperar a que terminen las hebras (no pasa nunca)
   barbero.join() ;
   for (int i = 0; i < numClientes; i++)
	clientes[i].join();
   clientes[numClientes].join();
}
