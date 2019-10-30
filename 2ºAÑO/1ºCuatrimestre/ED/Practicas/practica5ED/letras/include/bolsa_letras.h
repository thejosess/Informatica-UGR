/**
  *  @file bolsa_letras.h
  *  @brief fichero de cabecera del TDA bolsa_letras
  */
#ifndef BOLSA
#define BOLSA

#include <set>
#include <random>
#include "lista_palabras.h"

using namespace std;

/**
  *  @brief T.D.A. bolsa_letras
  *
  * Una instancia @e bolsa del tipo de datos abstracto @c bolsa_letras es un objeto del tipo @c multiset
  * compuesto por una letra sobre el tipo @c char 
  * . Lo representamos como;
  *
  * bolsa_letras = multiset<char> bolsa
  * siendo cada elemento(bolsa.elemento) una letra de la lista del multiset
  *
  * @author Raul Soria Gonzalez y José Santos Salvador
  * @date 5 de Enero 2019
  */
class bolsa_letras
{
private:
/**
  * @page rep bolsa_letras Rep del TDA bolsa_letras
  *
  * @section inv bolsa_letras Invariante de la representación
  *
  * Un objeto @e bolsa_letras del TDA bolsa_letras debe cumplir
  *
  * -@c lista.size() >=0
  *
  * -@c y los invariantes multiset de la stl
  *
  * @section fa bolsa_letras Función de abstracción
  *
  * Un objeto válido @e bolsa del TDA bolsa_letras representa al valor de tamaño @e n
  *
  * {bolsa<char>}
  * {bolsa.begin , char ,....bolsa.end}
  *
  */
multiset<char> bolsa; /**< letras */

public:

    /**
    @brief Construye una bolsa_letras vacía.
    **/
	inline bolsa_letras() {};

    /**
    @brief Constructor con parametros
    @param conjunto conjunto_letras de entrada
    */
	inline bolsa_letras(conjunto_letras & letras) { letras >> *this; };

    /**
    @brief Constructor con parametros
    @param bolsa_letras letras de entrada
    */
  inline bolsa_letras(const bolsa_letras & letras) { *this = letras; };

	/**
	@brief Devuelve el numero de char en el multiset
	**/
	inline int size() const { return bolsa.size(); };

	/**
	@brief Lee de un conjunto_letras
	@param conjunto conjunto_letras de entrada
	@param bolsa el objeto donde se realiza la lectura
	*/
	friend void operator>>(const conjunto_letras & conjunto, bolsa_letras & bolsa);

    /**
    @brief Sobrecarga del operador de igualdad para insertar
    @param la bolsa_letra original
    @return devuevle la bolsa_letras
    */
  bolsa_letras& operator=(const bolsa_letras & original);

    /**
    @brief Devuelve una letra char cogida de la bolsa
    @return devuevle la letra char escogida de la bolsa 
    */
	char coger_letra();

	    /**
         * @brief Definicion del tipo iteraror para relacionar
         * el TDA diccionario con el tipo iterator de los tipos rep
         * subyascentes del multiset de char de la STL
         */
    typedef multiset<char>::iterator iterator;

        /**
         * @brief Definicion del tipo const_iteraror para relacionar
         * el TDA diccionario con el tipo const_iterator de los tipos rep
         * subyascentes del multiset de char de la STL
         */
    typedef multiset<char>::const_iterator const_iterator;

        /**
         * @brief Devuelve el iterator begin del multiset<char> de la STL
         * @return iterator begin de multiset de char de la STL
         */
    inline bolsa_letras::iterator begin() { return bolsa.begin(); };

        /**
         * @brief Devuelve el const_iterator cbegin del multiset<char> de la STL
         * @return const_iterator cbegin de multiset de char de la STL
         */
    inline bolsa_letras::const_iterator begin() const { return bolsa.cbegin(); } ;

        /**
         * @brief Devuelve el iterator end del multiset<char> de la STL
         * @return iterator end de multiset de char de la STL
         */
    inline bolsa_letras::iterator end() { return bolsa.end(); };

        /**
         * @brief Devuelve el const_iterator cend del multiset<char> de la STL
         * @return const_iterator cend de multiset de char de la STL
         */
    inline bolsa_letras::const_iterator end() const { return bolsa.cend(); };
};

#endif