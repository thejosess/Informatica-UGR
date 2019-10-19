#include "motorlib/entidad.hpp"

void Entidad::resetEntidad() {
  hitbox = false;
  if(tipo == jugador) {
    desactivado = 0;
  }
  else{
    desactivado = aleatorio(7)+3;
  }

  colision = false;
  colisiones = 0;
  reset = true;
  if (vida != 0) muertes_innecesarias++;
  vida = 0;
  done = false;

  mensaje = true;
}

Action Entidad::think(int acc, vector <vector< unsigned char> > vision, int level) {
  Action accion = actIDLE;
  Sensores sensor;

  if (desactivado == 0) {
    vida--;
    hitbox = true;

    sensor.nivel = level;

    sensor.vida = vida;

    sensor.destinoF = destY;
    sensor.destinoC = destX;
    sensor.colision = colision;
    sensor.reset = reset;

    if ((sensor.destinoF == x) and (sensor.destinoC == y) and !done) {
      misiones++;
      done = true;
      if (tipo == jugador)
      cout << "Objetivo alcanzado!" << endl;
    }

    if (mensaje) {
      sensor.mensajeF = x;
      sensor.mensajeC = y;
    } else {
      sensor.mensajeF = -1;
      sensor.mensajeC = -1;
    }

    sensor.superficie = vision[1];
    sensor.terreno = vision[0];

    sensor.tiempo = getTiempo() / CLOCKS_PER_SEC;

    visionAux = vision;

    if (acc==-1)
      accion = comportamiento->think(sensor);
    else
      accion = static_cast<Action>(acc);


    colision = false;
    reset = false;
    mensaje = false;
  }
  else{
    desactivado--;
  }

  return accion;
}

bool Entidad::interact(Action accion, int valor) {
  bool out = false;
  int retorno = comportamiento->interact(accion, valor);

  if (retorno == 1) { // Desaparición temporal
    resetEntidad();
    out =  true;
  }

  if (retorno == 2) {  // Muerte
    hitbox = false;
    desactivado = -1;
    out = true;
  }

  if (retorno == 3) { //Revivir
    hitbox = true;
    desactivado = 0;
    out = true;
  }

  return out;
}


unsigned char Entidad::getSubTipoChar() {
  unsigned char out = ' ';

  switch (subtipo) {
    case jugador_: out = 'j'; break;
    case aldeano: out = 'a'; break;
  }

  return out;
}

string strAccion(int accion) {
  string out = "";

  switch (accion) {
    case 0: out = "actFORWARD"; break;
    case 1: out = "actTURN_L"; break;
    case 2: out = "actTURN_R"; break;
    case 3: out = "actIDLE"; break;
  }

  return out;
}


string Entidad::toString() {
  char aux[20];
  string saux;

  string str;

  sprintf(aux,"%d",vida);
  saux = aux;
  str += "Vida restante: " + saux + "\n";

  sprintf(aux,"%d",colision);
  saux = aux;
  str += "He colisionado? " + saux + "\n";

  sprintf(aux,"%d",reset);
  saux = aux;
  str += "Acabo de morir? " + saux + "\n";

  str += "Posicion actual: (F ";
    sprintf(aux,"%d", getX());
    saux = aux;
    str += saux;
    str += " , C ";
    sprintf(aux,"%d", getY());
    saux = aux;
    str += saux;
    str += ")";
    str += "\n";

  str += "Ultima Accion: " + strAccion(last_action) + "\n";

  sprintf(aux, "%3.3f", tiempo/CLOCKS_PER_SEC);
  saux = aux;

  str += "Tiempo Consumido: " + saux + "\n";

  if(visionAux.size() > 0) {
    str += "Superficie:\n";

    for(unsigned int i = 0; i<visionAux[1].size(); i++) {
      str += visionAux[1][i];
      str += "";
    }

    str += "\n";

    str += "Terreno:\n";

    for(unsigned int i = 0; i<visionAux[0].size(); i++) {
      str += visionAux[0][i];
      str += " ";
    }

    str += "\n";
  }

  return str;

}


void Entidad::fixTiempo_sig_accion(int celda){
  switch (celda) {
    case 'A': tiempo_sig_accion=10; break;
    case 'B': tiempo_sig_accion=5; break;
    case 'T': tiempo_sig_accion=2; break;
    case 'S': tiempo_sig_accion=1; break;
    default:
              tiempo_sig_accion=1;
      break;
  }

}
