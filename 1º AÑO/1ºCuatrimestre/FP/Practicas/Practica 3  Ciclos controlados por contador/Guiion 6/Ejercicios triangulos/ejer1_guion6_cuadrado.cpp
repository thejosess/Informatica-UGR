// programa que construye un cuadrado formado por asteriscos

#include <iostream>

using namespace std;

int main()
{
	cout<<"Ejercicio 1 del guion 6: cuadrado "<<endl;
	
	int i, j, k, n;
	
	cout<<"introducir un n que correspondera con el numero de filas y de columnas del cuadrado: "<<endl;
	cin>>n;
	
	for(i=1; i<=n; i++)
	{
		cout<<"*";
	}
	
	cout<<endl;
	
	for(k=1; k<=n-1; k++)
	{
		cout<<"*";
		
		for(j=2; j<=n-1; j++)
		{
			cout<<" ";
		}
		
		cout<<"*"<<endl;
	}
	
	for(i=1; i<=n; i++)
	{
		cout<<"*";
	}
	
	cout<<endl;
}
		
		
		
		
		
