/** 
 * @file Idioma.cpp
 * @author Raúl Soria González y Fernando Roldán
 * @warning Código incompleto. Implementar la clase completa
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include "Idioma.h"
#include "Bigrama.h"

Idioma::Idioma()
{
    _idioma="unknow";
    _conjunto=nullptr;
    _nBigramas=0;
}

Idioma::Idioma(int nbg)
{
    _idioma="unknow";
    _conjunto=new Bigrama [nbg];
    _nBigramas=nbg;
}

Idioma::Idioma(const Idioma& orig)
{
    this->copiar(orig);
}

Idioma::~Idioma()
{
    liberarMemoria();
}

Idioma& Idioma::operator=(const Idioma& orig)
{
    this->copiar(orig);
    
    return *this;
}

void Idioma::reservarMemoria(int n)
{
    if(_conjunto)
        delete [] _conjunto;
    
    _conjunto=new Bigrama [n];
    _nBigramas=n;
}

void Idioma::ampliarMemoria(int n)
{
    Bigrama* aux=new Bigrama [_nBigramas+n];
    
    for(int i=0; i<_nBigramas; i++)
        aux[i]=_conjunto[i];
    
    delete [] _conjunto;
    
    _conjunto=aux;
    
    _nBigramas+=n;
}

void Idioma::liberarMemoria()
{
    delete [] _conjunto;
}

std::string Idioma::getIdioma() const
{
    return _idioma;
}

void Idioma::setIdioma(const std::string& id)
{
    _idioma = id;
}

Bigrama Idioma::getPosicion(int p) const
{
    if(p>=0 && p<_nBigramas)
        return _conjunto[p];
}

void Idioma::setPosicion(int p, const Bigrama& bg)
{
    if(p>=0 && p<_nBigramas)
    {
        if(bigramaValido(_conjunto[p]))
        {
            ampliarMemoria(1);
            
            for(int i=_nBigramas-1; i>p; i--)
                _conjunto[i]=_conjunto[i-1];
            
            _conjunto[p]=bg;
        }
        else
            _conjunto[p]=bg;
    }
}

int Idioma::findBigrama(const std::string& bg) const
{
    bool encontrado=false;
    int pos;
    
    for(int i=0; i<_nBigramas && !encontrado; i++)
    {
        if(bg == _conjunto[i].getBigrama())
        {
            encontrado=true;
            pos=i;
        }
    }
    
    if(encontrado)
        return pos;
    else
        return -1;
}

/*int Idioma::ranking(const Bigrama& bg) const
{
    bool encontrado=false;
    int pos;
    
    for(int i=0; i<_nBigramas && !encontrado; i++)
    {
        if(strcmp(bg.getBigrama(), _conjunto[i].getBigrama())==0)
        {
            encontrado=true;
            pos=i;
        }
    }
    
    if(encontrado)
        return pos;
    else
        return _nBigramas;
}*/
double Idioma::ranking(const Bigrama& bg, const Idioma& otro, int pos1) const 
{
    bool encontrado = false;
    int pos;
    double dist = 0;
    
    for(int i = 0; i<_nBigramas&& !encontrado; i++){
        if(!strcmp(bg.getBigrama(),_conjunto[i].getBigrama())){
            encontrado = true;
            pos = i;
        }
    }
    
    if (encontrado){
        dist = (abs(pos - pos1));
    }
    else{
        dist = otro.getSize();
    }
    
    return dist/(pow(otro.getSize(), 2));
}

/*double Idioma::distancia(const Idioma& otro) const
{
    double sumatoria=0;
    
    for(int i=0; i<otro.getSize(); i++)
    {
        sumatoria+=abs(this->ranking(otro._conjunto[i]) - otro.ranking(otro._conjunto[i])) / (pow(otro.getSize(), 2));
    }
    
    return sumatoria;
}*/

double Idioma::distancia(const Idioma& otro) const
{
    double sumatoria = 0;
    
    for(int i=0; i<otro.getSize(); i++)
    {
        sumatoria += ranking(otro._conjunto[i], otro, i);
    }
    
    return sumatoria;
}

void Idioma::ordenar_quicksort(int izq, int der){
    int i, j, pivote;
    Bigrama aux; 
    i = izq;
    j = der;
    pivote = _conjunto[(izq+der)/2].getFrecuencia();
    do{
        while((_conjunto[i].getFrecuencia() > pivote) && (j <= der)){
            i++;
        }
        
        while( (pivote > _conjunto[j].getFrecuencia()) && ( j > izq ) ){
            j--;
        }
    
        if(i>=j){
            aux = _conjunto[i];
            _conjunto[i] = _conjunto[j];
            _conjunto[j] = aux; 
            i++;
            j--;
        }
    }while(i <= j);
    
    if(izq < j)
        ordenar_quicksort(izq, j);
    if(i < der)
        ordenar_quicksort(i, der);
}

void Idioma::ordenar()
{
    int pos_max;
    Bigrama tmp;
    
    for(int izda=0; izda<_nBigramas-1; izda++)
    {
        pos_max=izda;
        
        for(int i=izda+1; i<_nBigramas; i++)
            if(_conjunto[i].getFrecuencia() > _conjunto[pos_max].getFrecuencia())
                pos_max=i;
        
        if(pos_max!=izda)
        {
            tmp=_conjunto[izda];
            _conjunto[izda]=_conjunto[pos_max];
            _conjunto[pos_max]=tmp;
        }
    }
}

