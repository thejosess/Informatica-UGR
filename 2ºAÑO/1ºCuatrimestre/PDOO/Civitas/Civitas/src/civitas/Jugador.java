/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;

import java.util.ArrayList;

import java.lang.Float;

/**
 *
 * @author Enrique
 */
public class Jugador implements Comparable<Jugador> {
    static protected int CasasMax = 4;
    static protected int CasasPorHotel = 4;
    protected boolean encarcelado = false;
    static protected int HotelesMax = 4;
    private String nombre;
    private int numCasillaActual;
    static protected float PasoPorSalida = 1000;
    static protected float PrecioLibertad = 200;
    private boolean puedeComprar;
    private float saldo;
    static private float SaldoInicial = 7500;
    private ArrayList<TituloPropiedad> propiedades = new ArrayList<>();
    Sorpresa salvoconducto;
    
    void setSaldo(int i){
        saldo = i;
    }
    
    Jugador(String nombre) {
        this.nombre = nombre;
    }
    
    protected Jugador(Jugador otro){
        encarcelado = otro.encarcelado;
        nombre = otro.nombre;
        numCasillaActual = otro.numCasillaActual;
        puedeComprar = otro.puedeComprar;
        saldo = otro.saldo;
        propiedades = otro.propiedades;
        salvoconducto = otro.salvoconducto;
    }
    
    /*boolean cancelarHipoteca(int ip) {
        
    }*/
    
    int cantidadCasasHoteles() {
        int aux=0;
        for(int i = 0; i< propiedades.size(); i++)
        {
            aux += aux + propiedades.get(i).cantidadCasasHoteles();
        }
        return aux;
    }
    
    
    
    /*equal to 0: Object f is equal to the argument object
    less than 0: Object f is less than the argument object
    greater than 0: Object f is greater than the argument object*/

    
    @Override
    public int compareTo(Jugador arg0) {
        Float aux = this.getSaldo();
        return aux.compareTo(arg0.getSaldo());
    }
    
    /*boolean comprar(TituloPropiedad titulo) {
        
    }*/
    
    
    protected boolean debeSerEncarcelado() {
        if(this.isEncarcelado()) {
            return false;
        }
        
        else {
            if(!tieneSalvoConducto()) {
                return true;
            }
            
            else {
                this.perderSalvoConducto();
                Diario.getInstance().ocurreEvento("El jugador se libra de la cárcel ");
                return false;
            }
        }
    }
    
    boolean enBancarrota() {
        return saldo < 0;
    }
    
    boolean encarcelar(int numCasillaCarcel) {
        if(this.debeSerEncarcelado()) {
            this.moverACasilla(numCasillaCarcel);
            encarcelado = true;
            Diario.getInstance().ocurreEvento("Jugador encarcelado");
        }
        return encarcelado;
    }
    
    private boolean existeLaPropiedad(int ip) {
        return propiedades.contains(ip);
    }
    
    private int getCasasMax() {
        return CasasMax;
    }
    
    int getCasasPorHotel() {
        return CasasPorHotel;
    }
    
    private int getHotelesMax() {
        return HotelesMax;
    }
    
    protected String getNombre() {
        return nombre;
    }
    
    int getNumCasillaActual() {
        return numCasillaActual;
    }
    
    private float getPrecioLibertad() {
        return PrecioLibertad;
    }
    
    private float getPremioPorSalida() {
        return PasoPorSalida;
    }
    
    protected ArrayList<TituloPropiedad> getPropiedades() {
        return propiedades;
    }
    
    boolean getPuedeComprar() {
        return puedeComprar;
    }
    
    protected float getSaldo() {
        return saldo;
    }
    
    /*boolean hipotecar(int ip) {
        
    }*/
    
    public boolean isEncarcelado() {
        return encarcelado;
    }
    
    boolean modificarSaldo(float cantidad){
        saldo +=cantidad;
        return true;
    }
    
    boolean moverACasilla(int numCasilla){
        if(this.isEncarcelado()) {
            return false;
        }
        
        else {
            numCasillaActual = numCasilla;
            puedeComprar = false;
            Diario.getInstance().ocurreEvento("Jugador movido de casilla");
            return true;
        }
    }
    
    boolean obtenerSalvoconducto(Sorpresa sorpresa){
        if(this.isEncarcelado()) {
            return false;
        }
        
        else {
            salvoconducto = sorpresa;
            return true;
        }
    }
    
    boolean paga(float cantidad){
        return this.modificarSaldo(cantidad*(-1));
    }
    
    boolean pagaAlquiler(float cantidad){
        if(this.isEncarcelado()) {
            return false;
        }
        
        else {
            return this.paga(cantidad);
        }
    }
    
    boolean pagaImpuesto(float cantidad){
        if(this.isEncarcelado()) {
            return false;
        }
        
        else {
            return this.paga(cantidad);
        }
    }
    
    boolean pasaPorSalida(){
        this.modificarSaldo(this.getPremioPorSalida());
        Diario.getInstance().ocurreEvento("El jugador pasa por la salida y cobra");
        return true;
    }
    
    void perderSalvoConducto(){
        salvoconducto.usada();
        salvoconducto = null;
    }
    
    boolean puedeComprarCasilla(){
        if(this.isEncarcelado()) {
            puedeComprar = false;
        }
        
        else {
            puedeComprar = true;
        }
        
        return puedeComprar;
    }
    
    boolean puedeSalirCarcelPagando(){
        return saldo >= PrecioLibertad;
    }
    
    /*boolean contruirCasa(TituloPropiedad titulo){
        return titulo.contruirCasa(this);
    }
    
    boolean construirHotel(TituloPropiedad titulo){
        return titulo.construirHotel(this);
    }*/
    
    boolean puedoGastar(float precio){
        if(this.isEncarcelado()) {
            return false;
        }
        
        else {
            return saldo >= precio;
        }
    }
    
    boolean recibe(float cantidad){
        if(this.isEncarcelado()) {
            return false;
        }
        
        else {
            return this.modificarSaldo(cantidad);
        }
    }
    
    boolean salirCarcelPagando(){
        if(this.isEncarcelado() && this.puedeSalirCarcelPagando()) {
            this.paga(PrecioLibertad);
            encarcelado = false;
            Diario.getInstance().ocurreEvento("El jugador paga y sale de la cárcel");
            return true;
        }
        
        else {
            return false;
        }
    }
    
    boolean salirCarcelTirando(){
        if(Dado.getInstance().salgoDeLaCarcel()) {
            encarcelado = false;
            Diario.getInstance().ocurreEvento("El jugador sale de la cárcel");
            return true;
        }
        
        else {
            return false;
        }
    }
    
    boolean tieneAlgoQueGestionar(){
        return !this.getPropiedades().isEmpty();
    }
    
    boolean tieneSalvoConducto(){
        return salvoconducto != null;
    }

    @Override
    public String toString() {
        return "Jugador{" + "encarcelado=" + encarcelado + ", nombre=" + nombre + ", numCasillaActual=" + numCasillaActual + 
                ", puedeComprar=" + puedeComprar + ", saldo=" + saldo + ", propiedades=" + propiedades + '}';
    }
    
    boolean vender(int ip){
        if(this.isEncarcelado()) {
            return false;
        }
        
        else {
            TituloPropiedad titulo = null;
            if(this.existeLaPropiedad(ip) && titulo.vender(this)) {
                propiedades.remove(ip);
                Diario.getInstance().ocurreEvento("Propiedad vendida con éxito");
                return true;
            }
            
            else {
                return false;
            }
        }
    }
}