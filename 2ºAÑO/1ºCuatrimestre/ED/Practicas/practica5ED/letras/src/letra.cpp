#include "letra.h"

bool letra::operator<(const letra &D) const
{
	if(this->puntuacion == D.puntuacion)
		return this->caracter < D.caracter;
	else
		return this->puntuacion < D.puntuacion;
}

ostream & operator<<(ostream & os, const letra &D)
{
	os << D.caracter << '\t' << D.veces << '\t' << D.puntuacion;

	return os;
}

istream & operator>>(istream & is, letra &D)
{
  string aux;

  getline(is, aux, '\t');

  D.caracter = aux[0];;

  getline(is, aux, '\t');

  D.veces = atoi(aux.c_str());

  getline(is, aux, '\n');

  D.puntuacion = atoi(aux.c_str());

  return is;
}