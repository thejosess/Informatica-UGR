// Realizar un programa que acepte una matriz de enteros y devuelva el número de columnas únicas de la matriz,
// es decir, aquellas para las que NO existe otra columna en la matriz con los mismos valores. 

#include <iostream>

using namespace std;

int main()
{
	//ENTRADA
	
	const int MAX_FIL=30, MAX_COL=30;
	int matriz [MAX_FIL][MAX_COL];
	int util_fila, util_columna;
	
	do{
		cout<<"Introducir el numero de filas de la matriz: ";
		cin>> util_fila;
	}while(util_fila>MAX_FIL || util_fila<0);
	
	do{
		cout<<"Introducir el numero de columnas de la matriz: ";
		cin>> util_columna;
	}while(util_columna>MAX_COL || util_columna<0);
	
	for (int i =0; i< util_fila; i++)
	{
		for(int j=0; j<util_columna; j++)
		{
			cout<<"introducir el elemento "<<i+1<<" x "<<j+1<<" : ";
			cin>>matriz [i][j];
		}
	}
	
	//PROCESO
	
	
	int j=0, columna;
	
	for(int i=0; i<util_fila; i++)
	{
		while (j<util_columna)
		{
			columna=j+1;
			
			while(columna<util_columna)
			{
				if(matriz[i][j]==matriz[i][columna])
				{
					//Borrar
					for (int k=columna; k<util_columna-1; k++)
						matriz[i][k]=matriz[i][k+1];
					util_columna--;
				}
				else
					columna++;
			}
			i++;
		}
	}
	
	//SALIDA
	
	cout<<"la matriz ahora es: ";
	
	
	for(int i=0; i<util_fila; i++)
	{
		for(int j=0; j<util_columna; j++)
			cout<< matriz[i][j]<< " ";
	}
}
	
