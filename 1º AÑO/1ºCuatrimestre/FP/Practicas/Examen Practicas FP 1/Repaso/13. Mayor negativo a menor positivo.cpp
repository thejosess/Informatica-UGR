#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "spanish");
	
	const int MAX=1000;
	int v[MAX], util_v=25;
	
	cout << endl << "Programa que lee 25 enteros positivos y negativos y muestra los números que hay entre el mayor de los negativos y el menor de los positivos\n" << endl;
	
	for (int i=0; i<util_v; i++)
	{
		cout << "Introduzca el nº " << i+1 << "º: ";
		cin >> v[i];
	}
	
	int pos_min, tmp;
	for(int izda=0; izda<util_v-1; izda++)
	{
		pos_min=izda;
		for(int i=izda+1; i<util_v; i++)
			if(v[i]<v[pos_min])
				pos_min=i;
			
		tmp=v[izda];
		v[izda]=v[pos_min];
		v[pos_min]=tmp;
	}
	
	int c=0;
	for (int i=0; v[i]<0; i++)
		c++;
	
	int negativos[MAX], util_negativos=0;
	for (int i=0; i<c; i++)
	{
		negativos[i]=v[i];
		util_negativos++;
	}
	
	int positivos[MAX], util_positivos=0;
	for (int i=util_v-1; i>=c; i--)
	{
		positivos[util_positivos]=v[i];
		util_positivos++;
	}
	
	bool bien=true;
	if (util_negativos==0 || util_positivos==0)
		bien=false;
	
	if(bien)
	{
		cout << endl << "Estos son los números:\n" << endl;
	
		for (int i=negativos[util_negativos-1]; i<positivos[util_positivos-1]; i++)
			cout << i << ", ";
		
		cout << positivos[util_positivos-1] << endl;
	}
	else
		cout << endl << "No ha introducido positivos o no ha introducido negativos" << endl;
}
