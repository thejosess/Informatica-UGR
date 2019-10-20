/*7. Realizar un programa que inserte un vector dentro de otro a partir de una posición determinada. */

#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	const int MAX=1000;
	int v1[MAX];
	int v2[MAX];
	int v_alm[MAX];
	int util_v1, util_v2, pos,k=0;

	
//Lectura PRIMER vector

	do{
	cout<<"Introducir numero de digitos del primer vector: ";  
	cin>>util_v1;
	} while(util_v1<=0);
	
	
	for(int i=0; i<util_v1;i++){
		cout<<"Introducir "<<i+1<<" numero del primer vector: ";			
		cin>>v1[i];
	}
	
	cout<<endl;
	cout<<"Introducir la posicion en la que se quiere insertar el siguiente vector: ";
	cin>>pos;
	cout<<endl;
	
	//Lectura SEGUNDO vector

	do{
	cout<<"Introducir numero de digitos del segundo vector: ";  
	cin>>util_v2;
	} while(util_v2<=0);
	
	
	
	
	for(int i=0; i<util_v2;i++){
		cout<<"Introducir "<<i+1<<" numero del segundo vector: ";			
		cin>>v2[i];
	}
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	

	for(int i=pos-1;i<(pos-1+util_v2);i++){
	
		v1[i+util_v2]=v1[i];									//se desplazan los elemntos del primer vector
			
			v1[i]=v2[k];										//se meten los elementos del segundo vetor en el primero
			k++;
		
	}
	
	cout<<"El nuevo vector es: "<<endl<<"( ";
	
	for(int k=0;k<(util_v1+util_v2);k++){
		cout<<v1[k]<<"  ";		
	}
	
	cout<<" )";
	

		
}
