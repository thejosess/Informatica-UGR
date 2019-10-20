#include <iostream>
#include <string>
using namespace std ;

int main(){
	
	const int MAX = 1000 ;
	string v[MAX] , vectorRepe[MAX] ;
	int util_v , i , j , util_vector_repe ;
	bool encontrado ;
	
	do{
		cout << "Introduzca el num de elementos que va a tener el vector (entre 1 y " << MAX << "): ";
		cin >> util_v;
	}while (util_v < 1 || util_v > MAX);
	
	cout << endl;
	
	for (int i=0; i<util_v; i++)
	{
		cout << "Introduzca el elemento " << i+1 << " del vector: ";
		cin >> v[i];
	}
	
	util_vector_repe = 0;
    for (int i=0 ; i<util_v ; i++)
    {
          j = 0;
          encontrado = false;
          while (j<util_vector_repe && !encontrado)
               if (v[i] == vectorRepe[j])
                  encontrado=true;
               else
                  j++;

          if (!encontrado)
          {
              vectorRepe[util_vector_repe] = v[i];
              util_vector_repe ++;
          }
    }

    cout << "\nEl vector sin repetidos es: " << endl;
    for (int i=0; i<util_vector_repe; i++)
        cout << vectorRepe[i] << endl;
}
