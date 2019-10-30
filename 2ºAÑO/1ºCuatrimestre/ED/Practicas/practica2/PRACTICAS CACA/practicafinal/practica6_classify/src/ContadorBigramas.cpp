/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <fstream>

#include "ContadorBigramas.h"

ContadorBigramas::ContadorBigramas(const std::string& caracteresValidos)
{
    _caracteresValidos=caracteresValidos;
    
    this->reservarMemoria(getSize());
}

ContadorBigramas::ContadorBigramas(const ContadorBigramas & orig)
{
    this->copiar(orig);
}

ContadorBigramas::~ContadorBigramas()
{
    this->liberarMemoria();
}

ContadorBigramas& ContadorBigramas::operator=(const ContadorBigramas& orig)
{
    this->copiar(orig);
    
    return *this;
}

ContadorBigramas& ContadorBigramas::operator+=(const ContadorBigramas& rhs)
{
    for(int i=0; i<getSize(); i++)
        for(int j=0; i<getSize(); j++)
            _bigramas[i][j]+=rhs._bigramas[i][j];
    
    return *this;
}

int ContadorBigramas::getBigramasActivos() const
{
    int contador=0;
    
    for(int i=0; i<getSize(); i++)
        for(int j=0; j<getSize(); j++)
            if(_bigramas[i][j]>0)
                contador++;
    
    return contador;
}

bool ContadorBigramas::addBigrama(const char cadena[], int frecuencia)
{
    bool correcto=true;
    
    if(strlen(cadena)!=2 || frecuencia<0)
        correcto = false;
    else
    {
        int pos_1=_caracteresValidos.find(cadena[0]);
        int pos_2=_caracteresValidos.find(cadena[1]);
        
        if(pos_1 == std::string::npos || pos_2 == std::string::npos)
            correcto = false;
        else
        {
            if(frecuencia!=0)
                _bigramas[pos_1][pos_2]=frecuencia;
            else
                _bigramas[pos_1][pos_2]++;
        }
    }
    
    return correcto;
}

void ContadorBigramas::reservarMemoria(int n)
{
    _bigramas=new int* [n];
    for (int i = 0; i<n;i++){
        _bigramas[i] = new int [n];
        for(int j=0; j<n; j++)
        {
            _bigramas[i][j]=0;
        }
    }
}

void ContadorBigramas::copiar(const ContadorBigramas & otro)
{
    if(_bigramas)
    {
        this->liberarMemoria();
    }
    
    this->reservarMemoria(otro.getSize());
    
    for(int i=0; i<otro.getSize(); i++)
        for(int j=0; j<otro.getSize(); j++)
            _bigramas[i][j]=otro._bigramas[i][j];
    
    _caracteresValidos=otro._caracteresValidos;
}

void ContadorBigramas::liberarMemoria()
{
    for(int i=0; i<getSize(); i++)
        delete [] _bigramas[i];
    
    delete [] _bigramas;
}

bool ContadorBigramas::calcularFrecuenciasBigramas(const char* nfichero)
{
    bool correcto = true;
    std::ifstream entrada;
    char cad[3];
    cad[2]='\0';
    
    entrada.open(nfichero);
    if(entrada)
    {
        while(entrada)
        {
            entrada.get(cad[0]);
            entrada.get(cad[1]);
            entrada.unget();
            cad[0]=tolower(cad[0]);
            cad[1]=tolower(cad[1]);
            addBigrama(cad);
        }
    }
    else
        correcto = false;
    entrada.close();
    
    return correcto;
}

Idioma ContadorBigramas::toIdioma() const
{
    Idioma lang;
    Bigrama bg;
    char cad[3];
    cad[2]='\0';
    
    for(int i=0; i<getSize(); i++)
        for(int j=0; j<getSize(); j++)
            if(_bigramas[i][j]!=0)
            {
                cad[0]=_caracteresValidos[i];
                cad[1]=_caracteresValidos[j];
                bg.setBigrama(cad);
                bg.setFrecuencia(_bigramas[i][j]);
                lang.addBigrama(bg);
            }
    
    return lang;
}

void ContadorBigramas::fromIdioma(const Idioma &i)
{
    for(int j=0; j<i.getSize(); j++)
        addBigrama(i.getPosicion(j).getBigrama(), i.getPosicion(j).getFrecuencia());
}