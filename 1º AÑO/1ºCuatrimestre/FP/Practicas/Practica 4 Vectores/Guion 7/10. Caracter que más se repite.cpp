#include <iostream>

using namespace std;

int main ()
{
	cout << endl << "Programa que lee un vector de caracteres y dice cu�l es el que m�s se repite" << endl;
	
	const int MAX=1000;
	char v[MAX] , masveces;
	int util_v , r , mayor , j;
	
	do
	{
	cout << endl << "Introduzca cu�ntos elementos va a tener el vector: ";
	cin >> util_v;
	}while (util_v<1 || util_v>MAX);
	
	cout << endl;
	
	for (int i=0; i<util_v; i++)
	{
		cout << "Introduzca el elemento " << i+1 << " del vector: ";
		cin >> v[i];
	}
	

	for (int i=0; i<util_v; i++)
	{
		r=0;
		for (int j=0; j<util_v; j++){
		
			if (v[i]==v[j])
				r++;
		}
		if (i==0)
			mayor=r;
		else
			if (r>mayor)
			{
				mayor=r;
				masveces=v[i];
			}
	}
	
	cout << endl << "El caracter que m�s veces se repite es \"" << masveces << "\" que se repite " << mayor << " veces" << endl;
}
