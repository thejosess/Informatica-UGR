//Ejercicio dibujar figuras con asteriscos

#include <iostream>
using namespace std;

int main ()
{
	
	int i , j , l ;
	
	cout << "Introducir el numero de lineas maximo para el dibujo : " ;
	cin >> l ;
	
	for (j = l ; j >= 1  ; j -- )
	{
		for( i = 1; i <= (l-j) ; i ++) 
		{ 
			cout<<" "; 
		} 
		
		for ( i = 1 ; i <= j ; i++ )
		
			cout << '*' ;
			cout << endl;
	
}

}
