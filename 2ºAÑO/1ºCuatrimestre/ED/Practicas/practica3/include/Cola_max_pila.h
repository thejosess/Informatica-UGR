#ifndef COLAMAX
#define COLAMAX

#include <iostream>
#include <utility>
#include <stack>

using namespace std;

template <typename T>
class Cola_max
{
private:

	stack< pair<T,T> > primera;
	stack< pair<T,T> > segunda;

public:
	
	/**
     * @brief Constructor por defecto
     */
	inline Cola_max(){ int x = 2+3; };
        
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
	T maximo();
};

#include "Cola_max_pila.cpp"

#endif