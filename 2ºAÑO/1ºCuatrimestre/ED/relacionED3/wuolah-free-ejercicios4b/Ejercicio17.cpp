/*
	Dada la representación vector<list<T> > TH de un tipo de dato hash_table<T>. 
	Diseña una representación del iterador e implementa las operaciones:
	  hash_table<T>::iterator::operator--(), tabla_hash<T>::begin() y
	  hash_table<T>::end().
*/

//Representación del iterador a partir de hash_table
class hash_table{
public:
	class iterator;
	iterator begin();
	iterator end();

private:
	vector<list<T> >v;
	friend class iterator;

	class iterator{
	private: 
		friend class hash_table;
		vector<list<T> >::iterator it;
		list<T>::iterator it_lista;
	public:
		iterator();
		T & operator*();
		iterator & operator++();
		iterator & operator--();
		bool operator==(const iterator & iter);
		bool operator!=( const iterator & iter);		
	};

};

//Implemetación de begin() y end()
hash_table::iterator hash_table<T>::begin(){
	hash_table::iterator iter;
	iter.it = v.begin(); 
	iter.it_lista = (*iter).begin();  
}

hash_table::iterator hash_table<T>::end(){
	hash_table::iterator iter;
	iter.it = v.begin(); 	
	iter.it_lista = (*iter).begin(); 
}

//Implementación del operator --()
template<typename T>
hash_table::iterator &  hash_table::iterator::operator--(){

	if( it_lista != *it.begin() )
		it_lista--;	

	else{	
		//PRE: No estamos en la primera posición del vector
		it--;
		it_lista == *it.end();
		it_lista--; 
	}
}
