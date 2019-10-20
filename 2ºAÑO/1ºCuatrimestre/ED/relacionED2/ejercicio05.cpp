#include <iostream>
#include <map>
#include <string>

using namespace std;
typedef map<string,string> comando;


/**
* @brief función que devuelve un map con el comando que ha sido pasado con la ejecucion
* @param la cadena de string a la que tienes que sacar los parametros y opcciones de ejecucion
* @pre el string cad ha de ser pasado con la sintaxis correcta
* @author Jose Santos Salvador
*/

comando params(string cad)
{
	comando map;
	string c1,c2,c3;

	size_t en = cad.find('-');

	while(en != string::npos)
	{
		string aux;
		if(cad[en+3] != '-')
		{
			size_t i = en + 3 ;
			while(cad[i] != ' ')
			{
				aux+=cad[i];
				i++;
			}
			c1 = cad[en+1];
			c2 = aux;
			map.insert(pair<string,string>(c1,c2));
		}
		else
		{
			c3 = cad[en+1];
			map.insert(pair<string,string>(c3,"no parametro"));
			//es mejor dejando una etiqueta no parametro o '0' o directamente sin meterle nada			
		}
		en = cad.find('-', en+1) ;
	}
	return map;
}

int main(int argc, char *argv[])
{
	string aux;
	comando map;


	for(size_t i = 1; i < argc ; i++)
	{
		aux += argv[i];
		aux+= ' ';
	}

	map = params(aux);


	   cout << "\n*****************************************************************" << endl 
       		<< "COMANDO PASADO COMO ARGUMENTO" << endl
        	<< "*****************************************************************\n" << endl;

	for(comando::const_iterator i = map.begin() ;i != map.end() ; i++)
	{
		cout << "Primer argumento: " << i->first << " , segundo elemento del map: " << i->second << endl;
	}

	return 0;
}