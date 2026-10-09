#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <conio.h>
#include <string>
using namespace std;

string escritorio = "C:\\Users\\wwwel\\OneDrive\\Escritorio\\";

class Producto
{
protected:
    int id;
    string nombre;
    float precio;
    int cant;

public:
    Producto(int i, string n, float p, int c)
    {
        this->id = i;
        this->nombre = n;
        this->precio = p;
        this->cant = c;
    }

    void guardarEnArchivo()
    {
        // Crear el archivo dentro de la carpeta
        ofstream archivo(escritorio + "datos\\productos.txt", ios::app);
        string filename = escritorio + "datos\\productos.txt";
        if (archivo.is_open())
        {
            fstream archivo(filename, ios::app);
            archivo << id << ";" << nombre << ";" << cant << ";" << precio << endl;
        }
    }
};

/*
class Tienda
{
private:
    Producto **productos;
    int cap;

public:
    Tienda(int c)
    {
        productos = new Producto *[c];
        this->cap = c;
    }
};
*/

void CargarDatos()
{
    int id, cant;
    string nombre;
    float precio;
    int cap;

    filesystem::create_directory(escritorio + "datos");

    cout << "Ingrese la capacidad de tu Tienda: ";
    cin >> cap;
    cin.ignore();

    Producto **productos = new Producto *[cap];

    // Tienda tienda(cap);

    for (int i = 0; i < cap; i++)
    {
        cout << i + 1 << ". Ingrese nombre del producto: ";
        getline(cin >> ws, nombre);
        // ws= Significa "whitespace" (espacios en blanco)
        cout << "Ingrese cantidad disponible: ";
        cin >> cant;
        cout << "Ingrese precio: $";
        cin >> precio;
        cout << "\n";

        productos[i] = new Producto(i + 1, nombre, precio, cant);
        productos[i]->guardarEnArchivo();
    }

    for (int i = 0; i < cap; i++)
    {
        delete productos[i]; // Liberar memoria de cada objeto Persona
    }

    delete[] productos; // Liberar memoria del array dinámico
}

void LeerArchivo(fstream &archivo)
{
    int id, cant;
    string idStr, nombreStr, precioStr, cantStr;
    string nombre;
    float precio;

    cout << "\n--- LECTURA ---" << endl;
    while (getline(archivo, idStr, ';'))
    {
        id = stoi(idStr);
        getline(archivo, nombreStr, ';');
        nombre = nombreStr;
        getline(archivo, precioStr, ';');
        precio = stof(precioStr);
        getline(archivo, cantStr, ';');
        cant = stoi(cantStr);

        cout << "ID: " << id << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Cantidad: " << cant << endl;
        cout << "Precio: $" << precio << endl;
        cout << "\n";
    }
}

int main()
{
    setlocale(LC_ALL, "spanish");

    int opc;

    while (true)
    {
        cout << "========" << endl;
        cout << "  MENU  " << endl;
        cout << "========" << endl;
        cout << "\n";
        cout << "1. Cargar datos de productos" << endl;
        cout << "2. Leer los productos" << endl;
        cout << "3. Salir" << endl;
        cout << "Opción: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            CargarDatos();
            break;
        case 2:
        {
            fstream archivo(escritorio + "datos\\productos.txt", ios::in);
            if (archivo.is_open())
            {
                LeerArchivo(archivo);
            }
            else
            {
                cout << "No se pudo abrir el archivo." << endl;
            }
            break;
        }
        case 3:
            cout << "Saliendo del programa..." << endl;
            continue;
        default:
            cout << "Opción inválida..." << endl;
            break;
        }
        return 0;
    }

    return 0;
}