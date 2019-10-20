/*3. Realizar un programa que lea un vector de enteros positivos y busque la posición del mayor de los
primos que contiene.
*/



#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	
	const int MAX=1000;
	int mayor=0,util_v,pos;
	int v[MAX];
	bool esprimo=true;
	
	cout<<"Introducir la cantidad de numeros: ";
	cin>>util_v;
	
	for(int i=0; i<util_v; i++){
			cout<<"Introdudcir "<<i+1<<" numero: ";
			cin>>v[i];
			
			esprimo=true;
			
			for(int j=2;j<v[i];j++){
				if(v[i]%j==0)
					esprimo=false;
			
			}
		
		if(esprimo && v[i]>mayor){
		
			mayor=v[i];
			pos=i;}
		
		
	}
	
	cout<<"El primo mayor es "<<mayor<<" y su posicion es: "<<pos+1<<endl;
			
			
			
		
	

	
}

