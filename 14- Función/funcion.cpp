/*
1) CREAR UN ARCHIVO QUE REGISTRE PRODUCTOS, STOCK Y PRECIO (NOMBRE, PRECIO, STOCK/CANTIDAD).
CREAR FUNCION CARGARDATOS Y OTRA PARA VER DATOS
2) QUE ANALICE Y DEVUELVA TOTAL FACTURADO, PRODUCTO MAS CARO, PRODUCTO MAS BARATO,
PRODUCTO CON STOCK CRITICO (10 UNIDADES), PRODUCTO CON MAYOR IMPORTE Y PRODUCTO CON MENOR IMPORTE
*/

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
    int cant;
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

void Informe(fstream &archivo)
{
    cout << "\n--- INFORME ---" << endl;
    string nom, nommayor, nommenor;
    int cant;
    float pre, importe = 0, total = 0, mayorimporte = 0, menorimporte = 0;

    archivo.clear();
    archivo.seekg(0); // Volvemos al inicio del documento
    while (getline(archivo, nom, ';'))
    {
        archivo >> cant;
        archivo.ignore();
        archivo >> pre;
        archivo.ignore();

        importe = cant * pre;
        total += importe;

        if (importe > mayorimporte)
        {
            mayorimporte = importe;
            nommayor = nom;
        }

        if (menorimporte == 0 || importe < menorimporte)
        {
            menorimporte = importe;
            nommenor = nom;
        }

        cout << "Nombre: " << nom << endl;
        cout << "Cantidad vendida: " << cant << endl;
        cout << "Precio: $" << pre << endl;
        cout << "Importe: $" << importe << endl;
        cout << "\n";
    }

    cout << "Total facturado: $" << total << endl;
    cout << "Producto más caro: " << nommayor << " ($" << mayorimporte << ")" << endl;
    cout << "Producto más barato: " << nommenor << " ($" << menorimporte << ")" << endl;
}

int main()
{
    setlocale(LC_ALL, "spanish");

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
        cout << "Ingrese cantidad vendida: ";
        cin >> cant;
        cout << "Ingrese precio: ";
        cin >> pre;
        cout << "\n";

        archivo << nom << ";" << cant << ";" << pre << endl;
    }

    ContenidoFinal(archivo);

    Informe(archivo);

    archivo.close();

    return 0;
}