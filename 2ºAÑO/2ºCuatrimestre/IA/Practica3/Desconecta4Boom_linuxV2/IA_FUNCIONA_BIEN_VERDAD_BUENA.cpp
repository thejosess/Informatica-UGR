#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include "player.h"
#include "environment.h"

using namespace std;

const double masinf=9999999999.0, menosinf=-9999999999.0;


// Constructor
Player::Player(int jug){
    jugador_=jug;
}

// Actualiza el estado del juego para el jugador
void Player::Perceive(const Environment & env){
    actual_=env;
}

double Puntuacion(int jugador, const Environment &estado){
    double suma=0;

    for (int i=0; i<7; i++)
      for (int j=0; j<7; j++){
         if (estado.See_Casilla(i,j)==jugador){
            if (j<3)
               suma += j;
            else
               suma += (6-j);
         }
      }

    return suma;
}


// Funcion de valoracion para testear Poda Alfabeta
double ValoracionTest(const Environment &estado, int jugador){
    int ganador = estado.RevisarTablero();

    if (ganador==jugador)
       return 99999999.0; // Gana el jugador que pide la valoracion
    else if (ganador!=0)
            return -99999999.0; // Pierde el jugador que pide la valoracion
    else if (estado.Get_Casillas_Libres()==0)
            return 0;  // Hay un empate global y se ha rellenado completamente el tablero
    else
          return Puntuacion(jugador,estado);
}

