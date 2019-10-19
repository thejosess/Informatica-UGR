#include "motorlib/monitor.hpp"

#include <fstream>

void MonitorJuego::cambiarOrientacion(unsigned char entidad, unsigned char orientacion) {
  Orientacion aux;
  switch (orientacion) {
    case 0:
    	aux = norte;
    	break;

    case 1:
    	aux = este;
    	break;

    case 2:
    	aux = sur;
    	break;

    case 3:
    	aux = oeste;
    	break;
  }
  entidades[entidad]->setOrientacion(aux);
}

void MonitorJuego::setMapa(char * file) {
  ifstream ifile;
  ifile.open(file, ios::in);

  unsigned int colSize, filSize;
  ifile >> colSize;
  ifile >> filSize;

  vector<vector<unsigned char> > mapAux;
  vector<unsigned char> colAux(colSize);

  for (unsigned int i = 0; i < filSize; i++) {
    mapAux.push_back(colAux);
  }

  for (unsigned int i = 0; i < filSize; i++) {
    for (unsigned int j = 0; j < colSize; j++) {
      ifile >> mapAux[i][j];
    }
  }
  ifile.close();

  mapa = new Mapa(mapAux, &entidades);
}

bool MonitorJuego::inicializarJuego() {
  bool aux = empezarJuego;
  if (empezarJuego) {
      empezarJuego = false;
      resultados = false;
  }
  return aux;
}


void MonitorJuego::decPasos(GLUI_EditText * editPosX, GLUI_EditText * editPosY) {
  if (get_entidad(0)->fin()) {
    if (nivel < 4) {
      jugando = false;
      resultados = true;
    }
    else {
      // Nivel 4
      if ((maxPasos - pasosTotales) <= 0) {
        jugando = false;
        resultados = true;
      }
      else {
        // Nuevo destino
        if (objetivos.empty()) {
          int mix = -1, miy = -1;
          char celdaRand = '_';
          do {
            miy = aleatorio(getMapa()->getNFils()-1);
            mix = aleatorio(getMapa()->getNCols()-1);

            celdaRand = getMapa()->getCelda(miy, mix);
          }
          while( (celdaRand == 'P' or celdaRand == 'M') );

          setObjX(mix);
          setObjY(miy);
          if (editPosX != NULL)
          editPosX->set_int_val(mix);
          if (editPosY != NULL)
          editPosY->set_int_val(miy);
          cout << "Nuevo objetivo: (" << miy << "," << mix << ")" << endl;
          get_entidad(0)->resetFin();

          if (pasos > 0) {
            pasos--;
            pasosTotales++;
          }

        }
        else {
          pair<int,int> aqui = objetivos.front();
          objetivos.pop_front();
          setObjX(aqui.second);
          setObjY(aqui.first);
          get_entidad(0)->resetFin();

          if (pasos > 0) {
            pasos--;
            pasosTotales++;
          }

        }
      }
    }
  }
  else {
    if (pasos > 0) {
      pasos--;
      pasosTotales++;
    }

    if ((maxPasos - pasosTotales) <= 0) {
      jugando = false;
      resultados = true;
    }
  }
}

void MonitorJuego::setObjX(int valor) {
	objX = valor;
	if (jugar()) {
		get_entidad(0)->setObjetivo(objX, objY);
	}
}

void MonitorJuego::setObjY(int valor) {
	objY = valor;
	if (jugar()) {
		get_entidad(0)->setObjetivo(objX, objY);
	}
}

void MonitorJuego::inicializar(int mix, int miy) {
  clear();
  int tama = getMapa()->getNCols();

  int naldeanos = tama / 10;
  unsigned char celdaRand;

  //Primero SIEMPRE se coloca al jugador. SIEMPRE.
  if ((mix == -1) or (miy == -1)) {
    do {
      mix = aleatorio(getMapa()->getNFils()-1);
      miy = aleatorio(getMapa()->getNCols()-1);

      celdaRand = getMapa()->getCelda(mix, miy);
    }
    while( (celdaRand == 'P') or (celdaRand == 'M') or (getMapa()->entidadEnCelda(mix, miy) != '_') );
  }

  if ((nivel == 1) or (nivel == 2) or (nivel == 3)) {
    vector< vector< unsigned char> > mAux(getMapa()->getNFils(), vector< unsigned char>(getMapa()->getNCols(), '?'));
    for (int i = 0; i < getMapa()->getNFils(); i++)
      for (int j = 0; j < getMapa()->getNCols(); j++)
        mAux[i][j] = getMapa()->getCelda(i, j);

    nueva_entidad(new Entidad(jugador, jugador_, norte, mix, miy, new Jugador3D(""), new ComportamientoJugador(mAux), objX, objY, 3000));
  }
  else {
    nueva_entidad(new Entidad(jugador, jugador_, norte, mix, miy, new Jugador3D(""), new ComportamientoJugador(getMapa()->getNFils()), objX, objY, 3000));
  }

  if (nivel == 4) {
    for (int i=0; i<naldeanos; i++) {
      do {
        mix = aleatorio(getMapa()->getNFils()-1);
        miy = aleatorio(getMapa()->getNCols()-1);

        celdaRand = getMapa()->getCelda(mix, miy);
      }
      while( (celdaRand == 'P') or (celdaRand == 'M') or (getMapa()->entidadEnCelda(mix, miy) != '_') );

      nueva_entidad(new Entidad(npc, aldeano, norte, mix, miy, new Aldeano3D(""), new ComportamientoAldeano()));
    }
  }

  get_entidad(0)->setVision(getMapa()->vision(0));
  if ((nivel == 1) or (nivel == 2) or (nivel == 3))
  get_entidad(0)->notify();
}
