#include <iostream>
using namespace std ;

int main ()
{
	const int MAX_FIL = 100 , MAX_COL = 100 , MAX = 100;
	int m[MAX_FIL][MAX_COL] , util_fil , util_col  , i , j , fila , tmp , aux[MAX]  ;
	bool cambio ;
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
		
	for ( i = 0 ; i < util_fil ; i ++ )
	{
		for	( j = 0 ; j < util_col ; j ++)
			{
				media[i] = media[i] + m[i][j] ;
			}
			
		media[i] = media[i] / util_col ;
	}
	
	for (int i = 0; i < util_fil; i++)				// Copia del vector de medias a otro que será ordenado posteriormente.
	{
		media_ord[i] = media[i];
	}
	
	cambio = true ;

    for (int izda = 0; izda < util_fil && cambio; izda++)   	
    {                                             
        cambio = false;         
		            
        for (int i = util_fil - 1 ; i > izda ; i--)    
		{  
            if (media_ord[i] < media_ord[i-1])                   
            {                                   
	            tmp = media_ord[i];                     
	            media_ord[i] = media_ord[i-1];                  
	            media_ord[i-1] = tmp;                   
				cambio = true;                  
        	}
    	}
    } 
	
	for ( int i  = 0 ; i < util_fil ; i++)
		cout << "   " << media_ord[i] ;
	
	for (int i = 0; i < util_fil  ; i++)										// Proceso de ordenación de la matriz
    {
    	cambio = false;
    	
    	if (media[i] != media_ord[i])										// Condición que nos indica si ya está ordenada o no
    	{
    		cout << "\n veces que hace el cambio \n " << 1 << endl ;
    		for (int k = i + 1; k < util_fil + 1 && cambio == false; k++)		// Obtención de la siguiente fila que hay que colocar
    		{   				
    			if (media[k] == media_ord[i])
    			{
    				tmp = k;
    				cambio = true;
				}
			}
			for (int k = 0; k < util_col ; k++)								// Vertido del contenido de la matriz en el vector auxiliar y sustitución por la fila que hay que colocar
			{
				aux[k] = m[tmp][k];
				m[tmp][k] = m[i][k];
				m[i][k] = aux[k];			
			}
		}
	}
		/* EL PUTO PROBLEMA DE LOS COJONES ERAN LOS DECIMALES SU PUTA MADRE , EL VECTOR SE TENDRIA QUE HACER DOUBLE O QUE SE YO */
		/* NO HACE BIEN LAS MATRICES QUE TIENEN 5 FILAS */
		/* cuando pones columna 4  */
		/*Creo que el problema esta en la ultima pasada */
	
	cout<<"\n La matriz ordenada es: "<<endl;
	
		for(int i=0;i<util_fil;i++){
			cout<<"| ";
			for(int j=0;j<util_col;j++){
				cout << m[i][j]<<" ";
			}
			cout<<"|"<<endl;
		}
	
	
}	
