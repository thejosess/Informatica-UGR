// Realizar un programa que lea desde el teclado un numero entero n mayor que cero y muestre las n primeras filas del siguiente triangulo

#include <iostream>

using namespace std;

int main()
{
	int n, x;
	
	cout << endl << "Introduzca un nº: ";
	cin >> n;
	cout << "\n\t";
	
	for (int i=1; i<=n; i++)
		{
			for (int j=i; j<=n-1; j++)
			{
				cout << " ";
			}
			for (int k=i-1; k>=0; k--)
			{
				if(k>9)
			{
				x=k%10;
				cout << x;
			}
			else	
				cout << k;
			}
		for (int k=1; k<=i-1; k++)
		{
			if(k>9)
			{
				x=k%10;
				cout << x;
			}
			else
				cout << k;
		}
cout << "\n\t";
	}
}


