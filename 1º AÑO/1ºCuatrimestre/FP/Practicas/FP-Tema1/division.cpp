       // Programa que lee dos números enteros por
       // teclado y muestra por pantalla su
       // division real (Ver. 1)

      #include <iostream>

      using namespace std;

      int main()
      {
         int dato1;
         int dato2;
         double division;

         cout << "Introducir primer dato: ";
         cin >> dato1;

         cout << "Introducir segundo dato: ";
         cin >> dato2;

         division = (1.0*dato1) / dato2;

         cout << "La division es: " << division << endl;
      }

