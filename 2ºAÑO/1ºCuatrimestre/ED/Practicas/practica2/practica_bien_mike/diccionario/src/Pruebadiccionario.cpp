#include "Diccionario.h"

int main(int argc, char * argv[]){
	if (argc!=2){
		cout<<"Dime el nombre del fichero con el diccionario"<<endl;
		return 0;
	}

	ifstream f(argv[1]);
	if (!f){
		cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
		return 0;
	}

///Cargamos en memoria el diccionario.
   	Diccionario mi_diccionario;
	cout << "Cargando el diccionario..." << endl;	
	f >> mi_diccionario; 
	
///Obtener el recuento de definiciones.  
	cout << "Realizando el recuento de definiciones..." << endl;
	mi_diccionario.recuentoDefiniciones(); 
	
///Obtener las definiciones asociadas a una palabra  .
	Vector_Dinamico<string> palabraBuscada;
	string palabra;	
	cout << "\nIntroduzca una palabra para buscar sus definiciones: " << endl;
	cin >> palabra ;
	palabraBuscada = mi_diccionario.getDefinicionesTermino(palabra);   	

	cout << "Las definiciones de " << palabra << " son:" << endl;
	for(int i=0; i<palabraBuscada.size(); i++) 
		cout << "\t" << i+1 << ". " << palabraBuscada[i] << endl;
	
///Obtener el (sub)diccionario de términos comprendidos en [caracter_inicial, caracter_final].
	char caracterInicio, caracterFin;
	cout << "\nFiltrado por intervalo: " << endl;
	cout << "\tIntroduzca el caracter de inicio de intervalo: ";
	cin >> caracterInicio;
	cout << "\n\tIntroduzca el caracter de final del intervalo: ";
	cin >> caracterFin;
	cout << "\nSu intervalo es: [ " << caracterInicio << ", " << caracterFin << " ]" << endl;
	cout << mi_diccionario.filtrarPorIntervalo(caracterInicio, caracterFin);

///Obtener el (sub)diccionario de términos asociados a una palabra clave.
	string palabraClave;
	cout << "\nFiltrado por palabra clave: " << endl;
	cout << "\tIntroduzca la palabra clave a encontrar: ";
	cin >> palabraClave;
	cout << mi_diccionario.filtrarPalabraClave(palabraClave);

	return 0;
}
