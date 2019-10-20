
// Programa que lee dos números por teclado 
// y muestra por pantalla su producto

     #include <iostream>
     #include <cmath>
     #include <stdlib.h>
     using namespace std;
 
     int main (){
         int a, b, c, mayor;
          
         cout << "Introducir dato 1: ";  
         cin >> a;                     
    
         cout << "Introducir dato 2: ";  
         cin >> b;                     
         
         cout << "Introducir dato 3: ";  
         cin >> c;
         
         if (a>b)
            if (a>c)
               mayor=a;
            else
               mayor=c;
         else
            if (b>c)
               mayor=b;
            else
               mayor=c;
        
         cout << "El mayor es: " << mayor << endl;                                     
     }

