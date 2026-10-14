#include <iostream>
#include <string>

using namespace std;

// Función auxiliar para verificar si un caracter es vocal
bool es_vocal(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

// Función recursiva de Backtracking
// Usamos "long long" para evitar desbordamiento de memoria con números grandes
long long resolver(int indice, int vocales, int consonantes, bool tiene_L, const string& palabra) {
    
    // 1. Caso base: Romper la regla de las 3 seguidas
    if (vocales == 3 || consonantes == 3) {
        return 0; 
    }

    // 2. Caso base: Llegamos al final de la palabra
    if (indice == palabra.length()) {
        if (tiene_L == true) {
            return 1; // Palabra válida
        } else {
            return 0; // Palabra inválida porque no tiene 'L'
        }
    }

    char c = palabra[indice];

    // 3. Paso recursivo si encontramos un guión bajo '_'
    if (c == '_') {
        long long total = 0;
        
        // Rama 1: Reemplazar por una de las 5 vocales
        total += 5 * resolver(indice + 1, vocales + 1, 0, tiene_L, palabra);
        
        // Rama 2: Reemplazar por una de las 20 consonantes (que no son 'L')
        total += 20 * resolver(indice + 1, 0, consonantes + 1, tiene_L, palabra);
        
        // Rama 3: Reemplazar por la letra 'L' (1 opción)
        // Nota: cambiamos tiene_L a true
        total += 1 * resolver(indice + 1, 0, consonantes + 1, true, palabra);
        
        return total;
    } 
    // 4. Paso recursivo si es una letra preexistente
    else {
        if (es_vocal(c)) {
            // Es vocal preexistente
            return resolver(indice + 1, vocales + 1, 0, tiene_L, palabra);
        } else if (c == 'L') {
            // Es la letra L preexistente
            return resolver(indice + 1, 0, consonantes + 1, true, palabra);
        } else {
            // Es otra consonante preexistente
            return resolver(indice + 1, 0, consonantes + 1, tiene_L, palabra);
        }
    }
}

// Función principal
int main() {
    string palabra;
    
    // Leemos la palabra desde la consola
    if (cin >> palabra) {
        // Llamamos a la función empezando en el índice 0, con 0 vocales/consonantes seguidas y sin 'L'
        long long resultado = resolver(0, 0, 0, false, palabra);
        
        // Imprimimos el resultado final
        cout << resultado << endl;
    }
    
    return 0;
}