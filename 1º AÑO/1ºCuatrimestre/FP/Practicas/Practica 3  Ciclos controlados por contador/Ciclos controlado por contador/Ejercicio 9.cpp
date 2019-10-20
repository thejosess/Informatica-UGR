
#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	
	int num , cifra , i , ultimacifra , cifra1 , cifra2 , resto ;
	
	cout << "Introducir un entero: " ;
	cin >> num ;
	
	ultimacifra = num % 10 ;
	cifra = num / 10 ;
	
	if ( cifra < 10 )
	{
		cout <<  cifra << " " << ultimacifra << " " << endl;
		
	}
		
	else
	
	{
		for ( i = 10 ; resto < 10 ; i = i * 1 )
		{
			
			cifra1 = cifra / i ;
			cifra2 = cifra % i ;
	
			resto = cifra1 ;
			cifra = cifra1 ;
			
			cout << ultimacifra << " " << cifra2 << " " << cifra2 << " " << cifra1 << endl;
			
			
		}
		
	}


}
