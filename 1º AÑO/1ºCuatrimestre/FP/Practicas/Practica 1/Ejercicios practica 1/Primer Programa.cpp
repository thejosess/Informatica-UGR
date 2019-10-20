     #include <iostream>
     using namespace std;
	int main ()
{
	int variable1, variable2, variable3, suma, resta;
	
		cout << "Introducir primer dato: " ;
		cin >> variable1;
		
		cout << "Introducir segundo dato: " ;
		cin >> variable2 ;
		
		cout<< "Introducir tercer dato: " ;
		cin>> variable3 ;
	
	suma = variable1 + 2*variable2;
	cout << "La suma del 1 y del doble del segundo: " << suma <<endl;
	resta = suma - 3*variable3 ;
	cout << "La suma menos el triple del tercero: " << resta << endl;
}
