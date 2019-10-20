//Ejercicio 1
#include <iostream>
using namespace std;

int main()
{
	double intensidad, resistencia, voltaje;
	
	cout << "Introducir intensidad: ";
	cin >> intensidad;
	cout << "Introducir resistencia: ";
	cin >> resistencia;
	
	voltaje = intensidad*resistencia;
	cout << "El resultado de la ley de Ohm es: " <<voltaje << endl;
}
