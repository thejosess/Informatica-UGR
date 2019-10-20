# include <iostream>
using namespace std ;

int main ()
{
    int n ;
    
    cout << " Ingrese un numero : " ;
    cin >> n ;
    
    for (int j = 0 ; j < n ; ++j) 
	{
        for (int i = 0; i < n-j-1; ++i)
        
            cout << " ";
            
        for (int i = 0; i < 2*j+1; ++i)
        
             cout << "*" ;
        	cout << endl ;
    }

    for (int j=n-2; j>=0; --j) 
	{
        for (int i=0; i<n-j-1; ++i)
        
            cout << " " ;
            
        for (int i=0; i<2*j+1; ++i)
        
            cout << "*" ;
        	cout << endl ;
    }
}

