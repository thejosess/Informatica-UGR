//Ejercicio 2
#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	double numero1, numero2, numero3, media, mediaari;
	
	cout << "Introducir numero 1: " ;
	cin >> numero1;
	
	cout << "Introducir numero 2: " ;
	cin >> numero2;
	
	cout << "Introducir numero 3: " ;
	cin >> numero3;
	
	media = (numero1+numero2+numero3)/3;
	
	mediaari = sqrt((((numero1-media)*(numero1-media)) + ((numero2 - media)*(numero2-media)) + ((numero3-media)*(numero3-media)))/3);
	
	cout << "La media de los tres numeros es: " <<media<<endl;
	
	cout << "La media aritmetica es: " <<mediaari<<endl;
}
