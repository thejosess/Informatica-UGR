/* Muchos números naturales se pueden generar como suma de números consecutivos. Por
ejemplo, 6 = 1 + 2 + 3, 15 = 7 + 8 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5. Escribir un programa que
compruebe si un número entero leído desde el teclado cumple esta propiedad. */



#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n,suma=0,i=1;
	bool consec=true;
	
	cout<<"Introducir numero: ";
	cin>>n;
	
	while(consec&&i<=n){
		suma=suma+i;
		i++;
		if(suma==n)
			consec=false;
	
	}
	if(consec)
		cout<<n<<" no es suma de numeros consecutivos"<<endl;
	else
		cout<<n<<" es suma de numeros consecutivos"<<endl;


}
