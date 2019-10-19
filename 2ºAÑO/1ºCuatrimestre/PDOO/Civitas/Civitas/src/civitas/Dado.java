/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;

import java.util.Random;

/**
 *
 * @author Jose
 */
class Dado {
    static final private Dado instance = new Dado();
    
    private Random random;
    private int ultimoResultado;
    private Boolean debug;
    
    static private int SalidaCarcel = 5;
    
    public static Dado getInstance() {
        return instance;
    }
    
    private Dado() {
        random = new Random();
        ultimoResultado = 0;
        debug = false;
    }
    
    int tirar() {
        if(debug == false) {
            ultimoResultado = (random.nextInt(6)+1);
        }
        
        else {
            ultimoResultado = 1;
        }
        
        return ultimoResultado;
    }
    
    Boolean salgoDeLaCarcel() {
        int valor = this.tirar();
        System.out.println("Valor dado = " + valor);
        //esto de cout creo que está mal
        if(valor >= 5) {
            return true;
        }
        
        else {
            return false;
        }
    }
    
    int quienEmpieza(int n) {
        return (random.nextInt(n));
    }
    
    void setDebug(Boolean d) {
        debug = d;
    }
    
    int getUltimoResultado() {
        return ultimoResultado;
    }
}
