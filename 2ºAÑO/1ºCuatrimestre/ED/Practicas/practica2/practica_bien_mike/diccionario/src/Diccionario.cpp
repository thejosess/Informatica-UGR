#include "Diccionario.h"
#include <cstdlib>

/*********************************************************************************/
//Constructores

Diccionario::Diccionario(){}

Diccionario::Diccionario(Termino termino){
	terminos.resize(1);
	terminos[0] = termino;
}

Diccionario::Diccionario(Vector_Dinamico<Termino> terminos){
	this->terminos = terminos;
}

Diccionario::Diccionario(const Diccionario & original){
	this->terminos = original.terminos;
}

/********************************************************************************/
//Consultores

Vector_Dinamico<string> Diccionario::getDefinicionesTermino(string palabra){
	int posicionTermino = buscarTermino(palabra);
		
	if(posicionTermino == -1){
		cout << "ERROR: El término introducido (" << palabra << ") no se encuentra en el diccionario." << endl;
		cout << "Saliendo del programa..." << endl;
		exit(0);
	}
	return terminos[posicionTermino].getDefiniciones();
}


Vector_Dinamico<Termino> Diccionario::getVectorTerminos() const{
	return terminos;
}


int Diccionario::getNumeroTerminos() const{
	return terminos.size();
}

/*********************************************************************************/
//Metodos Interfaz

void Diccionario::setTerminos(Vector_Dinamico<Termino> nuevosTerminos){
	terminos = nuevosTerminos;
}

void Diccionario::addTermino(Termino nuevoTermino){
	bool encontrado = false;
	int posicion = -1;

	for(int i=0; i<terminos.size() && !encontrado; i++){
		if(terminos[i].getPalabra() == nuevoTermino.getPalabra()){
			encontrado = true;
			posicion = i;
			terminos[i].addDefinicion(nuevoTermino.getDefiniciones()[0]);
		}
	}
	if(posicion == -1){
		terminos.resize(getNumeroTerminos()+1);
		terminos[getNumeroTerminos()-1] = nuevoTermino;
	}
}

void Diccionario::deleteTermino(const Termino& termino){
	int posicionTermino = -1;
	for(int i=0; i<getNumeroTerminos(); i++)
		if(getVectorTerminos()[i].getPalabra() == termino.getPalabra())
			posicionTermino = i;
	for(int i=posicionTermino; i<getNumeroTerminos(); i++)
		getVectorTerminos()[i] = getVectorTerminos()[i+1];
	getVectorTerminos().resize(getNumeroTerminos()-1);	
}

/*********************************************************************************/
//Otros Metodos

int Diccionario::buscarTermino(string palabra){
	int min=0, max=getNumeroTerminos(), centro, posTermino=-1;
	while(min <= max && posTermino==-1){
		centro=(min+max)/2;
		if(getVectorTerminos()[centro].getPalabra().compare(palabra)==0){
			posTermino=centro;
		}
		else if(getVectorTerminos()[centro].getPalabra().compare(palabra)>0)
			max=centro-1;
		else
			min=centro+1;
	}
	
	return posTermino;
}

int Diccionario::buscarPrimerTerminoCaracter(char caracter){
	int min=0, max=getNumeroTerminos(), centro, posTermino=-1;
	while(min <= max && posTermino==-1){
		centro=(min+max)/2;
		if((terminos[centro].getPalabra()[0]==caracter &&
		   centro == 0) ||
		   (terminos[centro].getPalabra()[0]==caracter &&
		   terminos[centro-1].getPalabra()[0]!=caracter)){
			posTermino=centro;
		}
		else if(terminos[centro].getPalabra()[0]>caracter || 
			terminos[centro].getPalabra()[0]==caracter)
			max=centro-1;
		else
			min=centro+1;
	}
	
	return posTermino;
}

Diccionario Diccionario::filtrarPorIntervalo(char caracter_inicio, char caracter_fin){
	assert (caracter_inicio < caracter_fin);	
	Diccionario nuevoDiccionario;
	int posInicio=buscarPrimerTerminoCaracter(caracter_inicio);
	
	for(int i=posInicio; getVectorTerminos()[i].getPalabra()[0] <= caracter_fin; i++)
			nuevoDiccionario.addTermino(getVectorTerminos()[i]);

	return nuevoDiccionario;
}

Diccionario Diccionario::filtrarPalabraClave(string palabra_clave){
	Diccionario nuevoDiccionario;
	bool encontradoTermino;
	
	for(int i=0; i<this->getNumeroTerminos(); i++){
		Termino nuevoTermino;
		encontradoTermino = false;
		for(int j=0; j<this->getVectorTerminos()[i].getNumeroDefiniciones(); j++)
			if(this->getVectorTerminos()[i].getDefiniciones()[j].find(palabra_clave) != string::npos){
				nuevoTermino.addDefinicion(this->getVectorTerminos()[i].getDefiniciones()[j]);
				encontradoTermino = true;
			}
		if(encontradoTermino){
			nuevoTermino.setPalabra(this->getVectorTerminos()[i].getPalabra());
			nuevoDiccionario.addTermino(nuevoTermino);
		}
	}
	return nuevoDiccionario;
	
}

void Diccionario::recuentoDefiniciones(){
	int numeroTotalDefiniciones = 0, numeroMaximoDefiniciones = 0, numeroPromedio = 0;
	string palabraMasDefiniciones;

	for(int i=0; i<getNumeroTerminos(); i++){
		numeroTotalDefiniciones += getVectorTerminos()[i].getNumeroDefiniciones();
		if(numeroMaximoDefiniciones < getVectorTerminos()[i].getNumeroDefiniciones()){
			palabraMasDefiniciones = getVectorTerminos()[i].getPalabra();
			numeroMaximoDefiniciones = getVectorTerminos()[i].getNumeroDefiniciones();
		}			
	}

	numeroPromedio = numeroTotalDefiniciones / getNumeroTerminos();

	cout << "Recuento de definiciones: " << endl;
	cout << "\tEl numero total de definiciones es: " << numeroTotalDefiniciones << endl;
	cout << "\tEl numero maximo de definiciones asociadas a una palabra es: " << numeroMaximoDefiniciones << " y dicha palabra es \"" << palabraMasDefiniciones << "\"" << endl;
	cout << "\tEl promedio de definiciones por palabra es: " << numeroPromedio << endl;
}

/*********************************************************************************/
//Metodos Flujos

ostream& operator<<(ostream& os, const Diccionario& diccionario){
	for(int i=0; i<diccionario.getNumeroTerminos(); i++)	
		os << diccionario.getVectorTerminos()[i] << endl;
	return os;
}

istream& operator>>(istream& is, Diccionario& diccionario){
	do{
			Termino termino;

			is >> termino;
			if(!is.eof())
				diccionario.addTermino(termino);

			
	}while(!is.eof());
	
	return (is);
}
