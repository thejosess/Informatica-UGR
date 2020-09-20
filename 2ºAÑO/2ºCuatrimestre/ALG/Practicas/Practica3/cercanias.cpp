#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

float distancia(const Ciudad &c1,const Ciudad &c2)
{
    return sqrt(pow((c2.x()-c1.x()), 2) + pow((c2.y()-c1.y()), 2));
}

Ciudad seleccionar(const Mapa &mapa,const Ciudad &actual)
{
    Ciudad min = mapa.getCiudades()[0];

    for(int i = 1; i < mapa.getCiudades().size(); i++)
    {
        if(distancia(mapa.getCiudades()[i], actual) < distancia(min, actual))
            min = mapa.getCiudades()[i];
    }

    return min;
}

vector<Ciudad> cercania(Mapa mapa, const Ciudad &inicio)
{
    vector<Ciudad> sol;
    sol.push_back(inicio);

    while(!mapa.getCiudades().empty())
    {
        Ciudad x = seleccionar(mapa, sol[sol.size()-1]);
        mapa.eliminar(x);
        sol.push_back(x);
    }

    return sol;
}