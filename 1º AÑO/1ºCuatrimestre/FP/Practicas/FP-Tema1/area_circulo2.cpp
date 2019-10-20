/*
    Este programa solicita el radio de un circulo y calcula su area usando una
    constante llamada PI
*/

#include <iostream>
using namespace std;

int main()
{
   const double PI = 3.1415926535;
   double radio, area;

   //ENTRADA
   cout << "Este programa calcula el area de un circulo." << endl;
   cout << "Introduzca el radio: ";
   cin >> radio;

   //PROCESO
   area = PI * radio * radio;

   //SALIDA
   cout << "El area del circulo es: " << area << endl;
}
