#include <iostream>
#include <string>
#include <queue>
#include <stack>


using namespace std;

struct name
{
	string nombre;
	string apellidos;
	int prioridad;
};

/**
* @brief funtor que con el criterio de ordenacion segun el valor int del struct
* @author Jose Santos Salvador
*/
class prioridad
{
public:
	bool operator() (name nombre1, name nombre2)
	{
		if(nombre1.prioridad > nombre2.prioridad)
			return true;
		else
			return false;
	}
};
int main()
{
	priority_queue<name,vector<name>,prioridad> cola;

	name nombre1, nombre2, nombre3 ;
	int contador = 1 ;
	nombre1 = {" Jose", "Santos Salvador", 3};
	nombre2 = {" Samuel", "Jimenez Piñero", 4};
	nombre3 = {" Raul", "Soria Gonzalez", 5};

	cola.push(nombre1);
	cola.push(nombre2);
	cola.push(nombre3);

	while(!cola.empty())
	{
		cout << "\n" << contador << "º" << endl;
		cout << cola.top().apellidos << cola.top().nombre << endl;
		cola.pop() ;
		contador++;
	}
}