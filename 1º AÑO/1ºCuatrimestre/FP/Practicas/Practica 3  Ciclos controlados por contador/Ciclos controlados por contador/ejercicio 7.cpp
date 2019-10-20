// Ejercicio 7 guion 4

#include<iostream>
#include <cmath>
using namespace std;

int main ()
{

double n , a , mayor , segundo_mayor , tmp ;

cout << "Introducir numero de reales: " ;
cin >> n ;

cout << "Introducir "<< 1 << "real : " ;
cin >> a ;

mayor = a ;

cout << "Introducir " << 2 << "real: " ;
cin >> a ;

segundo_mayor = a ;


	if ( segundo_mayor > mayor )
		
		tmp = segundo_mayor ; 
		segundo_mayor = mayor ;
		mayor = tmp ;
		
		
	for ( int i = 3 ; i <= n ; i++) {
		
			cout << "Introducir " << i << "real : " ;
			cin >> a ;
			
			if ( a > mayor )
			
				mayor = a ;
				
			if ( a > segundo_mayor && a < mayor )
			
				segundo_mayor = a ;
				
}

cout << "El mas cercano es: " << segundo_mayor << endl;

}
