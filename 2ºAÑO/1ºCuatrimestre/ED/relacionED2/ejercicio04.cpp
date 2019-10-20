#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;
typedef map<string, int> contador;

/**
* @brief función que devuelve un vector de string que solo aparecen un @num de veces
* @param el map con las palabras y el numero de veces que han de aparecer esas palabras
* @author Jose Santos Salvador
*/

vector<string> veces(const contador &palabras, int num)
{
	contador::const_iterador i;
	vector<string> aux ;

	for(i = palabras,begin(); i != palabras.end() ; i++)
	{
		if(num == i->second)
			aux.push_back(i->first);
	}
	return aux;
}

map<string,int> contar(string nom_fich)
{
	string aux ;
	contador::iterator i;	
	contador map;

	ifstream entrada;
	entrada.open(nom_fich);


	while(!entrada.eof() && entrada >> aux)
	{
		cout << "lectura " << aux << endl;

	  	pair<contador::iterator,bool> elemento;
	  	elemento = map.insert(contador::value_type(aux,1));

	  	if(elemento.second==false)
	  	{
	  		cout << elemento.first->second << endl;
	  		cout << elemento.first->first << endl;
	  		elemento.first->second+=1;
	  	}
	}
	entrada.close();
	return map;
}


int main()
{
	string nom_fich="prueba.txt", aux;
	contador map;
	vector<string> vector;
	int numero = 2 ;

	/*cout << "Cual es el nombre del fichero para contar las palabras" <<endl;
	cin >> nom_fich;*/

	map = contar(nom_fich);
	contador::iterator i;

	for(i = map.begin() ; i != map.end(); i++)
	{
		cout << "La palabra: " << i->first << " aparece " << i ->second << endl;
	}

	vector = veces(map,numero) ;

	for(i = 0 ; i < vector.size() ; i++)
	{
		cout << "Palabra que parece " << numero << " veces: " << vector[i] <<endl;
	}
}