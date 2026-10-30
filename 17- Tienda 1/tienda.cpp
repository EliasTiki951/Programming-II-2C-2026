#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

class Productos
{
private:
    string nombre;
    int precio;
    int stock;

public:
    Productos(string n, int p, int s)
    {
        nombre = n;
        precio = p;
        stock = s;
    }

    string getNombre() { return nombre; }
    int getPrecio() { return precio; }
    int getStock() { return stock; }

    void setNombre(string n) { nombre = n; }
    void setPrecio(int p) { precio = p; }
    void setStock(int s) { stock = s; }

    void MostrarInfo()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: " << precio << endl;
        cout << "Stock: " << stock << endl;
        cout << endl;
    }
};

class Tienda
{
private:
    Productos **prod;
    int capacidad;
    int cantidad;

public:
    Tienda(int c)
    {
        capacidad = c;
        cantidad = 0;
        prod = new Productos *[capacidad];

        for (int i = 0; i < capacidad; i++)
        {
            prod[i] = nullptr;
        }
    }

    void AgregarProducto(Productos *pr)
    {
        if (cantidad >= capacidad)
        {
            cout << "No se pueden agregar mas productos";
            return;
        }

        prod[cantidad] = pr;
        cantidad++;
    }

    void AgregarProducto()
    {
        string n;
        int p, s;

        if (cantidad >= capacidad)
        {
            cout << "No se pueden agregar mas productos";
            return;
        }

        cout << "Nombre: ";
        cin >> n;
        cout << "Precio: ";
        cin >> p;
        cout << "Stock: ";
        cin >> s;

        prod[cantidad] = new Productos(n, p, s);
        cantidad++;
    }

    bool EliminarProducto(string nombre)
    {
        for (int i = 0; i < cantidad; i++)
        {
            if (prod[i]->getNombre() == nombre)
            {
                delete prod[i];

                /// MOVER ELEMENTOS DEL ARREGLO PARA ATRAS
                for (int j = i; j < cantidad - 1; j++)
                {
                    prod[j] = prod[j + 1];
                }

                cantidad--;
                cout << "Producto eliminado exitosamente" << endl;
                return true;
            }
        }
        cout << "Producto no encontrado" << endl;
        return false;
    }

    void VenderProducto()
    {
        int opc, cant, importe;
        cout << "Seleccione el producto: " << endl;

        for (int i = 0; i < cantidad; i++)
        {
            cout << i + 1 << ". " << prod[i]->getNombre() << endl;
        }
        cout << "Opcion: ";
        cin >> opc;
        opc--;
        cout << "Cantidad: ";
        cin >> cant;

        if (cant > prod[opc]->getStock())
        {
            cout << "Error, stock insuficiente";
            return;
        }
        else
        {
            importe = (prod[opc]->getPrecio() * cant);
            prod[opc]->setStock((prod[opc]->getStock() - cant));

            cout << "Importe: " << importe << endl;
        }
    }

    void MostrarProductos()
    {
        for (int i = 0; i < cantidad; i++)
        {
            prod[i]->MostrarInfo();
        }
    }
};

int main()
{
    Productos p1("Jamon", 100, 20);
    Productos p2("Queso", 500, 10);
    Productos *p3 = new Productos("Mortadela", 350, 8);
    Productos p4("Salame", 200, 10);

    // p1.MostrarInfo();

    Tienda t1(100);

    // CARGAR OBJETOS CREADOS EN STACK
    t1.AgregarProducto(&p1);
    t1.AgregarProducto(&p2);
    t1.AgregarProducto(&p4);

    /// CARGAR OBJETO DINAMICO EN HEAP
    t1.AgregarProducto(p3);

    cout << "MOSTRAR 1" << endl;
    cout << "------------------------------------" << endl;
    t1.MostrarProductos();

    // ERROR
    // t1.EliminarProducto("Jamon");

    // ELIMINACION EXITOSA
    t1.EliminarProducto("Mortadela");

    cout << "MOSTRAR 2" << endl;
    cout << "------------------------------------" << endl;
    t1.MostrarProductos();

    // CARGA MANUAL
    // t1.AgregarProducto();

    cout << "MOSTRAR 3" << endl;
    cout << "------------------------------------" << endl;
    t1.MostrarProductos();

    cout << "------------------------------------" << endl;
    t1.VenderProducto();

    cout << "MOSTRAR 4" << endl;
    cout << "------------------------------------" << endl;
    t1.MostrarProductos();
    t1.VenderProducto();

    return 0;
}