#include <iostream>	

using namespace std;

int main (){
	
	int l , i , j ; 
	
	cout << "Ingrese el alto : " ;
	cin >> l ;
	
		for ( j = 1 ; j <= l ; j ++)
		{
			
			for ( i = 1 ; i <= ( l - j) ; i ++)
			{
				cout << " " ;
			}
			
			for ( i = 1 ; i<= ( j * 2 - 1) ; i++)
			{
				cout << "*";
				
			}
			cout << endl;
			
		}
	
	
	
	
}
