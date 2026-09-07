// (falta agregar arreglo y puntero)

#include <iostream>
using namespace std;

class Personaje
{
protected:
    // ATRIBUTOS BASE
    string nombre;
    string clase;
    string equipo1;
    int jugadores1;
    int vida = 100;
    int edad;
    int suerte = 0;

public:
    // CONSTRUCTOR
    Personaje(string nombre, string clase, string equipo1, int jugadores1, int vida, int edad, int suerte)
    {
        this->nombre = nombre;
        this->clase = clase;
        this->equipo1 = equipo1;
        this->jugadores1 = jugadores1;
        this->vida = vida;
        this->edad = edad;
        this->suerte = suerte;
    }

    virtual ~Personaje() {}

    // SETTERS
    void setnombre(string nombre) { this->nombre = nombre; }
    void setclase(string clase) { this->clase = clase; }
    void setequipo(string equipo1) { this->equipo1 = equipo1; }
    void setedad(int edad) { this->edad = edad; }
    void setjugadores1(int jugadores1) { this->jugadores1 = jugadores1; }

    // GETTERS
    virtual string getnombre() { return nombre; }
    virtual string getclase() { return clase; }
    virtual string getequipo1() { return equipo1; }
    virtual int getedad() { return edad; }
    virtual int getvida() { return vida; }
    virtual int getjugadores1() { return jugadores1; }

    // METODOS
    virtual void iniciar()
    {
        cout << "Bienvenido a " << equipo1 << ", tu mision es derrotar al equipo rival." << endl;
    }

    virtual void atacar() {}

    virtual void curar() {}
};

class Mago : public Personaje
{
protected:
    int mana = 100;
    int maxcura = 0;

public:
    Mago(string nombre, string clase, string equipo1, int edad, int mana, int maxcura) : Personaje(nombre, clase, equipo1, 0, 100, edad, 0)
    {
        this->mana = mana;
        this->maxcura = maxcura;
    }

    virtual int getmana() { return mana; }

    void atacar() override
    {
        cout << "Le lanzas un hechizo al rival!" << endl;
        if (suerte == 0)
        {
            vida -= 15;
            cout << "El rival te contrataca, tu vida baja a " << vida << endl;
            if (vida <= 0)
            {
                cout << "Mueres en manos de tu enemigo, mejor suerte la proxima..." << endl;
            }
            suerte += 1;
        }
        else if (suerte == 1)
        {
            cout << "Derrotaste al rival!" << endl;
            if (jugadores1 > 0)
            {
                jugadores1 -= 1;
            }
            cout << "Rivales restantes: " << getjugadores1() << endl;
            suerte += 1;
        }
        else if (suerte == 2)
        {
            cout << "Derrotaste al rival!" << endl;
            if (jugadores1 > 0)
            {
                jugadores1 -= 1;
            }
            cout << "Rivales restantes: " << getjugadores1() << endl;
            suerte = 0;
        }
    }

    void curar() override
    {
        if (vida < 100 && maxcura < 4)
        {
            cout << "Tomas una pocion curativa, +10 de vida" << endl;
            maxcura += 1;
            vida += 10;
            cout << "Te quedan " << 4 - maxcura << " pociones" << endl;
        }
        else if (vida >= 100)
        {
            cout << "Tu vida ya esta completa." << endl;
        }
        else
        {
            cout << "No te quedan pociones." << endl;
        }
        cout << "Vida: " << vida << endl;
    }
};

class Guerrero : public Personaje
{
protected:
    int maxcura = 0;

public:
    Guerrero(string nombre, string clase, string equipo1, int edad, int maxcura) : Personaje(nombre, clase, equipo1, 0, 100, edad, 0)
    {
        this->maxcura = maxcura;
    }

    void atacar() override
    {
        cout << "Le pegas al rival!" << endl;
        if (suerte == 0)
        {
            vida -= 10;
            cout << "El rival te contrataca, tu vida baja a " << vida << endl;
            if (vida <= 0)
            {
                cout << "Mueres en manos de tu enemigo, mejor suerte la proxima..." << endl;
            }
            suerte += 1;
        }
        else if (suerte == 1)
        {
            cout << "Derrotaste al rival!" << endl;
            if (jugadores1 > 0)
            {
                jugadores1 -= 1;
            }
            cout << "Rivales restantes: " << getjugadores1() << endl;
            suerte += 1;
        }
        else if (suerte == 2)
        {
            cout << "Derrotaste al rival!" << endl;
            if (jugadores1 > 0)
            {
                jugadores1 -= 1;
            }
            cout << "Rivales restantes: " << getjugadores1() << endl;
            suerte = 0;
        }
    }

