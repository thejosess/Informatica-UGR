#include <iostream>
#include <stack>

using namespace std;

/**
* @brief función que sustituye un valor de la pila por otro
* @param pila donde sustituir el valor x por el yç
* @author Jose Santos Salvador
*/

template <typename T>
void sustituye(stack<T> &P, const T &x, const T &y)
{
	stack <T> aux ;

	while( !P.empty() )		//muestra el ultimo
	{
		if(P.top() == x)
			aux.push(y) ;
		else
			aux.push( P.top() ) ;

		P.pop() ;				//saca el ultimo
	}

	while( !aux.empty() )
	{
		P.push( aux.top() ) ;
		aux.pop() ;
	}

}

//stack pila LIFO

int main()
{
	stack <int> pila ;

	pila.push(10) ;
	pila.push(20) ;

	sustituye(pila, 10, 5) ;


	//PARA MOSTRAR LA PILA

	while( !pila.empty() )
	{
		cout << pila.top() << endl;
		pila.pop() ;
	}


}