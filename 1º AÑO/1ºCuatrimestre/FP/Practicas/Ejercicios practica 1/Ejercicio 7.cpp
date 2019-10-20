//Ejercicio 7

#include <iostream>

using namespace std;

int main ()
{
	int parte_entera;
	double parte_decimal, numero;
	
	cout << "Introduce un numero cualquiera: " ;
	cin >> numero;
	
	parte_entera = numero/1;
	parte_decimal = numero-parte_entera;
	
   cout << "La parte entera es : " << parte_entera << endl;	
		
   cout << "La parte decimal es : " << parte_decimal << endl;		

}
