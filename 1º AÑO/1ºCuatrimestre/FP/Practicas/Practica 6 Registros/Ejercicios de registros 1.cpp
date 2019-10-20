#include <iostream>
#include <cmath>
using namespace std ;

struct Punto{
 	double x;
 	double y;
};

struct Circulo{
 	Punto centro;
 	double radio;
};

Punto LeerPunto()
{
	Punto un_punto ;
	
	cout << "Introducir cordenada X : \n" ;
	cin >> un_punto.x ;
	
	cout << "Introducir cordenada Y : \n" ;
	cin >> un_punto.y ;
	
	return un_punto ;
}

Circulo LeerCir()

{
	Circulo un_circulo ;
	
	cout << "Introducir el centro \n" ;
	un_circulo.centro = LeerPunto() ;
		
	
	cout << "Introducir radio: ";
	cin >>  un_circulo.radio;
	
	return un_circulo ;
	
}

void MostrarCir(Circulo c)
{
	cout << "El centro del circulo es : " <<"("<< c.centro.x << "," <<c.centro.y << ")" << "\n El radio del circulo es: " << c.radio << endl ;
}

double DistanciaEuclidea(Punto p1, Punto p2){
	return sqrt((p1.x-p2.x)*(p1.x*p2.x)+(p1.y-p2.y)*(p1.y*p2.y));
}


bool EstaDentro(Punto p,Circulo c){

	if(DistanciaEuclidea( p, c.centro)<c.radio)
		return true;
		else
			return false;
		
}

int main ()
{
	const int MAX = 1000 ;
	int util_v , util_v1 = 0  , util_v2 = 0;	
	Circulo v[MAX] , v1[MAX] , v2[MAX] , circulo ;
		
	Punto p ;
	
	cout << "Introducir punto\n " ;
	p = LeerPunto() ;
	
	do{
        cout << "Numero de circulos del vector (<=" << MAX << "):";
        cin >> util_v;
   }while (util_v <= 0 || util_v > MAX);
	
	for ( int i=0 ; i < util_v ; i++){
		
		cout << "Introducir terminos del vector circulos\n " ;
		v[i] = LeerCir() ;	
	}
	
	for ( int i=0 ; i < util_v ; i++){
		
		if(EstaDentro( p , v[i]))
		{
			util_v1 ++ ;
			v1[i] = v[i] ;
		}
		
		if(!EstaDentro( p , v[i]))
		{
			util_v2 ++ ;
			v2[i] = v[i] ;
		}
	}
	
	for (int i=0 ; i < util_v1 ; i++){
		
		cout << "Los circulos que contienen al punto dentro son : \n" ;
		MostrarCir(v1[i]) ;	
	}
	
	for ( int i=0 ; i < util_v2 ; i++){
		
		cout << "Los circulos que no contienen al punto dentro son : \n" ;
		MostrarCir(v2[i]) ;	
	} 	
}
