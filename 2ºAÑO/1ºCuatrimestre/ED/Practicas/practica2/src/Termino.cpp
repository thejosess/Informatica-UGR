#include "Termino.h"

bool Termino::operator==(const Termino& termino)
{
    return this->getPalabra() == termino.getPalabra();
}

istream& operator>>(istream& is, Termino& term)
{
	string def, palabrita;

	getline(is, palabrita, ';');
	getline(is, def, '\n');
        
	term.setDefinicion(def);
        
        term.setPalabra(palabrita);
        
	return is;
}

ostream& operator<<(ostream& os, const Termino& term)
{

	int aux = term.getNumDefiniciones();

	for(int i = 0 ; i < aux ; i++)
	{
		os << term.palabra <<";" << term.definiciones[i] << "\n" << endl ;
	}

	return os;
}

void Termino :: setDefinicion(string definicion){
	this->definiciones.resize(1);
	this->definiciones[0] = definicion;

}

void Termino::addDefinicion(string definicionNueva){
	definiciones.resize(getNumDefiniciones()+1);
	definiciones[getNumDefiniciones()-1] = definicionNueva;
}
