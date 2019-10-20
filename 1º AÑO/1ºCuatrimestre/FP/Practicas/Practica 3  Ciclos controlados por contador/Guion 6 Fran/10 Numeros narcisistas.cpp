/* Un Número Narcisista es aquel número de n dígitos que resulta ser igual a la suma de las
potencias de orden n de sus dígitos. Un ejemplo es 153, porque equivale a 1³ + 5³ + 3³. Realizar
un programa que solicite un número entero positivo desde teclado menor de 1690 e indique si es
o no narcisista. */



#include <iostream>
#include <cmath>

using namespace std;

int main()
{
int cociente,cociente2,cociente3,ultimo_dato1,contador=0,ultimo_dato2,numero;
	
	cout<<"Introducir entero: ";
	cin>>cociente;
	
	cociente2=cociente;
	
//Contador
	while(cociente>0){
		
		ultimo_dato1=cociente%10;
		
		cociente=cociente/10;
		
		contador++;
		

	}
	
	cout<<"Tiene "<<contador<<" digitos"<<endl;
	
//Cifras separadas
	int suma=0;
	
	cociente3=cociente2;
	
	while(cociente2>0){
		
		ultimo_dato2=cociente2%10;
		
		cociente2=cociente2/10;
		
		numero=pow(ultimo_dato2,contador);
		
		suma=suma+numero;
		

	}
	if(suma==cociente3)
		cout<<cociente3<<" es narcisista"<<endl;
	else
		cout<<cociente3<<" no es narcisista"<<endl;
}
