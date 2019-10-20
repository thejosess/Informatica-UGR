/* */



#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	
	int const max_fil=100;
	int const max_col=100;
	
	int matriz[max_fil][max_col];
	int util_fil,util_col;
	

	
	cout<<"Introducir filas de la matriz: ";
	cin>>util_fil;
	cout<<"Introducir columnas de la matriz: ";
	cin>>util_col;
	
	cout<<endl;

	
	for(int i=0; i<util_fil; i++){
		for(int j=0; j<util_col; j++){
			cout<<"Introducir "<<j+1<<" elemento de la "<<i+1<<" fila: ";
			cin>>matriz[i][j];
		}
	}

	cout<<"La matriz inicial es: "<<endl;
	
		for(int i=0;i<util_fil;i++){
			cout<<"| ";
			for(int j=0;j<util_col;j++){
				cout<<matriz[i][j]<<" ";
			}
			cout<<"|"<<endl;
		}
	cout<<endl;
	
	
	int mayor=0,fila;
	
		for(int i=0; i<util_fil; i++){
			for(int j=0; j<util_col; j++){
				if(matriz[i][j]>mayor){
					mayor=matriz[i][j];
					fila=i;
				}
			}
		}
		
		cout<<"El numero mayor es: "<<mayor<<endl;
		cout<<endl;
		
		cout<<"Su fila es: ";
		for(int j=0;j<util_col;j++){
			cout<<matriz[fila][j]<<" ";
		}
		cout<<endl;
		cout<<endl;
		
	//Ordenar la fila de la matriz
	
		bool cambio=true;
		int intercambia;
		
		for (int izda = 0; izda < util_col && cambio; izda++){
			cambio = false;
			for (int i = util_col-1 ; i > izda ; i--){
				if (matriz[fila][i] < matriz[fila][i-1]){
					cambio = true;
					intercambia = matriz[fila][i];
					matriz[fila][i] = matriz[fila][i-1];
					matriz[fila][i-1] = intercambia;
				}
			}
		}
		
		cout<<"Su fila ordenada es: ";
		for(int j=0;j<util_col;j++){
			cout<<matriz[fila][j]<<" ";
		}
		cout<<endl;	
}
