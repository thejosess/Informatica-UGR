// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// Seminario 2. Introducción a los monitores en C++11.
//
// archivo: varios_fifo_su.cpp
// Ejemplo de un monitor en C++11 con semántica SU, para el problema
// del productor/consumidor, con varios productores y consumidores.
// Opcion FIFO (stack)
//
// Historial:
// Creado en Noviembre de 2018
// -----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cassert>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include "HoareMonitor.h"

using namespace std ;
using namespace HM;

constexpr int num_items = 40;     // número de items a producir/consumir
constexpr int num_hebras_prod = 8; // número de hebras productoras
constexpr int num_hebras_cons = 5; // número de hebras consumidoras

const int num_datos_prod = num_items / num_hebras_prod; // número de datos por hebra productora
const int num_datos_cons = num_items / num_hebras_cons; // número de datos por hebra consumidora

mutex
   mtx ;                 // mutex de escritura en pantalla

unsigned
   cont_prod[num_items], // contadores de verificación: producidos
   cont_cons[num_items], // contadores de verificación: consumidos
   cont_produc[num_hebras_prod] = {0};

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

int producir_dato( int num_productor )
{
   int valor = num_datos_prod * num_productor + cont_produc[num_productor] ;

   this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));

   mtx.lock();
   cout << "producido: " << valor << endl << flush ;
   mtx.unlock();

   cont_prod[valor] ++ ;
   cont_produc[num_productor] ++;
   return valor;
}
//----------------------------------------------------------------------

void consumir_dato( unsigned dato )
{
   if ( num_items <= dato )
   {
      cout << " dato === " << dato << ", num_items == " << num_items << endl ;
      assert( dato < num_items );
   }
   cont_cons[dato] ++ ;
   this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));

   mtx.lock();
   cout << "                  consumido: " << dato << endl ;
   mtx.unlock();
}
//----------------------------------------------------------------------

void ini_contadores()
{
   for( unsigned i = 0 ; i < num_items ; i++ ){
      cont_prod[i] = 0 ;
      cont_cons[i] = 0 ;
   }
}

//----------------------------------------------------------------------

void test_contadores()
{
   bool ok = true ;
   cout << "comprobando contadores ...." << flush ;

   for( unsigned i = 0 ; i < num_items ; i++ )
   {
      if ( cont_prod[i] != 1 )
      {
         cout << "error: valor " << i << " producido " << cont_prod[i] << " veces." << endl ;
         ok = false ;
      }
      if ( cont_cons[i] != 1 )
      {
         cout << "error: valor " << i << " consumido " << cont_cons[i] << " veces" << endl ;
         ok = false ;
      }
   }
   if (ok)
      cout << endl << flush << "solución (aparentemente) correcta." << endl << flush ;
}

// *****************************************************************************
// clase para monitor buffer, version LIFO, semántica SC, un prod. y un cons.

class ProdConsVariosSU : public HoareMonitor
{
 private:
 static const int           // constantes:
   num_celdas_total = 10;   //  núm. de entradas del buffer

 int                        // variables permanentes
   buffer[num_celdas_total],//  buffer de tamaño fijo, con los datos
   primera_libre ,          //  indice de celda de la próxima inserción
   primera_ocupada,	    //  indice de celda de la próxima extracción
   celdas_ocupadas;	    //  número de celdas ocupadas

 CondVar	            // colas condicion:
   consumidores,            //  cola donde esperan los consumidores
   productores;             //  cola donde espera los productores

 public:                    // constructor y métodos públicos
   ProdConsVariosSU(  ) ;      // constructor
   int  leer();                // extraer un valor (sentencia L) (consumidor)
   void escribir( int valor ); // insertar un valor (sentencia E) (productor)
} ;
// -----------------------------------------------------------------------------

ProdConsVariosSU::ProdConsVariosSU(  )
{
   primera_libre = 
   primera_ocupada = 
   celdas_ocupadas = 0;
   consumidores = newCondVar();
   productores = newCondVar();
}
// -----------------------------------------------------------------------------
// función llamada por el consumidor para extraer un dato

int ProdConsVariosSU::leer(  )
{
   // esperar bloqueado hasta que 0 < num_celdas_ocupadas
   if ( celdas_ocupadas == 0 )
      consumidores.wait();

   // hacer la operación de lectura, actualizando estado del monitor
   assert( 0 < celdas_ocupadas  );
   const int valor = buffer[primera_ocupada] ;
   primera_ocupada = (primera_ocupada + 1) % num_celdas_total;
   celdas_ocupadas--;

   // señalar al productor que hay un hueco libre, por si está esperando
   productores.signal();

   // devolver valor
   return valor ;
}
// -----------------------------------------------------------------------------

void ProdConsVariosSU::escribir( int valor )
{
   // esperar bloqueado hasta que num_celdas_ocupadas < num_celdas_total
   if ( celdas_ocupadas == num_celdas_total )
      productores.wait();
//cout << "escribir: ocup == " << num_celdas_ocupadas << ", total == " << num_celdas_total << endl ;
   assert( celdas_ocupadas < num_celdas_total );

   // hacer la operación de inserción, actualizando estado del monitor
   buffer[primera_libre] = valor ;
   celdas_ocupadas++ ;
   primera_libre = (primera_libre + 1) % num_celdas_total;

   // señalar al consumidor que ya hay una celda ocupada (por si esta esperando)
   consumidores.signal();
}

// *****************************************************************************
// funciones de hebras

void funcion_hebra_productora( MRef<ProdConsVariosSU> monitor, int num_productor )
{
   for( unsigned i=0 ; i<num_datos_prod ; i++ )
   {
      int valor = producir_dato(num_productor) ;
      monitor->escribir( valor );
   }
}

// -----------------------------------------------------------------------------

void funcion_hebra_consumidora( MRef<ProdConsVariosSU> monitor )
{
   for( unsigned i=0 ; i<num_datos_cons ; i++ )
   {
      int valor = monitor->leer();
      consumir_dato( valor ) ;
   }
}

// -----------------------------------------------------------------------------

int main()
{
   cout << "--------------------------------------------------------------------------------------" << endl
        << "Problema de los productores-consumidores (varios prod/cons, Monitor SU, buffer FIFO). " << endl
        << "--------------------------------------------------------------------------------------" << endl
        << flush ;

   MRef<ProdConsVariosSU> monitor = Create<ProdConsVariosSU>();

   // Crear y lanzar las hebras productoras
   thread hebras_productoras[num_hebras_prod];
   for(int i=0; i<num_hebras_prod; i++)
	hebras_productoras[i] = thread(funcion_hebra_productora, monitor, i);

   // Crear y lanzar las hebras consumidoras
   thread hebras_consumidoras[num_hebras_cons];
   for(int j=0; j<num_hebras_cons; j++)
	hebras_consumidoras[j] = thread(funcion_hebra_consumidora, monitor);

   //Esperar a que todas terminen
   for(int i=0; i<num_hebras_prod; i++)
	hebras_productoras[i].join();

   for(int j=0; j<num_hebras_cons; j++)
	hebras_consumidoras[j].join();

   // comprobar que cada item se ha producido y consumido exactamente una vez
   test_contadores() ;
}
