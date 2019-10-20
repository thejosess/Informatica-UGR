//Programa Ejercicio 3

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
	
	
	if ( numero_1 > numero_2 && numero_1 > numero_3 && numero_2 > numero_3 )
	
		cout << numero_1 << " " << numero_2 << " " << numero_3 << endl ;
		
		
	if ( numero_3 > numero_2 && numero_3 > numero_1 && numero_2 > numero_1 )
	
		cout << numero_3 << " " << numero_2 << " " << numero_1 << endl ;
		
	if ( numero_2 > numero_1 && numero_2 > numero_3 && numero_3 > numero_1 )
	
		cout << numero_2 << " " << numero_3 << " " << numero_1 << endl ;
	
	
	if ( numero_3 > numero_2 && numero_3 > numero_1 && numero_1 > numero_2 )
	
		cout << numero_3 << " " << numero_1 << " " << numero_2 << endl ;
		
	if ( numero_2 > numero_1 && numero_2 > numero_3 && numero_1 > numero_3 )
	
		cout << numero_2 << " " << numero_1 << " " << numero_3 << endl ;
		
	if ( numero_1 > numero_2 && numero_1 > numero_3 && numero_3 > numero_2 )
	
	cout << numero_1 << " " << numero_3 << " " << numero_2 << endl ;

}

