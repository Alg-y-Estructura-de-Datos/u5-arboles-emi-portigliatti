/*
Un almacén necesita gestionar su inventario de productos. Cada producto tiene un número único de identificación (ID), y el sistema debe mantener el inventario organizado para realizar búsquedas rápidas de productos y permitir actualizaciones del stock.
Utilizar un árbol AVL para almacenar los IDs de los productos. El árbol debe mantenerse balanceado para garantizar búsquedas rápidas.
Crear un sistema con un menú que permita gestionar las siguientes opciones:
1.	Insertar un código de producto.
2.	Eliminar un código de producto.
3.	Buscar un producto por código.
4.	Imprimir el árbol (mostrando su estructura balanceada).
5.	Salir del programa.
*/

#include <iostream>
#include "Arbol/ArbolBinarioAVL.h"
using namespace std;

void menu()
{
    cout << "--------------------MENU DE OPCIONES------------------" << endl;
    cout << "1. Insertar un codigo de producto." << endl;
    cout << "2. Eliminar un codigo de producto." << endl;
    cout << "3. Buscar un producto por codigo." << endl;
    cout << "4. Imprimir el arbol (mostrando su estructura balanceada)." << endl;
    cout << "5. Salir del programa." << endl;
    cout << "------------------------------------------------------" << endl;
}

int main()
{

    ArbolBinarioAVL<int> arbol;
    int opcion, id;

    do
    {
        menu();
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "Ingrese el ID del producto: ";
            cin >> id;
            try
            {
                arbol.put(id);
                cout << "Producto con codigo " << id << " insertado exitosamente." << endl;
            }
            catch (int e)
            {
                cout << "Error: el codigo ya existe o es invalido.\n";
            }
            break;
        case 2:
             cout << "Ingrese el codigo del producto a eliminar: ";
                cin >> id;
                try {
                    arbol.remove(id);
                    cout << "Producto con codigo " << id << " eliminado exitosamente."<<endl;
                } catch (int e) {
                    if(e==200){
                    cout << "Error: no se encontro el codigo a eliminar."<<endl;
                    }
                }
                break;
        case 3:
            cout << "Ingrese el ID del producto a buscar: ";
            cin >> id;
            try
            {
                int encontrado = arbol.search(id);
                cout << "El ID " << id << " se encuentra en el arbol." << endl;
            }
            catch (int e)
            {
                if (e == 404)
                {
                    cout << "ERROR: El ID " << id << " no se encuentra en el arbol." << endl;
                }
            }

        case 4:
            cout << "Estructura del arbol: " << endl;
            arbol.print();
            break;
        case 5:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
            break;
        }
    } while (opcion != 5);
}