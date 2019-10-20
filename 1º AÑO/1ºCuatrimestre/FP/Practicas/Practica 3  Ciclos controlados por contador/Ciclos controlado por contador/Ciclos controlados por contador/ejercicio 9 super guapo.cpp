#include <iostream>
#include <string>
using namespace std;

int main (){
	
	string numero ;
	int contador ;
	
	cout << "Introduce un numero , 0 para terminar\n" ;
	cin >> contador ;
	
	while ( numero != "0")
	{
		
		for ( int i = 0 ; i < numero.length() ; i++ )
		
		cout << numero[i] << " " ;
		cout << endl;
		
		
		cout << "Introducimos un numero , 0 para terminar \n" ;
		cin >>  numero ;
		
		
	}
	
	
}
