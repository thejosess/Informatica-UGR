//Realizar un programa que lea un número entero y calcule el número de cifras que tiene.



#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int i,cociente,ultimo_dato,contador=0;
	
	cout<<"Introducir entero: ";
	cin>>cociente;
	
	while(cociente>0){
		
		ultimo_dato=cociente%10;
		
		cociente=cociente/10;
		
		contador++;

	}
	cout<<contador;
}

