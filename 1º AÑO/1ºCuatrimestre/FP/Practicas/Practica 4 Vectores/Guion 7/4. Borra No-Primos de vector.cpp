#include <iostream>

using namespace std;

bool EsPrimo (int n)
{
	bool es_primo=true;
	
	if (n%2!=0 || n==2)
	{
		for (int i=2; i<n && es_primo; i++)
			if (n%i == 0 && n!=2)
				es_primo = false;
	}
	else
		es_primo=false;
	
	return es_primo;
}

int main()
{
	
	const int MAX=1000; 
	int v[MAX], util_v;
	
	cout << endl << "Programa que borra los elementos que no sean primos en un vector\n" << endl;
	
	do{
		cout << "Introduzca el nº de elementos que va a tener el vector (entre 1 y " << MAX << "): ";
		cin >> util_v;
	}while (util_v < 1 || util_v > MAX);
	
	cout << endl;
	
	for (int i=0; i<util_v; i++)
	{
		cout << "Introduzca el elemento " << i+1 << " del vector: ";
		cin >> v[i];
	}
	
	cout << endl << "El vector original es: (";
	for (int i=0; i<util_v-1; i++)
	{
		cout << v[i] << ", ";
	}
	cout << v[util_v-1] << ")" << endl;
	
	/////////////	Borrar no-primos	///////////////
	int i=0;
	while (i<util_v)
	{
		if(!EsPrimo(v[i]))
		{
			//Borrar
			for (int j=i; j<util_v-1; j++)
				v[j]=v[j+1];
			util_v--;
		}
		else
			i++;
	}
	////////////////////////////////////////////////
	
	if (util_v!=0)
	{
		cout << endl << "El vector sólo con primos es: (";
		
		for (int j=0; j<util_v-1; j++)
		{
			cout << v[j] << ", ";
		}	
		cout << v[util_v-1] << ")" << endl;
	}
	else
		cout << endl << "No ha introducido ningún nº primo en el vector" << endl;
}
