#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main(){
    vector<string> palabras; //guardará las combinaciones
    string palabra; //guardara el input

    while( cin >> palabra){
        palabras.push_back(palabra); //guarda el input en la lista (vector)
    }

    set<string> pal_comp; //guarda las palabras compuestas en un set

    for(int i = 0; i < palabras.size(); i++){
        for (int j = 0; j < palabras.size(); j++){
            if (i != j){ //se concatenan palabras DIFERENTES
                pal_comp.insert(palabras[i] + palabras[j]); //se concatenan
            }
        }
    }

    for (const string&pc : pal_comp){
        /*
        Para cada variable de texto (pc) dentro de nuestro conjunto (pal_comp), 
        mírala directamente en la memoria para no gastar recursos (const string&) y 
        ejecuta el código que sigue
        */
        cout << pc << "\n";
    }
    return 0;
}