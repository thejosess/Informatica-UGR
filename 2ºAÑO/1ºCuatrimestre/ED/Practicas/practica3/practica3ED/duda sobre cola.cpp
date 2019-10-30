#include<stack>
#include<iostream>

using namespace std ;
template<typename T>

struct celda_cola{
    T valor ;
    T maximo ;
} ;

template<typename T>
class Cola_max{
    private:
        stack<celda_cola<T> > pila_cola, auxiliar ; 

    public:
        /*Una cola dispone de front*, back*, push*, pop*, size* y empty**/
        /*Se traducirán a frente, dorso, poner, quitar, num_elementos y vacio*/
        /*Además añadiremos el método maximo* */
        bool vacio() const{
            return pila_cola.empty() ;
        }

        size_t num_elementos() const{
            return pila_cola.size() ;
        }

        T & dorso (){
            return pila_cola.top() ;
        }

        const T & dorso() const{
            return pila_cola.top() ;
        }

        T & frente (){
            celda_cola<T> item_frente ;
            while(!pila_cola.empty()){
                auxiliar.push(pila_cola.top()) ;
                pila_cola.pop() ;
            }
            item_frente = auxiliar.top();
            while(!auxiliar.empty()){
                pila_cola.push(auxiliar.top()) ;
                auxiliar.pop() ;
            }
            return item_frente.valor ;
        }

        const T & frente() const{
            celda_cola<T> item_frente ;
            while(!pila_cola.empty()){
                auxiliar.push(pila_cola.top()) ;
                pila_cola.pop() ;
            }
            item_frente = auxiliar.top();
            while(!auxiliar.empty()){
                pila_cola.push(auxiliar.top()) ;
                auxiliar.pop() ;
            }
            return item_frente.valor ;
        }

        T maximo() const{
            return pila_cola.top().maximo ;
        }

        void poner (T introducido){
            celda_cola<T> a_introducir ;
            a_introducir.valor = introducido ;
            a_introducir.maximo = introducido ;
            auxiliar.push(a_introducir) ; /*Violacion de segmento aqui*/

            if(introducido > pila_cola.top().maximo){
                while(!pila_cola.empty()){
                  pila_cola.top().maximo = introducido ;
                  auxiliar.push(pila_cola.top());
                  pila_cola.pop() ;
                }
            }

            while(!auxiliar.empty()){
                pila_cola.push(auxiliar.top()) ;
                auxiliar.pop() ;
            }
        }

        void quitar (){
            T max_anterior = pila_cola.top().maximo ;

            pila_cola.pop() ;

            if(pila_cola.top().valor < max_anterior){
                while(!pila_cola.empty()){
                  max_anterior = pila_cola.top().valor ;
                  pila_cola.top().maximo = max_anterior ;
                  auxiliar.push(pila_cola.top());
                  pila_cola.pop() ;
                }

                while(!auxiliar.empty()){
                    pila_cola.push(auxiliar.top()) ;
                    auxiliar.pop() ;
                }
            }
        }


};

int main(){
	
  Cola_max <int> p;
  p.poner(2);
  cout << "Se introduce el valor 2. El maximo es " << p.maximo() << endl;
  p.poner(5);
  cout << "Se introduce el valor 5. El maximo es " << p.maximo() << endl;
  p.poner(4);
  cout << "Se introduce el valor 4. El maximo es " << p.maximo() << endl;
  p.poner(9);
  cout << "Se introduce el valor 9. El maximo es " << p.maximo() << endl;
  p.poner(7);
  cout << "Se introduce el valor 7. El maximo es " << p.maximo() << endl;
  p.poner(8);
  cout << "Se introduce el valor 8. El maximo es " << p.maximo() << endl;
   
  cout << "La cola tiene " << p.num_elementos() << " elementos. ";
  cout << "El maximo es " << p.maximo() << endl;

  while(!p.vacio()){
    cout << "El frente contiene " << p.frente() << ". ";
    cout << "El maximo es " << p.maximo() << ". ";
    p.quitar();
    cout << "Se quita este valor" << endl;
  }
 
  Cola_max <float> q;
  q.poner(2.4);
  cout << "Se introduce el valor 2.4. El maximo es " << q.maximo() << endl;
  q.poner(5.5);
  cout << "Se introduce el valor 5.5. El maximo es " << q.maximo() << endl;
  q.poner(4.1);
  cout << "Se introduce el valor 4.1. El maximo es " << q.maximo() << endl;
  q.poner(9.6);
  cout << "Se introduce el valor 9.6. El maximo es " << q.maximo() << endl;
  q.poner(7.9);
  cout << "Se introduce el valor 7.9. El maximo es " << q.maximo() << endl;
  q.poner(8.3);
  cout << "Se introduce el valor 8.3. El maximo es " << q.maximo() << endl;
   
  cout << "La cola tiene " << q.num_elementos() << " elementos. ";
  cout << "El maximo es " << q.maximo() << endl;

  while(!q.vacio()){
    cout << "El frente contiene " << q.frente() << ". ";
    cout << "El maximo es " << q.maximo() << ". ";
    q.quitar();
    cout << "Se quita este valor" << endl;
  }

  return 0;
}