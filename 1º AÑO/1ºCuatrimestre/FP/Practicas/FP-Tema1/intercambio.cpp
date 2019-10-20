/* Archivo: intercambio.cpp
  Autor: Manuel Lozano
  Ultima modificacion: 02/10/2006
  ------------------------------------------------
  Este programa realiza el cambio de contenido entre
  dos variables.
*/

#include <iostream>
using namespace std;

int main()
{
   double x, y, tmp;

   //ENTRADAS
   cout << "Introducir el valor de x: ";
   cin >> x;

   cout << "Introducir el valor de y: ";
   cin >> y;

   //PROCESO
   tmp = x;
   x = y;
   y = tmp;

   //SALIDA
   cout << "x: " << x << " y: " << y << endl;
}
