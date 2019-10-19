package civitas;

class GestorEstados {
  EstadosJuego estadoInicial() {
    return (EstadosJuego.INICIO_TURNO);
  }
  
  OperacionesJuego operacionesPermitidas(Jugador jugador, EstadosJuego estado) {
    OperacionesJuego op = null;

    switch (estado) {
      case INICIO_TURNO :
        if (jugador.encarcelado)
          op = OperacionesJuego.SALIR_CARCEL;
        else
          op = OperacionesJuego.AVANZAR;
        break;

      case DESPUES_CARCEL :
        op = OperacionesJuego.PASAR_TURNO;
        break;

      case DESPUES_AVANZAR :
        if (jugador.encarcelado)
          op = OperacionesJuego.PASAR_TURNO;
        else if (jugador.getPuedeComprar())
          op = OperacionesJuego.COMPRAR;
        else if (jugador.tieneAlgoQueGestionar())
          op = OperacionesJuego.GESTIONAR;
        else
          op = OperacionesJuego.PASAR_TURNO;
        break;

      case DESPUES_COMPRAR :
        if (jugador.tieneAlgoQueGestionar())
          op = OperacionesJuego.GESTIONAR;
        else
          op = OperacionesJuego.PASAR_TURNO;
        break;

      case DESPUES_GESTIONAR :
        op = OperacionesJuego.PASAR_TURNO;
        break;        
    }
    return op;
  }
  
  EstadosJuego siguienteEstado (Jugador jugador, EstadosJuego estado, OperacionesJuego operacion) {
    EstadosJuego siguiente = null;

    switch (estado) {
      case INICIO_TURNO :
        if (operacion==OperacionesJuego.SALIR_CARCEL)
          siguiente = EstadosJuego.DESPUES_CARCEL;
        else if (operacion==OperacionesJuego.AVANZAR)
          siguiente = EstadosJuego.DESPUES_AVANZAR;
        break;

      case DESPUES_CARCEL :
        if (operacion==OperacionesJuego.PASAR_TURNO)
          siguiente = EstadosJuego.INICIO_TURNO;
        break;

      case DESPUES_AVANZAR :
        switch (operacion) {
          case PASAR_TURNO :
            siguiente = EstadosJuego.INICIO_TURNO;
            break;
          case COMPRAR :
            siguiente = EstadosJuego.DESPUES_COMPRAR;
            break;
          case GESTIONAR :
            siguiente = EstadosJuego.DESPUES_GESTIONAR;
            break;
        }
        break;

      case DESPUES_COMPRAR :
        if (operacion==OperacionesJuego.GESTIONAR)
          siguiente = EstadosJuego.DESPUES_GESTIONAR;
        else if (operacion==OperacionesJuego.PASAR_TURNO)
          siguiente = EstadosJuego.INICIO_TURNO;
        break;

      case DESPUES_GESTIONAR :
        if (operacion==OperacionesJuego.PASAR_TURNO)
          siguiente = EstadosJuego.INICIO_TURNO;
        break;
    }
    
    //modificacion propia
    if(siguiente == null)
        Diario.getInstance().ocurreEvento("De: "+estado.toString()+ " con "+operacion.toString());
    else
        Diario.getInstance().ocurreEvento("De: "+estado.toString()+ " con "+operacion.toString()+ " sale: "+siguiente.toString());

    return siguiente;
  }

}