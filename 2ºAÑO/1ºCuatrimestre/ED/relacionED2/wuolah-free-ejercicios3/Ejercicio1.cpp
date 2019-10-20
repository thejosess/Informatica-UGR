/*
	Un método de encriptación basado en un código consiste en transformar cada 
	letra del alfabeto por otra. Implementa una función encripta a la que se le 
	pasa una cadena de caracteres y un map<char,char> con el código y que 
	devuelva la cadena encriptada.
*/
#include<iostream>
#include <string>
#include <map>

using namespace std;

typedef map<char, char> dicc_CharChar;

string encripta(string cadena,const dicc_CharChar & codigo){

	for(unsigned i = 0; i < cadena.size();++i){
		auto we = codigo.find(cadena[i]);
		if(we != codigo.end())		
			cadena[i] = we->second;
	}
 return cadena;
}

int main(){
	dicc_CharChar encriptador;

	for (char i='a'; i< 'z';++i)
		encriptador.insert({i,i+1});
	encriptador.insert({'z','a'});

	for (char i='A'; i< 'Z';++i)
		encriptador.insert({i,i+1});
	encriptador.insert({'Z','A'});
	
	string cadena = "Unx z Zoqnazq";

	cout << encripta(cadena,encriptador);

	cout << endl << endl;

}
