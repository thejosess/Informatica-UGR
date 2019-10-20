// Ejercicio 4 con otra version

#include <iostream>
using namespace std;
int main()

{
   int division , n , i ;
   bool esprimo = true ;

   
         cout << "Ingrese numero"<< endl;
         cin >> n ; 
         
         for (i = 2 ; i < n ; i++ ){
         	
         if ( n % i == 0  )
         	
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
