#include <iostream>
#include <string>
#include <stack>

using namespace std;

/**
* @brief función que inserta un valor
* @param la pila ha insertar, la posicion y el valor
* @pre pos <= stack.size()
* @author Jose Santos Salvador
*/
template <typename T>
void insertar(stack<T> &P, int pos, const T &x)
{
	stack<T> aux ;

	int contador = P.size() - 1;

	while(!P.empty())
	{

		if(pos == contador)
		{
			if(pos == 0) 
			{
				aux.push(P.top());
				aux.push(x) ;
				P.pop();			
			}

			else
			{
				aux.push(x) ;
				aux.push(P.top());
				P.pop();
			}
		}
		else
		{
			aux.push(P.top());
			P.pop();	
		}
		contador-- ;
	}

	while( !aux.empty() ) 
	{
		P.push( aux.top() ) ;
		aux.pop() ;
	}
}

int main()
{
	stack<int> binaria ;

	int pos = 3, valor = 0 ;

	binaria.push(1) ;
	binaria.push(2) ;
	binaria.push(3) ;	
	binaria.push(4) ;

	insertar(binaria, pos, valor) ;

	while( !binaria.empty() )
	{
		cout << binaria.top() << endl;
		binaria.pop() ;
	}


}