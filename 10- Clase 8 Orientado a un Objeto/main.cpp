#include <iostream>
#include <cstdlib>
using namespace std;

class objeto
{
private:
    string nombre;
    int valor;

public:
    // Con parámetros
    objeto(string n, int v)
    {
        nombre = n;
        valor = v;
    }

    // Sin parámetros
    objeto()
    {
        nombre = "Sin Nombre";
        valor = 0;
    }

    // Setters
    void setNombre(string n) { nombre = n; }
    void setValor(int v) { valor = v; }

    // Getters
    string getNombre() { return nombre; }
    int getValor() { return valor; }

    void mostrarInfo()
    {
        cout << "\nInformacion del objeto: " << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Valor: " << valor << endl;
    }
};

class Persona
{
private:
    string nombre;
    int edad;
    objeto obj;

public:
    Persona(string n, int e, objeto o)
    {
        nombre = n;
        edad = e;
        obj = o;
    }

    Persona(string n, int e)
    {
        nombre = n;
        edad = e;
    }

    Persona()
    {
        nombre = "Sin Nombre";
        edad = 0;
    }

    void MostrarInfo()
    {
        cout << "\nInformacion de la persona: " << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        obj.mostrarInfo();
    }
};

void Cambiar(objeto *o)
{
    string n = "Alicia";
    int v = 100;
    /*
        cout << "Nombre: ";
        cin >> n;
        cout << "Valor: ";
        cin >> v;
        cout << "\n";
    */
    o->setNombre(n);
    o->setValor(v);
}

int main()
{
    objeto obj1("Llaves", 10);
    cout << "   Objeto 1" << endl;
    cout << "=============" << endl;
    obj1.mostrarInfo();
    cout << "\n";

    objeto obj2;
    cout << "   Objeto 2" << endl;
    cout << "=============" << endl;
    obj2.mostrarInfo();
    cout << "\n";

    objeto obj3("Billetera", 200);
    objeto *pObj = &obj3;

    cout << "   Objeto 3" << endl;
    cout << "=============" << endl;
    cout << "ANTES: " << endl;
    pObj->mostrarInfo();
    pObj->setNombre("Celular");
    pObj->setValor(500);
    cout << "\nDESPUES: " << endl;
    pObj->mostrarInfo();
    cout << "\nObjeto Original: " << endl;
    obj3.mostrarInfo();
    cout << "\n";

    objeto obj4;
    cout << "   Objeto 4" << endl;
    cout << "=============" << endl;
    Cambiar(&obj4);
    obj4.mostrarInfo();
    cout << "\n";

    Persona p1("Juan", 30, obj1);
    cout << "=============" << endl;
    cout << "  Personas  " << endl;
    cout << "=============" << endl;
    cout << "\n Personas 1  " << endl;
    cout << "=============" << endl;
    p1.MostrarInfo();
    cout << "\n";

    Persona p2("Maria", 25);
    cout << "\n Personas 2  " << endl;
    cout << "=============" << endl;
    p2.MostrarInfo();
    cout << "\n";

    Persona p3("Nicolas", 30, objeto("Celular", 2000));
    cout << "\n Personas 3  " << endl;
    cout << "=============" << endl;
    p3.MostrarInfo();
    cout << "\n";

    objeto Billetera("Billetera", 5000);
    objeto Cosas[3] = {Billetera, objeto(), objeto("Llaves de la casa", 500)};
    cout << "\n Arreglo de Objetos  " << endl;
    cout << "================" << endl;
    cout << "\n Arreglo 1:  " << endl;
    cout << "================" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "COSA " << i + 1 << ": ";
        Cosas[i].mostrarInfo();
        cout << "\n";
    }
    cout << "\n";

    return 0;
}