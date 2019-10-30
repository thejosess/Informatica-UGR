#include "lista_palabras.h"



vector<string> lista_palabras::palabras_longitud(int longitud )const
{
	vector<string> v;

	for(const_iterator i = this->begin(); i != this->end(); i++)
	{
		if((*i).length() == longitud)
			v.push_back(*i);
	}

	return v;
}

istream & operator>>(istream & is, lista_palabras &D)
{
    string palabrita;
    
    while(is)
    {
    	getline(is, palabrita, '\n');
        D.datos.insert(palabrita);
    }

    return is;
}

ostream & operator<<(ostream & os, const lista_palabras &D)
{
    for (lista_palabras::const_iterator i = D.begin() ; i != D.end(); i++ )
    {
        os << (*i) << endl;
    }

    return os;
}

map<char,int> lista_palabras::contar_char(const conjunto_letras & conjunto, int & total) const
{
	map<char,int> swiper;

	bool entrado = false;

	for(iterator it = this->begin(); it != this->end(); it++)
	{
		for(int i = 0; i < (*it).size(); i++)
		{
			if( conjunto.find(toupper((*it)[i])) )
			{
				swiper[toupper((*it)[i])]++;
				total++;
			}
		}
		entrado = false;
	}

	return swiper;
}

set<string>::iterator lista_palabras::buscar_char(char c1) const
{
    bool encontrado = false;
    iterator pos = datos.end();

    for(iterator it = datos.begin(); it != datos.end() && !encontrado; it++)
    {
        if((*it)[0] == c1)
        {
            pos = it;
            encontrado = true;
        }
    }

    return pos;
}

set<pair<string, int>,classcomp> lista_palabras::buscar_soluciones(const multiset<char> & ms_letras, const conjunto_letras & conjunto, const bool longitud) const
{
	set<pair<string, int>,classcomp> soluciones;

	set<char> s_letras(ms_letras.cbegin(), ms_letras.cend());		// asi ordena y quita repetidos

	iterator j;

	for(set<char>::const_iterator i = s_letras.cbegin(); i != s_letras.cend(); i++)
	{
		j = this->buscar_char(*i);

		while((*j)[0] == *i)
		{
			if(this->es_solucion(*j, ms_letras))
			{
				soluciones.insert(make_pair(*j, conjunto.calcular_puntuacion(*j, longitud)));
				//mejor solucion hay que inicializarlo a 0
			}
			//es necesario meterlas todas?? y si cogemos solo las diez mejores y empezando por las letras que tengan mejor puntuacion
			//podriamos ordenar el multiset para asi que empiece con las que tengan mejor puntuacion o no sé

			j++;
		}
	}

	return soluciones;
}

bool lista_palabras::es_solucion(string str, const multiset<char> & ms_letras) const
{
	multiset<char> aux(ms_letras.cbegin(), ms_letras.cend());		

	bool correcto = true;

	for(int i = 0; i < str.size() && correcto; i++)
	{
		if(aux.find(str[i]) != aux.end())
			aux.erase(aux.find(str[i]));
		else
			correcto = false;
	}

	return correcto;
}