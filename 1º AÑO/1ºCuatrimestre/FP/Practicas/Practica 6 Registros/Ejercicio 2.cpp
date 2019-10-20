/*2. Se desea definir un nuevo tipo de dato rect�ngulo, formado por dos reales (base y altura). Se
pide realizar los siguientes m�dulos:
� Leer un rect�ngulo. Rectangulo LeerRec()
� Calcular el �rea de un rect�ngulo. double Area(Rectangulo r)
� Mostrar los datos de un rect�ngulo por pantalla. void MostarRec(Rectangulo r)
Utilizar los m�dulos anteriores para (1) leer un vector de rect�ngulos, (2) ordenarlo (de forma
descendente) en funci�n de sus �reas y (3) mostrar el vector de rect�ngulos por pantalla.*/

using namespace std;

#include <iostream>
#include <cmath> 

struct Rectangulo{
	double base; 
	double altura;
};

Rectangulo LeerRec()
{
	Rectangulo r;
	
	cout<<"introducir base: ";
	cin>>r.base;
	
	cout<<"introducir altura: ";
	cin>>r.altura;
	
	return r;
	
}

double Area(Rectangulo r)
{
	return r.base*r.altura;
}

void MostrarRec(Rectangulo r)
{
	cout<<" base: "<<r.base<<" altura: "<<r.altura<<endl;
}

int main()
{
	//Utilizar los m�dulos anteriores para , y (3) mostrar el vector de rect�ngulos por pantalla.*/

int MAX=1000, util_v, izda, i;
Rectangulo v[MAX] , tmp;
bool cambio;

//(1) leer un vector de rect�ngulos

do{
	cout<<"Introducir numero de rectangulos ( >="<<MAX<<" ): "<<endl;
	cin>>util_v;
}while (util_v <= 0 || util_v > MAX);

for(int i=0; i<util_v; i++)
{
	cout << "\nEntrada del rectangulo: " << i+1 << endl;
   v[i]=LeerRec();
}

//(2) ordenarlo (de forma descendente) en funci�n de sus �reas 

cambio= true;
   for (izda=0; izda<util_v && cambio; izda++)
   {
          cambio=false;
          for (i=util_v-1 ; i>izda ; i--)
              if ( Area(v[i]) < Area(v[i-1]) )
              {
                   tmp=v[i];
                   v[i]=v[i-1];
                   v[i-1]=tmp;
				   
                   cambio=true;
              }
   }
              
//(3) mostrar el vector de rect�ngulos por pantalla.

 cout << "\nLos rectangulos ordenados por su area son:" << endl;

   for(int i=0; i<util_v; i++)
   {
      MostrarRec(v[i]);

       cout << " Area: " << Area(v[i]) << endl;
   }
}
