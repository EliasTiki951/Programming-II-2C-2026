#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;

void Limpiar()
{
#if defined(_WIN32)
    system("cls");
#elif defined(_linux) // ← Corregido: __linux_ (dos guiones bajos)
    system("clear");
#else
    std::cout << "Sistema operativo: Desconocido" << std::endl;
#endif
}

void Pausa()
{
#if defined(_WIN32)
    std::cout << "\nPresione Enter para continuar..." << std::endl;
    system("pause");
#elif defined(_linux_)
    std::cout << "\nPresione Enter para continuar..." << std::endl;
    cin.get();
    cin.ignore(100, '\n');
#else
    std::cout << "Sistema operativo: Desconocido" << std::endl;
#endif
}

string escritorio = "C:\\Users\\wwwel\\OneDrive\\Escritorio\\";

int main()
{
    // 1
    /*
    string filename = escritorio + "prueba.txt";

    ofstream archivo(filename);

    archivo << "Hola Mundo" << endl;
    */

    // 2
    /*
    string filename = escritorio + "Script.py";

    ofstream archivo(filename);

    archivo << "print(Hola Mundo)" << endl;
    */

    // 3
    /*
    string nombre;
    string filename = escritorio + "prueba.txt";

    // Ofstream es para cargar archivos
    ofstream archivo(filename, ios::app);
    // ios::app es para poder poner por debajo de lo que hay en el archivo

    for (int i = 0; i < 3; i++)
    {
        cout << "Nombre: ";
        cin >> nombre;

        archivo << nombre << endl;
    }

    // Ifstream es para leer el archivo.
    ifstream arch(filename);

    while (arch >> nombre)
    {
        cout << nombre << endl;
    }

    filesystem::create_directory(escritorio + "Carpeta_c++");
    //filesystem::create_directory = Sirve para crear carpeta.

    arch.close();
    archivo.close();
    */

    string nombre, apellido, carrera;
    int edad;
    string filename = escritorio + "prueba.txt";

    // fstream es de Lectura y Escritura
    fstream archivo(filename, ios::in | ios::out | ios::app);
    // ios::app = Significa "append" (añadir o adjuntar).
    // Todo lo que escribas en él se agregará al final del documento,
    // conservando intacto todo el contenido que ya existía previamente.

    // ios::in = Abre el archivo en modo lectura (Input).
    // ios::out = Abre el archivo en modo escritura (Output).

    // ios::trunc = Trunca el archivo. Si "prueba.txt" ya existía y tenía texto adentro,
    // lo borra por completo al abrirlo para empezar desde cero.

    /*
    for (int i = 0; i < 4; i++)
    {
        cout << "Nombre: ";
        getline(cin, nombre);
        cout << "Apellido: ";
        getline(cin, apellido);
        cout << "Edad: ";
        cin >> edad;
        cin.ignore();
        cout << "Carrera: ";
        getline(cin, carrera);
        cout << "\n";

        archivo << nombre << ";" << apellido << ";" << edad << ";" << carrera << endl;
    }
    cout << endl;
    */
    // LECTURA
    archivo.seekg(0);
    // archivo.seekg(0) = Sirve para mover el "cursor" de lectura de tu archivo de regreso al principio.
    // Seekg viene del inglés "seek" (buscar/posicionar) y la "g" final viene de "get" (obtener/leer).
    // Básicamente le dice al programa = "Posiciona el cursor de lectura en...".
    // El (0) Representa el byte 0, es decir, el inicio absoluto del archivo.
    while (getline(archivo, nombre, ';'))
    {
        getline(archivo, apellido, ';');
        archivo >> edad;
        archivo.ignore();
        getline(archivo, carrera);

        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Edad: " << edad << endl;
        cout << "Carrera: " << carrera << endl;
        cout << "\n";
    }

    filesystem::create_directories(escritorio + "DIR-1/DIR-2");
    // filesystem::create_directories = Sirve para crear carpetas

    return 1;
}