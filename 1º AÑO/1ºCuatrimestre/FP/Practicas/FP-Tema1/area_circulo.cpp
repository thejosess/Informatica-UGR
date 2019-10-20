/*
        Este programa solicita el radio de un circulo y calcula su area.
*/

#include <iostream>
using namespace std;

int main()
{
   double radio, area;

   //ENTRADA
   cout << "Introduzca el radio: ";
   cin >> radio;

   //PROCESO
   area = 3.14159 * radio * radio;

   //SALIDA
   cout << "El area del circulo es: " << area << endl;
}
