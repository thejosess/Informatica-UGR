//Programa que muestra el equipo ganador en la primera mitad
//del partido, al final del partido, el marcador final y el número 
//de triples anotados a partir de los datos de entrada que son el 
//equipo (A o B), puntos(1,2 o 3) y el minuto (0 a 39).

#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "spanish");
	
	cout<<"Programa que muestra el equipo ganador en la primera mitad del partido, al final del partido,"<<endl;
	cout<<" el marcador final y el número"<<endl;
	cout<<"de triples anotados a partir de los datos de entrada que son el equipo (A o B), puntos(1,2 o 3) y el minuto (0 a 39)."<<endl;
	cout<<endl;
	
	int puntos, minuto, puntosA, puntosB, puntosAprimeraparte=0, puntosAsegundaparte=0, puntosBprimeraparte=0, puntosBsegundaparte=0, triples=0;
	char equipo=' ';
	bool fin_del_partido;
	fin_del_partido=false;
	
	while(!fin_del_partido)
	{	
	
		puntos=0; 
		minuto=-3;
		string respuesta;
		equipo=' ';
	
		
		while(equipo!='A' && equipo!='B' )
		{
			cout<<"Introducir el equipo, A o B"<<endl;
			cin>>equipo;
		}
		
		while(puntos!=1 && puntos!=2 && puntos!=3 )
		{
			cout<<"Introducir los puntos 1, 2 o 3"<<endl;
			cin>>puntos;
		}
		
		while(minuto<0 || minuto>39 )
		{
			cout<<"Introducir el minuto en el que se ha anotado el punto, entre 0 y 39"<<endl;
			cin>>minuto;
		}
		
		do{
			cout<<"¿Ha terminado ya? (si o no)"<<endl;
			cin>>respuesta;
		}while(respuesta!="si" && respuesta!="no");
		
		if(respuesta=="si")
		{
			fin_del_partido=true;
		}
		
			if(equipo=='A')
	{
		if(minuto<20)
		{
			puntosAprimeraparte=puntosAprimeraparte+puntos;
		}
		else
		{
			puntosAsegundaparte=puntosAsegundaparte+puntos;
		}
	}
	
	puntosA=puntosAprimeraparte+puntosAsegundaparte;
	
	if(equipo=='B')
	{
		if(minuto<20)
		{
			puntosBprimeraparte=puntosBprimeraparte+puntos;
		}
		else
		{
			puntosBsegundaparte=puntosBsegundaparte+puntos;
		}
	}
	
	puntosB=puntosBprimeraparte+puntosBsegundaparte;
	
	if(puntos==3)
	{
		triples++;
	}
}
	

	
	//SALIDA
	
	cout<<endl;
	cout<<"RESULTADOS DEL PARTIDO!:";
	cout<<endl;
	
	cout<<"el marcador final es "<<puntosA<<" a "<<puntosB<<endl;
	cout<<"El numero de triples del partido han sido"<<triples<<endl;
	
	if(puntosAprimeraparte>puntosBprimeraparte)
	{
		cout<<"en la primera parte va ganando el equipo A"<<endl;
	}
	else
	{
		cout<<"En la primera parte va ganando el equipo B"<<endl;
	}
	
	cout<<endl;
	
	if(puntosA>puntosB)
		cout<<"El equipo A ha ganado el partido"<<endl;
	else
		cout<<"El equipo B ha ganado el partido"<<endl;
		
	cout<<"¡ENHORABUENA!";
	
		
}
