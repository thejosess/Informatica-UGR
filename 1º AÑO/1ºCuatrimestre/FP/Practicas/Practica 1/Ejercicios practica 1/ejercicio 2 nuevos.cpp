//Ejercicios Introduccion C++ , EJERCICIO 2

#include <iostream>
using namespace std;

int main()

{
	double num1 , num2 ;
	
	cout << "Introducir numero 1: ";
	cin >> num1 ;
	
	cout << "Introducir numero 2 : ";
	cin >> num2 ;
	
	if ( num1 < num2 )
	
		cout << "El segundo numero es el mayor : " << num2 << endl ;
		
	else 
		
		cout << "El primer numero es el mayor: "  << num1 << endl ;
		
}
