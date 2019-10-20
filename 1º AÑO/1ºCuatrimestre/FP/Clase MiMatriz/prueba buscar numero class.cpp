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

	bool encontrado ;
	int i , j  ,entero_buscar ;
	
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
			
			cout << "Intrdoc numero a buscar" ;
			cin >> entero_buscar ;
						
			for ( i=0; i<util_fil ; i++)
			{
				
	      		for ( j=0; j<util_col ; j++)
				{
	           		if( matriz[i][j] == entero_buscar )
	           		
						{   
							           			
	           			cout << "El numero se encuentra en la posicion" << i << "," << j << endl ;
	           			
	           			}	
	           		
	           		else
							cout << "No se encuentra el numero en la matriz" << endl ;
           		}	
    		}
		
}
