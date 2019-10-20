#include <iostream> 

using namespace std; 

int main() 
{ 
	int multiplicando,multiplicador,c; 
	c=0; 
	cout << "Hello world!" << endl; 
	cin>> multiplicando; 
	cin>> multiplicador ; 

	while (multiplicando !=0 ){ 
	
		if (multiplicando %2 !=0) 
		
			c = c + multiplicador ; 
			multiplicando = multiplicando / 2; 
			multiplicador = multiplicador * 2; 
		} 
		
		cout<<"respuesta"<<c<<endl; 

}
