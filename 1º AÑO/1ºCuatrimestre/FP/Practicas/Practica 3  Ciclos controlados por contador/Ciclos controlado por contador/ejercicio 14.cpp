// Ejercicio 14

#include<iostream>
using namespace std;

int main () {
	
	int fn , fn_1 , fn_2 , n ;
	
	cout << "Introducir el numero para realizar fibonacci : " ;
	cin >> n ;
	
	fn_1 = 0 ;
	
	fn_2 = 1 ;
	
	fn = 0 ;
	
	for ( int i = 2 ; i <= n ; i ++) {
		
		fn = fn_1 + fn_2 ;
		fn_2 = fn_1 ;
		fn_1 = fn ;
		
	}
	
	cout << fn << endl;

}
