#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"

#include <list>
#include <vector>

struct estado {
  int fila;
  int columna;
  int orientacion;
};

class ComportamientoJugador : public Comportamiento {
  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size) {
      // Inicializar Variables de Estado
      fil = col = 99;
      brujula = 0; // 0: Norte, 1:Este, 2:Sur, 3:Oeste
      destino.fila = -1;
      destino.columna = -1;
      destino.orientacion = -1;
      ultimaAccion = actIDLE;

      vector< unsigned char> aux(200, '?');

      for(int i = 0 ; i < 200; i++)
      {
        mapa_sensores.push_back(aux);
      }

    }
    
    ComportamientoJugador(std::vector< std::vector< unsigned char> > mapaR) : Comportamiento(mapaR) {
      // Inicializar Variables de Estado
      fil = col = 99;
      brujula = 0; // 0: Norte, 1:Este, 2:Sur, 3:Oeste
      destino.fila = -1;
      destino.columna = -1;
      destino.orientacion = -1;
      ultimaAccion = actIDLE;

      vector< unsigned char> aux(200, '?');

      for(int i = 0 ; i < 200; i++)
      {
        mapa_sensores.push_back(aux);
      }
    }
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);
    void VisualizaPlan(const estado &st, const list<Action> &plan);
    ComportamientoJugador * clone(){return new ComportamientoJugador(*this);}

  private:
    // Declarar Variables de Estado
    int fil, col, fila,columna, brujula;
    estado actual, destino;
    list<Action> plan;

    int pos_f = 99;
    int pos_c = 99;

    //Nuevas variables de Estado
    Action ultimaAccion;
    bool hayPlan = false;
    bool infoMapa = false;
    bool primera_vez = true;
    bool pk = false;

    vector<vector<unsigned char>> mapa_sensores;

    // Métodos privados de la clase
    bool pathFinding(int level, const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFinding_Profundidad(const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFinding_Anchura(const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFinding_CostoMinimo(const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFindingReto(const estado &origen, const estado &destino, list<Action> &plan);

    void calcularMapaReactivo(Sensores sensores, int pos_f, int pos_c, vector<vector<unsigned char>> &mapa_sensores);
    void findingPK(int posicion, list<Action> &plan);

    float distanciaE(const estado& n1, const estado& n2);


    void PintaPlan(list<Action> plan);
    bool HayObstaculoDelante(estado &st);

};

#endif
