#include <iostream>
#include <cmath>
using namespace std;

class Polinomio2G{
  
  private:  
    // Siendo el polinomio ax^2+bx+c
    int a, b, c;

  public:
    Polinomio2G()
        :a(0), b(0), c(0) {}

    Polinomio2G Suma(Polinomio2G p1, Polinomio2G p2){
        Polinomio2G p3;
        p3.a = p1.a+p2.a;
        p3.b = p1.b+p2.b;
        p3.c = p1.c+p2.c;

        return p3;
    }

    Polinomio2G MultiplicacionConst(Polinomio2G p1, int k){
        Polinomio2G p2;
        p2.a = k*p1.a;
        p2.b = k*p1.b;
        p2.c = k*p2.c;

        return p2;
    }

   /*Tecnicamente no se puede hacer eso */ void CalculoRaices(){
        float x1, x2;
        if(a==0){
            x1 = (-c)/b;
            cout<<"\nLa raíz es: "<<x1;
        }
        else{
            if( (b*b-4*a*c)>=0 ){
            x1=(-b+sqrt(b*b-4*a*c))/(2*a);
            x2=(-b-sqrt(b*b-4*a*c))/(2*a);
            
            cout<<"\nLa raíz 1 es: "<<x1;
            cout<<"\nLa raíz 2 es: "<<x2;
            }
            else
                cout<<"\nNo existen raices";
        }
    }
};
