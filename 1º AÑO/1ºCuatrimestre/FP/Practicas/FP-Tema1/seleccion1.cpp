   // Programa que lee dos números enteros y muestra
   // por pantalla el mayor

      #include <iostream>
      using namespace std;

      int main()
      {
         int dato1, dato2, mayor;

         cout << "Introducir primer dato: ";
         cin >> dato1;

         cout << "Introducir segundo dato: ";
         cin >> dato2;

         if (dato1 > dato2)
            mayor = dato1;
         else
            mayor = dato2;

         cout << "El mayor es: " << mayor << endl;
      }
