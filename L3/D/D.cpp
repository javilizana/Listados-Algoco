#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Función recursiva de backtracking
void buscar_permutaciones(const string& original_str, int original_val, string& actual_str, vector<bool>& usados, int& mejor_respuesta) {
    // 1. Caso Base: El string temporal tiene la misma longitud que el original
    if (actual_str.length() == original_str.length()) {
        int actual_val = stoi(actual_str);
        
        // Si la permutación armada es estrictamente mayor que el número X
        if (actual_val > original_val) {
            // Guardamos el valor si es el primero que encontramos o si es un incremento menor (más cercano a X)
            if (mejor_respuesta == -1 || actual_val < mejor_respuesta) {
                mejor_respuesta = actual_val;
            }
        }
        return; // Terminamos esta rama de la recursión
    }

    // 2. Ciclo Recursivo: Iteramos sobre todos los caracteres del string original
    for (size_t i = 0; i < original_str.length(); ++i) {
        // Solo procedemos si el dígito en la posición 'i' no ha sido utilizado en esta rama
        if (!usados[i]) {
            // PASO 1: "Hacer" (Modificar estado)
            usados[i] = true;
            actual_str.push_back(original_str[i]);

            // PASO 2: Llamada recursiva para el siguiente dígito
            buscar_permutaciones(original_str, original_val, actual_str, usados, mejor_respuesta);

            // PASO 3: "Deshacer" (El núcleo del Backtracking)
            // Revertimos los cambios para que el ciclo for pueda probar con el siguiente dígito
            actual_str.pop_back();
            usados[i] = false;
        }
    }
}

int main() {
    // Optimización estándar para acelerar la entrada/salida en C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string X_str;
    // Leemos la entrada
    if (cin >> X_str) {
        int original_val = stoi(X_str);
        int mejor_respuesta = -1; // Usamos -1 como bandera para saber si encontramos una respuesta válida
        
        vector<bool> usados(X_str.length(), false);
        string actual_str = "";

        // Iniciamos el backtracking
        buscar_permutaciones(X_str, original_val, actual_str, usados, mejor_respuesta);

        // Imprimimos el resultado según el formato exigido
        if (mejor_respuesta == -1) {
            cout << 0 << "\n";
        } else {
            cout << mejor_respuesta << "\n";
        }
    }

    return 0;
}