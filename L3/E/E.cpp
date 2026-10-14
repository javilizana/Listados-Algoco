#include <iostream>
#include <vector>
#include <cmath>     // Para sqrt() y round()
#include <algorithm> // Para swap()

using namespace std;

// En C++ es muy útil crear "structs" (similares a pequeñas clases o TDAs) 
// para mantener los datos ordenados, en lugar de usar variables sueltas.
struct Rectangulo {
    int alto, ancho;
};

int L; // Variable global para guardar el lado del cuadrado objetivo

// Función de validación geométrica
bool verificar(vector<Rectangulo>& rects) {
    // Caso 1.a (Paralelos): Los tres tienen el mismo alto L y sus anchos suman L
    if (rects[0].alto == L && rects[1].alto == L && rects[2].alto == L) {
        if (rects[0].ancho + rects[1].ancho + rects[2].ancho == L) {
            return true;
        }
    }
    
    // Caso 1.b (Mixto): Uno ocupa todo un lado (L) y los otros dos rellenan el resto.
    // Como no sabemos cuál de los 3 es el rectángulo principal, probamos los 3 casos.
    for (int i = 0; i < 3; i++) {
        int j = (i + 1) % 3; // Índice del segundo rectángulo
        int k = (i + 2) % 3; // Índice del tercer rectángulo
        
        if (rects[i].alto == L) {
            // El espacio restante a rellenar tiene un ancho de (L - rects[i].ancho)
            // Los otros dos rectángulos deben tener la misma altura para formar un bloque
            if (rects[j].alto == rects[k].alto && rects[j].alto == L - rects[i].ancho) {
                // Y la suma de las bases de ese bloque debe completar el largo L
                if (rects[j].ancho + rects[k].ancho == L) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

// Función recursiva de Backtracking
// Pasamos el vector por referencia (&) para no copiarlo en memoria en cada llamada
bool backtracking(int indice, vector<Rectangulo>& rects) {
    // Caso base: si ya decidimos la rotación de los 3 rectángulos, verificamos
    if (indice == 3) {
        return verificar(rects);
    }

    // Rama 1: Probar el rectángulo en su orientación actual
    if (backtracking(indice + 1, rects)) {
        return true;
    }

    // Rama 2: Rotar el rectángulo (intercambiar alto y ancho)
    swap(rects[indice].alto, rects[indice].ancho);
    
    if (backtracking(indice + 1, rects)) {
        return true;
    }
    
    // Restaurar el estado (Backtrack) para que las modificaciones de esta rama 
    // no afecten a las ramas anteriores en el árbol de recursión.
    swap(rects[indice].alto, rects[indice].ancho);

    return false; // Si ninguna de las dos ramas funcionó
}

int main() {
    // Optimizaciones de lectura para programación competitiva (ej. plataformas como Kattis o VJudge)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Rectangulo> rects(3);
    int area_total = 0;

    // 1. Lectura de datos y cálculo del área
    for (int i = 0; i < 3; i++) {
        cin >> rects[i].alto >> rects[i].ancho;
        area_total += rects[i].alto * rects[i].ancho;
    }

    // 2. Filtro matemático: ¿El área total forma un cuadrado perfecto?
    L = round(sqrt(area_total));
    
    if (L * L != area_total) {
        cout << "NO\n";
        return 0; // Terminamos el programa inmediatamente
    }

    // 3. Ejecutar el backtracking comenzando desde el índice 0
    if (backtracking(0, rects)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}