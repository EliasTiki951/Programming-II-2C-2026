// Crear un videoJuego de con un clase Persona con su nombre y vida;
// y una clase Arma con su nombre, daño y ataque.
// El juego debe permitir crear un personaje y un arma, y luego atacar al personaje con el arma,
// reduciendo su vida en la cantidad de daño del arma.

#include <iostream>
#include <cstdlib>
using namespace std;

class Arma
{
private:
    string nombre;
    int ataque;

public:
    /// CONSTRUCTOR
    Arma(string n, int a)
    {
        nombre = n;
        ataque = a;
    }

    Arma()
    {
        nombre = "Sin nombre";
        ataque = 0;
    }

    /// SETTERS
    void setNombre(string n) { nombre = n; }
    void setAtaque(int a) { ataque = a; }

    /// GETTERS
    string getNombre() { return nombre; }
    int getAtaque() { return ataque; }

    /// METODOS
    void MostrarInfo()
    {
        cout << "\nInformacion de " << nombre << ":" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Ataque: " << ataque << endl;
    }
};

class Persona
{
private:
    string nombre;
    int vida;
    Arma arma;

public:
    /// CONSTRUCTORES
    Persona(string n, int v, Arma a)
    {
        nombre = n;
        vida = v;
        arma = a;
    }

    Persona()
    {
        nombre = "Sin nombre";
        vida = 0;
    }

    /// SETTERS
    void setNombre(string n) { nombre = n; }
    void setVida(int v) { vida = v; }

    /// GETTERS
    string getNombre() { return nombre; }
    int getVida() { return vida; }

    /// METODOS
    void MostrarInfo()
    {
        cout << "\nInformacion de " << nombre << ":" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Vida: " << vida << endl;
        cout << "Arma: " << endl;
        arma.MostrarInfo();

        if (EstaVivo())
        {
            cout << nombre << " Esta vivo" << endl;
        }
        else
        {
            cout << nombre << " Esta Muerto" << endl;
        }
    }

    int CalcularDanio()
    {
        int atq = arma.getAtaque();
        return atq;
    }

    void RecibirDanio(int dmg)
    {
        vida -= dmg;
        if (vida < 0)
        {
            vida = 0;
        }
    }

    void Atacar(Persona *obj)
    {
        int atq = CalcularDanio();
        obj->RecibirDanio(atq);

        cout << nombre << " Ataco a " << obj->getNombre() << " haciendole perder " << atq << " puntos de vida.\n";
        cout << "Vida restante de " << nombre << ": " << vida << endl;
        cout << "Vida restante de " << obj->getNombre() << ": " << obj->getVida() << endl;
        cout << endl;
    }

    bool EstaVivo()
    {
        return vida > 0;
    }
};

void Pelea(Persona *p1, Persona *p2)
{
    while (p1->EstaVivo() && p2->EstaVivo())
    {
        p1->Atacar(p2);
        if (p2->EstaVivo())
        {
            p2->Atacar(p1);
        }
    }

    cout << "Fin de la Pelea." << endl;
    if (p1->EstaVivo())
    {
        cout << p1->getNombre() << " es el ganador" << endl;
    }
    else
    {
        cout << p2->getNombre() << " es el ganador" << endl;
    }
}

int main()
{

    Arma a1("Palo", 15);
    Persona p1("Andres", 100, a1);
    Persona p2("Flavio", 200, Arma("Cuchillo", 50));

    Pelea(&p1, &p2);

    return 0;
}