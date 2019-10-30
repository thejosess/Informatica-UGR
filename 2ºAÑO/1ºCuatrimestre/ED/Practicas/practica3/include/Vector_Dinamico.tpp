#include <cassert>

#include "Vector_Dinamico.h"

template <class T>
Vector_Dinamico<T>::Vector_Dinamico(int n){
  assert(n>=0);
  if (n>0)
    datos = new T[n];
  nelementos = n;
}

template <class T>
Vector_Dinamico<T>::Vector_Dinamico(const Vector_Dinamico<T> & original){
  nelementos = original.nelementos;
  if(nelementos>0){
    datos = new T[nelementos];
    for(int i=0; i<nelementos; i++)
      datos[i] = original.datos[i];
  }
  else
    nelementos = 0;
}

template <class T>
Vector_Dinamico<T>::~Vector_Dinamico(){
  if (nelementos>0)
    delete []datos;
}

template <class T>
int Vector_Dinamico<T>::size() const{
  return nelementos;
}

template <class T>
void Vector_Dinamico<T>::resize(int n){
  assert(n>=0);
  if(n != nelementos){
    if (n!=0){
      T* nuevos_datos = new T[n];
      if (nelementos>0){
        int minimo = n<nelementos?n:nelementos;
        for(int i=0; i<minimo; i++)
          nuevos_datos[i] = datos[i];
        delete[] datos;
      }
      nelementos = n;
      datos = nuevos_datos;
    }
    else{ //Si n==0
      if(nelementos>0)
        delete[] datos;
      datos = 0;
      nelementos=0;
    }
  }
}

template <class T>
T& Vector_Dinamico<T>::operator[](const int i){
  assert(i>=0 && i<nelementos);
  return datos[i];
}

template <class T>
const T& Vector_Dinamico<T>::operator[](const int i)const{
  assert(i>=0 && i<nelementos);
  return datos[i];
}

template <class T>
Vector_Dinamico<T>& Vector_Dinamico<T>::operator=(const Vector_Dinamico<T> &original){
  if (this != &original)
    if (nelementos>0)
      delete[] datos;
  nelementos = original.nelementos;
  if (nelementos>0){
    datos = new T[nelementos];
    for(int i=0; i<nelementos; i++)
      datos[i] = original.datos[i];
  }
  return *this;
}

template <class T>
void Vector_Dinamico<T>::addElemento(const T& elemento)
{
  this->resize(this->size() + 1);

  datos[this->size() - 1] = elemento;
}

template <class T>
void Vector_Dinamico<T>::rmElemento(const T& elemento)
{
  int pos = buscar(elemento);

  if(pos != -1)
  {
    for (int i = pos; i < nelementos - 1; i++)
    {
      datos[i] = datos[i + 1];
    }

    this->resize(this->size() - 1);
  }
}

template <class T>
int Vector_Dinamico<T>::buscar(const T& elemento) const
{
  int pos = -1;
  bool encontrado = false;

  for (int i = 0; i < nelementos && !encontrado; i++)
  {
    if (datos[i] == elemento)
    {
      encontrado = true;
      pos = i;
    }
  }

  return pos;
}
