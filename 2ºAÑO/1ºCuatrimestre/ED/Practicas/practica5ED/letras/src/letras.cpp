#include <fstream>
#include <iostream>
#include <string.h>
#include "bolsa_letras.h"
#include <algorithm>

#define RED "\033[31m"
#define GREEN "\033[96m"
#define WHITE "\033[37m"
#define CYAN "\033[36m"
#define ORANGE "\033[33m"

void sintaxis_incorrecta()
{
	cerr << RED << "\nSINTAXIS INCORRECTA" << endl
			<< "Los parámetros de entrada son los siguientes:\n" <<
				"\t1. El nombre del fichero con la lista de palabras\n" <<
				"\t2. El nombre del fichero con las letras\n" <<
				"\t3. El numero de letras que se deben generar de forma aleatoria\n"<<
				"\t4. Modalidad del juego: \n"<<
				"\t - L = Longitud: Se buscará la palabras más larga \n"<<
				"\t - P = Puntuación: Se buscará la palabra de mayor puntuación" << WHITE << endl;
}

int main( int argc, char ** argv)
{
	bool longitud;

	if(argc != 5)
	{
		sintaxis_incorrecta();

		return 0;
	}

	ifstream f_lista (argv[1]);
	if (!f_lista)
	{
		cerr << RED << "ERROR ABRIENDO FICHERO: " << argv[1] << endl;
		return 0;
	}

	ifstream f_letras (argv[2]);
	if (!f_letras)
	{
		cerr << RED << "ERROR ABRIENDO FICHERO: " << argv[2] << endl;
		return 0;
	}
	
	if(strcmp(argv[4], "L") == 0 || strcmp(argv[4], "l") == 0)
		longitud = true;
	else if(strcmp(argv[4], "P") == 0 || strcmp(argv[4], "p") == 0)
		longitud = false;
	else
	{
		sintaxis_incorrecta();

		return 0;
	}

	int num_aleatorio = atoi(argv[3]);

	if(num_aleatorio <= 0)
	{
		cerr << RED << "ERROR: EL NUMERO DE LETRAS HA DE SER MAYOR QUE 0" << WHITE << endl;
		return 0;
	}

	lista_palabras lista;
	conjunto_letras conjunto;

	f_lista >> lista; 
	f_letras >> conjunto;
	f_lista.close();
	f_letras.close();

	bolsa_letras bolsa(conjunto);

	multiset<char> ms_letras;

	cout << "----------------------------------------------------\n";
	cout << "  BIENVENIDO AL JUEGO DE LAS LETRAS DE RAY Y JOSÉ  \n";
	cout << "----------------------------------------------------\n";

	bool seguir_jugando = true, ganado;

	while(seguir_jugando)
	{
		ganado = false;

		ms_letras.clear();

		cout << "\nLas letras son: ";

		char c;

		for(int i = 0 ; i < num_aleatorio ; i++)
		{
			c = bolsa.coger_letra();

			cout << CYAN << c << WHITE << '\t';
			
			ms_letras.insert(tolower(c));
		}

		string solucion_user;

		cout <<"\n\nDime tu solucion: ";
		cin >> solucion_user;

		transform(solucion_user.begin(), solucion_user.end(), solucion_user.begin(), ::tolower);

		int puntuacion;

		bool se_puede = lista.es_solucion(solucion_user, ms_letras);
		bool existe = lista.Esta(solucion_user);

		if(!se_puede || !existe)
		{
			if(!se_puede)
				cerr << RED << "\nNo es posible formar esta palabra con las letras dadas..." << WHITE << endl;
			else
				cerr << RED << "\nEsa palabra no existe en el diccionario de la Real Academia de Ray y José..." << WHITE << endl;

			puntuacion = 0;
		}
		else
			puntuacion = conjunto.calcular_puntuacion(solucion_user, longitud);

		cout << "\nTu solucion: " << solucion_user << '\t' << "Puntuacion: " << puntuacion << endl;

		set<pair<string, int>, classcomp> soluciones = lista.buscar_soluciones(ms_letras, conjunto, longitud);
		cout << "\nMis soluciones son:\n\n";

		char jugar;

		if(!soluciones.empty())
		{
			set<pair<string, int>>::iterator it = soluciones.end();

			for(int i = 0; i < 6 && it != soluciones.begin(); i++)
				it--;

			for(it ; it != soluciones.end(); it++)
			{
				cout << it->first << "\t" << "Puntuacion: " << it->second << endl;
			}

			it = soluciones.end();
			it--;

			cout << "\nMejor solucion: " << it->first << "\t" << "Puntuacion: " << it->second << endl;

			if(puntuacion >= it->second)
				ganado = true;

			if(ganado)
				cout << GREEN << "\nHAS GANADO, ERES MEJOR QUE JORDI HURTADO (pero él seguirá siendo más joven)" << WHITE << endl;
			else
				cout << RED << "\nERES UN PERDEDOR, VUELVE A INTENTARLO" << WHITE << endl;
		}
		else
		{
			cout << ORANGE << "\nNo existen palabras con esa combinación de letras, por esta vez lo dejamos en empate..." << WHITE << endl;
		}

		do{
			cout << "\n¿Quieres seguir jugando[S/N]? ";
			cin >> jugar;
		}while(jugar != 'N' && jugar != 'n' && jugar != 'S' && jugar != 's');

		if(jugar == 'N' || jugar == 'n')
			seguir_jugando = false;
	}
}