/**
  *  @file letra.h
  *  @brief fichero de cabecera del TDA letra
  */
#ifndef LETRA
#define LETRA

#include <iostream>
#include <fstream>

using namespace std;

/**
  *  @brief T.D.A. letra
  *
  * Una instancia @e c1 del tipo de datos abstracto @c letra es un objeto del tipo @c set
  * compuesto por varias letras sobre el tipo @c letra 
  * Lo representamos como;
  *
  * letra = char, int, puntuacion
  * siendo el char el valor de la letra, el int el numero de veces que aparece y otro int con la puntuacion
  *
  * @author Raul Soria Gonzalez y José Santos Salvador
  * @date 5 de enero 2019
  */
class letra
{
private:
/**
  * @page rep letra Rep del TDA letra
  *
  * @section inv letra Invariante de la representación
  *
  * Un objeto @e c1 del TDA letra debe cumplir
  *
  * -@c c1.veces >=0
  *
  * -@c c1.puntuacion >=0
  *
  * -@c y los invariantes set de la stl
  *
  * @section fa letra Función de abstracción
  *
  * Un objeto válido @e c1 del TDA letra representa al valor de tamaño @e n
  *
  * (c1.caracter,c1.veces,c1.puntuacion)
  *
  */
	char caracter;	/**< caracter */
	int veces;		/**< numero veces de la letra */
	int puntuacion;	/**< puntuacion de la letra */

public:

    /**
    @brief Construye una letra vacía.
    **/
	inline letra() { veces = 0; };

        /**
         * @brief Devuelve el caracter de la letra
         * @return char devuelves el caracter
         */
	inline char getCaracter() const { return this->caracter; };

        /**
         * @brief Devuelve el numero de veces de la letra
         * @return int devuelves el numero de veces de la letra
         */
	inline int getVeces() const { return this->veces; };

        /**
         * @brief Devuelve la puntuacion de la letra
         * @return int devuelves la puntuacion de la letra
         */
	inline int getPuntuacion() const { return this->puntuacion; };

        /**
         * @brief Aisgna el caracter de la letra pasado por parametro 
         * @param char c para asignar al caracter de la letra
         */
	inline void setCaracter(char c) { this->caracter = c; };

        /**
         * @brief Aisgna el numero de veces que aparece la letra
         * @param int n_veces con el numero de veces que aparece la letra
         */
	inline void setVeces(int n_veces) { this->veces = n_veces; };

        /**
         * @brief Aisgna la puntuacion de la letra
         * @param int puntuacion con la puntuacion de la letra 
         */
	inline void setPuntuacion(int puntuacion) { this->puntuacion = puntuacion; };

        /**
         * @brief Sobrecarga del operador de menor
         * @return @true si es menor respecto al que le pasas @false en caso contrario
         */
	bool operator<(const letra &D) const;

	/**
	@brief Lee de un flujo de entrada un letra
	@param is flujo de entrada
	@param D el objeto donde se realiza la lectura.
	@return el flujo de entrada
	*/
	friend istream & operator>>(istream & is, letra &D);

	/**
	@brief Escribe en un flujo de salida un letra
	@param os flujo de salida
	@param D el objeto letra que se escribe
	@return el flujo de salida
	*/
	friend ostream & operator<<(ostream & os, const letra &D);
};

#endif