//Ejercicio sumatoria y factorial

#include <iostream>
using namespace std;

int main () 
{
	int producto , i , n ,suma ;
	
	producto = 1 ;
	suma = 0 ;
	
	cout << " Introducir el numero para hacer sumatoria y factorial " ;
	cin >> n ;
	
	for ( i=1 ; i <= n ; i++ ) {
	
		producto = producto * i ;
		
		suma = suma + producto ;
	}

	cout<<"El resultado es : " << suma << endl;

}
