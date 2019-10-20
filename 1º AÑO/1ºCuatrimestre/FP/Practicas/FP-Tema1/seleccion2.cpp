   // Programa que muestra lo que ocurre cuando se confunde la 
   // igualdad (==) con el operador de asignación (=)
      #include <iostream>
      using namespace std;
      int main()
      {
         int dato1; 
          
         cout << "Introducir primer dato: ";  
         cin >> dato1;                     
    
         if (dato1 = 5) 
            cout << dato1 << " es igual a 5!" << endl;
         else
            cout << dato1 << " es distinto a 5!" << endl;
      }
