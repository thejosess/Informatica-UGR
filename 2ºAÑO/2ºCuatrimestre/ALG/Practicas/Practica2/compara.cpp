// g++ -O2 comparacionPreferencias.cpp -o comparacionPreferencias
// ./comparacionPreferencias
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <vector>
using namespace std;

double uniforme() //Genera un n�mero uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C.
{
 int t = rand();
 double f = ((double)RAND_MAX+1.0);
 return (double)t/f;
}

int contarMovimientos(int* v1, int* v2, const int tam)
{
   int res = 0;

   for(int i=0; i < tam; i++)
   {
      int j = 0;
      bool min = true;

      while(j < tam && min)
      {
         if(v2[i % tam] < v1[j])
         {
            res++;
            j++;
         }
         else
            min = false;
      }
   }
   return res;
}

int comparacionPreferencias(int* v, const int tam)
{
   if(tam == 0)
      return 0;
   
   const int mitad = tam/2;
   int* v1 = new int [mitad];
   int* v2 = &v [mitad];
   v1 = v;

   int preferencias1 = comparacionPreferencias(v1, mitad);
   int preferencias2 = comparacionPreferencias(v2, mitad);
   int res = preferencias1 + preferencias2;

   res += contarMovimientos(v1, v2, mitad);

   delete[] v1;

   return res;
}

int main(int argc, char * argv[]){
   int* a, b, aux;
   chrono::time_point<std::chrono::high_resolution_clock> t02, tf2;
	double tejecucion2;
	ofstream fsalida;
   int opcion, tamano, comparacion, elemento, pos;
   char* fichero="salida_comparacion.txt";

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

         a = new int [tamano];
         // b = new int [tamano];
         
         cout << endl << "Primer Vector:" << endl;
         for(int i = 0; i < tamano; i++)
         {
            cout << "\tIntroduzca el elemento " << i+1 << " del primer vector: ";
            cin >> elemento;
            a[i] = elemento;
            cout << endl;
         }
         /* cout << endl << "Segundo Vector:" << endl;
         for(int i = 0; i < tamano; i++)
         {
            cout << "\tIntroduzca el elemento " << i+1 << " del segundo vector: ";
            cin >> elemento;
            b[i] = elemento;
            cout << endl;
         } */

         if(tamano <= 10)
         {
            cout << endl << "VECTORES:" << endl;
            cout << endl << "A: < ";
            for(int i = 0; i < tamano; i++)
               cout << a[i] << " ";
            cout << ">" << endl;

            /* cout << "B: < ";
            for(int i = 0; i < tamano; i++)
               cout << b[i] << " ";
            cout << ">" << endl; */
         }

         comparacion = comparacionPreferencias(a, tamano);

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

         a = new int [tamano];
         /* b = new int [tamano];
         aux = new int [tamano]; */

         srand(time(NULL));

         for (int j=0; j<tamano; j++) a[j]=j;
         //for (int j=0; j<tamano; j++) {cout << a[j] << " ";}
         //algoritmo de random shuffling the Knuth (permutaci�n aleatoria)
         for (int j=tamano-1; j>0; j--) {
            double u=uniforme();
            int k=(int)(j*u);
            int tmp=a[j];
            a[j]=a[k];
            a[k]=tmp;
         }

         /* // Llenamos a con numeros aleatorios
         for(int i = 0; i < tamano; i++)
         {
            aux[i] = i+1;
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
            aux[i] = i+1;
         }
         for(int i = 0; i < tamano; i++)
         {
            pos = rand() % aux.size();
            b.push_back(aux[pos]);
            aux.erase(aux.begin() + pos);
         } */

         //Medir el tiempo de la ejecución
         t02 = std::chrono::high_resolution_clock::now();
         comparacion = comparacionPreferencias(a, tamano);
         tf2 = std::chrono::high_resolution_clock::now();

         tejecucion2 = std::chrono::duration_cast<std::chrono::microseconds>(tf2 - t02).count();

         if(tamano <= 10)
         {
            cout << endl << "VECTORES:" << endl;
            cout << endl << "A: < ";
            for(int i = 0; i < tamano; i++)
               cout << a[i] << " ";
            cout << ">" << endl;

            /* cout << "B: < ";
            for(int i = 0; i < tamano; i++)
               cout << b[i] << " ";
            cout << ">" << endl; */
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

   delete[] a;
   /* delete[] b;
   delete[] aux; */
}
