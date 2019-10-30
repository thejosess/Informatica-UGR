#include "bolsa_letras.h"

void operator>>(const conjunto_letras & conjunto, bolsa_letras & bolsa)
{
	for(conjunto_letras::iterator i = conjunto.begin(); i != conjunto.end(); i++)
	{
		for(int j = 0; j < (*i).getVeces(); j++)
			bolsa.bolsa.insert((*i).getCaracter());
	}
}

//por el grupo hablaron de srang o cosas asi raras
int random(int min, int max)
{
	default_random_engine generator( (random_device())() );
	uniform_int_distribution<int> distribution(min,max);
	return distribution(generator);
}

char bolsa_letras::coger_letra()
{
	int numero = random(0, this->size());

	iterator it = this->begin();

	for(int i = 0; i < numero; i++)
		it++;

	char letra = (*it);

	this->bolsa.erase(it);

	return letra;
}

bolsa_letras& bolsa_letras::operator=(const bolsa_letras & original)
{
	for(iterator it = original.begin(); it != original.end(); it++)
	{
		this->bolsa.insert(*it);
	}

	return *this;
}