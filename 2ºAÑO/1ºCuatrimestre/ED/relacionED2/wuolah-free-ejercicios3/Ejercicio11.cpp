/*
	Implementa una función a la que se le pase una lista de enteros y un entero
	x de manera que cada vez que aparezca en una posición ese valor, se inserte
	x-1 en la posición siguiente.
*/
#include <iostream>
#include <list>

using namespace std;

void insertar(list<int> & l, int x){

	auto wi=l.begin();
	list<int>::iterator sig;

	for(wi; wi != l.end(); ++wi){
		sig=wi;
		++sig;
		if(*wi == x)
			l.insert(sig,x-1);
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

	cout << "Lista inicial :		" << endl;
	auto wi = lista.begin();
	for(wi; wi != lista.end(); ++wi)
		cout << *wi << " ";

	cout << endl;

	insertar(lista,3);

	cout << "Lista final :		" << endl;
	
	auto wo = lista.begin();
	for(wo; wo !=lista.end(); ++wo)
		cout << *wo << " ";

	cout << endl;
}
