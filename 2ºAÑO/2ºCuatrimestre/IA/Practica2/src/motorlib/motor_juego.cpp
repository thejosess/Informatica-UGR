#include "motorlib.hpp"

#include <unistd.h>

extern MonitorJuego monitor;

bool actuacionJugador(unsigned char celda, Action accion, unsigned int x, unsigned int y) {
  unsigned int mix, miy;
  unsigned char celdaRand;
  bool salida = false;

  switch (accion) {
    case actFORWARD:
      if (monitor.getMapa()->casillaOcupada(0) == -1) {
        switch (celda) {
          case 'M': // Muro
          case 'D':
                monitor.get_entidad(0)->seAostio(); break;
          case 'P': // Precipicio
                  do {
                    mix = aleatorio(monitor.getMapa()->getNFils()-1);
                    miy = aleatorio(monitor.getMapa()->getNCols()-1);

                    celdaRand = monitor.getMapa()->getCelda(mix, miy);
                  }
                  while(celdaRand == 'P' or celdaRand == 'M' or monitor.getMapa()->entidadEnCelda(mix, miy) == '_' );

                  monitor.get_entidad(0)->setPosicion(mix,miy);
                  monitor.get_entidad(0)->setOrientacion(norte);
                  monitor.get_entidad(0)->resetEntidad();
                  monitor.get_entidad(0)->setHitbox(true);
                  monitor.finalizarJuego();
                  monitor.setMostrarResultados(true);

                  break;
          case 'K': monitor.get_entidad(0)->notify();
          case 'B':
          case 'A':
          default:
            monitor.get_entidad(0)->setPosicion(x,y);
            salida = true;
            break;
        }
        monitor.get_entidad(0)->fixTiempo_sig_accion(celda);
      }
      else{
        monitor.get_entidad(0)->seAostio();
        /*if (monitor.get_entidad(monitor.getMapa()->casillaOcupada(0))->getSubTipo() == aldeano) {
            monitor.get_entidad(0)->perderPV(1);
        }*/
        salida = false;
      }
    break;

    case actTURN_R:
      switch (monitor.get_entidad(0)->getOrientacion()) {
        case norte:
          monitor.get_entidad(0)->setOrientacion(este);
        break;

        case este:
          monitor.get_entidad(0)->setOrientacion(sur);
        break;

        case sur:
          monitor.get_entidad(0)->setOrientacion(oeste);
        break;

        case oeste:
          monitor.get_entidad(0)->setOrientacion(norte);
        break;
      }
      monitor.girarJugadorDerecha();
      salida = true;
    break;

    case actTURN_L:
      switch (monitor.get_entidad(0)->getOrientacion()) {
        case norte:
          monitor.get_entidad(0)->setOrientacion(oeste);
        break;

        case este:
          monitor.get_entidad(0)->setOrientacion(norte);
        break;

        case sur:
          monitor.get_entidad(0)->setOrientacion(este);
        break;

        case oeste:
          monitor.get_entidad(0)->setOrientacion(sur);
        break;
        }
        monitor.girarJugadorIzquierda();
        salida = true;
    break;

    case actIDLE:
      salida = true;
    break;
  }

  return salida;
}

bool actuacionNPC(unsigned int entidad, unsigned char celda, Action accion, unsigned int x, unsigned int y) {
  bool out = false;
  switch (monitor.get_entidad(entidad)->getSubTipo()) {
      case aldeano: //Acciones para el aldeano
        switch (accion) {
          case actFORWARD:
           if ((celda != 'P' and celda != 'M') and monitor.getMapa()->casillaOcupada(entidad) == -1) {
             monitor.get_entidad(entidad)->setPosicion(x,y);
             out = true;
           }
           break;

          case actTURN_R:
            switch (monitor.get_entidad(entidad)->getOrientacion()) {
              case norte:
                monitor.get_entidad(entidad)->setOrientacion(este);
                break;

              case este:
                monitor.get_entidad(entidad)->setOrientacion(sur);
                break;

              case sur:
                monitor.get_entidad(entidad)->setOrientacion(oeste);
                break;

              case oeste:
                monitor.get_entidad(entidad)->setOrientacion(norte);
                break;
            }
            out = true;
            break;

          case actTURN_L:
            switch (monitor.get_entidad(entidad)->getOrientacion()) {
              case norte:
                monitor.get_entidad(entidad)->setOrientacion(oeste);
                break;

              case este:
                monitor.get_entidad(entidad)->setOrientacion(norte);
                break;

              case sur:
                monitor.get_entidad(entidad)->setOrientacion(este);
                break;

              case oeste:
                monitor.get_entidad(entidad)->setOrientacion(sur);
                break;
            }
            out = true;
            break;
        }
  }
  return out;
}

