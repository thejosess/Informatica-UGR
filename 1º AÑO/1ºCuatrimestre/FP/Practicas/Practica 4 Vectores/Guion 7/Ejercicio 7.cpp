//Guion 7 ejercicio 7

#include<iostream>
using namespace std;

int main ()
{
	const int MAX=1000;
	int v[MAX], util_v, w[MAX], util_w, pos;
	
	do
	{
		cout << "Introduzca el tamanio del vector original (entre 1 y " << MAX << "): ";
		cin >> util_v;
		
	} while (util_v <= 1 || util_v > MAX); 	
	
	do
	{
		cout << "Introduzca el tamanio del vector a introducir (entre 1 y " << MAX << "): ";
		cin >> util_w;
		
	} while (util_w <= 1 || util_w > MAX); 	
		
	for (int i=0; i<util_v; i++)
	{
		cout << "Introduzca valores del vector original" << endl;
		cin >> v[i];
	}
	for (int i=0; i<util_w; i++)
	{
		cout << "Introduzca valores del vector a introducir" << endl;
		cin >> w[i];
	}	
	do
	{
		cout << "Introduzca la posicion en la que introducir el nuevo vector (entre 0 y el tamanio-1)" << endl;
		cin >> pos;
		
	} while (pos < 0 || pos > util_v-1); 
	
	util_v = (util_v - pos) + util_w;
	
	for (int i=0; i<util_v; i++)
	{
		v[pos+i] = w[i];
	}
	for (int i=0; i<util_v; i++ )
	{
		cout << "La posicion " << i << " vale " << v[i] << endl;
	}
}
