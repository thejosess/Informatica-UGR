#ifndef TERMINO
#define TERMINO

#include <iostream>
using namespace std;

class Termino
{
private:

	string palabra;
	Vector_Dinamico<string> definiciones;

public:

	inline Termino(){ palabra = nullptr; };

	inline Termino(string palabra, Vector_Dinamico definiciones){ this.palabra = palabra; this.definiciones = definiciones; };

	inline Termino(const Termino & term){ this.palabra = term.palabra; this.definiciones = term.definiciones };

	inline string getPalabra() const { return palabra; };

	inline Vector_Dinamico<string> getDefiniciones() const { return definiciones; };

	inline int getNumDefiniciones() const { return definiciones.size(); };

	inline void setPalabra(string palabra){ this.palabra = palabra; };

	inline void setDefiniciones(Vector_Dinamico<string> definiciones){ this.definiciones = definiciones; };

	inline void setDefinicion(string definicion){ this.definiciones.addElemento(definicion); };

	istream& operator>>(istream& is, Termino& term);

	ostream& operator<<(ostream& os, const Termino& term);
}

#endif
