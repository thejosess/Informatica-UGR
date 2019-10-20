#include <iostream>
using namespace std ;

int main ()
{
	const int MAX_FIL = 100 , MAX_COL = 100 , MAX = 100;
	int m[MAX_FIL][MAX_COL] , util_fil , util_col  , i , j , util_v , izda , tmp ;
	bool cambio = true ; 
	int	v[MAX] , menor , suma , fila ;


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
		
	do{	
		cout << "Introducir numero de elementos del vector : " ;
		cin >> util_v ;
	}while( (util_v > MAX ) || ( util_v < 1 ) )  ;
	
	for ( i = 0 ; i < util_v ; i ++)
	{
		cout << "Introducir elemento " << i + 1 << " del vector : " ;
		cin >> v[i] ;	 
	}
	
	for ( izda = 0 ; izda < util_v && cambio ; izda++)
	{
		cambio = false ;
		
		for ( i = util_v - 1 ; i > izda ; i--)
		{
			if ( v[i] < v[i-1] )
			{
				cambio = true ;
				tmp = v[i] ;
				v[i] = v[i-1] ;
				v[i-1] = tmp ;
			}
		}
	}
	
	cout << "\n El vector ordenado es: \n" << endl ;
	for ( i = 0 ; i < util_v ; i++ )
	{
		cout << v[i] <<" ";
	}
	
	for ( int i = 0 ; i < util_fil ; i++)
		{
			menor = menor + m[0][i] ;
			fila = 0 ;
		}
	
	for(int i=0;i<util_fil;i++)
	{
		suma = 0 ;
		
		for(int j=0;j<util_col;j++)
		{
			suma = suma + m[i][j] ;
		}
			
		if( menor > suma )
		{
			menor = suma ;
			fila = i ;
		}	
	
	}
	
	for ( int i = 0 ; i < util_v ; i++)
		{
			m[fila][i] = v[i] ;
		}
	
	cout<<"\n La matriz finalizada es: "<<endl;
	
		for(int i=0;i<util_fil;i++){
			cout<<"| ";
			for(int j=0;j<util_col;j++){
				cout << m[i][j]<<" ";
			}
			cout<<"|"<<endl;
		}
}

