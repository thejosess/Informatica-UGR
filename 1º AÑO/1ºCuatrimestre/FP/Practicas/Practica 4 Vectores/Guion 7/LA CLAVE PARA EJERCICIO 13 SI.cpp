#include <iostream>
using namespace std;

int main(){
   const char TERMINADOR_ENTRADA_DATOS = '#';
   const int TAMANIO = 100;
   char componente;
   char principal[TAMANIO], a_buscar[TAMANIO];
   int total_utilizados, total_utilizados_a_buscar, pos_encontrado;
   bool encontrado, va_coincidiendo;

   cout << "Búsqueda de un vector dentro de otro\n\n";
   
   cout << "Introduzca caracteres. Para terminar introduzca #\n";
   
   cin >> componente;
   total_utilizados = 0;
   
   while (componente != TERMINADOR_ENTRADA_DATOS && total_utilizados < TAMANIO){
      principal[total_utilizados] = componente;
      total_utilizados++;
      cin >> componente;
   }
   
   cout << "Introduzca caracteres. Para terminar introduzca #\n";

   cin >> componente;
   total_utilizados_a_buscar = 0;

   while (componente != TERMINADOR_ENTRADA_DATOS && total_utilizados_a_buscar < TAMANIO){
      a_buscar[total_utilizados_a_buscar] = componente;
      total_utilizados_a_buscar++;
      cin >> componente;
   }

   for (int inicio = 0;
        inicio + total_utilizados_a_buscar <= total_utilizados
        &&
        !encontrado;
        inicio++){

      va_coincidiendo = true;

      for (int i = 0; i < total_utilizados_a_buscar && va_coincidiendo; i++)
         va_coincidiendo = principal[inicio + i] == a_buscar[i];

      if (va_coincidiendo){
         encontrado = true;
         pos_encontrado = inicio;
      }
   }

   if (encontrado)
      cout << "\nEncontrado en la posición " << pos_encontrado;
   else
      cout << "\nNo encontrado";
}
