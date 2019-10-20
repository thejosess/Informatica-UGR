#include <iostream>
using namespace std ;

int main ()
{
	const int MAX_FIL = 100 , MAX_COL = 100 , MAX = 100;
	int m[MAX_FIL][MAX_COL] , util_fil , util_col  , i , j , fila , tmp , cambio2[MAX]  ;
	bool cambio , cambio3  ;
	double	media[MAX] , media_ord[MAX];
	
	
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
		
	for ( i = 0 ; i < util_fil ; i ++)
	{
		media[i] = 0 ;	
	}	
	
	for ( i = 0 ; i < util_fil ; i ++)
	{
		cambio2[i] = 0 ;	
	}	
		
		
	for ( i = 0 ; i < util_fil ; i ++ )
	{
		for	( j = 0 ; j < util_col ; j ++)
			{
				media[i] = media[i] + m[i][j] ;
			}
			
		media[i] = media[i] / util_col ;
	}

   /* for (int izda = 0; izda < util_fil && cambio; izda++)   	
    {                                             
        cambio = false;         
		            
        for (int i = util_fil -1 ; i > izda ; i--)    
		{  
            if (media_ord[i] < media_ord[i-1])                   
            {                                   
	            tmp = media_ord[i];                     
	            media_ord[i] = media_ord[i-1];                  
	            media_ord[i-1] = tmp;                   
				cambio = true;                  
        	}
    	}
    } */

/*		cout << "La media primera fila es :" << media[0] << "La media de la segunda fila es :" << media[1] << endl ;
		
		cambio = true ;
		cambio3 = true ; */
					
/*	for ( i = 0 ; i < util_fil && cambio ; i ++ )
	{
		cambio = false ;
		for	( j = util_fil -1 ; j > i && cambio3 ; j --)
			{
				cambio3 = false ;
				cout << "Es la media fila " << j << " menor que " << "la fila " << j - 1 << endl ;
				cout<< "Es la media " << media[j] << " menor que " << media[j-1] << endl ;
				
				if ( media[j] < media[j-1] ) /*El problema tiene que estar en la primera pasada de la burbuja */
				//{
				/*	fila = j ;
					for ( int k = 0 ; k < util_col - 1  ; k ++)
					{
						cout << "Pene" << endl ;
						cambio = true ;
						cambio3 = true ;
						cambio2[k] = m [fila][k] ;
						m[fila][k] = m [fila-1][k] ;
						m[fila-1][k] = cambio2[k] ;
						
					}
					
					for ( int x = 0 ; x < util_fil ; x ++ )
					{
						for	( int y = 0 ; y < util_col ; y ++)
							{
								media[x] = media[x] + m[x][y] ;
							}
							
						media[x] = media[x] / util_col ;
					}
				}
			}	
	} */
	
	int intercambia;
	
	for(int j=0; j<util_fil; j++)
	{
		for(int i=util_col - 1; i>j; i--)
		{		
			if(media[i]<media[i-1])
			{
				intercambia=m[i][j];
				m[i][j]=m[i-1][j];
				m[i-1][j]=intercambia;
			}
		}
	}
	
	cout<<"La matriz ordenada es: "<<endl;
	
		for(int i=0;i<util_fil;i++){
			cout<<"| ";
			for(int j=0;j<util_col;j++){
				cout << m[i][j]<<" ";
			}
			cout<<"|"<<endl;
		}
	
	
}	
