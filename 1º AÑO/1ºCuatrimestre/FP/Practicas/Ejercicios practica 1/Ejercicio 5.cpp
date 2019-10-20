// Ejercicio 5

#include <iostream>
using namespace std;

int main()
{
	// Descripccion del programa para facilitarle el entendimiento al usuario
	
	cout << "  x vale 10 , y vale 20 y z vale 30  " << endl ;
	cout << " Este programa declara las variables x, y y z y les intercambia los valores entre si , siendo el valor x que pasa a y , el de y pasa z y el valor z pasa a x" << endl ;
	
      
      // Nucleo del programa y declaracion de variables 
      
	   int x = 10 ;   int y = 20;  int z = 30; int temporal; int temporal2;
		
		temporal = x ;
		temporal2 = y ;
		
		x = y;
		y = temporal ;
		z = temporal2 ;
	
	   //Resultado del programa
	   
			cout << "El valor de x es : " << x << endl ;
		   cout << "El valor de y es : " << y << endl ;
			cout << "El valor de z es : " << z << endl ;

}
