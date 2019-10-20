#include <iostream>
#include <list>
#include <typeinfo>

using namespace std;

/**
* @brief función que elimina un valor de la lista
* @param la lista y el elemento a eliminar
* @author Jose Santos Salvador
*/

typename static T value;

bool sentencia(const int & valor)
{
	return (valor==value) ;
}


	//SOY GILIPOLLAS PUEDES HACER UNA CONSTANTE GLOBAL PAPA EN VEZ DE PONER VALOR==1 PONES EN 1 LA CONSTANTE GLOBAL Y LA MODIFICAS EN LA FUNCION ELIMINA

template <class T>
void elimina(list<T> &l, const T &x)
{
	value = x;
	l.remove_if(sentencia);	
	//typename list<T>::iterator iterator;
	//iterator = l.begin();

	/* una forma de hacerlo muy eficiente seria con esta linea

	l.remove_if(sentencia);	

	y directamente poner el valor a eleminar en el funtor sentencia 
	pero no se ajusta con la cabecera y creo que podemos modificarla*/

	/*for(iterator = l.begin() ; iterator != l.end(); iterator++)
	{
		if(*iterator == x)
			l.erase(iterator); 
	}	*/
}

int main()
{

	//INTENTO DE HACERLO TODO CON TEMPLATE HASTA LA RECOGIDA DEL ELEMENTO
	/*template <typename T>
	T x ;

	cout << "Elemento a eliminar de la lista: " << endl;
	cin >> x ;

	typeid(x).name() elementos[] = {2, 1, 1, 1, 1, 5, 3} ;
	list<typeid(x).name()> l (elementos , elementos + 7) ;

	elimina(l,x);

	cout << l.push_back() ;*/

	int elementos[] = {2, 1, 1, 1, 1, 5, 3} ;
	list <int> l ( elementos , elementos + 6) ;

	cout << "los elementos de la lista son: ";

	for(list<int>::iterator i = l.begin() ; i != l.end() ; i++)
	{
		cout  << (*i) << " " ;
	}


	cout << "\nlos elementos de la lista tras hacer el eliminado son: ";

	elimina(l,1) ;

	for(list<int>::iterator i = l.begin() ; i != l.end() ; i++)
	{
		cout << (*i) << " " ;
	}

	cout <<endl;
}