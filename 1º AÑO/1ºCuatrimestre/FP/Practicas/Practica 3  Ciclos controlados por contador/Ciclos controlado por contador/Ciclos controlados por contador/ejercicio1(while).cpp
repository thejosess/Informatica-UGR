//Ejercicio 1

#include <iostream>
using namespace std;

int main ()
{
	
	int n , i , resultado  ;
	
	cout << "Introducir un entero: " ;
	cin >> n ;
	
	i = n; 	
	
	resultado = 1;
	
	while( i >= 1 )
	{	
			
			resultado = resultado * i  ; 
			
			i = i - 1;
			
			
  }
  
  	cout << "El factorial de n es :" << resultado << endl ;
  
}
