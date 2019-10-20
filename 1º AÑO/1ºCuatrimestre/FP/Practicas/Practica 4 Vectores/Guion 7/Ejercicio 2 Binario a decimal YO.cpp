#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	
	const int MAX=1000;
	int binario[MAX], util_binario, suma=0;
	
	cout << endl << "Programa que lee un n� binario y muestra su representaci�n en decimal" << endl;
	
	cout << endl << "Introduzca el n� de 0 y 1 que tiene el n� binario: ";
	cin >> util_binario;
	
	cout << endl << "Introduzca los 0 y 1 del n� binario separados por espacios: ";
	
	for (int i=util_binario-1; i>=0; i--)
	{
		cin >> binario[i];
		
	}
	
	for (int i=0; i<util_binario; i++)
	
		{
			suma=suma+(pow(2,i)*binario[i]);
		}
		
		cout << suma << endl;
}

