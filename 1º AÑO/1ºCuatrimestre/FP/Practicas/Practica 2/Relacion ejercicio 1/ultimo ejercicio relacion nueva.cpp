//Ejercicio 8

#include <iostream>

using namespace std;

#include <string>

int main ()

{
	
   string cad , cad_1 ;
   
   cout << "Introducir nombre y apellidos: ";
   
   getline(cin, cad);
      
   
   
   
   cout << "Introducir nombre y apellidos: ";
   
   getline(cin, cad_1) ;
   
  
   
	if ( cad_1 > cad ) 
		cout << cad_1 << " " << cad << endl ;
   
	else
		cout << cad << " " << cad_1 <<endl ;
   	
}

