#include <iostream>
using namespace std;
int main (){
	int i,j,L;
	cout<<"Introducir el lado del triangulo;";
	cin>>L;
	 
	 for(i=1;i<=L;i++){
	 	for(j=1;j<=L-1;j++)
	 	cout<<" "<<endl;
	 	for(j=1;j<=i;j++)
	 	cout<<"*"<<endl;
	 	
	 }
}
