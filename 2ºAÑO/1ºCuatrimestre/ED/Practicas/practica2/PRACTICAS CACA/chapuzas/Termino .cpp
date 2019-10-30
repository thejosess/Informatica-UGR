#include "Termino.h"

bool Termino::cargarDeFichero(const char* fichero)
{
	ifstream fentrada;
	fentrada.open(fichero);
	if(fentrada)
	{
		fentrada >> palabra;
	}
}

istream& Termino::operator>>(istream& is, Termino& term)
{
	string def;

	is.getline(term.palabra, 100, ';');
	is.getline(def, 256, '\n');
	term.setDefinicion(def);

	return is;
}

ostream& Termino::operator<<(ostream& os, const Termino& term)
{

	int aux = term.getNumDefiniciones();

	for(int i = 0 ; i < aux ; i++)
	{
		os << term.palabra <<";" << term.definiciones[i] << "\n" << endl ;
	}

	return os;
}