//Ejercicio 1 con for

#include <iostream>
using namespace std;

int main ()
{
	
	int n , i , resultado  ;
	
	resultado = 1 ;
	
	cout << "Introducir un entero: " ;
	cin >> n ;
	
	for ( i = n ; i > 0 ; i -- ) 
	{
		resultado = resultado * i ;
	}
		cout << "El factorial es : " << resultado << endl;
		
}
