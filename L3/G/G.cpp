#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Variables globales para el caso de prueba actual
int N, M;
vector<string> nombres_colores;
unordered_map<string, int> id_color;
vector<vector<bool>> prohibido;
vector<bool> visitado;
vector<int> ruta_actual;

// Variables para almacenar los resultados
int total_pinturas;
vector<int> mejor_pintura;

void backtrack() {
    // Caso base: si la ruta tiene N colores, completamos una pintura válida
    if (ruta_actual.size() == N) {
        total_pinturas++;
        
        // Como iteramos en orden de preferencia (0 a N-1), la primera
        // pintura válida que encontremos será obligatoriamente la favorita.
        if (total_pinturas == 1) {
            mejor_pintura = ruta_actual;
        }
        return;
    }

    // Explorar los colores en estricto orden de preferencia
    for (int i = 0; i < N; ++i) {
        // 1. Validar uso: saltar si ya usamos este color
        if (visitado[i]) continue;

        // 2. Validar adyacencia: saltar si choca con el color anterior
        if (!ruta_actual.empty()) {
            int ultimo_color = ruta_actual.back();
            if (prohibido[ultimo_color][i]) {
                continue;
            }
        }

        // 3. Avanzar (Hacer)
        visitado[i] = true;
        ruta_actual.push_back(i);

        // 4. Llamada recursiva
        backtrack();

        // 5. Retroceder (Deshacer / Backtracking)
        ruta_actual.pop_back();
        visitado[i] = false;
    }
}

void resolver_caso() {
    cin >> N;
    
    // Limpiar y redimensionar las estructuras para este nuevo caso
    nombres_colores.resize(N);
    id_color.clear();
    prohibido.assign(N, vector<bool>(N, false));
    visitado.assign(N, false);
    ruta_actual.clear();
    mejor_pintura.clear();
    total_pinturas = 0;

    // Leer los colores y asignarles su índice numérico (0 es el favorito)
    for (int i = 0; i < N; ++i) {
        cin >> nombres_colores[i];
        id_color[nombres_colores[i]] = i;
    }

    cin >> M;
    
    // Leer restricciones y marcar la matriz de adyacencia en ambas direcciones
    for (int i = 0; i < M; ++i) {
        string c1, c2;
        cin >> c1 >> c2;
        int id1 = id_color[c1];
        int id2 = id_color[c2];
        prohibido[id1][id2] = true;
        prohibido[id2][id1] = true;
    }

    // Iniciar la búsqueda
    backtrack();

    // Imprimir los resultados
    cout << total_pinturas << "\n";
    for (int i = 0; i < N; ++i) {
        cout << nombres_colores[mejor_pintura[i]] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Optimización de entrada/salida estándar para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        while (T--) {
            resolver_caso();
        }
    }
    return 0;
}