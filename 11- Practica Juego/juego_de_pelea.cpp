#include <iostream>
#include <cstdlib>
#include <random>
#include <string>
using namespace std;

class Arma
{
protected:
    string nombre;
    int ataque;
    int probCritico;
    int probAturdir;
    int probFallar;
    int probCabeza;

public:
    // Constructor
    Arma(string n, int a, int pCri, int pAtu, int pFal, int pCab)
    {
        nombre = n;
        ataque = a;
        probCritico = pCri;
        probAturdir = pAtu;
        probFallar = pFal;
        probCabeza = pCab;
    }

    // Sin Parametros
    Arma()
    {
        nombre = "Sin nombre";
        ataque = 0;
        probCritico = 0;
        probAturdir = 0;
        probFallar = 0;
        probCabeza = 0;
    }

    // Setters
    void setNombre(string n) { nombre = n; }
    void setAtaque(int a) { ataque = a; }
    void setProbCritico(int pCri) { probCritico = pCri; }
    void setProbAturdir(int pAtu) { probAturdir = pAtu; }
    void setProbFallar(int pFal) { probFallar = pFal; }
    void setProbCabeza(int pCab) { probCabeza = pCab; }

    // Getters
    string getNombre() { return nombre; }
    int getAtaque() { return ataque; }

    // Metodos
    void MostrarInfo()
    {
        cout << "\nInformacion del arma:" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Ataque: " << ataque << endl;
    }
};

class Personaje
{
protected:
    // ATRIBUTOS
    string nombre;
    int vida;
    Arma arma;

    // CONSTRUCTOR
public:
    Personaje(string n, int v, Arma a)
    {
        nombre = n;
        vida = v;
        arma = a;
    }

    Personaje()
    {
        nombre = " ";
        vida = 0;
        arma = Arma();
    }

    // METODOS
    void MostrarInfo()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Vida: " << vida << " HP." << endl;
        arma.MostrarInfo();
    }

    string getNombre() { return nombre; }
    int getVida() { return vida; }
    Arma getArma() { return arma; }

    void recibirDanio(int daño)
    {
        vida -= daño;
        if (vida < 0)
        {
            vida = 0;
        }
    }
};

Arma elegirArma()
{
    Arma espada("Espada", 25);         // Daño crítico o Debilidad
    Arma cuchillo("Cuchillo", 30);     // Daño crítico o Debilidad
    Arma lanza("Lanza", 35);           // Aturdido
    Arma motosierra("Motosierra", 35); // Aturdido
    Arma metralleta("MK-500", 55);     // Errar o apunta a la cabaza
    Arma escopeta("FK-400", 40);       // Errar o apunta a la cabeza

    int opcion;

    cout << "\n===== ELEGIR ARMA =====" << endl;
    cout << "1. Espada - Ataque: 25" << endl;
    cout << "2. Cuchillo - Ataque: 30" << endl;
    cout << "3. Lanza - Ataque: 35" << endl;
    cout << "4. Motosierra - Ataque: 35" << endl;
    cout << "5. MK-500 - Ataque: 50" << endl;
    cout << "6. FK-400 - Ataque: 40" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    while (opcion < 1 || opcion > 6)
    {
        cout << "Opcion invalida. Elija nuevamente: ";
        cin >> opcion;
    }

    if (opcion == 1)
        return espada;
    else if (opcion == 2)
        return cuchillo;
    else if (opcion == 3)
        return lanza;
    else if (opcion == 4)
        return motosierra;
    else if (opcion == 5)
        return metralleta;
    else
        return escopeta;
};

int main()
{
    string nom1, nom2;

    cout << "========== JUEGO DE PELEA ==========" << endl;
    cout << endl;
    cout << "Nombre del primer Jugador: ";
    getline(cin >> ws, nom1);

    Arma arma1 = elegirArma();
    Personaje jugador1(nom1, 500, arma1);

    cout << "Nombre del segundo Jugador: ";
    getline(cin >> ws, nom2);

    Arma arma2 = elegirArma();
    Personaje jugador2(nom2, 500, arma2);

    cout << "\n===== PERSONAJES =====" << endl;
    jugador1.MostrarInfo();
    jugador2.MostrarInfo();

    cout << "\n===== FIGHT =====" << endl;

    while (jugador1.getVida() > 0 && jugador2.getVida() > 0)
    {
    }

    cout << "\n===== FIN DE LA PELEA =====" << endl;

    if (jugador1.getVida() > 0)
        cout << "Ganador: " << jugador1.getNombre() << endl;
    else
        cout << "Ganador: " << jugador2.getNombre() << endl;

    return 0;
}