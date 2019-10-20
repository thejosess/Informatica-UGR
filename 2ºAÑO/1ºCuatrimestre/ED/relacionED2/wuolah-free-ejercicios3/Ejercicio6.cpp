/*
	Implementa una función que, dada una lista l de tipo T y un elemento x de 
	tipo T, elimine el elemento x de todas las posiciones en las que aparezca en
	l. Por ejemplo: si x = 1 y l = (2,1,1,1,1,5,3) el resultado debería ser 
	(2,5,3)
*/
#include<iostream>
#include <list>

using namespace std;

void elimina_elemento(list<int> &l,  int elem){

	auto wi = l.begin();

	while(wi != l.end()){
		if( *wi == elem)
			wi = l.erase(wi);
		else ++wi;
	}
}

int main(){

	list<int> lista;

	lista.push_back(2);
	lista.push_back(1);
	lista.push_back(1);
	lista.push_back(1);
	lista.push_back(1);
	lista.push_back(5);
	lista.push_back(3);

	auto wi =lista.begin();

	
	cout << "Lista inicial: " << endl;
	for(wi; wi != lista.end(); ++wi)
		cout << *wi << " ";

	elimina_elemento(lista, 1);
	cout << endl;

	cout << "Lista final: " << endl;

	auto wo = lista.begin();
	
	for(wo; wo!=lista.end(); ++wo)
		cout << *wo << " ";

	cout << endl;
}

