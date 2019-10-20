/*
          Este programa realiza el cambio de moneda de euros a pesetas.
*/

#include <iostream>
using namespace std;

int main() {
   double cantidad;

   //ENTRADAS
   cout << "Introduzca la cantidad que desea cambiar: ";
   cin >> cantidad;

   //SALIDA CON EL PROCESO INCORPORADO
   cout << cantidad << " euros son " << cantidad * 166.386 << " pesetas" << endl;

}
