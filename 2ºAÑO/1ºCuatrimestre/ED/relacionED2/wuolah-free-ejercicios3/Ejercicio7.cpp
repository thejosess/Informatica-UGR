/*
	Implementa una función elimina_duplicados(list<T> &l) que elimine los 
	elementos duplicados (sin ordenar previamente la lista).
*/
#include <iostream>
#include <list>

using namespace std;

void elimina_duplicados(list<int> &l){

	auto wi_inicio = l.begin();
	list<int>::iterator wi_fin;

	for( wi_inicio; wi_inicio != l.end(); ++wi_inicio){
		wi_fin = wi_inicio;
		++wi_fin;

		while(wi_fin != l.end() ){
			if(*wi_inicio == *wi_fin)
				wi_fin = l.erase(wi_fin);
			else ++wi_fin;
		}
	}
}

int main(){
	
	list<int> lista;

	lista.push_back(2);
	lista.push_back(1);
	lista.push_back(1);
	lista.push_back(2);
	lista.push_back(5);
	lista.push_back(5);
	lista.push_back(3);

	cout << "Lista inicial: " << endl;
	auto wi = lista.begin();
	for(wi; wi!=lista.end(); ++wi)
		cout << *wi << " ";

	cout << endl;

	elimina_duplicados(lista);

	cout << "Lista final: " << endl;

	auto wo = lista.begin();
	for(wo; wo!=lista.end(); ++wo)
		cout << *wo << " ";

	cout << endl;


	return 0;
}
