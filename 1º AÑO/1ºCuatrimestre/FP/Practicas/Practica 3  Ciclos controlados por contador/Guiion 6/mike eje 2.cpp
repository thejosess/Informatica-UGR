
#include <iostream>

using namespace std;

int main ()
{
	
	int i , j , num , divisores = 0 , suma = 0 ;
				
	for ( i = 2 ; i < 50 ; i++) 
	
	{
		
		for ( j = 1 ; j < i ; j ++ )
		
		{
			
			if ( num % j == 0) {
									
				divisores = j ;					
				suma = divisores + suma ;
			}	
				if (suma > i) {
				
					
					cout << "Un numero abundante es : " << i << endl;
				
				}
			
		}
	}
	
	
}
