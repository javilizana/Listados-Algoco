#include <iostream>
#include <string>
#include <list>

using namespace std;

void resolver(){
    string linea;
    getline(cin, linea); //lee la línea completa (con espacios)

    list<char> texto;
    auto cursor = texto.begin(); //coloca el cursor al inicio | cursor: puntero q ahora apunta al inicio de la linea

    for (char c : linea){ //en python: for c in linea..... | recorre cada letra del input
        if (c == '['){
            cursor = texto.begin();
        }
        else if(c == ']'){
            cursor = texto.end();
        }
        else if (c == '<'){
            if (cursor != texto.begin()){
                auto borrar = cursor; //borrar: cursor temporal
                --borrar; //movemos el cursor temporal 1 espcio a la izq
                texto.erase(borrar); //borramos el carc que apunta el cursor temporal
            }
        }
        else {
            texto.insert(cursor, c); //se inserta el carc en la pos del cursor
        }
    }

    for(char c : texto){
        cout << c; //juntamos todo
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    if (cin >> t){
        cin.ignore();
        while(t > 0){
            resolver();
            t--;
        }
    }

    
    return 0;

}