// (C) Miguel García Silvente

/**
  * @file bst.hxx
  * @brief Implementaci�n del TDA bst
  */

  /**
       * repABB Rep del TDA ABB
       *
       * @section invABB Invariante de la representaci�n
       *
       * Un objeto v�lido e rep del TDA BST debe cumplir 
       - @c 
       * rep.arbolb.Etiqueta(n).clave != rep.arbolb.Etiqueta(m).clave
       * para todo \e n,m del �rbol binario - Para todo nodo @c n se
       * verifica que la @c rep.arbolb.Etiqueta(n).clave es mayor que
       * @c rep.arbolb.Etiqueta(m).clave para todo @c m descendiente a
       * la izquierda de @c n y menor que @c
       * rep.arbolb.Etiqueta(u).clave para todo @c u es descendiente a
       * la derecha de @c n
       *
       * @section fA: Funci�n de abstracci�n
       *
       * Un objeto v�lido @e rep del TDA ABB queda representado por el �rbol arbolb
       *
    */



template <typename Key, typename T>
inline 
bool BST<Key, T>::encontrar(const pair<Key, T> & e,
      typename bintree<pair<Key, T> >::node & n,
      typename bintree<pair<Key, T> >::node & nodo_padre) const
{
  bool encontrado = false;
  n = arbolb.root();

  typename bintree<pair<Key, T> >::node padre_aux;

  while (!n.null() && !encontrado) {
    Key aux =  (*n).first;
    if (aux == e.first)  // La clave ya aparece
      encontrado = true;
    else {
      padre_aux = n;
      if (aux < e.first) // Debe insertarse a la derecha de n
        n = n.right();
      else // Debe insertarse a la izquierda de n
        n = n.left();
    }
  }
  
  nodo_padre = padre_aux;

  return encontrado;
}


template <typename Key, typename T>
inline 
BST<Key, T>::BST()
{
}

template <typename Key, typename T>
void BST<Key, T>::insert(const pair<Key, T> & entrada)
{
  bool encontrado = false;
  typename bintree<pair<Key, T> >::node n, nodo_padre;
  

  encontrado = encontrar(entrada, n, nodo_padre);

  if (!encontrado) {
    if (nodo_padre.null()) { // Arbol vacio
      bintree<pair<Key, T> > aux(entrada);
      arbolb = aux;
    }
    else {
      bintree<pair<Key, T> > aux(entrada);
      if ((*nodo_padre).first < entrada.first)
        arbolb.insert_right(nodo_padre, aux);
      else
        arbolb.insert_left(nodo_padre, aux);
    }
  }
  else // Sustituimos la etiqueta para esa clave
    (*n).second = entrada.second;
}

template <typename Key, typename T>
typename BST<Key, T>::iterator BST<Key, T>::find(const Key & clave) const
{
  pair<Key, T> e;
  typename bintree<pair<Key, T> >::node nodo, nodo_padre;

  e.first = clave;

  bool encontrado = encontrar(e, nodo, nodo_padre);

  iterator it;
  if (encontrado)
    it.elnodo = nodo;
  else
    it = end();

  return it;
}


template <class Key, class T>
void BST<Key, T>::borrar_nodo(
  typename bintree<typename BST<Key, T>::entry>::node nodo,
  typename bintree<typename BST<Key, T>::entry>::node nodo_padre)
{
  if (nodo.left().null() && nodo.right().null()) {
    bintree<typename BST<Key, T>::entry> Taux;
    if (nodo_padre.null())
      arbolb.clear();
    else {
      if (nodo_padre.left() == nodo)
        arbolb.prune_left(nodo_padre, Taux);
      else
        arbolb.prune_right(nodo_padre, Taux);
    }
  }
  else { // 1 - 2 hijos
    if (!nodo.left().null() && !nodo.right().null()) { // 2 hijos
      typename bintree<typename BST::entry>::node aux = nodo.left();
      while (!aux.right().null())
        aux = aux.right();
      *nodo = *aux;
      borrar_nodo(aux, aux.parent());
    }
    else { // 1 hijo
      bintree<typename BST::entry> Taux, Taux2;
      if (!nodo.left().null())
        arbolb.prune_left(nodo, Taux);
      else
        arbolb.prune_right(nodo, Taux);

      if (nodo_padre.null())
        arbolb = Taux;
      else {
        if (nodo_padre.left() == nodo) {
          //arbolb.prune_left(nodo_padre, Taux2);
          arbolb.insert_left(nodo_padre, Taux);
        }
        else {
          //arbolb.prune_right(nodo_padre, Taux2);
          arbolb.insert_right(nodo_padre, Taux);
        }
      }
    }
  }
}

