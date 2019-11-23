#include <iostream>
#include "Cola_max_pila.h"

using namespace std;

int main(){
	
  Cola_max <int> p;
  //p.push(2);
  p.size();
  cout << "Se introduce el valor 2. El maximo es " << p.maximo() << endl;
  /*p.push(5);
  cout << "Se introduce el valor 5. El maximo es " << p.maximo() << endl;
  p.push(4);
  cout << "Se introduce el valor 4. El maximo es " << p.maximo() << endl;
  p.push(9);
  cout << "Se introduce el valor 9. El maximo es " << p.maximo() << endl;
  p.push(7);
  cout << "Se introduce el valor 7. El maximo es " << p.maximo() << endl;
  p.push(8);
  cout << "Se introduce el valor 8. El maximo es " << p.maximo() << endl;
   
  cout << "La cola tiene " << p.size() << " elementos. ";
  cout << "El maximo es " << p.maximo() << endl;

  while(!p.empty()){
    cout << "El frente contiene " << p.front() << ". ";
    cout << "El maximo es " << p.maximo() << ". ";
    p.pop();
    cout << "Se quita este valor" << endl;
  }
 
  Cola_max <float> q;
  q.push(2.4);
  cout << "Se introduce el valor 2.4. El maximo es " << q.maximo() << endl;
  q.push(5.5);
  cout << "Se introduce el valor 5.5. El maximo es " << q.maximo() << endl;
  q.push(4.1);
  cout << "Se introduce el valor 4.1. El maximo es " << q.maximo() << endl;
  q.push(9.6);
  cout << "Se introduce el valor 9.6. El maximo es " << q.maximo() << endl;
  q.push(7.9);
  cout << "Se introduce el valor 7.9. El maximo es " << q.maximo() << endl;
  q.push(8.3);
  cout << "Se introduce el valor 8.3. El maximo es " << q.maximo() << endl;
   
  cout << "La cola tiene " << q.size() << " elementos. ";
  cout << "El maximo es " << q.maximo() << endl;

  while(!q.empty()){
    cout << "El frente contiene " << q.front() << ". ";
    cout << "El maximo es " << q.maximo() << ". ";
    q.pop();
    cout << "Se quita este valor" << endl;
  }*/

  return 0;
}
