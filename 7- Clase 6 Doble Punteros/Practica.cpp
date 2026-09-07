/*
PRACTICA CON PUNTEROS DOBLES Y ARREGLOS DINAMICOS DE OBJETOS.
Usando el codigo de la clase anterior con las clases (ANIMAL, perro, gato, vaca, cerdo y Pato)
Asignar los animales a punteros y crear un arreglo.

Consigna: Que el programa pida cuantos animales hay en el arreglo, osea que el usuario ingrese el tamaño del arreglo
que pregunte: cuantos animales? y en base a la respuesta que se muestre un menu con los animales y al elejir uno que se ejecuten sus funciones (ruido y comer)
*/

#include <iostream>
#include <random>
using namespace std;

class Animal
{
protected:
    string nombre;
    string nombreAnimal;

public:
    // CONSTRUCTOR
    Animal(string n)
    {
        nombre = n;
    }

    // GETTERS
    virtual string getNombre() { return nombreAnimal; }

    // METODOS
    void Comer()
    {
        cout << nombre << " esta comiendo" << endl;
    }

    virtual void Ruido() = 0; // METODO VIRTUAL PURO;

    // DESTRUCTOR
    virtual ~Animal() {}
};

class Perro : public Animal
{
private:
    string nombreAnimal = "Perro";

public:
    Perro(string n) : Animal(n) {}

    // GETTERS
    virtual string getNombre() { return nombreAnimal; }

    void Ruido()
    {
        cout << "Guau" << endl;
    }

    ~Perro() {}
};

class Gato : public Animal
{
private:
    string nombreAnimal = "Gato";

public:
    Gato(string n) : Animal(n) {}

    // GETTERS
    virtual string getNombre() { return nombreAnimal; }

    void Ruido()
    {
        cout << "Miau" << endl;
    }

    ~Gato() {}
};

class Vaca : public Animal
{
private:
    string nombreAnimal = "Vaca";

public:
    Vaca(string n) : Animal(n) {}

    // GETTERS
    virtual string getNombre() { return nombreAnimal; }

    void Ruido()
    {
        cout << "Muu" << endl;
    }

    ~Vaca() {}
};

class Cerdo : public Animal
{
private:
    string nombreAnimal = "Cerdo";

public:
    Cerdo(string n) : Animal(n) {}

    // GETTERS
    virtual string getNombre() { return nombreAnimal; }

    void Ruido()
    {
        cout << "oink" << endl;
    }

    ~Cerdo() {}
};

class Pato : public Animal
{
private:
    string nombreAnimal = "Pato";

public:
    Pato(string n) : Animal(n) {}

    // GETTERS
    virtual string getNombre() { return nombreAnimal; }

    void Ruido()
    {
        cout << "Cuack" << endl;
    }

    ~Pato() {}
};

int main()
{

    int cantidad;
    int opAnimal;

    while (true)
    {
        cout << "INGRESE LA CANTIDAD DE ANIMALES (1-5): ";
        cin >> cantidad;

        if (cantidad < 1 || cantidad > 5)
        {
            cout << "Error... Solo de 1 a 5" << endl;
            cout << "\n";
            continue;
        }
        else
        {
            break;
        }
    }

    Animal **zoo = new Animal *[cantidad];

    zoo[0] = new Perro("Firulais");
    zoo[1] = new Gato("Garfield");
    zoo[2] = new Vaca("Lola");
    zoo[3] = new Cerdo("Peppa");
    zoo[4] = new Pato("Donald");

    for (int i = 0; i < cantidad; i++)
    {
        cin.ignore();
        cout << "\n";
        cout << i + 1 << ". SELECCIONE UN ANIMAL (0 para salir):" << endl;
        cout << "1. Perro" << endl;
        cout << "2. Gato" << endl;
        cout << "3. Vaca" << endl;
        cout << "4. Cerdo" << endl;
        cout << "5. Pato" << endl;
        cout << "Tu opcion es: ";
        cin >> opAnimal;
        cout << endl;

        if (opAnimal == 1)
        {
            zoo[0]->Comer();
            zoo[0]->Ruido();
            cout << endl;
        }
        else if (opAnimal == 2)
        {
            zoo[1]->Comer();
            zoo[1]->Ruido();
            cout << endl;
        }
        else if (opAnimal == 3)
        {
            zoo[2]->Comer();
            zoo[2]->Ruido();
            cout << endl;
        }
        else if (opAnimal == 4)
        {
            zoo[3]->Comer();
            zoo[3]->Ruido();
            cout << endl;
        }
        else if (opAnimal == 5)
        {
            zoo[4]->Comer();
            zoo[4]->Ruido();
            cout << endl;
        }
        else if (opAnimal < 0 || opAnimal > 5)
        {
            cout << "Error, intente nuevamente..." << endl;
            i--;
        }
    }

    for (int i = 0; i < cantidad; i++)
    {
        delete zoo[i];
    }

    delete[] zoo;

    return 0;
}