std::ostream & operator<<(std::ostream & os, const Idioma & i)
{
    os << "MP-BIGRAMAS_IDIOMA-T-1.0" << std::endl;
    os << i.getIdioma() << std::endl;
    os << i.getSize() << std::endl;
    for(int j=0; j<i.getSize(); j++)
    {
        os << i._conjunto[j] << std::endl;
    }
    
    return os;
}

std::istream & operator>>(std::istream & is, Idioma & i)
{
    int frec;
    char bg [3];
    
    is.ignore(100, '\n');
    is >> i._idioma;
    is >> i._nBigramas;
    i.reservarMemoria(i._nBigramas);
    for(int j=0; j<i._nBigramas; j++)
    {
        is >> bg;
        is >> frec;
        i._conjunto[j].setBigrama(bg);
        i._conjunto[j].setFrecuencia(frec);
    }
    
    return is;
}

bool Idioma::salvarAFichero(const char *fichero) const
{
    bool estado = true;
    if(_nBigramas==0)
    {
        std::cerr << "Idioma vacio" << std::endl;
        estado = false;
    }
    else
    {
        std::ofstream salida;
        
        salida.open(fichero);
        
        salida << *this;
        
        if(!salida)
            estado = false;
        
        salida.close();
        
        return estado;
    }
}

void Idioma::addBigrama(const Bigrama& bg)
{
    int pos=findBigrama(bg.getBigrama());
    
    if(pos == -1)
    {
        ampliarMemoria(1);
        _conjunto[_nBigramas-1]=bg;
    }
    else
        _conjunto[pos].setFrecuencia(_conjunto[pos].getFrecuencia() + bg.getFrecuencia());
}

bool Idioma::cargarDeFichero(const char* fichero)
{
    std::string primera_linea = "MP-BIGRAMAS_IDIOMA-T-1.0";
    std::ifstream fentrada;
    std::string comprobacion;
    std::string idioma;
    int nbigr, frec;
    char bigr[3];
    
    std::cout << std::endl << "Abriendo fichero " << fichero << std::endl;
    fentrada.open(fichero);
    if(fentrada)
    {
        fentrada >> comprobacion;
        if(comprobacion != primera_linea)
        {
            std::cout << "ERROR fichero " << fichero << " no compatible" << std::endl;
            return false;
        }
        fentrada >> idioma;
        std::cout << "Idioma detectado: " << idioma << std::endl;
        fentrada >> nbigr;
        std::cout << "Leyendo " << nbigr << " bigramas" << std::endl;

        this->reservarMemoria(nbigr);
        for(int i=0; i<nbigr; i++)
        {
            if(!fentrada)
            {
                std::cout << "ERROR cargando datos del fichero " << fichero << std::endl;
                return false;
            }
            else
            {
                fentrada >> bigr;
                fentrada >> frec;
                _conjunto[i].setBigrama(bigr);
                _conjunto[i].setFrecuencia(frec);
            }
        }
        fentrada.close();
        
        this->setIdioma(idioma);
    }
    else
    {
        std::cout << "ERROR abriendo el fichero " << fichero << std::endl;
        return false;
    }
    
    std::cout << "OK" << std::endl;
    return true;
}

bool Idioma::addDeFichero(const char* fichero)
{
    std::string primera_linea = "MP-BIGRAMAS_IDIOMA-T-1.0";
    std::ifstream fentrada;
    std::string comprobacion;
    std::string idioma;
    int nbigr, frec;
    char bigr[3];
    
    std::cout << std::endl << "Abriendo fichero " << fichero << std::endl;
    fentrada.open(fichero);
    if(fentrada)
    {
        fentrada >> comprobacion;
        if(comprobacion != primera_linea)
        {
            std::cout << "ERROR fichero " << fichero << " no compatible" << std::endl;
            return false;
        }
        fentrada >> idioma;
        std::cout << "Idioma detectado: " << idioma << std::endl;
        if(idioma != _idioma)
        {
            std::cout << "ERROR idioma no compatible con " << _idioma << std::endl;
            return false;
        }
        fentrada >> nbigr;
        std::cout << "Leyendo " << nbigr << " bigramas" << std::endl;
        
        Bigrama* v=new Bigrama [nbigr];
        for(int i=0; i<nbigr; i++)
        {
            if(!fentrada)
            {
                std::cout << "ERROR cargando datos del fichero " << fichero << std::endl;
                delete [] v;
                return false;
            }
            else
            {
                fentrada >> bigr;
                fentrada >> frec;
                v[i].setBigrama(bigr);
                v[i].setFrecuencia(frec);
            }
        }
        fentrada.close();
    
        for(int i=0; i<nbigr; i++)
            this->addBigrama(v[i]);
        
        delete [] v;
    }
    else
    {
        std::cout << "ERROR abriendo el fichero " << fichero << std::endl;
        return false;
    }
    
    std::cout << "OK" << std::endl;
    return true;
}

void Idioma::copiar(const Idioma& otro)
{
    _idioma=otro.getIdioma();
    
    this->reservarMemoria(otro.getSize());
    
    for(int i=0; i<_nBigramas; i++)
        _conjunto[i]=otro._conjunto[i];
}
