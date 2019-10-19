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
public class Tablero {
    private int numCasillaCarcel;
    private ArrayList<Casilla> casillas;
    private int porSalida;
    private Boolean tieneJuez;
    
    public Tablero(int carcel) {
        if(carcel >= 1) {
            numCasillaCarcel = carcel;
        }
        
        else {
            numCasillaCarcel = 1;
        }
        
        casillas = new ArrayList<>();
        casillas.add(new Casilla("Salida"));
        porSalida = 0;
        tieneJuez = false;        
    }
    
    private Boolean correcto() {
        if(casillas.size() >= numCasillaCarcel && tieneJuez) {
            return true;
        }
        
        else {
            return false;
        }
    }
    
    private Boolean correcto(int numCasilla) {
        if(this.correcto() == true && (numCasilla > 0 && numCasilla <= casillas.size())) {
            return true;
        }
        
        else {
            return false;
        }
    }
    
    int getCarcel() {
        return numCasillaCarcel;
    }
    
    int getPorSalida() {
        int valor = 0;
        
        if(porSalida > 0) {
            valor = porSalida;
            porSalida -= 1;
            return valor;
        }
        
        else {
            return porSalida;
        }
    }
    
    void añadeCasilla(Casilla casilla) {
        if(casillas.size() == numCasillaCarcel) {
            casillas.add(new Casilla("Cárcel"));
        }
        
        casillas.add(casilla);
            
        if(casillas.size() == numCasillaCarcel) {
                casillas.add(new Casilla("Cárcel"));
            }
        System.out.println(casillas.size());
    }
    
    void añadeJuez() {
        if(tieneJuez == false) {
            casillas.add(new Casilla("Juez"));
            tieneJuez = true;
        }
    }
    
    Casilla getCasilla(int numCasilla) {
        if(this.correcto(numCasilla)) {
            return casillas.get(numCasilla);
        }
        
        else {
            return null;
        }
    }
    
    int nuevaPosicion(int actual, int tirada) {
        int posFinal;
        
        if(this.correcto() == false) {
            return -1;
        }
        
        else {
            posFinal = (actual + tirada) % casillas.size();
            
            if(posFinal != (actual + tirada)) {
                porSalida++;
            }
            
            return posFinal;
        }
   }
    
    int calcularTirada(int origen, int destino) {
        int tirada;
        
        if((destino - origen) < 0) {
            tirada = destino - origen + casillas.size();
            return tirada;
        }
        
        else {
            tirada = destino - origen;
            return tirada;
        }
    }
}
