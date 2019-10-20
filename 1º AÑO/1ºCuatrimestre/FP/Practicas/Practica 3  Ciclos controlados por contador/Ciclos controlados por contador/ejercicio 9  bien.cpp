#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int i , cociente , ultimo_dato;
	
	cout << "Introducir entero: ";
	cin >> cociente ;
	
	while( cociente > 0 ){
		
		ultimo_dato = cociente % 10 ;
		
		cociente = cociente / 10 ;
		
		cout << ultimo_dato << endl;
		
		
		
	}
	
	
	
}
