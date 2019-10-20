/*
	Construye una función que dado el map del ejercicio anterior devuelva un 
	multimap que nos permita consultar las palabras que aparecen un número 
	determinado de veces.
*/	

#include<iostream>
#include<fstream>
#include <string>
#include <map>

using namespace std;

typedef multimap<int, string> dicc_IntString;
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

dicc_IntString fichero_ocurrencia(dicc_StringInt & diccionario){
	dicc_IntString veces;
	for (auto wiii = diccionario.cbegin(); wiii != diccionario.cend();++wiii)
		veces.insert({wiii->second,wiii->first});

 return veces;
}

int main(){

	auto diccionario = fichero("Ejercicio1.cpp");
	auto diccionario_ocurrencia = fichero_ocurrencia(diccionario);
	for (auto wiii = diccionario_ocurrencia.cbegin(); 
									wiii != diccionario_ocurrencia.cend();++wiii)
		cout << wiii->first << '\t' << wiii->second << endl;

}
