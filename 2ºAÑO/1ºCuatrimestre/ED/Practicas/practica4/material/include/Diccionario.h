/**
  *  @file Diccionario.h
  *  @brief fichero de cabecera del TDA Diccionario
  */
#ifndef DICCIONARIO
#define DICCIONARIO

#include "Termino.h"
#include <set>
/**
  *  @brief T.D.A. Diccionario
  *
  * Una instancia @e dicc del tipo de datos abstracto @c Diccionario es un objeto del tipo @c pair
  * compuesto por un conjunto de terminos sobre el tipo @c set de la stl.
  * Lo representamos como ;
  *
  * terminos = set<Termino>
  * siendo terminos el contenedor de cada uno de los terminos y terminos.begin().first 
  * la palabra del Termino y terminos.begin().second las definiciones asociadas a la 
  * palabra
  *
  * Su uso puede verse en :
  * @include pruebadiccionario.cpp
  *
  * @author Raul Soria Gonzalez y José Santos Salvador
  * @date 5 de diciembre 2018
  */
class Diccionario
{
private:
/**
  * @page repDiccionario Rep del TDA Diccionario
  *
  * @section invTermino Invariante de la representación
  *
  * Un objeto @e dicc del TDA Diccionario debe cumplir
  *
  * -@c dicc.getNumTerminos >=0
  * -@c dicc.getPalabra != null 
  * -@c dicc.getTerminos tiene que ser de tipo set<Termino>
  * -@c dicc.getDefiniciones tienen que ser vector<string>
  * -@ y el invariantes del set de la stl
  *
  * @section faDiccionario Función de abstracción
  *
  * Un objeto válido @e rep del TDA Diccionario representa al valor de tamaño @e n
  *
  * {set<Termino> diccionario}
  * {diccionario[1] = Termino term1, diccionario[2] = Termino term2,... diccionario[n-1]=Termino term3}
  *
  */
set<Termino> terminos;  /**< todos los terminos de diccionario*/

public:

        /**
         * @brief Definicion del tipo iteraror para relacionar
         * el TDA diccionario con el tipo iterator de los tipos rep
         * subyascentes del set de Termino de la STL
         */
    typedef set<Termino>::iterator iterator;

        /**
         * @brief Definicion del tipo const_iteraror para relacionar
         * el TDA diccionario con el tipo const_iterator de los tipos rep
         * subyascentes del set de Termino de la STL
         */
    typedef set<Termino>::const_iterator const_iterator;

        /**
         * @brief Devuelve el iterator begin del set<Termino> de la STL
         * @return iterator begin de set de Termino de la STL
         */
    inline Diccionario::iterator begin(){return terminos.begin();};

        /**
         * @brief Devuelve el const_iterator cbegin del set<Termino> de la STL
         * @return const_iterator cbegin de set de Termino de la STL
         */
    inline Diccionario::const_iterator begin()const {return terminos.cbegin();} ;

        /**
         * @brief Devuelve el iterator end del set<Termino> de la STL
         * @return iterator end de set de Termino de la STL
         */
    inline Diccionario::iterator end(){return terminos.end();};

        /**
         * @brief Devuelve el const_iterator cend del set<Termino> de la STL
         * @return const_iterator cend de set de Termino de la STL
         */
    inline Diccionario::const_iterator end()const {return terminos.cend();};    
        
        /**
         * @brief Constructor por defecto
         */
	inline Diccionario() {};
        
        /**
         * @brief Constructor con parametro
         * @param terminos terminos para introducir en el diccionario
         */
	inline Diccionario(const set<Termino> & terminos){ this->terminos = terminos; };

        /**
         * @brief Constructor copia
         * @param dicc diccionario original
         */
	inline Diccionario(const Diccionario & dicc){ this->terminos = dicc.terminos; };

        /**
         * @brief Terminos
         * @return Devuelve un vector con los términos del diccionario
         */
	inline set<Termino> getTerminos() const { return terminos; };

        /**
         * @brief Definiciones de la palabra indicada
         * @param palabra palabra de la que buscar las definiciones
         * @return Devuelve un vector con las definiciones de la palabra
         */
	vector<string> getDefiniciones(string palabra) const;

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
         * @brief Busca un termino en el vector de terminos
         * @param termino termino a buscar
         */
    set<Termino>::iterator buscar(const Termino & termino);

        /**
         * @brief Elimina un término del diccionario
         * @param termino termino a eliminar
         */
	void rmTermino(const Termino & termino);

        /**
         * @brief Asigna un vector de términos al diccionario
         * @param terminos vector de términos a asignar
         */
	inline void setDiccionario(const set<Termino> & terminos){ this->terminos = terminos; };

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
	set<Termino>::iterator BuscarChar(char inicio) const;

        /**
         * @brief Definiciones que contienen una palabra
         * @param palabra palabra a buscar en las definiciones
         * @return Devuelve un diccionario con las definiciones que contengan la palabra
         */
	Diccionario FiltrarPorPalabra(string palabra) const;

        /**
         * @brief Definiciones que contienen una palabra contenida
         * @param palabra palabra a buscar en las definiciones
         * @return Devuelve un diccionario con las definiciones que contengan la palabra
         */
  Diccionario FiltrarPorContenidaPalabra(string palabra) const;

        /**
         * @brief Palabra que contiene la definicion pasada
         * @param definicion definicion a buscar en las palabras
         * @pre pasar de forma correcta la definicion
         * @return Devuelve una palabra que contenga la definicion pasada
         */
  string FiltrarPorDefinicion(string palabra) const;

        /**
         * @brief Subconjunto de diccionario con los terminos con num numero de definiciones asociadas
         * @param el num numero de definiciones asociadas a cada termino
         * @return Devuelve el subconjuto de diccionario con los terminos con un numero de definiciones asociadas num
         */
  Diccionario FiltrarPorNumeroDefiniciones(int num) const;

        /**
         * @brief Subconjunto de diccionario con los terminos con  numero de definiciones asociadas compredidos entre el intervalo
         * @param el num numero de definiciones asociadas a cada termino
         * @return Devuelve el subconjuto de diccionario con los terminos con un numero de definiciones asociadas comprendidas entre un intervalo
         */
  Diccionario FiltrarPorIntervaloNumeroDefiniciones(int inicio, int final) const;

        /**
         * @brief Devuelve por referencia tres enteros
         * @param num_max Número máximo de definiciones asociadas a una palabra
         * @param num_promedio Número promedio de definiciones por palabra
         * @param num_total Número total de definiciones
         * @param palabra el string de una palabra para ver el numero de definiciones
         * @param num_def el numero de definiciones asociada a la palabra
         */
 	void RecuentoDefiniciones(int & num_max, int & num_promedio, int & num_total, string & palabra,int & num_def) const;

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