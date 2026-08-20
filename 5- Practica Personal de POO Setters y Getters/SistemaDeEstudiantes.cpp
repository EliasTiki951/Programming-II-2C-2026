#include <iostream>
#include <string>
#include <cstdlib>
#include <locale.h>
using namespace std;

class Estudiante
{
private:
    string Nombre;
    int Edad;
    float Promedio;

public:
    // Usar el constructor por defecto y el constructor con parÃ¡metros se llama sobrecarga de constructores.

    Estudiante() // Constructor por defecto
    {
        Nombre = "";
        Edad = 0;
        Promedio = 0;
    }

    Estudiante(string nombre, int edad, float promedio) // Constructor con parÃ¡metros
    {
        this->Nombre = nombre;
        this->Edad = edad;
        this->Promedio = promedio;
    }

    // Getters: Es de Obtener
    string getNombre() { return Nombre; }
    int getEdad() { return Edad; }
    float getPromedio() { return Promedio; }

    // Setters: Mofidica + Validar
    void setNombre(string n)
    {
        if (!n.empty()) // empty() es una función de string que nos permite preguntar si el texto está vacío.
        {
            Nombre = n;
        }
        else
        {
            cout << "\n";
            cout << "El nombre no puede estar vacío." << endl;
        }
    }
    void setEdad(int e)
    {
        if (e >= 0 && e <= 120)
        {
            Edad = e;
        }
        else
        {
            cout << "\n";
            cout << "Edad no válida." << endl;
        }
    }
    void setPromedio(float p)
    {
        if (p >= 0 && p <= 10)
        {
            Promedio = p;
        }
        else
        {
            cout << "\n";
            cout << "Promedio no válido." << endl;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "spanish");

    // Estudiante estud1("Elias", 23, 9.5);

    Estudiante estud1;

    estud1.setNombre("Elias");
    estud1.setEdad(23);
    estud1.setPromedio(9.5);

    cout << "\n";
    cout << "Nombre: " << estud1.getNombre() << endl;
    cout << "Edad: " << estud1.getEdad() << endl;
    cout << "Promedio: " << estud1.getPromedio() << endl;

    return 0;
}