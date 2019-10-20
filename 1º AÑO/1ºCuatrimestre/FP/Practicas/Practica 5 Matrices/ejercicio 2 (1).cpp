#include <iostream>
using namespace std ;

int main (){
	
    const int MAX_FIL = 100, MAX_COL = 100;

    bool colrep , colunica;
    int i, j, k , cu , FilEncontrado, ColEncontrado;
    double m[MAX_FIL][MAX_COL];
    int f, c;

cu=0;

    do{
        cout << "Introducir el numero de filas: ";
        cin >> f;
    }while ( (f<1) || (f>MAX_FIL) );

    do{
       cout << "Introducir el numero de columnas: ";
       cin >>c;
    }while ( (c<1) || (c>MAX_COL) );


	for(i=0;i<f;i++){
		for(j=0;j<c;j++){
			cout<<"Introduce el "<<j+1<<" valor de la "<<i+1<<" fila: ";
			cin>>m[i][j];
		}
	}
	for(j=0;j<c;j++){
		colunica=true;
		for(k=0;k<c;k++){
			colrep=true;
			for(i=0;i<f;i++){
				if(m[i][j]!=m[i][k]){
					colrep=false;
				}
				if(colrep==true&&j!=k){
					colunica=false;
				}
			}
		}
		if(colunica==true){
			cu++;
		}
	}
	cout<<"El numero de columnas unicas es: "<<cu;
}
