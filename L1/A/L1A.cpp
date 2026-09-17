#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int n , k; // n = cant de niños | k = cant de comandos
    
    if (!(cin >> n >> k)) return 0; //si no lee el n y k

    stack<int> seguimiento; //solo acepta ints

    seguimiento.push(0); //la pos 0 siempre parte con el huevo

    for (int i = 0; i < k; ++i){
        string comando;
        cin >> comando;

        if (comando == "undo"){
            int m;
            cin >> m;
            for (int j = 0; j < m; ++j){
                seguimiento.pop();
            }
        } else{
            int comando_int = stoi(comando);
            int actual = seguimiento.top();
            
            int siguiente = (actual + comando_int) %n;

            if(siguiente < 0){
                siguiente += n;
            }

            seguimiento.push(siguiente);
        }
    }

    cout << seguimiento.top() << endl;
    return 0;
}