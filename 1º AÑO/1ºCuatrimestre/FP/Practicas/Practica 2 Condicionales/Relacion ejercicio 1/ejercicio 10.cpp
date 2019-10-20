//Ejercicio 10

#include <iostream>

using namespace std;

int main()
{
	
	//Entrada
			
	char  opccion ;
	double  a, b , valor ;
	
	cout << "Introducir primer real " ;
	
	cin >> a ;
	
	cout << "Introducir segundo real " ;
	
	cin >> b ;

	cout << "Suma(-S),restar(-R), multiplicar	(-M), dividir( -D ) " ;
	
	cin >> opccion ;
	
	//Proceso

   if ( opccion == 'S' || opccion == 's') 
   {	
   	valor = a + b ;
   	cout << "La suma es : " << valor << endl;
  }
   if ( opccion == 'R' || opccion =='r')
	{
   	valor = a * b ;
   	cout << "La multiplicacion es : " << valor << endl;
	}
     if ( opccion == 'R' || opccion =='r') 
   {
   	valor = a / b ;
   	cout << "La division es : " << valor << endl;
	}
   if ( opccion == 'R' || opccion =='r') 
   {
   	valor = a - b ;
   	cout << "La resta es : " << valor << endl;
	}
	
}
