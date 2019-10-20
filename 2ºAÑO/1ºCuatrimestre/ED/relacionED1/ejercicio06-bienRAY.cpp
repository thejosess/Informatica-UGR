#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class cola
{
private:
	stack<T> primera;
	stack<T> segunda;
public:
	void push(const T& elemento)
	{
		primera.push(elemento);
	}

	void pop()
	{
		if(segunda.empty())
			while(!primera.empty())
			{
				segunda.push(primera.top());
				primera.pop();
			}

		segunda.pop();
	}

	bool empty()
	{
		return primera.empty() && segunda.empty();
	}

	int size()
	{
		return segunda.size() + primera.size();
	}

	T front()
	{
		if(segunda.empty())
			while(!primera.empty())
			{
				segunda.push(primera.top());
				primera.pop();
			}

		return segunda.top();
	}

	T back()
	{
		if(primera.empty())
			while(!segunda.empty())
			{
				primera.push(segunda.top());
				segunda.pop();
			}

		return primera.top();
	}
};

template <typename T>
void insertar(cola<T> &P, int pos, const T &x)
{
	if(pos == P.size())
		P.push(x);
	else
		for(int i = 0; i < P.size(); i++)
		{
			if(i == pos)
				P.push(x);
			else
			{
				P.push(P.front());
				P.pop();
			}
		}
}

bool palindromo(string cad)
{
	bool pal = true;
	stack<char> pila;
	cola<char> cola;

	for(int i = 0; i < cad.size(); i++)
	{
		cola.push(cad[i]);
		pila.push(cad[i]);
	}

	while(!pila.empty() && pal)
	{
		if(pila.top() != cola.front())
			pal = false;

		pila.pop();
		cola.pop();
	}

	return pal;
}

void salida(string cad)
{
	if(palindromo(cad))
		cout << endl << "La cadena: \"" << cad << "\" SI es un palindromo" << endl;
	else
		cout << endl << "La cadena: \"" << cad << "\" NO es un palindromo" << endl;
}

int main()
{
	cout << endl << "\tEJERCICIO 4 USANDO COLA EN VEZ DE QUEUE" << endl;

	cola<int> cola, original;
	int i = 0;

	while(cola.size() != 10)
	{
		if(i != 5 && i != 8)
			cola.push(i);
		i++;
	}

	original = cola;

	cout << "\nCOLA ORIGINAL:\n" << endl;

	while(!original.empty())
	{
		cout << original.front() << endl;
		original.pop();
	}

	insertar(cola, 5, 5);
	insertar(cola, 8, 8);
	cout << "\nCOLA INSERTANDO EL '5' y el '8':\n" << endl;

	while(!cola.empty())
	{
		cout << cola.front() << endl;
		cola.pop();
	}

	cout << endl << "\tEJERCICIO 5 USANDO COLA EN VEZ DE QUEUE" << endl;

	string primera = "hola";
	string segunda = "oso";
	string tercera = "rajar";
	string cuarta = "que tal";
	string quinta = "rayar y rayar";

	salida(primera);
	salida(segunda);
	salida(tercera);
	salida(cuarta);
	salida(quinta);
}
