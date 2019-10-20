#include "bintree.h"
#include <iostream>

using namespace std;

template  <class T>
typename bintree<T>::node mas_profunda(const bintree<T> &Arb)
{
	typename bintree<T>::node v = Arb.root();
	typename bintree<T>::node izquierda, derecha;
	int intIzquierda = 0 , intDerecha = 0 ; 
	profundidadRecursiva(v.left(),izquierda,intIzquierda,0);
	profundidadRecursiva(v.right(), derecha, intDerecha,0);

	if(intIzquierda > intDerecha)
		return izquierda;
	else
		return derecha;
}

//@pre que el nodo esté dentro de ese arbol que le pasas
template  <class T>
int nivel(const bintree<T> &Arb, typename bintree<T>::node n)
{
	int nivel = 0 , nivel2 = 0;
	bool encontrado = false;
	bool primeravez = true;
	typename bintree<T>::node nodo;
	nodo = Arb.root();

	//nodo = nodo.parent();

	while()

	while(!encontrado)		//esto seria para resolver el ejercicio recorriendo 
							// el arbol y comparando si lo encuentras y llevando el contado nivel

	{
		//padre = nodo.parent();
		if(nodo == n)
			encontrado = true;
		else if(!subimos)
		{
			if(!nodo.left().null())
			{
				nodo = nodo.left();
				primeravez = true;

			}
			else if (!nodo.right().null())
			{
				nodo = nodo.right();
				primeravez = true;
			}
			else
			{
				if(!primeravez)
				{
					nodo = nodo.parent().parent();
					subimos = true;
				}
				else
				{
					subimos = true;
					nodo = nodo.parent();
				}
			}
		}
		else
		{
			if(!nodo.right().null())
			{
				nodo = nodo.right();
				primeravez = false;
				subimos = false;
			}
			else if (/* condition */)
			{
				/* code */
			}
		}
		typename bintree<T>::node de = nodo.right();
		typename bintree<T>::node iz = nodo.left();
	}
	//cuando encuentres el nodo vas haciendo ++ al nivel hasta llegar a raiz
}


template  <class T>
int profundidadRecursiva(const typename bintree<T>::node & n, const typename bintree<T>::node & nodo int &profundidadMax int &profundidad)
{
	const typename bintree<T>::node & nodoIz, nodoDec;
	nodo = n;

	if(!n.null())
	{

		int profundiadIz = profundidad , profundidadDec = profundidad ;


		nodoIz = n.left();
		profundidadIz++;
		profundidad(n.left(), nodoIz, profundidadMax,profundidadIz)

		nodoDec = n.right();
		profundidadDec++;
		profundidad(n.right(),nodoDec, profundidadMax, profundidadDec)

		if(profundidad > profundidadMax)
		{
			profundidadMax = profundidad ;
		}
		profundidad =  0;

		if(profundidadDec > profundidadIz)
			nodo = nodoDec;
		else
			nodo = nodoIz;

	}
	return profundidadMax;
}


int main()
{
		bintree<int>::node bin;
		bintree<int> Arbol(5);
		Arbol.insert_left(Arbol.root(),5);
		Arbol.insert_right(Arbol.root(),4);
		Arbol.insert_left(Arbol.root().left(),3);
		Arbol.insert_left(Arbol.root().left(),2);

		bin = mas_profunda(Arbol);

}