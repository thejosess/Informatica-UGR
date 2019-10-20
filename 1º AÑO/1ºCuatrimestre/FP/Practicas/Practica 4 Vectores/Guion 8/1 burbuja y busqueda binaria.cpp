/* 1. Realizar un programa que lea un vector de enteros y los ordene utilizando el método de la burbuja. El
programa también leerá un entero y lo buscará en el vector ordenado utilizando el método de búsqueda
binaria. */



#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	
	int const MAX=100;
	bool cambio=true;
	int vector[MAX];
	int total_utilizados;
	int intercambia;
	
	cout<<"Introducir longitud del vector: ";
	cin>>total_utilizados;
	
	for(int i=0;i<total_utilizados;i++){
		cout<<"Introducir "<<i+1<<" numero: ";
		cin>>vector[i];
	}
	
	
	
	//Metodo busqueda burbuja
	

	for (int izda = 0; izda < total_utilizados && cambio; izda++){
		cambio = false;
		for (int i = total_utilizados-1 ; i > izda ; i--){
			if (vector[i] < vector[i-1]){
					cambio = true;
					intercambia = vector[i];
					vector[i] = vector[i-1];
					vector[i-1] = intercambia;
			}
		}
	}
	
	cout<<"El vector ordenado es: "<<endl<<"( ";
	
	for(int i=0;i<total_utilizados;i++){
		cout<<vector[i]<<" ";
	}
	cout<<")"<<endl;
	
	
	
	//busqueda binaria
	
	int izda = 0;
	int dcha = total_utilizados - 1;
	int centro,pos_encontrado,buscado;
	bool encontrado = false;
	
	cout<<"Introducir digito a buscar: ";
	cin>>buscado;
	
	while (izda <= dcha && !encontrado){
		
		centro = (izda + dcha) / 2;
	
		if (vector[centro] == buscado)
			encontrado = true;
		else if (buscado < vector[centro])
			dcha = centro - 1;
		else
			izda = centro + 1;
	}

	if (encontrado){
		pos_encontrado = centro;
		cout<<"El numero esta en la posicion: "<<pos_encontrado;
	}
	
	else
		cout<<"No encontrado";

	
}


