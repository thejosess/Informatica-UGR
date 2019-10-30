#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class heap_doble{
private:
  vector <int> datos;
public:
  void insertar(int clave){
    int pos = datos.size();
    datos.push_back(clave);
    int padre = (pos-1)/2;
    int abuelo = (padre-1)/2;
    int profundidad =(log(pos+1)/log(2));
    bool colocado =false;
    
    while (pos>0 && !colocado){
      if (padre>0){ //Tiene padre y abuelo
        if (profundidad%2==0){ //Profundidad par
          //La clave debe ser menor que el padre y
          //mayor que el abuelo
          if (datos[padre] > datos[pos] &&
              datos[abuelo] < datos[pos])
            colocado=true;
          else{
            if (datos[padre]<datos[pos]){   //Padre
              swap(datos[padre],datos[pos]);
              pos = padre;
              padre = abuelo;
              abuelo = (padre-1)/2;
            }
            else if (datos[abuelo]>datos[pos]){  //Abuelo
              swap(datos[abuelo],datos[pos]);
              pos = abuelo;
              padre =(pos-1)/2;
              abuelo = (padre-1)/2;
            }
          }
        }
        else { //Profundidad impar
          //La clave debe ser mayor que el padre y
          //menor que el abuelo
          if (datos[padre] < datos[pos] &&
              datos[abuelo] > datos[pos])
            colocado=true;
          else{
            if (datos[padre]>datos[pos]){
              swap(datos[padre],datos[pos]);
              pos = padre;
              padre =abuelo;
              abuelo = (padre-1)/2;
            }
            else if (datos[abuelo]<datos[pos]){
              swap(datos[abuelo],datos[pos]);
              pos = abuelo;
              padre =(pos-1)/2;
              abuelo = (padre-1)/2;
            }
          }
        }
      }
      else{ //Solamente tiene padre (padre = 0)
        //La profundidad tiene que ser 1 (caso profundidad impar)
        //La clave debe ser mayor que la del padre
        if (datos[padre]<datos[pos])
          colocado=true;
        else{
          swap(datos[padre],datos[pos]);
          pos = padre;
          colocado =true;
          //Terminamos porque pos es 0
        }
      }
      profundidad--;
    }
  }
  
  void imprimir(){
    for(int i=0; i<datos.size(); i++)
      cout << datos[i] << " ";
    cout << endl;
  }
};

int main(){
  heap_doble mi_heap;
  const int N = 100;
  const float max = 100.0;
  
  srand((unsigned)time(NULL));
  for(int i=0; i<N; i++)
    mi_heap.insertar((int) (max*rand()/RAND_MAX));
  
  mi_heap.imprimir();
  
}
