#include <iostream>
#include <string>
#include <stack>

using namespace std;

/**
* @brief función que comprueba si un string tiene los parentesis correctos
* @param string a comprobar
* @author Jose Santos Salvador
*/
bool parentesis_correctos(string expresion)
{		

	stack <char> aux ;
	bool correcto;
	char parentesis1 = '(' ;
	char parentesis2 = ')' ;

	for( int i = 0 ; i < expresion.size() ; i++)
	{
		if(expresion[i] == parentesis1)
		{
			aux.push(expresion[i]) ;
		}
		else if (expresion[i] ==  parentesis2)
		{
				if(!aux.empty())
					aux.pop() ;	
				else
					return false ;				
		}
	}

	if(aux.empty())
		correcto = true ;
	else
		correcto = false ;

	return correcto ;
}

int main()
{
	string prueba1 = "h(ol(a)hg)ghg(" ;
	string prueba2 = "h(ol(a)hg)ghg" ;
	string prueba3 = "h(o(" ;
	string prueba4 = "h(ol(a)(" ;
	string prueba5 = ")ghg(" ;
	string prueba6 = "(hola(adios))";

	bool correcto = parentesis_correctos(prueba1) ;

	cout <<"\nExpresion 1 = "<< prueba1 << endl
    << "--------------------------------------------------------\n" << endl;

	if(correcto)
		cout << "Los parentesis son correctos" << endl;
	else
		cout << "Los parentesis son incorrectos" << endl;

	correcto = parentesis_correctos(prueba2) ;

	cout <<"\nExpresion 2 = "<< prueba2 << endl
    << "--------------------------------------------------------\n" << endl;

	if(correcto)
		cout << "Los parentesis son correctos" << endl;
	else
		cout << "Los parentesis son incorrectos" << endl;

	correcto = parentesis_correctos(prueba3) ;

	cout <<"\nExpresion 3 = " << prueba3 << endl
    << "--------------------------------------------------------\n" << endl;

	if(correcto)
		cout << "Los parentesis son correctos" << endl;
	else
		cout << "Los parentesis son incorrectos" << endl;

	correcto = parentesis_correctos(prueba4) ;

	cout <<"\nExpresion 4 = " << prueba4 <<  endl
    << "--------------------------------------------------------\n" << endl;	

	if(correcto)
		cout << "Los parentesis son correctos" << endl;
	else
		cout << "Los parentesis son incorrectos" << endl;

	correcto = parentesis_correctos(prueba5) ;

	cout <<"\nExpresion 5 = " << prueba5 << endl
    << "--------------------------------------------------------\n" << endl;

	if(correcto)
		cout << "Los parentesis son correctos" << endl;
	else
		cout << "Los parentesis son incorrectos" << endl;	

	correcto = parentesis_correctos(prueba6) ;

	cout <<"\nExpresion 6 = " << prueba6 << endl
    << "--------------------------------------------------------\n" << endl;

	if(correcto)
		cout << "Los parentesis son correctos\n" << endl;
	else
		cout << "Los parentesis son incorrectos\n" << endl;		


}