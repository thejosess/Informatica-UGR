#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

//generador de ejemplos para el problema de la comparación de preferencias. Simplemente se genera una permutación aleatoria del vector 0,1,2,...,n-2,n-1

double uniforme() //Genera un número uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C.
{
 int t = rand();
 double f = ((double)RAND_MAX+1.0);
 return (double)t/f;
}

int main(int argc, char * argv[])
{

  if (argc != 2)
    {
      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
      return -1;
    }

  int n = atoi(argv[1]);

  int * T = new int[n];
  assert(T);

srand(time(0));

for (int j=0; j<n; j++) T[j]=j;
//for (int j=0; j<n; j++) {cout << T[j] << " ";}
//algoritmo de random shuffling the Knuth (permutación aleatoria)
for (int j=n-1; j>0; j--) {
   double u=uniforme();
   int k=(int)(j*u);
   int tmp=T[j];
   T[j]=T[k];
   T[k]=tmp;
}

for (int j=0; j<n; j++) {cout << T[j] << " ";}
cout << endl;

}