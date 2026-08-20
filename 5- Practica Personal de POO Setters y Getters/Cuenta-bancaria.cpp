#include <iostream>
#include <string>
#include <cstdlib>
#include <locale.h>
using namespace std;

class CuentaBancaria
{
private:
    int numeroCuenta;
    string titular;
    float saldo;

public:
    CuentaBancaria()
    {
        int numeroCuenta = 0;
        string titular = "";
        float saldo = 0;
    }

    CuentaBancaria(int numeroCuenta, string titular, float saldo)
    {
        this->numeroCuenta = numeroCuenta;
        this->titular = titular;
        this->saldo = saldo;
    }

    // Getters
    int getNumeroCuenta() { return numeroCuenta; }
    string getTitular() { return titular; }
    float getSaldo() { return saldo; }

    // Setters
    void setNumeroCuenta(int n)
    {
        if (n < 0)
        {
            cout << "\n";
            cout << "Número de cuenta no válido." << endl;
        }
        else
        {
            numeroCuenta = n;
        }
    }

    void setTitular(string t)
    {
        if (!t.empty())
        {
            titular = t;
        }
        else
        {
            cout << "\n";
            cout << "El titular no puede estar vacío." << endl;
        }
    }

    void setSaldo(float s)
    {
        if (s < 0)
        {
            cout << "\n";
            cout << "Saldo no válido." << endl;
        }
        else
        {
            saldo = s;
        }
    }

    void depositar(float cantidad)
    {
        if (cantidad < 0)
        {
            cout << "\n";
            cout << "Cantidad no válida." << endl;
        }
        else
        {
            saldo += cantidad;
        }
    }

    void retirar(float cantidad)
    {
        if (cantidad < 0)
        {
            cout << "\n";
            cout << "Cantidad no válida." << endl;
        }
        else
        {
            if (cantidad > saldo)
            {
                cout << "\n";
                cout << "Saldo insuficiente." << endl;
            }
            else
            {
                saldo -= cantidad;
            }
        }
    }
};

int main()
{
    setlocale(LC_ALL, "spanish");

    CuentaBancaria cuenta1(15034, "Elias Tiquicala", 200500);

    cout << "\n";
    cout << "Titular: " << cuenta1.getTitular() << endl;
    cout << "Número de la cuenta: " << cuenta1.getNumeroCuenta() << endl;
    cout << "Saldo: $" << cuenta1.getSaldo() << endl;

    cuenta1.depositar(10000);

    cout << "\n";
    cout << "Ha depositado $10000 a su cuenta." << endl;
    cout << "Nuevo saldo es: $" << cuenta1.getSaldo() << endl;

    cuenta1.retirar(30000);

    cout << "\n";
    cout << "Ha retirado $30000 de su cuenta." << endl;
    cout << "Nuevo saldo es: $" << cuenta1.getSaldo() << endl;

    return 0;
}