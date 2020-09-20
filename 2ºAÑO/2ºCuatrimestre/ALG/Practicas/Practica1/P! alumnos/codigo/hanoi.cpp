/**
   @file Resoluci�n del problema de las Torres de Hanoi
*/

   
#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib> // Para usar srand y rand
#include <chrono>
#include <fstream> // Para usar ficheros


/**
   @brief Resuelve el problema de las Torres de Hanoi
   @param M: n�mero de discos. M > 1.
   @param i: n�mero de columna en que est�n los discos.
             i es un valor de {1, 2, 3}. i != j.
   @param j: n�mero de columna a que se llevan los discos.
             j es un valor de {1, 2, 3}. j != i.

   Esta funci�n imprime en la salida est�ndar la secuencia de 
   movimientos necesarios para desplazar los M discos de la
   columna i a la j, observando la restricci�n de que ning�n
   disco se puede situar sobre otro de tama�o menor. Utiliza
   una �nica columna auxiliar.
*/
void hanoi (int M, int i, int j);




void hanoi (int M, int i, int j)
{
  if (M > 0)
    {
      hanoi(M-1, i, 6-i-j);
      hanoi (M-1, 6-i-j, j);
  }
}

int main(int argc, char *argv[])
{
  chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
	double tejecucion; // tiempo de ejecucion del algoritmo en ms
  int n, i, argumento;

  ofstream fsalida;

	if (argc <= 2) {
		cerr<<"\nError: El programa se debe ejecutar de la siguiente forma.\n\n";
		cerr<<argv[0]<<" NombreFicheroSalida tamCaso1 tamCaso2 ... tamCasoN\n\n";
		return 0;
	}

// Abrimos fichero de salida
	fsalida.open(argv[1]);
	if (!fsalida.is_open()) {
		cerr<<"Error: No se pudo abrir fichero para escritura "<<argv[1]<<"\n\n";
		return 0;
	}
	
	// Pasamos por cada tamaÒo de caso
	for (argumento= 2; argumento<argc; argumento++) {
		
		// Cogemos el tamanio del caso
		n= atoi(argv[argumento]);
		
		cerr << "Ejecutando Hanoi para tam. caso: " << n << endl;
		
		t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
		hanoi(n, 1, 2); // Ejecutamos el algoritmo para tamaÒo de caso tam
		tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo
		
		unsigned long tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();
		
		cerr << "\tTiempo de ejec. (us): " << tejecucion << " para tam. caso "<< n<<endl;
		
		// Guardamos tam. de caso y t_ejecucion a fichero de salida
		fsalida<<n<<" "<<tejecucion<<"\n";
	}
	
	// Cerramos fichero de salida
	fsalida.close();

  return 0;
}
