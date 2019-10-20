//Ejercicio 4 Guion 4	

#include <iostream>
#include <cmath>
using namespace std;


int main ()
{
	
	double i , tope , numeros , menor , compara ;
	
	cout << "Introducir el limite de numeros : " ;
	cin >> tope ;
	
	compara = 0 ;
	
	cout << "Introducir un numero real " ;
	cin >> numeros ;
	
	menor = abs ( numeros ) ;
	
	while ( i < tope - 1 ) {
		
		cout << " Introducir un numero real " ;
		cin >> numeros ;
		
		if ( menor > abs ( numeros ) )
		
			menor = numeros ;
			
		i++ ;
}

	cout << "El numero real mas cercano a 0 es : " << menor << endl;
	
}
