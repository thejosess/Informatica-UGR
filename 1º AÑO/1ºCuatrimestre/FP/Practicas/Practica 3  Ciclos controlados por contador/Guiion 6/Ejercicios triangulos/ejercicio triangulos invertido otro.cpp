//Ejercicio dibujar figuras con asteriscos

#include <iostream>
using namespace std;

int main ()
{
	
	int i , j , l ;
	
	cout << "Introducir el numero de lineas maximo para el dibujo : " ;
	cin >> l ;
	
	for ( i = l ; i >= 1  ; i -- )
	{
		for ( j = 1 ; j <= l - 1 ; j ++)
		
			cout << ' ' ;
			
		for ( j = 1 ; j <= i ; j ++ )
		
			cout << '*' ;
			
		cout << endl;
	
}

}
