#include <iostream>
using namespace std;

class MiMatriz
{
	private:
		
		static const int MAX_FIL = 50 , MAX_COL = 50 ;
		int matriz_privada[MAX_FIL][MAX_COL];
        int util_fil;
        int util_col;
    	int fila;
        
    public :
    	
    	MiMatriz(){
		
			util_fil = 0 ;
			util_col = 0 ;
		}
		
		int Dato(int fila, int columna)
        {
            return matriz_privada[fila][columna];
        }	
		
		void AsignarDato( int fila , int columna , int dato)
			{
				matriz_privada[fila][columna] = dato ;
			}
		
		void Introd_Util_fil( int dato)
			{
				util_fil = dato ;
			}
			
		void Introd_Util_col( int dato)
			{
				util_col = dato ;
			}
			
		int Total_col()
			{
				return util_col ;
			}
		
		int Total_fil()
			{
				return util_fil ;
			}
		
		void BorrarTodos()
      		{
           		util_fil = 0;
           		util_col = 0;
       		}
		
		void Introd_Fila_ordenar ( int dato)
			{
				fila = dato ;
			}
		
		int Fila_ordenar ()
			{
				return fila - 1 ;
			}
			
		void OrdenarFila ()
		{
			
			
			bool cambio=true;
			int intercambia , dato1;
			
			for (int izda = 0; izda < Total_col() && cambio; izda++){
			cambio = false;
			for (int i = Total_col()-1 ; i > izda ; i--)
				{
				if (Dato(Fila_ordenar(),i) < Dato(Fila_ordenar(),i-1)){
					cambio = true;
					intercambia = Dato(Fila_ordenar(),i);
					dato1 = Dato(Fila_ordenar(),i-1);
					AsignarDato(Fila_ordenar(),i,dato1) ;
					AsignarDato(Fila_ordenar(),i-1,intercambia) ;
					
					}
				}	
			}
		}
		
		
		
};
	MiMatriz CompletarMatriz (){
		
	MiMatriz m ;
	int dato1, dato2;
	int valor ;

	cout<<"Introducir filas de la matriz: ";
	cin>>dato1 ;
	m.Introd_Util_fil(dato1);
	cout<<"Introducir columnas de la matriz: ";
	cin>>dato2 ;
	m.Introd_Util_col(dato2);
	
		for(int i=0; i<m.Total_fil(); i++){
		for(int j=0; j<m.Total_col(); j++){
			cout << "Introducir "<<j+1<<" elemento de la "<<i+1<<" fila: ";
			cin >>  valor ;
			
			m.AsignarDato(i,j,valor) ;
						
			}
		}
		
		return m ;
		
	}

	void MostrarMatriz (MiMatriz m)
		{
			cout<<"La matriz  es: "<<endl;
	
			for(int i=0;i<m.Total_fil();i++){
				cout<<"| ";
				for(int j=0;j<m.Total_col();j++){
					cout<<m.Dato(i,j)<<" ";
				}
				cout<<"|"<<endl;
			}
		cout<<endl;
		}

	int MostrarMayor(MiMatriz m)
	{
					
		int mayor=0;
		
		for(int i=0; i<m.Total_fil(); i++){
			for(int j=0; j<m.Total_col(); j++){
				if(m.Dato(i,j)>mayor){
					mayor=m.Dato(i,j);
					}
				}
			}
			cout<<"El numero mayor es: "<<mayor<<endl;
			cout<<endl;		
	}
	
	int MostrarMatrizOrdenada(int fila){
		MiMatriz m ;
		
		cout<<"Su fila ordenada es: ";
		for(int j=0;j<m.Total_col();j++){
			cout<<m.Dato(fila,j)<<" ";
		}
	}

int main () {
	
	int fil ; 
	MiMatriz matriz ;
	
	matriz=CompletarMatriz();
	
	MostrarMatriz(matriz) ;
	
	MostrarMayor(matriz);	
	
	cout << "Introduzca fila de la matriz a ordenar: ";
	cin >> fil ;
	matriz.Introd_Fila_ordenar(fil) ;
	
	matriz.OrdenarFila();
	
	/*MostrarMatrizOrdenada(matriz.Fila_ordenar());*/
	MostrarMatriz(matriz) ;

	
}
