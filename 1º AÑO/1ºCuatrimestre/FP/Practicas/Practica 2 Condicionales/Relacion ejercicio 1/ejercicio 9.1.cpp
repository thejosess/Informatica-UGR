
//Ejercicio 9

#include <iostream>

using namespace std;

int main()
{
	
	//Entrada
	char a ;
	int  i ;
	
	cout << "Introducir caracter: " ;
	
	cin >>a;
	
	i = a ;
	
	//Proceso
	
	if ( i >= 97 && i <= 122 )
	{
		a = i -32 ;
		cout << " La letra es minuscula y su mayuscula es : " << a << endl;		
	}
	
	else
	{
		a = i + 32 ;
	 	cout << "La letra es mayuscula y su minuscula es :" << a << endl;
	}
		
}
