#include <iostream>
#include <cstdlib>

using namespace std;

class Objeto
{
private:
    string nombre;
    int valor;

public:
    Objeto(string n, int v)
    {
        nombre = n;
        valor = v;
    }

    Objeto()
    {
        nombre = "Sin Nombre";
        valor = 0;
    }

    string getNombre() { return nombre; }
    int getValor() { return valor; }

    void setNombre(string n) { nombre = n; }
    void setValor(int v) { valor = v; }

    void MostrarInfo()
    {
        cout << "Informacion del Objeto:" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Valor: " << valor << endl;
    }
};

class Persona
{
private:
    string nombre;
    int edad;
    Objeto obj;

public:
    Persona(string n, int e, Objeto o)
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
        cout << "Objeto: " << endl;
        obj.MostrarInfo();
    }
};

void Cambiar(Objeto *o)
{
    string n = "Algo"; // BORRAR SI VAN A CARGAR LOS DATOS MANUALMENTE
    int v = 100;

    // cout<<"Nombre: ";
    // cin>>n;
    // cout<<"Valor: ";
    // cin>>v;
    // cout<<endl;

    o->setNombre(n);
    o->setValor(v);
}

int main()
{
    Objeto obj1("Llaves", 10);

    cout << "Objeto 1" << endl;
    cout << "---------------" << endl;
    obj1.MostrarInfo();
    cout << endl;

    Objeto obj2;

    cout << "Objeto 2" << endl;
    cout << "---------------" << endl;
    obj2.MostrarInfo();
    cout << endl;

    Objeto obj3("Billetera", 200);
    Objeto *pObj = &obj3;

    cout << "Objeto 3" << endl;
    cout << "---------------" << endl;
    cout << "ANTES: " << endl;
    pObj->MostrarInfo();
    pObj->setNombre("Celular");
    pObj->setValor(500);
    cout << "\nDESPUES: " << endl;
    pObj->MostrarInfo();
    cout << "\nOBJETO ORIGINAL: " << endl;
    obj3.MostrarInfo();
    cout << endl;

    Objeto obj4;

    cout << "Objeto 4" << endl;
    cout << "---------------" << endl;
    Cambiar(&obj4);
    obj4.MostrarInfo();
    cout << endl;

    Persona p1("Miguel", 40, obj1);

    cout << "\n---------------" << endl;
    cout << "PERSONAS" << endl;
    cout << "---------------" << endl;
    cout << "\nPERSONA 1" << endl;
    p1.MostrarInfo();
    cout << endl;

    Persona p2("Carlos", 55);

    cout << "\n---------------" << endl;
    cout << "PERSONAS" << endl;
    cout << "---------------" << endl;
    cout << "\nPERSONA 2" << endl;
    p2.MostrarInfo();
    cout << endl;

    Persona p3("Nicolas", 30, Objeto("Celular", 2000));

    cout << "\n---------------" << endl;
    cout << "PERSONAS" << endl;
    cout << "---------------" << endl;
    cout << "\nPERSONA 3" << endl;
    p3.MostrarInfo();
    cout << endl;

    Objeto Billetera("Billetera", 5000);
    Objeto Cosas[3] = {Billetera,
                       Objeto(),
                       Objeto("Llaves de Casa", 500)};

    cout << "\n---------------" << endl;
    cout << "ARREGLOS DE OBJETOS" << endl;
    cout << "---------------" << endl;
    cout << "\nARREGLO 1" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "COSA " << i + 1 << endl;
        Cosas[i].MostrarInfo();
        cout << endl;
    }
    cout << endl;

    return 0;
}