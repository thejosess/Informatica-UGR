//triangulo equilatero hueco por dentro

#include <iostream>

using namespace std;

int main ()
{
	int j, k, n=6;

	for(int i=1; i<=n-1; i++)
	{
		
		for(j=i-1; j<=n-1; j++)
		{
			cout<<" ";
		}
		
		cout<<"*"<<endl;
	
		for(int l=n-1; l>=0; l--)
		{
			cout<<" ";
		}
		
				
		for(k=i-1; k>=0; k--)
		{
			cout<<" ";
		}
		
		cout<<"*"<<endl;
		
		
	}
	
	for(int i=1; i<=n; i++)
	{
		cout<<" "<<"*";
	}

}
