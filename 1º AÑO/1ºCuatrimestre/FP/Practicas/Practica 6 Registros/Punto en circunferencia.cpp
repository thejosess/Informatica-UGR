#include <iostream>
#include <cmath>

using namespace std;

struct punto
{
	double x, y;
};

struct circunferencia
{
	punto centro;
	double radio;
};

punto LeerPunto ()
{
	punto p;
	
	cout << "\n\tIntroduzca la coordenada x: ";
	cin >> p.x;
	
	cout << "\tIntroduzca la coordenada y: ";
	cin >> p.y;
	
	return p;
}

punto LeerPuntoDobleTab ()
{
	punto p;
	
	cout << "\n\t\tIntroduzca la coordenada x: ";
	cin >> p.x;
	
	cout << "\t\tIntroduzca la coordenada y: ";
	cin >> p.y;
	
	return p;
}

void ImprimirPunto (punto p)
{
	cout << "(" << p.x << ", " << p.y << ")";
}

circunferencia LeerCircunferencia ()
{
	circunferencia c;
	
	cout << "\n\tCentro de la circunferencia:\n\t";
	c.centro=LeerPuntoDobleTab();
	
	cout << "\n\tIntroduzca el radio de la circunferencia: ";
	cin >> c.radio;
	
	return c;
}

double DistanciaEuclidea (punto p1, punto p2)
{
	return sqrt ( pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2) );
}

bool PuntoDentroCircunferencia (punto p, circunferencia c)
{
	if (DistanciaEuclidea(p, c.centro) < c.radio)
		return true;
	else
		return false;
}

bool PuntoPerimetroCircunferencia (punto p, circunferencia c)
{
	if (DistanciaEuclidea(p, c.centro) == c.radio)
		return true;
	else
		return false;
}

int main ()
{
	setlocale(LC_ALL, "spanish");
	
	cout << endl << "Programa que muestra la relación entre un punto y una circunferencia" << endl;
	
	circunferencia c;
	punto p;
	
	cout << endl << "Circunferencia:" << endl;
	c=LeerCircunferencia();
	
	cout << endl << "Punto a comprobar:" << endl;
	p=LeerPunto();
	
	if (PuntoDentroCircunferencia(p, c))
	{
		cout << endl << "El punto ";
		ImprimirPunto(p);
		cout << " es un punto interior a la circunferencia introducida" << endl;
	}
	else
		if (PuntoPerimetroCircunferencia(p, c))
		{
			cout << endl << "El punto ";
			ImprimirPunto(p);
			cout << " es un punto perteneciente al perímetro de la circunferencia introducida" << endl;
		}
		else
		{
			cout << endl << "El punto ";
			ImprimirPunto(p);
			cout << " es un punto exterior a la circunferencia introducida" << endl;
		}
}
