#ifndef COLA_MAX_VD_H
#define COLA_MAX_VD_H

#include <queue>
#include <iostream>
#include "Vector_Dinamico.h"

using namespace std;

template <typename T>
class Cola_max
{
	private:

		Vector_Dinamico<pair<T,T>> cola;

	public:

		inline Cola_max(){cola.resize(0);};
		Cola_max(const Cola_max<T> &c1);
		void push(const T &elemento);
		T front();
		T back();
		inline int size(){return cola.size();};
		void pop();
		bool empty();
		inline T maximo(){return cola[0].second ;};
};

#endif