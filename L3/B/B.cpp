#include <iostream> // Necesario para cin (input) y cout (print)
#include <cmath>    // Necesario para la función abs() (valor absoluto)
#include <string>   // Para manejar cadenas de texto

using namespace std; // Nos evita escribir std::cout o std::cin todo el tiempo

int main() {
    string fila;
    int scatter = 0;

    // En Python harías algo como: for i in range(4):
    for (int i = 0; i < 4; i++) {
        // 'cin >>' lee la siguiente palabra o línea sin espacios. 
        // Es equivalente a input().strip() en Python.
        cin >> fila; 
        
        for (int j = 0; j < 4; j++) {
            char c = fila[j]; // Extraemos el caracter en la posición j
            
            if (c != '.') {
                // En Python usarías ord(c) - ord('A'). 
                // En C++ los caracteres son números en el fondo (ASCII), así que puedes restarlos directamente.
                int val = c - 'A'; 
                
                // Calculamos la fila y columna donde DEBERÍA estar esa letra
                // La división entera (/) nos da la fila, el módulo (%) nos da la columna
                int fila_ideal = val / 4;
                int columna_ideal = val % 4;
                
                // Sumamos la distancia de Manhattan usando abs()
                scatter += abs(i - fila_ideal) + abs(j - columna_ideal);
            }
        }
    }

    // cout es el equivalente a print() en Python. endl es un salto de línea.
    cout << scatter << endl;

    // Todo programa en C++ que termina correctamente debe retornar 0
    return 0;
}