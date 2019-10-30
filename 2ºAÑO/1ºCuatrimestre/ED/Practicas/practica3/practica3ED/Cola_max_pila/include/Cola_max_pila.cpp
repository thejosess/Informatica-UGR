#include "Cola_max_pila.h"

template <typename T>
Cola_max<T>::Cola_max(const Cola_max<T> &c1) //colas de distinto template?? poner aqui template??
{
	this->cola = c1.cola ;
}

template <typename T>
void Cola_max<T>::push(const T& elemento)
{
	if(primera.empty())
		while(!segunda.empty())
		{
			primera.push(segunda.top());
			segunda.pop();
		}

	if(primera.size() == 0)
		primera.addElemento(make_pair(elemento, elemento));
	else
	{
		if(elemento > primera.top().second)
			while(!primera.empty())
			{
				segunda.push(primera.top());
				primera.pop();
			}

			while(!segunda.empty())
			{
				if(segunda.top().second < elemento)
					primera.push(make_pair(segunda.top().first,elemento));
				else
					primera.push(segunda.top());

				segunda.pop();
			}

		primera.push(make_pair(elemento, elemento));
	}
}

template <typename T>
void Cola_max<T>::pop()
	{
		if(segunda.empty())
			while(!primera.empty())
			{
				segunda.push(primera.top());
				primera.pop();
			}

		segunda.pop();
	}


template <typename T>
T Cola_max<T>::front()
{
	if(segunda.empty())
		while(!primera.empty())
		{
			segunda.push(primera.top());
			primera.pop();
		}

	return segunda.top().first;
}

template <typename T>
T Cola_max<T>::back()
{
	if(primera.empty())
		while(!segunda.empty())
		{
			primera.push(segunda.top());
			segunda.pop();
		}

	return primera.top().first;
}

template <typename T>
int Cola_max<T>::size()
{
	return segunda.size() + primera.size();
}

template <typename T>
bool Cola_max<T>::empty()
{
	return primera.empty() && segunda.empty();
}

template <typename T>
T Cola_max<T>::maximo()
{
	if(segunda.empty())
		while(!primera.empty())
		{
			segunda.push(primera.top());
			primera.pop();
		}
	return segunda.top().second;
}

	