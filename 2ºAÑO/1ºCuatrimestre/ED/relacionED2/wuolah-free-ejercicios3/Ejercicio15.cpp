/*
	Una variante del vector disperso es aquella en la que se puede definir cual
	es el valor nulo. Modifica la clase anterior de forma que se pueda definir
	cual es el valor nulo al crear un objeto. Implementa también 
	cambiar_nulo(const T &n)
*/
#include <iostream>
#include <list>
#include <vector>

using namespace std;

template<typename T>
class vdisperso{
public: 

	vdisperso(const vector<T> &v, T vNulo)
	{
		valorNulo=vNulo;
		auto wi = v.begin();
		n=0;
		for(wi; wi != v.end(); ++wi, ++n)
			if(*wi != valorNulo)
				coefs.push_back(pair<int,T>(n,*wi));
	}

	void asignar_coeficiente(int i, const T &x)
	{
		auto itpar=coefs.begin();
		bool encontrado=false;

		while( !encontrado && itpar!=coefs.end() ){
				if( itpar->first == i){
					itpar->second=x;	
					encontrado=true;
					++itpar;	
				}
				else 
					++itpar;
		}

		if(!encontrado)
			coefs.push_back(pair<int,T>(i,x));
	}

	vector<T> convertir()const
	{
		vector<T>v_convertido;
		v_convertido.reserve(n);
		auto wi = v_convertido.begin();
		int pos=0;

		auto itpar=coefs.begin();
		for( int i=0; i<n ;i++){
			if (itpar->first==i){
				v_convertido.push_back(itpar->second);
				++itpar;
		
			}
			else {
					v_convertido.push_back(valorNulo);
					++wi;
			}
		}
		return v_convertido;
	}

	void imprime_v_disperso()
	{
		auto itpar = coefs.begin();
		cout << "Vector disperso: " << endl;
		
		for( itpar; itpar!= coefs.end() ; ++itpar)
			cout <<" (" << itpar->first << "," << itpar->second <<") ";
	}

private:
	list< pair<int,T> > coefs;
	int n;
	T valorNulo;

};



int main(){
	vector<int>vec, vect;
	int n;
	int vNulo;

	cout << "Introduzca el valor que quiere como nulo: " << endl;
	cin >> vNulo;

	cout << "Introduzca valores para rellenar el vector: (<0 para acabar)" 
		 << endl;
	cin >> n;
	while( n>=0){
		vec.push_back(n);
		cout << "Introduzca valores para rellenar el vector: (<0 para acabar)" 
			 << endl;		
		cin >> n;
	}


	cout << "Vector con los valores introducidos " << endl;
	auto wi = vec.begin();

	for(wi; wi != vec.end(); ++wi){
		cout << *wi << "  ";
	}

	cout << endl << endl ;
	vdisperso <int>v(vec,vNulo);
	v.imprime_v_disperso();

	cout << endl << endl;
	vect=v.convertir();

	cout << "Convertido: " << endl;
	for( int i = 0 ; i<vect.size() ; i++)
		cout << vect[i] << " " ;

	cout << endl << endl;

}