    void curar() override
    {
        if (vida < 100 && maxcura < 4)
        {
            cout << "Tomas una pocion curativa, +5 de vida" << endl;
            maxcura += 1;
            vida += 5;
            cout << "Te quedan " << 4 - maxcura << " pociones" << endl;
        }
        else if (vida >= 100)
        {
            cout << "Tu vida ya esta completa." << endl;
        }
        else
        {
            cout << "No te quedan pociones." << endl;
        }
        cout << "Vida: " << vida << endl;
    }
};

int main()
{
    string n;
    string opEquipo1;
    int opClase, opEdad, op, opjugadores;
    Personaje p1("", "", "", 0, 100, 0, 0);
    Mago m1("", "", "", 0, 100, 0);
    Guerrero g1("", "", "", 0, 0);

    cout << "INICIANDO..." << endl;
    cout << "BIENVENIDO A - THE BEST GAME - " << endl;
    cout << endl;
    cout << "INTRODUCE EL NOMBRE DE TU PERSONAJE: ";
    cin >> n;
    p1.setnombre(n);
    cout << endl;
    cout << "ELIJE TU CLASE: (1-2)" << endl;

    do
    {
        cout << "1. Mago" << endl;
        cout << "2. Guerrero" << endl;
        cin >> opClase;
    } while (opClase != 1 && opClase != 2);

    if (opClase == 1)
    {
        p1.setclase("Mago");
    }
    else if (opClase == 2)
    {
        p1.setclase("Guerrero");
    }
    else
    {
        cout << "Error en la seleccion de clase" << endl;
    }

    cout << endl;
    cout << "INTRODUCE EL NOMBRE DE TU EQUIPO: ";
    cin >> opEquipo1;
    p1.setequipo(opEquipo1);

    cout << endl;
    cout << "INTRODUCE LA CANTIDAD DE ENEMIGOS: ";
    cin >> opjugadores;
    while (opjugadores < 10 || opjugadores > 15)
    {
        cout << "Para dificultad normal, elegi entre 10 y 15 enemigos: ";
        cin >> opjugadores;
    }
    p1.setjugadores1(opjugadores);
    m1.setjugadores1(opjugadores);
    g1.setjugadores1(opjugadores);

    Personaje **arreglo = new Personaje *[opjugadores];
    for (int i = 0; i < opjugadores; i++)
    {
        if (opClase == 1)
        {
            arreglo[i] = new Mago("Enemigo", "Mago", opEquipo1, 0, 100, 0);
        }
        else
        {
            arreglo[i] = new Guerrero("Enemigo", "Guerrero", opEquipo1, 0, 0);
        }
    }

    cout << endl;
    cout << "INTRODUCE LA EDAD:" << endl;
    cin >> opEdad;
    p1.setedad(opEdad);

    cout << endl;
    cout << endl;

    cout << "Bienvenido a Banderville " << p1.getnombre() << endl;
    cout << "Tienes " << p1.getvida() << " puntos de vida" << endl;
    if (p1.getclase() == "Mago")
    {
        cout << "Tienes " << m1.getmana() << " puntos de mana" << endl;
    }
    cout << "Equipo: " << p1.getequipo1() << endl;
    cout << "Rivales restantes: " << p1.getjugadores1() << endl;

    cout << endl;

    do
    {
        cout << "1. Atacar" << endl;
        cout << "2. Curar" << endl;
        cout << "3. Info" << endl;
        cout << "0. Salir del juego" << endl;
        cout << endl;
        cin >> op;
        cout << endl;
        if (op == 1 && p1.getclase() == "Mago")
        {
            m1.atacar();
        }
        else if (op == 2 && p1.getclase() == "Mago")
        {
            m1.curar();
        }
        else if (op == 2 && p1.getclase() == "Guerrero")
        {
            g1.curar();
        }
        else if (op == 1 && p1.getclase() == "Guerrero")
        {
            g1.atacar();
        }
        else if (op == 3)
        {
            cout << "Tienes " << p1.getvida() << " puntos de vida" << endl;
            if (p1.getclase() == "Mago")
            {
                cout << "Tienes " << m1.getmana() << " puntos de mana" << endl;
            }
            cout << "Equipo: " << p1.getequipo1() << endl;
            if (p1.getclase() == "Mago")
            {
                cout << "Rivales restantes: " << m1.getjugadores1() << endl;
            }
            else
            {
                cout << "Rivales restantes: " << g1.getjugadores1() << endl;
            }
            cout << "Primer rival: " << arreglo[0]->getnombre()
                 << " (" << arreglo[0]->getclase() << ")" << endl;
        }

        if (op == 1 && ((p1.getclase() == "Mago" && m1.getjugadores1() == 0) ||
                        (p1.getclase() == "Guerrero" && g1.getjugadores1() == 0)))
        {
            cout << "Felicitaciones, ganaste la partida!" << endl;
            cout << "El juego ha finalizado." << endl;
            op = 0;
        }

    } while (op != 0);

    for (int i = 0; i < opjugadores; i++)
    {
        delete arreglo[i];
    }
    delete[] arreglo;

    return 0;
}