/** 
 * @file learn.cpp
 * @author DECSAI
*/

#include "ContadorBigramas.h"

using namespace std;

const string SINTAXIS = "ERROR: Sintaxis incorrecta\nSintaxis: learn {-c |-a} [-l idioma] [-f ficherosalida.bgr] texto.txt [texto2.txt texto3.txt...]";

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

void aniade(int n, int* pos, int &util)
{
    pos[util]=n;
    util++;
}

int main(int argc, char *argv[])
{
    std::string valid="abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF";
    
    if (argc  < 3)
    {
        return sintaxis();
    }
    
    bool existe_c=false, existe_a=false, existe_l=false, existe_f=false, es_txt;
    char* idioma="unknow";
    char* bgr="out.bgr";
    int n_txt=0;
    int v_pos[100];
    
    for(int i=1; i<argc; i++)
    {
        if(strcmp(argv[i], "-c") == 0 && !existe_c)
            existe_c=true;
        else if(strcmp(argv[i], "-a") == 0 && !existe_a)
            existe_a=true;
        else if(strcmp(argv[i], "-l") == 0 && !existe_l)
        {
            existe_l=true;
            idioma=argv[i+1];
            i++;
        }
        else if(strcmp(argv[i], "-f") == 0 && !existe_f)
        {
            existe_f=true;
            bgr=argv[i+1];
            i++;
        }
        else
        {
            es_txt=false;

            for(int j=0; argv[i][j]!='\0'; j++)
            {
                if(argv[i][j]=='.' && argv[i][j+1]!='\0')
                    if(argv[i][j+1]=='t' && argv[i][j+2]!='\0')
                        if(argv[i][j+2]=='x' && argv[i][j+3]!='\0')
                            if(argv[i][j+3]=='t')
                                if(argv[i][j+4]=='\0')
                                {
                                    es_txt=true;
                                    aniade(i, v_pos, n_txt);
                                }
            }

            if(!es_txt)
            {
                return sintaxis(argv[i]);
            }
        }
    }
    
    if((existe_a && existe_c) || (!existe_a && !existe_c) || n_txt==0)
    {
        return sintaxis();
    }
    if(existe_a && !existe_f)
    {
        cerr << "ERROR: No ha indicado el fichero al que añadir los bigramas" << endl;
    }
    
    if(existe_c)
    {
        Idioma lang;
        ContadorBigramas matriz(valid);
        
        for(int i=0; i<n_txt; i++)
        {
            matriz.calcularFrecuenciasBigramas(argv[v_pos[i]]);
        }
        
        lang=matriz.toIdioma();
        lang.ordenar();
        if(existe_l)
            lang.setIdioma(idioma);
        lang.salvarAFichero(bgr);
    }
    else
    {
        Idioma lang;
        ContadorBigramas matriz(valid);
        
        lang.cargarDeFichero(bgr);
        matriz.fromIdioma(lang);
        
        for(int i=0; i<n_txt; i++)
        {
            matriz.calcularFrecuenciasBigramas(argv[v_pos[i]]);
        }
        
        lang=matriz.toIdioma();
        lang.ordenar();
        if(existe_l)
            lang.setIdioma(idioma);
        lang.salvarAFichero(bgr);
    }
    
    return 0;
}