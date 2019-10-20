/* */



#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	
	int const max_fil=100;
	int const max_col=100;
	const int MAX = 10;
	int matriz[max_fil][max_col] , util_fil,util_col , v[MAX] , util_v	, numero , vector , select;

	
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
	
	
	    
	    cout << "\n Introducir tamaño del vector , no ha de ser mayor al tamañado de filas o columnas: \n" ;
	    cin >> util_v ;
	    
	    for (int i=0; i<util_v; i++){
	    	
	        cout << "\n Introducir dato del vector a introducir en matriz : \n";
	        cin >> v[i];
	    }
	    
	    cout << "\n Introducir si se desea meter el vector en una fila(1) o columna(2) : \n" ;
	    cin >> select ;
	    
	    cout << "\n Introducir la fila o columna donde se desea introducir : \n " ;
	    cin >> numero ;
	    
	    numero = numero - 1 ;
	    
	    if ( select == 1){
	    
	    	for(int i=0; i<util_fil; i++){     
		
				for(int j=0; j<=i; j++){
					
					matriz[numero][i] = v[j] ; 		
						
				}
			}
		}
	    
	   /* if ( select == 1){
		
	    	for(int i=0; i<util_v; i++){     
		
				for(int j=util_v; j>i; j--){
					
					matriz[numero][j] = v[i] ; 		
				}
			}	
		}*/
	    										//Al dar la opccion de por filas o por columnas , si se elige de introducir en las filas, se procesa solo las columnas y se va colocando el vector
	    if ( select == 2){
	    
	    	for(int i=0; i<util_col; i++){     
		
				for(int j=0; j<=i; j++){
					
					matriz[i][numero] = v[j] ; 		
						
				}
			}
		}
		
		
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
