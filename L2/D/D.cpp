#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

/*
- Paso 1: Leer los atributos
    El problema indica que la primera línea contiene entre 1 y 20 atributos únicos separados 
    por espacios. Como no sabemos cuántos atributos son exactamente antes de leer, usamos 
    getline(cin, linea_atributos) para atrapar la línea completa. Luego, la herramienta 
    stringstream actúa como un procesador de texto que nos permite extraer palabra por palabra 
    (ignorando los espacios) y guardarlas en nuestro vector atributos.

- Paso 2: Leer las canciones
    Leemos la variable 'm' que nos dirá cuántas canciones hay (entre 1 y 100). Con ese dato, 
    declaramos nuestra matriz canciones. Utilizamos dos bucles for anidados: el primero 
    iterará 'm' veces (una por canción) y el segundo iterará según la cantidad de columnas. 
    Como las palabras nunca tienen espacios internos (usan guiones bajos), podemos usar 
    simplemente cin >> para que el programa salte al siguiente texto válido automáticamente y 
    llene la matriz

- Paso 3: Leer los comandos y ordenar
    Leemos la cantidad de comandos y abrimos un bucle que se repetirá esa cantidad de veces.

    1. Leemos la palabra del comando (ej. "Artist").
    
    2. Buscamos esa palabra en nuestro vector atributos para saber su índice (indice_columna).

    3. Llamamos a stable_sort. Le entregamos el inicio y fin de nuestra matriz de canciones y 
    le pasamos nuestra función comparadora (lambda). Esta función le dice a C++: "Al comparar 
    la canción A y la canción B, revisa únicamente la columna indice_columna de ambas, y colócalas 
    basándote en el orden lexicográfico de sus valores ASCII". Como es stable_sort, si las 
    palabras son iguales en ambas canciones, respetará el orden anterior, cumpliendo con la 
    regla de oro del problema.

- Paso 4: Imprimir los resultados
    La salida exige que haya una línea en blanco entre cada par de listas impresas. Para lograr 
    esto sin dejar una línea en blanco sobrante al final del programa, añadimos un salto de 
    línea (cout << endl;) solo si no estamos en la primera ejecución del comando (cmd > 0). 
    Finalmente, imprimimos los nombres de los atributos y el contenido de la matriz ordenado, 
    añadiendo un espacio entre los campos adyacentes. La lógica 
    (i == cantidad_columnas - 1 ? "" : " ") asegura que no dejemos un espacio molesto al 
    final de la línea.

*/


int main(){
    //Paso 1: leer la primera linea de atributos
    string linea_atributos;

    //leemos la primera linea completa
    if(!getline(cin, linea_atributos)) return 0;

    //usamos stringstream para separar las palabras
    stringstream ss(linea_atributos);
    string atributo;
    vector<string> atributos;

    while (ss >> atributo){
        atributos.push_back(atributo);
    }

    int cant_columnas = atributos.size();

    //Paso 2: leer las canciones
    int m;
    if(!(cin >> m)) return 0;

    //creamos una matri de m filas y 'cant_columnas' columnas
    vector<vector<string>> canciones (m, vector<string>(cant_columnas));

    for (int i = 0; i < m; i++){
        for (int j = 0; j < cant_columnas; j++){
            cin >> canciones[i][j];
        }
    }

    //Paso 3: leer comandos y ordenar
    int n;
    cin >> n;

    for (int cmd = 0; cmd < n; cmd++){
        string comando;
        cin >> comando;

        //encontrar en que columna esta el atributo del comando
        int indice_col = -1;
        for (int i = 0; i < cant_columnas; i++){
            if(atributos[i] == comando){
                indice_col = i;
                break;
            }
        }

        //aplicamos el ordenamiento estable
        if (indice_col != -1){
            stable_sort(canciones.begin(), canciones.end(),
                [indice_col](const vector<string>& a, const vector<string>& b){
                    return a[indice_col] < b[indice_col];
                }
            );
        }

        //Paso 4: imprimir resultados
        //imprimimos una linea en blanco ANTES de cada nueva lista, excepto la primera
        if(cmd > 0){
            cout << endl;
        }

        //imprimimos los atributos
        for (int i = 0; i < cant_columnas; i++){
            cout << atributos[i] << (i == cant_columnas - 1 ? "" : " ");
        }

        cout << endl;

        //imprimimos la matriz de canciones ordenadas
        for (int i = 0; i < m; i++){
            for(int j = 0; j < cant_columnas; j++){
                cout << canciones[i][j] << (j == cant_columnas - 1 ? "" : " ");
            }
            cout << endl;
        }
    }

    return 0;
}