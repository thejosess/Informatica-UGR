/**
  *  @file Termino.h
  *  @brief fichero de cabecera del TDA Termino
  */
#ifndef TERMINO
#define TERMINO

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/**
  *  @brief T.D.A. Termino
  *
  * Una instancia @e term del tipo de datos abstracto @c Termino es un objeto del tipo @c pair
  * compuesto por una palabra sobre el tipo @c string 
  * y su definición sobre el tipo @c vector de la stl. Lo representamos como;
  *
  * termino = <palabra,definiciones[i]>
  * siendo definiciones[i] las definiciones del termino y asociadas a dicha palabra
  *
  * Su uso puede verse en :
  * @include pruebadiccionario.cpp
  *
  * @author Raul Soria Gonzalez y José Santos Salvador
  * @date 5 de diciembre 2018
  */
class Termino
{
private:
/**
  * @page repTermino Rep del TDA Termino
  *
  * @section invTermino Invariante de la representación
  *
  * Un objeto @e term del TDA Termino debe cumplir
  *
  * -@c term.getNumDefiniciones >=0

  * -@c term.getPalabra tiene que ser de tipo string

  * -@c term.getDefiniciones tienen que ser vector<string>

  * -@c y los invariantes del pair, string y vector de la stl
  *
  * @section faTermino Función de abstracción
  *
  * Un objeto válido @e rep del TDA Termino representa al valor de tamaño @e n
  *
  * {term<palabra,string[1]...string[n-1]}
  * {term.first , term.second()[1],....term.second[n-1]}
  *
  */
pair<string, vector<string>> termino;    /**< palabra con sus definiciones */

public:

        /**
         * @brief Definicion del tipo iteraror para relacionar
         * el TDA termino con el tipo iterator de los tipos rep
         * subyascentes del vector de string de la STL
         */
    typedef vector<string>::iterator iterator;

        /**
         * @brief Definicion del tipo const_iteraror para relacionar
         * el TDA termino con el tipo const_iterator de los tipos rep
         * subyascentes del vector de string de la STL
         */
    typedef vector<string>::const_iterator const_iterator;

        /**
         * @brief Devuelve el iterator begin del vector<string> de la STL
         * @return iterator begin de vector de string de la STL
         */
    inline Termino::iterator begin(){return termino.second.begin();};
    
        /**
         * @brief Devuelve el const_iterator cbegin del vector<string> de la STL
         * @return const_iterator cbegin de vector de string de la STL
         */
    inline Termino::const_iterator begin()const {return termino.second.cbegin();} ;

        /**
         * @brief Devuelve el iterator end del vector<string> de la STL
         * @return iterator end de vector de string de la STL
         */
    inline Termino::iterator end(){return termino.second.end();};

        /**
         * @brief Devuelve el const_iterator cend del vector<string> de la STL
         * @return const_iterator cend de vector de la STL
         */
    inline Termino::const_iterator end() const {return termino.second.cend();} ; 


        /**
         * @brief Constructor por defecto 
         */
	inline Termino(){};

        /**
         * @brief Constructor con parametros
         * @param palabra le pasas una palabra como parametro para construir un Termino
         * @param definiciones le pasas unas definiciones como parametro para construir un Termino
         */
	inline Termino(string palabra, const vector<string> definiciones){ this->termino.first = palabra; this->termino.second = definiciones; };
        
        /**
         * @brief Constructor con un parametro termino
         * @param term termino pasado para construir un Termino
         */
	inline Termino(const Termino & term){ this->termino.first = term.termino.first; this->termino.second = term.termino.second; };
        
        /**
         * @brief Devuelve una palabra
         * @return palabra devuelves la palabra de Termino
         */
	inline string getPalabra() const { return termino.first ; };
        
        /**
         * @brief Devuelve las definiciones
         * @return definiciones devuelves las definiciones asociadas de Termino
         */
	inline vector<string> getDefiniciones() const { return this->termino.second; };
        
        /**
         * @brief Devuelve el numero de definiciones    
         * @return tamaño devuelves el tamaño de las definiciones de termino
         */
	inline int getNumDefiniciones() const { return termino.second.size(); };
        
        /**
         * @brief Asigna una palabra pasada por parametro a palabra
         * @param palabra se le pasa una palabra que asgina a palabra
         */
	inline void setPalabra(string palabra){ this->termino.first = palabra; };
        
        /**
         * @brief Aisgna definiciones pasadas por parametro a las definiciones
         * @param definiciones que se le asigna a definiciones
         */
	inline void setDefiniciones(vector<string> definiciones){ this->termino.second = definiciones; };
        
        /**
         * @brief Asignacion de una definicion pasada por parametro a la definicion
         * @param definicion que se le asigna a definicion 
         */
	inline void addDefinicion(string definicion){ this->termino.second.push_back(definicion); };
        
        /**
         * @brief Asignacion de una definicion pasada por parametro a la definicion
         * @param definicion que se le asigna a definicion 
         */
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

        /**
         * @brief Sobrecarga del operador de menor
         * @return @true si es menor respecto al que le pasas @false en caso contrario
         */
    bool operator<(const Termino &termino) const;

        /**
         * @brief Sobrecarga del operador distinto
         * @return @true si es distinto al que le pasas @false en caso contrario
         */
    bool operator!=(const Termino &term)const;

        /**
         * @brief Sobrecarga del operador distinto de null
         * @return @true si es distinto al que le pasas @false en caso contrario
         */
   // bool operator/() ;


};

#endif
