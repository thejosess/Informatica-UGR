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
		cout << bin << endl;

}