/*
	CRIBA DE ERASTOTENES
*/

#include <iostream>

using namespace std;

void MostrarVector(int vector[], int util_v){
	
	cout << "El vector es: ";
	for(int i=0; i<util_v; i++){
		
		cout << vector[i] << " ";
	}
	cout << endl;
}

int main(){
	
	const int MAX=100000;
	int natural;
	int vector[MAX];
	int util_v;
	int pos_ultimo_entero_no_tachado;
	bool fin=false;
	
	do{
		cout << "Introduce un natural: ";
		cin >> natural;
	}while(natural < 0);
	
	//Generamos el vector con todos los numeros compendidos entre natural y 2
	util_v = natural-1;
	
	for(int i=0; i<util_v; i++){
		vector[i]=i+2;	
	}
	//Lo mostramos para ver que se ha generado bien
	MostrarVector(vector,util_v);
	
	//Ahora recorremos el vector y vamos "tachando" las coincidencias
	pos_ultimo_entero_no_tachado = 0;
	
	while(!fin){

		for(int i=pos_ultimo_entero_no_tachado; i<util_v-1; i++){
			
			if(vector[i+1] % vector[pos_ultimo_entero_no_tachado] == 0){
				vector[i+1] = -1;
			}	
		}
		
		for(int i=pos_ultimo_entero_no_tachado+1; i<util_v; i++){
			
				if(i == util_v-1){
						fin = true;
					}
					
				if(vector[i] != -1){
					pos_ultimo_entero_no_tachado = i;
					cout << "Numero siguiente encontrado: " << vector[pos_ultimo_entero_no_tachado] << endl;
					
					i=util_v+1;  //SALIMOS DEL FOR
				}
		}
		
		
		
		MostrarVector(vector,util_v);
	}
	
	for(int i=0; i<util_v; i++){
		
		if(vector[i]==-1){
			
			for(int j=i; j<util_v-1; j++){
				
				vector[j]=vector[j+1];
			}
			util_v--;
			i--;
		}
	}
	
	cout << "El vector al final queda: ";
	MostrarVector(vector,util_v);
	
}
