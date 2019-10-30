#include <unordered_map>
#include "ArbolBinario.hpp"
using namespace std;

template <typename T>
class contenedor{
private:
  unordered_map<T,ArbolBinario<int> > datos;
public:
  //...
  class iterator{
    friend class contenedor;
  private:
    typename unordered_map<T,ArbolBinario<int> >::iterator it,final;
  public:
    
    iterator(){}
    
    bool operator==(const iterator &i)const{
      return i.it == it;
    }
    
    bool operator!=(const iterator &i)const{
      return i.it != it;
    }
    
    pair<const T, ArbolBinario<int> > & operator* (){
      return *it;
    }
    
    iterator & operator++(){
      bool salir =false;
      ++it;
      while (it!=final && !salir)
        if (suma(it->second.raiz())%2==0)
          salir =true;
        else
          ++it;
      
      return *this;
    }
  };
  
  iterator begin(){
    iterator i;
    i.it=datos.begin();
    i.final = datos.end();
    if (suma((i.it)->second.raiz())%2 != 0)
      ++i;
    return i;
  }
  
  iterator end(){
    
    iterator i;
    i.it=datos.end();
    i.final = datos.end();
    return i;
  }
  
};

int main()
{
 
  ArbolBinario<int> arbol;
  
//  const int N = 10;
//  const float max = 100.0;
//  srand((unsigned)time(NULL));
//  for(int i=0; i<N; i++)
//    arbol.insertar((int) (max*rand()/RAND_MAX));
  
  float datos[8] = {5,3,8,1,4,6,9,7};
  
  cout << "escribe en el arbol";
  cin >> arbol;
  
  cout << "Árbol resultante:" << endl;
  cout << arbol;


  
  
  return 0;


}
