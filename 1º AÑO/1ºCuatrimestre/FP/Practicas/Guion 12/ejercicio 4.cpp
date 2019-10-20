#include <iostream>
using namespace std ;

class NumeroBinario{
	
	private :
		
		int	num ;
		static const int MAX = 100 ;
		int v[MAX], util_vector ;
	
	public :
		
		void IntroducirNumero(int numero)
		{
			num = numero ;
		}
		
		void AsignarDato( int i , int dato)
		{
			v[i] = dato ;
		}
		
		void AsignarUtilVector( int dato)
		{
			util_vector = dato ;
		}
		
		void BinarioDecimal()
		{
			int util , i  ;
			NumeroBinario numero ;
			
			for ( i = 0 ; num > 1 ; i++ )
			{
					numero.AsignarDato(i, num % 2)	; 
					
					num = num / 2 ; 
		
					util ++ ;
			}
				numero.AsignarUtilVector(util) ;
				
			for ( i = numero.DevolverUtilvector() - 1 ; i >= 0 ; i-- )
				{
					/*cout << numero.DevolverDato(i)  ; */
				}
		}
		
		int DevolverUtilvector()
		{
			return util_vector ;
		}
		
		int DevolverDato( int i )
		{
			return v[i] ;
		}
		
};

void DevolverNumero( NumeroBinario numero)
{
		int i ;
		
		for ( i = numero.DevolverUtilvector() - 1 ; i >= 0 ; i-- )
		{
				cout <<"\n " << numero.DevolverDato(i) << endl ;
		}
}

int main ()
{
	int i , numero;
	NumeroBinario num ;
	
	cout << "Introducir numero decimal: " ;
	cin >> numero ;
	
	num.IntroducirNumero (numero) ;
	num.BinarioDecimal() ;
	DevolverNumero(num) ;
}
