#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

// system("cls"); Limpiar pantalla
// system("pause"); Pausar pantalla

/*
void UsarArchivo(fstream &archivo)
{
    string texto;
    archivo << "Texto escrito desde funcion" << endl;

    archivo.seekg(0);
    while (getline(archivo, texto))
    {
        cout << texto << endl;
    }
}
*/

void ContenidoFinal(fstream &archivo)
{
    cout << "\n--- CONTENIDO TOTAL DEL ARCHIVO ---" << endl;
    string nom;
    int cant, pro;
    float pre;

    archivo.clear();
    archivo.seekg(0); // Volvemos al inicio del documento

    while (getline(archivo, nom, ';'))
    {
        archivo >> cant;
        archivo.ignore();
        archivo >> pre;
        archivo.ignore();

        cout << "Nombre: " << nom << endl;
        cout << "Cantidad: " << cant << endl;
        cout << "Precio: $" << pre << endl;
        cout << "\n";
    }
}

void MayorValor(fstream &archivo)
{
    cout << "\n--- PRODUCTO CON MAYOR VALOR ---" << endl;
}

int main()
{
    string nom;
    int cant, pro;
    float pre;

    fstream archivo("C:\\Users\\wwwel\\OneDrive\\Escritorio\\Ejemplo.txt", ios::in | ios::out | ios::trunc);

    archivo.clear();

    cout << "===========" << endl;
    cout << "  INFORME  " << endl;
    cout << "===========" << endl;
    cout << "\n";

    cout << " Cuantos productos desea ingresar: ";
    cin >> pro;
    cout << "\n";
    cin.ignore(); // Limpiar el buffer

    for (int i = 0; i < pro; i++)
    {
        cout << i + 1 << ". Ingrese nombre del producto: ";
        getline(cin >> ws, nom);
        archivo.clear();
        // ws= Significa "whitespace" (espacios en blanco)
        cout << "Ingrese cantidad: ";
        cin >> cant;
        cout << "Ingrese precio: ";
        cin >> pre;
        cout << "\n";

        archivo << nom << ";" << cant << ";" << pre << endl;
    }

    ContenidoFinal(archivo);

    archivo.close();

    return 0;
}