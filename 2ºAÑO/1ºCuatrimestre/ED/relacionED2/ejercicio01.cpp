#include <iostream>
#include <map>
#include <string>

using namespace std;

/**
* @brief función que encripta una frase
* @param la cadena y el codigo mediante un map
* @author Jose Santos Salvador
*/

typedef map<char, char> encriptacion;
string encripta(string cad, const encriptacion &codigo)
{
	string aux;

	for(int i = 0; i < cad.size() ; i++)
	{
		if(codigo.find(cad[i]) != codigo.end())
			aux += codigo.find(cad[i])->second;
	}
	return aux;
}

int main()
{
	map<char,char> codigo;

	for(int i = 97; i <= 122 ; i++)
	{
		codigo[i] = i + 5;
		codigo[i -32] = (i - 32)+ 5;
	}

	string cad = "abcd" ;
	string aux;

	aux = encripta(cad, codigo);
	cout << aux << endl;
}