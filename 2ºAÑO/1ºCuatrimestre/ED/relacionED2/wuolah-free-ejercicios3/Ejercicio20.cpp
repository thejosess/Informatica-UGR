/*
	Escribe un programa que permita leer de la entrada estándar una serie de
	coordenadas (como un par de float) y que contabilice de forma eficiente el
	número de veces que aparece cada uno de los pares.
*/
#include <iostream>
#include <map>
#include <utility>
using namespace std;

typedef map<pair<float,float>,int> MyMap;

int main(){
	MyMap mymap;

	float x,y;
	while (x != -1.0){
		cin >> x;
		if (x != -1.0){
			cin >> y;
			auto it = mymap.find({x,y});
			if(it == mymap.end())
				mymap.insert({{x,y},1});
			else
				++it->second;
		}
	}

	for (auto it = mymap.begin(); it != mymap.end(); ++it){
		cout << " ("  << it->first.first  << ", " << it->first.second << ") "<< it->second << " veces" << endl;
	}

	cout << endl << endl;
}
