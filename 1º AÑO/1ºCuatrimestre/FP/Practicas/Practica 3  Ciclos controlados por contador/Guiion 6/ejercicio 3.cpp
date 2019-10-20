#include <iostream>

using namespace std ;

int main (){
	
	int i , j , multiplicando , multiplicador ;
	
	cout << "Introducir primero numero: " ;
	cin >> multiplicando ;
	
	cout << "Introducir segundo numero: " ;
	cin >> multiplicador ;	
	
	
	while ( multiplicando > 1) {
		
			multiplicando = multiplicando / 2 ;	
			
			while (  multiplicando > 1 )
			
				multiplicador = multiplicador * 2 ;
			
			cout << "Es : " << multiplicador << endl ;

		}

	
	
	
	
	
}
