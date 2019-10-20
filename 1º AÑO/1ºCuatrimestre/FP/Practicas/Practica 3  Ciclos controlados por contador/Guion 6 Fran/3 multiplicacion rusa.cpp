/* Multiplicacion rusa */



#include <iostream>
#include <cmath>

using namespace std;

int main()
{
		int m,n,suma=0;
		
		cout<<"Introducir multiplicando: ";
		cin>>n;
		cout<<"Introducir multiplicador: ";
		cin>>m;
		
		while(n>=1){
			
			if(n%2!=0)
				suma=suma+m;
					
			m=m*2;
			n=n/2;
		}
		
		cout<<"El resultado es: "<<suma;
			
		
				


}
