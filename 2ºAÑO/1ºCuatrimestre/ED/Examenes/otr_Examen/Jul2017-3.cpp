/*
	bool es_subarbol(const bintree<int> & ab1, const bintree<int> &ab2);
*/

#include <iostream>
#include "bintree.h"

using namespace std;

bool iguales (typename bintree<int>::node n1, typename bintree<int>::node n2){
	if ( !n1.null() && n2.null() )
      return false;
  	else  if ( n1.null() && !n2.null() ) 
      return false;


  if(!n1.null() && !n2.null() && *n1 == *n2){
    iguales(n1.left() , n2.left());
    iguales(n1.right() , n2.right());
  }
	return true;
}
bool es_subarbol( const bintree<int> & ab1,  const bintree<int> & ab2 ){
	typename bintree<int>::node nodo1=ab1.root();
	typename bintree<int>::node nodo2=ab2.root();

	return iguales(nodo1,nodo2);
}

int main(){
	//Árbol: 
  	//       1
  	//      / \
  	//     9   9
  	//    / \   \ 
  	//   9   8   5
  	//        \   
  	//         7   

    bintree<int> Arb(1);
  
	Arb.insert_left(Arb.root(), 9);
	Arb.insert_right(Arb.root(), 9);
	Arb.insert_left(Arb.root().left(), 9);
	Arb.insert_right(Arb.root().left(), 8);
	Arb.insert_right(Arb.root().left().right(), 7);
	Arb.insert_left(Arb.root().right(), 5);

	if(es_subarbol(Arb, Arb))
		cout << "Son subarboles" << endl;
	else cout << "No son subarboles" << endl;
}
