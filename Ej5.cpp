/*
Problema: Trabajas en una empresa de logística y debes gestionar los paquetes que llegan
y se entregan a través de un sistema. Cada paquete tiene un número de seguimiento único.
Tu sistema debe permitir la entrada de nuevos paquetes, la entrega (eliminación) de
paquetes, y la verificación de los que siguen en tránsito.
● Tarea: Inserta los paquetes con los números de seguimiento: 1001, 5002, 3003,
2004, 4500, 7005, 8006.
● Desafío: Los paquetes con los números de seguimiento 2004 y 4500 fueron
entregados, así que elimínalos. Luego, un nuevo paquete con el número 3500 llega
al sistema. Verifica si el paquete con el número 1001 sigue en tránsito e imprime la
lista de paquetes restantes.
*/

#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

int main(){

    ArbolBinario<int> paquetes;
    paquetes.put(1001);
    paquetes.put(5002);
    paquetes.put(3003);
    paquetes.put(2004);
    paquetes.put(4500);
    paquetes.put(7005);
    paquetes.put(8006);

    cout << "Lista de paquetes original: " << endl;
    paquetes.print();

    cout << "Paquetes entregados: " << endl;
    paquetes.remove(2004);
    paquetes.remove(4500);
    paquetes.print();

    paquetes.put(3500);
    cout<<"Nuevo paquete con el numero 3500 llega al sistema"<<endl;
    cout << "Lista de paquetes restantes: " << endl;
    paquetes.print();

    try
    {
        int dato=paquetes.search(1001);
        cout<<"El paquete con el numero 1001 sigue en transito"<<endl;
    }
    catch(int e)
    {
        if(e==404){
            cout<<"El paquete con el numero 1001 no sigue en transito"<<endl;
        }
    }
    

}