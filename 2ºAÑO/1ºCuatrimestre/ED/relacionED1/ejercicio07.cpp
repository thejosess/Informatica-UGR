#include <iostream>
#include <string>
#include <queue>
#include <queue>


using namespace std;

/**
  *  @brief T.D.A de una cola con dos pilas 
  * @author José Santos Salvador
  */
template <typename T>
class Stack
{
	private:
		queue<T> cola ;
		queue<T> cola2 ;

	public:
		Stack()
		{
			queue<T> cola ;
			queue<T> cola2 ;
		}

		/*Stack(const queue<T>& pila)		
		{								
			this->cola = pila;
		}*/

		Stack(const Stack<T>& c1)
		{
			this->cola = c1.getCola() ;
		}

		queue<T> getCola() const 
		{
			return this->cola ;
		}

		bool operator=(const Stack<T>& c1)
		{
			this->cola = c1.getCola() ;
		}

		bool operator<(const Stack<T>& c1)
		{
			if(this->cola < c1.getCola())
				return true ;
			else
				return false;
		}

		bool operator==(const Stack<T>& c1)
		{
			if(this->cola == c1.getCola())
				return true ;
			else
				return false ;
		}

		void push(T valor)
		{
			cola.push(valor);
		}

		void pop()
		{
			if(cola.size() != 1)
			{
				T aux = cola.back() ;

				while(!cola.empty())
				{
					if(cola.front() == aux)
					{
						cola.pop();
					}
					else
					{
						cola2.push(cola.front());
						cola.pop();
					}
				}

				while(!cola2.empty())
				{
					cola.push(cola2.front());			//AQUI ESTA EL ERROR
					cola2.pop();
				}
	
			}
			
			else
			{
				cola.pop();
			}
		}

		T top()				//arreglar esto
		{
			return cola.back() ;
		}

		bool empty()
		{
			if(cola.empty())
				return true ;
			else
				return false ;
		}

		T size()
		{
			return cola.size() ;
		}
};

int main()
{

	   cout << "*****************************************************************" << endl 
        << "TDA pila CON DOS colas" << endl
        << "*****************************************************************" << endl;

	Stack<int> cola;
	Stack<int> cola2;

	cola.push(2) ;
	cola2.push(2) ;

	cola.push(3);
	cola2.push(3);

	//CREACION DE LAS COLAS E INTRODUCCION DE SUS VALORES

	Stack<int> prueba(cola) ;		//PRUEBA CONSTRUCTOR CON PARAMETROSS

	cout <<  "\nMostrando datos de las colas en el final de la misma(el ultimo en entrar)" << endl
    << "--------------------------------------------------------\n" << endl;

	cout << cola.top() << endl;
	cout << cola2.top() << endl ; 
	cout << prueba.top() << endl ;

	//ELIMINANDO EL PRIMER VALOR QUE HA ENTRADO EN LAS COLAS

	cola.pop() ; 
	cola2.pop() ;
	prueba.pop() ;

	cout <<  "\nMostrando datos de las colas en el final de la misma(el ultimo en entrar) tras hacer pop" << endl
    << "--------------------------------------------------------\n" << endl;

	cout << cola.top() << endl;
	cout << cola2.top() << endl ; 
	cout << prueba.top() << endl ;

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