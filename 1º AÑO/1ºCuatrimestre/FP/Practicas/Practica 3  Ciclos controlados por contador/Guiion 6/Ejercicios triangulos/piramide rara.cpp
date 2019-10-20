#include <iostream>

using namespace std;

int main ()
{
	
	int l  , i ;
	
	l = 7 ;
	
	for ( i = 3 ; i >= 0 ; i-- )
	{
		
		for ( int j = 1 ; j <= i ; j++)
		{
			
			cout<< " " ;
			
		}
		
		for ( int  k = 1 ; k <= l - (i*2) ; k++)
		{
			
			cout << "*" ;
			
		}
		
		for ( int j = l ; j <= i ; j++)
		{
		
			cout << " " ;
		
		}	
	
	cout << endl;
	cout << endl;
	
}
	
}
