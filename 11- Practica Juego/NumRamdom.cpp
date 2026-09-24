// Códgo para poner un número aleatorio

#include <iostream>
#include <random>

using namespace std;

int main()
{

    random_device rd;
    mt19937 generador(rd());

    uniform_int_distribution<int> distribucion(50, 100);

    int numero = distribucion(generador);

    cout << "Numero aleatorio: " << numero << endl;

    return 0;
}