#include <iostream>
#include <list>
using namespace std;

struct enfrentamiento{
  unsigned char eq1,eq2;
  unsigned int puntos_eq1,puntos_eq2;
};

class liga{
private:
  list<enfrentamiento>res;
public:
  
  //...
  
  int Ganados(unsigned char equipo){
    list<enfrentamiento>::iterator i;
    int cuantos=0;
    for (i=res.begin();i!=res.end();++i){
      if ((i->eq1==equipo && (i->puntos_eq1 > i->puntos_eq2)) ||
          (i->eq2==equipo && (i->puntos_eq2 > i->puntos_eq1)))
          cuantos++;
    }
    return cuantos;
  }
  
  
  class iterator {
    friend class liga;
  private:
    list<enfrentamiento>::iterator it,final;
  public:
    
    iterator(){}
    
    bool operator==(const iterator &otro)const{
      return it == otro.it;
    }
    
    bool operator!=(const iterator &otro)const{
      return it != otro.it;
    }
    
    enfrentamiento& operator* (){
      return *it;
    }
    
    iterator & operator++(){
      bool salir =false;
      ++it;
      while (it!=final && !salir){
        if (it->puntos_eq1 == it->puntos_eq2)
          salir=true;
        else
          ++it;
      }
      return *this;
    }
  };
  
  iterator begin(){
    iterator i;
    i.it=res.begin();
    i.final = res.end();
    if((i.it)->puntos_eq1 != (i.it)->puntos_eq2)
      ++i;
    return i;
  }
  
  iterator end(){
    iterator i;
    i.it=res.end();
    i.final = res.end();
    return i;
  }
  
};

//...
