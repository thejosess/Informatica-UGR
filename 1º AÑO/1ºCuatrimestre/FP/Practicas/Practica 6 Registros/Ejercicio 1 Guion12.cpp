#include <iostream>
#include <cmath>
using namespace std ;


class Polinomio2G
{
	private :
		
		int a ;
		int b ;
		int c ;
	
	public :
		
		Polinomio2G()
		{						
			a = 0 ;				
			b = 0 ;
			c = 0 ;
		}
		
		void IntrodTerminoA ( int dato )
		{
			a = dato ;
		}
		
		int TerminoA ()
		{
			return a ;
		}
		
		void IntrodTerminoB ( int dato )
		{
			b = dato ;
		}
		
		int TerminoB ()
		{
			return b ;
		}
		
		void IntrodTerminoC ( int dato )
		{
			c = dato ;
		}
		
		int TerminoC ()
		{
			return c ;
		}
		
};

	Polinomio2G LeerPolinomio ()
	{
		Polinomio2G p ;
		int a , b , c ;
		
		cout << "Introducir termino A del polinomio: " ;
		cin >> a ;
		p.IntrodTerminoA(a) ;
		
		cout << "Introducir termino B del polinomio: " ;
		cin >> b ;
		p.IntrodTerminoB(b) ;
		
		cout << "Introducir termino C del polinomio: " ;
		cin >> c ;
		p.IntrodTerminoC(c) ;
		
		return p ;
	}
	
	void MostrarPolinomio (Polinomio2G p )
	{
		cout << "El polinomio es : " << p.TerminoA() << "x^2 + " << p.TerminoB() << "x + " << p.TerminoC() << endl ; 	
	}

	Polinomio2G Suma ( Polinomio2G pol1 , Polinomio2G pol2)
	{
		Polinomio2G p ;
			
		p.IntrodTerminoA(pol1.TerminoA() + pol2.TerminoA()) ;
		p.IntrodTerminoB(pol1.TerminoB() + pol2.TerminoB()) ;
		p.IntrodTerminoC(pol1.TerminoC() + pol2.TerminoC()) ;
			
		return p ;
	}
	
	Polinomio2G Producto ( Polinomio2G pol1)
	{
		Polinomio2G p ;
		int num ;
		
		cout << "Introducir numero a multiplicar: " ;
		cin >> num ;
		
		p.IntrodTerminoA(pol1.TerminoA() * num ) ;
		p.IntrodTerminoB(pol1.TerminoB() * num ) ;
		p.IntrodTerminoC(pol1.TerminoC() * num) ;		
		
		return p ;
		
	}
	
	int Raices ( Polinomio2G pol1)
	{
		double x1 , x2 ;
		
		x1 =  ( - pol1.TerminoB() + (sqrt( (pol1.TerminoB()*pol1.TerminoB()) -( 4 * pol1.TerminoA() * pol1.TerminoC() ) ) ) ) / ( 2  * pol1.TerminoA() ) ;
		x2 =  ( - pol1.TerminoB() - (sqrt( (pol1.TerminoB()*pol1.TerminoB()) -( 4 * pol1.TerminoA() * pol1.TerminoC() ) ) ) ) / ( 2  * pol1.TerminoA() );
	
		cout << "La raiz 1 vale: " << x1 << endl;

		cout << "La raiz 2 vale: " << x2 << endl;
		
	}

int main ()
{
	Polinomio2G pol1 , pol2 ;
	cout << "PRIMER POLINOMIO: " << endl ;
	pol1 = LeerPolinomio() ;
	MostrarPolinomio(pol1) ;
	
	cout << "SEGUNDO POLINOMIO: " << endl ;
	pol2 = LeerPolinomio() ;
	MostrarPolinomio(pol2) ;	
	
	cout << "LA SUMA DE AMBOS: " << endl ;
	MostrarPolinomio(Suma(pol1 , pol2)) ;
	
	MostrarPolinomio(Producto(pol1)) ;
	
	Raices(pol2) ;
}
