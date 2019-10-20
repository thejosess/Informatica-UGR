/*
	Implementa una función bintree<int>::node ancestro_comun 
	(bintree<int>::node n1) que devuelva el nodo que sea el primer ancestro 
	común a los nodos n1 y n2. La eficiencia debe ser proporcional a la altura 
	del árbol.
*/

#include <iostream>
#include "bintree.h"

using namespace std;

template <typename T>
void recorridos(const bintree<T> & arb)
{
	cout << endl << "Tamaño del arbol: " << arb.size() << endl;
	cout << "El recorrido en preorden: ";

	auto it = arb.begin_preorder();
	for (it; it!=arb.end_preorder(); ++it)
		cout << *it << " ";
	
	cout << endl;

}

int profundidad( const typename bintree<int>::node & n , int &p, int & pfNodo ){

	if( !n.null() )
  {
    	int prol=pfNodo;
    	prol++;
		profundidad(n.left() , p, prol);
	 	int pror=pfNodo;
    	pror++;
     	profundidad(n.right(), p, pror );

  		if (pfNodo > p ){
  			p=pfNodo;
  		}

  		pfNodo=0;
	}
	return p;

}

bintree<int>::node ancestro_comun(  typename bintree<int>::node & n1,  typename bintree<int>::node & n2){
  typename bintree<int>::node ancestro = n1;

  //Prof nodo 1
  int p1 = 0, prof1 = 0;
  profundidad(n1, p1, prof1);

  //Prof nodo 2
  int p2 = 0, prof2 = 0;
  profundidad(n2, p2, prof2);

  if (p1 != p2){
    while( p2 > p1){
      n2= n2.parent();
      p2--;
    }
  }

  bool encontrado =false ; 

  while ( !n1.parent().null() && !n2.parent().null() && !encontrado ){
    n1 = n1.parent();
    n2 = n2.parent();
    if ( n1 == n2){
      encontrado=true;
      ancestro = n1;
    }
  }

    return ancestro;
}

int main(){
	//Árbol: 
  	//        1
  	//      /  \
  	//     9    9
  	//    / \  / \ 
  	//   9   8 5 4
  	//        \  
  	//         7 

    bintree<int> Arb(1);
  
	Arb.insert_left(Arb.root(), 9);
	Arb.insert_right(Arb.root(), 9);
	Arb.insert_left(Arb.root().left(), 9);
	Arb.insert_right(Arb.root().left(), 8);
	Arb.insert_right(Arb.root().left().right(), 7);
	Arb.insert_left(Arb.root().right(), 5);
	Arb.insert_right(Arb.root().right(), 4);

	recorridos(Arb);

  	
  	typename bintree<int>::node n1=Arb.root();
	n1 = n1.left();

	typename bintree<int>::node n2=Arb.root();
	n2 = n2.right();

	cout << "\nNodo 1 : " << *n1 << "\t\tNodo 2: " << *n2 << endl; 

	typename bintree<int>::node ancestro ;
	ancestro = ancestro_comun(n1, n2);

	cout << "El primer ancestro comun es : " << *ancestro << endl << endl;
  	
	
}
