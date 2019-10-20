//Ejercicio 6

#include <iostream>

using namespace std;
	
int main ()

{
		//Entrada
	
	int numero_1 , numero_2 , numero_3 ;
	
	cout << "Introducir termino a : " ;
	
	cin >> numero_1 ;
	
	cout << "Introducir termino b  : " ;
	
	cin >> numero_2 ;
	
	cout << "Introducir termino c : " ;
	
	cin >> numero_3 ;
	
	//Proceso
	
	
	if ( ( numero_1 * numero_1 ) + ( numero_2 * numero_2 ) == numero_3 * numero_3 )
	
		cout << " Es un triple de Pitágoras" << endl;
		
	else
	
		cout << "No es un triple Pitágoras" << endl;

}
