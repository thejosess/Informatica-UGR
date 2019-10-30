///
///@file Diccionario.h
///@brief fichero de cabecera del TDA Diccionario
///
///Se crea un diccionario, el diccionario está compuesto de un vector
///de términos.
///
#ifndef Diccionario_h
#define Diccionario_h
///
///@brief TDA Diccionario
///
///@author Miguel Ángel Benítez Alguacil
///@author Najib Saadouli Arco
///
///Una instancia @e d del tipo de dato abstracto
///@c Vector_Dinamico sobre el tipo @c Termino es un
///array 1-D de un determinado tamaño @e n que puede
///crecer y decrecer a petición del usuario.
///Podemos representarlo como:
///    {d[0], d[1],...,d[n-1]}
///donde d[i] es el Termino asociado a la posición i del vector
///
///Un ejemplo de uso puede verse en
///@include Pruebadiccionario.cpp
///
#include "Termino.h"

class Diccionario{
private:
  ///
  ///@page repDiccionario Rep del TDA Diccionario
  ///@section invDiccionario Invariante de Representación
  ///
  ///Un objeto @e d del TDA Diccionario debe cumplir:
  ///
  ///-@c d.terminos>=0
  ///
  ///@section faDiccionario Función de Abstracción
  ///
  ///Un objeto válido @e rep del TDA Diccionario
  ///representa al vector de tamaño @e n
  ///
  ///  {d.datos[0], d.datos[1],..., d.datos[nelementos-1]}
  ///
  Vector_Dinamico<Termino> terminos;  	///<Vector dinámico que alberga los términos
public:
  //Constructores
  ///
  ///@brief Constructor por defecto
  Diccionario();
  ///
  ///@brief Constructor con parámetro, crea un diccionario con un sólo término
  ///@param termino es el primer y único término que tendrá el diccionario.
  Diccionario(Termino termino);
  ///
  ///@brief Constructor con parámetros
  ///@param terminos es un vector dinámico de términos.
  Diccionario(Vector_Dinamico<Termino> terminos);
  ///
  ///@brief Constructor de copia
  ///@param original es el diccionario del que se hace copia. No se modifica.
  Diccionario(const Diccionario & original);
  //Operadores de consulta
  ///
  ///@brief Definiciones asociadas a la palabra.
  ///@param palabra es de la que obtendremos las definiciones
  ///@return Devuelve el vector de definiciones de palabra. 
  Vector_Dinamico<string> getDefinicionesTermino(string palabra);
  ///
  ///@brief Vector de términos.
  ///@return Devuelve el vector con todos los términos del diccionario.
  Vector_Dinamico<Termino> getVectorTerminos() const;
  ///
  ///@brief Número total de términos del diccionario.
  ///@return Devuelve el número de términos.
  int getNumeroTerminos() const;
  ///Operadores de modificación
  ///
  ///@brief Añade un término al diccionario.
  ///@param termino será el nuevo término que añadamos al vector,
  ///para ello amplía en uno el vector dinámico y añade el nuevo término. 
  void addTermino(Termino termino);
  ///
  ///@brief Modifica los términos del diccionario.
  ///@param nuevosTerminos será el nuevo vector de términos del diccionario.
  void setTerminos(Vector_Dinamico<Termino> nuevosTerminos);
  ///
  ///@brief Elimina un término del diccionario. 
  void deleteTermino(const Termino& termino);
  ///Metodos Privados
  ///
  ///@brief Busca el Termino cuya palabra es la indicada
  ///@param palabra string que corresponde al Termino a buscar
  ///@return Devuelve el entero correspondiente a la posicion del Termino que se quiere encontrar en el Diccionario
  int buscarTermino(string palabra);
  ///
  ///@brief Busca el primer Termino cuya palabra empieza por caracter
  ///@param caracter char por el que empieza el Termino
  ///@return Devuelve el entero correspondiente a la posicion del Termino que se quiere encontrar en el Diccionario
  int buscarPrimerTerminoCaracter(char caracter);
  ///Operaciones
  /// 
  ///@brief Obtener un subconjunto del diccionario dado un intervalo.
  ///@param diccionario es el Diccionario del que buscaremos el intervalo. 
  ///@param caracter_inicio es el extremo inferior del intervalo.
  ///@param caracter_fin es el extremo superior del intervalo.
  ///@return Devuelve el diccionario acotado por ese intervalo.
  Diccionario filtrarPorIntervalo(char caracter_inicio, char caracter_fin);
  /// 
  ///@brief Obtener un subconjunto del diccionario dado un intervalo.
  ///@param diccionario es el Diccionario del que buscaremos la palabra. 
  ///@param palabra_clave es la palabra que buscaremos.
  ///@return Devuelve un subdiccionario que contenga las palabras en cuyas definiciones aparece la palabra clave.
  Diccionario filtrarPalabraClave(string palabra_clave);
  /// 
  ///@brief Escribe por pantalla el número de definiciones, el máximo de definiciones asociadas a una palabra y el promedio de definiciones por palabra.
  ///@param diccionario es el Diccionario del que obtendremos datos.
  void recuentoDefiniciones();
  ///Sobrecarga de operadores
  /// 
  ///@brief Sobrecarga para el operador de inserción en un flujo de salida.
  ///@param os El flujo de salida en el que se inserta
  ///@return @p os para poder encadenar varias inserciones consecutivas
  friend ostream& operator<<(ostream& os, const Diccionario& diccionario);
  /// 
  ///@brief Sobrecarga para el operador de extracción de un flujo.
  ///@param is El flujo de entrada desde el que se extrae.
  ///@return @p is para poder encadenar varias extracciones consecutivas
  friend istream& operator>>(istream& is, Diccionario& diccionario);
};
#endif /* Diccionario_h */
