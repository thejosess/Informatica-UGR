
#include <iostream>
using namespace std;

int main(){
    const int MAX = 1000;
    int v[MAX] , util_vector , j , pos , mayor = 0  , contador ;
    bool esprimo = true ;

	cout << "Introduce el tamaño del vector util: " ;
	cin >> util_vector ;
	
	
	for (int i=0; i <= util_vector - 1 ; i++)
	{
    	
    	cout << "Introducir numeros : ";
    	cin >> v[i];
    	
    	for (int j= 2  ; j < v[i] ; j ++)
		{
			if ( v[i] % j == 0)
				
				contador = contador + 1 ;
			
		}
	
	if ( contador == 0)
		
		esprimo = true;
	else
		esprimo = false ;
		
	if (esprimo == true)
		
		if ( v[i] > mayor)
		{
			mayor = v[i] ;	
			pos = i ;
		}
	}
		
		cout << "La posicion es : " << pos << " Y el mayor de los primos es : " << mayor << endl ;   

		
}

