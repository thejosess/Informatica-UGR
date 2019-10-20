#include <iostream>
using namespace std ;

int main ()
{
	const int MAX_FIL = 100 , MAX_COL = 100 , MAX = 100;
	int m[MAX_FIL][MAX_COL] , util_fil , util_col  , i , j , util_v , izda , tmp ;
	bool cambio = true ; 
	int	v[MAX] , menor , suma , fila , columna , mayor , fila1 , columna1 ;


	do{	
		cout << "Introducir numero de filas : " ;
		cin >> util_fil ;
	}while( (util_fil > MAX_FIL ) || ( util_fil < 1 ) )  ;
	
	
	do{	
		cout << "Introducir numero de columnas : " ;
		cin >> util_col ;
	}while( (util_col > MAX_COL ) || ( util_col < 1 ) )  ;
	
	
	for ( i = 0 ; i < util_fil ; i++)
	{
		for( j = 0 ; j < util_col ; j++)
		{
			cout << "Introducir elemento " << i + 1 << " de la columna " << j + 1  << " : " ;
			cin >> m[i][j]	;
		}	
	}
	
	cout<<"La matriz inicial es: "<<endl;
	
		for(int i=0;i<util_fil;i++){
			cout<<"| ";
			for(int j=0;j<util_col;j++){
				cout << m[i][j]<<" ";
			}
			cout<<"|"<<endl;
		}
		
		
	util_v = util_fil ;
	mayor = -1 ;
	
	for ( i = 0 ; i < util_fil ; i++)
	{
		menor = m[i][0] ;
		fila = i ;
		columna = j ;
		
		for( j = 0 ; j < util_col ; j++)
		{
			if( menor >= m[i][j] )
			{
				menor = m[i][j] ;
				fila = i ;
				columna = j ;
			}			
		}	
		
		if (menor > mayor)
			{
				mayor = menor ;
				fila1 = fila ;
				columna1 = columna ;
			}	
	}
		
	
	cout << "El valor mas grande entre los minimos de cada fila es: " << mayor << " y esta en la pos: " << "( " <<fila1 << ", " << columna1	<< " )" << endl ;

}
