// Generar la siguiente matriz n x n (sólo para valores impares de n y mayores a 3). Por ejemplo, para n = 5

#include <iostream>

using namespace std;

int main()
{
	//ENTRADA
	
	int MAX=30;
	int matriz[MAX][MAX];
	int util_matriz;
	
	do{
		cout<<"Introducir el numero n de la matriz n x n , recuerda que debe ser impar y mayor a 3: ";
		cin>>util_matriz;
	}while(util_matriz%2==0 || util_matriz<3);
	
	//ESTE FOR PONE LA PRIMERA FILA Y LA ULTIMA
	
	for(int i=0; i<util_matriz; i++)
	{
		for(int j=0; j<util_matriz; j++)
		{
			matriz[i][j]=j+1;
			matriz[util_matriz-1][util_matriz-j-1]=(2*util_matriz)-1-j;

		}
	}
	
	for(int i=0; i<util_matriz; i++)
	{
		for(int j=0; j<util_matriz; j++)
		{
			matriz[j+1][util_matriz-1]=util_matriz+1+j;
			matriz[util_matriz-1-j][i]=(2*util_matriz)+j;
		}
			
		util_matriz=util_matriz-2;
	}
	
	
			

	
	cout<<"La matriz es : "<<endl;
	
	for(int i =0; i<util_matriz; i++)
	{
		for (int j=0; j<util_matriz; j++)
		{
			cout<<matriz[i][j]<<" ";
		}
		
		cout<<endl;
	}
}
