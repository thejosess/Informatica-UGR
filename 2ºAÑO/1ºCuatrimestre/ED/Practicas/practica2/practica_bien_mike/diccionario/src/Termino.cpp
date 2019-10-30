#include "Termino.h"

/*********************************************************************************/
//Constructores

Termino::Termino(){}

Termino::Termino(string palabra, Vector_Dinamico<string> definicion){
	this->palabra = palabra;
	this->definiciones = definicion;
}

Termino::Termino(const Termino & original){
	this->palabra = original.palabra;
	this->definiciones = original.definiciones;
}

/********************************************************************************/
//Consultores

string Termino::getPalabra() const{
	return palabra;
}

Vector_Dinamico<string> Termino::getDefiniciones() const{
	return definiciones;
}

int Termino::getNumeroDefiniciones() const{
	return definiciones.size();
}

/*********************************************************************************/
//Metodos Interfaz

void Termino::setPalabra(string nuevaPalabra){
	palabra = nuevaPalabra;
}

void Termino::setDefinicion(string definicion){
	this->definiciones.resize(1);
	this->definiciones[0] = definicion;
}

void Termino::addDefinicion(string definicionNueva){
	definiciones.resize(getNumeroDefiniciones()+1);
	definiciones[getNumeroDefiniciones()-1] = definicionNueva;
}

Termino& Termino::operator=(const Termino &original){
	this->palabra = original.palabra;
	this->definiciones = original.definiciones;
	return *this;
}

/*********************************************************************************/
//Metodos Flujos

istream& operator>>(istream& is, Termino& termino)
{
	if(!is.eof()){
		string cad_palabra, cad_definicion;

		getline(is, cad_palabra, ';');
		getline(is, cad_definicion);
		
		termino.setDefinicion(cad_definicion);
		
		termino.setPalabra(cad_palabra);
	}
        
	return is;
}

ostream& operator<<(ostream& os, const Termino& termino)
{
	os << termino.palabra << ":" << endl ;	
	for(int i = 0 ; i < termino.getNumeroDefiniciones() ; i++)
	{
		os << "\t" << i+1 << ": " << termino.definiciones[i] << endl;
	}

	return os;
}
