/* Programa que calcula las raíces de una ecuación
   de segundo grado

      Entradas: Los parámetros de la ecuación
      Salidas: Las raíces de la parábola
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   double a, b, c; // Parámetros de la ecuación
   double r1, r2;  // Raíces obtenidas

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
   cout << "Las raíces son: " << r1 << " y " << r2 << endl;
}
