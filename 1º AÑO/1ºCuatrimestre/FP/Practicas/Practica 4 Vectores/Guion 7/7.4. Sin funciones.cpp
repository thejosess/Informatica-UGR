#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "spanish");
	
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
	bool es_primo;
	while (i<util_v)
	{
		//Comprueba si es primo
		es_primo=true;
		if (v[i]%2!=0 || v[i]==2)
		{
			for (int j=2; j<v[i] && es_primo; j++)
				if (v[i]%j == 0 && v[i]!=2)
					es_primo = false;
		}
		else
			es_primo=false;
		////////////////////////
		
		if(!es_primo)
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
