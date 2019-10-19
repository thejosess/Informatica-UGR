#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"

#include <iostream>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <vector>

// Este es el método principal que debe contener los 4 Comportamientos_Jugador
// que se piden en la práctica. Tiene como entrada la información de los
// sensores y devuelve la acción a realizar.
Action ComportamientoJugador::think(Sensores sensores)
{
	// Estoy en el nivel 1

	if (sensores.nivel != 4)
	{
		if (sensores.mensajeF != -1)
		{
			fil = sensores.mensajeF;
			col = sensores.mensajeC;
			ultimaAccion = actIDLE;
		}

		//Actualizar el efecto de la ultima accion
		switch (ultimaAccion)
		{
		case actTURN_R:
			brujula = (brujula + 1) % 4;
			break;
		case actTURN_L:
			brujula = (brujula + 3) % 4;
			break;
		case actFORWARD:
			switch (brujula)
			{
			case 0:
				fil--;
				break; //si quieres subir al norte, restas filas
			case 1:
				col++;
				break;
			case 2:
				fil++;
				break; //si quieres bajar al sur, sumas filas
			case 3:
				col--;
				break;
			}
			break;
		}

		//Mira si ha cambiado el destino
		if(sensores.destinoF != destino.fila or sensores.destinoC != destino.columna)
		{
			destino.fila = sensores.destinoF;
			destino.columna = sensores.destinoC;
			hayPlan = false;
		}

		if(!hayPlan)
		{
			actual.fila = fil;
			actual.columna = col;
			actual.orientacion = brujula;
			hayPlan = pathFinding(sensores.nivel, actual, destino, plan);
		}

		Action sigAccion;
		if (hayPlan && plan.size()>0)
		{
			sigAccion = plan.front();
			plan.erase(plan.begin());
		}
		else
		{
			if(sensores.terreno[2] == 'P' || sensores.terreno[2]=='M' ||
				sensores.terreno[2] == 'D' || sensores.superficie[2] == 'a')
			{
				sigAccion = actTURN_R;
			}
			else
			{
				sigAccion = actFORWARD;
			}
		}
		
		//Recordar la ultima accion
		ultimaAccion = sigAccion;
		return sigAccion;
	}
	else   //NIVEL 2
	{

		if (sensores.mensajeF != -1 && !infoMapa)
		{
			actual.fila = sensores.mensajeF;		
			actual.columna = sensores.mensajeC;
			actual.orientacion = brujula;
			ultimaAccion = actIDLE;
			infoMapa = true;
			hayPlan = false;
		}

		//Mira si ha cambiado el destino
		if(sensores.destinoF != destino.fila or sensores.destinoC != destino.columna)
		{
			destino.fila = sensores.destinoF;
			destino.columna = sensores.destinoC;
			hayPlan = false;
		}

		if(!infoMapa)
		{
			calcularMapaReactivo(sensores, fil, col, mapa_sensores);
		}
		else
		{
			if(primera_vez)
			{
				int valorf = fil-actual.fila;
				int valorc = col-actual.columna;

					//volcar la matriz auxiliar sobre la matriz mapaResultado
					for(int i = valorf; i < 200 ; i++)
					{
						for(int j = valorc; j < 200 ; j++)
						{
							if(mapa_sensores[i][j] != '?')
							{	
								mapaResultado[i-valorf][j-valorc] = mapa_sensores[i][j];
							}
							primera_vez=false;
						}
					}
					fil = sensores.mensajeF;
					col = sensores.mensajeC;
			}
			else
				calcularMapaReactivo(sensores,fil,col,mapaResultado);
		}

		if(!hayPlan && infoMapa)
		{
			actual.fila = fil;
			actual.columna = col;
			actual.orientacion = brujula;
			hayPlan = pathFinding(sensores.nivel, actual, destino, plan);
		}

		Action sigAccion; 
		if (hayPlan && plan.size()>0)
		{
			if(sensores.terreno[2] == 'P' || sensores.terreno[2]=='M' ||
				sensores.terreno[2] == 'D' || sensores.superficie[2] == 'a' && plan.front() == actFORWARD)
			{
				hayPlan = false;
				sigAccion = actTURN_R;
			}
			else
			{
				sigAccion = plan.front();
				plan.erase(plan.begin());
			}
			
		}
		else
		{
			plan.clear();
			int encontrado;
			bool pk = false;

			for(int i = 0 ; i < sensores.terreno.size(); i++)
			{
				if(sensores.terreno[i] == 'K')
				{
					encontrado = i;
					pk = true;
				}
			}

			if(pk)
			{
				if(encontrado == 0)
					infoMapa = true;  //es redundante pero necesario
				else
				{
					cout << "encontrado en "  << encontrado << endl;
					findingPK(encontrado,plan);
					hayPlan =true;
					sigAccion = plan.front();
					plan.erase(plan.begin());

				}
			}

			else
				if(sensores.terreno[2] == 'P' || sensores.terreno[2]=='M' ||
				sensores.terreno[2] == 'D' || sensores.superficie[2] == 'a')
			{
				sigAccion = actTURN_R;
			}
			else
			{
				sigAccion = actFORWARD;
			}
		}
		
		//Recordar la ultima accion
		ultimaAccion = sigAccion;

		//Actualizar el efecto de la ultima accion
		switch (ultimaAccion)
		{
		case actTURN_R:
			brujula = (brujula + 1) % 4;
			break;
		case actTURN_L:
			brujula = (brujula + 3) % 4;
			break;
		case actFORWARD:
			switch (brujula)
			{
			case 0:
				fil--;
				break; //si quieres subir al norte, restas filas
			case 1:
				col++;
				break;
			case 2:
				fil++;
				break; //si quieres bajar al sur, sumas filas
			case 3:
				col--;
				break;
			}
			break;
		}

		return sigAccion;
	}
}

