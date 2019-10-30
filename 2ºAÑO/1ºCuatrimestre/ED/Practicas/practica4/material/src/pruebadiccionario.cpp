#include "Diccionario.h"
#include <fstream>
#include <iostream>

using namespace std;


int main(int argc, char * argv[])
{

  if (argc!=2)
  {
    cout<<"Dime el nombre del fichero con el diccionario"<<endl;
    return 0;
  }

  ifstream f (argv[1]);
  if (!f)
  {
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }

   
  Diccionario mi_diccionario;

  mi_diccionario.CargarDeFichero(argv[1]); 
   
  cout << mi_diccionario.getNumTerminos() << endl;
   

  cout<< "--------------------------------------------------------" << endl 
      << "Diccionario de la real academia de Ray y José." << endl
      << "--------------------------------------------------------" << endl;

  int valor;

  cout << "Como se desea recibir la informacion: \n -> 1 para mostrar por pantalla \n -> 2 para dar la salida a un fichero\n";
  cin >> valor;

  if(valor == 2)
  {

    mi_diccionario.SalvarAFichero("RARJ.txt") ;
     
    string palabra ;
    vector<string> definiciones ;
     
    cout << "\n\nIntroducir palabra para buscar sus definiciones: " << endl;
    cin >> palabra ;
     
    definiciones = mi_diccionario.getDefiniciones(palabra) ;
     
    cout << "\nLas definiciones asociadas a dicha palabra son: \n" << endl ;
    cout << "--------------------------------------------------------\n" << endl ;

    for( int i = 0 ; i < definiciones.size() ; i ++ )
    {
        cout << "-" << definiciones[i] << "\n" <<  endl;
    }
      
    cout << "--------------------------------------------------------" << endl ;
     
    char c1, c2 ;
     
    cout <<"Introducir primer caracter del intervalo para filtrar: " << endl;
    cin >> c1 ;
    cout <<"\nIntroducir segundo caracter del intervalo para filtrar: " << endl;
    cin >> c2 ;
     
    Diccionario filtrado_palabraClave = mi_diccionario.FiltrarPorIntervalo(c1,c2) ;
     
    filtrado_palabraClave.SalvarAFichero("filtrado_palabraClave") ;
             
    string palabraClave,palabraClaveContenida;

    cout << "--------------------------------------------------------" << endl ;

     
    cout << "Introducir palabra clave para obtener sus terminos asociados: " << endl;
    cin >> palabraClave ;
     
    Diccionario palabraclave ;
    palabraclave = mi_diccionario.FiltrarPorPalabra(palabraClave);
     
    palabraclave.SalvarAFichero("filtrado_palabraEnDefiniciones");

    cout << "--------------------------------------------------------" << endl ;
     
    cout << "Introducir palabra clave contenida para obtener sus terminos asociados: " << endl;
    cin >> palabraClaveContenida ;
     
    Diccionario palabraclaveContenida ;
    palabraclave = mi_diccionario.FiltrarPorContenidaPalabra(palabraClave);
     
    palabraclave.SalvarAFichero("filtrado_palabraContenidaEnDefiniciones");

    cout << "--------------------------------------------------------" << endl ;
   
    int num_max, num_promedio, num_total ,num_def;

    string palabrita;

    cout << "Introducir palabra para obtener su numero de definiciones: " << endl;
    cin >> palabrita ;

    mi_diccionario.RecuentoDefiniciones( num_max, num_promedio, num_total, palabrita, num_def) ;
     
    cout << "\nEl numero maximo de deficiones que tiene un termino es: " << num_max << endl ;
    cout << "El numero promedio de deficiones es: " << num_promedio << endl ;
    cout << "El numero total de deficiones es: " << num_total << endl ;  
    cout << "El numero total de deficiones asociada a " << palabrita<< " es : " << num_def << endl ;  


    cout << "\n--------------------------------------------------------" << endl ;
 
    string def; /*= "the 1st letter of the Roman alphabet";*/
    cout << "Pasar definicion para encontrar palabra asociada: \n";
    cin >> def;

    cout << "\nLa palabra asociada es: \n";
    cout << mi_diccionario.FiltrarPorDefinicion(def);

    cout << "\n--------------------------------------------------------" << endl ;

    int num;
    cout << "Introducir numero de definiciones para cada terminos para filtrar diccionario: \n";
    cin >> num;

    Diccionario FiltrarPorNumDefiniciones = mi_diccionario.FiltrarPorNumeroDefiniciones(num);
    FiltrarPorNumDefiniciones.SalvarAFichero("FiltradoNumDefiniciones");

    cout << "\n--------------------------------------------------------" << endl ;

    int inicio,final;
    cout << "Introducir primer intervalo de numero de definiciones para cada terminos para filtrar diccionario: \n";
    cin >> inicio;

    cout << "\nIntroducir primer intervalo de numero de definiciones para cada terminos para filtrar diccionario: \n";
    cin >> final;

    Diccionario FiltrarPorIntervaloNumDefiniciones = mi_diccionario.FiltrarPorIntervaloNumeroDefiniciones(inicio,final);
    FiltrarPorNumDefiniciones.SalvarAFichero("FiltradoIntervaloNumDefiniciones");

    cout << "\n--------------------------------------------------------" << endl ;

   }

  
  if(valor == 1)
  {
    mi_diccionario.SalvarAFichero("RARJ.txt") ;
     
    string palabra ;
    vector<string> definiciones ;
     
    cout << "\n\nIntroducir palabra para buscar sus definiciones: " << endl;
    cin >> palabra ;
     
    definiciones = mi_diccionario.getDefiniciones(palabra) ;
     
    cout << "\nLas definiciones asociadas a dicha palabra son: \n" << endl ;
    cout << "--------------------------------------------------------\n" << endl ;

    for( int i = 0 ; i < definiciones.size() ; i ++ )
    {
        cout << "-" << definiciones[i] << "\n" <<  endl;
    }
      
    cout << "--------------------------------------------------------" << endl ;
     
    char c1, c2 ;
     
    cout <<"Introducir primer caracter del intervalo para filtrar: " << endl;
    cin >> c1 ;
    cout <<"\nIntroducir segundo caracter del intervalo para filtrar: " << endl;
    cin >> c2 ;
     
    Diccionario filtrado_palabraClave = mi_diccionario.FiltrarPorIntervalo(c1,c2) ;
     
    cout << filtrado_palabraClave;
             
    string palabraClave,palabraClaveContenida;

    cout << "--------------------------------------------------------" << endl ;

     
    cout << "Introducir palabra clave para obtener sus terminos asociados: " << endl;
    cin >> palabraClave ;
     
    Diccionario palabraclave ;
    palabraclave = mi_diccionario.FiltrarPorPalabra(palabraClave);
     
    cout << palabraclave;

    cout << "--------------------------------------------------------" << endl ;
     
    cout << "Introducir palabra clave contenida para obtener sus terminos asociados: " << endl;
    cin >> palabraClaveContenida ;
     
    Diccionario palabraclaveContenida ;
    palabraclaveContenida = mi_diccionario.FiltrarPorContenidaPalabra(palabraClaveContenida);
     
    cout << palabraclaveContenida;

    cout << "--------------------------------------------------------" << endl ;
   
    int num_max, num_promedio, num_total ,num_def;

    string palabrita;

    cout << "Introducir palabra para obtener su numero de definiciones: " << endl;
    cin >> palabrita ;

    mi_diccionario.RecuentoDefiniciones( num_max, num_promedio, num_total, palabrita, num_def) ;
     
    cout << "\nEl numero maximo de deficiones que tiene un termino es: " << num_max << endl ;
    cout << "El numero promedio de deficiones es: " << num_promedio << endl ;
    cout << "El numero total de deficiones es: " << num_total << endl ;  
    cout << "El numero total de deficiones asociada a " << palabrita<< " es : " << num_def << endl ;  


    cout << "\n--------------------------------------------------------" << endl ;
 
    string def; /*= "the 1st letter of the Roman alphabet";*/
    cout << "Pasar definicion para encontrar palabra asociada: \n";
    cin >> def;

    cout << "\nLa palabra asociada es: \n";
    cout <<"-" << mi_diccionario.FiltrarPorDefinicion(def);

    cout << "\n--------------------------------------------------------" << endl ;


    int num;
    cout << "Introducir numero de definiciones para cada terminos para filtrar diccionario: \n";
    cin >> num;

    Diccionario FiltrarPorNumDefiniciones = mi_diccionario.FiltrarPorNumeroDefiniciones(num);
    cout << FiltrarPorNumDefiniciones;

    cout << "\n--------------------------------------------------------" << endl ;

    int inicio,final;
    cout << "Introducir primer intervalo de numero de definiciones para cada terminos para filtrar diccionario: \n";
    cin >> inicio;

    cout << "\nIntroducir primer intervalo de numero de definiciones para cada terminos para filtrar diccionario: \n";
    cin >> final;

    Diccionario FiltrarPorIntervaloNumDefiniciones = mi_diccionario.FiltrarPorIntervaloNumeroDefiniciones(inicio,final);
    cout << FiltrarPorNumDefiniciones;

    cout << "\n--------------------------------------------------------" << endl ;

  }

}