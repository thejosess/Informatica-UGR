/*
	Implementa una función lis<l> mezclar(const list<l> &l1, const list<l> &l2)
	que dadas dos listas ordenadas l1 y l2 devuelva una lista ordenada mezclando
	las dos listas.
*/
#include <iostream>
#include <list>
using namespace std;

list<int> mezclarListas(list<int> l1, list<int> l2){

	list<int>lista_resultante;
	auto it1 = l1.begin();
	auto it2 = l2.begin();

	while( it1 != l1.end() && it2 != l2.end()){
		if(*it1 <= *it2){
			lista_resultante.push_back(*it1);
			++it1;
		}
		else{
			lista_resultante.push_back(*it2);
			++it2;		
		}
	}

	while(it1 != l1.end() ){
		lista_resultante.push_back(*it1);
		++it1;		
	}

	while(it2 != l2.end() ){
		lista_resultante.push_back(*it2);
		++it2;		
	}

	return lista_resultante;	
}

int main(){

	list<int>lista1,lista2, lista_resultante;

	lista1.push_back(1);
	lista1.push_back(1);
	lista1.push_back(1);
	lista1.push_back(1);
	lista1.push_back(2);
	lista1.push_back(3);
	lista1.push_back(5);

	lista2.push_back(1);
	lista2.push_back(1);
	lista2.push_back(2);
	lista2.push_back(2);
	lista2.push_back(3);
	lista2.push_back(5);
	lista2.push_back(5);

	cout << "Lista 1 :	 " << endl;
	auto it1 = lista1.begin();
	for(it1; it1 != lista1.end(); ++it1)
		cout << *it1 << " ";

	cout << endl;

	cout << "Lista 2 :	 " << endl;
	auto it2 = lista2.begin();
	for(it2;it2 != lista2.end(); ++it2)
		cout << *it2 << " ";

	cout << endl;

	lista_resultante = mezclarListas(lista1,lista2);

	cout << "Lista mezclada y ordenada :	" << endl;
	auto it3 = lista_resultante.begin();
	for(it3; it3 != lista_resultante.end(); ++it3)
		cout << *it3 << " ";

	cout << endl;
}
