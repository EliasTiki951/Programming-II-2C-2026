#include <iostream>
#include <cstdlib>

using namespace std;

class Animal
{
protected:
    string nombre;

public:
    Animal(string n)
    {
        nombre = n;
    }

    virtual void HacerRuido()
    {
        cout << nombre << " hace ruido" << endl;
    }
};

class Perro : public Animal
{
public:
    Perro(string n) : Animal(n) {}

    void HacerRuido() override
    {
        cout << nombre << " hace Guau" << endl;
    }

    void Ladrar()
    {
        cout << nombre << " hace Guau" << endl;
    }
};

class Gato : public Animal
{
public:
    Gato(string n) : Animal(n) {}

    void HacerRuido() override
    {
        cout << nombre << " hace Miau" << endl;
    }

    void Maullar()
    {
        cout << nombre << " hace Miau" << endl;
    }
};

class Pajaro : public Animal
{
public:
    Pajaro(string n) : Animal(n) {}

    void HacerRuido() override
    {
        cout << nombre << " hace su canto" << endl;
    }

    void Volar()
    {
        cout << nombre << " vuela alto" << endl;
    }
};

int main()
{
    Animal a1("Maxi");
    Perro p1("Firulais");
    Gato g1("Tom");
    Pajaro pj1("Hornero");

    a1.HacerRuido();
    p1.HacerRuido();
    g1.HacerRuido();
    pj1.HacerRuido();

    Animal *Loro = new Pajaro("Loro");

    Loro->HacerRuido();

    /*

    Animal *pp=new Pajaro("Loro");

    pp->HacerRuido();

    Animal **ap=new Animal*[2];

    ap[0]=new Perro("Fatiga");
    ap[1]=new Gato("Sr Gato");

        for(int i=0;i<2;i++){
            ap[i]->HacerRuido();
            }
    */
    return 0;
}