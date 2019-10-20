#include <iostream>
#include <string>
#include <queue>
#include <stack>


using namespace std;

/**
* @brief función que comprueba si un string es un palindromo
* @param string a comprobar
* @pre el string ha de estar escrito sin tildes y sin espacios
* @author Jose Santos Salvador
*/


bool palindromo(string cad)
{
	stack<char> pila;
	queue<char> cola;		
	bool palindromo = true ;

	for(size_t i = 0 ; i < cad.size() ; i++)
	{
		pila.push(cad[i]) ;
		cola.push(cad[i]) ;
	}

	while( !pila.empty() && palindromo )
	{
		if( !(tolower(cola.front()) == tolower(pila.top()) ) )
			palindromo = false ;

		pila.pop() ;
		cola.pop() ;	
	}
	return palindromo ;
}

int main()
{

	string cad = "ana" ;
	string cad1 = "Ana" ;
	string cad2 = " Jose" ;
	string cad3 = "AcavaraCaravaca" ;

	bool correcto ;
	correcto = palindromo(cad) ;

	cout <<"\nPrueba con ana" << endl
    << "--------------------------------------------------------" << endl;

	if(correcto)
		cout<<"El string es un palindromo" << endl;
	else
		cout<<"El string no es una palindromo" << endl ;

	cout <<"\nPrueba con Ana" << endl
    << "--------------------------------------------------------" << endl;

	correcto ;
	correcto = palindromo(cad1) ;

	if(correcto)
		cout<<"El string es un palindromo" << endl;
	else
		cout<<"El string no es una palindromo" << endl ;

	cout <<"\nPrueba con Jose" << endl
    << "--------------------------------------------------------" << endl;

	correcto ;
	correcto = palindromo(cad2) ;

	if(correcto)
		cout<<"El string es un palindromo" << endl;
	else
		cout<<"El string no es una palindromo" << endl ;

	cout <<"\nA cavar a Caravaca" << endl
    << "--------------------------------------------------------" << endl;

	correcto ;
	correcto = palindromo(cad3) ;

	if(correcto)
		cout<<"El string es un palindromo" << endl;
	else
		cout<<"El string no es una palindromo" << endl ;




}