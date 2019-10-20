#include <iostream>
#include <string>
using namespace std ;

int main(){
	
	const int MAX = 1000 ;
	int v1[MAX] , v2 [MAX] , util_v1, util_v2 , i , j , pos_encontrado;
	bool encontrado , va_coincidiendo  ;
	
	do{
		cout << "Introduzca el num de elementos VECTOR 1 que va a tener el vector (entre 1 y " << MAX << "): ";
		cin >> util_v1;
	}while (util_v1 < 1 || util_v1 > MAX);
	
	do{
		cout << "Introduzca el num de elementos VECTOR 2 que va a tener el vector (entre 1 y " << MAX << "): ";
		cin >> util_v2;
	}while (util_v2 < 1 || util_v2 > MAX);
	
	
	for (int i=0; i<util_v1; i++)
	{
		cout << "Introduzca el elemento VECTOR 1 del vector: ";
		cin >> v1[i];
	}
	
	
	for (int i=0; i<util_v2; i++)
	{
		cout << "Introduzca el elemento VECTOR 2 del vector: ";
		cin >> v2[i];
	}
	
	for (int i = 0 ; i + util_v2 <= util_v1 && !encontrado ; i ++)
	{
		va_coincidiendo = true ;
		
		for ( int j = 0 ; j < util_v2 && va_coincidiendo ;
		 va_coincidiendo = v1 [i+j] == v2[j]  )	
			
			if ( va_coincidiendo){
				
				encontrado = true ;
				pos_encontrado = i ;
			}		
	}
	
    if ( encontrado)
    	cout << "Encontrado en la posicion" << pos_encontrado ;
    else
    	cout << "No encontrado" ;
}
