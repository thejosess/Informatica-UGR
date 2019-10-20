/*
	Tenemos dos listas: l, que contiene n elementos y otra li que contiene una 
	serie de posiciones de la lista anterior (valores de la clase iterador). 
	Construye una función a la que se le pasen esas dos listas y devuelva otra 
	que contenga los elementos de l indicados por las posiciones de la lista li.
*/
#include <iostream>
#include <list>

using namespace std;

int get_elemento(int pos, list<int>l)
{
	auto wi=l.begin();
	for(int i=0 ; i<pos; ++i)
		++wi;
	return *wi;
}
list<int> obtener_lista(list<int> & l, list<int> & li){

	auto we = li.begin();
	list<int>lista_resultante;

	for(we; we != li.end(); ++we){
		if(*we < l.size() )
			lista_resultante.push_back(get_elemento(*we,l)); //elemento de *it,l
		else
			cout << "La posicion " << *we << " no es valida" << endl;
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

	lista2.push_back(4);
	lista2.push_back(1);
	lista2.push_back(2);
	lista2.push_back(2);
	lista2.push_back(3);
	lista2.push_back(5);
	lista2.push_back(5);
	

	cout << "Lista de valores : " << endl;
	auto it1 = lista1.begin();
	for(it1 ;it1 != lista1.end(); ++it1)
		cout << *it1 << " ";

	cout << endl;

	cout << "Lista de posiciones: " << endl;
	auto it2 = lista2.begin();
	for(it2; it2 != lista2.end(); ++it2)
		cout << *it2 << " ";

	cout << endl;

	cout << "Lista (a partir de lista 1) formada con  las posiciones en lista 2" 
		 << endl; 

	lista_resultante = obtener_lista(lista1,lista2);

	auto wi = lista_resultante.begin();
	for(wi; wi != lista_resultante.end(); ++wi)
		cout << *wi << " ";
	cout << endl;
}
