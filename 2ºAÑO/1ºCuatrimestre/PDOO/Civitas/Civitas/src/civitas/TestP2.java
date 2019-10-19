/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Jose
 */
public class TestP2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        
        System.out.println("\n\n *****Prueba TituloPropiedad*****");
        
        TituloPropiedad titulo = new TituloPropiedad("Eoo", 100, 2, 150, 200, 250);
        System.out.println(titulo.toString());
        
        Jugador jugador = new Jugador("hola");
        
        //titulo.setJugador(jugador);
        if(titulo.vender(jugador))
        {
            System.out.println("Kike bien");
        }
        
        /*titulo.setJugador(jugador);
        
        if(titulo.cancelarHipoteca(jugador))
            System.out.println("\nBien");
        else
            System.out.println("\nMal");
        
        if(!titulo.propietarioEncarcelado())
            System.out.println("\nBien x2");
        
       
        
        titulo.tramitarAlquiler(jugador2);*/
        
        
        System.out.println("\n\n *****Prueba Sorpresa*****");
        Tablero tablero = new Tablero(5);
        
         Jugador jugador2 = new Jugador("caca");
        
        ArrayList<Jugador> todos = new ArrayList<>();
        todos.add(jugador);
        todos.add(jugador2);
        
        /* MazoSorpresas mazo = new MazoSorpresas();
        
        mazo.alMazo(new Sorpresa(TipoSorpresa.SALIRCARCEL, mazo ));
        
        Sorpresa s1 = new Sorpresa(TipoSorpresa.IRACARCEL, tablero);
        Sorpresa s2 = new Sorpresa(TipoSorpresa.IRCASILLA, tablero,10, "PrUeBa");
        Sorpresa s3 = new Sorpresa(TipoSorpresa.PAGARCOBRAR, 25, "tuso");
        Sorpresa s4 = new Sorpresa(TipoSorpresa.SALIRCARCEL, mazo);
        
        Sorpresa s5 = new Sorpresa(TipoSorpresa.PORJUGADOR, 15, "premoh");
        Sorpresa s6 = new Sorpresa(TipoSorpresa.PORCASAHOTEL, 20, "kike tonto");
        
        s4.usada();
        
        s1.aplicarAJugador(0, todos);
        s2.aplicarAJugador(0, todos);
        s3.aplicarAJugador(0, todos);
        s4.aplicarAJugador(0, todos);
        s5.aplicarAJugador(0, todos);
        s6.aplicarAJugador(0, todos);*/
        
        
        Sorpresa s3 = new Sorpresa(TipoSorpresa.PAGARCOBRAR, 25, "tuso");
        s3.aplicarAJugador(0, todos);
        
        Casilla descanso = new Casilla("a descansar primo");
        //descanso.recibeJugador_impuesto(0, todos);
        //descanso.recibeJugador_juez(0, todos);

        
        Jugador tonto = new Jugador("histianogonagdo");
        Jugador josetonto = new Jugador(tonto);
        
        josetonto.setSaldo(1000);
        
        if(josetonto.compareTo(tonto) > 0 )
            System.out.println("\funciona, PRIMERO MAS GRANDE");
       
        
        ArrayList<String> nombres = new ArrayList<>();
        nombres.add("viva");
        nombres.add("españa");
        CivitasJuego dinamitamarchita = new CivitasJuego(nombres);
        
        System.out.println(dinamitamarchita.infoJugadorTexto());
        
        dinamitamarchita.finalDelJuego();
        System.out.println(dinamitamarchita.infoJugadorTexto());
        dinamitamarchita.salirCarcelPagando();
        dinamitamarchita.salirCarcelTirando();
        dinamitamarchita.siguientePasoCompletado(OperacionesJuego.AVANZAR);
        dinamitamarchita.getCasillaActual();
        
        MazoSorpresas mazo = new MazoSorpresas();
        
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
        
        dinamitamarchita.inicialiarMazoSorpresas(tablero);
        dinamitamarchita.inicializarTablero(mazo);
        
        dinamitamarchita.vender(4);
        
        Jugador pruebaC = new Jugador(tonto);
        
    }  
}
