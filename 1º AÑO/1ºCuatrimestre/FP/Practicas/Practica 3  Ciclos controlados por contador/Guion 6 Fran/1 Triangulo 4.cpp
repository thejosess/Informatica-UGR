/* Triangulo 4 */



#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int L;
	
	cout<<"Introducir longitud: ";
	cin>>L;
	
	for(int i=1;i<=L;i++){
		
		
		for(int j=1;j<=i;j++){
			cout<<' ';
			}
		
		for(int j=L;j>=i;j--){
			cout<<'*';
		}
			
	
		cout<<endl;
	}

}
