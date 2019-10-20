#include <iostream>
using namespace std ;
int main ()
{
   int n ;
   cout << " Introduzca un numero : " ;
   cin >> n ;
   for (int j=0; j<n ; ++j) {
      for (int i=0; i<n ; ++i) {
         cout << '*' ;
      }
      cout << endl;
   }
}
