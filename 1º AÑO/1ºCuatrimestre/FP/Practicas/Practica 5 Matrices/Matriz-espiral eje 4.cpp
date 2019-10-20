#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "spanish");
	
	cout << endl << "Programa que muestra una matriz cuyos números hacen una espiral" << endl;
	
	const int MAX=50;
	int m[MAX][MAX];
	int util_m;
	
	do{
		cout << endl << "Introduzca el nº de filas de la matriz (impar >= 3): ";
		cin >> util_m;
	}while(util_m%2==0 || util_m<3);
	
	int cuadrado=pow(util_m, 2);
	int centro=util_m/2;
	int fila=centro;
	int columna=centro;
	m[fila][columna]=cuadrado;
	cuadrado--;
	
	for(int i=1; i<=util_m; i++)
	{
		if(i%2!=0)
		{
			for(int j=0; j<i; j++)
			{
				columna--;
				m[fila][columna]=cuadrado;
				cuadrado--;
			}
			for(int j=0; j<i; j++)
			{
				fila++;
				m[fila][columna]=cuadrado;
				cuadrado--;
			}
		}
		else
		{
			for(int j=0; j<i; j++)
			{
				columna++;
				m[fila][columna]=cuadrado;
				cuadrado--;
			}
			for(int j=0; j<i; j++)
			{
				fila--;
				m[fila][columna]=cuadrado;
				cuadrado--;
			}
		}
	}
	
	cout << endl << "La matriz es:\n"<<endl;
	for(int i=0; i<util_m; i++)
	{
		cout << "\t";
		for(int j=0; j<util_m; j++)
			cout<< m[i][j]<< " ";
		cout << endl;
	}
}
