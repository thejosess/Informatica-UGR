
#include <cmath>
#include <iostream>
using namespace std;

int main(){
    const int MAX = 1000;
    int v[MAX] , util_vector , suma = 0 ;

	cout << "Introduce el tamano del vector util: " ;
	cin >> util_vector ;
	
	cout << "Introducir numero en binario : " << endl ;
	
	
	for (int i=util_vector - 1; i >= 0  ; i--)
	{
    	
		cin >> v[i];
		
	}
	
	for ( int i = 0 ; i < util_vector ; i ++ )
	{
		
		suma=suma+(pow(2,i)* v[i]);
		
		
	}
	
	cout << "El numero en decimal es : " << suma << endl;
    
}

