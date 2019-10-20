// Ejemplo de uso del tipo BST
// (C) Miguel García Silvente

#include <string>
#include <iostream>
#include "bst.h"
using namespace std;

template <typename K, typename T>
ostream& operator<<(ostream &os, BST<K, T> &dicc)
{
  typename BST<K, T>::iterator i;
  for (i= dicc.begin(); i!=dicc.end(); ++i)
    os << (*i).first << ": " << (*i).second << " " << endl;

  return os;
}

int main()
{
  const int NUM = 1000000;
  BST<int, string> dicc;
 
  for (int i= 0; i<NUM; i++) {
    pair<int, string> aux(rand(), "");
    dicc.insert(aux);
  }

  cout << "Contenido del diccionario" << endl;
  cout << dicc << endl;
     
  return 0;
}
