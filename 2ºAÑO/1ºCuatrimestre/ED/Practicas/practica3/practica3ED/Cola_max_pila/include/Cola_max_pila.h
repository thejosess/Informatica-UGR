#ifndef COLA_MAX_PILA_H
#define COLA_MAX_PILA_H

#include "Cola_max_pila.cpp"
#include <stack>
#include <iostream>

using namespace std;

template <typename T>
class Cola_max
{
	private:

		stack<pair<T,T>> primera;
		stack<pair<T,T>> segunda;

	public:

		inline Cola_max();
		Cola_max(const Cola_max<T> &c1);
		void push(const T &elemento);
		T front();
		T back();
		int size();
		void pop();
		bool empty();
		T maximo();
};

#endif