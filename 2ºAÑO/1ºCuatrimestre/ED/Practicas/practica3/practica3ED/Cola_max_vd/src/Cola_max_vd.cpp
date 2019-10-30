#include "Cola_max_vd.h"

template <typename T>
Cola_max<T>::Cola_max(const Cola_max<T> &c1) //colas de distinto template?? poner aqui template??
{
	this->cola = c1.cola ;
}

template <typename T>
void Cola_max<T>::push(const T& elemento)
{
	if(cola.size() == 0)
		cola.addElemento(make_pair(elemento, elemento));
	else
	{
		if(elemento > cola[cola.size() - 1].second)
			for(int i = 0; i < cola.size(); i++)
				if(cola[i].second < elemento)
					cola[i].second = elemento;

		cola.addElemento(make_pair(elemento, elemento));
	}
}

template <typename T>
void Cola_max<T>::pop()
{
	cola.rmElemento(0);
}

template <typename T>
T Cola_max<T>::front()
{
	return cola[0].first ;
}

template <typename T>
T Cola_max<T>::back()
{
	return cola[cola.size() - 1].first ;
}

template <typename T>
int Cola_max<T>::size()
{
	return cola.size();
}

template <typename T>
bool Cola_max<T>::empty()
{
	return cola.empty();
}