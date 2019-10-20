//Ejercicio 10
#include <iostream>
using namespace std;
int main(){
	
	int n , x , y , v , z , i , x0 , y0 , z0 , v0 ;
	bool EsNarcisista = false ;
	
	do {
		
		cout << "Introduce un natural menor que 1690 : " ;
		cin >> n ;
	} while ( n <= 0 || n > 1690 ) ;
	
	x = n / 1000 ;
	y = ( n -1000 * x ) / 100 ;
	z = ( n - 1000 * x - 100 * y) / 10 ;
	v = n -1000 * x -100 * y -10 * z ;
	x0 = x ;
	y0 = y ;
	z0 = z ;
	v0 = v ;
	
	for ( i = 1 ; ( x + y + z + v) < n ; i ++ )
	{
		
		x = x*x0 ;
		y = y*y0 ;
		v = v*v0 ;
		z = z*z0 ;
	}
	
	if ((x+y+z+v) == n)
		
		EsNarcisista = true ;
		
	if ( EsNarcisista)
	{
		cout << "El numero " << n << " es narcisista porque sus cifras elevadas a "<< i << " dan " << n << endl;
		cout << x << " + " << y << z << " + " << v << endl; 
	}
	
	else
		cout << " El numero " << n << " NO es narcisista " << endl;
		
}
	

