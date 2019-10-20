#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <math.h>


using namespace std;

/**
*@brief funcion que evalua una expresion en postfijo y te devuvel el resultado
*@author José Santos Salvador
*@param expresion que contiene la formula, vector de pair con las variables y su valor y el numero_variables
*@return el resultado de evaluar la expresión.
*/
template <typename T>
T evaluar(string expresion, pair<char, T> *variables, int num_variables)
{
	stack<T> pila ;
	T dc, iz ;
	bool encontrado = false ;

	for (int i=0; i < expresion.size(); ++i) 
	{
		encontrado = false;
		for(int j = 0 ; j < num_variables && !encontrado  ; j++)
		{
			if (expresion[i] == variables[j].first)
			{
				pila.push(variables[j].second);
				encontrado = true ;
			}
			if(expresion[i] == '+' || expresion[i] == '-' || expresion[i] == '*' || expresion[i] == '/' || expresion[i] == '^')
			{
				dc = pila.top(); 
				pila.pop();

				iz = pila.top(); 
				pila.pop();

				switch (expresion[i])
				{
					case '+': pila.push(iz+dc); break;
					case '-': pila.push(iz - dc); break;
					case '*': pila.push(iz*dc); break;
					case '/': pila.push(iz / dc); break;
					case '^': pila.push(pow(iz,dc)); break;
				}

				encontrado = true ;
			}
		}

	}
	return pila.top();
}

int main()
{

 cout << "*****************************************************************" << endl 
        << "Funcion evaluar postfijo" << endl
        << "*****************************************************************" << endl;

string expresion = "ab^c*d/e+" ;
string expresion2 = "abcde+*+-" ;
string expresion3 = "ab+cd*+e*" ;
int num_variables = 5;




cout <<"\nEvaluacion de la expresion 1 " << expresion << " resultado esperado = 134" << endl
    << "--------------------------------------------------------\n" << endl;

	pair<char,int> variables[num_variables];

	variables[0] = make_pair('a',5);
	variables[1] = make_pair('b',3);
	variables[2] = make_pair('c',2);
	variables[3] = make_pair('d',2);
	variables[4] = make_pair('e',9);

	// estoy mostrando el valor del pair esteticamente queda mejor pero no es neceseario para su funcionamiento
	for( int i = 0 ; i < num_variables ; i++)
	{
		cout << variables[i].first << " = " << variables[i].second  << endl ;
	}

	cout << "El resultado obtenido con la funcion " << evaluar(expresion, variables, num_variables) << "\n";


cout <<"\nEvaluacion de la expresion 2 " << expresion2 << " resultado esperado = -41 "<< endl
    << "--------------------------------------------------------\n" << endl;

	pair<char,int> variables2[num_variables];

	variables2[0] = make_pair('a',12);
	variables2[1] = make_pair('b',4);
	variables2[2] = make_pair('c',7);
	variables2[3] = make_pair('d',5);
	variables2[4] = make_pair('e',2);

	for(int i = 0 ; i < num_variables ; i++)
	{
		cout << variables2[i].first << " = " << variables2[i].second << endl ;
	}

	cout << "El resultado obtenido con la funcion " << evaluar(expresion2, variables2, num_variables) << "\n";

cout <<"\nEvaluacion de la expresion 3 " << expresion3 << " resultado esperado = 207 "<< endl
    << "--------------------------------------------------------\n" << endl;

	pair<char,int> variables3[num_variables];

	variables3[0] = make_pair('a',2);
	variables3[1] = make_pair('b',6);
	variables3[2] = make_pair('c',3);
	variables3[3] = make_pair('d',5);
	variables3[4] = make_pair('e',9);

	for(int  i = 0 ; i < num_variables ; i++)
	{
		cout << variables3[i].first << " = " << variables3[i].second  << endl ;
	}

	cout << "El resultado obtenido con la funcion " << evaluar(expresion3, variables3, num_variables)  << "\n" << endl;	
}