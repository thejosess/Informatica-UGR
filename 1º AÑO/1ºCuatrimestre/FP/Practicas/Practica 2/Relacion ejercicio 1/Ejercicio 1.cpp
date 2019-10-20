//Programa Ejercicio 1

#include <iostream>

using namespace std;

int main()
{
	//Entrada
	
	int numero ;
	
	
	//Proceso
	
	cout << "Introducir numero entero : " ;
	
	cin >> numero ;
	
	
	if ( numero == 0 )
	
		cout << " El numero es 0 " << endl;
		
	else 
	if ( numero < 0 )
		
		cout << "El numero es negativo " << endl ;
				
	else
			
		cout << "El numero es positivo " << endl ;
		
	
}

