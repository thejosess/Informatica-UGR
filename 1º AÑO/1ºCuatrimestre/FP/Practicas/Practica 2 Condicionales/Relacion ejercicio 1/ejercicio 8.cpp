
//Ejercicio 8

#include <iostream>

using namespace std;

int main()
{
	
	//Entrada
			
	char car ;
	
	cout << "Introducir caracter: " ;
	
	cin >>car;
	
	//Proceso
	
	if ( car == 'a' || car == 'e' || car == 'i' ||  car == 'o' || car == 'u' )
	
		cout << "La vocal es minuscula " << endl;
		
	else
	
		if ( car == 'A' || car == 'E' || car == 'I' ||  car == 'O' || car == 'U' )
	
			cout << "La vocal es mayuscula " << endl;
					
		else
		
			cout << "No es ninguna vocal " << endl;	
		
		
}
