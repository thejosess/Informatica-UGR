#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

/**
* @brief función que cuenta las veces que sale un string en un fichero
* @param el string con el nombre del fichero para abrir
* @author Jose Santos Salvador
*/

typedef map<string, int> contador;
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

		//map.insert(map.begin(),map.find(aux));

		/*for(i = map.begin() ; i != map.end(); i++)
		{
			if(aux == i->first)
				i->second = i->second + 1;
			else
				map[i->first] = i->second ;
		}*/
	}
	entrada.close();
	return map;
}


int main()
{
	string nom_fich="prueba.txt", aux;
	contador map;

	/*cout << "Cual es el nombre del fichero para contar las palabras" <<endl;
	cin >> nom_fich;*/

	map = contar(nom_fich);
	contador::iterator i;

	for(i = map.begin() ; i != map.end(); i++)
	{
		cout << "La palabra: " << i->first << " aparece " << i ->second << endl;
	}
}