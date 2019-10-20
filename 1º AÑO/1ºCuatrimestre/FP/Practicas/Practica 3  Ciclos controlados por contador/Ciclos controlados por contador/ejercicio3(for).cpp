//Ejercicio 3

#include <iostream>
using namespace std;

int main ()
{
	
	int n , i , producto  ;
	
	cout << "Introducir un entero: " ;
	cin >> n ;
		
	for ( i = 1 ; i<= 1000 ; i++ )
	{	
			
			producto = n * i  ; 	
			
			cout << "El factorial de n es :" << producto << endl ;
		
  }
  
}
