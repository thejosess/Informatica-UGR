//Ejercicio dibujar figuras con asteriscos

#include <iostream>
using namespace std;

int main ()
{
	
	int i , j , l ;
	
	cout << "Introducir el numero de lineas maximo para el dibujo : " ;
	cin >> l ;
	
	for (j = 1 ; j <= l  ; j ++ )
	{
		for ( i = j ; j <= l ; i++ )
		
			cout << '*' ;

			
		cout << endl;
	
}

}
