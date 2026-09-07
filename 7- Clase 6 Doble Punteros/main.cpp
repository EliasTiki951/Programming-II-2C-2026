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
        // cout<<"Constructor de la clase Animal"<<endl;
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
        // cout<<"Destructor de la clase Animal"<<endl;
    }
};

class Perro : public Animal
{
public:
    Perro(string n) : Animal(n)
    {
        // cout<<"Constructor de la clase Perro"<<endl;
    }

    void Ruido()
    {
        cout << "Guau" << endl;
    }

    ~Perro()
    {
        // cout<<"Destructor de la clase Perro"<<endl;
    }
};

class Gato : public Animal
{
public:
    Gato(string n) : Animal(n)
    {
        // cout<<"Constructor de la clase Gato"<<endl;
    }

    void Ruido()
    {
        cout << "Miau" << endl;
    }

    ~Gato()
    {
        // cout<<"Destructor de la clase Gato"<<endl;
    }
};

class Vaca : public Animal
{
public:
    Vaca(string n) : Animal(n)
    {
        // cout<<"Constructor de la clase Vaca"<<endl;
    }

    void Ruido()
    {
        cout << "Muu" << endl;
    }

    ~Vaca()
    {
        // cout<<"Destructor de la clase Vaca"<<endl;
    }
};

class Persona
{
private:
    string nombre;

public:
    Persona(string n) { nombre = n; }

    void Presentar()
    {
        cout << "Hola, soy " << nombre << endl;
    }
};

/// ACA ESTA LA EXPLICACION SOBRE LOS PUNTEROS
void Guardar()
{
    int a = 100;
    int *p = &a;
    int **dp = &p;
    int ***tp = &dp;

    cout << " A: " << a << endl;
    cout << "&A: " << &a << endl;
    cout << " P: " << p << endl;
    cout << "*P: " << *p << endl;
    cout << "&P: " << &p << endl;
    cout << "DP: " << dp << endl;
    cout << "*DP: " << *dp << endl;
    cout << "**DP: " << **dp << endl;
    cout << "***DP: " << ***tp << endl;
}

int main()
{

    Persona **Jugadores = new Persona *[3];

    Jugadores[0] = new Persona("Kevin");
    Jugadores[1] = new Persona("Maximiliano");
    Jugadores[2] = new Persona("Rodrigo");

    for (int i = 0; i < 3; i++)
    {
        Jugadores[i]->Presentar();
    }

    for (int i = 0; i < 3; i++)
    {
        delete Jugadores[i];
    }

    delete[] Jugadores;

    cout << "\n";

    Guardar();

    return 0;
}