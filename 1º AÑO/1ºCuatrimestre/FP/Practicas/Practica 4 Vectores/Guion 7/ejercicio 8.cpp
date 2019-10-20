#include <iostream>
#include <string>
using namespace std ;

int main(){
	
	const int MAX = 1000 ;
	string v[MAX] ;
	int util_v  , j ,  i=0 , pos;
	
	do{
		cout << "Introduzca el num de elementos que va a tener el vector (entre 1 y " << MAX << "): ";
		cin >> util_v;
	}while (util_v < 1 || util_v > MAX);
	
	cout << endl;
	
	for (int i=0; i<util_v; i++)
	{
		cout << "Introduzca el elemento " << i+1 << " del vector: ";
		cin >> v[i];
	}
	
	
	while (i<util_v)
	{
		pos=i+1;
		while(pos<util_v)
		{
			if(v[i]==v[pos])
			{
				//Borrar
				for (int j=pos; j<util_v-1; j++)
					v[j]=v[j+1];
				util_v--;
			}
			else
				pos++;
		}
		i++;
	}
	
	for ( i = 0 ; i < util_v ; i++){

		cout << "El vector es : " << v[i] << endl;
	}
}
