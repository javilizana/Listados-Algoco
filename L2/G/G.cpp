#include <iostream>  // Para leer (cin) y escribir (cout)
#include <vector>    // Para usar vectores (equivalente a las listas de Python)
#include <algorithm> // Para usar sort() y lower_bound()

using namespace std;

int main() {
    // Optimización para que la lectura de muchos datos (100.000 líneas) sea rápida
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 1. Leer n (cantidad de tarros) y m (cantidad de colores)
    int n, m;
    cin >> n >> m;

    // En Python: tarros = [0] * n
    // Usamos 'long long' (entero de 64 bits) para evitar problemas con números grandes
    vector<long long> tarros(n);

    // 2. Leer los tamaños de los n tarros disponibles
    for (int i = 0; i < n; i++) {
        cin >> tarros[i];
    }

    // 3. Ordenar la lista de menor a mayor
    // En Python: tarros.sort()
    sort(tarros.begin(), tarros.end());

    // Variable para acumular la respuesta (en Python: desperdicio_total = 0)
    long long desperdicio_total = 0;

    // 4. Procesar cada uno de los m colores que necesita Joe
    for (int i = 0; i < m; i++) {
        long long necesidad;
        cin >> necesidad;

        // Búsqueda binaria: busca el primer elemento >= necesidad
        // lower_bound devuelve un "puntero/iterador" a la posición encontrada.
        // Al poner un asterisco (*) al principio, extraemos el valor guardado ahí.
        long long tarro_elegido = *lower_bound(tarros.begin(), tarros.end(), necesidad);

        // Sumamos lo que sobra de pintura
        desperdicio_total += (tarro_elegido - necesidad);
    }

    // 5. Imprimir el resultado final seguido de un salto de línea ('\n')
    cout << desperdicio_total << "\n";

    return 0;
}