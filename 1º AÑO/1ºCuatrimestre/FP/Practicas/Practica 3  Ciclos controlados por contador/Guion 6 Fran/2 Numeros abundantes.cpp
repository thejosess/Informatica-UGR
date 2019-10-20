/* Numeros abundantes*/



#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int suma, contador=0, i=1;
	
	while(contador<50){
		
		suma=0;
		
		for(int j=1;j<i;j++){
			
			if(i%j==0){
				suma=suma+j;
			}
			
		}
		if(suma>i){
			cout<<"Numero "<<contador+1<<": "<<i<<endl;
			contador++;	}	
		i++;
		}
			
	
	}

