#include <iostream>
#include <string>
using namespace std;

class animal
{
protected:
    string nombre;

public:
    animal(string nombre)
    {
        this->nombre = nombre;
    }

    animal(string n) { nombre = n; }

    void hacerRuido()
    {
        cout << nombre << " hace un ruido" << endl;
    }
};

class perro : public animal
{
public:
    perro(string n) : animal(n) {}

    void hacerRuido()
    {
        cout << nombre << " hace guau" << endl;
    }

    void Ladrar()
    {
        cout << nombre << " hace guau" << endl;
    }
};

int main()
{
    perro p1("Rex");
    p1.hacerRuido();
    p1.Ladrar();

    return 0;
}