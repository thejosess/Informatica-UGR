#include <iostream>
using namespace std;

int main(){
     
int numero;
int divisor;
cout << "Introduzca un número: ";
cin >> numero;
divisor=1;
do {
if((numero%divisor)==0)
    cout << " " << divisor <<" es divisor";
    divisor++;
}while(divisor<=numero);

}
