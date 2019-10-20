
//Ejercicio 7

#include <iostream>

using namespace std;

int main()

{
	
	//Entradas 
	
	bool esPar_1 , esPar_2 , esPar_3 , esPar_4 ;
	
	int numero_1 , numero_2 , numero_3 , numero_4 ;
	
	cout << "Introducir entero 1 distinto de cero : " ;
	
	cin >> numero_1 ;
	
	cout << "Introducir entero 2 distinto de cero   : " ;
	
	cin >> numero_2 ;
	
	cout << "Introducir entero 3 distinto de cero  : " ;
	
	cin >> numero_3 ;
	
	cout << "Introducir entero 4 distinto de cero  : " ;
	
	cin >> numero_4 ;
	
	
	//Proceso : determinacion de los numeros pares
	
	if ( numero_1 % 2 == 0 ) 
	
		esPar_1 = true ;
		
	   else 
	   
	   	esPar_1 = false;
		
	if ( numero_2 % 2 == 0 )
		
		esPar_2 = true ;
		
		else 
	   
	   	esPar_2 = false;
		
	if ( numero_3 % 2 == 0 ) 
	
		esPar_3 = true ;	
		
		else 
	   
	   	esPar_3 = false;
		
	if ( numero_4 % 2 == 0 )
		
		esPar_4 = true ;
		
		else 
	   
	   	esPar_4 = false;
		
		
	// Proceso : determinacion de el mayor par	
	
		if( esPar_1 && esPar_2 && esPar_3 && esPar_4 )
	
			if ( numero_1 > numero_2 > numero_3 > numero_4 )
			
				cout << "El mayor de los pares es : " << numero_1 << endl;
			
			if ( numero_2 > numero_1 > numero_3 > numero_4 )
		
				cout << "El mayor de los pares es : " << numero_2 << endl;
				
			if ( numero_3 > numero_1 > numero_2 > numero_4 )
		
				cout << "El mayor de los pares es : " << numero_3 << endl;
			
			if ( numero_4 > numero_1 > numero_2 > numero_3)
				
				cout << "El mayor de los pares es : " << numero_4 << endl;
				
		else
				
			if( esPar_1 && esPar_2 && esPar_3 )
		
				if ( numero_1 > numero_2 > numero_3 )
				
					cout << "El mayor de los pares es : " << numero_1 << endl;
				
				if ( numero_2 > numero_1 > numero_3 )
			
					cout << "El mayor de los pares es : " << numero_2 << endl;
					
				if ( numero_3 > numero_1 > numero_2 )
			
					cout << "El mayor de los pares es : " << numero_3 << endl;
			
			else
			
			   if( esPar_1 && esPar_2 && esPar_4 )
		
				if ( numero_1 > numero_2 > numero_4 )
				
					cout << "El mayor de los pares es : " << numero_1 << endl;
				
				if ( numero_2 > numero_1 > numero_4 )
			
					cout << "El mayor de los pares es : " << numero_2 << endl;
					
				if ( numero_4 > numero_1 > numero_2 )
			
					cout << "El mayor de los pares es : " << numero_4 << endl;
					
			else
					
			if( esPar_4 && esPar_2 && esPar_3 )
		
				if ( numero_4 > numero_2 > numero_3 )
				
					cout << "El mayor de los pares es : " << numero_4 << endl;
				
				if ( numero_2 > numero_4 > numero_3 )
			
					cout << "El mayor de los pares es : " << numero_2 << endl;
					
				if ( numero_3 > numero_4 > numero_2 )
			
					cout << "El mayor de los pares es : " << numero_3 << endl;
			
			else
				
				if( esPar_1 && esPar_2 )
	
				if ( numero_1 < numero_2)
					
					cout << "El mayor de los pares es : " << numero_2 << endl;
				else
				
					cout << "El mayor de los pares es : " << numero_1 << endl;
				
				if( esPar_1 && esPar_3 )
			
					if ( numero_1 < numero_3)
					
						cout << "El mayor de los pares es : " << numero_3 << endl;
					
					else
				
						cout << "El mayor de los pares es : " << numero_1 << endl;	
					
				if( esPar_1 && esPar_4 )
			
					if ( numero_1 < numero_4)
					
						cout << "El mayor de los pares es : " << numero_4 << endl;
					
					else
				
						cout << "El mayor de los pares es : " << numero_1 << endl;
						
				else
							
					if( esPar_1)
						
						cout << "el Par mayor es : " << numero_1 << endl;
						
					if( esPar_2)
						
						cout << "el Par mayor es : " << numero_2 << endl;
						
					if( esPar_3)
						
						cout << "el Par mayor es : " << numero_3 << endl;
					
					if( esPar_4)
						
						cout << "el Par mayor es : " << numero_4 << endl;
		
		
		
	// Salida: Especificacion de no introducir ningun par
	
	if ( esPar_1 == false && esPar_2 == false && esPar_3 == false && esPar_4 == false )
		
		cout <<"No has introducido ningún par " << endl;
		
}
			
		

