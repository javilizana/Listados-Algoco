#include <iostream>
#include <set> // Importamos la herramienta para usar conjuntos

using namespace std;

int main(){
    int N, Y; //N: total obstaculos | Y: mario anotó 
    cin >> N >> Y;

    set<int> M_encontrados;

    // Leemos los Y números que anotó Mario
    for (int i = 0; i < Y; i++){
        int obstaculo;
        cin >> obstaculo;

        M_encontrados.insert(obstaculo); //// Lo añadimos al conjunto
    }

    // Revisamos todos los obstáculos del 0 al N-1
    for (int i = 0; i < N; i++){

        if (M_encontrados.find(i) == M_encontrados.end()){
            cout << i << endl;
        }
    }
    cout << "Mario got " << M_encontrados.size() << " of the dangerous obstacles.\n";
    return 0;
}