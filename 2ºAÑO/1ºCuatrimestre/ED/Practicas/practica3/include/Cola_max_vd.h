#ifndef COLAMAX
#define COLAMAX

#include <queue>
#include <iostream>
#include "Vector_Dinamico.h"

using namespace std;

/**
  *  @brief T.D.A. Cola_max
  *
  * Se trata de una cola con dos implementaciones, una realizada a partir de un vector
  *	y otra a partir de dos pilas, pero ambas implementaciones funcionan de igual manera.
  * Esta cola guarda un pair que contiene el elemento que corresponde con
  * esa posición de la cola y el elemento máximo que hay actualmente en la cola.
  *
  * @author Raul Soria Gonzalez y José Santos Salvador
  * @date 15 de Noviembre 2018
  */

template <typename T>
class Cola_max
{
private:

	Vector_Dinamico<pair<T,T>> cola;

public:

    /**
     * @brief Constructor por defecto
     */
	inline Cola_max(){ cola.resize(0); };

    /**
     * @brief Constructor copia
     * @param c1 La cola original
     */
	Cola_max(const Cola_max<T> &c1);
	
	/**
     * @brief Añade un elemento al final de la cola
     * @param elemento El elemento que se ha de añadir
     */
	void push(const T& elemento);

    /**
     * @brief Saca el elemento que está en el frente de la cola
     */
	void pop();

    /**
     * @brief Indica si la cola está vacía o no
     * @return Devuelve @b true si lo está @b false si no lo está
     */
	bool empty();

    /**
     * @brief Indica el tamaño de la cola
     * @return Devuelve el tamaño de la cola
     */
	int size();

    /**
     * @brief Devuelve el elemento que está al frente de la cola
     * @return Devuelve dicho elemento
     */
	T front();

    /**
     * @brief Devuelve el elemento que está al final de la cola
     * @return Devuelve el último elemento introducido en la cola
     */
	T back();
	
    /**
     * @brief Indica el elemento máximo que hay actualmente en la cola
     * @return devuelve el máximo de la cola
     */
	inline T maximo(){ return cola[0].second; };
};

#include "Cola_max_vd.cpp"

#endif