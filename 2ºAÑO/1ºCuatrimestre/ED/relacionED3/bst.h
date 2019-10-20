//-*-Mode: C++;-*-

/**
  * @file BST.h
  * @brief TDA BST
  *
  */

#ifndef __BST_H__
#define __BST_H__


/**
 *  @brief TDA. BST
 *
 * TDA BST::BST, insert, erase, find, size, empty
 * clear, begin, end, ~BST
 *
 * El TDA BST representa objetos que abstraen el concepto de Arbol
 * Binario de Busqueda (Binary Search Tree). Es un tipo contenedor,
 * cuyos componentes son Entradas formados por dos partes {clave,
 * valor}, de tipos Key y T, respectivamente.
 *
 * Los objetos de tipo Key deben tener las operaciones:
 * - bool operator<(const Key & a, const Key & b);
 * - bool operator==(const Key & a, const Key & b);
 *
 * Los objetos de tipo T deben tener las operaciones:
 * - bool operator==(const T & a, const T & b);
 *
 *
 */

using namespace std;

#include "bintree.h" 

template <typename Key, typename T>
class BST {

public:

  class iterator;
  typedef unsigned int size_type;


 /**
     @brief Constructor primitivo por defecto.

     Crea un BST vac�o.
  */
  BST();

  /**
      @brief Inserta o actualiza una entrada en el BST.

      @param entrada:  Entrada a insertar en el receptor.

      Si no existe una entrada con clave igual a entrada.first,
      inserta entrada en el receptor.  Si ya existe, su
      valor asociado es reemplazado por entrada->second.
  */
  void insert(const pair<Key, T> & entrada);


  /**
     @brief Buscar una clave en el BST

     @param clave: Clave a buscar en el BST.
     @return  iterador a la posici�n del BST con la clave
              'clave', si est� en el BST. end, en otro caso.

  */
  iterator find(const Key & clave) const;


  /**
     @brief Eliminar una entrada en el BST.

     @param clave: Clave a buscar en el BST.

     @return posici�n del siguiente elemento, si 'clave'
                   existe en el receptor. end, en otro caso.

    Busca 'clave' entre las entradas del receptor.  Si la encuentra,
    la elimina y devuelve la posicici�n del siguiente elemento.
    En otro caso, devuelve la posici�n final del recorrido.
  */
  iterator erase(const Key & clave);


  /**
     @brief Devuelve el n�mero de entradas del receptor.

     @return  N�mero de entradas del receptor.
  */
  size_type size() const;


  /**
     @brief Vac�a el receptor.

     Elimina todas las entradas del receptor.
  */
  void clear();

  /**
     @brief Indica si el receptor est� vac�o.

     @return true, si el receptor no tiene entradas;
             false, en otro caso.
  */
  bool empty() const;


  /**
     @brief Posici�n de la primera entrada.

     @return Posici�n inicial del recorrido del receptor
     (posici�n del primer elemento).
  */
  iterator begin() const;

  /**
    @brief Posici�n final del ABB.

    @return Posici�n final del recorrido del receptor
    (posici�n posterior al �ltimo elemento).
  */
  iterator end();
   
  
    /**
     @brief Posici�n de la primera entrada.

     @return Posici�n inicial del recorrido del receptor
     (posici�n del primer elemento).
  */
  iterator begin();

  /**
    @brief Posici�n final del ABB.

    @return Posici�n final del recorrido del receptor
    (posici�n posterior al �ltimo elemento).
  */
  iterator end() const;

  /**
     Destructor.
     
     Liberar todos los recursos asociados al receptor.
  */
  ~BST();


class iterator {
  public:
    /**
       @brief Constructor primitivo por defecto.
    */
    iterator();
  
    /**
       @brief Constructor de copia.
    */
    iterator(const iterator & ite);

    /**
       @brief Operador de incremento.
       
       @pre El BST asociado NO ha sido modificado despu�s
       de la creaci�n del iterador receptor.
       @pre El iterador receptor NO est� al final del recorrido:
       (receptor) != end()
       
       @return  Posici�n actual en el recorrido creciente del BST
                asociado.

	Modifica el (iterador) receptor haci�ndolo apuntar al
	siguiente elemento en el recorrido creciente del
	BST asociado.
    */
    iterator & operator++();
    
    /**
       @brief Obtener el elemento al que apunta el iterator.
       
       @pre El BST asociado NO ha sido modificado despu�s
       de la creaci�n del iterador receptor.
       @pre El iterador receptor NO est� al final del recorrido:
       (receptor) != end()
       
       @return
       El par <Key,T> correspondiente al dato de la posici�n actual
       del recorrido.
    */
    pair<Key,T> operator*() const;


    /**
       @brief Comparaci�n de igualdad.
       
       @param i: Segundo iterador en la comparaci�n.
       @return true, si el receptor e i tienen el mismo valor.
       false, en caso contrario.
    */
    bool operator==(const iterator &i) const;

    /**
       Comparaci�n de igualdad.
       
       @param i: Segundo iterador en la comparaci�n.
       @return false, si el receptor e i tienen el mismo valor.
       true, en caso contrario.
    */
    bool operator!=(const iterator &i) const;
    
    iterator & operator=(const iterator &i);

  private:
    friend class BST;

    typename bintree<pair<Key, T> >::node elnodo;
  };


 private:

  /**
   *  @brief BST<Key, T>::entry
   *
   * Es el tipo de dato base contenido en BST
   */
  typedef pair<Key, T> entry;

  bool encontrar(const pair<Key, T> & e,
    typename bintree<pair<Key, T> >::node & n,
    typename bintree<pair<Key, T> >::node & nodo_padre) const;
    
  void borrar_nodo(typename bintree<typename BST<Key, T>::entry>::node nodo,
		 typename bintree<typename BST<Key, T>::entry>::node nodo_padre);


  bintree<entry> arbolb;
};

#include "bst.hxx"

#endif


