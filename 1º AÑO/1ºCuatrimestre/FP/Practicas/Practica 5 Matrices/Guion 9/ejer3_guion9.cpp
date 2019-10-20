// Disponemos de una matriz con filas de distintos tamaños con enteros consecutivos. 
// Realizar un programa que encuentre el vector con mayor longitud que se puede formar al concatenar dos filas de la matriz. 
//NOTA: Usar un vector para almacenar los tamaños de las filas de la matriz.

#include <iostream>

using namespace std;

int main()
{
	//ENTRADA
	
	const int MAX_FIL=30, MAX_COL=30;
	int matriz[MAX_FIL][MAX_COL];
	int util_fila, util_columna[MAX_FIL];
	
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
	
	//PROCESO

	int buscar, max=-1, vectorprimeroprincipio=-1, vectorsegundofinal=-1;
	
	for(int i=0; i<util_fila; i++)
	{
		buscar=matriz[i][util_columna[i]-1];
		
		for(int j=0; j<util_fila; j++)
		{
			if((buscar+1)==matriz[j][0] && (matriz[j][util_columna[j]-1]-matriz[i][0]+1)>max )
			{
				max=(matriz[j][util_columna[j]-1]-matriz[i][0]+1);
				vectorprimeroprincipio=matriz[i][0];
				vectorsegundofinal=matriz[j][util_columna[j]-1];
			}
		}
	
	}
	
	//SALIDA
	
	cout<<"El vector mas largo poosible al concatenar dos filas es: "<<endl;
	
	for(int i=vectorprimeroprincipio; i<vectorsegundofinal+1; i++)
	{
		cout<<"  "<<i;
	}
	
	
	}
	
	
				
				
		
	
	
	
	
