#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

//generador de ejemplos para el problema de la serie unimodal de n�meros. Se genera un �ndice aleatorio entre 1 y n-2, se asigna el mayor entero (n-1) a ese �ndice, a los �ndices anteriores a p se le asignan valores en orden creciente (0,1,...,p-1) y a los �ndices mayores que p se le asignan valores en orden decreciente (n-2, n-1,...,p

double uniforme() //Genera un n�mero uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C.
{
double u;
  u = (double) rand();
  u = u/(double)(RAND_MAX+1.0);
 return u;
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
double u=uniforme();
int p=1+(int)((n-2)*u);
T[p]=n-1;
for (int i=0; i<p; i++) T[i]=i;
for (int i=p+1; i<n; i++) T[i]=n-1-i+p;

for (int j=0; j<n; j++) {cout << T[j] << " ";}

}
