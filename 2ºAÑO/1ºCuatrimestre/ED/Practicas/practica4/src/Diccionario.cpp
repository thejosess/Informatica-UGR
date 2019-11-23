#include "Diccionario.h"

vector<string> Diccionario::getDefiniciones(string palabra) const
{
    for(iterator i = terminos.begin(); i != terminos.end(); i++)
    {
        if((*i).getPalabra() == palabra)
            return (*i).getDefiniciones();
    }
}

void Diccionario::addTermino(const Termino & termino)
{
    iterator pos = this->buscar(termino);
    Termino term;

    if (pos == this->end())
        this->terminos.insert(termino);
    else
    {
        term = (*pos);
        this->terminos.erase(term);
        term.addDefinicion(termino.getDefiniciones()[0]);
        this->terminos.insert(term);
    }
}

bool Diccionario::CargarDeFichero(const char* fichero)
{
    ifstream fentrada;
    Termino aux ;
    
    cout << endl << "Abriendo fichero " << fichero << endl;
    fentrada.open(fichero);
    if(fentrada)
    {
        while(fentrada >> aux)
        {
            this->addTermino(aux);
        }

        fentrada.close();
    }
    else
    {
        cerr << "ERROR abriendo el fichero " << fichero << endl;
        return false;
    }
    
    cout << "OK" << endl;
    return true;
}

bool Diccionario::SalvarAFichero(const char* fichero) const
{
    bool estado = true;

    ofstream salida;
        
    salida.open(fichero);
        
    salida << *this;
        
    if(!salida)
        estado = false;
        
    salida.close();
        
    return estado;
}

set<Termino>::iterator Diccionario::BuscarChar(char c1) const
{
    bool encontrado = false ;
    iterator pos = terminos.end() ;

    for(iterator i = terminos.begin() ; i != terminos.end() && !encontrado ; i++ )
    {
        if((*i).getPalabra()[0] == c1)
        {
            pos = i ;
            encontrado = true ;
        }
    }

    return pos ;
}

Diccionario Diccionario::FiltrarPorIntervalo(char inicio, char fin) const
{
    Diccionario aux ;

    iterator comienzo = BuscarChar(inicio), end = BuscarChar(fin + 1);

    for(iterator i = comienzo ; i != end ; i++ )
    {
        aux.addTermino((*i)) ;
    }

    return aux ;
}

Diccionario Diccionario::FiltrarPorPalabra(string palabra) const
{
    /*FiltrarPorPalabra y FiltrarPorContenidoPalabra son casi iguales
    pero tienen algunas diferencias y por eso hemos dejado ambas
    segun la que se quiera usar*/

    Diccionario aux ;
    bool primeravez;
    int found;

    
    palabra = " " + palabra + " ";

    return FiltrarPorContenidaPalabra(palabra);
}

/*void Diccionario::FiltrarPorPrefijos() const
{
    Diccionario prefijo;

    prefijo = FiltrarPorContenidaPalabra("anti");
    prefijo.SalvarAFichero("prefijoAnti");

    //los prefijos están en ingles pero se podria hacer
    una funcion para filtrar el diccionario por subconjutos de prefijos
    como esta funcion o de sufijos
    // al tener FiltrarPorContenidaPalabra se puede filtrar tambien los generos,
    por singular o plural etc.
}*/

Diccionario Diccionario::FiltrarPorContenidaPalabra(string palabra) const
{
    Diccionario aux ;
    bool primeravez;
    int found;

    for(iterator i = this->begin() ; i != this->end(); i++ )
    {
        primeravez = true;
        Termino term;

        for(int k = 0 ; k < (*i).getNumDefiniciones() ; k++)
        {
            found = (*i).getDefiniciones()[k].find(palabra) ;

            if(found != string::npos)
            {
                if(primeravez)
                {
                    term.setDefinicion((*i).getDefiniciones()[k]);
                    term.setPalabra((*i).getPalabra());
                    primeravez = false;
                }
                else
                    term.addDefinicion((*i).getDefiniciones()[k]);
            }
        }
        /*if(term/)
            aux.terminos.insert(term);    */
    }
    return aux;    
}

string Diccionario::FiltrarPorDefinicion(string palabra) const
{
    int found;
    bool continuar = true;
    string termino;

    for(iterator i = this->begin() ; i != this->end() && continuar; i++ )
    {
        for(int k = 0 ; k < (*i).getNumDefiniciones() && continuar ; k++)
        {
            found = (*i).getDefiniciones()[k].find(palabra) ;

            if(found != string::npos)
            {
                termino = (*i).getPalabra();
                continuar = false;
            }
        }
    }
    return termino;    
}

Diccionario Diccionario::FiltrarPorNumeroDefiniciones(int num) const
{
    iterator i = this->begin();
    Diccionario aux;

    for(iterator i = this->begin() ; i != this->end(); i++ )
    {
        if((*i).getNumDefiniciones() == num)
            aux.addTermino((*i));
    }

    return aux;
}

Diccionario Diccionario::FiltrarPorIntervaloNumeroDefiniciones(int inicio, int final) const
{
    iterator i = this->begin();
    Diccionario aux;

    for(iterator i = this->begin() ; i != this->end(); i++ )
    {
        if((*i).getNumDefiniciones() >= inicio && (*i).getNumDefiniciones() <= final)
            aux.addTermino((*i));
    }

    return aux;
}


void Diccionario::RecuentoDefiniciones(int & num_max, int & num_promedio, int & num_total, string & palabra, int & num_def) const
{
    num_promedio = 0 , num_total = 0 ;
    iterator i = this->begin();
    num_max = (*i).getNumDefiniciones();

    for(iterator i = this->begin() ; i != this->end(); i++ )
    {
        num_total+=(*i).getNumDefiniciones();

        if((*i).getPalabra() == palabra)
            num_def = (*i).getNumDefiniciones();

        if((*i).getNumDefiniciones() > num_max)
        {
            num_max = (*i).getNumDefiniciones() ;
        }
    }

    num_promedio = num_total / this->getNumTerminos() ;
}

set<Termino>::iterator Diccionario::buscar(const Termino & termino)
{
    iterator aux = this->end();
    if(!this->terminos.empty())
        for(iterator i = this->begin() ; i != this->end(); i++ )
        {
            if((*i).getPalabra() == termino.getPalabra())
                aux = i;
        }

    return aux;
}

void Diccionario::rmTermino(const Termino & termino)
{
    terminos.erase(termino);
}

istream& operator>>(istream& is, Diccionario& dicc)
{
    Termino term;

    while(is)
    {
        is >> term;

        dicc.addTermino(term);
    }

    return is;
}

ostream& operator<<(ostream& os, const Diccionario& dicc)
{
    Diccionario::const_iterator i;       //clase amiga

    for (i = dicc.begin() ; i != dicc.end(); i++ )
    {
        os << (*i) ;
    }

    return os;
}