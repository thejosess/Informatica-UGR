// Ejercicio 11 Guion 4

#include <iostream>

using namespace std;

int main() {
	
	int tope , i , numero1 , numero2 , a , compare  ;
	
	bool ordenados = true ;
	
	cout << "Cantidad de numeros a leer: " ;
	cin >> tope ;
	
	cout << "Primer numero : " ;
	cin >> numero1 ;
	
	cout << "Segundo numero : " ;
	cin >> numero2 ;
	
	
	for ( i = 0 ; i < tope - 2 ; i ++ ){
	
			cout << "Leer numero : " ;
			cin >> a ;
			
			if ( numero2 > numero1 )
				
				compare = numero2 ; 
			
			if ( compare < a ){ 
			
				compare = a ;
				ordenados = true ;
				
			}else
			
				ordenados = false ;
			
}
	if ( ordenados == true )
	
		cout << "Están ordenados " << endl;
		
	else
	
		cout << "Estan desordenados " << endl;
}
	
