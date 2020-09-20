#include <iostream>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <chrono>
#include <fstream> // Para usar ficheros
#include <string>
using namespace std;


void reajustar( int T[], int num_elem, int k)
{
    int j;
    int v;
    v = T[k];
    bool esAPO = false;
    while((k < num_elem/2) && !esAPO)
    {
        j = k + k + 1;
        if((j < (num_elem - 1)) && (T[j] < T[j+1]))
        j++;
            if( v >= T[j])
        esAPO = true;
            T[k] = T[j];
            k = j;
    }
    T[k] = v;
}


void heapsort(int T[], int num_elem)
{
    int i ;
    for(i = num_elem / 2; i >= 0; i--)
        reajustar(T, num_elem, i);
    for(i = num_elem -1 ; i>= 1; i--)
        {
            int aux = T[0];
            T[0] = T[i];
            T[i] = aux;
            reajustar(T, i, 0);
        }
}



int main(int argc, char * argv[])
{

	ofstream fsalida;

  	if (argc <= 3)
    {
    	cout<<"\nError: El programa se debe ejecutar de la siguiente forma.\n\n";
    	cout<<argv[0]<<" NombreFicheroSalida Semilla tamCaso1 tamCaso2 ... tamCasoN\n\n";
      
      return -1;
    }

  	srandom(atoi(argv[2]));

  	fsalida.open(argv[1]);
	if (!fsalida.is_open()) {
		cerr<<"Error: No se pudo abrir fichero para escritura "<<argv[1]<<"\n\n";
		return 0;
	}

	for(int argumento=3; argumento<argc; argumento++){
		int n = atoi(argv[argumento]);

  		int * T = new int[n];
  		assert(T);
  		
  		for (int i = 0; i < n; i++)
    	{
      		T[i] = random();
    	};
		cerr << "Ejecutando Mergesort para tam. caso: " << n << endl;
		chrono::high_resolution_clock::time_point t_antes = chrono::high_resolution_clock::now();
  		heapsort(T, n);
  		chrono::high_resolution_clock::time_point t_despues = chrono::high_resolution_clock::now();
  		unsigned long t_ejecucion = chrono::duration_cast<std::chrono::microseconds>(t_despues - t_antes).count();
  		cout << "\tTiempo de ejec. (us): " << t_ejecucion << " para tam. caso "<< n<<endl;
  		fsalida<<n<<" "<<t_ejecucion<<"\n";
  		delete [] T;
	}

	fsalida.close();
  	

	return 0;
};
