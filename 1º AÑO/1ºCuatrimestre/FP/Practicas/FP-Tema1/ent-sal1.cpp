#include <iostream>
using namespace std;

int main()
{
   int valor;
   double resultado;
   char caracter;

    //ENTRADAS
    cout << "Introduce un valor entero: ";
    cin >> valor;

    cout << "Y ahora un valor real: ";
    cin >> resultado;

    cout << "Y finalmente un caracter: ";
    cin >> caracter;

    //SALIDAS
    cout << "El primer numero era: "<< valor << endl;
    cout << "El segundo numero era: "<< resultado << endl;
    cout << "El caracter era: " << caracter << endl;
}

