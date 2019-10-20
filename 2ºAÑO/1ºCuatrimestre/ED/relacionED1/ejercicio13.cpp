#include <iostream>
#include <string>
#include <queue>
#include <stack>


using namespace std;

int contarVocales(string cad)
{
	int contador = 0;

	for(int i = 0 ; i < cad.size() ; i++)
	{
		if(tolower(cad[i]) == 'a' || tolower(cad[i]) == 'e' || tolower(cad[i]) == 'i' || tolower(cad[i]) == 'o' || tolower(cad[i]) == 'u')
			contador++;
	}
	return contador;
}

/**
* @brief funtor que con el criterio de ordenacion segun la cantidad de vocales y en caso de igualdad es en orden alfabetico
* @param la pila ha insertar, la posicion y el valor
* @author Jose Santos Salvador
*/
class prioridad
{
public:
	bool operator() (string cad1, string cad2)
	{
		int tam_cad1 = contarVocales(cad1);
		int tam_cad2 = contarVocales(cad2);

		if(tam_cad1 == tam_cad2)
		{
			if(cad1[0] < cad2[0])
				return true;
			else
				return false;
		}

		if(tam_cad1 < tam_cad2)
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
	cad1 = "ae" ;
	cad2 = "aeio" ;
	cad3 = "beio" ;

	cola.push(cad1);
	cola.push(cad2);
	cola.push(cad3);

	while(!cola.empty())
	{
		// el simbolo de primero, segundo, etc , puede dar errores entre versiones
		// de window o ubuntu, este ha sido realizado con ubuntu 18
		cout << "\n" << contador << "º" << endl;
		cout << cola.top() << endl;
		cola.pop() ;
		contador++;
	}
}
