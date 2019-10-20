#include <iostream>
using namespace std;

int main()
{
	bool esprimo;
	int n ;
	
	cout << "Introduzca un entero:  " ;
	cin >> n ;
	
	if ( n % 2 == 0 && n % 3 == 0 )
		
		esprimo = true ;
		
	else 
		
		esprimo = false ;
		
	if ( esprimo = true )
		
		cout << " El numero tiene al 2 y al 3 como factores primos " << endl;
	
	else 
		
		cout << "El numero no tiene al 2 y al 3 como factores primos " << endl;
		
}
