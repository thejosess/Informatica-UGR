#include <iostream>
#include <list>

using namespace std;

int orden(const list<int> &L){
  list<int>::const_iterator it_actual,it_siguiente;
  unsigned int sentido;
  //Inicializamos it1 al primer elemento
  it_actual=L.cbegin();
  if (it_actual==L.cend()) //Si la lista está vacía
    sentido = 0;
  else{ //Si no está vacía
    
    //Inicializamos it2 al segundo elemento
    it_siguiente=it_actual;
    it_siguiente++;
    
    //Determinamos el orden a comprobar a partir
    //de los dos primeros elementos
    if (*it_actual<=*it_siguiente)
      sentido =1;
    else
      sentido =2;
    
    //Avanzamos los iteradores
    it_actual++;
    it_siguiente++;
    
    //Terminaremos cuando el segundo llegue al final o
    //cuando falle alguna comprobación
    while (it_siguiente!=L.cend() && sentido!=0){
      if (sentido==1 && !(*it_actual<=*it_siguiente))
        sentido = 0;
      else if (sentido==2 && !(*it_siguiente<=*it_actual))
        sentido = 0;
      it_actual++;
      it_siguiente++;
    }
  }
  return sentido;
}

//Versión alternativa
//Cortesía de Bruno García Tripoli

int orden2(const list<int> &L){
  bool flag1 = true; //orden descendente
  bool flag2 = true; //orden ascendente
  
  for(auto it = L.begin(); it!=L.end() && (flag1 || flag2) ; it++ ){
    auto it_next = it;
    it_next++;
    
    if(it_next==L.end() ) break;
    if(!(*it<*it_next)) flag1 = false;
    if(!(*it>*it_next)) flag2 = false;
  }
  
  return (flag1 && flag2)? 0 : flag1? 1 : flag2? 2 : 0;
}


int main(){
  list<int> lista;
  
  for(int i=1; i<=5; i++)
    lista.push_back(i);
//    lista.push_front(i);

//  lista.push_back(3);
  
  list<int>::const_iterator it;
  for(it=lista.cbegin(); it!=lista.cend(); it++)
    cout << *it << " ";
  cout << endl;
  
  cout << "Orden: " << orden(lista) << endl;
  cout << "Orden: " << orden2(lista) << endl;
}

