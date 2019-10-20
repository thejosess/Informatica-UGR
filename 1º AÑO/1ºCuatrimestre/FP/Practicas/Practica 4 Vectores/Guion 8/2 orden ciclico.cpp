/* 2. Realizar un programa que vea un vector de reales y compruebe si está ordenado de forma cíclica.
Ejemplo: 7 9 11 15 18 100 1 3 5 6 */



#include <iostream>
#include <cmath>

using namespace std;


int main()
{

	int const MAX=100;
	int v[MAX];
	int util_v, ruptura;
	bool secuencia=true;


	cout<<"Introducir longitud del vector: ";
	cin>>util_v;
	
	for(int i=0;i<util_v;i++){
		cout<<"Introducir "<<i+1<<" numero: ";
		cin>>v[i];
	}


	int i=0;

		while(i<util_v-1 && secuencia){
			
			if(v[i]<v[i+1])
				secuencia=true;
			else 
				secuencia=false;
				ruptura=i+1;
			
			if(!secuencia){
				if(v[ruptura]<v[ruptura+1])
					secuencia=true;
			}
		
			i++;
		}
		
		if(secuencia)
			cout<<"Esta ordenado de forma ciclica";
		else
			cout<<"No esta ordenado de forma ciclica";
			
	
	

	
}


