#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main(){
	
    string numero;
    int contador;

    cout << "Introduzca un numero, 0 para terminar\n";
    cin >> numero;

    while( numero != "0" )
	{
        for ( int i = 0; i < numero.length(); i++)
        
        cout << numero[i] << " ";
        cout << endl;

        cout << "Introduzca un numero, 0 para terminar\n";
        cin >> numero;
    }
}
