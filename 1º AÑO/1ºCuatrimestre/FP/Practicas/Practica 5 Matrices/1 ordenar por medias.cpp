/* Ordenar filas de una mtatriz por su media */



#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	
	int const max_fil=5;
	int const max_col=4;
	
	int matriz[max_fil][max_col]={ {1,5,32,5} , {3,22,8,4}, {5,0,10,9}, {1,20,17,8}, {16,11,0,2} };

	double media1=0,media2=0,media3=0,media4=0,media5=0;
	int suma=0;

	cout<<"La matriz inicial es: "<<endl;
	
		for(int i=0;i<max_fil;i++){
			cout<<"| ";
			for(int j=0;j<max_col;j++){
				cout<<matriz[i][j]<<" ";
			}
			cout<<"|"<<endl;
		}


	//Media primera fila
	for(int j=0;j<max_col;j++){
		suma=suma+matriz[0][j];
	}
	media1=suma/(max_col*1.0);
	suma=0;
	
	//Media segunda fila
	for(int j=0;j<max_col;j++){
		suma=suma+matriz[1][j];
	}
	media2=suma/(max_col*1.0);
	suma=0;
	
	//Media tercera fila
	for(int j=0;j<max_col;j++){
		suma=suma+matriz[2][j];
	}
	media3=suma/(max_col*1.0);
	suma=0;
	
	//Media cuarta fila
	for(int j=0;j<max_col;j++){
		suma=suma+matriz[3][j];
	}
	media4=suma/(max_col*1.0);
	suma=0;
	
	//Media quinta fila
	for(int j=0;j<max_col;j++){
		suma=suma+matriz[4][j];
	}
	media5=suma/(max_col*1.0);
	suma=0;
	
	cout<<"Las medias de las filas (de arriba a abajo) son: "<<
	media1<<", "<<media2<<", "<<media3<<", "<<media4<<" y "<<media5<<endl;
	

	
}

