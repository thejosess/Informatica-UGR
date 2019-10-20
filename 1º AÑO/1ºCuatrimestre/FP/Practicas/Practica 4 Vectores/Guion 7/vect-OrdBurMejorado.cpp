/*
      Este programa ordena un vector mediante el método de la burbuja mejorado
*/

#include <iostream>
using namespace std;

int main()
{
    const int MAX = 1000;
    double v[MAX];
    int util_v, izda, i, tmp;
    double aux;
    bool cambio;

    do{
       cout << "Introduzca número de componentes: ";
       cin >> util_v;
    }while (util_v > MAX || util_v < 0);

    cout << "\nIntroduzca valores reales:\n";
    for (int i=0 ; i<util_v ; i++)
    {
         cout << "Pos. " << i << ": ";
         cin >> v[i];
    }

//**************************************************
    cambio = true;                                //
    for (izda=0; izda<util_v && cambio; izda++)   //
    {                                             //
             cambio = false;                      //
             for (i=util_v-1 ; i>izda ; i--)      //
             if (v[i] < v[i-1])                   //
             {                                    //
                  tmp = v[i];                     //
                  v[i] = v[i-1];                  //
                  v[i-1] = tmp;                   //
			                                      //
			      cambio = true;                  //
             }                                    //
    }                                             //
//**************************************************

    cout << "El vector ordenado es: " << endl;
    for (int i=0; i<util_v; i++)
         cout << v[i] << endl;
}