bool actuacion(unsigned int entidad, Action accion) {
  bool out = false;
  unsigned char celda, objetivo;
  unsigned int x,y;

  //Calculamos cual es la celda justo frente a la entidad
  switch (monitor.get_entidad(entidad)->getOrientacion()) {
    case norte:
      x = monitor.get_entidad(entidad)->getX() - 1;
      y = monitor.get_entidad(entidad)->getY();
    break;

    case sur:
      x = monitor.get_entidad(entidad)->getX() + 1;
      y = monitor.get_entidad(entidad)->getY();
    break;

    case este:
      x = monitor.get_entidad(entidad)->getX();
      y = monitor.get_entidad(entidad)->getY() + 1;
    break;

    case oeste:
      x = monitor.get_entidad(entidad)->getX();
      y = monitor.get_entidad(entidad)->getY() - 1;
    break;
  }

  celda = monitor.getMapa()->getCelda(x,y);

  //Dependiendo el tipo de la entidad actuamos de una forma u otra
  switch (monitor.get_entidad(entidad)->getTipo()) {
    case jugador:
      out = actuacionJugador(celda, accion,  x, y);
    break;

    case npc:
      out = actuacionNPC(entidad, celda, accion, x, y);
    break;
  }

  return out;
}

void nucleo_motor_juego(MonitorJuego &monitor, int acc, GLUI_EditText * editPosX, GLUI_EditText * editPosY) {
  Action accion;
  unsigned char celdaRand;

  vector < vector < vector <unsigned char> > > estado;

  estado.clear();

  for(unsigned int i = 0; i < monitor.numero_entidades(); i++) {
    estado.push_back(monitor.getMapa()->vision(i));
  }

  if (monitor.get_entidad(0)->ready()){
    clock_t t0 = clock();
    accion = monitor.get_entidad(0)->think(acc, estado[0], monitor.getLevel());
    clock_t t1 = clock();

    monitor.get_entidad(0)->addTiempo(t1-t0);
    monitor.get_entidad(0)->getLastAction(accion);
    actuacion(0, accion);
    monitor.get_entidad(0)->setVision(monitor.getMapa()->vision(0));
  }
  else {
    monitor.get_entidad(0)->perderPV(1);
  }


    for(unsigned int i = 1; i < monitor.numero_entidades(); i++) {
      clock_t t0 = clock();
      accion = monitor.get_entidad(i)->think(-1, estado[i], monitor.getLevel());
      clock_t t1 = clock();

      monitor.get_entidad(i)->addTiempo(t1-t0);
      actuacion(i, accion);
      monitor.get_entidad(i)->setVision(monitor.getMapa()->vision(i));
    }


  monitor.get_entidad(0)->decTiempo_sig_accion();
  monitor.decPasos(editPosX, editPosY);


  if (acc != -1) {
    sleep(monitor.getRetardo() / 10);
  }
}

