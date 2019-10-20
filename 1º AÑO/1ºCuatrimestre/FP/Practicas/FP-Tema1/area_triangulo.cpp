/*
  Este programa solicita las longitudes de la base y la altura de un triangulo
  y calcula su area.
*/

#include <iostream>
using namespace std;

int main()
{
   double base, altura, area;

   // Entradas
   cout << "Introduzca la longitud de la base: ";
   cin >> base;

   cout << "Introduzca la longitud de la altura: ";
   cin >> altura;

   // Proceso
   area = (base * altura) / 2;

   // Salida
   cout << "\n\nEl area del triangulo es " << area  <<  endl;
}
