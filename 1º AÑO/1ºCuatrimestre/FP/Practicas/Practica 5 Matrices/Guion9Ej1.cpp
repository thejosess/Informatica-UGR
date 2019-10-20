//Guión 9 Ejercicio 1

#include <iostream>
using namespace std;


int main ()
{
	const int MAX_FIL= 20, MAX_COL = 20, MAX = 10; 
	
	int m[MAX_FIL][MAX_COL], utilf_m, utilc_m, media[MAX], util_media, media_ord[MAX], aux[MAX_FIL], izda, tmp;
	
	bool cambio;
	
	cout << "Introduzca el numero de filas de la matriz: ";				// Lectura de la matriz
	cin >> utilf_m;
	
	cout << "\nIntroduzca el numero de columnas de la matriz: ";
	cin >> utilc_m;
	
	util_media = utilf_m;
	
	for (int i = 0; i < util_media; i++)					// Rellenado del vector de medias con ceros para poder operar con ella 
	{
		media[i] = 0;
	}
	
	for (int i = 0; i < utilc_m; i++)						// Rellenado de la matriz
	{
		for (int j = 0; j < utilf_m; j++)
		{
			cout << "\nIntroduzca el numero de la posicion " << i << "," << j << ": ";
			cin >> m[i][j];
		}
	}
	
	for (int i = 0; i < utilc_m; i++)					// Obtención del vector de medias, necesario para saber en qué columnas se halla  
	{
		for (int j = 0; j < utilf_m; j++)
		{
			media[i] = media[i] + m[i][j]; 
		}
		
		media[i] = media[i] / utilf_m;	
	}
	
	for (int i = 0; i < util_media; i++)				// Copia del vector de medias a otro que será ordenado posteriormente.
	{
		media_ord[i] = media[i];
	}
	
	cambio = true; 										// Obtención del vector de medias ordenadas
	
    for (izda = 0; izda < util_media && cambio; izda++)   	
    {                                             
        cambio = false;         
		            
        for (int i = util_media-1 ; i > izda ; i--)    
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
    
    for (int i = 0; i < utilc_m; i++)										// Proceso de ordenación de la matriz
    {
    	cambio = false;
    	
    	if (media[i] != media_ord[i])										// Condición que nos indica si ya está ordenada o no
    	{
    		for (int k = i + 1; k < util_media && cambio == false; k++)		// Obtención de la siguiente fila que hay que colocar
    		{   				
    			if (media[k] == media_ord[i])
    			{
    				tmp = k;
    				cambio = true;
				}
			}
			for (int k = 0; k < utilf_m; k++)								// Vertido del contenido de la matriz en el vector auxiliar y sustitución por la fila que hay que colocar
			{
				aux[k] = m[tmp][k];
				m[tmp][k] = m[i][k];
				m[i][k] = aux[k];			
			}
		}
	}
	
	cout << "\nLa matriz ha sido ordenado de acuerdo a las medias de sus filas" << endl;
	
	for (int i = 0; i < utilc_m; i++)												// Impresión por pantalla de la matriz 
	{
		for (int j = 0; j < utilf_m; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}
