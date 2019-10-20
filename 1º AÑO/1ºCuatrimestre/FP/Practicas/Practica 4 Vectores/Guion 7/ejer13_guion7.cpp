//Realizar un programa que lea dos vectores de enteros, A y B, 
//y determine si B se encuentra dentro de A. De estar, se devolverá la posición de comienzo de B dentro de A.

#include <iostream>

using namespace std;

int main()
{
	
	//ENTRADA
	
	int MAX=1000;
	int vectorA[MAX], vectorB[MAX];
	int util_va, util_vb;
	
	cout<<"  INTRODUCE EL NUMERO DE CIFRAS QUE VA A CONTENER EL VECTOR A: ";
	cin>>util_va;
	
	cout<<"  INTRODUCE EL NUMERO DE CIFRAS QUE VA A CONTENER EL VECTOR B: ";
	cin>>util_vb;
	
	for(int i=0; i<util_va; i++)
	{
		cout<<"INTRODUZCA UN VALOR DEL VECTOR A: ";
		cin>>vectorA[i];
	}
	
	for(int i=0; i<util_vb; i++)
	{
		cout<<"INTRODUCIR UN VALOR DEL VECTOR B: ";
		cin>>vectorB[i];
	}
	
	//PROCESO
	
	bool encontrado=false, va_coincidiendo;
	double posicion_encontrado=-1;
		
	for(int inicio=0; inicio + util_vb<=util_va && !encontrado ; inicio++)
	{
		va_coincidiendo=true;
		
		for(int i =0; i<util_va && va_coincidiendo ; i++)
		{
			va_coincidiendo=vectorA[inicio+i]==vectorB[i];
			
			if(va_coincidiendo)
			{
				encontrado=true;
				posicion_encontrado=inicio;
			}
		}
	}
	
	//SALIDA
	
	if(posicion_encontrado==-1)
		cout<<"LO SENTIMOS, PERO NO SE HAN ENCONTRADO COINCIDENCIAS"<<endl;
	else
		cout<<"LA POSICION EN LA QUE EL VECTOR B SE ENCUENTRA CONTENIDO EN EL VECTOR A ES "<<posicion_encontrado<<endl;

}
	

