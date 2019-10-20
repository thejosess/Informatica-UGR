#include <iostream>
#include <list>

using namespace std;

/**
* @brief función que elimina los valores repetidos de la lista
* @param la lista 
* @author Jose Santos Salvador
*/

template <class T>
void elimina_duplicados(list<T> &l)
{
	typename list<T>::iterator i;
	typename list<T>::iterator j,aux;

	i=l.begin();

	while(i != l.end())			//recorres la elemento a elemento
	{
		j = i;
		j++;					//colocas el iterador en la posicion siguiente a i
		while(j!=l.end())		//recorres toda la lista comparando cada elemento
		{
			if((*i) == (*j))
				j = l.erase(j);
			else
			{
				j++;
			}
		}
		i++;
	}
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

	elimina_duplicados(l) ;

	for(list<int>::iterator i = l.begin() ; i != l.end() ; i++)
	{
		cout << (*i) << " " ;
	}

	cout <<endl;
}