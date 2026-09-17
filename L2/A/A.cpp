#include <iostream>

using namespace std;

int main(){
    int P;
    cin >> P;

    for (int i = 0; i < P; i++){ //para cada caso de prueba
        int K;
        cin >> K;
        int estaturas [20];
        for (int j = 0; j < 20; j++){ //llenamos el arreglo con los 20 niños
            cin >> estaturas[j];
        }

        int pasos = 0;
        for (int n = 1; n < 20; n++){
            int actual = estaturas[n]; //guardamos la estatura del estudiante actual
            int pos = n-1;
            while (pos >= 0 && estaturas[pos] > actual){
                estaturas[pos + 1] = estaturas[pos];
                pasos += 1;
                pos--;
            }
            estaturas[pos + 1] = actual; 

        }

        cout << K << " " << pasos << endl;
    }
}