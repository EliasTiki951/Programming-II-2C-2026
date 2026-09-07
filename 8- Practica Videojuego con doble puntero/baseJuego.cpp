#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <string>
#include <thread>

using namespace std;

// Cosas que tienen en comun todos los personajes.
class clases
{
protected:
    string nombre;
    string armas[5];
    string tipo;
    int vida;
    int vidaMaxima;
    int dano;
    bool ultimoAtaqueFueCritico;

public:
    // Arranca con su vida y dano iniciales.
    clases(string n, int vidaInicial, int danoBase)
        : nombre(n), vida(vidaInicial), vidaMaxima(vidaInicial), dano(danoBase),
          ultimoAtaqueFueCritico(false) {}

    // Le resta vida, pero nunca baja de cero.
    void RecibirDanio(int cantidad)
    {
        vida -= cantidad;
        if (vida < 0)
        {
            vida = 0;
        }
    }

    // El dano varia un poco y a veces sale un golpe critico.
    virtual int Atacar(clases &objetivo)
    {
        static random_device semilla;
        static mt19937 generador(semilla());
        uniform_int_distribution<int> variacion(dano * 80 / 100, dano * 120 / 100);
        uniform_int_distribution<int> probabilidad(1, 100);

        int danoReal = variacion(generador);
        bool esCritico = probabilidad(generador) <= 10;
        ultimoAtaqueFueCritico = esCritico;
        if (esCritico)
        {
            danoReal *= 2;
        }

        objetivo.RecibirDanio(danoReal);
        return danoReal;
    }

    // Recupera hasta 20 de vida, sin pasarse de la vida maxima.
    int Curar(clases &objetivo)
    {
        int vidaAnterior = objetivo.vida;
        objetivo.vida = min(objetivo.vida + 20, objetivo.vidaMaxima);
        return objetivo.vida - vidaAnterior;
    }

    // Sube el dano en 10 para los siguientes ataques.
    void Reforzar()
    {
        dano += 10;
    }
    bool EstaVivo() const
    {
        return vida > 0;
    }
    int ObtenerVida() const
    {
        return vida;
    }
    bool FueCritico() const
    {
        return ultimoAtaqueFueCritico;
    }
    virtual void CargarDatos() = 0;
    virtual void MostrarDatos() = 0;
    virtual ~clases() {}
};

// El caballero tiene bastante vida y un dano normal.
class caballero : public clases
{
private:
    string armasDisponibles[5] = {"espada", "escudo", "lanza", "arco", "hacha"};

public:
    caballero(string n) : clases(n, 120, 18)
    {
    }
    void CargarDatos() override
    {
        int opcion;
        cout << "saludos " << nombre << endl;
        cout << "Elija un arma:" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << ". " << armasDisponibles[i] << endl;
        }
        do
        {
            cout << "Arma: ";
            cin >> opcion;
            if (opcion < 1 || opcion > 5)
            {
                cout << "Opcion invalida. Elige un numero del 1 al 5: ";
            }
        } while (opcion < 1 || opcion > 5);
        armas[0] = armasDisponibles[opcion - 1];
        cout << "Arma elegida: " << armas[0] << endl;
    }

    void MostrarDatos() override
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Clase: Caballero" << endl;
        cout << "Arma: " << armas[0] << endl;
        cout << "Vida: " << vida << endl;
    }
};

