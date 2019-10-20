#include <iostream>
using namespace std ;

int main (){
	
	const int MAX = 1000 ;
	int v[MAX] , util_v , pos , longitud= 0 , mayor ;
	bool secuencia = false ;
	
	cout << "Introducir tamaño del vector: " ;
	cin >> util_v ;
	
	for ( int i = 0 ; i < util_v ; i ++)
	{
		cout << "Introdcir elemento " << i << " del vector: " ;
		cin >> v[i] ;
	}
	
	for ( int i = 0 ; i < util_v ; i ++)
	{
		if ( v [i] + 1 == v[i+1] )
				 
			longitud ++ ; 
			
			
		if (i==0)
			mayor=longitud;
		else
			if (longitud>mayor)
			{
				mayor=longitud;
				pos=i;
			}
		
	}
	
	cout << "La longitud de la secuencia de seguidos mas larga es : " << mayor << " , comienza en : " << pos - 1 << endl ;
}

