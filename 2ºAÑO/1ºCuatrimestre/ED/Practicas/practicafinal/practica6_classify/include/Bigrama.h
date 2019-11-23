
/** 
 * @file Idioma.h
 * @author DECSAI
*/

#ifndef BIGRAMA_H
#define BIGRAMA_H

#include <iostream>
#include <cstring>
/**
 * @class Bigrama
 * @brief Gestión individual de bigramas: pares de letras consecutivas de un texto y su frecuencia asociada dentro del texto   
 */
class Bigrama {
public:
    /// @brief Constructor base
    Bigrama();
    
    void operator=(const Bigrama& bg);
    
    /**
     * @brief Devuelve el bigrama almacenado
     * @return el bigrama
     */
    const char* getBigrama() const;
    
    /**
     * @brief Devuelve la frecuencia almacenada
     * @return la frecuencia
     */
    int getFrecuencia() const;
    
    /**
     * @brief Actualiza el bigrama, siempre que sea de la longitud adecuada, 
     *  en otro caso, no se actualiza, para evitar desbordamientos del vector
     * @param cadena El nuevo valor del bigrama
     */
    void setBigrama(const char cadena[]);

    /**
     * @brief Actualiza la frecuencia almacenada
     * @param frec La nueva frecuencia
     */
    void setFrecuencia(int frec);
    
    /**
     * @brief Sobrecarga del operador relacional para comparar dos bigramas lexicográficamente
     * @param b el segundo bigrama a comparar
     * @return this->_bigrama > b
     */
    inline bool operator>(const Bigrama &b){return (strcmp(this->_bigrama, b._bigrama) > 0);};
    
    friend std::ostream& operator<<(std::ostream& os, const Bigrama& bigrama);
    friend std::istream& operator>>(std::istream& is, Bigrama& bigrama);

private:
    char _bigrama[3]; /// Bigrama almacenado, incluyendo el '\0'. Ojo a desbordamientos
    int _frecuencia; /// Frecuencia almacenada
};

/**
 * @brief Sobrecarga del operador de inserción en un stream.
 * @param os El stream de salida en el que se inserta
 * @return @p os para poder encadenar varias inserciones consecutivas
 */
std::ostream& operator<<(std::ostream& os, const Bigrama& bigrama);

/**
 * @brief Sobrecarga del operador de extracción de un stream.
 * @param is El stream de entrada desde el que se extrae
 * @return @p is para poder encadenar varias extracciones consecutivas
 */
std::istream& operator>>(std::istream& is, Bigrama& bigrama);

void ordenaAscFrec(Bigrama *v, int n);

void ordenaAscBigr(Bigrama *v, int n);

bool bigramaValido(const Bigrama &b);

void imprimeBigramas(const Bigrama *v, int n);

void sumaBigramas(const Bigrama *v1, int nv1, const Bigrama *v2, int nv2, Bigrama *&res, int & nres);

#endif /* BIGRAMA_H */

