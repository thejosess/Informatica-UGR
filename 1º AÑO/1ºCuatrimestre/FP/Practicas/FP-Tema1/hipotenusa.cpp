/*
  Este programa solicita las longitudes de los lados de un triangulo y calcula
  su hipotenusa.
*/

#include <iostream>
#include <cmath>  //¡Es necesaria para utilizar sqrt!
using namespace std;

int main()
{
   double lado1, lado2, hipotenusa;

   //ENTRADAS
   cout << "Introduzca la longitud del lado 1: ";
   cin >> lado1;

   cout << "Introduzca la longitud del lado 2: ";
   cin >> lado2;

   //PROCESO
   hipotenusa = sqrt(lado1*lado1+lado2*lado2);

   //SALIDA
   cout << "La hiponusa es " << hipotenusa << endl;
}
