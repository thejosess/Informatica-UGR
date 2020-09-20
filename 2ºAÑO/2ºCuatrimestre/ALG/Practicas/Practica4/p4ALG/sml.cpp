#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;


string sml(const string &x, const string &y){
    string sub;
    int cont=0;
    vector<vector <int>> m ;
    vector<int>aux;

    string x2 = "x" + x;
    string y2 = "y" + y;

    for(int i=0;i<y2.size();i++){
        aux.push_back(0);
    }
    for(int i=0;i<x2.size();i++){
        m.push_back(aux);
    }


    for(int i=1; i< x2.size(); i++){
        for(int j=1; j< y2.size(); j++){
            if(x2[i]==y2[j]){
                m[i][j] = 1 + m[i-1][j-1];
            }else{
                m[i][j]=fmax(m[i-1][j],m[i][j-1]);
            }
        }
    }
    cont = m[x2.size()-1][y2.size()-1];
    sub.resize(cont);
    int i = x2.size()-1, j = y2.size()-1;
    while (cont != 0) {
        if(x2[i] == y2[j])
        {
            cont--;
            sub[cont] = x2[i];
            i--; j--;
        }
        else
        {
            if(m[i-1][j] > m[i][j-1])
                i--;
            else
                j--;
        }
    }

    return sub;
}

int main(){
    string x = "gacggattag";
    string y = "gatcggaatag";

    string sol = sml(x,y);

    cout << "La subsecuencia más larga tiene " << sol.size() << " caracteres y es: " << sol << endl;

    return 0;
}
