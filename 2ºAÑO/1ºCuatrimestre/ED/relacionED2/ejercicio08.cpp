#include <iostream>
#include <list>

using namespace std;

/**
* @brief función que invierte una lista
* @param la lista 
* @author Jose Santos Salvador
*/

template <class T>
list<T> inversa(const list<T> &l)
{
	typename list<T>::const_iterator iterator = l.end();
	iterator--;
	list<T> lista;

	while(iterator != l.begin())
	{
		lista.push_back(*iterator);
		iterator--;
	}	
	return lista;
}

int main()
{
	int elementos[] = {2, 1, 1, 1, 1, 5, 3} ;
	list <int> l ( elementos , elementos + 6) ;

	cout << "los elementos de la lista son: ";

	for(list<int>::iterator i = l.begin() ; i != l.end() ; i++)
	{
		cout  << (*i) << " " ;
	}


	cout << "\nlos elementos de la lista tras hacer el eliminado son: ";

	list<int> aux;
	aux = inversa(l) ;

	for(list<int>::iterator i = aux.begin() ; i != aux.end() ; i++)
	{
		cout << (*i) << " " ;
	}

	cout <<endl;
}