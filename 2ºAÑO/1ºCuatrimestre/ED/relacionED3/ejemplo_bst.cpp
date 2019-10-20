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
  const int NUM = 6;
  BST<string, string> dicc;
  string palabras[NUM] = {"piedra", "tiza", "diamante", "rosa", "adoquin", "margarita"};
  string definiciones[NUM] = {"objeto muy duro", "objeto muy blando", "objeto muy duro", "tipo de flor", "objeto duro o persona intransigente", "flor utilizada para tomar decisiones importantes"};
  
  for (int i= 0; i<NUM; i++) {
    pair<string, string> aux(palabras[i], definiciones[i]);
    dicc.insert(aux);
    cout << "Num.datos: " << dicc.size() << endl;
    if (dicc.find(palabras[i])!=dicc.end())
      cout << "Clave " << palabras[i] << " insertada correctamente" << endl;
    else
      cerr << "Clave " << palabras[i] << "no insertada" << endl;
  }

  BST<string, string>::iterator i;
  cout << "Listado del árbol" << endl;
  for (i= dicc.begin(); i!=dicc.end(); ++i)
    cout << (*i).first << ": " << (*i).second << endl;

  cout << "Contenido del diccionario" << endl;
  cout << dicc << endl;
  dicc.erase("tiza"); 
  cout << "Contenido del diccionario" << endl;
  cout << dicc << endl;
  
  cout << "Contenido del diccionario" << endl;
  cout << dicc << endl;
  dicc.erase("piedra"); 
  cout << "Contenido del diccionario" << endl;
  cout << dicc << endl;
     
  return 0;
}
