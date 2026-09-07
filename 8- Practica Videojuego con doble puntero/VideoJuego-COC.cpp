// Recreo el videojuego de Clash of Clans con doble puntero y polimorfismo, para poder crear tropas y personajes.

#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <string>

using namespace std;

class Campamento
{
protected:
    int espacio;

public:
    Campamento(int espacio)
    {
        this->espacio = espacio;
    }

    int getEspacio()
    {
        return espacio;
    }
};

class Tropa : public Campamento
{
protected:
    string nombreTropa;

public:
    Tropa(string nombreTropa, int espacio)
        : Campamento(espacio)
    {
        this->nombreTropa = nombreTropa;
    }

    virtual void Presentar()
    {
        cout << "Nombre de la tropa: " << nombreTropa << endl;
        cout << "Espacio que ocupa: " << espacio << endl;
    }

    virtual ~Tropa() {}
};

class Barbaro : public Tropa
{
public:
    Barbaro() : Tropa("Barbaro", 1) {}
};

class Arquera : public Tropa
{
public:
    Arquera() : Tropa("Arquera", 1) {}
};

class Mago : public Tropa
{
public:
    Mago() : Tropa("Mago", 4) {}
};

class Gigante : public Tropa
{
public:
    Gigante() : Tropa("Gigante", 5) {}
};

class Dragon : public Tropa
{
public:
    Dragon() : Tropa("Dragon", 20) {}
};

class Montapuerco : public Tropa
{
public:
    Montapuerco() : Tropa("Montapuerco", 5) {}
};

int main()
{
    setlocale(LC_ALL, "");

    int Campa;
    int opc;

    int espacioTotal;
    int espacioDisponible;
    int tropasCreadas = 0;

    cout << "====================" << endl;
    cout << "   CLASH OF CLANS   " << endl;
    cout << "====================" << endl;
    cout << "\n";

    cout << "Arma tu ejercito para luchar contra las aldeas." << endl;
    cout << "Andando..." << endl;

    while (true)
    {
        cout << "\nCuantos Campamentos tienes? (1-4): ";
        cin >> Campa;

        if (Campa >= 1 && Campa <= 4)
        {
            break;
        }

        cout << "Incorrecto, elija una opcion..." << endl;
    }

    espacioTotal = Campa * 20;
    espacioDisponible = espacioTotal;

    cout << "\nCada campamento tiene 20 de espacio." << endl;
    cout << "En total tienes " << espacioTotal << " de espacio." << endl;

    // Arreglo dinamico
    Tropa **Ejercito = new Tropa *[espacioTotal];

    while (espacioDisponible > 0)
    {
        cout << "\n====================" << endl;
        cout << "Espacio disponible: " << espacioDisponible << endl;
        cout << "====================" << endl;

        cout << "1. Barbaro" << endl;
        cout << "2. Arquera" << endl;
        cout << "3. Mago" << endl;
        cout << "4. Gigante" << endl;
        cout << "5. Dragon" << endl;
        cout << "6. Montapuerco" << endl;
        cout << "0. Terminar ejercito" << endl;

        cout << "Elija una tropa: ";
        cin >> opc;

        Tropa *nuevaTropa = nullptr;

        switch (opc)
        {
        case 1:
            nuevaTropa = new Barbaro();
            break;

        case 2:
            nuevaTropa = new Arquera();
            break;

        case 3:
            nuevaTropa = new Mago();
            break;

        case 4:
            nuevaTropa = new Gigante();
            break;

        case 5:
            nuevaTropa = new Dragon();
            break;

        case 6:
            nuevaTropa = new Montapuerco();
            break;

        case 0:
            cout << "\nTerminaste de armar tu ejercito." << endl;
            espacioDisponible = 0;
            continue;

        default:
            cout << "Opcion invalida." << endl;
            continue;
        }

        // Verificar espacio
        if (nuevaTropa->getEspacio() <= espacioDisponible)
        {
            Ejercito[tropasCreadas] = nuevaTropa;

            espacioDisponible -= nuevaTropa->getEspacio();

            tropasCreadas++;

            cout << "\nTropa creada correctamente." << endl;
        }
        else
        {
            cout << "\nNo hay suficiente espacio para esta tropa." << endl;

            delete nuevaTropa;
        }
    }

    cout << "\n====================" << endl;
    cout << "      EJERCITO       " << endl;
    cout << "====================" << endl;

    for (int i = 0; i < tropasCreadas; i++)
    {
        cout << "\nTropa " << i + 1 << ":" << endl;
        Ejercito[i]->Presentar();
    }

    cout << "\nEspacio utilizado: " << espacioTotal - espacioDisponible << endl;

    cout << "Espacio restante: " << espacioDisponible << endl;

    // Liberar objetos
    for (int i = 0; i < tropasCreadas; i++)
    {
        delete Ejercito[i];
    }

    // Liberar arreglo
    delete[] Ejercito;

    return 0;
}