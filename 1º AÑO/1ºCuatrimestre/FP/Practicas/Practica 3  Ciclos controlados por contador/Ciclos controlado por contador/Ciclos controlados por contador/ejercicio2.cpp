//Ejercicio 2 con for

#include <iostream>
using namespace std;

int main ()
{
	
	int num1 , num2 , i , division ;
	
	cout << "Introducir numero  inicial : " ;
	cin >> num1 ;
	
	cout << "Introducir numero  final: " ;
	cin >> num2 ;
	
	
	for ( i = num2 - 1 ; i > num1  ; i = i - 1 ) 
	{
		division = i % 2 ;
		
		if ( division  == 0 )
			
	   	cout << "Los  numeros pares son : " << i << endl;
	}
	
	
}
