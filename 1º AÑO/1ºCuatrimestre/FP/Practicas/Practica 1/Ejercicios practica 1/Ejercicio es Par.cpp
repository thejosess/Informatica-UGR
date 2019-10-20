//Programa que lee si un numero es par o impar

#include <iostream>

using namespace std;

int main()
{
	int n ;
	bool  esPar ;
	
	cout << " Introduce el numero: " ;
	cin >> n ;
	
	if ( n%2 == 0 ) 
		esPar = true ;
		
	if ( n == 0 )
		cout << " 0 es par " ;
		
	else
		
		if ( esPar ) 
		   cout << n << " es par " << endl;
		else
			cout << n << " es impar " << endl;
			
	
}
