#include <iostream> 

using namespace std; 
int main() 
{ 
	int l; 
	int j , i;
	 
	cout<<"Ingrese el Alto: "; 
	cin>> l ; 

		for( j = l ; j >= 1 ; j--) 
		{ 
		
			for( i = 1; i <= (l - j) ; i ++) 
			{ 
				cout<<" "; 
			} 
			
			for(i = 1; i <= (j*2-1) ; i ++) 
			{ 
				cout<<"*"; 
			} 
			cout<<endl; 
		} 
		
		cout<<endl; 
		cout<<endl; 
		
}

