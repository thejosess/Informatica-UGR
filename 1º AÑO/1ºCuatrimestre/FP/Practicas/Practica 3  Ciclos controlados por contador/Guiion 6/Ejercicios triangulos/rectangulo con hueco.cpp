// Ejercicio cuadrado 
#include <iostream>

using namespace std;

int main (){
	
	int L ;
	
	cout << "Introducir longitud: " ;
	cin >> L ;
	
	
	for ( int i = 1 ; i <= L ; i++){
		
		cout << '*' ;
		
	}
	
	cout << endl ;
	
	for ( int i = 1 ; i <= L-2 ; i++ )
	{
		cout << '*' ;	
			
		for ( int j = 1 ; j <= L -2 ; j++ ){
			
			cout << ' ' ;
			
		}	
		
		cout << '*' ;
		cout << endl ;	
	}
	
	for ( int i = 1 ; i <= L ; i++){
		
		cout << '*' ;
	}
	
	cout << endl;
}
