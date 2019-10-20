// -----------------------------------------------------------------------------
// 
// Miguel Ángel Benítez Alguacil	75577060A
// 
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
	T_B = 80 ,
	T_C = 50 ,
	T_D = 40 ,
	T_E = 20 ;

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
void TareaE() { Tarea( "E", milliseconds(T_E) );  }

// -----------------------------------------------------------------------------
// implementación del ejecutivo cíclico:

int main( int argc, char *argv[] )
{
   // Ts = duración del ciclo secundario
   const milliseconds Ts( 250 );

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
		TareaA(); TareaB(); TareaD(); TareaE(); 
		duracion_teorica = milliseconds_f(T_A + T_B + T_D + T_E);
		break ;

            case 3 : 
		TareaA(); TareaB(); TareaC();   
		duracion_teorica = milliseconds_f(T_A + T_B + T_C);        
		break ;

            case 4 : 
		TareaA(); TareaB(); TareaD();   
		duracion_teorica = milliseconds_f(T_A + T_B + T_D);       
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
