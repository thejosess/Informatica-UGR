// Disponemos de una matriz con filas de distintos tamaños con enteros consecutivos. 
// Realizar un programa que encuentre el vector con mayor longitud que se puede formar al concatenar dos filas de la matriz. 
//NOTA: Usar un vector para almacenar los tamaños de las filas de la matriz.

#include <iostream>

using namespace std;

int main()
{
	//ENTRADA
	
	const int MAX_FIL=30, MAX_COL=30 , MAX[1000] ;
	int matriz[MAX_FIL][MAX_COL];
	int util_fila, util_columna[MAX_FIL] , mayor = 0 , ultimo = 0 , seguidos[MAX];
	bool encontrado = false ;
	
	do{
		cout<<"Introducir el numero de filas: ";
		cin>>util_fila;
	}while(util_fila<1 && util_fila>30);
	
	for(int i=0; i<util_fila; i++)
	{
		do{
			cout<<"Introducir el numero de elementos de la fila "<<i+1<<" : ";
			cin>>util_columna[i];
		}while(util_columna[i]<1 && util_columna[i]>30);
	}
	
	for(int i=0; i<util_fila; i++)
	{
		for(int j=0; j<util_columna[i]; j++)
		{
			cout<<"Introducir el elemento de la matriz "<<i+1<<" x "<<j+1<<endl;
			cin>>matriz[i][j];
		}
	}
	
	int columnas , totalcolumnas = 1 , mayor = 0 ;
	
	for(int i=0; i<util_fila; i++)
	{
		for(int j=0; j<util_columna[i]; j++)
		{
			
			mayor = totalcolumnas ;
			ultimo = matriz[i][util_columna[i]] ;
			columnas = ultil_columna[i]
						
			for ( int k = 0 ; k < util_fila ; k ++)
			{
				if ( ultimo + 1 = matriz[k][0])
				{
					totalcolumnas = columnas + util_columna[k] ;
				}
				 
				 
			}
			
		}
	}
