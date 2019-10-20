// Ejercicio 5 con for  solo con letras en minuscula

#include <iostream>
using namespace std;
int main()

{
	
	char car ;
	int  i , n , cantidad_a , cantidad_z ;
	
	cantidad_a = 0 ;
	cantidad_z = 0 ; 
	
	for ( i = 0 ;  i <= 20 ; i ++ ) {
	
		cout << "Introduce una letra entre a - z : " ;
		cin >> car ;
			
		n = car ;
		
		if ( n == 97 ){
			
			cantidad_a = cantidad_a + 1 ;
		}
		
		if ( n == 122 ) {
			
			cantidad_z = cantidad_z + 1 ; 
		}	
	
	}
	
	if ( cantidad_a > cantidad_z )
		
		cout << "La letra a se ha introducido mas veces que z " << endl;
	
	if ( cantidad_z > cantidad_a )
	
		cout << "La letra z se ha introducido mas veces que a " << endl;
		
	if ( cantidad_z == 0 )
	
		cout << " No se ha introducido ninguna vez la z " << endl;
		
	if ( cantidad_a == 0 )
	
		cout << " No se ha introducido ninguna vez la a " << endl;
		
}
