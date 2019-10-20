//Programa Ejercicio 4

#include <iostream>

using namespace std;

int main()

{
	//Entrada
	
	int numero_1 , numero_2 , numero_3 ;
	
	cout << "Introducir numero entero : " ;
	
	cin >> numero_1 ;
	
	cout << "Introducir numero entero : " ;
	
	cin >> numero_2 ;
	
	cout << "Introducir numero entero : " ;
	
	cin >> numero_3 ;
	
	//Proceso
	
	
	if ( numero_1 > numero_2 && numero_1 > numero_3 )
	
		cout << " El numero mayor es : " << numero_1 << endl;
		
		
	if ( numero_3 > numero_2 && numero_3 > numero_1 )
	
		cout << " El numero mayor es : " << numero_3 << endl;
	
	if ( numero_2 > numero_3 && numero_2 > numero_1 )
	
		cout << " El numero mayor es : " << numero_2 << endl;
		

}

