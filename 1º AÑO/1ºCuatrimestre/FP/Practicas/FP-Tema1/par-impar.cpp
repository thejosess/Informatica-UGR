    // Programa que determina si un número es par o impar

     #include <iostream>
     using namespace std;
 
     int main ()
     {
         int numero, resto;

         cout << "Introducir numero: ";  
         cin >> numero;

         resto = numero % 2;

         if (resto == 0)
            cout << numero << " es par" << endl;
         else 
            cout << numero << " es impar" << endl;
     }

