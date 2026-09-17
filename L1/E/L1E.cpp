#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm> //para usar min()

using namespace std;

void resolver_caso(){
    int n;
    cin >> n;

    // Bids (Compras): Max-Heap. El precio más alto queda en la cima
    // compras (precio, cant acciones)
    priority_queue<pair<int,int>> bids; 

    // Asks (Ventas): Min-Heap. El precio más bajo queda en la cima
    //ventas (precio, cant acciones)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> ask; 
    
    int stock_price = -1; // -1 representará nuestro guion "-"

    for (int i = 0; i < n; i++){
        string tipo_orden , shares, at;
        int acciones, precio;

        cin >> tipo_orden >> acciones >> shares >> at >> precio;
        //"buy 10 shares at 100" -> tipo_orden = "buy", acciones = 10, shares = "shares", at = "at", precio = 100

        if (tipo_orden == "buy"){
            bids.push({precio, acciones});
        } else {
            ask.push({precio, acciones});
        }

        /*
        condiciones:
        - Que haya compradores (!bids.empty())
        - Que haya vendedores (!asks.empty())
        - Que el mejor precio de compra sea mayor o igual al mejor 
        precio de venta (bids.top().first >= asks.top().first)
        */
        while (!bids.empty() && !ask.empty() && bids.top().first >= ask.top().first){
            auto mejor_bid = bids.top();
            auto mejor_ask = ask.top();
            //las sacamos pq ya estan en las variables temporales
            bids.pop();
            ask.pop();

            stock_price = mejor_ask.first; // El precio del trato es el de la venta (ask)
            
            // Cantidad de acciones a intercambiar
            int acciones_intercambiadas = min(mejor_bid.second, mejor_ask.second);
            
            // Restamos las acciones que ya se vendieron/compraron
            mejor_bid.second -= acciones_intercambiadas;
            mejor_ask.second -= acciones_intercambiadas;

            // Si a la orden aún le faltan acciones, vuelve a la cola
            if (mejor_bid.second > 0){
                bids.push(mejor_bid);
            }
            if (mejor_ask.second > 0){
                ask.push(mejor_ask);
            }
        }

        //imprimimos el estado actual
        if (ask.empty()){
            cout << "- ";
        } else {
            cout << ask.top().first << " ";
        }
        if (bids.empty()){
            cout << "- ";
        } else {
            cout << bids.top().first << " ";
        }
        if (stock_price == -1){
            cout << "-\n";
        }else{
            cout << stock_price << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casos_prueba;
    if (cin >> casos_prueba){
        while (casos_prueba--){
            resolver_caso();
        }
    }
    return 0;
}