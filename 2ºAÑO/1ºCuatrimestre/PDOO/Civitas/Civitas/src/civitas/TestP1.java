/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;

import java.util.Scanner;

/**
 *
 * @author Jose
 */
public class TestP1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //TAREA 1
        System.out.println("\n\n *****TAREA 1*****");
        
        int tamanio = 20;
        
        int uno = 0;
        int dos = 0;
        int tres= 0;
        int cuatro = 0;
        
        for(int i = 1; i <= 100; i++) {
            int empieza = Dado.getInstance().quienEmpieza(4)+1;
            
            if(empieza == 1) {
                uno++;
            }
            
            else if(empieza == 2) {
                dos++;
            }
            
            else if(empieza == 3) {
                tres++;
            }
            
            else if(empieza == 4) {
                cuatro++;
            }
        }
        
        System.out.println("El jugador 1 ha salido " + uno + " veces");
        System.out.println("El jugador 2 ha salido " + dos + " veces");
        System.out.println("El jugador 3 ha salido " + tres + " veces");
        System.out.println("El jugador 4 ha salido " + cuatro + " veces");
        System.out.println("LA SUMA DE CADA VALOR DA: " + (uno + dos + tres + cuatro));
        
        //TAREA 2
        System.out.println("\n\n *****TAREA 2*****");
        Boolean deb = true;
        Dado.getInstance().setDebug(deb);
        System.out.println("Modo debug activado");
        int valor = Dado.getInstance().tirar();
        System.out.println("Valor dado: " + valor);
        
        deb = false;
        Dado.getInstance().setDebug(deb);
        System.out.println("Modo debug desactivado");
        valor = Dado.getInstance().tirar();
        System.out.println("Valor dado: " + valor);
        
        //TAREA 3
        System.out.println("\n\n *****TAREA 3*****");
        System.out.println("Tiramos el dado y sale: " + Dado.getInstance().tirar());
        System.out.println("El último resultado del dado es " + Dado.getInstance().getUltimoResultado());
        if(Dado.getInstance().salgoDeLaCarcel()) {
            System.out.println("Como ha salido mayor o igual que 5, salimos de la cárcel");
        }
        
        else {
            System.out.println("Ha salido menor que 5, por lo tanto no salimos de la cárcel");
        }
        
        //TAREA 4
        System.out.println("\n\n *****TAREA 4*****");
        System.out.println("Casilla de tipo " + TipoCasilla.CALLE);
        System.out.println("Sorpresa de tipo " + TipoSorpresa.SALIRCARCEL);
        System.out.println("Estado de Juego: " + EstadosJuego.INICIO_TURNO);
        
        //TAREA 5
        System.out.println("\n\n *****TAREA 5*****");
        String prueba = "";
        MazoSorpresas mazo = new MazoSorpresas();
        Sorpresa s1 = new Sorpresa(TipoSorpresa.SALIRCARCEL, mazo);
        Sorpresa s2 = new Sorpresa(TipoSorpresa.PORJUGADOR, 12, "Hoy es el dia de la felicidad, todos los jugadores te dan 12");
        mazo.alMazo(s1);
        mazo.alMazo(s2);
        mazo.siguiente();
        mazo.inhabilitarCartaEspecial(s2);
        mazo.habilitarCartaEspecial(s2);
        //Esto lo hemos hecho con breakproints y debugere
        System.out.println(Diario.getInstance().leerEvento());
        Diario.getInstance().ocurreEvento("prueba");
        System.out.println(Diario.getInstance().leerEvento());
        System.out.println(Diario.getInstance().eventosPendientes());
        
        //TAREA 7
        System.out.println("\n\n *****TAREA 7*****");
        Scanner capt = new Scanner(System.in);
        
        System.out.println("\n\n Dime el numero de la carcel");
        int carcel = capt.nextInt();
        
        
        String calle1 = "CALLE 1";
        String calle2 = "CALLE 2";
        String calle3 = "CALLE 3";
        String calle4 = "CALLE 4";
        String calle5 = "CALLE 5";
        String calle6 = "CALLE 6";
        String calle7 = "CALLE 7";
        String calle8 = "CALLE 8";
        String calle9 = "CALLE 9";
        
        Tablero tablero = new Tablero(carcel);
        Casilla c1 = new Casilla(calle1);
        Casilla c2 = new Casilla(calle2);
        Casilla c3 = new Casilla(calle3);
        Casilla c4 = new Casilla(calle4);
        Casilla c5 = new Casilla(calle5);
        Casilla c6 = new Casilla(calle6);
        Casilla c7 = new Casilla(calle7);
        Casilla c8 = new Casilla(calle8);
        Casilla c9 = new Casilla(calle9);
        
        tablero.añadeCasilla(c1);
        tablero.añadeCasilla(c2);
        tablero.añadeCasilla(c3);
        tablero.añadeCasilla(c4);
        tablero.añadeCasilla(c5);
        tablero.añadeCasilla(c6);
        tablero.añadeCasilla(c7);
        tablero.añadeCasilla(c8);
        tablero.añadeCasilla(c9);
        
        if(carcel > tamanio) {
            System.out.println("ERROR, la posicion de carcel es mayor que el tamaño del tablero \n");
            tablero.añadeCasilla(new Casilla("Carcel"));
        }
        
        else {
            System.out.println("Tablero creado correctamente \n");
        }
        
        tablero.añadeJuez();
        
        int origen = 7;
        System.out.println("El jugador se encuentra en la casilla 7");
        int valor_dado = Dado.getInstance().tirar();
        System.out.println("Tiramos el dado y sale: " + valor_dado);
        System.out.println("Por lo tanto el jugador avanza hasta la casilla " + tablero.nuevaPosicion(origen, valor_dado));
        //hay 9 casillas + juez y mas carcel
        //hacer los metodos to_s
        
    }  
}
