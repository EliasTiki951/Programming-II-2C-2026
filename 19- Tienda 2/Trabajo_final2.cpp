#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Productos
{
protected:
    int id, precio, stock, idBuscado;
    string nombre, nombreProducto, stockProducto, precioProducto;
    /*cambiar la ruta por el de su computadora para ver el archivo*/
    string ruta = "C:\\Users\\lauta\\Desktop\\";

public:
    Productos(int id, int precio, int stock, string nombre)
    {
        this->id = id;
        this->nombre = nombre;
        this->precio = precio;
        this->stock = stock;
    }

    void escribir()
    {
        ofstream archivo(ruta + "productos.csv", ios::app);
        if (id <= 1)
        {
            archivo << "id;nombre;precio;stock" << endl;
        }
        archivo << id << ";" << nombre << ";" << precio << ";" << stock << endl;
        archivo.close();
    }

    void buscarProducto()
    {

        cout << "Ingrese el ID del producto que quiere buscar: ";
        cin >> idBuscado;

        ifstream archivo(ruta + "productos.csv");
        if (!archivo)
        {
            cout << "No se pudo abrir el archivo de productos." << endl;
            return;
        }

        string idTexto;
        bool encontrado = false;
        while (getline(archivo, idTexto, ';'))
        {
            getline(archivo, nombreProducto, ';');
            getline(archivo, precioProducto, ';');
            getline(archivo, stockProducto);

            if (idTexto == "id")
            {
                continue;
            }

            if (idTexto == to_string(idBuscado))
            {
                cout << "id " << idTexto << endl;
                cout << "nombre " << nombreProducto << endl;
                cout << "precio " << precioProducto << endl;
                cout << "stock " << stockProducto << endl;
                cout << endl;
                encontrado = true;
                break;
            }
        }

        archivo.close();

        if (!encontrado)
        {
            cout << "Producto no encontrado." << endl;
            cout << endl;
        }
    }

    void verProductos()
    {
        ifstream archivo(ruta + "productos.csv");
        if (!archivo)
        {
            cout << "No se pudo abrir el archivo de productos." << endl;
            return;
        }

        string linea;
        while (getline(archivo, linea))
        {
            cout << linea << endl;
        }

        archivo.close();
    }

    void modificarProducto()
    {
        cout << "Ingrese el ID del producto que desea modificar: ";
        cin >> idBuscado;

        ifstream archivo(ruta + "productos.csv");
        if (!archivo)
        {
            cout << "No se pudo abrir el archivo de productos." << endl;
            return;
        }

        string contenido;
        bool encontrado = false;
        string idTexto;
        while (getline(archivo, idTexto, ';'))
        {
            if (!getline(archivo, nombreProducto, ';') ||
                !getline(archivo, precioProducto, ';') ||
                !getline(archivo, stockProducto))
            {
                cout << "El archivo de productos tiene un formato invalido." << endl;
                return;
            }

            if (idTexto == "id")
            {
                contenido += "id;nombre;precio;stock\n";
                continue;
            }

            if (idTexto == to_string(idBuscado))
            {
                cout << "Ingrese el nuevo nombre del producto: ";
                cin.ignore();
                getline(cin, nombreProducto);
                cout << "Ingrese el nuevo precio del producto: ";
                cin >> precioProducto;
                cout << "Ingrese el nuevo stock del producto: ";
                cin >> stockProducto;
                contenido += idTexto + ";" + nombreProducto + ";" + precioProducto + ";" + stockProducto + "\n";
                encontrado = true;
            }
            else
            {
                contenido += idTexto + ";" + nombreProducto + ";" + precioProducto + ";" + stockProducto + "\n";
            }
        }
        archivo.close();

        if (!encontrado)
        {
            cout << "Producto no encontrado." << endl;
            return;
        }

        ofstream salida(ruta + "productos.csv", ios::trunc);
        if (!salida)
        {
            cout << "No se pudo guardar el producto modificado." << endl;
            return;
        }
        salida << contenido;
        if (!salida)
        {
            cout << "No se pudo guardar el producto modificado." << endl;
            return;
        }
        cout << "Producto modificado correctamente." << endl;
    }

    void eliminarProducto()
    {
        cout << "Ingrese el ID del producto que desea eliminar: ";
        cin >> idBuscado;

        ifstream archivo(ruta + "productos.csv");
        if (!archivo)
        {
            cout << "No se pudo abrir el archivo de productos." << endl;
            return;
        }

        string contenido;
        bool encontrado = false;
        string idTexto;
        while (getline(archivo, idTexto, ';'))
        {
            if (!getline(archivo, nombreProducto, ';') ||
                !getline(archivo, precioProducto, ';') ||
                !getline(archivo, stockProducto))
            {
                cout << "El archivo de productos tiene un formato invalido." << endl;
                return;
            }

            if (idTexto == "id")
            {
                contenido += "id;nombre;precio;stock\n";
            }
            else if (!encontrado && idTexto == to_string(idBuscado))
            {
                encontrado = true;
            }
            else
            {
                contenido += idTexto + ";" + nombreProducto + ";" + precioProducto + ";" + stockProducto + "\n";
            }
        }
        archivo.close();

        if (!encontrado)
        {
            cout << "Producto no encontrado." << endl;
            return;
        }

        ofstream salida(ruta + "productos.csv", ios::trunc);
        if (!salida)
        {
            cout << "No se pudo guardar el archivo de productos." << endl;
            return;
        }
        salida << contenido;
        if (!salida)
        {
            cout << "No se pudo guardar el archivo de productos." << endl;
        }
    }
};

