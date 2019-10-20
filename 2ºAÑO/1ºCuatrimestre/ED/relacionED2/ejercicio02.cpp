#include <iostream>
#include <map>
#include <string>

using namespace std;

/**
* @brief función que desencripta una frase
* @param la cadena y el codigo mediante un map
* @author Jose Santos Salvador
*/

typedef map<char, char> encriptacion;
string desencripta(string cad, const encriptacion &codigo)
{
	encriptacion::const_iterator i;		
	encriptacion map;
	int j = 0;
	string aux;

	for(i = codigo.begin() ; i != codigo.end(); i++)
	{
		map.insert(pair<char,char>(i->second,i->first));
	}

	for(int i = 0; i < cad.size() ; i++)		//es el mismo codigo que encripta
	{
		if(map.find(cad[i]) != map.end())
			aux += map.find(cad[i])->second;
	}

	return aux;
}

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

	encriptacion codigo;

	for(int i = 97; i <= 122 ; i++)
	{
		codigo[i] = i + 5;
		codigo[i -32] = (i - 32)+ 5;
	}

	string cad = "abcd" ;
	string aux;

	aux = encripta(cad, codigo);
	cout << aux << endl;

	string cad1 = "fghi" ;
	string aux1;

	aux1 = desencripta(cad1, codigo);
	cout << aux1 << endl;
}