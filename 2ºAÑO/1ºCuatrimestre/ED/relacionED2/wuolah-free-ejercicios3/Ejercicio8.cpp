/*
	Implementa una función que dada una lista l devuelva una lista que tenga los
	elementos de l pero en orden inverso.
*/
#include <iostream>
#include <list>

using namespace std;

list<int> invertir(list<int> l){

	list<int> lista_invertida;
	auto wi = --l.end();	

	for(wi; wi!=l.begin(); --wi)
		lista_invertida.push_back(*wi);

	lista_invertida.push_back(*wi);

	return lista_invertida;
}

int main(){

	list<int> lista_invertida;
	list<int> lista;

	lista.push_back(2);
	lista.push_back(1);
	lista.push_back(1);
	lista.push_back(1);
	lista.push_back(1);
	lista.push_back(5);
	lista.push_back(3);

	lista_invertida = invertir(lista);

	cout << "Lista inicial: " << endl;
	auto wi = lista.begin();

	for(wi; wi!=lista.end(); ++wi)
		cout << *wi << " ";

	cout << endl;

	cout << "Lista inversa: " << endl;
	auto wo = lista_invertida.begin();
	for(wo; wo != lista_invertida.end(); ++wo)
		cout << *wo << " ";

	cout << endl;
}

