/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;

/**
 *
 * @author Jose
 */
public class TituloPropiedad {
    private float alquilerBase = 0;
    static private float factorInteresesHipoteca = (float) 1.1; //mal diagrama, cambiar float a double
    private float factorRevalorizacion = 0;
    private float hipotecaBase = 0;
    private boolean hipotecado = false;
    private String nombre = "";
    private int numCasas = 0;
    private int numHoteles = 0;
    private float precioCompra = 0;
    private float precioEdificar = 0;
    private Jugador propietario = null;
    
    TituloPropiedad(String nom, float ab, float fr, float hb, float pc, float pe) {
        nombre = nom;
        alquilerBase = ab;
        factorRevalorizacion = fr;
        hipotecaBase = hb;
        precioCompra = pc;
        precioEdificar = pe;
    }
    
    void actualizarPropietarioPorConversion(Jugador jugador) {
        propietario = jugador;
    }
    
    boolean cancelarHipoteca(Jugador jugador) {
        if(hipotecado && esEsteElPropietario(jugador))
        {
            jugador.paga(getImporteCancelarHipoteca());
            hipotecado=false;
            return true;
        }
        else
            return false;     
    }
    
    int cantidadCasasHoteles() {
        return numCasas + numHoteles;
    }
    
   /* boolean comprar(Jugador jugador) {
        if(tienePropietario())
        {
            return false;
        }
        else
        {
            propietario = jugador;
            propietario.paga(precioCompra);
            return true;
        }
    }*/
    
    /*boolean contruirCasa(Jugador jugador) {
        boolean aux = false;
        if(propietario == jugador)
        {
            propietario.paga(precioEdificar);
            numCasas++;
            aux = true;
        }
        return aux;
    }*/
    
    /*boolean construirHotel(Jugador jugador) {
        boolean aux = false;
        if(propietario == jugador)
        {
            propietario.paga(precioEdificar);
            numHoteles++;
            aux = true;
        }
        return aux;
    }*/
    
    boolean derruirCasas(int n, Jugador jugador) {
        if(jugador == propietario && numCasas > n)
        {
            numCasas -= n;
            return true;
        }
        else
            return false;   
    }
    
    private boolean esEsteElPropietario(Jugador jugador) {
        if(jugador == propietario)
            return true;
        else
            return false;
    }
    
    public boolean getHipotecado() {
        return hipotecado;
    }
    
    float getImporteCancelarHipoteca() {
        return hipotecaBase*factorInteresesHipoteca;
    }
    
    private float getImporteHipoteca() {
        return hipotecaBase;
    }
    
    String getNombre() {
        return nombre;
    }
    
    int getNumCasas()  {
        return numCasas;
    }
    
    int getNumHoteles() {
        return numHoteles;
    }
    
    private float getPrecioAlquiler() {
        if(hipotecado || this.propietarioEncarcelado()) {
            return 0;
        }
        
        else {
            double aux = alquilerBase*(1.0+(numCasas*0.5) + (numHoteles*2.5));
            float alquiler = (float) aux;
            return alquiler;
        }
    }
    
    float getPrecioCompra() {
        return precioCompra;
    }
    
    float getPrecioEdificar() {
        return precioEdificar;
    }
    
    private float getPrecioVenta() {
        return precioCompra + (precioEdificar*factorRevalorizacion);
    }
    
    Jugador getPropietario() {
        return propietario;
    }
    
    /*boolean hipotecar(Jugador jugador) {
        if(!hipotecado && this.esEsteElPropietario(jugador)) {
            jugador.recibe(hipotecaBase);
            hipotecado = true;
            return true;
        }
        
        else {
            return false;
        }
    }*/
    
    private boolean propietarioEncarcelado() {
        boolean aux = true;
        if(!propietario.encarcelado || propietario == null) {
            aux = false;
        }
        
        else if(propietario.encarcelado) {
            aux = true;
        }
        
        return aux;
    }
    
    boolean tienePropietario() {
        return propietario != null;
    }

    @Override
    public String toString() {
        return "TituloPropiedad{" + "\n" + ", nombre=" + nombre + "\n" + "alquilerBase=" + alquilerBase + "\n" + ", factorRevalorizacion=" + factorRevalorizacion + "\n" + ", hipotecaBase=" 
                + hipotecaBase + "\n" + ", hipotecado=" + hipotecado + "\n" + ", numCasas=" + numCasas + "\n" + ", numHoteles=" + numHoteles + "\n" + ", precioCompra= " + precioCompra + "\n" +", precioEdificar="
                + precioEdificar + "\n" + ", propietario= " + propietario + '}';
    }
    

    
    void tramitarAlquiler(Jugador jugador) {
        if(propietario != null && !esEsteElPropietario(jugador))
            jugador.pagaAlquiler(this.getPrecioAlquiler());
            propietario.recibe(this.getPrecioAlquiler());
    }
    
    boolean vender(Jugador jugador) {
        if(esEsteElPropietario(jugador))
        {
            float precioVenta = precioCompra+(numCasas+5*numHoteles)*precioEdificar*factorRevalorizacion;
            propietario.recibe(precioVenta);
            propietario = null;
            return true;
        }
        else
        {
            return false;
        }
    }
}
