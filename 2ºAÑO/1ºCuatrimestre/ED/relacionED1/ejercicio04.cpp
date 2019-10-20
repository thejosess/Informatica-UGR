#include <iostream>
#include <string>
#include <queue>

using namespace std;

/**
* @brief función que inserta un valor
* @param la cola ha insertar, la posicion y el valor
* @pre pos <= queue.size()
* @author Jose Santos Salvador
*/
template <typename T>
void insertar(queue<T> &P, int pos, const T &x)
{

	queue<T> aux ;

	int contador = 0;

	while(contador <= P.size() + 1)
	{

		if(pos == contador)
		{

			aux.push(x) ;
			aux.push(P.front());
			P.pop();	
		}

		else
		{
			aux.push(P.front());
			P.pop();	
		}
		contador++ ;
	}

	P = aux ;
}

int main()
{
	queue<int> binaria ;

	//@pre la posicion debe ser igual o menor al tamaño de la pila
	//@brief la posicion donde insertar empieza en el 0
	int pos = 2, valor = 0 ;

	binaria.push(1) ;
	binaria.push(2) ;
	binaria.push(3) ;

	insertar(binaria, pos, valor) ;

	while( !binaria.empty() )
	{
		cout << binaria.front() << endl;
		binaria.pop() ;
	}
}