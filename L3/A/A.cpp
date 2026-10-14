#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//se debe imrpimir Alice o Bob dependiendo de qn gane cada partida
//int: hasta 2x10^9
//long long: hasta 9x10^18
//ocupar long long cuando el numero esta justo en el limite o sobre int

//Regla mat: para ver si un numero n es primo hay que revisar los divisores hasta raiz(n)

bool esPrimo(long long n){
    if (n <= 1) return false; //0 y 1 no son primos
    if(n == 2) return true; //2 es par y primo
    if (n % 2 == 0) return false; //los pares no son primos

    //probamos impares desde 3 hasta raiz(n)
    for(long long i = 3; i * i <= n; i += 2 ){
        if(n % i == 0){
            return false; //encontramos un div => no es primo
        }
    }

    return true; //si todo falló => es primo
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //PRE-CALCULO
    vector<long long> perdedores = {0}; //lista que guarda los valores de N en un estado perdedor

    //calculamos perdedores hasta cubrir el limite max de 10^9
    for(long long num = 1; perdedores.back() <= 15000000; num++){
        bool es_perdedor = true;

        //recorremos los perdedores previos para ver si num es ganador
        for(size_t n = 0; n < perdedores.size(); n++){
            if(esPrimo(num - perdedores[n] + 1)){
                es_perdedor = false;
                break;
            }
        }

        if(es_perdedor){
            perdedores.push_back(num);
        }

    }

    //LECTURA Y RESPUESTA
    int Q;
    cin >> Q; //Q: cant casos prueba (primera línea) o cant de partidas
    //p: num primo

    for(int i = 0; i < Q; i++){
        long long N = 0; //N: num inicial de piedras al inicio de cada partida
        cin >> N;

        //busqueda binaria en el vector de perdedores
        if(binary_search(perdedores.begin(), perdedores.end(), N)){
            cout << "Bob" << "\n"; // Si es un estado perdedor, gana el segundo jugador
        } else{
            cout << "Alice" << "\n"; // Si es un estado ganador, gana el primer jugador
        }

    }

    return 0;
}