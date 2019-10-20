/*
	Un vector disperso es un vector en el que la inmensa mayoría de sus 
	elementos son nulos. Para representar este tipo de vectores se suele 
	utilizar como representación una lista:

	template <typename T>
	class vdisperso{
		public:	
			vdisperso(const vector<T> &v);
			void asignar_coeficiente(int i, const T &x);
			vector<T> convertir() const;
		...
		private:
			list< pair<int, T> > coefs;
			int n;
	}

	De esa forma se ahorra una gran cantidad de espacio. Implementa los dos
	métodos indicados en la parte pública.
*/
#include <iostream>
#include <list>
#include <vector>

using namespace std;

template<typename T>
class vdisperso{
public: 
	vdisperso(const vector<T> &v)
	{
		auto wi = v.begin();
		n=0;
		for(wi; wi != v.end(); ++wi, ++n)
			if(*wi!=0)
				coefs.push_back(pair<int,T>(n,*wi));
	}

	void asignar_coeficiente(int i, const T &x)
	{
		auto wi = coefs.begin();
		bool encontrado=false;

		while( !encontrado && wi != coefs.end() ){
				if( wi->first == i){
					wi->second=x;	
					encontrado=true;
					++wi;
				}
				else 
					++wi;
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
					v_convertido.push_back(0);
					++wi;
			}
		}

		return v_convertido;
	}

	void imprime_v_disperso(){
		auto itpar = coefs.begin();
		cout << "Vector disperso: " << endl;
		
		for( itpar; itpar != coefs.end(); ++itpar)
			cout <<" (" << itpar->first << "," << itpar->second <<") ";
	}

private:
	list< pair<int,T> > coefs;
	int n;
};

int main(){
	vector<int>vec, vect;
	int n;

	cout << "Introduzca valores para rellenar el vector: (<0 para acabar)"
		 << endl;
	cin >> n;
	while( n >= 0){
		vec.push_back(n);
		cout << "Introduzca valores para rellenar el vector: (<0 para acabar)" 
			 << endl;		
		cin >> n;
	}


	cout << "Vector con los valores introducidos: " << endl;
	auto wi = vec.begin();

	for(wi; wi != vec.end(); ++wi){
		cout << *wi<< "  ";
	}

	cout << endl << endl ;
	vdisperso <int>v(vec);
	v.imprime_v_disperso();

	cout << endl << endl;

	vect = v.convertir();

	cout << "Convertido: " << endl;
	for( int i = 0 ; i<vect.size() ; ++i)
		cout << vect[i] << " " ;

	cout << endl;
}

