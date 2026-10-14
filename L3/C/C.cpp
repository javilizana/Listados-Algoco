#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    // Optimización estándar para acelerar la lectura/escritura en C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    // 1. Ciclo de lectura: lee hasta encontrar un "0"
    while (cin >> s && s != "0") {
        bool es_tautologia = true;

        // 2. Generar las 32 combinaciones posibles (2^5)
        for (int i = 0; i < 32; i++) {
            stack<bool> st;

            // 3. Evaluar la expresión de derecha a izquierda
            for (int j = s.length() - 1; j >= 0; j--) {
                char c = s[j];

                // Si es una variable (p, q, r, s, t)
                if (c >= 'p' && c <= 't') {
                    // Calculamos a qué bit corresponde (p=0, q=1, r=2, s=3, t=4)
                    int bit_index = c - 'p';
                    // Extraemos el valor del bit usando shift y la operación AND
                    bool valor = (i >> bit_index) & 1;
                    st.push(valor);
                } 
                // Si es el operador Not (solo requiere un operando)
                else if (c == 'N') {
                    bool w = st.top(); 
                    st.pop();
                    st.push(!w);
                } 
                // Si son los operadores lógicos de dos variables
                else {
                    bool w = st.top(); st.pop();
                    bool x = st.top(); st.pop();

                    if (c == 'K') {        // And
                        st.push(w && x);
                    } else if (c == 'A') { // Or
                        st.push(w || x);
                    } else if (c == 'C') { // Implies
                        st.push(!w || x);
                    } else if (c == 'E') { // Equals
                        st.push(w == x);
                    }
                }
            }

            // Al final, el tope de la pila tiene el resultado de la fórmula para esta combinación
            if (!st.top()) {
                es_tautologia = false;
                break; // Cortamos el ciclo, ya sabemos que no es tautología
            }
        }

        // 4. Comprobar e imprimir el resultado
        if (es_tautologia) {
            cout << "tautology\n";
        } else {
            cout << "not\n";
        }
    }

    return 0;
}