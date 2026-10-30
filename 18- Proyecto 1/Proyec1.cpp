// Para este trabajo se deberá desarrollar un programa que simule la gestión de una tienda almacenando
// (o el nombre que quieran) en memoria dinámica, aplicando .
// El sistema debe contar con un menú interactivo que permita
// la información de los productos (como código, nombre, precio y stock),
// así como listarlos y buscarlos. Es obligatorio el uso de punteros y
// reserva/liberación manual de memoria (new/delete).

#include <iostream>
#include <string>
using namespace std;

class Producto
{
private:
    int codigo;
    string nombre;
    float precio;
    int stock;

public:
    Producto(int c, string n, float p, int s)
    {
        codigo = c;
        nombre = n;
        precio = p;
        stock = s;
    }

    int getCodigo() { return codigo; }
    string getNombre() { return nombre; }
    float getPrecio() { return precio; }
    int getStock() { return stock; }

    void MostrarInfo()
    {
        cout << "Codigo: " << codigo << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Stock: " << stock << endl;
    }
};

class Tienda
{
private:
    Producto **productos;
    int capacidad;
    int cantidad;

    int BuscarIndice(int codigo)
    {
        for (int i = 0; i < cantidad; i++)
        {
            if (productos[i]->getCodigo() == codigo)
            {
                return i;
            }
        }

        return -1;
    }

public:
    Tienda(int c)
    {
        capacidad = c;
        cantidad = 0;
        productos = new Producto *[capacidad];

        for (int i = 0; i < capacidad; i++)
        {
            productos[i] = nullptr;
        }
    }

    void AgregarProducto()
    {
        if (cantidad >= capacidad)
        {
            cout << "La tienda alcanzo su capacidad maxima." << endl;
            return;
        }

        int codigo;
        string nombre;
        float precio;
        int stock;

        cout << "Ingrese el codigo del producto: ";
        if (!(cin >> codigo))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: el codigo debe ser un numero entero." << endl;
            return;
        }

        if (codigo <= 0)
        {
            cout << "Error: el codigo debe ser mayor que cero." << endl;
            return;
        }

        if (BuscarIndice(codigo) != -1)
        {
            cout << "Ya existe un producto con ese codigo." << endl;
            return;
        }

        cout << "Ingrese el nombre del producto: ";
        cin.ignore(10000, '\n');
        getline(cin, nombre);

        if (nombre == "")
        {
            cout << "Error: el nombre no puede estar vacio." << endl;
            return;
        }

        cout << "Ingrese el precio del producto: $";
        if (!(cin >> precio))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: el precio debe ser un numero." << endl;
            return;
        }

        if (precio < 0)
        {
            cout << "Error: el precio no puede ser negativo." << endl;
            return;
        }

        cout << "Ingrese el stock del producto: ";
        if (!(cin >> stock))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: el stock debe ser un numero entero." << endl;
            return;
        }

        if (stock < 0)
        {
            cout << "Error: el stock no puede ser negativo." << endl;
            return;
        }

        productos[cantidad] = new Producto(codigo, nombre, precio, stock);
        cantidad++;

        cout << "Producto agregado correctamente." << endl;
    }

    void ListarProductos()
    {
        if (cantidad == 0)
        {
            cout << "Todavia no hay productos cargados." << endl;
            return;
        }

        cout << "\n===== LISTA DE PRODUCTOS =====" << endl;

        for (int i = 0; i < cantidad; i++)
        {
            cout << "\nProducto " << i + 1 << endl;
            cout << "-------------------------" << endl;
            productos[i]->MostrarInfo();
        }
    }

    void BuscarProducto()
    {
        int codigo;

        cout << "Ingrese el codigo del producto que busca: ";
        if (!(cin >> codigo))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: el codigo debe ser un numero entero." << endl;
            return;
        }

        int indice = BuscarIndice(codigo);

        if (indice == -1)
        {
            cout << "No se encontro un producto con ese codigo." << endl;
        }
        else
        {
            cout << "\n===== PRODUCTO ENCONTRADO =====" << endl;
            productos[indice]->MostrarInfo();
        }
    }

    ~Tienda()
    {
        for (int i = 0; i < cantidad; i++)
        {
            delete productos[i];
        }

        delete[] productos;
    }
};

int main()
{
    int capacidad;

    cout << "===== SISTEMA DE GESTION DE TIENDA =====" << endl;
    cout << "Ingrese la cantidad maxima de productos que desea guardar: ";

    while (!(cin >> capacidad) || capacidad <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ingrese una cantidad entera mayor que cero: ";
    }

    Tienda tienda(capacidad);
    int opcion;

    do
    {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Listar productos" << endl;
        cout << "3. Buscar producto por codigo" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: debe ingresar una opcion numerica." << endl;
            opcion = -1;
            continue;
        }

        switch (opcion)
        {
        case 1:
            tienda.AgregarProducto();
            break;

        case 2:
            tienda.ListarProductos();
            break;

        case 3:
            tienda.BuscarProducto();
            break;

        case 0:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
            break;
        }

    } while (opcion != 0);

    return 0;
}