#include <iostream>

using namespace std;

int main ()
{
	int n , aux_numeros1 , numeros2, numeros1 ;
	
	cout << "Introduce n: " ;
	cin >> n ;
	
	cout << endl;
	
	for ( int i = 1 ; i <= n ; i++){
	
	
		for ( int j = n - i ; j > 0 ; j --){
		
				
			cout << " " ;
			
		}
		
		numeros1 ++ ;
		aux_numeros1 = numeros1;
		
		for ( int j = i ; j > 0 ; j--){
			
			cout << aux_numeros1%10;
			aux_numeros1-- ;
	
		}
	
		numeros2 = 2 ;	
	
		for ( int j = n - i + 1 ; j > 0 ; j --){
			
			cout << numeros2%10;
			numeros2 ++ ;
		}
	}
		
		cout << endl ;
}
