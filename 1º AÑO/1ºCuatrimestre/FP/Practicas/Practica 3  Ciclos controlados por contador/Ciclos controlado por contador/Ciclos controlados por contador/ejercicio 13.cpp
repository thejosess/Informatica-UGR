// Ejercicio 13 Guion 4

#include<iostream>

using namespace std;

int main () {
	
	int a , mayor_neg , menor_pos ;
	bool HayPosit = false , HayNeg = false ;
	
	
	for ( int i = 1 ; i <= 5 ; i++ ) 
	{
		
		cout << "Introducir enteros: " ;
		cin >> a ;
		
		if ( a > 0 )
		{
			
			if ( HayPosit ) 
			{
				
				if ( a < menor_pos )
				
					menor_pos = a ;
			}
			
			else 
			
			{
				menor_pos = a ;
				
				HayPosit = true ;
			}
		}
		
		if ( a < 0 )
		{
			
			if ( HayNeg ) 
			{
				
				if ( a > mayor_neg )
				
					mayor_neg = a ;
			}
			
			else 
			
			{
				mayor_neg = a ;
				
				HayNeg = true ;
			}
		}


	}

	for ( int i = mayor_neg + 1 ; i < menor_pos ; i++ )
		{
			
			cout << i << endl ;
			
		}



}
