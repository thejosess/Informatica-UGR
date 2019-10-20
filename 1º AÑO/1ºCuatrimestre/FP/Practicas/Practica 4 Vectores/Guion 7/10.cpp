//programa que lea caracteres y diga cual es el que mas se repite ;
#include <iostream>
using namespace std;
int main(){
	
	const int MAX=1000;
	char v[MAX];
	int util_v;
	int contador=1,mayor=1,g=0;
	bool SeRepite;
	char elemento;
	
	do {
		cout<<"Cuantos elementos tiene el vector:";
		cin>>util_v;
	}while(util_v<0&&util_v>MAX);
	
	for(int i=0;i<util_v;i++){
	 cout<<"Introducir elemento:";
	 cin>>v[i];}
	
	 for(int i=0;i<util_v;i++){
		SeRepite=false;
		contador=1;
		 for(int j=0;j<i;j++){
			  if(v[i]==v[j]){
				 contador=contador+1;}
		 }//comprobar si se repite el char y cuantas veces
        if(contador>mayor){
       		 mayor=contador;
       		 elemento=v[i];
       		}
}
	 	
    cout<<"El elemento que mas se repite es: "<<elemento<<" y se repite:"<<mayor<<" veces.";
}
