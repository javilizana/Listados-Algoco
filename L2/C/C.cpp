#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

//1. definimos la estructura de los datos
struct Persona{
    string nombre;
    vector<int> jerarquia;
};

//2. funcion comparadora para ordenar
bool compararPersona(const Persona& a, const Persona& b){
    //si las jerarquías son iguales, desempatamos por nombre
    if (a.jerarquia == b.jerarquia){
        return a.nombre < b.nombre;
    }

    //si no son iguales, ordenamos de mayor a menor jerarquia
    return a.jerarquia > b.jerarquia;
}

void resolverCaso(){
    int n;
    cin >> n;
    cin.ignore(); //limpiamos el salto de linea que deja cin >>

    vector<Persona> personas;

    for (int i = 0; i < n; i++){
        string linea;
        getline(cin, linea); //leemos la linea completa

        //3. separamos el nombre del resto
        size_t posDosPuntos = linea.find(':');
        string nombre = linea.substr(0, posDosPuntos);

        //extraemos las clases, saltando los : y el espacio (pos + 2)
        string clasesStr = linea.substr(posDosPuntos + 2);

        //eliminamos " class" del final (tiene 6 carac)
        clasesStr = clasesStr.substr(0, clasesStr.length() - 6);

        //4. procesamos las palabras separadas por guiones
        stringstream ss(clasesStr);
        string palabra;
        vector<int> jerarquia;

        while (getline(ss, palabra, '-')){
            if(palabra == "upper") jerarquia.push_back(3);
            else if (palabra == "middle") jerarquia.push_back(2);
            else if (palabra == "lower") jerarquia.push_back(1);
        }

        //invertimos la lista para que la clase principal quede al principio (pos 0)
        reverse(jerarquia.begin(), jerarquia.end());
        
        //5. Padding: rellenamos con 'middle' (2) hasta tener 10 elementos
        while (jerarquia.size() < 10){
            jerarquia.push_back(2);
        }
        
        //agregamos a la persona ya procesada a la lista principal
        personas.push_back({nombre, jerarquia});
    }

    //6. ordenamos usando la funcion personalizada
    sort(personas.begin(), personas.end(), compararPersona);

    //7. imprimimos el resultado
    for(const Persona& p : personas){
        cout << p.nombre << endl;
    }

    cout << "==============================" << endl;
}  

int main(){
    //leemos la cant de casos
    int t;
    if(cin >> t){
        cin.ignore();
        while (t--){
            resolverCaso();
        }
    }
    return 0;
}
