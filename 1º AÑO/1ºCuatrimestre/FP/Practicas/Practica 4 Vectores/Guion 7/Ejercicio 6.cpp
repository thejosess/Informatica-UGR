#include <iostream>
#include <string>
using namespace std ;

int main(){
	
	const int MAX = 1000 ;
	string v1[MAX] , v2 [MAX] , vu [MAX] , vi [MAX] ;
	int util_v1, util_v2 , i , j , util_vu ,x , util_vi;
	
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
	
	//VECTOR UNION
	
	util_vu = util_v1 + util_v2 ;
	
	for ( int i = 0 ; i < util_v1 ; i++)
		
		vu[i] = v1[i] ;
	
	 x = 0 ;	
	for ( int i = util_v1 ; i < util_vu ; i++){
		
		vu[i] = v2[x] ;
		x++ ;
	}
	
	//VECTOR INTERSECCION
	
	util_vi = 0 ;
	bool encontrado , existe = false ;
	
	for ( int j = 0 ; j < util_v1 ; j ++)
	{
		encontrado = false ;
		
		for ( int i = 0 ; i < util_v2 && !encontrado; i++)
		{
			if ( v2[i] == v1[i] )
			{
				vi[util_vi] = v1[j] ;
				util_vi ++ ;
				encontrado = true ;
				existe = true ;
			}	
		}
	}
	//////////////////////////////////
	
	for ( int i = 0 ; i < util_vu  ; i++)
	{
		cout <<"El vector union es : " << vu[i] << endl ;
	}
	
	for ( int i = 0 ; i < util_vi  ; i++)
	{
		cout << "El vector interseccion es : " << vi[i] << endl ;
	}
	
}
