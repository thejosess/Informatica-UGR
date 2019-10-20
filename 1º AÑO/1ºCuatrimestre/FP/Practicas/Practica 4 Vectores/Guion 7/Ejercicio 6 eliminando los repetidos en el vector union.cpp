#include <iostream>
using namespace std;

void Union(char vec1[], int tamVec1, char vec2[], int tamVec2, char vecUnion[], int &tamVecUnion)
{
	bool esta;
	
	for(int i=0; i<tamVec1; i++)
		vecUnion[tamVecUnion++]= vec1[i];
		
	for(int i=0; i<tamVec2; i++)
	{
		esta= false;
		
		for(int j=0; j<tamVecUnion and !esta; j++)
			if(vec2[i]==vecUnion[j])
				esta= true;
				
		if(!esta)
			vecUnion[tamVecUnion++]= vec2[i];
	}
}

void Interseccion(char vec1[], int tamVec1, char vec2[], int tamVec2, char vecInter[], int &tamVecInter)
{	
	for(int i=0; i<tamVec1; i++)
	{
		for(int j=0; j<tamVec2; j++)
			if(vec1[i]==vec2[j])
				vecInter[tamVecInter++]= vec1[i];
	}
}

int main()
{
	const int MAX= 1000;
	char v1[MAX], v2[MAX], unionV[MAX], interseccionV[MAX];
	int tam1, tam2, tamUnion= 0, tamInter= 0;
	
	do
	{
		cout << "Tamaño del vector 1: ";
		cin >> tam1;
	} while(tam1<=0);
	
	cout << endl;
	for(int i=0; i<tam1; i++)
	{
		cout << "v1[" << i << "]= ";
		cin >> v1[i];
	}	
	cout << endl;	

	do
	{
		cout << "Tamaño del vector 2: ";
		cin >> tam2;
	} while(tam2<=0);
	
	cout << endl;
	for(int i=0; i<tam2; i++)
	{
		cout << "v2[" << i << "]= ";
		cin >> v2[i];
	}		
	
	Union(v1, tam1, v2, tam2, unionV, tamUnion);
	Interseccion(v1, tam1, v2, tam2, interseccionV, tamInter);
	
	cout << "\nUnion: ";
	for(int i=0; i<tamUnion; i++)
		cout << unionV[i] << " ";
		
	cout << "\nInterseccion: ";
	for(int i=0; i<tamUnion; i++)
		cout << interseccionV[i] << " ";		
}
