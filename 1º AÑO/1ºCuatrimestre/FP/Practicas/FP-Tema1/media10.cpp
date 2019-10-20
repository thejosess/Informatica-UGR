
// Programa que lee 10 números por teclado
// y muestra por pantalla su media

     #include <iostream>
     #include <stdlib.h>
     using namespace std;

     int main (){
         double variable, suma, media;
         int i;

         suma=0;
         for (i=1; i<=10; i++)
         {
              cout << "Introducir dato " << i << " :";
              cin >> variable;

              suma=suma+variable;
         }
         media=suma/10;
         cout << "La media es: " << media << endl;
     }

