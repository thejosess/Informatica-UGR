#include <iostream>
using namespace std ;

bool EsPrimo (int n)
{
	bool es_primo=true;
	
	if (n%2!=0 || n==2)
	{
		for (int i=2; i<n && es_primo; i++)
			if (n%i == 0 && n!=2)
				es_primo = false;
	}
	else
		es_primo=false;
	
	return es_primo;
}

int main () {
	
	int numero ;
	
	cout << "Introducir numero" ;
	cin >> numero ;
	
	if(EsPrimo(numero))
		cout << "Es primo" << endl;
	else
		cout <<"No es primo" << endl ;
	
}


/*	for (int izda = 0; izda < Total_fil() && cambio; izda++){  
			cambio = false;
			for (int i = Total_fil()-1 ; i > izda ; i--) */