class mago : public clases
{
private:
    string hechizosDisponibles[5] = {"transmutacion", "destruccion", "proteccion", "curacion", "ilusion"};

public:
    mago(string n) : clases(n, 85, 22)
    {
    }
    void CargarDatos() override
    {
        int opcion;
        cout << nombre << " es un mago" << endl;
        cout << "Elija una clase de hechizo:" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << ". " << hechizosDisponibles[i] << endl;
        }
        do
        {
            cout << "clase: ";
            cin >> opcion;
            if (opcion < 1 || opcion > 5)
            {
                cout << "Opcion invalida. Elige un numero del 1 al 5: ";
            }
        } while (opcion < 1 || opcion > 5);
        armas[0] = hechizosDisponibles[opcion - 1];
        cout << "clase elegida: " << armas[0] << endl;
    }

    void MostrarDatos() override
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Clase: Mago" << endl;
        cout << "clase de hechizo: " << armas[0] << endl;
        cout << "Vida: " << vida << endl;
    }
};
class invocador : public clases
{
private:
    string invocacionesDisponibles[5] = {"nigromante", "diabolista", "druidicos", "arcano", "elementalista"};

public:
    invocador(string n) : clases(n, 100, 19)
    {
    }
    void CargarDatos() override
    {
        int opcion;
        cout << nombre << " es un invocador" << endl;
        cout << "Elija una clase de invocador:" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << ". " << invocacionesDisponibles[i] << endl;
        }
        do
        {
            cout << "clase: ";
            cin >> opcion;
            if (opcion < 1 || opcion > 5)
            {
                cout << "Opcion invalida. Elige un numero del 1 al 5: ";
            }
        } while (opcion < 1 || opcion > 5);
        armas[0] = invocacionesDisponibles[opcion - 1];
        cout << "clase de invocador elegida: " << armas[0] << endl;
    }

    void MostrarDatos() override
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Clase: Invocador" << endl;
        cout << "clase de invocador: " << armas[0] << endl;
        cout << "Vida: " << vida << endl;
    }
};

class dragon : public clases
{
public:
    dragon(string n) : clases(n, 300, 30)
    {
    }

    int Atacar(clases &objetivo) override
    {
        static random_device semilla;
        static mt19937 generador(semilla());
        uniform_int_distribution<int> variacion(dano * 80 / 100, dano * 120 / 100);
        uniform_int_distribution<int> probabilidad(1, 100);

        int danoReal = variacion(generador);
        ultimoAtaqueFueCritico = probabilidad(generador) <= 10;
        if (ultimoAtaqueFueCritico)
        { // El dragon tiene un 10% de probabilidad de critico.
            danoReal *= 2;
        }

        objetivo.RecibirDanio(danoReal);
        return danoReal;
    }

    int IntentarCurarse()
    {
        if (vida == vidaMaxima)
        {
            return 0;
        }

        static random_device semillaCuracion;
        static mt19937 generadorCuracion(semillaCuracion());
        uniform_int_distribution<int> probabilidad(1, 100);
        int resultado = probabilidad(generadorCuracion);

        if (resultado <= 5)
        {
            int vidaRecuperada = vidaMaxima - vida;
            vida = vidaMaxima;
            return vidaRecuperada;
        }

        if (resultado <= 20)
        {
            int vidaAnterior = vida;
            vida = min(vida + vidaMaxima * 20 / 100, vidaMaxima);
            return vida - vidaAnterior;
        }

        return 0;
    }

    void CargarDatos() override
    {
    }

    void MostrarDatos() override
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Clase: Dragon" << endl;
        cout << "Vida: " << vida << endl;
    }
};