bool lanzar_motor_juego(int & colisiones, int acc, GLUI_EditText * editPosX, GLUI_EditText * editPosY) {
  bool out = false;

  if (monitor.continuarBelkan()) {
    if (monitor.jugar()) {
      if ((monitor.getPasos() != 0) and (!monitor.finJuego())) {
        unsigned char celdaRand;
        if (monitor.getObjY() >= monitor.getMapa()->getNFils() or monitor.getObjX() >= monitor.getMapa()->getNCols()){
          celdaRand = 'P';
        }
        else {
          celdaRand = monitor.getMapa()->getCelda(monitor.getObjY(), monitor.getObjX());
        }

        if (celdaRand == 'P' or celdaRand == 'M'){
          int mix = -1, miy = -1;
          do {
            miy = aleatorio(monitor.getMapa()->getNFils()-1);
            mix = aleatorio(monitor.getMapa()->getNCols()-1);

            celdaRand = monitor.getMapa()->getCelda(miy, mix);
          }
          while( (celdaRand == 'P' or celdaRand == 'M') );

          monitor.setObjX(mix);
          monitor.setObjY(miy);
          if (editPosX != NULL)
          editPosX->set_int_val(mix);
          if (editPosY != NULL)
          editPosY->set_int_val(miy);
          cout << "Cambiado el objetivo\n";
        }
        nucleo_motor_juego(monitor, acc, editPosX, editPosY);
	      colisiones += monitor.get_entidad(0)->getColisiones();
      }
    }

    if (monitor.mostrarResultados()) {
      unsigned int aciertos = 0, totalCasillas = 0, fallos = 0;

      for(unsigned int i = 0; i < monitor.getMapa()->getNCols(); i++) {
        for(unsigned int j = 0; j < monitor.getMapa()->getNCols(); j++) {
          if (monitor.getMapa()->getCelda(i, j) == monitor.get_entidad(0)->getMapaResultado()[i][j]) {
            aciertos++;
          }
          else if (monitor.getMapa()->getCelda(i, j) != monitor.get_entidad(0)->getMapaResultado()[i][j] and monitor.get_entidad(0)->getMapaResultado()[i][j]!='?') {
            fallos++;
          }
          totalCasillas++;
        }
      }
      cout << "Tiempo Consumido: " << 1.0 * monitor.get_entidad(0)->getTiempo() / CLOCKS_PER_SEC << endl;
      cout << "Fallos: " << fallos << endl;
      cout << "Colisiones: " << colisiones << endl;
      cout << "Muertes: " << monitor.get_entidad(0)->getMuertesI() << endl;
      cout << "Objetivos encontrados: " << monitor.get_entidad(0)->getMisiones() << endl;
      monitor.setMostrarResultados(false);

      out = true;
    }
  }
  return out;
}


void lanzar_motor_juego2(MonitorJuego &monitor) {
  int colisiones = 0;

  monitor.get_entidad(0)->setObjetivo(monitor.getObjX(), monitor.getObjY());

  while (!monitor.finJuego() && monitor.jugar()) {
      nucleo_motor_juego(monitor,-1, NULL, NULL);
      colisiones += monitor.get_entidad(0)->getColisiones();
  }

  if (monitor.mostrarResultados()) {
    unsigned int aciertos = 0, totalCasillas = 0, fallos = 0;

    for(unsigned int i = 0; i < monitor.getMapa()->getNCols(); i++) {
      for(unsigned int j = 0; j < monitor.getMapa()->getNCols(); j++) {
        if (monitor.getMapa()->getCelda(i, j) == monitor.get_entidad(0)->getMapaResultado()[i][j]) {
          aciertos++;
        }
        else if (monitor.getMapa()->getCelda(i, j) != monitor.get_entidad(0)->getMapaResultado()[i][j] and monitor.get_entidad(0)->getMapaResultado()[i][j]!='?') {
          fallos++;
        }
        totalCasillas++;
      }
    }
    cout << "Tiempo Consumido: " << 1.0 * monitor.get_entidad(0)->getTiempo() / CLOCKS_PER_SEC << endl;
    cout << "Fallos: " << fallos << endl;
    cout << "Colisiones: " << colisiones << endl;
    cout << "Muertes: " << monitor.get_entidad(0)->getMuertesI() << endl;
    cout << "Objetivos encontrados: " << monitor.get_entidad(0)->getMisiones() << endl;
    monitor.setMostrarResultados(false);
  }
}
