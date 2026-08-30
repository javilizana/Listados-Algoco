#include <iostream>
#include <vector>
#include <unordered_map> //librería para los diccionarios {}

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, b; //n: numeros de la secuencia | b: objetivo de mediana
    if (!(cin >> n >> b)) return 0;

    vector<int> a(n); //Creamos una lista llamada a de tamaño n.
    int pos_b = -1; //para recordar la pos del objetivo

    for (int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == b){
            pos_b = i; //si encontramos a b, guardamos su pos
        }
    }

    unordered_map<int, long long> sum_izq; //"diccionario"
    int sum_actual = 0;

    //Contamos hacia la izquierda desde la posición de B
    sum_izq[0] = 1; // El caso base: no tomar nada a la izquierda suma 0

    for(int i = pos_b - 1; i>=0; i--){
        if(a[i] > b){
            sum_actual +=1;
        } else {
            sum_actual -=1;
        }
        sum_izq[sum_actual]++;
    }

    long long total_secuencias = 0;
    sum_actual = 0;

    total_secuencias += sum_izq[0]; //sumamos las combinaciones solo con el lado izquierdo (lado derecho vacío)

    //Contamos hacia la derecha
    for(int i = pos_b + 1; i < n; i++){
        if(a[i] > b){
            sum_actual +=1;
        } else {
            sum_actual -=1;
        }

        /*
        Si en el lado derecho llevamos una suma de, por ejemplo, +2, 
        necesitamos que el izquierdo tenga un -2 para que la suma total se 
        neutralice a 0. Buscamos ese -2 (el opuesto) en nuestro diccionario y 
        sumamos la cantidad de veces que apareció.
        */
        total_secuencias += sum_izq[-sum_actual];
    }
    //imprimimos
    cout << total_secuencias << "\n";
    return 0;
}