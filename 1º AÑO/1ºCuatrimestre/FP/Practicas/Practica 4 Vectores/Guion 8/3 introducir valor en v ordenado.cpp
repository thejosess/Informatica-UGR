/*3. Escribe un programa para insertar el valor de una variable x en un vector v ordenado de forma creciente,
de forma que dicho vector contin�e estando ordenado. El vector tendr� un n�mero de elementos v�lidos
que podr� ser menor que el n�mero total de elementos del vector. Si en el momento de la inserci�n el
n�mero de elementos v�lidos coincide con el n�mero total de elementos del vector, el elemento de
mayor valor desaparecer�.
*/



#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	int util_v;
	bool pos=false;
	int posicion,x;
	
	cout<<"Introducir el numero de elementos del vector: ";
	cin>>util_v;
	
	int v[util_v];
	
	for(int i=0; i<util_v; i++){
		cout<<"Introducir "<<i+1<<" numero del vector: ";
		cin>>v[i];
	}
	
	cout<<"Introducir el numero a introducir: ";
	cin>>x;

	int i=0;
	
	while(i<util_v && !pos){
		if(v[i]>x){
			pos=true;
			
			for(int j=i+1;j<util_v;j++){
				v[j]=v[j-1];
			}
			
			v[i]=x;
		}
		else
			i++;
	}
			
	if(pos){

		
		cout<<"El nuevo vector es: ( ";
		for(int i=0;i<util_v;i++){
			cout<<v[i]<<" ";
		}
		cout<<")";
			
	}
	
	
	else
		cout<<"El numerp es mayor que los elementos del vector";
}


