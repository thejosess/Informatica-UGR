//  Ejercicio 6

#include <iostream>
using namespace std;

int main ()
{
	int horas , minutos , segundos , resto1 , resto2 , resultado1, resultado2;
	
		cout << "Introducir horas : " ;
		cin >> horas ;
		
		cout << "Introducir minutos : " ;
		cin >> minutos ;
		
		cout << "Introducir segundos : " ;
		cin >> segundos ;
	
			resto1 = segundos / 60 ;
			
			segundos = segundos % 60 ;
		   resultado1 = 	resto1 + minutos ;
			
			resto2 = resultado1 / 60 ;
			
			resultado2 = resto2 + horas ;
			
			minutos = resultado1 % 60 ;
	
				cout << "Horas : " << resultado2 << endl ;
				cout << "Minutos : " << minutos << endl ;
				cout << "Segundos : " << segundos << endl ;
	
}
