// Ejercicio 1 Guion 7 

#include <iostream>
using namespace std;

int main ()
{
	
	int num , i , a , resto ;
	
	const int MAX = 1000 ;
	int vector[MAX] , util_vector = 0 ;
	
	cout << "Introducir el decimal que quieres pasar a binario: " ;
	cin >> num ;
	
	a = num ;
	
	for ( i = 0 ; a > 1 ; i++ )
	{
	
		vector[i] = a % 2 ; // Aqui estamos procesando el vector , por eso no es necesarios hacer un for expecific
		
		a = a / 2 ;
		
		util_vector ++ ;
		
	}
	
	cout << a ; 
	
	for ( i = util_vector - 1 ; i >= 0 ; i-- )
	{
		
		cout << vector [ i ] ;
		
	}
	
}
