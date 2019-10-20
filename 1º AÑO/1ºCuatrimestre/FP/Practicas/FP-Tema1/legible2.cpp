// PROGRAMA QUE RESUELVE LA ECUACION ax+b=0
// ENTRADAS: Los coeficientes a y b
// SALIDAS:  La solución x

#include <iostream>
using namespace std;

int main()
{
        double a, b, x;
        
        //ENTRADAS
        cout << "PROGRAMA QUE RESUELVE LA ECUACION ax+b=0" << endl;
        
        cout<<"Introducir a: ";
        cin>>a;   
        
        cout<<"Introducir b: ";
        cin >> b;
        
        //PROCESO Y SALIDAS
        if (a != 0)
        {
            x = -b / a;
        
            cout<<"x: :" << -b / a << endl;
        }    
        else
            cout<<"No existe solucion" << endl;
}
