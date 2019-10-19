/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;

import java.util.ArrayList;
import java.util.Collections;

/**
 *
 * @author Jose
 */
public class CivitasJuego {
    
    private int indiceJugadorActual;
    private Tablero tablero;
    private ArrayList<Jugador> jugadores = new ArrayList<>();
    private EstadosJuego estado ;
    private GestorEstados gestorEstados;
    private MazoSorpresas mazo;
    
    CivitasJuego(ArrayList<String> nombres){
        for(int i = 0; i < nombres.size(); i++)
        {
            Jugador jugador = new Jugador(nombres.get(i));
            jugadores.add(jugador);
        }
        gestorEstados = new GestorEstados();
        estado = gestorEstados.estadoInicial();
        indiceJugadorActual = Dado.getInstance().quienEmpieza(jugadores.size());
        mazo = new MazoSorpresas(); 
        this.inicializarTablero(mazo);
        this.inicialiarMazoSorpresas(tablero);
    }
    
    /*private void avanzaJugador(){
        
    }*/
    
    /*public boolean cancelarHipoteca(int ip){
        
        return true;
    }*/
    
    /*public boolean comprar(){
        return true;
    }*/
    
    /*public boolean construirCasa(int ip){
        return this.getJugadorActual().puedeEdificarCasa(titulo);
    }
    
    public boolean construirHotel(int ip){
        return this.getJugadorActual().puedeEdificarCasa(titulo);
    }*/
    
    private void contabilizarPasosPorSalida(Jugador jugadorActual){
        boolean seguir=true;
                
        while(seguir)
        {
            if(tablero.getPorSalida() ==  0)
                seguir = false;
            else
                jugadorActual.pasaPorSalida();
        }
    }
    
    public boolean finalDelJuego(){
        boolean end = false;
        
        for(int i = 0; i < jugadores.size() && !end; i++)
        {
            if(jugadores.get(i).enBancarrota())
                end = true;
        }
        
        return end;
    }
    
    public Jugador getJugadorActual(){
        return jugadores.get(indiceJugadorActual);
    }
    
    /*public boolean hipotecar(int ip){
        return this.getJugadorActual().hipotecar(ip);;
    }*/
    
    public String infoJugadorTexto(){
        return jugadores.get(indiceJugadorActual).toString();
    }
    
     void inicialiarMazoSorpresas(Tablero tablero){
        mazo.alMazo(new Sorpresa(TipoSorpresa.PAGARCOBRAR, -100, "Te han multado por ir a 10km/h con el coche TORTUGA"));
        mazo.alMazo(new Sorpresa(TipoSorpresa.PAGARCOBRAR,250,"Saludas a los autobuseros, por ser un buen ciudadano recibes 250 euros"));
        mazo.alMazo(new Sorpresa(TipoSorpresa.IRCASILLA, tablero, 4, "Te has caido en una alcantarilla y apareces en china, te mueves 4 casillas" ));
        mazo.alMazo(new Sorpresa(TipoSorpresa.IRCASILLA,tablero,2,"tropezar y no caerte es avanzar, te mueves dos casillas"));
        mazo.alMazo(new Sorpresa(TipoSorpresa.IRACARCEL,tablero));
        mazo.alMazo(new Sorpresa(TipoSorpresa.PORCASAHOTEL,25,"Recibes dinero por pasar por tu territorio, toma 25" ));
        mazo.alMazo(new Sorpresa( TipoSorpresa.PORCASAHOTEL,-10,"No es tu territorio ahora pagas 10"));
        mazo.alMazo(new Sorpresa(TipoSorpresa.PORJUGADOR, -12, "le pagas al resto de jugadores 12"));
        mazo.alMazo(new Sorpresa(TipoSorpresa.PORJUGADOR, 12, "Hoy es el dia de la felicidad, todos los jugadores te dan 12"));
        mazo.alMazo(new Sorpresa(TipoSorpresa.SALIRCARCEL, mazo ));
    }
    
     void inicializarTablero(MazoSorpresas mazo){
        tablero = new Tablero(5); //se supone que puedes poner la casilla de carcel que quieras        
        tablero.añadeCasilla(new Casilla("Parking"));
        tablero.añadeCasilla(new Casilla(5, "Juez"));
        tablero.añadeCasilla(new Casilla(100f, "Impuesto"));
        tablero.añadeCasilla(new Casilla(mazo, "Sorpresa 1"));
        tablero.añadeCasilla(new Casilla(mazo, "Sorpresa 2"));
        tablero.añadeCasilla(new Casilla(mazo, "Sorpresa 3"));
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("C1", 150f, 200f, 80f, 45f, 140f)));
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("C2", 170f, 250f, 90f, 55f, 140f)));
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("C3", 190f, 300f, 100f, 65f, 140f)));
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("C4", 210f, 350f, 110f, 75f, 140f)));
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("C5", 230f, 400f, 120f, 85f, 140f)));
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("C6", 250f, 450f, 130f, 95f, 140f)));
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("C7", 270f, 500f, 140f, 45f, 140f)));
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("C8", 290f, 550f, 150f, 45f, 140f)));
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("C9", 310f, 600f, 160f, 45f, 140f)));
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("C10", 330f, 650f, 170f, 45f, 140f)));
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("C11", 350f, 700f, 180f, 45f, 140f)));
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("C12", 370f, 750f, 190f, 45f, 140f)));
    }
    
    private void pasarTurno(){
        indiceJugadorActual = (indiceJugadorActual + 1) % jugadores.size();     //preguntar a David
    }
    
    private ArrayList<Jugador> ranking(){
        Collections.sort(jugadores);
        return jugadores;
    }
    
    public boolean salirCarcelPagando(){
        return this.getJugadorActual().salirCarcelPagando();
    }
    
    public boolean salirCarcelTirando(){
        return this.getJugadorActual().salirCarcelTirando();
    }
    
    public Casilla getCasillaActual(){
        int casilla = jugadores.get(indiceJugadorActual).getNumCasillaActual();
        return tablero.getCasilla(casilla);
    }
    
    /*public OperacionesJuego siguientePaso(){
        OperacionesJuego juego = OperacionesJuego.PASAR_TURNO;
        return juego;
    }*/
    
    public void siguientePasoCompletado(OperacionesJuego operacion){
        estado = gestorEstados.siguienteEstado(this.getJugadorActual(), estado, operacion);
    }
    
    public boolean vender(int ip){
        return this.getJugadorActual().vender(ip);
    }
    
    
}
