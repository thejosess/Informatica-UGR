/*
Implementa un TDA cola usando como representación dos pilas
*/

#include <iostream>
#include <stack>

using namespace std;

template<typename T>

class Cola{
private:

	stack<T> pila, pila_aux;

public:

	bool empty() const{
		return pila.empty();
	}

	size_t size() const{
		return pila.size();
	}
	
	T& back(){
		return pila.top();
	}

	const T& back() const{
		return pila.top();
	}

	T& front(){
		while (!pila.empty()){
			pila_aux.push(pila.top());
			pila.pop();
		}
		T& devolver = pila_aux.top();
		while (!pila_aux.empty()){
			pila.push(pila_aux.top());
			pila_aux.pop();
		}
		return devolver;
	}

	const T& front() const{
		while (!pila.empty()){
			pila_aux.push(pila.top());
			pila.pop();
		}
		T& devolver = pila_aux.top();
		while (!pila_aux.empty()){
			pila.push(pila_aux.top());
			pila_aux.pop();
		}
		return devolver;
	}

	void pop(){
		while (!pila.empty()){
			pila_aux.push(pila.top());
			pila.pop();
		}
		pila_aux.pop();
		while (!pila_aux.empty()){
			pila.push(pila_aux.top());
			pila_aux.pop();
		}
	}

	void push(const T& nombredevariable){
		pila.push(nombredevariable);
	}
};

int main(){

	Cola<int> enteros;
	enteros.push(1);
	enteros.push(2);
	enteros.push(3);
	enteros.push(4);

	while (!enteros.empty()){
		cout << "front() " << enteros.front() << endl;
		cout << "back() " << enteros.back() << endl;
		cout << "size() " << enteros.size() << endl;

		enteros.pop();
	}
	return(0);
}