// ------------------- Los tres metodos anteriores no se pueden modificar



 double aux_valoracion(const Environment &estado, int jugador)
{
   int valor = 0, boom_enemy, enemy, boom;

   //asignación de los identificadores segun el que esta jugando
   if(jugador == 1)
   {
      boom_enemy = 5;
      enemy = 2;
      boom = 4;
   }
   else
   {
      boom=5;
      enemy=1;
      boom_enemy=4;
   }
   
   for(int fil=0; fil < 7; fil++)
   {
      for(int col=0; col<7; col++)
      {
         if(estado.See_Casilla(fil,col)==0)
            return 0;

         //4 en fila
         if(fil<4)
         {
            if((estado.See_Casilla(fil,col)) == (estado.See_Casilla(fil,col+1)) &&
               (estado.See_Casilla(fil,col+1)) == (estado.See_Casilla(fil,col+2) &&               
               (estado.See_Casilla(fil,col+2)) == (estado.See_Casilla(fil,col+3))))
                  valor+= +900000;
            if( ((estado.See_Casilla(fil,col)) ==boom) || ((estado.See_Casilla(fil,col+1)) == boom ) ||               
               ((estado.See_Casilla(fil,col+2)) == boom ) || ((estado.See_Casilla(fil,col+3) == boom)))
                  valor+=999999; //estoy dandole un plus por ser bomba alguna de las casillas
            if( ((estado.See_Casilla(fil,col)) ==boom_enemy) || ((estado.See_Casilla(fil,col+1)) == boom_enemy ) ||               
               ((estado.See_Casilla(fil,col+2)) == boom_enemy ) || ((estado.See_Casilla(fil,col+3) == boom_enemy)))
                  valor-=99999;     //DESBORDA PORQUE ES MUY GRANDE Y HAGO UN +=
         }

         //4 en columna
         if(fil<4 && col<4)
         {
            if((estado.See_Casilla(fil,col)) == (estado.See_Casilla(fil+1,col)) &&
               (estado.See_Casilla(fil+1,col)) == (estado.See_Casilla(fil+2,col) &&               
               (estado.See_Casilla(fil+2,col)) == (estado.See_Casilla(fil+3,col))))
                  valor+= +900000;
            if( ((estado.See_Casilla(fil,col)) ==boom) || ((estado.See_Casilla(fil+1,col)) == boom ) ||               
               ((estado.See_Casilla(fil+2,col)) == boom ) || ((estado.See_Casilla(fil+3,col) == boom)))
                  valor+=999999; //estoy dandole un plus por ser bomba alguna de las casillas
            if( ((estado.See_Casilla(fil,col)) == boom_enemy) || ((estado.See_Casilla(fil+1,col)) == boom_enemy ) ||               
               ((estado.See_Casilla(fil+2,col)) == boom_enemy ) || ((estado.See_Casilla(fil+3,col) == boom_enemy)))
                  valor-=99999;
         }

         //4 en diagonal en parte derecha
         if(fil<4 && col<4)
         {
            if((estado.See_Casilla(fil,col)) == (estado.See_Casilla(fil+1,col+1)) &&
               (estado.See_Casilla(fil+1,col+1)) == (estado.See_Casilla(fil+2,col+2) &&               
               (estado.See_Casilla(fil+2,col+2)) == (estado.See_Casilla(fil+3,col+3))))
                  valor+= +900000;
            if( ((estado.See_Casilla(fil,col)) ==boom) || ((estado.See_Casilla(fil+1,col+1)) == boom ) ||               
               ((estado.See_Casilla(fil+2,col+2)) == boom ) || ((estado.See_Casilla(fil+3,col+3) == boom)))
                  valor+=999999; //estoy dandole un plus por ser bomba alguna de las casillas
            if( ((estado.See_Casilla(fil,col)) == boom_enemy) || ((estado.See_Casilla(fil+1,col+1)) == boom_enemy ) ||               
               ((estado.See_Casilla(fil+2,col+2)) == boom_enemy ) || ((estado.See_Casilla(fil+3,col+3) == boom_enemy)))
                  valor-=99999;
         }

         //4 en diagonal en parte izquierda
         if(fil>2 && col<4)
         {
            if((estado.See_Casilla(fil,col)) == (estado.See_Casilla(fil-1,col+1)) &&
               (estado.See_Casilla(fil-1,col+1)) == (estado.See_Casilla(fil-2,col+2) &&               
               (estado.See_Casilla(fil-2,col+2)) == (estado.See_Casilla(fil-3,col+3))))
                  valor+= +900000;
            if( ((estado.See_Casilla(fil,col)) ==boom) || ((estado.See_Casilla(fil-1,col+1)) == boom ) ||               
               ((estado.See_Casilla(fil-2,col+2)) == boom ) || ((estado.See_Casilla(fil-3,col+3) == boom)))
                  valor+=999999; //estoy dandole un plus por ser bomba alguna de las casillas
            if( ((estado.See_Casilla(fil,col)) == boom_enemy) || ((estado.See_Casilla(fil-1,col+1)) == boom_enemy ) ||               
               ((estado.See_Casilla(fil-2,col+2)) == boom_enemy ) || ((estado.See_Casilla(fil-3,col+3) == boom_enemy)))
                  valor-=99999;
         }

         //3 en la fila
         if(col < 5)
         {
            if((estado.See_Casilla(fil,col)) == (estado.See_Casilla(fil,col+1)) &&
               (estado.See_Casilla(fil,col+1)) == (estado.See_Casilla(fil,col+2)))
                  valor+= +90;
            if((estado.See_Casilla(fil,col)) == boom || (estado.See_Casilla(fil,col+1)) == boom || estado.See_Casilla(fil,col+2) == boom)
                  valor+= +99;
            if((estado.See_Casilla(fil,col)) == boom_enemy || (estado.See_Casilla(fil,col+1)) == boom_enemy || estado.See_Casilla(fil,col+2) == boom_enemy)
                  valor-= 50;
         }

         //3 en la columna
         if(fil < 5)
         {
            if((estado.See_Casilla(fil,col)) == (estado.See_Casilla(fil+1,col)) &&
               (estado.See_Casilla(fil+1,col)) == (estado.See_Casilla(fil+2,col)))
                  valor+= +90;
            if((estado.See_Casilla(fil,col)) == boom || (estado.See_Casilla(fil+1,col)) == boom || estado.See_Casilla(fil+2,col) == boom)
                  valor+= +99;
            if((estado.See_Casilla(fil,col)) == boom_enemy || (estado.See_Casilla(fil+1,col)) == boom_enemy || estado.See_Casilla(fil+2,col) == boom_enemy)
                  valor-= 50;

                  //PONER +INF O . INF DE LA LIBRERIA
         }
      
         //3 en diagonal parte derecha
         if(fil<5 && col<5)
         {
            if((estado.See_Casilla(fil,col)) == (estado.See_Casilla(fil+1,col+1)) &&
               (estado.See_Casilla(fil+1,col+1)) == (estado.See_Casilla(fil+2,col+2)))
                  valor+= +90;
            if((estado.See_Casilla(fil,col)) == boom || (estado.See_Casilla(fil+1,col+1)) == boom || estado.See_Casilla(fil+2,col+2) == boom)
                  valor+= +99;
            if((estado.See_Casilla(fil,col)) == boom_enemy || (estado.See_Casilla(fil+1,col+1)) == boom_enemy || estado.See_Casilla(fil+2,col+2) == boom_enemy)
                  valor-= 50;
         }

      //3 en diagonal parte izquierda
         if(fil>1 && col<5)
         {
            if((estado.See_Casilla(fil,col)) == (estado.See_Casilla(fil-1,col+1)) &&
               (estado.See_Casilla(fil-1,col+1)) == (estado.See_Casilla(fil-2,col+2)))
                  valor+= +90;
            if((estado.See_Casilla(fil,col)) == boom || (estado.See_Casilla(fil-1,col+1)) == boom || estado.See_Casilla(fil-22,col+2) == boom)
                  valor+= +99;
            if((estado.See_Casilla(fil,col)) == boom_enemy || (estado.See_Casilla(fil-1,col+1)) == boom_enemy || estado.See_Casilla(fil-2,col+2) == boom_enemy)
                  valor-= 50;
         }

         // 2 fila
         if(col <6)
         {
            if((estado.See_Casilla(fil,col)) == (estado.See_Casilla(fil,col+1)))
               valor+= +9;
            if((estado.See_Casilla(fil,col)) == boom || (estado.See_Casilla(fil,col+1)) == boom)
               valor+= +9;
            if((estado.See_Casilla(fil,col)) == boom_enemy || (estado.See_Casilla(fil,col+1)) == boom_enemy)
               valor-= +4;
         }

         //2 columna
         if(fil < 6)
         {
            if((estado.See_Casilla(fil,col)) == (estado.See_Casilla(fil+1,col)))
               valor+= +9;
            if((estado.See_Casilla(fil,col)) == boom || (estado.See_Casilla(fil+1,col)) == boom)
               valor+= +9;
            if((estado.See_Casilla(fil,col)) == boom_enemy || (estado.See_Casilla(fil+1,col)) == boom_enemy)
               valor-= +4;
         }

         return valor;

         // 2 en diagonal parte derecha
         if(fil<6 && col <6)
         {
            if((estado.See_Casilla(fil,col)) == (estado.See_Casilla(fil+1,col+1)))
               valor+= +8;
            if((estado.See_Casilla(fil,col)) == boom || (estado.See_Casilla(fil+1,col+1)) == boom)
               valor+= +9;
            if((estado.See_Casilla(fil,col)) == boom_enemy || (estado.See_Casilla(fil+1,col+1)) == boom_enemy)
               valor-= +4;
         }

         // 2 en diagonal parte izquierda
         if(fil>0 && col < 6)
         {
            if((estado.See_Casilla(fil,col)) == (estado.See_Casilla(fil-1,col+1)))
               valor+= +9;
            if((estado.See_Casilla(fil,col)) == boom || (estado.See_Casilla(fil-1,col+1)) == boom)
               valor+= +9;
            if((estado.See_Casilla(fil,col)) == boom_enemy || (estado.See_Casilla(fil-1,col+1)) == boom_enemy)
               valor-= +4;
         }
      }
   }
   return valor;
}


