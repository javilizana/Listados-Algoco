#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main(){
    int N, H;
    cin >> N >> H;

    //guardamos memoria para los obstaculos del techo y del suelo
    vector<int> suelo(N/2);
    vector<int> techo(N/2);

    //Recorremos hasta N/2 pero en cada vuelta guardamos dos datos, asiq en realidad 
    //estamos leyendo la cueva completa
    for (int i = 0; i < N/2; i++){
        cin >> suelo[i] >> techo[i];
    }

    //ordenamos los vectores
    sort(suelo.begin(), suelo.end());
    sort(techo.begin(), techo.end());

    int cant_niveles = 0;
    int min_obstaculos = N +1;

    //h: altura de vuelo o altura del nivel
    for (int h = 1; h <= H; h++){

        //suelo con tamaño >= h:
        int choques_suelo = suelo.end() - lower_bound(suelo.begin(), suelo.end(), h);

        //techo con tamaño >= H - h + 1
        int choques_techo = techo.end() - lower_bound(techo.begin(), techo.end(), H - h + 1);

        int total_choques = choques_suelo + choques_techo;

        if(total_choques < min_obstaculos){
            min_obstaculos = total_choques;
            cant_niveles = 1;
        } else if (total_choques == min_obstaculos){
            cant_niveles += 1;
        }
    }

    cout << min_obstaculos << " " << cant_niveles << "\n";

    return 0;

}