// Llama al algoritmo de busqueda que se usará en cada comportamiento del agente
// Level representa el comportamiento en el que fue iniciado el agente.
bool ComportamientoJugador::pathFinding(int level, const estado &origen, const estado &destino, list<Action> &plan)
{
	switch (level)
	{
	case 1:
		cout << "Busqueda en profundad\n";
		return pathFinding_Profundidad(origen, destino, plan);
		break;
	case 2:
		cout << "Busqueda en Anchura\n";
		return pathFinding_Anchura(origen, destino, plan);
		break;
	case 3:
		cout << "Busqueda Costo Uniforme\n";
		return pathFinding_CostoMinimo(origen, destino,plan);
		break;
	case 4:
		cout << "Busqueda para el reto\n";
		return pathFindingReto(origen, destino, plan);
		break;
	}
	cout << "Comportamiento sin implementar\n";
	return false;
}

//---------------------- Implementación de la busqueda en profundidad ---------------------------

// Dado el código en carácter de una casilla del mapa dice si se puede
// pasar por ella sin riegos de morir o chocar.
bool EsObstaculo(unsigned char casilla)
{
	if (casilla == 'P' or casilla == 'M' or casilla == 'D')
		return true;
	else
		return false;
}

// Comprueba si la casilla que hay delante es un obstaculo. Si es un
// obstaculo devuelve true. Si no es un obstaculo, devuelve false y
// modifica st con la posición de la casilla del avance.
bool ComportamientoJugador::HayObstaculoDelante(estado &st)
{
	int fil = st.fila, col = st.columna;

	// calculo cual es la casilla de delante del agente
	switch (st.orientacion)
	{
	case 0:
		fil--;
		break;
	case 1:
		col++;
		break;
	case 2:
		fil++;
		break;
	case 3:
		col--;
		break;
	}

	// Compruebo que no me salgo fuera del rango del mapa
	if (fil < 0 or fil >= mapaResultado.size())
		return true;
	if (col < 0 or col >= mapaResultado[0].size())
		return true;

	// Miro si en esa casilla hay un obstaculo infranqueable
	if (!EsObstaculo(mapaResultado[fil][col]))
	{
		// No hay obstaculo, actualizo el parámetro st poniendo la casilla de delante.
		st.fila = fil;
		st.columna = col;
		return false;
	}
	else
	{
		return true;
	}
}

struct nodo
{
	estado st;
	list<Action> secuencia;
	int coste;
	float distancia;
};

