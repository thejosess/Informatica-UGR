/**
  *  @file conjunto_letras.h
  *  @brief fichero de cabecera del TDA conjunto_letras
  */
#ifndef CONJUNTO_LETRAS
#define CONJUNTO_LETRAS

#include "letra.h"
#include <set>

/**
  *  @brief T.D.A. conjunto_letras
  *
  * Una instancia @e conjunto del tipo de datos abstracto @c conjunto_letras es un objeto del tipo @c set
  * compuesto por varias letras sobre el tipo @c letra 
  * Lo representamos como;
  *
  * conjunto_letras = set<letra> conjunto
  * siendo cada elemento(conjunto.elemento) una letra del set compuesto por letras
  *
  * @author Raul Soria Gonzalez y José Santos Salvador
  * @date 5 de enero 2019
  */
class conjunto_letras
{
private:
/**
  * @page rep conjunto_letras Rep del TDA conjunto_letras
  *
  * @section inv conjunto_letras Invariante de la representación
  *
  * Un objeto @e conjunto del TDA conjunto_letras debe cumplir
  *
  * -@c conjunto.size() >=0
  *
  * -@c y los invariantes set de la stl
  *
  * @section fa conjunto_letras Función de abstracción
  *
  * Un objeto válido @e conjunto del TDA conjunto_letras representa al valor de tamaño @e n
  *
  * {conjunto<letra>}
  * {conjunto.begin , conjunto ,....conjunto.end}
  *
  */
	set<letra> conjunto; /**< letras */

public:

    /**
    @brief Construye un conjunto_letras vacío.
    **/
	inline conjunto_letras() {};

	/**
	@brief Devuelve el numero de letras en el conjunto_letras
	**/
	inline int size() const { return conjunto.size(); };

  /**
  @brief Calcula la puntuacion de una palabra pasada por parametro
  @param string str la palabra para calcular su puntuacion
  @param bool longitud para saber si hay que calcularle la puntuacion o solo la longitud
  @return int con el valor calculado por la funcion
  */
  int calcular_puntuacion(string str, bool longitud) const;

	/**
	@brief Lee de un flujo de entrada un conjunto_letras
	@param is flujo de entrada
	@param D el objeto donde se realiza la lectura.
	@return el flujo de entrada
	*/
	friend istream & operator>>(istream & is, conjunto_letras &D);

	/**
	@brief Escribe en un flujo de salida un conjunto_letras
	@param os flujo de salida
	@param D el objeto conjunto_letras que se escribe
	@return el flujo de salida
	*/
	friend ostream & operator<<(ostream & os, const conjunto_letras &D);

	    /**
         * @brief Definicion del tipo iteraror para relacionar
         * el TDA diccionario con el tipo iterator de los tipos rep
         * subyascentes del set de letra de la STL
         */
    typedef set<letra>::iterator iterator;

        /**
         * @brief Definicion del tipo const_iteraror para relacionar
         * el TDA diccionario con el tipo const_iterator de los tipos rep
         * subyascentes del set de letra de la STL
         */
    typedef set<letra>::const_iterator const_iterator;

        /**
         * @brief Devuelve el iterator begin del set<letra> de la STL
         * @return iterator begin de set de letra de la STL
         */
    inline conjunto_letras::iterator begin() { return conjunto.begin(); };

        /**
         * @brief Devuelve el const_iterator cbegin del set<letra> de la STL
         * @return const_iterator cbegin de set de letra de la STL
         */
    inline conjunto_letras::const_iterator begin() const { return conjunto.cbegin(); };

        /**
         * @brief Devuelve el iterator end del set<letra> de la STL
         * @return iterator end de set de letra de la STL
         */
    inline conjunto_letras::iterator end() { return conjunto.end(); };

        /**
         * @brief Devuelve el const_iterator cend del set<letra> de la STL
         * @return const_iterator cend de set de letra de la STL
         */
    inline conjunto_letras::const_iterator end() const { return conjunto.cend(); };

        /**
         * @brief Devuelve el conjunto
         * @return set<letra> que es el conjunto
         */
    inline set<letra> getConjunto() const {return conjunto;};

        /**
         * @brief Devuelve el conjunto
         * @param el char c1 que quieres buscar en el conjunto
         * @return si está o no en el conjunto
         */
    bool find(char c1) const ;
};

#endif