int main()
{
    int opc, cantidad = 0, id, precio, stock;
    string nombre;
    Productos b1(0, 0, 0, "");
    int siguienteLin = 1;
    ifstream archivo("C:\\Users\\lauta\\Desktop\\productos.csv");
    string linea;
    int idGuardado;
    char separador;

    getline(archivo, linea);
    while (archivo >> idGuardado >> separador)
    {
        if (separador == ';' && idGuardado >= siguienteLin)
        {
            siguienteLin = idGuardado + 1;
        }
        getline(archivo, linea);
    }

    Productos **producto = nullptr;
    while (true)
    {
        cout << endl;
        cout << "bienvenido al sistema de inventario" << endl;
        cout << "1. Ingresar productos" << endl;
        cout << "2. buscar producto" << endl;
        cout << "3. ver productos" << endl;
        cout << "4. modificar producto" << endl;
        cout << "5. eliminar producto" << endl;
        cout << "0. salir" << endl;
        cout << "ingrese una opcion: ";
        cin >> opc;
        cin.ignore();

        switch (opc)
        {
        case 1:
        {
            cout << "cuantos productos quiere ingresar: ";
            cin >> cantidad;
            cin.ignore();

            producto = new Productos *[cantidad];
            cout << "cargando productos..." << endl;

            for (int i = 0; i < cantidad; i++)
            {
                id = siguienteLin++;
                cout << "Id del producto " << id << ": " << endl;

                cout << "ingrese el nombre del producto: " << endl;
                getline(cin, nombre);
                cout << "ingrese el precio del producto: " << endl;
                cin >> precio;
                cin.ignore();
                cout << "ingrese el stock del producto: " << endl;
                cin >> stock;
                cin.ignore();
                producto[i] = new Productos(id, precio, stock, nombre);
                producto[i]->escribir();
            }
            cout << endl;
            break;
        }
        case 2:
            cout << "buscando..." << endl;
            b1.buscarProducto();
            cout << endl;
            break;
        case 3:
            cout << "leyendo productos..." << endl;
            b1.verProductos();
            cout << endl;
            break;
        case 4:
            cout << "modificando..." << endl;
            b1.modificarProducto();
            cout << endl;
            break;
        case 5:
            cout << "eliminando..." << endl;
            b1.eliminarProducto();
            cout << endl;
            break;
        case 0:
            for (int i = 0; i < cantidad; i++)
            {
                delete producto[i];
            }
            delete[] producto;
            cout << "adios..." << endl;
            return 0;
        default:
            cout << "opcion invalida" << endl;
            cout << "por favor ingrese una opcion valida" << endl;
            cout << endl;
            break;
        }
    }
    return 0;
}