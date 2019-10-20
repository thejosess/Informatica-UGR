#include <iostream>

using namespace std;

void leerVector(int vector[], int util_v)
{
	for(int i=0; i<util_v; i++){
		
		cout << "Introduce el vector (posicion " << i << " ): ";
		cin >> vector[i];
	}
}

int main()
{
	const int MAX = 10000;
	int vectorsito[MAX];
	int utilete;
	
	cout << "Cuantos numeros tiene el vector de enteros: ";
	cin >> utilete;
	
	int unos_consecutivos=0;
	int posicion_de_la_secuencia_de_unos_mas_larga=10001;
	int longitud_de_secuencia_de_unos_mas_larga=0;
	
	leerVector(vectorsito, utilete);
	
	for(int i=0; i<utilete; i++){
		
		if(vectorsito[i]==1){
		
			if(unos_consecutivos == 0 && posicion_de_la_secuencia_de_unos_mas_larga == 10001){
				posicion_de_la_secuencia_de_unos_mas_larga=i;	
			}
			
			unos_consecutivos++;
			
		}
		else{
			
			if(unos_consecutivos != 0 && unos_consecutivos > longitud_de_secuencia_de_unos_mas_larga){
					longitud_de_secuencia_de_unos_mas_larga = unos_consecutivos;
					posicion_de_la_secuencia_de_unos_mas_larga = i - longitud_de_secuencia_de_unos_mas_larga;
			}
			unos_consecutivos = 0;
		}
		
		//EXCEPCION PARA LA ZORRA DE RAY
		
		if(i==utilete-1 && vectorsito[i] == 1){
			longitud_de_secuencia_de_unos_mas_larga = unos_consecutivos;
			posicion_de_la_secuencia_de_unos_mas_larga = i+1 - longitud_de_secuencia_de_unos_mas_larga;
		}
	}
	
	if(posicion_de_la_secuencia_de_unos_mas_larga == 10001){
		
		cout << "No hay ninguna secuencia de unos en el vector";
	}
	else{
		cout << "La secuencia de unos mas larga mide: " << longitud_de_secuencia_de_unos_mas_larga << "  y empieza en la posicion " << posicion_de_la_secuencia_de_unos_mas_larga;
	}

	
}

