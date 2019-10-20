//Programa Ejercicio 2

#include <iostream>

using namespace std;

int main()

{
	//Entrada
	
	int numero ;
	
	
	//Proceso
	
	cout << "Introducir numero entero : " ;
	
	cin >> numero ;
	
	
	if ( numero % 5 == 0 )
	
		cout << " El numero es multiplo de 5 " << endl ;
		
	else 
		
		cout << " El numero no es multiplo de 5 " << endl ;
		
 	if ( numero > 1000 )
 	
 		cout << " El numero es mayor que 1000 " << endl ;
 	
 	else 
 		
 		cout << "El numero no es mayor que 1000 " << endl ;
		
	
}