int main()
{
    // Primero armamos el equipo.
    int p, opc;
    string nombre;
    cout << "cuantos personajes tiene tu equipo: ";
    do
    {
        cin >> p;
        if (p <= 0)
        {
            cout << "El equipo debe tener al menos un personaje: ";
        }
    } while (p <= 0);

    clases **equipo = new clases *[p];
    for (int i = 0; i < p; i++)
    {
        cout << "ingrese el nombre del personaje " << i + 1 << endl;
        cout << "nombre: ";
        cin >> nombre;

        cout << "que clase es el personaje" << i + 1 << endl;
        cout << "1.guerrero" << endl;
        cout << "2.mago" << endl;
        cout << "3.invocador" << endl;
        cout << "ingrese numero: ";
        cin >> opc;

        while (opc < 1 || opc > 3)
        {
            cout << "Opcion invalida. Elige una clase del 1 al 3: ";
            cin >> opc;
        }

        switch (opc)
        {
        case 1:
            equipo[i] = new caballero(nombre);
            break;
        case 2:
            equipo[i] = new mago(nombre);
            break;
        case 3:
            equipo[i] = new invocador(nombre);
            break;
        default:
            equipo[i] = nullptr;
            break;
        }
        if (equipo[i] != nullptr)
        {
            equipo[i]->CargarDatos();
        }
    }
    cout << "\nDatos de todos los personajes:\n";
    for (int i = 0; i < p; i++)
    {
        if (equipo[i] != nullptr)
        {
            cout << "\nPersonaje " << i + 1 << ":" << endl;
            equipo[i]->MostrarDatos();
        }
    }
    cout << endl;

    // Presentacion antes de empezar la pelea.
    cout << "----------------------------------------------" << endl;
    cout << " se van a enfrentar al señor de las bestias" << endl;
    cout << "      que oculta un tesoro legendario" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "estan listos?" << endl;
    cout << "1.si" << endl;
    cout << "2.no" << endl;
    cout << "elijan una opcion: ";
    cin >> opc;
    switch (opc)
    {
    case 1:
        cout << "entonces que comience la aventura" << endl;
    iniciarCombate:
    {
        // Si vuelven a pelear, el jefe empieza con toda su vida.
        dragon jefe("Senor de las bestias");
        int turno = 1;

        // La pelea sigue mientras el jefe este vivo.
        while (jefe.EstaVivo())
        {
            cout << "\n========== Turno " << turno << " ==========" << endl;

            bool equipoVivo = false;
            // Cada personaje vivo elige que hacer.
            for (int i = 0; i < p; i++)
            {
                if (equipo[i] != nullptr && equipo[i]->EstaVivo())
                {
                    equipoVivo = true;
                    int accion;
                    cout << "\nPersonaje " << i + 1 << ", elige una accion:" << endl;
                    cout << "1. Atacar" << endl;
                    cout << "2. Curar a un aliado" << endl;
                    cout << "3. Usar refuerzo (+10 dano)" << endl;
                    cout << "elija una opcion: ";
                    cin >> accion;

                    switch (accion)
                    {
                    case 1:
                    {
                        int danoHecho = equipo[i]->Atacar(jefe);
                        cout << "Personaje " << i + 1 << " hace " << danoHecho
                             << " de dano al jefe." << endl;
                        cout << "Vida del jefe: " << jefe.ObtenerVida() << endl;
                        this_thread::sleep_for(chrono::milliseconds(1000));

                        // Un critico provoca un contraataque inmediato del jefe.
                        if (equipo[i]->FueCritico() && jefe.ObtenerVida() < 300 && jefe.EstaVivo())
                        {
                            int cantidadVivos = 0;
                            for (int j = 0; j < p; j++)
                            {
                                if (equipo[j] != nullptr && equipo[j]->EstaVivo())
                                {
                                    cantidadVivos++;
                                }
                            }

                            static random_device semillaContraataque;
                            static mt19937 generadorContraataque(semillaContraataque());
                            uniform_int_distribution<int> eleccionContraataque(1, cantidadVivos);
                            int objetivoElegido = eleccionContraataque(generadorContraataque);
                            int vivosContados = 0;

                            for (int j = 0; j < p; j++)
                            {
                                if (equipo[j] != nullptr && equipo[j]->EstaVivo())
                                {
                                    vivosContados++;
                                    if (vivosContados == objetivoElegido)
                                    {
                                        int danoContraataque = jefe.Atacar(*equipo[j]);
                                        cout << "El critico enfurece al jefe y contraataca al personaje "
                                             << j + 1 << " causando " << danoContraataque
                                             << " de dano." << endl;
                                        cout << "Vida del personaje " << j + 1 << ": "
                                             << equipo[j]->ObtenerVida() << endl;
                                        this_thread::sleep_for(chrono::milliseconds(1000));
                                        break;
                                    }
                                }
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        int objetivo;
                        cout << "Elige el personaje que quieres curar (1-" << p << "): ";
                        cin >> objetivo;
                        objetivo--;
                        if (objetivo >= 0 && objetivo < p && equipo[objetivo] != nullptr && equipo[objetivo]->EstaVivo())
                        {
                            int vidaRecuperada = equipo[i]->Curar(*equipo[objetivo]);
                            cout << "Personaje " << objetivo + 1 << " recupera "
                                 << vidaRecuperada << " de vida." << endl;
                            cout << "Vida actual: "
                                 << equipo[objetivo]->ObtenerVida() << endl;
                        }
                        else
                        {
                            cout << "Objetivo invalido o derrotado. No se cura." << endl;
                        }
                        break;
                    }
                    case 3:
                        equipo[i]->Reforzar();
                        cout << "Personaje " << i + 1
                             << " aumenta su dano para los proximos ataques." << endl;
                        break;
                    default:
                        cout << "Accion invalida. Pierdes tu turno." << endl;
                        break;
                    }

                    if (!jefe.EstaVivo())
                    {
                        break;
                    }
                }
            }

            if (!jefe.EstaVivo() || !equipoVivo)
            {
                break;
            }

            // El jefe elige al azar a uno de los personajes vivos.
            int cantidadVivos = 0;
            for (int i = 0; i < p; i++)
            {
                if (equipo[i] != nullptr && equipo[i]->EstaVivo())
                {
                    cantidadVivos++;
                }
            }

            static random_device semillaObjetivo;
            static mt19937 generadorObjetivo(semillaObjetivo());
            uniform_int_distribution<int> eleccion(1, cantidadVivos);
            int personajeElegido = eleccion(generadorObjetivo);
            int vivosContados = 0;

            for (int i = 0; i < p; i++)
            {
                if (equipo[i] != nullptr && equipo[i]->EstaVivo())
                {
                    vivosContados++;
                    if (vivosContados == personajeElegido)
                    {
                        int danoRecibido = jefe.Atacar(*equipo[i]);
                        cout << "El jefe hace " << danoRecibido
                             << " de dano al personaje " << i + 1 << "." << endl;
                        cout << "Vida del personaje " << i + 1 << ": "
                             << equipo[i]->ObtenerVida() << endl;
                        this_thread::sleep_for(chrono::milliseconds(1000));

                        // Si fue critico, el jefe ataca hasta a 3 aventureros.
                        if (jefe.FueCritico())
                        {
                            cout << "El jefe hizo un ataque critico y ataca a otros aventureros."
                                 << endl;
                            int objetivos[3];
                            int cantidadObjetivos = 1;
                            objetivos[0] = i;

                            // Guardamos hasta otros dos personajes que estaban vivos.
                            for (int j = 0; j < p && cantidadObjetivos < 3; j++)
                            {
                                if (j != i && equipo[j] != nullptr && equipo[j]->EstaVivo())
                                {
                                    objetivos[cantidadObjetivos] = j;
                                    cantidadObjetivos++;
                                }
                            }

                            for (int objetivo = 1; objetivo < cantidadObjetivos; objetivo++)
                            {
                                int j = objetivos[objetivo];
                                int danoCritico = jefe.Atacar(*equipo[j]);
                                cout << "El jefe hace " << danoCritico
                                     << " de dano al personaje " << j + 1 << "." << endl;
                                cout << "Vida del personaje " << j + 1 << ": "
                                     << equipo[j]->ObtenerVida() << endl;
                                this_thread::sleep_for(chrono::milliseconds(1000));
                            }
                        }
                        this_thread::sleep_for(chrono::milliseconds(1500));
                        break;
                    }
                }
            }
            if (jefe.EstaVivo())
            {
                int vidaRecuperada = jefe.IntentarCurarse();
                if (vidaRecuperada > 0)
                {
                    if (jefe.ObtenerVida() == 300)
                    {
                        cout << "El jefe se cura por completo." << endl;
                    }
                    else
                    {
                        cout << "El jefe recupera " << vidaRecuperada
                             << " puntos de vida." << endl;
                    }
                    cout << "Vida del jefe: " << jefe.ObtenerVida() << endl;
                    this_thread::sleep_for(chrono::milliseconds(1000));
                }
            }
            turno++;
        }

        // Vemos quien gano la pelea.
        if (jefe.EstaVivo())
        {
            cout << "\nEl equipo fue derrotado." << endl;
        }
        else
        {
            cout << "\nEl equipo derroto al Senor de las bestias." << endl;
        }
    }
    break;
    case 2:
        cout << "proceden a retirarse..." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "pero..." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "..." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "..." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "el dragon..." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "..." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "esta..." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "..." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "atras tuyo!!" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        goto iniciarCombate;
    default:
        cout << "opcion invalida" << endl;
        break;
    }

    // Borramos lo que reservamos para el equipo.
    for (int i = 0; i < p; i++)
    {
        delete equipo[i];
    }
    delete[] equipo;
    return 0;
}