/*
	Implementa una función bool contenida(const list<T> &l1, const list<T> &l2)
	a la que se le pases dos listas y compruebe si la lista l1 está contenida en
	l2 (si los elementos aparecen en la otra y en el mismo orden).
*/
#include <iostream>
#include <list>
using namespace std;

bool contenida(list<int> & l1, list<int> & l2){
	bool sublista=false;
	auto it1 = l1.begin();
	auto it2 = l2.begin();

	for( it2; it2 != l2.end(); ++it2){
		it1 = l1.begin();
		if(*it2 == *it1 ){
			sublista=true;
			while(sublista && it1 != l1.end() ){
				if(*it2!=*it1)
					sublista=false;				
				else ++it1, ++it2;
			}
		}
	}
	return(sublista);
}

int main(){

	list<int>lista1,lista2;

	lista1.push_back(1);
	lista1.push_back(1);
	lista1.push_back(2);
	lista1.push_back(2);
	lista1.push_back(2);

	lista2.push_back(1);
	lista2.push_back(1);
	lista2.push_back(2);
	lista2.push_back(2);
	lista2.push_back(2);
	lista2.push_back(3);
	lista2.push_back(5);

	cout << "Lista 1: " << endl;

	auto it1 = lista1.begin();
	for(it1; it1 != lista1.end(); ++it1)
		cout << *it1 << " ";
	cout << endl;

	cout << "Lista 2: " << endl;
	
	auto it2 = lista2.begin();
	for(it2; it2 != lista2.end(); ++it2)
		cout << *it2 << " ";
	cout << endl;

	if (contenida(lista1,lista2))
		cout << "Lista 1 esta contenida en lista 2 " << endl;
	else
		cout << "Lista 1 NO esta contenida en lista 2" << endl;

}
