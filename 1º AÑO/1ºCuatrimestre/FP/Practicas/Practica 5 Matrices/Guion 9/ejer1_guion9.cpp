//Escriba un programa para ordenar las filas de una matriz de enteros positivos. 
//Para hacer dicha ordenación, debemos calcular la media de los valores de cada fila.
//A continuación ordenaremos las filas de la matriz de acuerdo a los valores de sus medias (de menor a mayor).
//Por ejemplo, dada la siguiente matriz:

#include <iostream>

using namespace std;

int main()
{
	//ENTRADA
	
	const int MAX_FIL=30, MAX_COL=30, MAX=1000;
	int matriz [MAX_FIL][MAX_COL];
	int util_fila, util_columna;
	int media[MAX];
	
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
			cout<<"introducir el elemento "<<i+1<<" x "<<j+1;
			cin>>matriz [i][j];
		}
	}
	
	//PROCESO
	
	int util_media=1;
	
	for(int i=0; i<util_fila; i++)
	{
		media[i]=0;
		
		for(int j=0; j<util_columna; j++)
		{
			media[i]=media[i]+matriz[i][j];
		}
		
		util_media++;
		media[i] = media[i] / util_columna ;
	}
	
	int intercambia;
	
	for(int i=0; i<util_fila; i++)
	{
		for(int j=0; j<util_columna; j++)
		{		
			if(media[i]>media[i+1])
			{
				intercambia=matriz[i+1][j];
				matriz[i+1][j]=matriz[i][j];
				matriz[i][j]=intercambia;
			}
		}
	}
	
	//SALIDA
		
	cout<<"La matriz ordenada es: "<<endl;
	
		for(int i=0;i<util_fila;i++){
			cout<<"| ";
			for(int j=0;j<util_columna;j++){
				cout << matriz[i][j]<<" ";
			}
			cout<<"|"<<endl;
		}
}
