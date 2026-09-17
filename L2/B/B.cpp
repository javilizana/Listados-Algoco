#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//funcion comparadora que solo evalúa los primeros dos caracteres
bool comparar_nombres(const string& a, const string& b){
    //extraemos 2 letras de a y 2 de b
    string inicio_a = a.substr(0, 2);
    string inicio_b = b.substr(0, 2);
    
    //si inicio_a es menor alfabeticamente de inicio_b => true (significa que 'a' va primero)
    return inicio_a < inicio_b;  
}

int main(){
    int n;
    bool primera_vez = true;
    
    while(cin >> n && n != 0){
        
        if (!primera_vez){ //imprime un espacio en blanco solo si NO es el primer caso
            cout << endl; 
        }
        primera_vez = false;

        vector<string> nombres;

        for(int i = 0; i < n; i++){ //metemos todos los nombres a la lista (desordenados)
            string nombre_temporal;
            cin >> nombre_temporal; //leemos un nombre
            nombres.push_back(nombre_temporal); //lo agregamos al final de la lista

        }

        //se usa el stable sort para mantener el orden de entrada en caso de empate
        stable_sort(nombres.begin(), nombres.end(), comparar_nombres);

        for(int i = 0; i < n; i++){
            cout << nombres[i] << endl;
        }

    }

    return 0;
}