// g++ -O2 comparacionPreferencias.cpp -o comparacionPreferencias
// ./comparacionPreferencias
//Grupo Ciri
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <vector>
using namespace std;

int BuscarBinario(vector<int> v, const int ini, const int fin, const int x)
{
   if (ini > fin)
      return -1;

   int centro = (ini + fin) / 2;
   if (v[centro] == x)
      return centro;
   if (v[centro] > x)
      return BuscarBinario(v, ini, centro - 1, x);
   return BuscarBinario(v, centro + 1, fin, x);
}

int comparacionPreferencias(const vector<int> &a, vector<int> &b, int ini, int fin){
   int res;
   if (ini == fin){
      if (b[ini] != a[ini]){
         int pos = BuscarBinario(a, 0, a.size()-1, b[ini]);
         if (pos > ini){
            int aux = b[ini];
            b[ini] = b[ini + 1];
            b[ini + 1] = aux;
         }
         else{
            int aux = b[ini];
            b[ini] = b[ini - 1];
            b[ini - 1] = aux;
         }
         res = 1;
      }
      else
         res = 0;
   }
   else{
      int centro = (ini + fin) / 2;
      res = comparacionPreferencias(a, b, ini, centro) + comparacionPreferencias(a, b, centro + 1, fin);
   }
   return res;
}

int main(int argc, char * argv[]){
   vector<int> a, b, aux;
   chrono::time_point<std::chrono::high_resolution_clock> t02, tf2;
	double tejecucion2;
	ofstream fsalida;
   int opcion, tamano, comparacion, elemento, pos;
   char* fichero="salida.txt";

   cout << "\n1. Introducir manualmente los vectores" << endl
      << "2. Realizar prueba de la eficiencia" << endl
      << "\n\tElija una de las opciones anteriores: ";
   cin >> opcion;

   switch (opcion)
   {
      case 1:
         
         do{
         cout << endl << "Introduzca el tamaño de los vectores (nº positivo): ";
         cin >> tamano;
         }while(tamano <= 0);
         
         cout << endl << "Primer Vector:" << endl;
         for(int i = 0; i < tamano; i++)
         {
            cout << "\tIntroduzca el elemento " << i+1 << " del primer vector: ";
            cin >> elemento;
            a.push_back(elemento);
            cout << endl;
         }
         cout << endl << "Segundo Vector:" << endl;
         for(int i = 0; i < tamano; i++)
         {
            cout << "\tIntroduzca el elemento " << i+1 << " del segundo vector: ";
            cin >> elemento;
            b.push_back(elemento);
            cout << endl;
         }

         if(tamano <= 10)
         {
            cout << endl << "VECTORES:" << endl;
            cout << endl << "A: < ";
            for(int i = 0; i < tamano; i++)
               cout << a[i] << " ";
            cout << ">" << endl;

            cout << "B: < ";
            for(int i = 0; i < tamano; i++)
               cout << b[i] << " ";
            cout << ">" << endl;
         }

         comparacion = comparacionPreferencias(a, b, 0, tamano - 1);

         cout << "La comparacion de preferencias de los dos vectores es: " << comparacion << endl;
         break;
      
      case 2:

         do{
         cout << endl << "Introduzca el tamaño de los vectores (nº positivo): ";
         cin >> tamano;
         }while(tamano <= 0);

         // cout << endl << "Introduzca el nombre del fichero de salida: ";
         // cin >> fichero;

         fsalida.open(fichero);

         if (!fsalida.is_open())
         {
            cerr << "Error: No se pudo abrir fichero para escritura " << argv[1] << "\n\n";
            break;
         }

         srand(time(NULL));
         // Llenamos a con numeros aleatorios
         for(int i = 0; i < tamano; i++)
         {
            aux.push_back(i);
         }
         for(int i = 0; i < tamano; i++)
         {
            pos = rand() % aux.size();
            a.push_back(aux[pos]);
            aux.erase(aux.begin() + pos);
         }
         // Llenamos b con numeros aleatorios
         for(int i = 0; i < tamano; i++)
         {
            aux.push_back(i);
         }
         for(int i = 0; i < tamano; i++)
         {
            pos = rand() % aux.size();
            b.push_back(aux[pos]);
            aux.erase(aux.begin() + pos);
         }

         //Medir el tiempo de la ejecución
         t02 = std::chrono::high_resolution_clock::now();
         comparacion = comparacionPreferencias(a, b, 0, tamano - 1);
         tf2 = std::chrono::high_resolution_clock::now();

         tejecucion2 = std::chrono::duration_cast<std::chrono::microseconds>(tf2 - t02).count();

         if(tamano <= 10)
         {
            cout << endl << "VECTORES:" << endl;
            cout << endl << "A: < ";
            for(int i = 0; i < tamano; i++)
               cout << a[i] << " ";
            cout << ">" << endl;

            cout << "B: < ";
            for(int i = 0; i < tamano; i++)
               cout << b[i] << " ";
            cout << ">" << endl;
         }

         cout << "La comparacion de preferencias de los dos vectores es: " << comparacion << endl;
         cout << endl << "Tiempo con DyV: " << tejecucion2 << endl;
         fsalida << tamano << " " << tejecucion2;

         fsalida.close();
         break;
   
      default:
         cerr << "Opción no valida" << endl;
         break;
   }
}
