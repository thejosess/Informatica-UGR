//Ejercicio 11

#include <iostream>

using namespace std;

int main()
{
	double a , b , c , d , e , f , g , h , i , j , media , n=0 ;
	
	
	cout << "Introducir un valor real: " ;
	cin >> a ;
	
	cout << "Introducir un valor real: " ;
	cin >> b ;
	
	cout << "Introducir un valor real: " ;
	cin >> c ;
	
	cout << "Introducir un valor real: " ;
	cin >> d ;
	
	cout << "Introducir un valor real: " ;
	cin >> e ;
	
	cout << "Introducir un valor real: " ;
	cin >> f ;
	
	cout << "Introducir un valor real: " ;
	cin >> g ;
	
	cout << "Introducir un valor real: " ;
	cin >> h ;
	
	cout << "Introducir un valor real: " ;
	cin >> i ;
	
	cout << "Introducir un valor real: " ;
	cin >> j ;
	
	media = ( a + b + c + d + e + f + g + h + i + j ) / 10 ;
	
	if ( a > media ) 
		
		n = n + 1 ;
		
 	if ( b > media ) 
		
		n = n + 1 ;
		
	if ( c > media ) 
		
		n = n + 1 ;
		
	if ( d > media ) 
		
		n = n + 1 ;
		
	if ( e > media ) 
		
		n = n + 1 ;
		
	if ( f > media ) 
		
		n = n + 1 ;
		
	if ( g > media ) 
		
		n = n + 1 ;
		
	if ( h > media ) 
		
		n = n + 1 ;
		
	if ( i > media ) 
		
		n = n + 1 ;
		
	if ( j > media ) 
		
		n = n + 1 ;
		
	cout << "Hay " << n << " valores mayores que la media " << endl;
  
}
