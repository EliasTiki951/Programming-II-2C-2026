#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

void Limpiar()
{
#if defined(_WIN32)
    system("cls");
#elif defined(__linux__) // ← Corregido: __linux_ (dos guiones bajos)
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
#elif defined(__linux__)
    std::cout << "\nPresione Enter para continuar..." << std::endl;
    cin.get();
    cin.ignore(100, '\n');
#else
    std::cout << "Sistema operativo: Desconocido" << std::endl;
#endif
}

string escritorio = "C:\\Users\\wwwel\\OneDrive\\Escritorio\\";

class Producto
{
private:
    int id;
    string nombre;
    int precio;
    int cantidad;

public:
    Producto(int i, string n, int p, int c)
    {
        id = i;
        nombre = n;
        precio = p;
        cantidad = c;
    }

    int getID() { return id; }
    string getNombre() { return nombre; }
    int getPrecio() { return precio; }
    int getCantidad() { return cantidad; }

    void setNombre(string n) { nombre = n; }
    void setPrecio(int p) { precio = p; }
    void setCantidad(int c) { cantidad = c; }

    void MostrarInfo()
    {
        cout << "ID: " << id << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: " << precio << endl;
        cout << "Cantidad: " << cantidad << endl;
    }

    void ModificarInfo()
    {
        int p, c, opc;
        string n;

        while (true)
        {
            do
            {
                cout << endl;
                cout << "Dato a modificar: " << endl;
                cout << "1.Nombre" << endl;
                cout << "2.Precio" << endl;
                cout << "3.Cantidad" << endl;
                cout << "0.Salir" << endl;
                cout << "Opcion:";
                cin >> opc;
                cin.ignore();
            } while (opc < 0 || opc > 3);

            switch (opc)
            {
            case 1:
                cout << endl;
                cout << "Nuevo Nombre: ";
                getline(cin, n);
                nombre = n;
                break;
            case 2:
                cout << endl;
                cout << "Nuevo Precio: ";
                cin >> p;
                precio = p;
                cin.ignore();
                break;
            case 3:
                cout << endl;
                cout << "Nuevo Cantidad: ";
                cin >> c;
                cantidad = c;
                cin.ignore();
                break;
            case 0:
                return;
            }
        }
    }
};

class Tienda
{
private:
    Producto **inventario;
    int capacidad;
    int cantidad;

public:
    Tienda(int c)
    {
        capacidad = c;
        cantidad = 0;

        inventario = new Producto *[capacidad];

        for (int i = 0; i < capacidad; i++)
        {
            inventario[i] = nullptr;
        }
    }

    ~Tienda()
    {
        for (int i = 0; i < capacidad; i++)
        {
            delete inventario[i];
        }

        delete[] inventario;
    }

    bool AgregarProducto(Producto *p)
    {
        if (cantidad >= capacidad)
        {
            cout << "Error: Stock Insuficiente.";
            return false;
        }
        else
        {
            inventario[cantidad] = p;
            cantidad++;
            return true;
        }
    }

    bool AgregarProducto(int cant)
    {
        int i, p, c;
        string n;

        if (cantidad >= capacidad || (cantidad + cant) > capacidad)
        {
            cout << "Error: Stock Insuficiente.";
            return false;
        }
        else
        {
            for (int j = 0; j < cant; j++)
            {
                i = cantidad + 1;

                cout << endl;
                cout << "Nombre: ";
                getline(cin, n);
                cout << "Precio: ";
                cin >> p;
                cin.ignore();
                cout << "Cantidad: ";
                cin >> c;
                cin.ignore();

                inventario[cantidad] = new Producto(i, n, p, c);
                cantidad++;
            }
            return true;
        }
    }

    void MostrarProductos()
    {
        for (int i = 0; i < cantidad; i++)
        {
            cout << "Producto " << i + 1 << endl;
            inventario[i]->MostrarInfo();
            cout << endl;
        }
    }

    void ModificarInfo()
    {
        int opc, i;

        do
        {
            cout << "1.Seleccionar producto por ID" << endl;
            cout << "2.Ver lista de Productos" << endl;
            cout << "0.Salir" << endl;
            cout << "Opcion: ";
            cin >> opc;
            cin.ignore();
        } while (opc < 0 || opc > 2);

        switch (opc)
        {
        case 1:
            cout << "ID: ";
            cin >> i;
            cin.ignore();

            inventario[i - 1]->ModificarInfo();
            break;

        case 2:
            for (int i = 0; i < cantidad; i++)
            {
                cout << inventario[i]->getID() << ". " << inventario[i]->getNombre() << endl;
            }

            cout << endl;
            cout << "ID: ";
            cin >> i;
            cin.ignore();
            cout << endl;

            inventario[i - 1]->ModificarInfo();
            break;

        case 0:
            return;
        }
    }

