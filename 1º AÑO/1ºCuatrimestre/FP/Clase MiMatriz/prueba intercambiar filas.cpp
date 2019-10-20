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
	
	const int MAX = 10;
	int v[MAX] , util_v	, numero , vector , selectc, fila1 = 1 , fila2 = 2 , temp;
	

	
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

	cout << "\nIntroducir fila 1 a intercambiar : \n" ;
	cin >> fila1 ;
	
	cout << "Introducir fila 2 a intercambiar : " ;
	cin >> fila2 ;

		temp ;
		fila1 -- ;
		fila2 -- ;
		
		for ( int i =0 ;i < util_col ; i ++) {
		
			temp = matriz [fila1][i] ;
			matriz[fila1][i] = matriz[fila2][i] ;
			matriz[fila2][i] = temp ;
		}
		cout << "Se intercambian las filas : " << fila1+1 << "y" << fila2 + 1 << endl;		
	
		
		cout<<"La matriz convertida es: "<<endl;
	
		for(int i=0;i<util_fil;i++){
			cout<<"| ";
			for(int j=0;j<util_col;j++){
				cout<<matriz[i][j]<<" ";
			}
			cout<<"|"<<endl;
		}
	cout<<endl;
		
}
