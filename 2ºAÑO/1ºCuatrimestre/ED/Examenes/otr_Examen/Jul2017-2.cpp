/*
	bool ordenada_ascendente(list<T> &L, list<T> & I);
*/

#include <iostream>
#include <list>

using namespace std;

int get_elemento(int pos, list<int>l)
{
	auto wi=l.begin();
	for(int i=0 ; i<pos; ++i)
		++wi;
	return *wi;
}

template<typename T>
bool ordenada_ascendente(list<T> &L, list<T> & I){
	auto wi = I.begin();
	int anterior = 0;
	bool fufa;

	for(wi; wi!= I.end();++wi){
		if(anterior <= get_elemento(*wi,L)){
			anterior = get_elemento(*wi,L);
			fufa = true;
		}
		else fufa = false;
	}
	return fufa;
}

int main(){
	list<int>lista1, lista2;

	lista1.push_back(2);
	lista1.push_back(7);
	lista1.push_back(3);
	lista1.push_back(9);
	lista1.push_back(6);
	lista1.push_back(5);
	lista2.push_back(0);
	lista2.push_back(2);
	lista2.push_back(5);
	lista2.push_back(4);
	lista2.push_back(1);
	lista2.push_back(3);
	

	if(ordenada_ascendente(lista1,lista2))
		cout << "La lista está ordenada ascendentemente" << endl;
	else
		cout << "La lista no está ordenada" << endl;
}