    bool EliminarProducto()
    {
        int opc, id;
        string nombre;

        do
        {
            Limpiar();
            cout << "1. Eliminar por ID" << endl;
            cout << "2. Eliminar por Nombre" << endl;
            cout << "0. Salir" << endl;
            cout << "Opcion: ";
            cin >> opc;
            cout << endl;
        } while (opc < 0 || opc > 2);

        switch (opc)
        {
        case 1:
            cout << endl;
            cout << "ID: ";
            cin >> id;
            cin.ignore();
            nombre = "0x0000"; //<- NOMBRE ALEATORIO PARA QUE EL IF DE ABAJO NO DE VERDADERO, PUEDE SER CUALQUIER NOMBRE MIENTRAS NO HAYA UN PRODUCTO CON ESE MISMO NOMBRE
            break;

        case 2:
            cout << endl;
            cout << "Nombre: ";
            cin >> nombre;
            cin.ignore();
            id = -1;
            break;

        case 0:
            return false;
        }

        for (int i = 0; i < cantidad; i++)
        {
            if (inventario[i]->getNombre() == nombre || inventario[i]->getID() == id)
            {
                delete inventario[i];

                /// MOVER ELEMENTOS DEL ARREGLO PARA ATRAS
                for (int j = i; j < cantidad - 1; j++)
                {
                    inventario[j] = inventario[j + 1];
                }

                cantidad--;
                cout << "Producto eliminado exitosamente" << endl;
                return true;
            }
        }
        cout << "Producto no encontrado" << endl;
        return false;
    }

    void GuardarArchivo()
    {
        int id, precio, cant;
        string nombre;

        fstream archivo(escritorio + "productos.txt", ios::out | ios::trunc);

        for (int i = 0; i < cantidad; i++)
        {
            id = inventario[i]->getID();
            nombre = inventario[i]->getNombre();
            precio = inventario[i]->getPrecio();
            cant = inventario[i]->getCantidad();

            archivo << id << ';' << nombre << ';' << precio << ';' << cant << endl;
        }
        archivo.close();
    }

    void CargarDesdeArchivo()
    {
        int id, precio, cant, i = 0;
        string nombre;

        fstream archivo(escritorio + "productos.txt", ios::in | ios::out);

        if (archivo >> id)
        {

            for (int i = 0; i < cantidad; i++)
            {
                delete inventario[i];
                inventario[i] = nullptr;
                cantidad = 0;
            }

            archivo.seekg(0);
            while (archivo >> id)
            {
                archivo.ignore(1);
                getline(archivo, nombre, ';');
                archivo >> precio;
                archivo.ignore(1);
                archivo >> cant;
                archivo.ignore(1);

                inventario[i] = new Producto(id, nombre, precio, cant);
                cantidad++;
                i++;
            }
        }
        else
        {
            cout << "El archivo esta vacio." << endl;
        }

        archivo.close();
    }

    void LeerArchivo()
    {
        int id, precio, cant;
        string nombre;

        fstream archivo(escritorio + "productos.txt", ios::in | ios::out);

        if (archivo >> id)
        {
            archivo.seekg(0);
            while (archivo >> id)
            {
                archivo.ignore(1);
                getline(archivo, nombre, ';');
                archivo >> precio;
                archivo.ignore(1);
                archivo >> cant;
                archivo.ignore(1);

                cout << id << ';' << nombre << ';' << precio << ';' << cantidad << endl;
            }
        }
        else
        {
            cout << "El archivo esta vacio." << endl;
        }

        archivo.close();
    }
};

int main()
{
    Tienda *t1 = new Tienda(100);
    Producto *p1 = new Producto(1, "Jamon", 1000, 10);
    Producto *p2 = new Producto(2, "Queso", 4000, 20);

    t1->AgregarProducto(p1);
    t1->AgregarProducto(p2);

    int opc, cant;

    while (true)
    {
        Limpiar();
        cout << "TIENDA" << endl;
        cout << "1.Agregar Producto" << endl;
        cout << "2.Mostrar Productos" << endl;
        cout << "3.Modificar Productos" << endl;
        cout << "4.Eliminar Productos" << endl;
        cout << "5.Guardar Archivo" << endl;
        cout << "6.Cargar desde Archivo" << endl;
        cout << "7.Leer Archivo" << endl;
        cout << "0.Salir" << endl;
        cout << "Opcion: ";
        cin >> opc;
        cin.ignore();

        switch (opc)
        {

        case 1:
            Limpiar();
            cout << "Cuantos productos \ndesea agregar?: ";
            cin >> cant;
            cin.ignore();
            t1->AgregarProducto(cant);
            Pausa();
            break;

        case 2:
            Limpiar();
            t1->MostrarProductos();
            Pausa();
            break;

        case 3:
            Limpiar();
            t1->ModificarInfo();
            Pausa();
            break;

        case 4:
            Limpiar();
            t1->EliminarProducto();
            Pausa();
            break;

        case 5:
            Limpiar();
            t1->GuardarArchivo();
            Pausa();
            break;

        case 6:
            Limpiar();
            t1->CargarDesdeArchivo();
            Pausa();
            break;

        case 7:
            Limpiar();
            t1->LeerArchivo();
            Pausa();
            break;

        case 0:
            return 0;
        }
    }

    delete t1;

    return 0;
}