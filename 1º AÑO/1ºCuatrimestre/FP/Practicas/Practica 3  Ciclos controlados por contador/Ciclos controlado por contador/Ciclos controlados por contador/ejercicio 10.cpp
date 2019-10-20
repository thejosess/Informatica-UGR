// Ejercicio 8 guion 4

#include<iostream>
using namespace std;

int main () {
	
	bool Esperfecto ;
	
	int n , i  , division , suma  ;
	
	cout << "Introducir numero : " ;
	cin >> n ;

	for ( i = 1 ; i < n  ; i ++ ) {
	
		if (n % i == 0 ){
			
			suma = suma + i ;
			
		}
	
	if ( suma == n )
		
		Esperfecto = true ;
		
	else
		
		Esperfecto = false ;
		
}

	if ( Esperfecto )
	
		cout << "El numero es perfecto " << endl;
		
	else
	
		cout << "El numero no es perfecto" << endl ; 
}

