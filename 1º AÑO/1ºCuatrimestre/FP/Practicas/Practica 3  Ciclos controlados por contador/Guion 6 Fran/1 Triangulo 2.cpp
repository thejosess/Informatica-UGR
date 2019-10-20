/* Triangulo 2  */



#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int L;
	cout<<"Introducir longitud: ";
	cin>>L;
	
	for(int i=L;i>=1;i--){
		for(int j=1;j<=i;j++){
			cout<<'*';
			}
	
		cout<<endl;
}


}
