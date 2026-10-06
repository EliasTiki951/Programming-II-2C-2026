/*
Practica Personal:
Dato:
class Persona
string nombre;
string apellido;
int edad;

Crear un método que cargue dentro de un archivo de texto la información de varias personas,
a su vez, este método debe crear el archivo dentro de la una carpeta
*/

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
using namespace std;

string escritorio = "C:\\Users\\wwwel\\OneDrive\\Escritorio\\";

class Persona
{
protected:
    string nombre;
    string apellido;
    int edad;

public:
    Persona(string n, string a, int e)
    {
        this->nombre = n;
        this->apellido = a;
        this->edad = e;
    }

    void guardarEnArchivo()
    {
        // Crear el archivo dentro de la carpeta
        ofstream archivo("C:\\Users\\wwwel\\OneDrive\\Escritorio\\datos\\persona.txt", ios::app);
        string filename = escritorio + "datos\\persona.txt";
        if (archivo.is_open())
        {
            fstream archivo(filename, ios::app);
            archivo << "Nombre: " << nombre << endl;
            archivo << "Apellido: " << apellido << endl;
            archivo << "Edad: " << edad << endl;
            cout << "\n";
            archivo.close();
            cout << "Info guardada" << endl;
            cout << "\n";
        }
        else
        {
            cout << "Info no guardada." << endl;
        }
    }
};

int main()
{
    string nombre, apellido;
    int edad, cant;

    filesystem::create_directory(escritorio + "datos");

    cout << "============" << endl;
    cout << "  REGISTRO  " << endl;
    cout << "============" << endl;
    cout << "\n";

    cout << "Cuantas personas desea registrar? ";
    cin >> cant;
    cout << "\n";
    cin.ignore(); // Limpiar el buffer de entrada

    for (int i = 0; i < cant; i++)
    {
        cout << "Persona " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        getline(cin, nombre);
        cout << "Apellido: ";
        getline(cin, apellido);
        cout << "Edad: ";
        cin >> edad;
        cin.ignore(); // Limpiar el buffer de entrada

        Persona p1(nombre, apellido, edad);
        p1.guardarEnArchivo();
    }

    return 0;
}