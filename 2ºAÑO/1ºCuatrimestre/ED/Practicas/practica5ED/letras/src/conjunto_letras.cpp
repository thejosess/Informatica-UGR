#include "conjunto_letras.h"

istream & operator>>(istream & is, conjunto_letras &D)
{
    letra letrita;

    is.ignore(50, '\n');
    
    while(is >> letrita)
    {
        D.conjunto.insert(letrita);
    }

    return is;
}

ostream & operator<<(ostream & os, const conjunto_letras &D)
{
    os << "#Letra\tCantidad\tPuntos\n";

    for (conjunto_letras::const_iterator i = D.begin() ; i != D.end(); i++ )
    {
        os << (*i) << endl;
    }

    return os;
}

int conjunto_letras::calcular_puntuacion(string str, bool longitud) const
{
    if(longitud)
        return str.size();
    else
    {
        int puntuacion = 0;

        for(int i = 0; i < str.size(); i++)
        {
            for(iterator it = this->begin(); it != this->end(); it++)
            {
                if(str[i] == tolower((*it).getCaracter()))
                    puntuacion += (*it).getPuntuacion();
            }
        }

        return puntuacion;
    }
}

bool conjunto_letras::find(char c1) const
{
    bool encontrado = false;
    for(iterator it = this->begin(); it != this->end() && !encontrado; it++)
    {
        if((*it).getCaracter() == c1)
            encontrado = true;
    }

    return encontrado;
}