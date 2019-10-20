//Programa Ejercicio 17
#include <iostream>
using namespace std;

int main()
{
	//Entrada
	
	int numero , dig1 , dig2 , dig3 ;
	
	//Proceso
	
	cout << "Introducir numero entero : ";
	cin >> numero;
	
	//Salida
	
	dig1 = numero / 100 ;
	
	dig2 = ( numero / 10 ) % 10  ;

	dig3 = numero % 10 ;	
	
	cout << dig1 << "   " << dig2 << "   " << dig3 << endl;
}

