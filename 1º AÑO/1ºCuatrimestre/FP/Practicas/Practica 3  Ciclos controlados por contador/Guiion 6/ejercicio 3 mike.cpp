#include <iostream>
using namespace std;
int main ()
{
 int multiplicando, multiplicador, i, resultado = 0;
 
 cout << "Introduce el multiplicando: ";
 cin >> multiplicando;
 
 cout << "Introduce el multiplicador: ";
 cin >> multiplicador;
 
 for ( i = 1; multiplicando != 0; i++ )
 {
  if ( multiplicando % 2 == 1)
   resultado = resultado + multiplicador;
  multiplicando = multiplicando / 2;
  multiplicador = multiplicador * 2;
 }
 cout << "El resultado es: " << resultado << endl;
}
