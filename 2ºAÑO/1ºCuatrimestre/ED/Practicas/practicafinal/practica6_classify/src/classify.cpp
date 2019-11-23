/** 
 * @file learn.cpp
 * @author DECSAI
*/

#include "ContadorBigramas.h"

using namespace std;

const string SINTAXIS = "ERROR: Sintaxis incorrecta\nSintaxis: classify ficheroIdiomaDesconocido.txt ficheroIdiomaEspañol.bgr ficheroIdiomaIngles.bgr ficheroIdiomaAleman.bgr ficheroIdiomaPortugues.bgr ]";

int sintaxis()
{
    cerr << SINTAXIS << endl;
    return 0;
}

int sintaxis(char* arg)
{
    cerr << "Elemento inesperado: " << arg << endl;
    cerr << SINTAXIS << endl;
    return 0;
}

int main(int argc, char *argv[])
{
    string valid="abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF"; 
    
    bool existe_txt = false;
    int n_idiomas = 0; 
    bool existen_idiomas = false;
    
    
        for(int j = 0 ; argv[1][j]!= '\0' ; j++){
            if(argv[1][j] == '.' && argv[1][j+1] == 't' && argv[1][j+2] == 'x' &&
                argv[1][j+3] == 't' && argv[1][j+4] == '\0')
                existe_txt = true;    
        }   
    
    for (int i = 2; i < argc; i++){
        for (int j = 0; argv [i][j]!= '\0'; j++){
            if(argv[i][j] == '.' && argv[i][j+1] == 'b' && argv[i][j+2] == 'g' &&
                argv[i][j+3] == 'r' && argv[i][j+4] == '\0')
                n_idiomas++;
        }
    }
    if (n_idiomas >=2)
        existen_idiomas = true; 

    if (!existe_txt)
        return sintaxis();
    
    if(!existen_idiomas){
        cerr << "El numero de idiomas introducido no es valido, han de ser minimo 2" << endl;
    return 0;
    }
    
    Idioma lang; 
    Idioma otro;
    
    ContadorBigramas matriz(valid);
    ContadorBigramas idiomas(valid);
    
    double dist;
    double minima=2;
    string idioma="unknow";
    
    matriz.calcularFrecuenciasBigramas(argv[1]);
    //matriz.calcularFrecuenciasBigramas(argv[v_pos[i]]);
    lang = matriz.toIdioma();
    lang.ordenar();
    
    for(int i=2; i<argc; i++)
    {
        otro.cargarDeFichero(argv[i]);
        otro.ordenar();
        dist=otro.distancia(lang);
        cout << "Distancia con " << lang.getIdioma() << ": " << dist << endl;
        if(dist<minima)
        {
            minima=dist;
            idioma=otro.getIdioma();
        }
    }
    
    cout << endl << "El idioma del fichero introducido es: " << idioma << endl;
    
    return 0;
}