struct ComparaEstados
{
	bool operator()(const estado &a, const estado &n) const
	{
		if ((a.fila > n.fila) or (a.fila == n.fila and a.columna > n.columna) or
			(a.fila == n.fila and a.columna == n.columna and a.orientacion > n.orientacion))
			return true;
		else
			return false;
	}
};

// Implementación de la búsqueda en profundidad.
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.
bool ComportamientoJugador::pathFinding_Profundidad(const estado &origen, const estado &destino, list<Action> &plan)
{
	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado, ComparaEstados> generados; // Lista de Cerrados
	stack<nodo> pila;					   // Lista de Abiertos

	nodo current;
	current.st = origen;
	current.secuencia.empty();

	pila.push(current);

	while (!pila.empty() and (current.st.fila != destino.fila or current.st.columna != destino.columna))
	{

		pila.pop();
		generados.insert(current.st);

		// Generar descendiente de girar a la derecha
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion + 1) % 4;
		if (generados.find(hijoTurnR.st) == generados.end())
		{
			hijoTurnR.secuencia.push_back(actTURN_R);
			pila.push(hijoTurnR);
		}

		// Generar descendiente de girar a la izquierda
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion + 3) % 4;
		if (generados.find(hijoTurnL.st) == generados.end())
		{
			hijoTurnL.secuencia.push_back(actTURN_L);
			pila.push(hijoTurnL);
		}

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st))
		{
			if (generados.find(hijoForward.st) == generados.end())
			{
				hijoForward.secuencia.push_back(actFORWARD);
				pila.push(hijoForward);
			}
		}

		// Tomo el siguiente valor de la pila
		if (!pila.empty())
		{
			current = pila.top();
		}
	}

	cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna)
	{
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else
	{
		cout << "No encontrado plan\n";
	}

	return false;
}

bool ComportamientoJugador::pathFinding_Anchura(const estado &origen, const estado &destino, list<Action> &plan)
{
	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado, ComparaEstados> generados; // Lista de Cerrados
	queue<nodo> cola;					   // Lista de Abiertos

	nodo current;
	current.st = origen;
	current.secuencia.empty();

	cola.push(current);

	while (!cola.empty() and (current.st.fila != destino.fila or current.st.columna != destino.columna))
	{

		cola.pop();
		generados.insert(current.st);

		// Generar descendiente de girar a la derecha
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion + 1) % 4;
		if (generados.find(hijoTurnR.st) == generados.end())
		{
			hijoTurnR.secuencia.push_back(actTURN_R);
			cola.push(hijoTurnR);
		}

		// Generar descendiente de girar a la izquierda
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion + 3) % 4;
		if (generados.find(hijoTurnL.st) == generados.end())
		{
			hijoTurnL.secuencia.push_back(actTURN_L);
			cola.push(hijoTurnL);
		}

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st))
		{
			if (generados.find(hijoForward.st) == generados.end())
			{
				hijoForward.secuencia.push_back(actFORWARD);
				cola.push(hijoForward);
			}
		}

		// Tomo el siguiente valor de la cola
		if (!cola.empty())
		{
			current = cola.front();
		}
	}

	cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna)
	{
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else
	{
		cout << "No encontrado plan\n";
	}

	return false;
}

struct classcomp 
{
  bool operator() (const nodo& n1, const nodo& n2) const
  {  

    return n1.coste > n2.coste;  //de menor a mayor
  }
};

void funcion_costo(nodo &n, vector< vector< unsigned char> > mapaResultado)
{
	if(mapaResultado[n.st.fila][n.st.columna] == 'T')
		n.coste += 2;
	else
		if(mapaResultado[n.st.fila][n.st.columna] == 'B')
	{
		n.coste += 5;
	}
	else
		if(mapaResultado[n.st.fila][n.st.columna] == 'A')
	{
		n.coste += 10;
	}
	else
		if(mapaResultado[n.st.fila][n.st.columna] == '?')
	{
		n.coste +=1;
	}
	
	else
	{
		n.coste += 1;
	}
}

