/*
	Construye una función a la que se le pasen los parámetros con los que se ha
	ejecutado un programa y determine qué opciones se han seleccionado y, en su
	caso, el valor que se la ha asignado. Por ejemplo: tar -z -x -f fichero 
	debería indicar que se han activado z,x y también f que tiene un parámetro 
	fichero.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

typedef map<string, string> dicc_StringString;

void parametros(string cadena,dicc_StringString & activados){
	istringstream linea(cadena);
	string palabra;
	string o_fichero;

	bool primera = true;
	bool opcion = false;

	while(linea>>palabra){
		if(primera)
			primera=false;
		else{
			if (palabra[0] == '-'){
				if (opcion)
					activados.insert({o_fichero,""});
				else
					opcion = true;
				o_fichero = palabra;
			}
			else {
				opcion = false;
				activados.insert({o_fichero, palabra});
			}
		}
	}

	if(palabra[0] == '-')
		activados.insert({palabra,""});
	
}

int main(){

	string cadena = "tar -z -x -f fichero -c directorio";
	dicc_StringString activados;

	parametros(cadena,activados);
	for(auto it = activados.begin(); it != activados.end(); ++it)
		cout << it->first << " " << it->second << endl;

}

