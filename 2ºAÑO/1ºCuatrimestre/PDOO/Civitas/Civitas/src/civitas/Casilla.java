/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;

import java.util.ArrayList;

/**
 *
 * @author Enrique
 */
public class Casilla {
    private String nombre;
    private static int carcel;
    private float importe;
    private TipoCasilla tipo;
    private TituloPropiedad tituloPropiedad; // tipo Calle ?
    private Sorpresa sorpresa;
    private MazoSorpresas mazo;              //duda
    
    Casilla(String nom) {
        this.init();
        nombre = nom;
        tipo = TipoCasilla.DESCANSO;
    }
    
    Casilla(TituloPropiedad titulo){
        this.init();
        tituloPropiedad = titulo;
        tipo = TipoCasilla.CALLE;
        nombre = titulo.getNombre();
        
    }
    
    Casilla(float cantidad, String nombre){
        this.init();
        importe = cantidad;
        this.nombre = nombre;
        tipo = TipoCasilla.IMPUESTO;
    }
    
    Casilla(int numCasillaCarcel, String nombre){
        this.init();
        carcel = numCasillaCarcel;
        this.nombre = nombre;
        tipo = TipoCasilla.JUEZ;
    }
    
    Casilla(MazoSorpresas mazo, String nombre){
        this.init();
        this.mazo = mazo;
        this.nombre = nombre;
        tipo = TipoCasilla.SORPRESA;
        //this.sorpresa = mazo.siguiente();
    }
    
    public String getNombre() {
        return nombre;
    }
    
    TituloPropiedad getTituloPropiedad(){
        return tituloPropiedad;
    }
    
    private void informe(int actual, ArrayList<Jugador> todos){
        Diario.getInstance().ocurreEvento("El jugador "+ todos.get(actual).getNombre()+ " ha caido en la casilla"  );
        this.toString();
    }
    
    private void init(){
        nombre = "\0";
        carcel = 0;
        importe = 0;
        tipo = null;
        tituloPropiedad = null;
        sorpresa = null;
        mazo = null;
    }
    
    public boolean jugadorCorrecto(int iactual, ArrayList<Jugador> todos){
        return (iactual >= 0 && iactual < todos.size());
    }
    
    /*void recibeJugador(int iactual, ArrayList<Jugador> todos){
        
    }
    
    private void recibeJugador_calle(int iactual, ArrayList<Jugador> todos){
        
    }*/
    
    
    private void recibeJugador_impuesto(int iactual, ArrayList<Jugador> todos){
        if(this.jugadorCorrecto(iactual, todos)) {
            this.informe(iactual, todos);
            todos.get(iactual).pagaImpuesto(importe);
        }
    }
    
    private void recibeJugador_juez(int iactual, ArrayList<Jugador> todos){
        if(this.jugadorCorrecto(iactual, todos)) {
            this.informe(iactual, todos);
            todos.get(iactual).encarcelar(carcel);
        }
    }
    
    /*private void recibeJugador_sorpresa(int iactual, ArrayList<Jugador> todos){
        
    }*/

    @Override
    public String toString() {
        return "Casilla{" + "nombre=" + nombre + ", importe=" + importe + ", tipo=" + tipo + ", tituloPropiedad=" + tituloPropiedad + '}';
    }   
}