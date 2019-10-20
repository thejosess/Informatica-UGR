#include <iostream>
using namespace std;

int main(){
   const char TERMINADOR_ENTRADA_DATOS = '#';
   const int TAMANIO = 100;
   char anterior, actual;
   char vector[TAMANIO];
   int total_utilizados, pos_encontrado, izda, dcha, centro;
   bool encontrado, prosigue_lectura;
   char buscado;

   cout << "Búsqueda binaria para vectores ordenados\n\n";
   cout << "Introduzca caracteres ordenados de menor a mayor. "
        << "Para terminar introduzca # o un valor menor que el anterior\n";

   cin >> actual;
   total_utilizados = 0;
   anterior = actual;

   while (actual != TERMINADOR_ENTRADA_DATOS && actual >= anterior){
      vector[total_utilizados] = actual;
      total_utilizados++;
      anterior = actual;
      cin >> actual;
   }

   /*
   cin >> actual;
   anterior = actual;
   total_utilizados = 0;

   do{
      prosigue_lectura = actual != TERMINADOR_ENTRADA_DATOS
                         &&
                         actual >= anterior;

      if (prosigue_lectura){
         vector[total_utilizados] = actual;
         total_utilizados++;
         anterior = actual;
         cin >> actual;
      }
   }while (prosigue_lectura);
   */

   cout << "\n\nIntroduzca un valor a buscar ";
   cin >> buscado;

   //////////////////////////////////////////////////////////////////
   // Búsqueda binaria:
   
   izda = 0;
   dcha = total_utilizados - 1;
   encontrado = false;

   while (izda <= dcha  &&  !encontrado){
      centro = (izda + dcha) / 2;

      if (vector[centro] == buscado)
         encontrado = true;
      else if (buscado < vector[centro])
         dcha = centro - 1;
      else
         izda = centro + 1;
   }


   if (encontrado)
      pos_encontrado = centro;
   else
      pos_encontrado = -1;

   if (encontrado)
      cout << "\nEncontrado en la posición " << pos_encontrado;
   else
      cout << "\nNo encontrado";
}
