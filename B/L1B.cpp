#include <iostream>

using namespace std;

int main(){
    
    int n; //cant de montañas
    cin >> n;

    int salto = 0; //vamos a retornar este valor
    int max_h = 0; //montaña + alta
    int min_h = 0; //pto + bajo encontrado dsp de max_h

    for (int i = 0; i < n; ++i){
        int h; //altura montaña actual
        cin >> h;

        //si esq estamos en la primera montaña
        if (i == 0){
            max_h = h;
            min_h = h;
        }
        //si se encuentra un pilar igual o más alto
        else if (h >= max_h){
            if (max_h - min_h > salto){
                salto = max_h - min_h;
            }
            max_h = h;
            min_h = h;
        }
        //si la montaña actual es mas baja
        else{
            if (h < min_h){
                min_h = h;
            }
            if (h - min_h > salto){
                salto = h - min_h;
            }
        }
    }

    cout << salto;
    return 0;

}

