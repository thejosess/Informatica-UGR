#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <math.h>


using namespace std;

/**
  *  @brief T.D.A de ventana
  * @author José Santos Salvador
  */
template <typename T>
class Ventana
{
	private:
		stack<T> pila ;
		stack<T> pila2 ;

	public:
		Ventana()
		{
			stack<T> pila ;
			stack<T> pila2 ;			
		}

		void insertar(T elemento)
		{
			pila.push(elemento);
		}

		void moverIzquierda()
		{
			pila.push(pila2.top());
			pila2.pop();
		}

		void moverDerecha()
		{
			pila2.push(pila.top());
			pila.pop();
		}

		void borrar()
		{
			pila.pop();
		}

		T topIzquierda()
		{
			return pila.top();
		}

		T topDerecha()
		{
			return pila2.top();
		}

		void printIzquierda()
		{
			while(!pila.empty())
			{
				cout << pila.top() << endl;
				pila.pop();
			}
		}

		void printDerecha()
		{
			while(!pila2.empty())
			{
				cout << pila2.top() << endl;
				pila2.pop();
			}
		}
};

int main()
{

cout << "*****************************************************************" << endl 
        << "TDA VENTANA" << endl
        << "*****************************************************************" << endl;

cout <<"\nInsertando 3 y 4 en la ventana por ese orden" << endl
    << "--------------------------------------------------------\n" << endl;

	Ventana<int> ventana ;
	ventana.insertar(3);
	ventana.insertar(4);

cout <<"\nMoviendo el valor 4 a la derecha de la ventana" << endl
    << "--------------------------------------------------------\n" << endl;

	ventana.moverDerecha();


cout <<"\nMostrando el valor top del lado izquierdo de la ventana" << endl
    << "--------------------------------------------------------\n" << endl;	

	cout << ventana.topIzquierda() << endl;

cout <<"\nMostrando el valor top del lado derecho de la ventana" << endl
    << "--------------------------------------------------------\n" << endl;

	cout << ventana.topDerecha() << endl;


cout <<"\nInsertando numerosos valores en la ventana y mover a la derecha algunos" << endl
    << "--------------------------------------------------------\n" << endl;	

	ventana.insertar(1);
	ventana.insertar(2);
	ventana.insertar(3);
	ventana.insertar(4);
	ventana.insertar(5);
	ventana.insertar(6);	

	ventana.moverDerecha();
	ventana.moverDerecha();
	ventana.moverDerecha();	

cout <<"\nMostrando los valores de la ventana lado derecho" << endl
    << "--------------------------------------------------------\n" << endl;

	ventana.printDerecha();


cout <<"\nMostrando los valores de la ventana lado izquierda" << endl
    << "--------------------------------------------------------\n" << endl;

	ventana.printIzquierda();

}