#include <iostream>
#include <string>
#include <queue>
#include <stack>


using namespace std;

/**
* @brief funtor que con el criterio de ordenacion segun el tamaño de los tamaños de uns tring
* @author Jose Santos Salvador
*/
class prioridad
{
public:
	bool operator() (string cad1, string cad2)
	{
		if(cad1.size() < cad2.size())
			return true;
		else
			return false;
	}
};
int main()
{
	priority_queue<string,vector<string>,prioridad> cola;

	string cad1, cad2, cad3 ;
	int contador = 1 ;
	cad1 = "hola" ;
	cad2 = "Hola mundo" ;
	cad3 = "Hola Mundo , ¿Cómo estas?" ;

	cola.push(cad1);
	cola.push(cad2);
	cola.push(cad3);

	while(!cola.empty())
	{
		cout << "\n" << contador << "º" << endl;
		cout << cola.top() << endl;
		cola.pop() ;
		contador++;
	}
}