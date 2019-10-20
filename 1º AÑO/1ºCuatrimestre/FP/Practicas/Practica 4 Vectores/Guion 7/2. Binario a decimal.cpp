#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	
	const int MAX=1000;
	int binario[MAX], util_binario, suma=0;
	bool es_binario=true;
	
	cout << endl << "Programa que lee un nº binario y muestra su representación en decimal" << endl;
	
	cout << endl << "Introduzca el nº de 0 y 1 que tiene el nº binario: ";
	cin >> util_binario;
	
	cout << endl << "Introduzca los 0 y 1 del nº binario separados por espacios: ";
	
	for (int i=util_binario-1; i>=0; i--)
	{
		cin >> binario[i];
		
		if(binario[i]!=0 && binario[i]!=1)
		
		{
			es_binario=false;
		}
	}
	
	if (es_binario)
	{
		cout << endl << "El binario ";
		///// Mostramos el binario separando los dígitos de 4 en 4
		if(util_binario%4==0)
		{	
			int r=0;
			for (int i=util_binario-1; i>=0; i--)
			{
				if(r%4==0 && r!=0)
					cout << " ";
				
				cout << binario[i];
				r++;
			}
		}
		else
		{
			int o=util_binario%4;
			for (int i=0; i<4-o; i++)
				cout << "0";
		
			int r=4-o;
			for (int i=util_binario-1; i>=0; i--)
			{
				if(r%4==0)
					cout << " ";
				
				cout << binario[i];
				r++;
			}
		}
		/////////////////////////	
		cout << " en decimal es: ";
		for (int i=0; i<util_binario; i++)
		{
			suma=suma+(pow(2,i)*binario[i]);
		}
		cout << suma << endl;
	}
	else
		cout << endl << "\tNo ha introducido un nº binario" << endl;
}

