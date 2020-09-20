//g++ -O2 matrizTraspuesta.cpp -o matrizTraspuesta
//./matrizTraspuesta "TraspuestaNombre.dat" "TraspuestaNombreDyV.dat" 100 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
using namespace std;

void traspuesta(int **m, int **res, int inif, int finf, int inic, int finc){
	if(inif == finf)
		res[inif][inic] = m[inic][inif];
	else
	{
		int centrof = (inif + finf)/2;
		int centroc = (inic + finc)/2;
		
		traspuesta(m, res, inif, centrof, inic, centroc);
		traspuesta(m, res, inif, centrof, centroc + 1, finc);
		traspuesta(m, res, centrof + 1, finf, inic, centroc);
		traspuesta(m, res, centrof + 1, finf, centroc + 1, finc);
	}
}

int main(int argc, char * argv[]){
   int **m, **mt; //m es la matriz normal, mt es la matriz traspuesta.
	int n, i, argumento, x;
   chrono::time_point<std::chrono::high_resolution_clock> t01, t02, tf1, tf2;
	double tejecucion, tejecucion2;
	unsigned long int semilla;
	ofstream fsalidaSin, fsalidaCon;
   
   if (argc < 5){
      cerr << "Formato " << argv[0] << " fichero salida sin DyV" << " fichero salida con DyV" << " semilla" << " tam_matriz1 " << "tam_matriz2 " << "... tam_matrizN" << endl;
      return -1;
   }
   
   fsalidaCon.open(argv[2]);
   fsalidaSin.open(argv[1]);

   if (!fsalidaSin.is_open()) {
		cerr<<"Error: No se pudo abrir fichero para escritura " <<argv[1] <<"\n\n";
		return 0;
	}

   if (!fsalidaCon.is_open()) {
		cerr<<"Error: No se pudo abrir fichero para escritura " <<argv[2] <<"\n\n";
		return 0;
	}
   
   semilla = atoi(argv[3]);
   srand(semilla);

   for(int argumento = 4; argumento < argc; argumento++){
      n = atoi(argv[argumento]);
      m = new int *[n]; 
      mt = new int *[n];

      cout << endl << "Tam caso matriz: " << n << endl;

      //Crear las matrices dinámicas
      for(int i = 0; i < n; i++){
         m[i] = new int[n];
         mt[i] = new int[n];
      }

      //Rellenar la primera matriz con numeros aleatorios
      for(int i = 0; i < n; i++){
         for(int j = 0; j < n; j++){
            m[i][j] = rand();
         }
      }

      //Calculo de la traspuesta sin DyV
      t01 = std::chrono::high_resolution_clock::now();
      for(int i = 0; i < n; i++){
         for(int j = 0; j < n; j++){
            mt[j][i] = m[i][j];
         }
      }
      tf1 = std::chrono::high_resolution_clock::now();

      tejecucion = std::chrono::duration_cast<std::chrono::microseconds>(tf1 - t01).count();
      cout << "Tiempo sin DyV: " << tejecucion << endl;
      fsalidaSin << n << " " << tejecucion << endl;

      //Medir el tiempo de la ejecución con divide y venceras
      t02 = std::chrono::high_resolution_clock::now();
      traspuesta(m, mt, 0, n-1, 0, n-1);
      tf2 = std::chrono::high_resolution_clock::now();

      tejecucion2 = std::chrono::duration_cast<std::chrono::microseconds>(tf2 - t02).count();
      cout << "Tiempo con DyV: " << tejecucion2 << endl;
      fsalidaCon << n << " " << tejecucion2 << endl; 

      //Liberar el espacio dinámico de las matrices
      for(int i = 0; i < n; i++){
         delete [] m[i];
         delete [] mt[i];
      }      
      delete [] m;
      delete [] mt;
   }

   fsalidaCon.close();
   fsalidaSin.close();   
}
