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
	
	if (  (b*b) -( 4 * a * c )  > 0 )
		
		cout << "Tiene dos raices " << endl;
		
	else 
	
		if ( (b*b) -( 4 * a * c )  > 0 )
		
		   cout << "No tiene ninguna raiz " << endl;
		
      else 
      
			if (  (b*b) -( 4 * a * c ) == 0 )
  		
  		      cout << "Tiene una raiz " << endl ;
		
}
