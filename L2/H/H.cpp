#include <iostream>
#include <vector>
#include <algorithm> // Necesario para sort() y lower_bound()

using namespace std;

int main() {
    // Optimización opcional para que cin/cout sea rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    bool primer_caso = true;

    // En Python: while True: n = int(input()); if n == 0: break
    // Lee 'n' continuamente hasta que n sea 0
    while (cin >> n && n != 0) {
        
        // El problema pide una línea en blanco entre cada caso de prueba
        if (!primer_caso) {
            cout << "\n";
        }
        primer_caso = false;

        // Creamos las dos listas de tamaño n
        vector<int> lista1(n);
        vector<int> lista2(n);

        // Leemos los primeros n números (Lista 1)
        for (int i = 0; i < n; i++) {
            cin >> lista1[i];
        }

        // Leemos los siguientes n números (Lista 2)
        for (int i = 0; i < n; i++) {
            cin >> lista2[i];
        }

        // Hacemos una copia de la lista 1 para poder ordenarla sin perder el orden original
        vector<int> lista1_ordenada = lista1;

        // Ordenamos de menor a mayor la copia de la lista 1 y la lista 2
        sort(lista1_ordenada.begin(), lista1_ordenada.end());
        sort(lista2.begin(), lista2.end());

        // Recorremos la lista 1 original para ir imprimiendo en el orden correcto
        for (int i = 0; i < n; i++) {
            int numero_actual = lista1[i];

            // Buscamos en qué posición (índice) quedó 'numero_actual' dentro de 'lista1_ordenada'
            // usando búsqueda binaria (lower_bound)
            int indice = lower_bound(lista1_ordenada.begin(), lista1_ordenada.end(), numero_actual) - lista1_ordenada.begin();

            // Como lista1_ordenada y lista2 están emparejadas en las mismas posiciones,
            // imprimimos el elemento de lista2 en ese mismo índice
            cout << lista2[indice] << "\n";
        }
    }

    return 0;
}