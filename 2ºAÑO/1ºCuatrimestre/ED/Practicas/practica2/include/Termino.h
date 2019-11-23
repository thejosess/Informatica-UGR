#ifndef TERMINO
#define TERMINO

#include <iostream>
#include <fstream>
#include "Vector_Dinamico.h"

using namespace std;

class Termino
{
private:

	string palabra;
	Vector_Dinamico<string> definiciones;

public:

        /**
         * @brief Constructor por defecto 
         */
	inline Termino(){ definiciones.resize(0); };

        /**
         * @brief Constructor con parametros
         * @param palabra le pasas una palabra como parametro para construir un Termino
         * @param definiciones le pasas unas definiciones como parametro para construir un Termino
         */
	inline Termino(string palabra, Vector_Dinamico<string> definiciones){ this->palabra = palabra; this->definiciones = definiciones; };
        
        /**
         * @brief Constructor con un parametro termino
         * @param term termino pasado para construir un Termino
         */
	inline Termino(const Termino & term){ this->palabra = term.palabra; this->definiciones = term.definiciones; };
        
        /**
         * @brief Devuelve una palabra
         * @return palabra devuelves la palabra de Termino
         */
	inline string getPalabra() const { return palabra; };
        
        /**
         * @brief Devuelve las definiciones
         * @return definiciones devuelves las definiciones asociadas de Termino
         */
	inline Vector_Dinamico<string> getDefiniciones() const { return this->definiciones; };
        
        /**
         * @brief Devuelve el numero de definiciones    
         * @return definiciones.size() devuelves el tamaño de las definiciones de termino
         */
	inline int getNumDefiniciones() const { return definiciones.size(); };
        
        /**
         * @brief Asigna una palabra pasada por parametro a palabra
         * @param palabra se le pasa una palabra que asgina a palabra
         */
	inline void setPalabra(string palabra){ this->palabra = palabra; };
        
        /**
         * @brief Aisgna definiciones pasadas por parametro a las definiciones
         * @param definiciones que se le asigna a definiciones
         */
	inline void setDefiniciones(Vector_Dinamico<string> definiciones){ this->definiciones = definiciones; };
        
	void addDefinicion(string definicionNueva);

        /**
         * @brief Asignacion de una definicion pasada por parametro a la definicion
         * @param definicion que se le asigna a definicion 
         */
	//inline void setDefinicion(string definicion){ this->definiciones.addElemento(definicion); };
        void setDefinicion(string definicion);
        /**
         * @brief Sobrecarga del operador de igualdad
         * @return @true si son iguales los terminos @false si son distintos
         */
        bool operator==(const Termino& termino);
        
        /**
         * @brief Sobrecarga del operador >> 
         * @return devuelve el operador de flujo de entrada
         */
	friend istream& operator>>(istream& is, Termino& term);
        
       /**
         * @brief Sobrecarga del operador de entrada
         * @return devuelve el operador de flujo de entrada
         */
	friend ostream& operator<<(ostream& os, const Termino& term);
};

#endif
