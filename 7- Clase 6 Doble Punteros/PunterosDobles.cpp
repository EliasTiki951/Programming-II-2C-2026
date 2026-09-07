#include <iostream>
#include <random>

using namespace std;

class Animal
{
protected:
    string nombre;

public:
    // CONSTRUCTOR
    Animal(string n)
    {
        nombre = n;
        cout << "Constructor de la clase Animal" << endl;
    }

    // METODOS

    void Comer()
    {
        cout << nombre << " esta comiendo" << endl;
    }

    virtual void Ruido() = 0; // METODO VIRTUAL PURO;

    // DESTRUCTOR
    virtual ~Animal()
    {
        cout << "Destructor de la clase Animal" << endl;
    }
};

class Perro : public Animal
{
public:
    Perro(string n) : Animal(n)
    {
        cout << "Constructor de la clase Perro" << endl;
    }

    void Ruido()
    {
        cout << "Guau" << endl;
    }

    ~Perro()
    {
        cout << "Destructor de la clase Perro" << endl;
    }
};

class Gato : public Animal
{
public:
    Gato(string n) : Animal(n)
    {
        cout << "Constructor de la clase Gato" << endl;
    }

    void Ruido()
    {
        cout << "Miau" << endl;
    }

    ~Gato()
    {
        cout << "Destructor de la clase Gato" << endl;
    }
};

class Vaca : public Animal
{
public:
    Vaca(string n) : Animal(n)
    {
        cout << "Constructor de la clase Vaca" << endl;
    }

    void Ruido()
    {
        cout << "Muu" << endl;
    }

    ~Vaca()
    {
        cout << "Destructor de la clase Vaca" << endl;
    }
};

// CLASE PERSONA PARA EL ARREGLO
class Persona
{
private:
    string nombre;

public:
    Persona(string n) { nombre = n; }

    void Presentar() { cout << "Hola, mi nombre es " << nombre << endl; }
};

int main()
{
    /*
    Persona p1("Juan");

    Persona arr[3] = {Persona("Pedro"), Persona("Marcos"), Persona("Lucas")}; // Arreglo

    arr[0].Presentar();

    for (int i = 0; i < 3; i++)
    {
        arr[i].Presentar();
    }

    p1.Presentar();

    cout << endl;

    int a = 100;
    int *p = &a;
    // Un puntero doble almacena la direccion de memoria de otro puntero.
    int **dp = &p;

    cout << "A: " << a << endl;       // muestra el valor de A
    cout << "$A: " << &a << endl;     // muestra la direccion en memoria de A
    cout << "P: " << p << endl;       // muestra la direccion de memoria de A
    cout << "*P: " << *p << endl;     // muestra el valor de A
    cout << "&P: " << &p << endl;     // muestra la direccion de memoria de P
    cout << "DP: " << dp << endl;     // muestra la direccion de memoria de P
    cout << "*DP: " << *dp << endl;   // muestra el valor de P, que es la direccion de A
    cout << "**DP: " << **dp << endl; // muestra el valor de A al desreferenciar dos veces

    cout << endl;
    */

    // ARREGLO DE OBJETO DIANMICO

    Persona *p1 = nullptr;
    p1 = new Persona("Miguel");
    p1->Presentar();
    delete p1;

    Persona **Jugadores = new Persona *[3];

    Jugadores[0] = new Persona("Kevin");
    Jugadores[1] = new Persona("Maxi");
    Jugadores[2] = new Persona("Rodri");

    for (int i = 0; i < 3; i++)
    {
        Jugadores[i]->Presentar();
    }

    // LIBERAMOS MEMORIA (PRIMERO BORRO LOS ELEMENTOS CON FOR Y DESPUES BORRO EL ARREGLO)
    for (int i = 0; i < 3; i++)
    {
        delete Jugadores[i];
    }

    delete[] Jugadores;

    return 0;
}
