#ifndef DICCIONARIO
#define DICCIONARIO

#include "Termino.h"

/**
  *  @brief T.D.A. Diccionario
  *
  * Una instancia @e c del tipo de datos abstracto @c Diccionario es un objeto
  *, compuestos por un vector dinamico de string de la clase abstracta termino
  * que este a su vez es representado por un dato string palabra y un vector de string definiciones.
  *
  * Un ejemplo de su uso:
  * @include pruebadiccionario.cpp
  *
  * @author Raul Soria Gonzalez y José Santos Salvador
  * @date 26 de Octubre 2018
  */

class Diccionario
{
private:

	Vector_Dinamico<Termino> terminos;

public:
        
        /**
         * @brief Constructor por defecto
         */
	inline Diccionario() { this->terminos.resize(0); };
        
        /**
         * @brief Constructor con parametro
         * @param terminos terminos para introducir en el diccionario
         */
	inline Diccionario(const Vector_Dinamico<Termino> & terminos){ this->terminos = terminos; };

        /**
         * @brief Constructor copia
         * @param dicc diccionario original
         */
	inline Diccionario(const Diccionario & dicc){ this->terminos = dicc.terminos; };

        /**
         * @brief Terminos
         * @return Devuelve un vector con los términos del diccionario
         */
	inline Vector_Dinamico<Termino> getTerminos() const { return terminos; };

        /**
         * @brief Definiciones de la palabra indicada
         * @param palabra palabra de la que buscar las definiciones
         * @return Devuelve un vector con las definiciones de la palabra
         */
	Vector_Dinamico<string> getDefiniciones(string palabra) const;

        /**
         * @brief Número de términos en el diccionario
         * @return Devuelve el número de términos del diccionario
         */
	inline int getNumTerminos() const { return terminos.size(); };

        /**
         * @brief Añade un término al diccionario
         * @param termino termino a añadir
         */
	void addTermino(const Termino & termino);

        /**
         * @brief Elimina un término del diccionario
         * @param termino termino a eliminar
         */
	inline void rmTermino(const Termino & termino){ this->terminos.rmElemento(termino); };

        /**
         * @brief Asigna un vector de términos al diccionario
         * @param terminos vector de términos a asignar
         */
	inline void setDiccionario(const Vector_Dinamico<Termino> & terminos){ this->terminos = terminos; };

        /**
         * @brief Escribe un fichero con el diccionario
         * @param fichero de salida
         * @return Devuelve @true si no ha habido problemas @false si no se ha podido escribir
         */
	bool SalvarAFichero(const char* fichero) const;

        /**
         * @brief Carga un diccionario desde un fichero
         * @param fichero path del fichero
         * @return Devuelve @true si no ha habido problemas @false si no se ha podido crear el diccionario
         */
	bool CargarDeFichero(const char* fichero);

        /**
         * @brief Filtra los términos que están en un intervalo entre dos letras
         * @param inicio primer caracter
         * @param fin segundo caracter
         * @return Devuelve el diccionario con los términos dentro del intervalo
         */
	Diccionario FiltrarPorIntervalo(char inicio, char fin) const;

        /**
         * @brief Busca la posición del primer término que empiece por el char indicado
         * @param inicio caracter a buscar
         * @return Devuelve la posición del término
         */
	int BuscarChar(char inicio) const;

        /**
         * @brief Definiciones que contienen una palabra
         * @param palabra palabra a buscar en las definiciones
         * @return Devuelve un diccionario con las definiciones que contengan la palabra
         */
	Diccionario FiltrarPorPalabra(string palabra) const;

        /**
         * @brief Devuelve por referencia tres enteros
         * @param num_max Número máximo de definiciones asociadas a una palabra
         * @param num_promedio Número promedio de definiciones por palabra
         * @param num_total Número total de definiciones
         */
 	void RecuentoDefiniciones(int & num_max, int & num_promedio, int & num_total) const;

        /**
         * @brief Sobrecarga del operador de entrada de flujo
         */
 	friend istream& operator>>(istream& is, Diccionario& dicc);

        /**
         * @brief Sobrecarga del operador de salida de flujo
         */
	friend ostream& operator<<(ostream& os, const Diccionario& dicc);
};

#endif