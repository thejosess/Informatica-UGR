/*
      Este programa que obtiene la media de un vector con 10 elementos
*/

#include <iostream>
using namespace std;

int main(){
    const int MAX = 10;
    int v[MAX];
    double media;

    for (int i=0; i<MAX; i++){
        cout << "Introducir dato : ";
        cin >> v[i];
    }

    media = 0;
    for (int i=0; i<MAX; i++){
        media = media + v[i];
    }

    media = media / MAX;

    cout << "\nMedia = " << media << endl;
}
