#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int n, k;
    
    // 1. Leer el número de estudiantes (n) y comandos (k)
    // n y k están en la primera línea.
    if (!(cin >> n >> k)) return 0;

    // Pila para guardar el historial de quién tiene el huevo.
    stack<int> positions;
    
    // El niño 0 siempre empieza con el huevo en la posición inicial.
    positions.push(0);

    // 2. Procesar los k comandos
    for (int i = 0; i < k; ++i) {
        string cmd;
        cin >> cmd;

        if (cmd == "undo") {
            int m;
            cin >> m;
            // Si el comando es "undo m", quitamos los últimos m estados de la pila.
            for (int j = 0; j < m; ++j) {
                // El problema garantiza que Daenerys no hará "undo" más allá del inicio del juego,
                // por lo que no deberíamos vaciar la pila por completo.
                positions.pop();
            }
        } else {
            // Si el comando es un número, lo convertimos a entero
            int p = stoi(cmd);
            int current_pos = positions.top();
            
            // Calculamos la nueva posición.
            // Nota importante sobre el módulo en C++: 
            // Como p puede ser negativo (lanzamiento en sentido antihorario),
            // el operador % puede dar resultados negativos.
            // Para asegurar un índice circular correcto entre 0 y n-1:
            int next_pos = ((current_pos + p) % n + n) % n;
            
            // Guardamos la nueva posición en la pila
            positions.push(next_pos);
        }
    }

    // 3. Imprimir la posición final
    // Al final, la posición actual será el tope de la pila
    cout << positions.top() << endl;

    return 0;
}