// -----------------------------------------------------------------------------
// 
// Miguel Ángel Benítez Alguacil	75577060A
//
//   Datos de las tareas:
//   ------------
//   Ta.   T    C
//   ------------
//   A   500  100
//   B   500  150
//   C  1000  200
//   D  2000  240
//  -------------
//
//  Planificación (con Ts == 500 ms)
//  *---------*---------*---------*-------*
//  | A B C   | A B D   | A B C   | A B   |
//  *---------*---------*---------*-------*
//
// Respuesta a las preguntas:
/*
1. ¿ cual es el mínimo tiempo de espera que queda al final de las iteraciones del 
	ciclo secundario con tu solución ?
Ciclo 1 --> A + B + C = 100 + 150 + 200	=> 50ms
Ciclo 2 --> A + B + D = 100 + 150 + 240	=> 10ms
Ciclo 3 --> A + B + C = 100 + 150 + 200	=> 50ms
Ciclo 4 --> A + B     = 100 + 150 	=> 250ms
	El mínimo tiempo serían 10ms.

2. ¿ sería planificable si la tarea D tuviese un tiempo cómputo de 250 ms ?
	Teóricamente sí, porque sería un ciclo justo, pero en la práctica no porque en la
	siguiente iteración empezará con un pequeño retraso.
*/
// -----------------------------------------------------------------------------

#include <string>
#include <iostream> // cout, cerr
#include <thread>
#include <chrono>   // utilidades de tiempo
#include <ratio>    // std::ratio_divide

using namespace std ;
using namespace std::chrono ;
using namespace std::this_thread ;

// tipo para duraciones en segundos y milisegundos, en coma flotante:
typedef duration<float,ratio<1,1>>    seconds_f ;
typedef duration<float,ratio<1,1000>> milliseconds_f ;

const int	// tiempo que tarda cada tarea
	T_A = 100 ,
	T_B = 150 ,
	T_C = 200 ,
	T_D = 240 ;

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

void TareaA() { Tarea( "A", milliseconds(T_A) );  }
void TareaB() { Tarea( "B", milliseconds(T_B) );  }
void TareaC() { Tarea( "C", milliseconds(T_C) );  }
void TareaD() { Tarea( "D", milliseconds(T_D) );  }

// -----------------------------------------------------------------------------
// implementación del ejecutivo cíclico:

int main( int argc, char *argv[] )
{
   // Ts = duración del ciclo secundario
   const milliseconds Ts( 500 );

   // ini_sec = instante de inicio de la iteración actual del ciclo secundario
   time_point<steady_clock> ini_sec = steady_clock::now(), ini_fin;
   milliseconds_f duracion_real, duracion_teorica, retraso ;

   while( true ) // ciclo principal
   {
      cout << endl
           << "---------------------------------------" << endl
           << "Comienza iteración del ciclo principal." << endl ;

      for( int i = 1 ; i <= 4 ; i++ ) // ciclo secundario (4 iteraciones)
      {
         cout << endl << "Comienza iteración " << i << " del ciclo secundario." << endl ;

         switch( i )
         {
            case 1 : 
		TareaA(); TareaB(); TareaC();           
		duracion_teorica = milliseconds_f(T_A + T_B + T_C);
		break ;

            case 2 : 
		TareaA(); TareaB(); TareaD(); 
		duracion_teorica = milliseconds_f(T_A + T_B + T_D);
		break ;

            case 3 : 
		TareaA(); TareaB(); TareaC();   
		duracion_teorica = milliseconds_f(T_A + T_B + T_C);        
		break ;

            case 4 : 
		TareaA(); TareaB();   
		duracion_teorica = milliseconds_f(T_A + T_B);       
		break ;
         }
	 
	 // calcular cuando acaban de ejecutarse las tareas
	 ini_fin = steady_clock::now();
	 duracion_real = milliseconds_f(ini_fin - ini_sec) ;

	 cout << endl << "La duracion teórica es: " << duracion_teorica.count() << " milisegundos." << endl ;
	 cout << "La duracion real es: " << duracion_real.count() << " milisegundos." << endl ;
	 

	 // calcular el retraso
	 retraso = milliseconds_f(duracion_real - duracion_teorica);
	 cout << "El retraso es de: " << retraso.count() << " milisegundos." << endl ;

	 // comprobar que la duracion es la correcta (duracion teórica no difiere en más de 20 milisegundos de la real)
	 if (retraso >= milliseconds_f(20)){
		cout << "Error, el retraso es mayor de 20 milisegundos. Programa abortado" << endl;
		exit(-1);
	 }
	
         // calcular el siguiente instante de inicio del ciclo secundario
         ini_sec += Ts ;

         // esperar hasta el inicio de la siguiente iteración del ciclo secundario
         sleep_until( ini_sec );
      }
   }
}
