#ifndef DICCIONARIO
#define DICCIONARIO

#include "Termino.h"

class Diccionario
{
private:

	Vector_Dinamico<Termino> terminos;

public:

	inline Diccionario(){ terminos = new Vector_Dinamico<Termino>(0); };

	inline Diccionario(const Vector_Dinamico & terminos){ this.terminos = terminos; };

	inline Diccionario(const Diccionario & dicc){ this.terminos = dicc.terminos; };

	inline Vector_Dinamico<Termino> getTerminos() const { return terminos; };

	Vector_Dinamico<string> getDefiniciones(string palabra) const;

	inline int getNumTerminos() const { return terminos.size(); };

	void addTermino(Termino termino);

	inline void rmTermino(Termino termino){ this.terminos.rmElemento(termino); };

	inline void setDiccionario(Vector_Dinamico<Termino> terminos){ this.terminos = terminos };

	bool SalvarAFichero(const char* fichero) const;

	bool CargarDeFichero(const char* fichero);

	Diccionario FiltrarPorIntervalo(char inicio, char fin) const;

	int BuscarChar(char inicio) const;

	Diccionario FiltrarPorPalabra(string palabra) const;

 	void RecuentoDefiniciones(int & num_max, int & num_promedio, int & num_total) const;

 	istream& operator>>(istream& is, Diccionario& dicc);

	ostream& operator<<(ostream& os, const Diccionario& dicc);
}

#endif