///
///@file Termino.h
///@brief fichero de cabecera del TDA Termino
///
///Se crea un término, cada término está compuesto de una palabra y sus definiciones.
///
#ifndef Termino_h
#define Termino_h
///
///@brief TDA Termino
///
///@author Miguel Ángel Benítez Alguacil
///@author Najib Saadouli Arco
///
///Una instancia @e d del tipo de dato abstracto
///@c Vector_Dinamico sobre el tipo @c string es un
///array 1-D de un determinado tamaño @e n que puede
///crecer y decrecer a petición del usuario.
///Podemos representarlo como:
///    {t[0], t[1],...,t[n-1]}
///donde t[i] es el string asociado a la posición i del vector
///
///Un ejemplo de uso puede verse en
///@include Pruebadiccionario.cpp
///
#include <cstring>
#include <fstream>
#include <iostream>
#include "Vector_Dinamico.h"
using namespace std;

class Termino{
private:
  ///
  ///@page repTermino Rep del TDA Termino
  ///@section invTermino Invariante de Representación
  ///
  ///Un objeto @e t del TDA Termino debe cumplir:
  ///
  ///-@c t.palabra es un string que representa a la palabra del término
  ///
  ///-@c t.definiciones es un Vector_Dinamico de string
  ///que alberga @c nelementos definiciones de tipo @c string
  ///
  ///@section faTermino Función de Abstracción
  ///
  ///
  string palabra;   				///<Cadena de string para la palabra
  Vector_Dinamico<string> definiciones;  	///<Vector dinámico que alberga las definiciones de la palabra
public:
  //Constructores
  ///
  ///@brief Constructor por defecto
  Termino();
  ///
  ///@brief Constructor con parámetros
  ///@param palabra indica la cadena de string que corresponde al nombre del término
  ///@param definicion es un vector dinámico de cadenas de string 
  ///que alberga las distintas definiciones del término.
  Termino(string palabra, Vector_Dinamico<string> definicion);
  ///
  ///@brief Constructor de copia
  ///@param original es el término del que se hace copia. No se modifica.
  Termino(const Termino & original);
  //Operadores de consulta
  ///
  ///@brief Nombre de la palabra del término.
  ///@return Devuelve la cadena de string que forma la palabra. 
  string getPalabra() const;
  ///
  ///@brief Definiciones asociadas a la palabra.
  ///@return Devuelve el vector con las cadenas de string que contienen 
  ///las definiciones del término.
  Vector_Dinamico<string> getDefiniciones() const;
  ///
  ///@brief Número de definiciones asociadas a cada término.
  ///@return Devuelve el número de definiciones del término.
  int getNumeroDefiniciones() const;
  ///Operadores de modificación
  /// 
  ///@brief Establece la palabra.
  void setPalabra(string nuevaPalabra);
  /// 
  ///@brief Establece la definición.
  void setDefinicion(string definicion);
  ///
  ///@brief Añade una definición al vector de definiciones,
  ///@param definicionNueva será la definición que añadamos al vector,
  ///para ello amplía en uno el vector dinámico y añade la nueva cadena. 
  void addDefinicion(string definicionNueva);
  ///Operador de asignación
  ///
  ///@brief Asigna un término a otro
  ///@param original será el término asignado a this,
  ///@return Devuelve el this. Permite la concatenación.
  Termino& operator=(const Termino &original);
  ///Sobrecarga de operadores
  /// 
  ///@brief Sobrecarga para el operador de inserción en un flujo de salida.
  ///@param os El flujo de salida en el que se inserta
  ///@return @p os para poder encadenar varias inserciones consecutivas
  friend istream& operator>>(istream& is, Termino& term);
  /// 
  ///@brief Sobrecarga para el operador de extracción de un flujo.
  ///@param is El flujo de entrada desde el que se extrae.
  ///@return @p is para poder encadenar varias extracciones consecutivas
  friend ostream& operator<<(ostream& os, const Termino& term);
};
#endif /* Termino_h */