bool ComportamientoJugador::pathFinding_CostoMinimo(const estado &origen, const estado &destino, list<Action> &plan)
{
	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado, ComparaEstados> generados; // Lista de Cerrados
	priority_queue<nodo,vector<nodo>,classcomp> cola;					   // Lista de Abiertos

	nodo current;
	current.st = origen;
	current.coste = 0;
//	current.secuencia.empty();

	cola.push(current);

	while (!cola.empty() and (current.st.fila != destino.fila or current.st.columna != destino.columna))
	{

		cola.pop();
		if(generados.find(current.st)==generados.end())
		{
			generados.insert(current.st);

			// Generar descendiente de girar a la derecha
			nodo hijoTurnR = current;
			hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion + 1) % 4;
			
			if (generados.find(hijoTurnR.st) == generados.end())
			{
					hijoTurnR.secuencia.push_back(actTURN_R);
					hijoTurnR.coste++;
					cola.push(hijoTurnR);
			}

			// Generar descendiente de girar a la izquierda
			nodo hijoTurnL = current;
			hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion + 3) % 4;
			if (generados.find(hijoTurnL.st) == generados.end())
			{
					hijoTurnL.secuencia.push_back(actTURN_L);
					hijoTurnL.coste++;
					cola.push(hijoTurnL);
			}


			// Generar descendiente de avanzar
			nodo hijoForward = current;
			if (!HayObstaculoDelante(hijoForward.st))
			{
				if (generados.find(hijoForward.st) == generados.end())
				{
						hijoForward.secuencia.push_back(actFORWARD);
						funcion_costo(hijoForward, mapaResultado);
						cola.push(hijoForward);
				}
			}
		}

			// Tomo el siguiente valor de la cola
			if (!cola.empty())
			{
				current = cola.top();
			}
	}

	cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna)
	{
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else
	{
		cout << "No encontrado plan\n";
	}

	return false;
} 

float ComportamientoJugador::distanciaE(const estado& n1, const estado& n2)
{
    float dx = pow (n1.fila - n2.fila,2);
    float dy = pow (n1.columna - n2.columna, 2);

    float sol = (sqrt(dx + dy));

    return sol;
}

struct cmp 
{
  bool operator() (const nodo& n1, const nodo& n2) const
  {  
    return n1.coste + n1.distancia > n2.coste + n2.distancia;  //de menor a mayor
  }
};

bool ComportamientoJugador::pathFindingReto(const estado &origen, const estado &destino, list<Action> &plan)
{
	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado, ComparaEstados> generados; // Lista de Cerrados
	priority_queue<nodo,vector<nodo>,cmp> cola;					   // Lista de Abiertos

	nodo current;
	current.st = origen;
	current.secuencia.empty();
	current.distancia = distanciaE(current.st, destino);

	cola.push(current);

	while (!cola.empty() and (current.st.fila != destino.fila or current.st.columna != destino.columna))
	{

		cola.pop();
		generados.insert(current.st);

		// Generar descendiente de girar a la derecha
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion + 1) % 4;
		if (generados.find(hijoTurnR.st) == generados.end())
		{
			hijoTurnR.secuencia.push_back(actTURN_R);
			hijoTurnR.distancia = distanciaE(hijoTurnR.st, destino);
			cola.push(hijoTurnR);
		}

		// Generar descendiente de girar a la izquierda
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion + 3) % 4;
		if (generados.find(hijoTurnL.st) == generados.end())
		{
			hijoTurnL.secuencia.push_back(actTURN_L);
			hijoTurnL.distancia = distanciaE(hijoTurnL.st, destino);
			cola.push(hijoTurnL);
		}

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st))
		{
			if (generados.find(hijoForward.st) == generados.end())
			{
				hijoForward.secuencia.push_back(actFORWARD);
				hijoForward.distancia = distanciaE(hijoForward.st, destino);
				cola.push(hijoForward);
			}
		}

		// Tomo el siguiente valor de la cola
		if (!cola.empty())
		{
			current = cola.top();
		}
	}

	cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna)
	{
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else
	{
		cout << "No encontrado plan\n";
	}

	return false;
} 

// Sacar por la términal la secuencia del plan obtenido
void ComportamientoJugador::PintaPlan(list<Action> plan)
{
	auto it = plan.begin();
	while (it != plan.end())
	{
		if (*it == actFORWARD)
		{
			cout << "A ";
		}
		else if (*it == actTURN_R)
		{
			cout << "D ";
		}
		else if (*it == actTURN_L)
		{
			cout << "I ";
		}
		else
		{
			cout << "- ";
		}
		it++;
	}
	cout << endl;
}

