//Ejercicio 3
#include <iostream>
using namespace std;
#include <cmath>

int main()
{
	double a, b, c, x1, x2 ;
	
	cout << "Introducir termino a: ";
	cin >> a;
	
	cout << "Introducir termino b: ";
	cin >> b;
	
	cout << "Introducir termino c: ";
	cin >> c;
	
	x1 =  ( - b + (sqrt( (b*b) -( 4 * a * c ) ) ) ) / ( 2  * a ) ;
	x2 =  ( - b - (sqrt( (b*b) -( 4 * a * c ) ) ) ) / ( 2  * a );
	
	cout << "La raiz 1 vale: " << x1 << endl;
	cout << "La raiz 2 vale: " << x2 << endl;
}
