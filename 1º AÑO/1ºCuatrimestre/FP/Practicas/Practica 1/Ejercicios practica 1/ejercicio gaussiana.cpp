// Ejercicio formula gaussiana

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	
	// Variables 
	
	double media , desviacionTipica , valorAbcisa , valorGaussiana ;
	
	cout << "Introducir media: ";
	cin >> media ;
	
	cout << "Introducir desviacion tipica : " ;
	cin >> desviacionTipica ;
	
	cout << "Introudcir valor de la abcisa " ;
	cin >> valorAbcisa ;
	
	// Operaciones
	
   valorGaussiana = ( exp (	( -1 / 2 ) * ( pow ( ( valorAbcisa - media ) / ( desviacionTipica )   , 2 ) )  ) ) / ( desviacionTipica * ( sqrt ( 2 * 3.14159265 ) ) ) ;
   
   cout << " El valor de la operacion Gaussiana es : " << valorGaussiana << endl ;
   
}
