//Ejercicio 3

#include <iostream>
using namespace std;

int main ()
{
	
	int n , i , resultado  ;
	
	cout << "Introducir un entero: " ;
	cin >> n ;
	
	i = 1 ;
	
	while( i <= 1000 )
	{	
			
			resultado = n * i  ; 
			
			i ++ ;
			
		  	cout << "Los multiplos  de n son :" << resultado << endl ;
			
  }
  
}
