#include <iostream>
#include <string>
using namespace std ;

int main(){
	
	const int MAX = 1000 ;
	int v1[MAX] , v2 [MAX] , vu[MAX] , util_vu , util_v1, util_v2 , i , j , x , izda , tmp;
	
	do{
		cout << "Introduzca el num de elementos VECTOR 1 que va a tener el vector (entre 1 y " << MAX << "): ";
		cin >> util_v1;
	}while (util_v1 < 1 || util_v1 > MAX);
	
	do{
		cout << "Introduzca el num de elementos VECTOR 2 que va a tener el vector (entre 1 y " << MAX << "): ";
		cin >> util_v2;
	}while (util_v2 < 1 || util_v2 > MAX);
	
	
	for (int i=0; i<util_v1; i++)
	{
		cout << "Introduzca el elemento VECTOR 1 del vector: ";
		cin >> v1[i];
	}
	
	
	for (int i=0; i<util_v2; i++)
	{
		cout << "Introduzca el elemento VECTOR 2 del vector: ";
		cin >> v2[i];
	}
	
	//vector union
	util_vu = util_v1 + util_v2 ;
	
	for ( int i = 0 ; i < util_v1 ; i++)
		
		vu[i] = v1[i] ;
	
	 x = 0 ;	
	for ( int i = util_v1 ; i < util_vu ; i++){
		
		vu[i] = v2[x] ;
		x++ ;
	}
	
	//*******************************************
    for (izda=0; izda<util_vu; izda++)      //
          for (i=util_vu-1 ; i>izda ; i--)  //
             if (vu[i] < vu[i-1])            // 
             {                             //
             	  tmp = vu[i];              //
                  vu[i] = vu[i-1];           //
                  vu[i-1] = tmp;            //
			 }                             //
//*******************************************

    cout << "El vector ordenado es: " << endl;
    for (int i=0; i<util_vu; i++)
         cout << vu[i] << endl;

}
