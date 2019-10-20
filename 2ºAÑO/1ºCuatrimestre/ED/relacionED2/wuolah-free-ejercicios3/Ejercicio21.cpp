/*
	En un servicio de urgencias de un hospital quieren tener la posibilidad de 
	poder gestionar el orden en que los pacientes se irán atendiendo. Para ello,
	de cada paciente se guarda nombre, apellidos, dni, gravedad. Al mismo tiempo
	se quiere poder acceder por dni. Construye una clase adecuada e implementa 
	las operaciones de inserción y borrado.
*/
#include <iostream>
#include <queue>
#include <map>
#include <utility>

using namespace std;

typedef struct {
	string nombre;
	string apellidos; 
	string dni;
	int gravedad;
}Paciente;

struct pri{
	bool operator()(Paciente a, Paciente b)
	{
		return (a.gravedad < b.gravedad);
	}
};

class Urgencias{

private:
	//Ordenado de mayor a menor gravedad
	priority_queue<Paciente, vector<Paciente>, pri> conjunto_pacientes;
	map<string, Paciente> buscar_por_dni;
public: 

	Paciente get_Siguiente_Paciente(){
		return conjunto_pacientes.top();
	}

	void Aniade_Paciente(Paciente c){
		conjunto_pacientes.push(c);
		buscar_por_dni.insert({c.dni,c});
	}

	void Borrar_Paciente(){
		Paciente c = conjunto_pacientes.top();
		conjunto_pacientes.pop();
		buscar_por_dni.erase(c.dni);
	}

	pair<bool,Paciente> buscar(string dni){
		pair<bool, Paciente> devolver;
		devolver.first = true;
		auto it = buscar_por_dni.find(dni);
		if(it == buscar_por_dni.end()) 
			devolver.first = false;
		else
			devolver.second = it->second;
		return devolver;
	}

	int get_Numero_Pacientes(){
		return conjunto_pacientes.size();
	}

	priority_queue<Paciente, vector<Paciente>, pri> getColaEspera(){
		return conjunto_pacientes;
	}

	bool empty(){
		return conjunto_pacientes.size()==0;
	}
	
};
ostream & operator << (ostream & os, const Paciente & c){
	os << c.nombre << " " << c.apellidos << " " << c.dni << endl;
	return os;
}
int main(){
	Urgencias pacientes;

	Paciente paciente1;
	paciente1.nombre = "Luis";
	paciente1.apellidos = "Suárez Pérez";
	paciente1.dni = "12301243N";
	paciente1.gravedad = 3;
	
	Paciente paciente2;
	paciente2.nombre = "John";
	paciente2.apellidos = "Gómez Fernández";
	paciente2.dni = "16861654L";
	paciente2.gravedad = 5;

	pacientes.Aniade_Paciente(paciente1);
	pacientes.Aniade_Paciente(paciente2);
	
	cout << "Paciente con DNI: 12301243N " << endl;
	auto wi = pacientes.buscar("12301243N");
	if (wi.first)
		cout << wi.second << endl;
	else cout << "No existe ese paciente." << endl;

	cout << "Paciente con DNI: 12341435L " << endl;
	auto we = pacientes.buscar("12341435L");
	if (we.first)
		cout << we.second << endl;
	else cout << "No existe ese paciente." << endl;

	cout << endl << endl;

	while (!pacientes.empty()) {
   		cout << pacientes.get_Siguiente_Paciente();
    	pacientes.Borrar_Paciente();
  	}

	cout << endl << endl;
}

