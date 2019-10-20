//Ejercicio 5

#include <iostream>

using namespace std;

int main()

{
	//Entrada
	
	int numero_1 , numero_2 , numero_3 ;
	
	cout << "Introducir numero entero distinto a 0 : " ;
	
	cin >> numero_1 ;
	
	cout << "Introducir numero entero distinto a 0 : " ;
	
	cin >> numero_2 ;
	
	cout << "Introducir numero entero distinto a 0 : " ;
	
	cin >> numero_3 ;
	
	//Proceso
	
	
	if ( numero_1 > 0 && numero_2 > 0 && numero_3 > 0 )
	
		cout << "El signo predominante es positivo" << endl;
		
		
	if ( numero_3 > 0 && numero_2 > 0 && numero_1 < 0 )
	
		cout << "El signo predominante es positivo" << endl ;
		
	if ( numero_2 > 0 && numero_1 > 0 && numero_3 < 0 )
	
		cout << "El signo predominante es positivo" << endl ;
	
	
	if ( numero_1 > 0 && numero_3 > 0 && numero_2 < 0 )
	
		cout << "El signo predominante es positivo" << endl ;
		
		
		
		
	if ( numero_1 < 0 && numero_2 < 0 && numero_3 < 0 )
	
		cout << "El signo predominante es negativo" << endl;
		
		
	if ( numero_3 < 0 && numero_2 < 0 && numero_1 > 0 )
	
		cout << "El signo predominante es negativo" << endl ;
		
	if ( numero_2 < 0 && numero_1 < 0 && numero_3 > 0 )
	
		cout << "El signo predominante es negativo" << endl ;
	
	
	if ( numero_1 < 0 && numero_3 < 0 && numero_2 > 0 )
	
		cout << "El signo predominante es negativo" << endl ;

}
