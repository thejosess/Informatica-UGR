// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// Práctica 4. Implementación de sistemas de tiempo real.
//
// Archivo: ejecutivo2.cpp
//
// RESPUESTAS A LAS PREGUNTAS:
/* 1. ¿ cual es el mínimo tiempo de espera que queda al final de las
   iteraciones del ciclo secundario con tu solución ?

   Es el del ciclo ABD ya que utiliza 490 ms, y 10 ms de espera.

   2. ¿ sería planificable si la tarea D tuviese un tiempo cómputo de
   250 ms ?

   Podría ser siendo muy precisos y justo al acabar el ciclo ABD que consume 500 ms
   deberia empezar el siguiente.
*/
//   Datos de las tareas:
//   ------------
//   Ta.  T    C
//   ------------
//   A  500  100
//   B  500  150
//   C  1000 200
//   D  2000 240
//  -------------
//
//  Planificación (con Ts == 500 ms)
//  *---------*----------*---------*--------*
//  | A B C   | A B D    | A B C   | A B    |
//  *---------*----------*---------*--------*
//
// autor: Jose Santos Salvador
// -----------------------------------------------------------------------------

#include <string>
#include <iostream> 
#include <thread>
#include <chrono>   
#include <ratio>    

using namespace std ;
using namespace std::chrono ;
using namespace std::this_thread ;

// tipo para duraciones en segundos y milisegundos, en coma flotante:
typedef duration<float,ratio<1,1>>    seconds_f ;
typedef duration<float,ratio<1,1000>> milliseconds_f ;

// -----------------------------------------------------------------------------
// tarea genérica: duerme durante un intervalo de tiempo (de determinada duración)

void Tarea( const std::string & nombre, milliseconds tcomputo )
{
   cout << "   Comienza tarea " << nombre << " (C == " << tcomputo.count() << " ms.) ... " ;
   sleep_for( tcomputo );
   cout << "fin." << endl ;
}

// -----------------------------------------------------------------------------
// tareas concretas del problema:

void TareaA() { Tarea( "A", milliseconds(100) );  }
void TareaB() { Tarea( "B", milliseconds(150) );  }
void TareaC() { Tarea( "C", milliseconds(200) );  }
void TareaD() { Tarea( "D", milliseconds(240) );  }

// -----------------------------------------------------------------------------
// implementación del ejecutivo cíclico:

int main( int argc, char *argv[] )
{
   // Ts = duración del ciclo secundario
   const milliseconds Ts( 500 );

   // ini_sec = instante de inicio de la iteración actual del ciclo secundario
   time_point<steady_clock> ini_sec = steady_clock::now();
   time_point<steady_clock> instante_fin;
   while( true ) // ciclo principal
   {
      cout << endl
           << "---------------------------------------" << endl
           << "Comienza iteración del ciclo principal." << endl ;

      for( int i = 1 ; i <= 4 ; i++ ) // ciclo secundario (4 iteraciones)
      {
         instante_fin = steady_clock::now();
         milliseconds_f duracion_retraso = instante_fin - ini_sec ;

         cout << endl << "La duración del retraso del ciclo " << i << " ha sido de " << duracion_retraso.count()
         << "  ms" << endl;

         if (duracion_retraso.count() > 20){
            cout << endl << "Duración del retraso > 20 ms. Programa abortado. " << endl;
            exit(0);
         }

         cout << endl << "Comienza iteración " << i << " del ciclo secundario." << endl ;

         switch( i )
         {
            case 1 :  TareaA(); TareaB(); TareaC(); break ;
            case 2 :  TareaA(); TareaB(); TareaD(); break ;
            case 3 :  TareaA(); TareaB(); TareaC(); break ;
            case 4 :  TareaA(); TareaB();           break ;
         }

         // calcular el siguiente instante de inicio del ciclo secundario
         ini_sec += Ts ;

         // esperar hasta el inicio de la siguiente iteración del ciclo secundario
         sleep_until( ini_sec );
         
      }
   }
}