void AnularMatriz(vector<vector<unsigned char>> &m)
{
	for (int i = 0; i < m[0].size(); i++)
	{
		for (int j = 0; j < m.size(); j++)
		{
			m[i][j] = 0;
		}
	}
}

// Pinta sobre el mapa del juego el plan obtenido
void ComportamientoJugador::VisualizaPlan(const estado &st, const list<Action> &plan)
{
	AnularMatriz(mapaConPlan);
	estado cst = st;

	auto it = plan.begin();
	while (it != plan.end())
	{
		if (*it == actFORWARD)
		{
			switch (cst.orientacion)
			{
			case 0:
				cst.fila--;
				break;
			case 1:
				cst.columna++;
				break;
			case 2:
				cst.fila++;
				break;
			case 3:
				cst.columna--;
				break;
			}
			mapaConPlan[cst.fila][cst.columna] = 1;
		}
		else if (*it == actTURN_R)
		{
			cst.orientacion = (cst.orientacion + 1) % 4;
		}
		else
		{
			cst.orientacion = (cst.orientacion + 3) % 4;
		}
		it++;
	}
}

	void ComportamientoJugador::calcularMapaReactivo(Sensores sensores, int pos_f, int pos_c, vector<vector<unsigned char>> &mapa_sensores)
	{
	switch (brujula){
		case 0: //Norte
			mapa_sensores[pos_f][pos_c]=sensores.terreno[0];
			mapa_sensores[pos_f-1][pos_c-1]=sensores.terreno[1];
			mapa_sensores[pos_f-1][pos_c]=sensores.terreno[2];
			mapa_sensores[pos_f-1][pos_c+1]=sensores.terreno[3];
			mapa_sensores[pos_f-2][pos_c-2]=sensores.terreno[4];
			mapa_sensores[pos_f-2][pos_c-1]=sensores.terreno[5];
			mapa_sensores[pos_f-2][pos_c]=sensores.terreno[6];
			mapa_sensores[pos_f-2][pos_c+1]=sensores.terreno[7];
			mapa_sensores[pos_f-2][pos_c+2]=sensores.terreno[8];
			mapa_sensores[pos_f-3][pos_c-3]=sensores.terreno[9];
			mapa_sensores[pos_f-3][pos_c-2]=sensores.terreno[10];
			mapa_sensores[pos_f-3][pos_c-1]=sensores.terreno[11];
			mapa_sensores[pos_f-3][pos_c]=sensores.terreno[12];
			mapa_sensores[pos_f-3][pos_c+1]=sensores.terreno[13];
			mapa_sensores[pos_f-3][pos_c+2]=sensores.terreno[14];
			mapa_sensores[pos_f-3][pos_c+3]=sensores.terreno[15];
				break;

		case 1: //Este
			mapa_sensores[pos_f][pos_c]=sensores.terreno[0];
			mapa_sensores[pos_f-1][pos_c+1]=sensores.terreno[1];
			mapa_sensores[pos_f][pos_c+1]=sensores.terreno[2];
			mapa_sensores[pos_f+1][pos_c+1]=sensores.terreno[3];
			mapa_sensores[pos_f-2][pos_c+2]=sensores.terreno[4];
			mapa_sensores[pos_f-1][pos_c+2]=sensores.terreno[5];
			mapa_sensores[pos_f][pos_c+2]=sensores.terreno[6];
			mapa_sensores[pos_f+1][pos_c+2]=sensores.terreno[7];
			mapa_sensores[pos_f+2][pos_c+2]=sensores.terreno[8];
			mapa_sensores[pos_f-3][pos_c+3]=sensores.terreno[9];
			mapa_sensores[pos_f-2][pos_c+3]=sensores.terreno[10];
			mapa_sensores[pos_f-1][pos_c+3]=sensores.terreno[11];
			mapa_sensores[pos_f][pos_c+3]=sensores.terreno[12];
			mapa_sensores[pos_f+1][pos_c+3]=sensores.terreno[13];
			mapa_sensores[pos_f+2][pos_c+3]=sensores.terreno[14];
			mapa_sensores[pos_f+3][pos_c+3]=sensores.terreno[15];
				break;

		case 2: //Sur
			mapa_sensores[pos_f][pos_c]=sensores.terreno[0];
			mapa_sensores[pos_f+1][pos_c+1]=sensores.terreno[1];
			mapa_sensores[pos_f+1][pos_c]=sensores.terreno[2];
			mapa_sensores[pos_f+1][pos_c-1]=sensores.terreno[3];
			mapa_sensores[pos_f+2][pos_c+2]=sensores.terreno[4];
			mapa_sensores[pos_f+2][pos_c+1]=sensores.terreno[5];
			mapa_sensores[pos_f+2][pos_c]=sensores.terreno[6];
			mapa_sensores[pos_f+2][pos_c-1]=sensores.terreno[7];
			mapa_sensores[pos_f+2][pos_c-2]=sensores.terreno[8];
			mapa_sensores[pos_f+3][pos_c+3]=sensores.terreno[9];
			mapa_sensores[pos_f+3][pos_c+2]=sensores.terreno[10];
			mapa_sensores[pos_f+3][pos_c+1]=sensores.terreno[11];
			mapa_sensores[pos_f+3][pos_c]=sensores.terreno[12];
			mapa_sensores[pos_f+3][pos_c-1]=sensores.terreno[13];
			mapa_sensores[pos_f+3][pos_c-2]=sensores.terreno[14];
			mapa_sensores[pos_f+3][pos_c-3]=sensores.terreno[15];
				break;

		case 3: //Oeste
			mapa_sensores[pos_f][pos_c]=sensores.terreno[0];
			mapa_sensores[pos_f+1][pos_c-1]=sensores.terreno[1];
			mapa_sensores[pos_f][pos_c-1]=sensores.terreno[2];
			mapa_sensores[pos_f-1][pos_c-1]=sensores.terreno[3];
			mapa_sensores[pos_f+2][pos_c-2]=sensores.terreno[4];
			mapa_sensores[pos_f+1][pos_c-2]=sensores.terreno[5];
			mapa_sensores[pos_f][pos_c-2]=sensores.terreno[6];
			mapa_sensores[pos_f-1][pos_c-2]=sensores.terreno[7];
			mapa_sensores[pos_f-2][pos_c-2]=sensores.terreno[8];
			mapa_sensores[pos_f+3][pos_c-3]=sensores.terreno[9];
			mapa_sensores[pos_f+2][pos_c-3]=sensores.terreno[10];
			mapa_sensores[pos_f+1][pos_c-3]=sensores.terreno[11];
			mapa_sensores[pos_f][pos_c-3]=sensores.terreno[12];
			mapa_sensores[pos_f-1][pos_c-3]=sensores.terreno[13];
			mapa_sensores[pos_f-2][pos_c-3]=sensores.terreno[14];
			mapa_sensores[pos_f-3][pos_c-3]=sensores.terreno[15];
				break;
		}
	}

void ComportamientoJugador::findingPK(int posicion, list<Action> &plan)
{
	nodo sol;
	switch(posicion)
	{
		case 1:
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actTURN_L);
		break;

		case 2:
			sol.secuencia.push_back(actFORWARD);
		break;

		case 3:
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actTURN_R);
		break;

		case 4:
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actTURN_L);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
		break;

		case 5:
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actTURN_L);
			sol.secuencia.push_back(actFORWARD);
		break;

		case 6:
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
		break;

		case 7:
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actTURN_R);
			sol.secuencia.push_back(actFORWARD);
		break;

		case 8:
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actTURN_R);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
		break;

		case 9:
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actTURN_L);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
		break;

		case 10:
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actTURN_L);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
		break;

		case 11:
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actTURN_L);
			sol.secuencia.push_back(actFORWARD);
		break;

		case 12:
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
		break;

		case 13:
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actTURN_R);
			sol.secuencia.push_back(actFORWARD);
		break;

		case 14:
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actTURN_R);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
		break;

		case 15:
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actTURN_R);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
			sol.secuencia.push_back(actFORWARD);
		break;
	}

	plan = sol.secuencia;
}



int ComportamientoJugador::interact(Action accion, int valor)
{
	return false;
}
