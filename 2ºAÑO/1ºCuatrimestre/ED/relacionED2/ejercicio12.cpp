#include <iostream>
#include <list>

using namespace std;

/**
* @brief función que invierte una lista
* @param la lista 
* @author Jose Santos Salvador
*/

template <class T>
bool iguales(T valor1, T valor2)
{
	return valor1==valor2
}

template <class T>
bool contenida(const list<T> &l1, const list<T> &l2)
{
	l1.merge(l2,iguales)	//al pasarlos constantes no funciona
}

int main()
{
	int elementos[] = {2, 1, 1, 1, 1, 5, 3} ;
	list <int> l1 ( elementos , elementos + 6) ;

	cout << "los elementos de la lista 1 son: ";

	for(list<int>::iterator i = l.begin() ; i != l.end() ; i++)
	{
		cout  << (*i) << " " ;
	}

	int elementos[] = {2, 1, 1, 1} ;
	list <int> l2 ( elementos , elementos + 4) ;

	cout << "los elementos de la lista 2 son: ";

	for(list<int>::iterator i = l.begin() ; i != l.end() ; i++)
	{
		cout  << (*i) << " " ;
	}

	if(contenida(l1,l2))
		cout << "Esta contenida" << endl;
	else
		cout <<"No esta contenida" << endl;


}