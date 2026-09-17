#include <iostream>
#include <string>
#include <deque>
#include <sstream>

using namespace std;

// 1. Leer la cantidad de casos de prueba
// 2. Crear un ciclo (for o while) para procesar cada caso
// 3. Dentro del ciclo: leer comandos, leer cantidad de números, leer el string de la lista
// 4. Limpiar el string de la lista y meter los números al deque
// 5. Aplicar la lógica de la variable booleana y los pop_front/pop_back
// 6. Imprimir el resultado final o "error"

int main(){
    int n; // cant de casos de prueba
    cin >> n;

    for (int i = 0; i < n; ++i){ // para cada caso de prueba
        string comandos;
        int cant_elementos;
        string entrada;
        cin >> comandos >> cant_elementos >> entrada;

        // Supongamos que acabas de leer la entrada y la guardaste en esta variable:
        //string entrada = "[1,2,33,4]";
        // 4.1. Quitar los corchetes iniciales y finales
        // substr(inicio, cantidad) toma un pedazo del string. 
        // Empezamos en el índice 1 (para saltar el '[') y tomamos el largo total menos 2 (para no incluir '[' ni ']').
        string entrada_limpia = entrada.substr(1, entrada.length() -2);
        // "[1,2,33,4]" -> "1,2,33,4"

        deque<int> lista;

        if (!entrada_limpia.empty()){
            stringstream flujo(entrada_limpia);
            string temporal;

            while (getline(flujo, temporal, ',')){
                lista.push_back(stoi(temporal)); //coloca todos los numeros en el deque
            }
        }

        bool reversa = false;
        bool error = false;
        for (char c : comandos){
            
            if (c == 'R'){
                reversa = !reversa;
            }
            else if (c == 'D'){
                if (lista.empty()){
                    error = true;
                    break;
                }
                else{
                    if(reversa == true){
                        lista.pop_back();
                    } else{
                        lista.pop_front();
                    }
                }  
            }
        }

        if (error){
            cout << "error\n";
        }
        else{
            cout <<"[";
            while (!lista.empty()){
                if (reversa == true){
                    cout << lista.back();
                    lista.pop_back();
                } else {
                    cout << lista.front();
                    lista.pop_front();
                }
                
                if (!lista.empty()){
                    cout << ",";
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}