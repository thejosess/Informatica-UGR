//Ejercicio 7

#include <iostream>

using namespace std;

#include <cmath>

int main ()

{
	
	// Entrada
	
	double real_1 , real_2 , real_3 , real_4 , modulo_1 , modulo_2 ;
	
	//Complejo 1
	
	cout << "Introducir termino a del primer complejo: " ;
	
	cin >> real_1 ;
	
	cout << "Introducir termino b del primer complejo: " ;
	
	cin >> real_2 ;
	
	//Complejo 2
	
	cout << "Introducir termino a del segundo complejo : " ;
	
	cin >> real_3 ;
	
	cout << "Introducir termino b del segundo complejo : " ;
	
	cin >> real_4 ;
	
	
	//Operaciones
	
	modulo_1 = sqrt ( ( real_1 * real_1 ) +  ( real_2 * real_2 ) ) ;
	
	modulo_2 = sqrt ( ( real_3 * real_3 ) +  ( real_4 * real_4 ) ) ;
	
	if ( modulo_1 > modulo_2 ) 
	
		cout << "El primer complejo tiene un modulo mayor " << endl ;
	
	else
	
		cout << "El segundo complejo tiene un modulo mayor " << endl ;
   
}
