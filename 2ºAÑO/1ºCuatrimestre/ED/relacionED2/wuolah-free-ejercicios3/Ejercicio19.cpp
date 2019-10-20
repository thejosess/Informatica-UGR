/*
	Define una clase que permita guardas los datos de los pilotos de F1. Por 
	ejemplo, nombre, apellido (solo uno), posición en la clasificación, nombre
	de la escudería. Además debe permitir que se pueda buscar a un piloto por su
	apellido. ¿Qué podríamos añadir a esa clase para que se pueda buscar también
	por cualquiera de los restantes campos?
*/
#include <iostream>
#include <string>
#include <list>
#include <utility>

using namespace std;

struct Piloto{
	string nombre;
	string apellido;
	int posClasificacion;
	string nombreEscuderia;
};

class Pilotos{
public:
	Piloto getPiloto(int pos){
		if(pos<pilotos.size() ){
			auto it = pilotos.begin();
			for( int i = 0 ; i<pos ;++i)
				++it;
			return *it;
		}
	}

	void aniade(Piloto p){
		pilotos.push_back(p);
	}

	list<Piloto>::iterator begin(){
		return pilotos.begin();
	}
	
	list<Piloto>::iterator end(){
		return pilotos.end();
	}

	int getPosClasificacion(Piloto p){
		return p.posClasificacion;
	}

	string getNombreEscuderia(Piloto p){
		return p.nombreEscuderia;
	}

	int size(){
		return pilotos.size();
	}

	bool empty(){
		return size()==0;
	}


private:
	list<Piloto> pilotos;

};


int main(){
	string nombree = "Paco";
	string apellidos = "Pérez Suárez";
	int clasificacion = 5;
	string escuderia = "Ferrari";

	Pilotos lista;
	Piloto piloto1;

	piloto1.nombre = nombree;
	piloto1.apellido = apellidos;
	piloto1.posClasificacion = clasificacion;
	piloto1.nombreEscuderia = escuderia;

	lista.aniade(piloto1);

	string nombre2 = "Alonso";
	string apellido2 = "Fernández Méndez";
	int clasificacion2 = 2;
	string escuderia2 = "McLaren";

	Piloto piloto2;

	piloto2.nombre = nombre2;
	piloto2.apellido = apellido2;
	piloto2.posClasificacion = clasificacion2;
	piloto2.nombreEscuderia = escuderia2;

	lista.aniade(piloto2);

	auto wi = lista.begin();
	for(wi; wi != lista.end(); ++wi)
		cout << "Piloto{ Nombre: " << wi->nombre << " Apellidos: " 
			 << wi->apellido << " Puesto clasificacion: " << wi->posClasificacion
			 << " Escuderia: " << wi->nombreEscuderia << "}" << endl;
	
	cout << endl << endl;
}
