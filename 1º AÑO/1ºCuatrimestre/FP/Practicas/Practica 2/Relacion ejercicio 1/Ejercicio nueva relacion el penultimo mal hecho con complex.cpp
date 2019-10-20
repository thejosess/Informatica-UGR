//Ejercicio 7

#include <iostream>

using namespace std;

#include <cmath>

#include<complex>

int main ()

{
	
	// Entrada
	
	complex<double> real_1 , real_2 ;
	
	//Complejos
	
	cout << "Introducir termino primer complejo: " ;
	
	cin >> real_1 ;
	
	
	
	cout << "Introducir termino segundo complejo: " ;
	
	cin >> real_2 ;

	
	//Operaciones
	
	
	if ( norm(real_1) > norm(real_2) )
		
		cout << "El primer complejo tiene un modulo mayor" << endl;
		
	else 
		
		cout << "El segundo complejo es mayor " << endl;
		
}
