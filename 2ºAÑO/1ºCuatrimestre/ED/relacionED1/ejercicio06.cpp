#include <iostream>
#include <string>
#include <queue>
#include <stack>


using namespace std;

/**
  *  @brief T.D.A de una cola con dos pilas 
  * @author José Santos Salvador
  */
template <typename T>
class Cola
{
	private:
		stack<T> pila ;
		stack<T> pila2 ;

	public:
		Cola()
		{
			stack<T> pila ;
			stack<T> pila2 ;
		}

		/*Cola(const stack<T>& pila)		
		{								
			this->pila = pila;
		}*/

		Cola(const Cola<T>& c1)
		{
			this->pila = c1.getCola() ;
		}

		stack<T> getCola() const 
		{
			return this->pila ;
		}

		bool operator=(const Cola<T>& c1)
		{
			this->pila = c1.getCola() ;
		}

		bool operator<(const Cola<T>& c1)
		{
			if(this->pila < c1.getCola())
				return true ;
			else
				return false;
		}

		bool operator==(const Cola<T>& c1)
		{
			if(this->pila == c1.getCola())
				return true ;
			else
				return false ;
		}

		void push(T valor)
		{
			pila.push(valor);
		}

		void pop()
		{
			if(pila.size() != 1)
			{
				while(!pila.empty())
				{
					pila2.push(pila.top());
					pila.pop();
				}

				pila2.pop();

				while(!pila2.empty())
				{
					pila.push(pila2.top());			//AQUI ESTA EL ERROR
					pila2.pop();
				}
	
			}
			
			else
			{
				pila.pop();
			}
		}

		T front()				
		{
			if(pila.size() != 1)
			{
				while(!pila.empty())
				{
					pila2.push(pila.top());
					pila.pop();
				}

				return pila2.top();
			}
			
			else
			{
				return pila.top();
			}
		}

		T back()
		{
			return pila.top();
		}

		bool empty()
		{
			if(pila.empty())
				return true ;
			else
				return false ;
		}

		T size()
		{
			return pila.size() ;
		}
};

int main()
{

	   cout << "*****************************************************************" << endl 
        << "TDA COLA CON DOS PILAS" << endl
        << "*****************************************************************" << endl;

	Cola<int> cola;
	queue<int> cola2;

	cola.push(2) ;
	cola2.push(2) ;

	cola.push(3);
	cola2.push(3);

	//CREACION DE LAS COLAS E INTRODUCCION DE SUS VALORES

	Cola<int> prueba(cola) ;		//PRUEBA CONSTRUCTOR CON PARAMETROSS

	cout <<"\nMostrando datos de las colas en el frente de la misma" << endl
    << "--------------------------------------------------------\n" << endl;

	cout << cola.front() << endl;
	cout << cola2.front() << endl ; 
	cout << prueba.front() << endl;

	//ELIMINANDO EL PRIMER VALOR QUE HA ENTRADO EN LAS COLAS

	cola.pop() ; 
	cola2.pop() ;
	prueba.pop() ;

	cout <<  "\nMostrando datos de las colas en el final de la misma" << endl
    << "--------------------------------------------------------\n" << endl;

	cout << cola.back() << endl;
	cout << cola2.back() << endl ; 
	cout << prueba.back() << endl ;

	cout << "\nMostrando datos de las colas en el frente de la misma otra vez" << endl
    << "--------------------------------------------------------\n" << endl;

	cout << cola.front() << endl;
	cout << cola2.front() << endl ; 
	cout << prueba.front() << endl ;

	cout << "\nProbando la funcion size()" << endl
    << "--------------------------------------------------------\n" << endl;

    cout << cola.size() << endl;

	cout << "\nProbando la funcion empty()" << endl
    << "--------------------------------------------------------\n" << endl;

    if(cola.empty())
    	cout << "La pila esta vacia" << endl ;
    else
    	cout << "La pila no esta vacia" << endl ;

	cout << "\nProbando la sobrecarga del operador = y ==" << endl
    << "--------------------------------------------------------\n" << endl;

    prueba.push(5);
    prueba = cola ;

    if(prueba == cola)
    	cout << "Son iguales" << endl ;
    else
    	cout << "No son iguales" << endl ;

    cout << "\nProbando la sobrecarga del operador  < "<< endl
    << "--------------------------------------------------------\n" << endl;

    prueba.push(5) ;

    cout << "La pila 1 contiene un valor mas que la pila 2\n" << endl ;

    if(prueba < cola)
    	cout << "La pila 2 es mayor que la pila 1" << endl ;
    else
    	cout << "La pila 1 es mayor que la pila 2" << endl ;

}