// Funcion heuristica (ESTA ES LA QUE TENEIS QUE MODIFICAR)
double Valoracion(const Environment &estado, int jugador)
{
   int gana = estado.RevisarTablero();

   if(gana == jugador)
   {
      return 999999;
   }
   else if(gana !=0)
      return -999999;
   else 
   {
      if(jugador == 1)
      {
         return aux_valoracion(estado, jugador) - aux_valoracion(estado,2);  //si eres primer jugador pues le restas la valoracion del segundo
      }
      else
      {
         return aux_valoracion(estado,jugador) - aux_valoracion(estado,1);   //si eres el segundo jugador pues le restas la valoracion del primero
         // es al reves??
      }
   }
}

double Poda_AlfaBeta(const Environment &E, int jugador, int profundidad, Environment::ActionType &action, double alpha,double beta, bool max_min, double &numeroNodos)
{
   if(profundidad == 0 || E.JuegoTerminado() /*zz|| E.RevisarTablero() == 1|| E.RevisarTablero() == 2*/)
   {
      numeroNodos++;
      return Valoracion(E, jugador);
   }

   int act = -1, hijos;
   double nodo;
   Environment::ActionType accion;
   Environment hijo = E.GenerateNextMove(act);
   bool VecAct[8];
   hijos = E.possible_actions(VecAct);

   //cambair max_min por una variable que consuma menos, int??
   if(!max_min)
   {
      for(int i=0; i<hijos;i++)
      {
         nodo=Poda_AlfaBeta(hijo,jugador,profundidad-1,accion,alpha,beta,true,numeroNodos);
         if(nodo>alpha)
         {
            alpha=nodo;
            action=static_cast<Environment::ActionType>(act);
         }
         if(beta<=alpha)
            break;

         hijo = E.GenerateNextMove(act);
      }
      return alpha;
   }
   else if(max_min)
   {
      for(int i=0; i<hijos;i++)
      {
         nodo=Poda_AlfaBeta(hijo,jugador,profundidad-1,accion,alpha,beta,false,numeroNodos);
         if(nodo<beta)
         {
            beta=nodo;
            action=static_cast<Environment::ActionType>(act);
         }
         if(beta<=alpha)
            break;

         hijo = E.GenerateNextMove(act);
      }
      return beta;
      
   }
}


