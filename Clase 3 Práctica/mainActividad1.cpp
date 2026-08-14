/*
1) Crear uan clase Persona y una clase alumno que herede los
atributos de Persona, lo cual Persona tiene en privado los atributos de
Nombre, Apellido y Edad.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <locale.h>
using namespace std;
/*
    P.O.O.: Programación Orientada a Objetos
    Encapsulamiento
    Abstracción
    Herencia
    Polimorfismo

    CLASES
    ATRIBUTOS

*/

class Persona
{
private:
    string Nombre;
    string Apellido;
    int Edad;

public:
    Persona(string n, string a, int e)
    {
        this->Nombre = n;
        this->Apellido = a;
        this->Edad = e;
    }
    Persona() = default;

    string getNombre() { return Nombre; }
    string getApellido() { return Apellido; }
    int getEdad() { return Edad; }

    void Presentar()
    {
        cout << "Ingrese Nombre Completo: ";
        getline(cin, Nombre);
        cout << "Ingrese Apellido Completo: ";
        getline(cin, Apellido);
        cout << "Ingrese Edad: ";
        cin >> Edad;
    }
};

class Alumno : public Persona
{
private:
    int Legajo;
    string Carrera;
    string Materias[4];

public:
    int getLegajo() { return Legajo; }
    string getCarrera() { return Carrera; }
    string getMaterias()
    {
        string resultado;
        for (int i = 0; i < 4; i++)
            resultado += Materias[i] + "\n";
        return resultado;
    }
    // string getMaterias() { return Materias; }

    Alumno(int l, string c, string m[])
    {
        this->Legajo = l;
        this->Carrera = c;
        for (int i = 0; i < 4; i++)
        {
            this->Materias[i] = m[i];
        }
    }
    Alumno() = default;

    void Presentar()
    {
        Persona::Presentar();
        cin.ignore();
        cout << "Que carrera estas cursando? ";
        getline(cin, Carrera);
        cout << "Cual es tu legajo? ";
        cin >> Legajo;
        cout << "Cuales son las materias que estas cursando? ";
        cin.ignore();
        for (int i = 0; i < 4; i++)
        {
            cout << "- ";
            getline(cin, Materias[i]);
        }

        cout << "\n";
        cout << "Sos " << getNombre() << " " << getApellido() << " tienes " << getEdad() << " años." << endl;
        cout << "Sos alumno de la carrera de " << getCarrera() << " y tu legajo es " << getLegajo() << "." << endl;
        cout << "\n";
        cout << "Las Materias que estas cursando son: " << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << "- " << Materias[i] << endl;
        }
        cout << "\n";
    }
};

int main()
{
    setlocale(LC_ALL, "spanish");

    Alumno a1, a2;
    a1.Presentar();
    a2.Presentar();

    return 0;
}