#include "Diccionario.h"

Vector_Dinamico<string> Diccionario::getDefiniciones(string palabra) const
{
	for(int i = 0; i < this.getNumTerminos(); i++)
	{
		if(terminos[i].palabra == palabra)
			return terminos[i].definiciones;
	}
}

int Diccionario::addTermino(Termino termino)
{
	pos = this.terminos.buscar(termino);

	if (pos == -1)
		this.terminos.addElemento(termino);
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

            // seria mas eficiente usar una variable i que haga lo de los corchetes ??
            int i = this.getNumTerminos() ;
        
            if(aux.palabra == this.terminos[i - 1].palabra)
            {
                this.terminos[i-1].definiciones.addElemento(aux.definiciones[0]) ;
            }
            else
            {
                this.terminos.addElemento(aux);
            }
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
    int pos = -1 ;             //Suponiendo que hay palabras con todas las letras(A-Z)
    int tam = this.getNumTerminos() ;

    for(int i = 0 ; i < tam && !encontrado ; i++ )
    {
        if(this.terminos[i].palabra[0] == c1)
        {
            pos = i ;
            perdido = true ;
        }
    }

    return pos ;
}


Diccionario Diccionario::FiltrarPorIntervalo(char inicio, char fin) const
{
    Diccionario aux ;

    int inicio = BuscarChar(char inicio),
    	final = BuscarChar(char fin);

    for(int i = inicio ; i < final ; i++ )
    {
        aux.addTermino(this.terminos[i]) ;
    }

    return aux ;
}

Diccionario Diccionario::FiltrarPorPalabra(string palabra) const
{
    Diccionario aux ;
    int pos,
    	j = 0;
	bool encontrado;

    palabra = " " + palabra + " ";

    for(int i = 0 ; i < this.getNumTerminos(); i++ )
    {
    	encontrado = false;

        for(int k = 0 ; k < this.terminos[i].getNumDefiniciones ; k++)
        {
            found = this.terminos[i].definiciones[k].find(palabra) ;

            if(found != string::npos)
            {
            	encontrado = true;
            	if(aux.terminos[j].palabra == nullptr)
            	{
            		aux.terminos.resize(aux.getNumTerminos() + 1);
                	aux.terminos[j].palabra = this.terminos[i].palabra ;
            	}
                aux.terminos[j].setDeficion(this.terminos[i].definiciones[k]) ;
            }
        }

        if(encontrado)
        	j++;
    }

    return aux;
}

void Diccionario::RecuentoDefiniciones(int & num_max, int & num_promedio, int & num_total) const
{
    num_max = terminos[0].this.getNumDefiniciones() , num_promedio = 0 , num_total = 0 ;

    for( int i = 0 ; i < this.getNumTerminos() ; i++)
    {
        num_total+=terminos[i].this.getNumDefiniciones();

        if(terminos[i].this.getNumDefiniciones() > num_max)
        {
            num_max = terminos[i].this.getNumDefiniciones() ;
        }
    }

    num_promedio = num_total / this.getNumTerminos() ;
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
}
