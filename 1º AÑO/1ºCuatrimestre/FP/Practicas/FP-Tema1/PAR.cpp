   // Programa que lee dos números enteros y muestra por pantalla el mayor
   
      #include <iostream>
      using namespace std;
      int main()
      {
         int n; 
          
         cout << "Introducir un dato: ";  
         cin >> n;                     
    
         if (n % 2 == 0); // <----------- ¡ CUIDADO CON EL PUNTO Y COMA ! 
             cout << n << " es PAR" << endl;
      }
