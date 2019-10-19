/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;

import java.util.ArrayList;

/**
 *
 * @author Jose
 */
public class Sorpresa {
    private String texto;
    private int valor;
    private Tablero tablero;
    private MazoSorpresas mazo;
    private TipoSorpresa tipo;
    
    Sorpresa(TipoSorpresa tipo, Tablero tablero){
        this.init();
        if(tipo == TipoSorpresa.IRACARCEL) {
            valor = tablero.getCarcel();
            this.tablero = tablero;
            this.tipo = tipo;
        }
    }
    
    Sorpresa(TipoSorpresa tipo, Tablero tablero, int valor, String texto){
        this.init();
        if(tipo == TipoSorpresa.IRCASILLA) {
            this.tipo = tipo;
            this.texto = texto;
            this.tablero = tablero;
            this.valor = valor;
        }
    }
        
    Sorpresa(TipoSorpresa tipo, int valor, String texto){
        this.init();
        this.tipo = tipo;
        this.valor = valor;
        this.texto = texto;
    }
    
    Sorpresa(TipoSorpresa tipo, MazoSorpresas mazo){
        this.init();
        if(tipo == TipoSorpresa.SALIRCARCEL) {
            this.tipo = tipo;
            this.mazo = mazo;
        }
    }
        
    void aplicarAJugador(int actual, ArrayList<Jugador> todos){
        if(tipo == TipoSorpresa.IRCASILLA)
            aplicarAJugador_irACasilla(actual,todos);
        else if(tipo == TipoSorpresa.IRACARCEL)
            aplicarAJugador_irCarcel(actual,todos);
        else if(tipo == TipoSorpresa.PAGARCOBRAR)
            aplicarAJugador_pagarCobrar(actual,todos);
        else if(tipo == TipoSorpresa.PORCASAHOTEL)
            aplicarAJugador_porCasaHotel(actual,todos);
        else if(tipo == TipoSorpresa.PORJUGADOR)
            aplicarAJugador_porJugador(actual,todos);
        else if(tipo == TipoSorpresa.SALIRCARCEL)
            aplicarAJugador_salirCarcel(actual,todos);
    }
    
    private void aplicarAJugador_irACasilla(int actual, ArrayList<Jugador> todos){
        if(this.jugadorCorrecto(actual, todos))
        {
            this.informe(actual, todos);
            int casillaActual = todos.get(actual).getNumCasillaActual();
            int tirada = tablero.calcularTirada(casillaActual, valor);
            int posicion = tablero.nuevaPosicion(casillaActual, tirada);
            todos.get(actual).moverACasilla(posicion);
            //tablero.getCasilla(casillaActual).recibeJugador(actual, todos);
            
        }
    }
    
    private void aplicarAJugador_irCarcel(int actual, ArrayList<Jugador> todos){
        if(this.jugadorCorrecto(actual, todos))
        {
            this.informe(actual, todos);
            todos.get(actual).encarcelar(tablero.getCarcel());
        }
    }
    
    private void aplicarAJugador_pagarCobrar(int actual, ArrayList<Jugador> todos){
        if(this.jugadorCorrecto(actual, todos))
        {
            this.informe(actual, todos);
            todos.get(actual).modificarSaldo(valor);
        }
    }
    
    private void aplicarAJugador_porCasaHotel(int actual, ArrayList<Jugador> todos){
        if(this.jugadorCorrecto(actual, todos))
        {
            this.informe(actual, todos);
            todos.get(actual).modificarSaldo(valor*todos.get(actual).cantidadCasasHoteles());
        }
    }
    
    private void aplicarAJugador_porJugador(int actual, ArrayList<Jugador> todos){
        if(this.jugadorCorrecto(actual, todos))
        {
            this.informe(actual, todos);
            
            Sorpresa s1 = new Sorpresa(TipoSorpresa.PAGARCOBRAR,valor*(-1),"pagarCobrar");
            for(int i = 0; i<todos.size(); i++)
            {
                if(i != actual)
                    s1.aplicarAJugador_pagarCobrar(i, todos);
            }
            
            Sorpresa s2 = new Sorpresa(TipoSorpresa.PAGARCOBRAR,valor*todos.size()-1,"pagarCobrar");
            s2.aplicarAJugador_pagarCobrar(actual, todos);
            
        }
    }
    
    private void aplicarAJugador_salirCarcel(int actual, ArrayList<Jugador> todos){
        boolean sigue = true;
        if(this.jugadorCorrecto(actual, todos))
        {
            this.informe(actual, todos);
            for(int i = 0; i < todos.size() && sigue; i++)
            {
                if(todos.get(i).tieneSalvoConducto())
                    sigue = false;
            }
            
            if(sigue)
                todos.get(actual).obtenerSalvoconducto(this);
            this.salirDelMazo();
        }
    }
    
    private void informe(int actual, ArrayList<Jugador> todos){
        Diario.getInstance().ocurreEvento("Se está aplicando una sorpresa al jugador " + todos.get(actual).getNombre());
    }
   
    private void init(){
        valor = -1;
        mazo = null;
        tablero = null;
    }
    
    public boolean jugadorCorrecto(int actual,ArrayList<Jugador> todos ){
        return actual >= 0 && actual < todos.size() ;
    }
    
    void salirDelMazo(){
        if(tipo == TipoSorpresa.SALIRCARCEL) {
            mazo.inhabilitarCartaEspecial(this);
        }
    }

    @Override
    public String toString() {
        return "Sorpresa{" + "texto=" + texto + ", valor=" + valor + ", tablero=" + tablero + ", mazo=" + mazo + ", tipo=" + tipo + '}';
    }
    
    
    
    void usada(){
        if(tipo == TipoSorpresa.SALIRCARCEL) {
            mazo.habilitarCartaEspecial(this);
        }
    }
    
}
