#include <iostream>
using namespace std ;

int main (){
	
	const int MAX = 1000 ;
	int v[MAX] , util_v , longitud , pos , mayor ;
	bool secuencia = false ;
	
	cout << "Introducir tamaño del vector: " ;
	cin >> util_v ;
	
	for ( int i = 0 ; i < util_v ; i ++)
	{
		cout << "Introdcir elemento " << i << " del vector: " ;
		cin >> v[i] ;
	}
	
	for (int i=0; i<util_v; i++)
	{
		longitud = 0 ;
		
		for (int j= i + 1; j<util_v; j++){
		
			if (v[i] + 1 ==v[j])
				longitud ++;
		}
		if (i==0)
			mayor=longitud;
		else
			if (longitud>mayor)
			{
				mayor=longitud;
				pos=i;
			}
	}
	
	
	cout << "La longitud de la secuencia de seguidos mas larga es : " << longitud << " , comienza en : " << pos  << endl ;
}

