/*
	Implementa la clase vector dinámico usando como representación el tipo list.
	¿Qué orden de eficiencia tiene cada operación?
*/
#include <iostream>
#include <list>

using namespace std;

class VectorDinamico{

private:
	list<int>v;
	int capacidad;

public:
	VectorDinamico(int p_capacidad) :capacidad(p_capacidad){
	}

	void aniade(int elemento){
		if (v.size() < capacidad)
		v.push_back(elemento);
	}

	int getElemento(int indice){
		auto wi = v.begin();
		if(indice<v.size())
			for(int i=0 ; i<indice ; ++i)
				++wi;

		return *wi;	
	}

	int size(){
		return v.size();
	}

	bool empty(){
		return size()==0;
	}

	void toString(){
		auto wi = v.begin();
		for(wi; wi != v.end() ; ++wi)
			cout << *wi << " ";	
	}

	int getCapacidad(){
		return capacidad;
	}
};


int main(){

	VectorDinamico vector(15);
	int n;

	cout << "Introduzca datos para el vector: (<0 para acabar) " << endl;
	cin >> n ;

	while(n >= 0 && vector.size()< vector.getCapacidad() ){
		vector.aniade(n);
		cout << "Añada un nuevo numero: (<0 para acabar) " << endl;
		cin >> n;
	}

	if(vector.empty())
		cout << "El vector esta vacio " << endl ;
	else{
		cout << "Vector: " << endl;
		vector.toString();
	}

	cout << endl << endl;

	cout << "El tamanio del vector es: " << vector.size() << endl;

	cout << endl << endl;
}



