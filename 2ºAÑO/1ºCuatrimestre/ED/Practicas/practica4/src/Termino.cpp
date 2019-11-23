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
		os << term.getPalabra() <<";" << term.getDefiniciones()[i] << "\n" << endl ;
	}

	return os;
}

void Termino::setDefinicion(string definicion)
{
        if(this->getNumDefiniciones() != 0)
            termino.second.clear();
        
        termino.second.push_back(definicion);
}

bool Termino::operator<(const Termino &term)const //para ordenar el set
{
	return this->termino.first < term.termino.first ;
}

bool Termino::operator!=(const Termino &term)const
{
	return term.termino.first != this->termino.first ;
}

/*bool Termino::operator/()
{
	return this->termino.first != nullptr;
}*/

