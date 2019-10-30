/** 
 * @file Bigrama.cpp
 * @author Raúl Soria González y Fernando Roldán
 * @warning Código incompleto
*/

#include <cstring>
#include "Bigrama.h"

using namespace std;

int INVALID_FREC=-2;

Bigrama::Bigrama() {
    _bigrama[0] = '\0';
    _frecuencia = -1;
}

void Bigrama::operator=(const Bigrama& bg)
{
    this->setBigrama(bg.getBigrama());
    this->setFrecuencia(bg.getFrecuencia());
}

const char* Bigrama::getBigrama() const
{
    return _bigrama;
}

int Bigrama::getFrecuencia() const
{
    return _frecuencia;
}

void Bigrama::setBigrama(const char cadena[])
{
    char numeros[10]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool hay_numeros=false;
    
    if (strlen(cadena)==2)
    {
        for(int i=0; i<10; i++)
            for(int j=0; j<2; j++)
                if(cadena[j]==numeros[i])
                    hay_numeros=true;
        
        if(hay_numeros)
            _frecuencia=INVALID_FREC;   //Si hay numeros no es valido
        else
        {
            strcpy(_bigrama,cadena);
            if(_frecuencia==INVALID_FREC)   //Por si se le hace un set a un bigrama que era invalido
                _frecuencia=-1;
        }
    }
    else
        _frecuencia=INVALID_FREC;   //Si no tiene tamaño 2 no es valido
}

void Bigrama::setFrecuencia(int frec)
{
    if(frec >= 0 && _frecuencia!=INVALID_FREC)
        _frecuencia=frec;
}

std::ostream& operator<<(std::ostream& os, const Bigrama& bigrama)
{
    os << bigrama._bigrama << " " << bigrama._frecuencia;
    
    return os;
}

std::istream& operator>>(std::istream& is, Bigrama& bigrama)
{
    char bgr[3];
    int frec;
    
    is >> bgr; bigrama.setBigrama(bgr);
    is >> frec; bigrama.setFrecuencia(frec);
    
    return is;
}

void ordenaAscFrec(Bigrama *v, int n)
{
    int pos_min;
    Bigrama tmp;
    
    for(int izda=0; izda<n-1; izda++)
    {
        pos_min=izda;
        
        for(int i=izda+1; i<n; i++)
            if(v[i].getFrecuencia() < v[pos_min].getFrecuencia())
                pos_min=i;
        
        if(pos_min!=izda)
        {
            tmp=v[izda];
            v[izda]=v[pos_min];
            v[pos_min]=tmp;
        }
    }
}

void ordenaAscBigr(Bigrama *v, int n)
{
    int pos_min;
    Bigrama tmp;
    
    for(int izda=0; izda<n-1; izda++)
    {
        pos_min=izda;
        
        for(int i=izda+1; i<n; i++)
            if(strcmp(v[i].getBigrama(), v[pos_min].getBigrama()) < 0)
                pos_min=i;
        
        if(pos_min!=izda)
        {
            tmp=v[izda];
            v[izda]=v[pos_min];
            v[pos_min]=tmp;
        }
    }
}

bool bigramaValido(const Bigrama &b)
{
    bool valido=false;
    
    if(b.getFrecuencia() != INVALID_FREC && b.getFrecuencia() != -1)
        valido=true;
    
    return valido;
}

void imprimeBigramas(const Bigrama *v, int n)
{
    int salidas=0;
    
    for(int i=0; i<n; i++)
    {
        if(bigramaValido(v[i]))
        {
            cout << v[i].getBigrama() << " -> " << v[i].getFrecuencia() << endl;
            salidas++;
        }
    }
    
    if(salidas==0)
        cout << "Vector vacio!!!" << endl;
}

void sumaBigramas(const Bigrama *v1, int nv1, const Bigrama *v2, int nv2, Bigrama *&res, int & nres)
{
    Bigrama *v1_aux=new Bigrama [nv1], *v2_aux=new Bigrama [nv2];
    bool valido=true;
    int frec;
    
    if(nv1==nv2)
    {
        for(int i=0; i<nv1; i++)
        {
            v1_aux[i].setBigrama(v1[i].getBigrama());
            v1_aux[i].setFrecuencia(v1[i].getFrecuencia());
            v2_aux[i].setBigrama(v2[i].getBigrama());
            v2_aux[i].setFrecuencia(v2[i].getFrecuencia());
        }

        ordenaAscBigr(v1_aux, nv1);
        ordenaAscBigr(v2_aux, nv2);
        
        for(int i=0; i<nv1 && valido; i++)
        {
            if(strcmp(v1_aux[i].getBigrama(), v2_aux[i].getBigrama()) != 0)
                valido=false;
        }
    }
    else
        valido=false;
    
    if(valido)
    {
        nres=nv1;
        res=new Bigrama[nres];
        
        for(int i=0; i<nres; i++)
        {
            res[i].setBigrama(v1_aux[i].getBigrama());
            frec = v1_aux[i].getFrecuencia() + v2_aux[i].getFrecuencia();
            res[i].setFrecuencia(frec);
        }
    }
    
    delete [] v1_aux;
    delete [] v2_aux;
}