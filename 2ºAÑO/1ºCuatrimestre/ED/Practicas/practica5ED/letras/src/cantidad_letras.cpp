#include <lista_palabras.h>
#include <fstream>
#include <clocale>

#define RED "\033[31m"

bool salida(char* salida, const map<char,int> & mapita, int total)
{
	ofstream f_salida (salida);
	if (!f_salida)
	{
		cerr << RED << "ERROR ABRIENDO FICHERO DE SALIDA: " << salida << endl;
		return false;
	}

	f_salida << "#Letra\tCantidad\n";

	for(map<char,int>::const_iterator it = mapita.begin(); it != mapita.end(); it++)
	{
		f_salida << it->first << '\t' << (double) (it->second * 100) / total << endl;
	}

	f_salida.close();

	return true;
}

int main(int argc, char** argv)
{
	if(argc != 4)
	{
		cerr << RED << "\nSINTAXIS INCORRECTA" << endl
			<< "Los parámetros de entrada son los siguientes:\n" <<
				"\t1. El nombre del fichero con lista_palabras\n" <<
				"\t2. El nombre del fichero con las letras\n" <<
				"\t3. El fichero donde escribir el conjunto de letras con la cantidad de apariciones calculada\n";

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

	lista_palabras lista;
	conjunto_letras conjunto;

	f_lista >> lista; 
	f_letras >> conjunto;

	f_lista.close();
	f_letras.close();

	int total = 0;

	map<char,int> mapita = lista.contar_char(conjunto, total);

	salida(argv[3], mapita, total);
}