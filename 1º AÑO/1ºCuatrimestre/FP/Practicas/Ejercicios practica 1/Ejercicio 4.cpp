//Programa capaz de resolver un sistema de ecuaciones
//Ejercicio 4

#include <iostream>
using namespace std;

int main () 
{
	//Primera parte del algortimo, definicion de variables
	
	double a , b , c , d , e , f , x , y ;
	
	cout << "  ax + by = c    dx + ey = f  " << endl ;
	
	cout << "Introducir termino a : " ;
	cin >> a ;
	
	cout << "Introducir termino b : " ;
	cin >> b ;
	
	cout << "Introducir termino c : " ;
	cin >> c ;
	
	cout << "Introducir termino d : " ;
	cin >> d ;
	
	cout << "Introducir termino e : " ;
	cin >> e ;
	
	cout << "Introducir termino f : " ;
	cin >> f ;
	
	//Segunda parte del algo, operaciones de variables
	
	y = ( (f * a) + (d * c * -1) ) / ( (a * e ) + (d * b * -1) ) ;
   x = ( c + (b * y * -1) ) / a ;
   
   cout << "El valor de x es : " << x << endl ;
   cout << "El valor de y es : " << y << endl ;
   
}
