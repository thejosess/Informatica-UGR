/*
      Este programa ordena un vector mediante el método de la burbuja
*/

#include <iostream>
using namespace std;

int main()
{
    const int MAX = 1000;
    double v[MAX];
    int util_v, izda, i, tmp;
    double aux;

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

//*******************************************
    for (izda=0; izda<util_v; izda++)      //
          for (i=util_v-1 ; i>izda ; i--)  //
             if (v[i] < v[i-1])            // 
             {                             //
             	  tmp = v[i];              //
                  v[i] = v[i-1];           //
                  v[i-1] = tmp;            //
			 }                             //
//*******************************************

    cout << "El vector ordenado es: " << endl;
    for (int i=0; i<util_v; i++)
         cout << v[i] << endl;
}
