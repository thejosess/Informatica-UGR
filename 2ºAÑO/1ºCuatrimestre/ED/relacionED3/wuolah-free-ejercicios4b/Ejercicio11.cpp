/*
	Dado un bintree T , organizado como un BST, implementa una función a la que 
	se le pasen dos valores a y b y que determine de forma eficiente los valores 
	presentes en el árbol y que estén comprendidos entre ambos. Tanto a como b 
	no tienen porqué aparecer en el árbol.
*/

#include <iostream>
#include <string>
#include "bst.h"

using namespace std;

void valores_comprendidos( int a, int b, BST<int, string> & A){

	BST<int, string>::iterator i = A.begin();
	cout << "Numeros comprendidos entre " << a << " y " << b << endl;
	for (i; i!=A.end(); ++i)
		if ((*i).first > a && (*i).first < b )
			cout << (*i).first <<  " esta comprendido en el rango de valores " << endl;

}

int main(){

	BST<int, string> Arb;
	Arb.insert(pair<int,string>(1, "nodo 1"));
	Arb.insert(pair<int,string>(7, "nodo 2"));
	Arb.insert(pair<int,string>(9, "nodo 3"));
	Arb.insert(pair<int,string>(10, "nodo 4"));
	Arb.insert(pair<int,string>(13, "nodo 5"));
	Arb.insert(pair<int,string>(3, "nodo 6"));
	Arb.insert(pair<int,string>(5, "nodo 7"));
	Arb.insert(pair<int,string>(8, "nodo 8"));

	BST<int, string>::iterator i;
	cout << endl << "Listado del arbol" << endl;
	for (i= Arb.begin(); i!=Arb.end(); ++i)
		cout << (*i).first << ": " << (*i).second << endl;


	cout << endl << endl;
	BST<int, string>::iterator it = Arb.begin();
	
	valores_comprendidos(3, 10,  Arb);
	
	cout << endl << endl;
}
