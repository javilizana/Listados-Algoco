#include <iostream>
#include <vector>
#include <algorithm> // Para usar std::max y std::min

using namespace std;

int main() {
    // 1. Optimización de entrada/salida (I/O). 
    // En programación competitiva, cin/cout pueden ser lentos. 
    // Estas dos líneas aceleran la lectura, evitando el "Time Limit Exceeded".
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // Leemos el número de rondas (equivalente a N = int(input()) en Python)
    if (!(cin >> N)) return 0;

    // 2. Arreglos de frecuencias.
    // Equivalente en Python a: countA = [0] * 101
    // Usamos tamaño 101 porque los números van del 1 al 100, así el índice coincide con el número.
    vector<int> countA(101, 0);
    vector<int> countB(101, 0);

    // Bucle para cada ronda (equivalente a: for ronda in range(N):)
    for (int ronda = 0; ronda < N; ronda++) {
        int a, b;
        cin >> a >> b; // Leemos los dos números de la ronda actual

        // Registramos que tenemos un ejemplar más de estos números
        countA[a]++;
        countB[b]++;

        // 3. Copias temporales.
        // A diferencia de Python, donde "tempA = countA" solo copia la referencia,
        // en C++ al asignar un vector a otro se hace una copia profunda automática (como countA.copy()).
        vector<int> tempA = countA;
        vector<int> tempB = countB;

        int max_sum = 0;
        int i = 1;   // Puntero 'i' busca el número más pequeño disponible en A (avanza hacia adelante)
        int j = 100; // Puntero 'j' busca el número más grande disponible en B (retrocede hacia atrás)

        // Bucle de dos punteros
        while (i <= 100 && j >= 1) {
            // Si ya no nos quedan copias del número 'i' en A, avanzamos al siguiente número
            if (tempA[i] == 0) {
                i++;
                continue;
            }
            // Si ya no nos quedan copias del número 'j' en B, retrocedemos al número anterior
            if (tempB[j] == 0) {
                j--;
                continue;
            }

            // Si llegamos a esta línea, significa que tenemos números disponibles tanto en 'i' como en 'j'.
            // Vemos cuántas parejas podemos formar simultáneamente.
            int parejas = min(tempA[i], tempB[j]);
            
            // Calculamos la suma de esta pareja y vemos si es la máxima que hemos encontrado en esta ronda
            max_sum = max(max_sum, i + j);

            // Restamos las parejas formadas de nuestros contadores temporales
            tempA[i] -= parejas;
            tempB[j] -= parejas;
        }

        // 4. Imprimimos el resultado de la ronda
        // Usamos "\n" en lugar de endl porque es más rápido para imprimir muchas líneas
        cout << max_sum << "\n";
    }

    return 0;
}