/*
Problema: Estás diseñando un sistema de inscripción para un gimnasio, donde cada socio
tiene un número de socio único. El sistema debe permitir la inscripción de nuevos socios, la
eliminación de socios que se dan de baja, y la búsqueda de socios activos.
● Tarea: Inscribe a los socios con los siguientes números de socio: 500, 250, 750, 100,
300, 600, 800.
● Desafío: Un socio con el número 250 se da de baja, así que elimínalo. Luego,
verifica si los socios con los números 300 y 750 aún están activos. Imprime la lista
de socios actualizada.
*/
#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

int main()
{

    ArbolBinario<int> socios;
    socios.put(500);
    socios.put(250);
    socios.put(750);
    socios.put(100);
    socios.put(300);
    socios.put(600);
    socios.put(800);

    cout << "Lista de socios original: " << endl;
    socios.print();

    socios.remove(250);

    try
    {
        int socio1 = socios.search(300);
        cout << "El socio con el numero 300 esta activo" << endl;
    }
    catch (int e)
    {
        if (e == 404)
        {
            cout << "El socio con el numero 300 no esta activo" << endl;
        }
    }

    try
    {
        int socio2 = socios.search(750);
        cout << "El socio con el numero 750 esta activo" << endl;
    }
    catch (int e)
    {
        if (e == 404)
        {
            cout << "El socio con el numero 750 no esta activo" << endl;
        }
    }
    cout << "Lista de socios luego de remover al socio con el numero 250: " << endl;
    socios.print();
}