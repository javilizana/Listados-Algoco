#include <iostream>

using namespace std;

int main() {
    // Optimización para acelerar la entrada y salida de datos en la consola
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Leemos la cantidad de bytes
    if (cin >> n) {
        for (int k = 0; k < n; k++) {
            int byte_recibido;
            // Leemos cada byte ofuscado
            cin >> byte_recibido;

            // Probamos todos los valores posibles (fuerza bruta de 0 a 255)
            for (int i = 0; i < 256; i++) {
                // Aplicamos la fórmula del sensor y la máscara de 8 bits (255)
                if (((i ^ (i << 1)) & 255) == byte_recibido) {
                    // Si coincide, encontramos el byte original
                    cout << i << " ";
                    break; // Salimos del ciclo para evaluar el siguiente número
                }
            }
        }
        // Un salto de línea al final por buena práctica
        cout << "\n";
    }

    return 0;
}