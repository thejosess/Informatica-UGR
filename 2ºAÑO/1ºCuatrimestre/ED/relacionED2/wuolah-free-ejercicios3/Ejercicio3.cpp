/*
	Construye una función a la que se le pase el nombre de un fichero y devuelva
	un map que contenga las palabras que aparecen y el número de veces que 
	aparece cada una.
*/
#include<iostream>
#include<fstream>
#include <string>
#include <map>

using namespace std;

typedef map<string, int> dicc_StringInt;

dicc_StringInt fichero(const string & nombre){

	dicc_StringInt ocurrencia;
	ifstream fi(nombre);
	string palabra;
	while(fi>>palabra)
		ocurrencia[palabra]++;

	fi.close();
	return ocurrencia;
}

int main(){

	auto diccionario = fichero("Ejercicio1.cpp");
	for (dicc_StringInt::const_iterator wiii = diccionario.cbegin(); wiii != diccionario.cend();++wiii)
		cout << wiii->first << '\t' << wiii->second << endl;

}
