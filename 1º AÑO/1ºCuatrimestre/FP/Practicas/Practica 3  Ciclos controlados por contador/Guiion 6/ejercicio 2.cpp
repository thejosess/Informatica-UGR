
#include <iostream>

using namespace std;

int main ()
{
	
	int suma , abundantes = 0  ;
				
	for ( int i = 1 ; abundantes < 50 ; i++) 
	
	{
		suma = 0 ;
		
		for ( int j = 1 ; j < i ; j ++ )
		
		{
			
			if ( i % j == 0) {
			
									
				suma+=j ;
			} 
			
			}
				if (suma > i){
				
					
					cout <<" " << abundantes+1 << ".=>" << i << endl ;
					abundantes++;
			}
			
			
		
	}
	
	
}
