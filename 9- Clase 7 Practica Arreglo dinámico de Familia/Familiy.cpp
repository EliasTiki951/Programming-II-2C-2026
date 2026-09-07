/*
Crear uan clase Persona para cargar toda la familia y poder presentarlo y saber si estudia o no.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <locale.h>
using namespace std;

class Persona
{
private:
    string Nombre;
    string Apellido;
    int Edad;

public:
    // Constructor
    Persona(string n, string a, int e)
    {
        Nombre = n;
        Apellido = a;
        Edad = e;
    }

    // Setters
    // void setNombre(string n) { this->Nombre = n; }
    // void setApellido(string a) { this->Apellido = a; }
    // void setEdad(int e) { this->Edad = e; }

    // Getters
    // string getNombre() { return this->Nombre; }
    // string getApellido() { return this->Apellido; }
    // int getEdad() { return this->Edad; }

    virtual void Presentar()
    {
        cout << "\n";
        cout << "Hola, me llamo " << Nombre << " " << Apellido << " y tengo " << Edad << " años." << endl;
    }
};

class Estudiante : public Persona
{
public:
    // ATRIBUTOS
    string carrera;
    int Legajo;

    // CONSTRUCTOR
    Estudiante(string n, string a, int e, string c, int l) : Persona(n, a, e)
    {
        this->carrera = c;
        this->Legajo = l;
    }

    void Presentar() override
    {
        Persona::Presentar(); // Llamar al método Presentar de la clase base
        cout << "Estudio " << carrera << " y mi legajo es " << Legajo << "." << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    int tam, edad, estu, legajo;
    string nombre, apellido, universidad, carrera;

    // VOY A AGREGAR LA CANTIDAD DE PERSONAS QUE VOY A GUARDAR EN EL ARRAY DINÁMICO
    cout << "Ingrese cuantos son en tu familia: ";
    cin >> tam;
    cin.ignore(); // Limpiar el buffer de entrada

    Persona **Familia = new Persona *[tam];
    //**Doble puntero apunta a un nuevo puntero.
    // En este caso puedo guardar varios objetos de la clase Persona en un array dinámico.
    // Persona *P = New Persona(); se puede guardar un solo objeto.

    for (int i = 0; i < tam; i++)
    {
        cout << "FAMILIAR " << i + 1 << endl;
        cout << "Ingrese el nombre: ";
        getline(cin, nombre);
        cout << "Ingrese el apellido: ";
        getline(cin, apellido);
        cout << "Ingrese la edad: ";
        cin >> edad;
        cout << "Estudias? (1: Si, 0: No): ";
        cin >> estu;
        if (estu == 1)
        {
            cin.ignore(); // Limpiar el buffer de entrada
            cout << "Ingrese la carrera: ";
            getline(cin, carrera);
            cout << "Ingrese el número de legajo: ";
            cin >> legajo;
            Familia[i] = new Estudiante(nombre, apellido, edad, carrera, legajo);
        }
        else
        {
            Familia[i] = new Persona(nombre, apellido, edad);
        }
        cin.ignore(); // Limpiar el buffer de entrada
        cout << "\n";

        // SE VAN A ALMACENAR EN EL ARRAY DINÁMICO LOS OBJETOS DE LA CLASE PERSONA
        // Familia[i] = new Persona(nombre, apellido, edad);
    }

    // USAMOS EL METODO CON TODO LOS OBJETOS CREADOS EN EL ARRAY DINÁMICO
    for (int i = 0; i < tam; i++)
    {
        Familia[i]->Presentar();
    }

    // VOY A BORRAR LA MEMORIA DE CADA OBJETO CREADO DEL ARRAY DINÁMICO, PARA EVITAR FUGAS DE MEMORIA
    for (int i = 0; i < tam; i++)
    {
        delete Familia[i]; // Liberar memoria de cada objeto Persona
    }

    delete[] Familia; // Liberar memoria del array dinámico

    return 0;
}