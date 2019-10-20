/*
	Una forma eficiente de guardar secuencias de valores iguales consiste en 
	guardar cada uno de los valores seguidos del número de veces que aparece en 
	la secuencia. Por ejemplo,

	<1,1,1,2,2,2,2,2,2,7,7,7,7,7,12,1,1,5,5>
	< (1,3), (2,6), (7,5), (12,1), (1,2), (5,2) > 

	Implementa las funciones:

	list<pair<T, int> > comprimir(const list<T> &l) +
	list<T> descomprimir(const list<pair<T, int> > &lc)

	que permitan convertir entre ambas representaciones.
*/
#include <iostream>
#include <list>

using namespace std;

template<typename T>
list<pair<T,int> >comprimir(const list<T> &l){

	list<pair<T,int> > resultado;
	int n_apariciones;
	bool iguales;

	auto it1=l.begin();
	auto it2=l.begin();

	while(it1 != l.end() && it2 != l.end() ){
		n_apariciones = 0;
		it1 = it2;
		iguales = true;

		while(iguales){
			if(*it1 == *it2){
				++n_apariciones;
				++it2;
			}
			else
				iguales=false;
		}
		
		pair<T,int> parlista(*it1, n_apariciones);
		resultado.push_back(parlista);	
		++it1;	
	}
	return resultado;
}

template<typename T>
list<T> descomprimir(const list<pair<T,int> > &lc){
	auto wi = lc.begin();
	list<T> resultado;
	for( wi; wi != lc.end(); ++wi)
		for(int i=0 ; i<wi->second; ++i)
			resultado.push_back(wi->first);

	return resultado;
}

int main(){
	list<int>lista1, lista_descomprimida;
	list<pair<int,int> > lista2;

	lista1.push_back(1);
	lista1.push_back(1);
	lista1.push_back(1);
	lista1.push_back(2);
	lista1.push_back(2);
	lista1.push_back(2);
	lista1.push_back(2);
	lista1.push_back(2);
	lista1.push_back(2);
	lista1.push_back(7);
	lista1.push_back(7);
	lista1.push_back(7);
	lista1.push_back(7);
	lista1.push_back(7);
	lista1.push_back(12);
	lista1.push_back(1);
	lista1.push_back(1);
	lista1.push_back(5);
	lista1.push_back(5);

	cout << "Lista: " << endl;
	auto wi = lista1.begin();
	for(wi; wi != lista1.end(); ++wi)
		cout << *wi << " ";
	
	cout << endl << endl;

	lista2=comprimir(lista1);

	cout << "Lista comprimida: " << endl;
	auto itpar = lista2.begin();

	for(itpar; itpar != lista2.end(); ++itpar)
		cout << "(" << itpar->first << "," << itpar->second  << ")  ";

	cout << endl << endl;

	lista_descomprimida =descomprimir(lista2);

	cout << "Lista descomprimida" << endl;

	auto we = lista_descomprimida.begin();
	for(we; we != lista_descomprimida.end(); ++we)
		cout << *we << " ";
	
	cout << endl << endl;

}
