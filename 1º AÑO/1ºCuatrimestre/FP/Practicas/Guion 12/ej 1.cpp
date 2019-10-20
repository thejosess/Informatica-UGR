// Elaborar una clase “Polinomio2G” que modele los polinomios de grado dos implementando las
// operaciones de suma (de un polinomio con otro para obtener un tercer polinomio), producto por un
// número real y cálculo de las raíces reales del polinomio, si es que existen. Realizar un programa
// principal para probar los distintos métodos realizados.

#include <iostream>
#include <cmath>
using namespace std;

class Polinomio2G
{
	private:
		static const int v_util=3;
		int vp[v_util];
		int c, l, i;
	 
	public:	// // Constructores
		 Polinomio2G()
		 :c(0), l(0), i(0) {}
	
		void SetPolinomio ( int t_c, int t_l, int t_i)
		{
		c=t_c;
		l=t_l;
		i=t_i;	
		}
		
		int GetCuadrado ()
		{
			return c;
		}
		int GetLineal ()
		{
			return l;
			
		}
		int GetIndependiente ()
		{
			return i;
		}
	// Modulo Suma de dos polinomios de segundo grado
		
		Polinomio2G SumaPolinomios (Polinomio2G p2)
		{
			Polinomio2G suma;
			
			suma.c = p2.c+c;
   	   suma.l = p2.l+l;
  	    	suma.i = p2.i+i;
			
			return suma;
		}
		
		Polinomio2G ProductoReal (int real)
		{
			Polinomio2G producto;
			
			producto.c = c * real;
			producto.l = l * real;
			producto.i = i * real;
			
			return producto;
		}
		int Raiz1Polinomio()
		{
			float raiz1;
			
			raiz1 = (-(l) + sqrt((l * l) - (4 * c * l))) / (2*c);
			
			return raiz1;
			
		}
		
			int Raiz2Polinomio()
		{
			float raiz2;
			
			raiz2 = (-(l) - sqrt((l * l) - (4 * c * l))) / (2*c);
			
			return raiz2;
			
		}
		
};


int main ()
{
	Polinomio2G p1, p2, suma;
	int c1, l1, i1, c2, l2, i2;
	
	
	cout << "Introducir terminos del polinomio 1: " << endl;
	cout << "Cuadrado: ";
	cin >> c1;
	cout << endl << "Lineal: ";
	cin >> l1;
	cout << endl << "Independiente: ";
	cin >> i1;
	
	cout << "Introducir terminos del polinomio 2: " << endl;
	cout << "Cuadrado: ";
	cin >> c2;
	cout << endl << "Lineal: ";
	cin >> l2;
	cout << endl << "Independiente: ";
	cin >> i2;
	
	p1.SetPolinomio( c1, l1, i1);
	p2.SetPolinomio( c2, l2, i2);
	
	suma = p1.SumaPolinomios(p2);

	cout << "La suma seria:   " << "Resultado = ";
	cout << suma.GetCuadrado() << "x^2 + " << suma.GetLineal() <<  "x + " << suma.GetIndependiente() << endl;
	
	int real;
	cout << "Introducir real para multiplicar unos de los dos polinomios por ese real:   " ;
	cin >> real;
	int elegir;
	Polinomio2G producto;
	do{
		cout << "Introducir 1 para multiplicar el real con el primer polinomio" << endl << "Intrdocur 2 para multiplicar el real con el segundo polinomio" << endl;
		cin >> elegir;
	}while (elegir!=1 && elegir!=2);
	if (elegir==1)
	{
		cout << "El producto entre el primer polinomio y " << real << " =   ";
		producto = p1.ProductoReal(real);
		cout << producto.GetCuadrado() << "x^2 + " << producto.GetLineal() <<  "x + " << producto.GetIndependiente() << endl; 
	}
	if (elegir==2)
	{
		cout << "El producto entre el segundo polinomio y " << real << " =   ";
		producto = p2.ProductoReal(real);
		cout << producto.GetCuadrado() << "x^2 + " << producto.GetLineal() <<  "x + " << producto.GetIndependiente() << endl; 
	}
	int elegir2, raiz1, raiz2;
	do{
		cout << "Introducir 1 para calcular las raices del primer polinomio" << endl << "Intrdocur 2 para para calcular las raices del segundo polinomo" << endl;
		cin >> elegir2;
	}while (elegir2!=1 && elegir2!=2);
	if (elegir2==1)
	
		if (elegir2==1)
	{
		cout << "Las raices del primer polinomio serian:   ";
		raiz1 = p1.Raiz1Polinomio();
		raiz2 = p1.Raiz2Polinomio();
		cout << raiz1 << " y " << raiz2;
	}
	if (elegir2==2)
	{
		cout << "Las raices del segundo polinomio serian:" << endl;
		raiz1 = p2.Raiz1Polinomio();
		raiz2 = p2.Raiz2Polinomio();
		cout << raiz1 << " y " << raiz2;
	
	}
	
}









