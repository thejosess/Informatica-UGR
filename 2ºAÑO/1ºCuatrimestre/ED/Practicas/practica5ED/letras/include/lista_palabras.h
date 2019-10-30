/**
  *  @file lista_palabras.h
  *  @brief fichero de cabecera del TDA lista_palabras
  */
#ifndef __lista_palabras_h__
#define __lista_palabras_h__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include "conjunto_letras.h"

using namespace std;

/**
  * @brief es el functor que sirve de criterio de ordenación para el set<pair<string,int>> te ordena por el int y despues por el string
  * @param le pasa los pair<string,int>> que ha de comparar a y b
  * @return @true si es menor respecto al que le pasas @false en caso contrario
  */
struct classcomp 
{
  bool operator() (const pair<string,int>& a, const pair<string,int>& b) const
  {
  if(a.second == b.second)
      return a.first < b.first;
    else
      return a.second < b.second;
  }
};


/**
  *  @brief T.D.A. lista_palabras
  *
  * Una instancia @e lista del tipo de datos abstracto @c lista_palabras es un objeto del tipo @c set
  * compuesto por varias palabras sobre el tipo @c string 
  * Lo representamos como;
  *
  * lista_palabras = set<string> palabras
  * siendo cada elemento(palabras.elemento) una palabra de la lista de palabras del set
  *
  * @author Raul Soria Gonzalez y José Santos Salvador
  * @date 5 de enero 2019
  */
class lista_palabras
{
private:
/** 
  * @page rep lista_palabras Rep del TDA lista_palabras
  *
  * @section inv lista_palabras Invariante de la representación
  *
  * Un objeto @e lista del TDA lista_palabras debe cumplir
  *
  * -@c lista.size() >=0
  *
  * -@c los invariantes del string y set de la stl
  *
  * @section fa lista_palabras Función de abstracción
  *
  * Un objeto válido @e lista del TDA lista_palabras representa al valor de tamaño @e n
  *
  * {lista<string>}
  * {lista.begin , string ,....lista.end}
  *
  */
	set<string> datos; /**< lista de palabras palabra */

public:

	/**
	@brief Construye un lista_palabras vacío.
	**/
	inline lista_palabras() {};

	/**
	@brief Devuelve el numero de palabras en el lista_palabras
	**/
	inline int size() const { return datos.size(); };

	/**
	@brief Obtiene todas las palabras en el lista_palabras de una longitud dada
	@param longitud la longitud de las palabras de salida
	@return un vector con las palabras de longitud especificada en el parámetro de entrada
	**/
	vector<string> palabras_longitud(int longitud) const ;

	/**
	@brief Indica si una palabra está en el lista_palabras o no
	@param palabra la palabra que se quiere buscar
	@return true si la palabra esta en el lista_palabras. false en caso contrario
	**/
	inline bool Esta(string palabra) { return datos.find(palabra) == this->end() ? false : true; };

	/**
	@brief Cuenta la cantidad de veces que sale un char y almacena ese frecuencia y el char en un map, y el total de las letras que salen
	@param int total de las letras que almacenas y conjunto_letras conjunto
	@return el map con el char y la cantidad de veces que sale
	**/
	map<char,int> contar_char(const conjunto_letras & conjunto, int & total) const;

  /**
  @brief Busca el char c1 en la lista_palabras
  @param char c1 a buscar dentro de la lista
  @return el iterador donde se encuentra dicho char en a la lista_palabras
  **/
  set<string>::iterator buscar_char(char c1) const;

  /**
  @brief Busca las soluciones posibles dentro de unos requisitos pasados por parametros
  @param multiset<char> ms_letras con las letras
  @param conjunto_letras conjunto con el conjunto de letras posible para la solucion
  @param bool longitud para decidir si quieres saber la longitud o no
  @return un set<pair<string,int>,classcomp> con las soluciones que cumplen los requisitios
  **/
  set<pair<string, int>,classcomp> buscar_soluciones(const multiset<char> & ms_letras, const conjunto_letras & conjunto, const bool longitud) const;

  /**
  @brief comprueba si es solucion la palabra str pasada por parametro
  @param string str que es la palabra que hay que comprobar
  @param multiset<char> ms_letras con las letras
  @return un set<pair<string,int>> con las soluciones que cumplen los requisitios
  **/
  bool es_solucion(string str, const multiset<char> & ms_letras) const;

	/**
	@brief Lee de un flujo de entrada un lista_palabras
	@param is flujo de entrada
	@param D el objeto donde se realiza la lectura.
	@return el flujo de entrada
	**/
	friend istream & operator>>(istream & is, lista_palabras &D);

	/**
	@brief Escribe en un flujo de salida un lista_palabras
	@param os flujo de salida
	@param D el objeto lista_palabras que se escribe
	@return el flujo de salida
	**/
	friend ostream & operator<<(ostream & os, const lista_palabras &D);

        /**
         * @brief Definicion del tipo iteraror para relacionar
         * el TDA diccionario con el tipo iterator de los tipos rep
         * subyascentes del set de string de la STL
         */
    typedef set<string>::iterator iterator;

        /**
         * @brief Definicion del tipo const_iteraror para relacionar
         * el TDA diccionario con el tipo const_iterator de los tipos rep
         * subyascentes del set de string de la STL
         */
    typedef set<string>::const_iterator const_iterator;

        /**
         * @brief Devuelve el iterator begin del set<string> de la STL
         * @return iterator begin de set de string de la STL
         */
    inline lista_palabras::iterator begin() { return datos.begin(); };

        /**
         * @brief Devuelve el const_iterator cbegin del set<string> de la STL
         * @return const_iterator cbegin de set de string de la STL
         */
    inline lista_palabras::const_iterator begin() const { return datos.cbegin(); } ;

        /**
         * @brief Devuelve el iterator end del set<string> de la STL
         * @return iterator end de set de string de la STL
         */
    inline lista_palabras::iterator end() { return datos.end(); };

        /**
         * @brief Devuelve el const_iterator cend del set<string> de la STL
         * @return const_iterator cend de set de string de la STL
         */
    inline lista_palabras::const_iterator end() const { return datos.cend(); };    
};

#endif