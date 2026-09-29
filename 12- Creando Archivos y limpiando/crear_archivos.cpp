#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

void Limpiar()
{
#if defined(_WIN32)
    system("cls");
#elif defined(_linux) // ← Corregido: __linux_ (dos guiones bajos)
    system("clear");
#else
    std::cout << "Sistema operativo: Desconocido" << std::endl;
#endif
}

void Pausa()
{
#if defined(_WIN32)
    std::cout << "\nPresione Enter para continuar..." << std::endl;
    system("pause");
#elif defined(_linux_)
    std::cout << "\nPresione Enter para continuar..." << std::endl;
    cin.get();
    cin.ignore(100, '\n');
#else
    std::cout << "Sistema operativo: Desconocido" << std::endl;
#endif
}

void Escribir()
{
    string nombre;

    ofstream archivo("datos.txt");
    for (int i = 0; i < 2; i++)
    {
        cout << "Nombre: ";

        getline(cin, nombre);

        archivo << nombre << endl;
    }
    archivo.close();
}

void Append()
{
    string nombre;

    ofstream archivo("datos.txt", ios::app);
    for (int i = 0; i < 2; i++)
    {
        cout << "Nombre: ";

        getline(cin, nombre);

        archivo << nombre << endl;
    }
    archivo.close();
}

void Leer()
{
    string nombre;

    ifstream archivo("datos.txt");

    while (getline(archivo, nombre))
    {
        cout << nombre << endl;
    }

    archivo.close();
}

void Productos()
{
    string nombre;
    int precio;

    ofstream archivo("productos.txt");

    for (int i = 0; i < 3; i++)
    {
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Precio: ";
        cin >> precio;

        archivo << nombre << " " << precio << endl;
    }

    archivo.close();
}

void LeerProductos()
{
    string nombre;
    int precio;

    ifstream archivo("productos.txt");

    while (archivo >> nombre >> precio)
    {
        cout << nombre << " " << precio << endl;
    }

    archivo.close();
}

int main()
{
    // string nombre;

    /*
    ofstream archivo("datos.txt", ios::app);
    // ios::app es para que pueda escribir abajo de lo que ya estaba escrito
    // en caso de que no esté eso, se reescribirá el archivo.

    // ios::trunc = Sobreescribe el archivo
    // ios::app = Añade al final

    for (int i = 0; i < 5; i++)
    {
        cout << "Nombre: ";
        getline(cin, nombre);

        archivo << nombre << endl;
    }

    archivo.close();

    */

    /*
    ifstream archivo("datos.txt");
    while (getline(archivo, nombre))
    // archivo >> nombre se puede hacer asi para que cada nombre se escriba abajo.
    //(getline(archivo, nombre)) Fila completa de cada nombre
    {
        cout << nombre << endl;
    }
    */

    int opc;

    while (true)
    {
        Limpiar();
        cout << "ADMINISTRAR ARCHIVOS" << endl;
        cout << "1. Escribir" << endl;
        cout << "2. Append" << endl;
        cout << "3. Leer" << endl;
        cout << "4. Cargar Productos" << endl;
        cout << "5. Ver Productos" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opc;
        cin.ignore(100, '\n');

        switch (opc)
        {

        case 1:
            Limpiar();
            Escribir();
            break;

        case 2:
            Limpiar();
            Append();
            break;

        case 3:
            Limpiar();
            Leer();
            Pausa();
            break;
        case 4:
            Limpiar();
            Productos();
            break;

        case 5:
            Limpiar();
            LeerProductos();
            Pausa();
            break;
        case 0:
            return 0;

        default:
            cout << "Error, intente nuevamente.";
            Pausa();
            break;
        }
    }

    return 1;
}