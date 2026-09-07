#include <iostream>
#include <cstdlib>
#include <string>
#include <locale.h>
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

int main()
{
    cout << "PERRO: " << endl;
    Perro p1("Firulais");
    p1.Comer();
    p1.Ruido();
    cout << endl;

    cout << "GATO: " << endl;
    Gato g1("Mastodonte");
    g1.Comer();
    g1.Ruido();
    cout << endl;

    cout << "VACA: " << endl;
    Vaca v1("Lola");
    v1.Comer();
    v1.Ruido();
    cout << endl;

    cout << "FATIGA: " << endl;
    Animal *p = new Perro("Fatiga");
    p->Comer();
    p->Ruido();

    cout << "JOAQUINA: " << endl;
    Animal *v = new Vaca("Joaquina");
    v->Comer();
    v->Ruido();

    cout << endl;
    cout << endl;

    Animal *pa[3];

    pa[0] = new Perro("Betun");
    pa[1] = new Gato("Garfield");
    pa[2] = new Vaca("Otis");

    cout << "ARREGLO DE ANIMALES" << endl;
    pa[0]->Ruido();
    pa[1]->Ruido();
    pa[2]->Ruido();
    cout << "ARREGLO DE ANIMALES" << endl;
    cout << endl;
    cout << endl;

    return 0;
}
