#include <iostream>

using namespace std;

main()
{
	setlocale(LC_ALL, "spanish");
	
	int a, i=0, MAX=1000, v[MAX];
	
	cout << endl << "Programa que separa los dígitos del nº introducido" << endl;
	
	do
	{
	cout << endl << "Introduzca un entero positivo: ";
	cin >> a;
	}while (a<0);
	
	while (a/10 >= 1)
	{
		v[i]=a%10;
		a=a/10;
		i++;
	}
	
	cout << endl << "\n\t" << a << "  ";
	
	for (int j=i-1; j>=0; j--)
		cout << v[j] << "  ";
	
	cout << endl;
}
