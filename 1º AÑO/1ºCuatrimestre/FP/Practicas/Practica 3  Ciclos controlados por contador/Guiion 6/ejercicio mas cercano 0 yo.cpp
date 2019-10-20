#include <iostream>
#include <cmath>

using namespace std;

int main()
	{
		int i ;
		double n , cercano , numero ;
		
		cout << "Introducir el numero de reales que va a introducir :  " ; 
		cin >> n ;
		cout << "Introducir un numero real : ";
		cin >> numero ;
		
			cercano = numero ;
			
		for ( i = 2 ; i <= n ; i++)
		{
			
			cout << "Introduzca un numero real: " ;
			cin >> numero ;
			
			if ( numero < cercano )
				
				cercano = numero ;
		}
		
	cout << "El numero mas cercano a 0 es : " << cercano << endl;
	
}
