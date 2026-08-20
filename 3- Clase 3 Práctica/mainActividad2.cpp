/*
2) Crear una clase Comida y sos atributos que sean Nombre, precio y stock
y los MÃ©todos comer, cocinar, vender.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <locale.h>
using namespace std;

class Comida
{
private:
    string Nombre;
    double Precio;
    int Stock;

public:
    Comida(string n, double p, int s)
    {
        this->Nombre = n;
        this->Precio = p;
        this->Stock = s;
    }
    Comida() = default;

    string getNombre() { return Nombre; }
    double getPrecio() { return Precio; }
    int getStock() { return Stock; }

    bool modificarStock(int cantidad)
    {
        if ((Stock + cantidad) >= 0)
        {
            Stock += cantidad;
            return true;
        }
        else
        {
            cout << "No hay suficiente stock." << endl;
            return false;
        }
    }
};

class Hamburguesa : public Comida
{
private:
    int Vendidos = 0;
    long double Recaudacion = 0;

public:
    Hamburguesa(string n, double p, int s, int v, double r) : Comida(n, p, s)
    {
        this->Vendidos = v;
        this->Recaudacion = r;
    }
    Hamburguesa() = default;

    int getVendidos() { return Vendidos; }
    long double getRecaudacion() { return Recaudacion; }

    void calculoDeVenta(int cantidad)
    {
        Vendidos += cantidad;
        Recaudacion += cantidad * getPrecio();
    }

    void cocinar(int cantidad) { modificarStock(cantidad); }
    void comer(int cantidad) { modificarStock(-cantidad); }
    void vender(int cantidad)
    {
        if (modificarStock(-cantidad))
        {
            calculoDeVenta(cantidad);
        }
    }
};

int main()
{
    setlocale(LC_ALL, "spanish");

    int Opc, Coci, Come, Vende;

    Hamburguesa hambur1("Hamburguesa Triple", 20000, 1000, 0, 0);

    while (true)
    {
        cout << "==========" << endl;
        cout << "   MENÚ   " << endl;
        cout << "==========" << endl;
        cout << "\n";
        cout << "1. Ver todo el Menú" << endl;
        cout << "2. Cocinar" << endl;
        cout << "3. Comer" << endl;
        cout << "4. Vender" << endl;
        cout << "5. Salir" << endl;
        cin >> Opc;
        switch (Opc)
        {
        case 1:
            cout << "\n";
            cout << "Nombre: " << hambur1.getNombre() << endl;
            cout << "Precio: $" << hambur1.getPrecio() << endl;
            cout << "Stock: " << hambur1.getStock() << endl;
            cout << "Vendidos: " << hambur1.getVendidos() << endl;
            cout << "Recaudación: $" << hambur1.getRecaudacion() << endl;
            cout << "\n";
            continue;
        case 2:
            cout << "\n";
            cout << "Cuanto desea cocinar? ";
            cin >> Coci;
            hambur1.cocinar(Coci);
            cout << "\n";
            continue;
        case 3:
            cout << "\n";
            cout << "Cuanto desea comer? ";
            cin >> Come;
            hambur1.comer(Come);
            cout << "\n";
            continue;
        case 4:
            cout << "\n";
            cout << "Cuanto desea vender? ";
            cin >> Vende;
            hambur1.vender(Vende);
            cout << "\n";
            continue;
        case 5:
            cout << "Saliendo..." << endl;
            return 0;
        default:
            cout << "\n";
            cout << "Elija otra opción..." << endl;
            cout << "\n";
            continue;
        }
    }

    return 0;
}