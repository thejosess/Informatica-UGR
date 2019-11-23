#include "Diccionario.h"
#include <fstream>
#include <iostream>

using namespace std;

/*
 IMPORTANTE README:
 
 * Hemos estado realizando las pruebas pertinentes en el main para el funcionamiento del TDA
 * y pudimos observar que la funcion getDefiniciones genera un error que provoca 
 * que en funciones como FiltrarPorIntervalo te introduzca definiciones repetidas y recursivas
 * por ejemplo si has de meter la definicion 3, te introduce la 0 ya metida, la 1, la 2 y la 3 y asi
 * consecutivamente de forma que genera una carga muy grande para el ordenador y por eso lo hace lento
 * y repetido. Hemos intentado solucionarlo de distintas formas pero no conseguimos ver a que se debe dicho error.
 * En el make hemos creado una funcion short con tan solo las primeras 1000 entradas del diccionario de prueba
 * y asi no dejar colgada la terminal con el diccionario de 8000 entradas.
 */

int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con el diccionario"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   
   Diccionario mi_diccionario;
   //f>>mi_diccionario; //Cargamos en memoria el diccionario
   mi_diccionario.CargarDeFichero(argv[1]);
   /* Exhibir aqui la funcionalidad programada para el TDA Diccionario / TDA Termino  
    Algunas sugerencias: 
    - Obtener las definiciones asociadas a una palabra   
    - Obtener el (sub)diccionario de términos comprendidos en [caracter_inicial, caracter_final]
    - Obtener el (sub)diccionario de términos asociados a una palabra clave. Ejemplo: el diccionario de terminos asociados a "color"   
    - Obtener el numero total de definiciones, el maximo de definiciones asociadas a una unica palabra y el promedio de definiciones por palabra
    - Cualquier otra funcionalidad que considereis de interes 
   */
   
   cout << mi_diccionario.getNumTerminos() << endl;
   

   cout << "--------------------------------------------------------" << endl 
        << "Diccionario de la real academica de Ray y José." << endl
        << "--------------------------------------------------------" << endl;
   
   mi_diccionario.SalvarAFichero("RARJ.txt") ;
   
   string palabra ;
   Vector_Dinamico<string> definiciones ;
   
   cout << "Introducir palabra para buscar sus definiciones: " << endl;
   cin >> palabra ;
   
   definiciones = mi_diccionario.getDefiniciones(palabra) ;
   
   cout << "\nLas definiciones asociadas a dicha palabra son: \n" << endl ;
   cout << "--------------------------------------------------------" << endl ;

   for( int i = 0 ; i < definiciones.size() ; i ++ )
   {
       cout << definiciones[i] << endl;
   }
    
   cout << "--------------------------------------------------------" << endl ;
   
   
   Diccionario filtrado_intervalo ;
   char c1, c2 ;
   
   cout <<"Introducir primer caracter del intervalo para filtrar: " << endl;
   cin >> c1 ;
   cout <<"Introducir segundo caracter del intervalo para filtrar: " << endl;
   cin >> c2 ;
   
   Diccionario filtrado_palabraClave = mi_diccionario.FiltrarPorIntervalo(c1,c2) ;
   
   filtrado_palabraClave.SalvarAFichero("filtrado_palabraClave") ;
           
   string palabraClave;
   
   cout << "Introducir palabra clave para obtener sus terminos asociados: " << endl;
   cin >> palabraClave ;
   
   Diccionario palabraclave = mi_diccionario.FiltrarPorPalabra(palabraClave);
   
   palabraclave.SalvarAFichero("filtrado_palabraEnDefiniciones");
      
   
   int num_max, num_promedio, num_total ;
   
   mi_diccionario.RecuentoDefiniciones( num_max, num_promedio, num_total) ;
   
   cout << "El numero maximo de deficiones que tiene un termino es: " << num_max << endl ;
   cout << "El numero promedio de deficiones es: " << num_promedio << endl ;
   cout << "El numero total de deficiones es: " << num_total << endl ;

   
   /*
   for(int i = 0; i < mi_diccionario.getNumTerminos(); i++)
   {
       cout << 
   }
   */
}