#include <iostream>
#include "ABB.hpp"
#include <queue>
#include <stack>
#include<iostream>
using namespace std;

int main(int argc, const char * argv[]) {
  ABB<int> arbol;
  
//  const int N = 10;
//  const float max = 100.0;
//  srand((unsigned)time(NULL));
//  for(int i=0; i<N; i++)
//    arbol.insertar((int) (max*rand()/RAND_MAX));
  
  float datos[8] = {5,3,8,1,4,6,9,7};
  
  for(int i=0; i<8; i++)
    arbol.insertar(datos[i]);
  
  cout << "Árbol resultante:" << endl;
  cout << arbol;
  
  arbol.Esquema();
  
  cout << endl;

  arbol.ImprimeProfundidad();
  cout << endl;
  
  return 0;
}
