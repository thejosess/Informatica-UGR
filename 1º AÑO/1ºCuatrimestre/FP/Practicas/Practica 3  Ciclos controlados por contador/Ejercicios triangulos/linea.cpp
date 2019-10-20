
//Ejercicio dibujar figuras con asteriscos

#include <iostream>
using namespace std;

int main ()
{
	
	int i , j , l ;
	
	cout << "Introducir el numero de lineas maximo para el dibujo : " ;
	cin >> l ;
	
	for ( i = 1 ; i <= l ; i++ )
	{
		for ( j = 1  ; j <=l ; j++)
		
			cout << '*' ;
			cout << endl;
	}


}