// Invoca el siguiente movimiento del jugador
Environment::ActionType Player::Think(){
    const int PROFUNDIDAD_MINIMAX = 6;  // Umbral maximo de profundidad para el metodo MiniMax
    const int PROFUNDIDAD_ALFABETA = 8; // Umbral maximo de profundidad para la poda Alfa_Beta

    Environment::ActionType accion; // acci�n que se va a devolver
    bool aplicables[8]; // Vector bool usado para obtener las acciones que son aplicables en el estado actual. La interpretacion es
                        // aplicables[0]==true si PUT1 es aplicable
                        // aplicables[1]==true si PUT2 es aplicable
                        // aplicables[2]==true si PUT3 es aplicable
                        // aplicables[3]==true si PUT4 es aplicable
                        // aplicables[4]==true si PUT5 es aplicable
                        // aplicables[5]==true si PUT6 es aplicable
                        // aplicables[6]==true si PUT7 es aplicable
                        // aplicables[7]==true si BOOM es aplicable



    double valor; // Almacena el valor con el que se etiqueta el estado tras el proceso de busqueda.
    double alpha, beta; // Cotas de la poda AlfaBeta

    int n_act; //Acciones posibles en el estado actual
    double numeroNodos=0;


    n_act = actual_.possible_actions(aplicables); // Obtengo las acciones aplicables al estado actual en "aplicables"
    int opciones[10];

    // Muestra por la consola las acciones aplicable para el jugador activo
    //actual_.PintaTablero();
    cout << " Acciones aplicables ";
    (jugador_==1) ? cout << "Verde: " : cout << "Azul: ";
    for (int t=0; t<8; t++)
      if (aplicables[t])
         cout << " " << actual_.ActionStr( static_cast< Environment::ActionType > (t)  );
    cout << endl;


    //--------------------- COMENTAR Desde aqui
   
   /*
    cout << "\n\t";
    int n_opciones=0;
    JuegoAleatorio(aplicables, opciones, n_opciones);

    if (n_act==0){
      (jugador_==1) ? cout << "Verde: " : cout << "Azul: ";
      cout << " No puede realizar ninguna accion!!!\n";
      //accion = Environment::actIDLE;
    }
    else if (n_act==1){
           (jugador_==1) ? cout << "Verde: " : cout << "Azul: ";
            cout << " Solo se puede realizar la accion "
                 << actual_.ActionStr( static_cast< Environment::ActionType > (opciones[0])  ) << endl;
            accion = static_cast< Environment::ActionType > (opciones[0]);

         }
         else { // Hay que elegir entre varias posibles acciones
            int aleatorio = rand()%n_opciones;
            cout << " -> " << actual_.ActionStr( static_cast< Environment::ActionType > (opciones[aleatorio])  ) << endl;
            accion = static_cast< Environment::ActionType > (opciones[aleatorio]);
         }
   */

    //--------------------- COMENTAR Hasta aqui


    //--------------------- AQUI EMPIEZA LA PARTE A REALIZAR POR EL ALUMNO ------------------------------------------------
    
    valor = Poda_AlfaBeta(actual_, jugador_, PROFUNDIDAD_ALFABETA, accion, menosinf, masinf,false, numeroNodos);
    cout << "Valor AlfaBeta: " << valor << "  Accion: " << actual_.ActionStr(accion) << endl;

    return accion;
}