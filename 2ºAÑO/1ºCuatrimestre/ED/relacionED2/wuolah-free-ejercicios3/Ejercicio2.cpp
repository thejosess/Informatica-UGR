/*
	Implementa una función desencripta que haga el proceso inverso al del 
	ejercicio anterior.
*/
#include<iostream>
#include <string>
#include <map>

using namespace std;

typedef map<char, char> dicc_CharChar;

string desencripta(string cadena,const dicc_CharChar & codigo){

	dicc_CharChar desencriptador;
	for (dicc_CharChar::const_iterator wiii = codigo.cbegin(); wiii != codigo.cend();++wiii)
		desencriptador.insert({wiii->second,wiii->first});

	for(unsigned i = 0; i < cadena.size();++i){
		auto we = desencriptador.find(cadena[i]);
		if(we != desencriptador.end())		
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
	
	string cadena = "Voy a Aprobar";

	cout << desencripta(cadena,encriptador);

	cout << endl << endl;

}
