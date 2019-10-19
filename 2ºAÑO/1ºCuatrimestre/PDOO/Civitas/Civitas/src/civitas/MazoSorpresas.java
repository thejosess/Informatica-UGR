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
public class MazoSorpresas {
    private ArrayList<Sorpresa> sorpresas;
    private Boolean barajada;
    private int usadas;
    private Boolean debug;
    private ArrayList<Sorpresa> cartasEspeciales;
    private Sorpresa ultimaSorpresa;
    
    private void init() {
        sorpresas = new ArrayList<>();
        cartasEspeciales = new ArrayList<>();
        barajada = false;
        usadas = 0;
    }
    
    MazoSorpresas(Boolean d) {
        d = debug;
        this.init();
        
        if(debug == true) {
            Diario.getInstance().ocurreEvento("debug ya activado");
        }
    }
    
    MazoSorpresas() {
        this.init();
        debug = false;
    }
    
    void alMazo(Sorpresa s) {
        if(barajada == false) {
            sorpresas.add(s);
        }
    }
    
    Sorpresa getUltimaSorpresa(){
        return ultimaSorpresa;
    }
    
    Sorpresa siguiente() {
        if(barajada == false || usadas == sorpresas.size()) {
            if(debug != true) {
                
                Collections.shuffle(sorpresas);
                usadas = 0;
                barajada = true;
            }
        }
        
        usadas++;
        Sorpresa aux = sorpresas.get(0);
        sorpresas.remove(0);
        sorpresas.add(aux);
        ultimaSorpresa = aux;
        
        return ultimaSorpresa;
    }
    
    void inhabilitarCartaEspecial(Sorpresa sorpresa) {
        if(sorpresas.contains(sorpresa)) {
            sorpresas.remove(sorpresa);
            cartasEspeciales.add(sorpresa);
            String evento = "inhabilitarCartaEspecial"; 
            Diario.getInstance().ocurreEvento(evento);
            //preguntar funcionamiento diario
        }
        
        
    }
    
    void habilitarCartaEspecial(Sorpresa sorpresa) {
        if(cartasEspeciales.contains(sorpresa)) {
            cartasEspeciales.remove(sorpresa);
            sorpresas.add(sorpresa);
            String evento = "habilitarCartaEspecial";
            Diario.getInstance().ocurreEvento(evento);
        }
    }
}
