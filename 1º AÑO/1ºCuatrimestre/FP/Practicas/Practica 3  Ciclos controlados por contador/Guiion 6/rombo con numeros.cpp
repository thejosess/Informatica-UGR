#include <iostream>
#include <cmath>
using namespace std;

int main (){
	
	int L ;
	
	cout << "Introducir longitud: " ;
	cin >> L ;
	
	for ( int i = 1 ; i <= L / 2 ; i ++ ){
		
		for ( int j = L ; j >= i ; j -- ) {
			
			cout << ' ' ;
			}
		
		for ( int j = 1 ; j <= 2 * i - 1 ; j ++ ) {
			
			cout << ( 2*j-1)%10 ;
		}
		
		cout << endl ;
	}
	
	for ( int i = L / 2 + 1 ; i >= 1 ; i--){
		
		for ( int j = i ; j <= L ; j ++){
			
			cout << ' ' ;
		}
		
		for ( int j = 1 ; j <= 2 * i - 1 ; j++){
			
			cout << ( 2 * j - 1 ) % 10 ;
			
		}
		cout << endl ;

	}	
}
