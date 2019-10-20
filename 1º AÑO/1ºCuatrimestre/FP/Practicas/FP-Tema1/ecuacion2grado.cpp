/* Programa que calcula las ra�ces de una ecuaci�n
   de segundo grado

      Entradas: Los par�metros de la ecuaci�n
      Salidas: Las ra�ces de la par�bola
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   double a, b, c; // Par�metros de la ecuaci�n
   double r1, r2;  // Ra�ces obtenidas

   //ENTRADAS
   cout << "\nIntroduce coeficiente de 2o grado: ";
   cin >> a;

   cout << "\nIntroduce coeficiente de 1er grado: ";
   cin >> b;

   cout << "\nIntroduce coeficiente independiente: ";
   cin >> c;

   //PROCESO
   r1 = ( -b + sqrt( b*b-4*a*c ) ) / (2*a);
   r2 = ( -b - sqrt( b*b-4*a*c ) ) / (2*a);

   //SALIDA
   cout << "Las ra�ces son: " << r1 << " y " << r2 << endl;
}
