#include <iostream>
using namespace std ;


class Polinomio2G
{
	private :
		
		int a ;
		int b ;
		int c ;
	
	public :
		
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
		p.IntrodTerminoA(b) ;
		
		cout << "Introducir termino C del polinomio: " ;
		cin >> a ;
		p.IntrodTerminoA(c) ;
		
		return p ;
	}
	
	void MostrarPolinomio (Polinomio2G p )
	{
		cout << "El polinomio es : " << p.TerminoA() << "x^2 + " << p.TerminoB() << "x + " << p.TerminoC() << endl ; 	
	}

/*	Polinomio2G Suma ( Polinomio2G pol1 , Polinomio2G pol2)
	{
		Polinomio2G p ;
			
		p.IntrodTerminoA(pol1.TerminoA() + pol2.TerminoA()) ;
		p.IntrodTerminoB(pol1.TerminoB() + pol2.TerminoB()) ;
		p.IntrodTerminoC(pol1.TerminoC() + pol2.TerminoC()) ;
			
		return p ;
	} */

int main ()
{
	Polinomio2G pol ;
	
	pol = LeerPolinomio() ;
	MostrarPolinomio(pol) ;	
	
}
