/*
	Resuelve el problema anterior pero sobre la lista pasada por referencia.
*/
#include <iostream>
#include <list>

using namespace std;

void invertir(list<int> & l){

	auto izda = l.begin();
	auto dcha = --l.end();

	int tam=l.size();
	int aux;

	for( int i=0; i<tam/2;	i++){
		aux=*izda;
		*izda=*dcha;
		*dcha=aux;
		--dcha,++izda;
	}
}

int main(){
	list<int>lista;

	lista.push_back(2);
	lista.push_back(1);
	lista.push_back(1);
	lista.push_back(1);
	lista.push_back(1);
	lista.push_back(5);
	lista.push_back(3);

	cout << "Lista inicial: " << endl;
	auto wi = lista.begin();

	for(wi; wi !=lista.end(); ++wi)
		cout << *wi << " ";

	invertir(lista);
	cout << endl;

	cout << "Lista inversa: " << endl;
	auto wo = lista.begin();
	
	for(wo; wo != lista.end(); ++wo)
		cout << *wo << " ";
	
	cout << endl;
}


