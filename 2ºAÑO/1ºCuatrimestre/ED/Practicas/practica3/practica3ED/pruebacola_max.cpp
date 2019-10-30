#include <iostream>
#include "Cola_max.h"

using namespace std;

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

  while(!p.vacia()){
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

  while(!q.vacia()){
    cout << "El frente contiene " << q.frente() << ". ";
    cout << "El maximo es " << q.maximo() << ". ";
    q.quitar();
    cout << "Se quita este valor" << endl;
  }

  return 0;
}
