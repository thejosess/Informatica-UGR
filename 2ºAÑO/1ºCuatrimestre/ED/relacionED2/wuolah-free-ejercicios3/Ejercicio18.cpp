/*
	Implementa la función intercalar(vector<T> &v, vector<pair<int, T> > pos)
	que inserta el segundo elemento de cada par de pos en v en los lugares
	indicados por el primer elemento de cada par de pos
*/
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void intercalar(vector<T> &v , vector< pair<int, T> >pos){
	auto wi = v.begin();
	auto itpar = pos.begin();

	for( itpar; itpar != pos.end() ; ++itpar)

		if( itpar->first < v.size() ){

			for( int i=0; i< itpar->first ; ++i)
				++wi;

			v.insert(wi, itpar->second );		
		}
		else
			cout << "Error, posicion invalida " << endl;
}

int main(){
	vector<int> v;
	vector<pair<int,int> > posicion;

	for(int i =0 ; i<10; i++){
		v.push_back(i);
	}

	pair<int,int> pairVector(0, 5);
	posicion.push_back(pairVector);

	cout << "Vector inicial: " << endl;
	auto wi = v.begin();
	for(wi; wi != v.end(); ++wi)
		cout << *wi << " ";

	intercalar(v, posicion);

	auto wo = v.begin();
	cout << endl << endl << "Vector final: " << endl;
	for(wo; wo != v.end() ; ++wo)
		cout << *wo << " ";

	cout << endl << endl;

}
