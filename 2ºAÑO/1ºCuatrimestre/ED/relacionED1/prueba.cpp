#include <iostream>
#include <string>
#include <queue>
#include <stack>


using namespace std;

int main()
{

	stack<int> cola;
	stack<int> pila2;
	queue<int> c1;

	cola.push(3);
	cola.push(2);
	c1.push(3);
	c1.push(2);

	c1.pop();

	if(cola.size() != 1)
	{
		while(!cola.size())
		{
			pila2.push(cola.top());
			cola.pop();
		}

			pila2.pop();
	}
			
	else
	{
		cola.pop();
	}

	stack<int> *puntero ;
	puntero = &c1 ;

	cout << *puntero.front() << endl ;


}