#include "Diccionario.h"

Vector_Dinamico<string> Diccionario::getDefiniciones(string palabra) const
{
	for(int i = 0; i < this->getNumTerminos(); i++)
	{
		if(terminos[i].getPalabra() == palabra)
			return terminos[i].getDefiniciones();
	}
}

void Diccionario::addTermino(const Termino & termino)
{
	int pos = this->terminos.buscar(termino);

	if (pos == -1)
		this->terminos.addElemento(termino);
	else
	{
		for(int i = 0; i < termino.getNumDefiniciones(); i++)
			this->terminos[pos].setDefinicion(termino.getDefiniciones()[i]);
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
        while(fentrada)
        {
            fentrada >> aux ;
/*
            // seria mas eficiente usar una variable i que haga lo de los corchetes ??
            int i = this->getNumTerminos() ;
        
            if(aux.getPalabra() == this->terminos[i - 1].getPalabra())
            {
                this->terminos[i-1].setDefinicion(aux.getDefiniciones()[0]) ;
            }
            else
            {
                this->terminos.addElemento(aux);
            }*/this->addTermino(aux);
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

int Diccionario::BuscarChar(char c1) const
{
    bool encontrado = false ;
    int pos = -1 ;
    int tam = this->getNumTerminos() ;

    for(int i = 0 ; i < tam && !encontrado ; i++ )
    {
        if(this->terminos[i].getPalabra()[0] == c1)
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

    int comienzo = BuscarChar(inicio),
    	end = BuscarChar(fin);

    for(int i = comienzo ; i < end ; i++ )
    {
        aux.addTermino(this->terminos[i]) ;
    }

    return aux ;
}

Diccionario Diccionario::FiltrarPorPalabra(string palabra) const
{
    Diccionario aux ;
    int found,
    	j = 0;
    bool encontrado;

    palabra = " " + palabra + " ";

    for(int i = 0 ; i < this->getNumTerminos(); i++ )
    {
    	encontrado = false;

        for(int k = 0 ; k < this->terminos[i].getNumDefiniciones() ; k++)
        {
            found = this->terminos[i].getDefiniciones()[k].find(palabra) ;

            if(found != string::npos)
            {
            	encontrado = true;
            	if(aux.terminos[j].getPalabra().empty())
            	{
            		aux.terminos.resize(aux.getNumTerminos() + 1);
                	aux.terminos[j].getPalabra() = this->terminos[i].getPalabra() ;
            	}
                aux.terminos[j].setDefinicion(this->terminos[i].getDefiniciones()[k]) ;
            }
        }

        if(encontrado)
        	j++;
    }

    return aux;
}

void Diccionario::RecuentoDefiniciones(int & num_max, int & num_promedio, int & num_total) const
{
    num_max = this->terminos[0].getNumDefiniciones() , num_promedio = 0 , num_total = 0 ;

    for( int i = 0 ; i < this->getNumTerminos() ; i++)
    {
        num_total+=this->terminos[i].getNumDefiniciones();

        if(this->terminos[i].getNumDefiniciones() > num_max)
        {
            num_max = this->terminos[i].getNumDefiniciones() ;
        }
    }

    num_promedio = num_total / this->getNumTerminos() ;
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
	for (int i = 0; i < dicc.getNumTerminos(); i++)
	{
		os << dicc.terminos[i];
	}

	return os;
}
