// Ejercicio 4 con while

#include <iostream>
using namespace std;
int main()

{
   int division , n , i ;
   bool esprimo = true ;

   
         cout << "Ingrese numero"<< endl;
         cin >> n ; 
         
         i = 2 ; 
         
         while (i < n ){
         
         division = n % i ;
         
         i++ ;
         
         if ( division == 0  )
         	
             esprimo = false ;  
         }
         
         
         if ( esprimo ) 
         
			{
            cout << "Es Primo" ;
              
         }
				else {
					
               cout<< "No es Primo" ;
         }
}