template <class Key, class T>
typename BST<Key, T>::iterator BST<Key, T>::erase(const Key & clave)
{
  typename bintree<typename BST<Key, T>::entry>::node nodo, nodo_padre;

  typename BST<Key, T>::entry e;
  e.first = clave;

  bool encontrado = encontrar(e, nodo, nodo_padre);
  if (encontrado)
    borrar_nodo(nodo, nodo_padre);

  //return encontrado; // ���Error!!!
}


template <class Key, class T>
inline 
typename BST<Key, T>::size_type BST<Key, T>::size() const
{
  return arbolb.size();
}

template <class Key, class T>
inline
typename BST<Key, T>::iterator BST<Key, T>::begin() const
{
  iterator ite;
  if (!arbolb.empty()) {
    typename bintree<typename BST<Key, T>::entry>::node nodo = arbolb.root();
    while (!nodo.left().null)
      nodo = nodo.left();
    ite.elnodo = nodo;
  }
  
  return ite;
}

template <class Key, class T>
inline 
typename BST<Key, T>::iterator BST<Key, T>::end()
{
  iterator ite;
  return ite;
}

template <class Key, class T>
inline
typename BST<Key, T>::iterator BST<Key, T>::begin()
{
  iterator ite;
  if (!arbolb.empty()) {
    typename bintree<typename BST<Key, T>::entry>::node nodo = arbolb.root();
    while (!nodo.left().null())
      nodo = nodo.left();
    ite.elnodo = nodo;
  }
  
  return ite;
}

template <class Key, class T>
inline 
typename BST<Key, T>::iterator BST<Key, T>::end() const
{
  iterator ite;
  return ite;
}


template <class Key, class T>
inline 
BST<Key, T>::~BST()
{
}

template <class Key, class T>
inline 
BST<Key, T>::iterator::iterator()
{
}

template <class Key, class T>
inline 
typename BST<Key, T>::iterator& BST<Key, T>::iterator::operator++()
{
  if (elnodo.null())
    return *this;

  if (!elnodo.right().null()) {
      elnodo = elnodo.right();
      while (!elnodo.left().null())
        elnodo = elnodo.left();
  }
  else {
      while (!elnodo.parent().null() &&
                 elnodo.parent().right() == elnodo)
        elnodo = elnodo.parent();
      // Si (padre de elnodo es nodo_nulo), hemos terminado
      //       // En caso contrario, el siguiente node es el padre
     elnodo = elnodo.parent();
  }
  return *this;
}

template <class Key, class T>
inline pair<Key, T> BST<Key, T>::iterator::operator*() const
{
  return *elnodo;
}


template <class Key, class T>
inline 
bool BST<Key, T>::iterator::operator==(const BST<Key, T>::iterator &i) const
{
  return elnodo == i.elnodo;
}

template <class Key, class T>
inline 
bool BST<Key, T>::iterator::operator!=(const BST<Key, T>::iterator &i) const
{
  return !(*this == i);
}

template <class Key, class T>
inline 
typename BST<Key, T>::iterator & 
BST<Key, T>::iterator::operator=(const BST<Key, T>::iterator &i)
{
  elnodo = i.elnodo;
  return *this;
}


template <class Key, class T>
inline 
BST<Key, T>::iterator::iterator(const typename BST<Key, T>::iterator & i)
  : elnodo(i.elnodo)
{
}
