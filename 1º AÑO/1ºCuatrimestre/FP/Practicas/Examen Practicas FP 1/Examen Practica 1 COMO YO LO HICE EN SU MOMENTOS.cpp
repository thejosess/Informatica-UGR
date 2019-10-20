// Examen practica 1

#include <iostream>

using namespace std ;

int main () {
	
	int n , i , j , numero , numero1 , contador ;
	
	cout << " Introducir el numero de filas para la figura : " ;
	cin >> n ;
	
	contador = 1 ;
	
	for ( i = n ; i >= 2 ; i -- )
	{
		
		for ( j = 1 ; j <= i ; j ++ ) 
		{
			
			cout << " " ;
			
		}
		
		for ( j = n ; j >= i ; j -- )
		{
			
			//Me ha faltado realizar esta parte bien por falta de tiempo, si hubiera creado una variable llamada linea
			// que contara con ++ las veces que entra en el primer for , y luego le vas restando -1 dentro de este for y lanzando ese numero 
			// por pantalla me hubiera salido
			
			numero = j ;
				
			cout << numero % 10  ;
		
		}
		
		for ( j = 1 ; j <= i ; j ++ )
		{
			
			numero = j ;
			
			cout << numero % 10 ;
		}
		
		cout << endl ;
	}
	
	
}
