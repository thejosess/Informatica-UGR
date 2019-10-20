ejercicios_arboles
#include <iostream>
#include "bintree.h"

using namespace std;
int main()
{
	bintree<int> A(7);
	bintree<int> B(1);

	A.insert_left(A.root(),B) ;
	B = bintree<int>(9);
	A.insert_right(A.root(),B) ;
	B = bintree<int>(6);
	A.insert_left(A.root(),left(),B);

	bintree<int>:node n;
	n = A.root(),left();

	//pag 43



}