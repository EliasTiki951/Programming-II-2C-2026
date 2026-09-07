// Quiero que creen un programa de un negocio de cuantos dias se trabajó
// en el mes (1-30) y en base a eso ingresar el total recaudado en cada uno de los dias,
// y mostrar la facturación total del mes.

#include <iostream>
#include <cstdlib>
#include <string>
#include <locale.h>
// #include <random>
using namespace std;

// Importar libreria <random>
// include <random>
//
// random_device rd;
// uniform_int_distribution<int> dist(100,999);
// int random = dist(rd);
// cout<<"Random: "<<random<<endl;

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");

    int dias, total = 0;
    // int arr[5];
    // int mat[3][5];

    int *p = nullptr; // IMPORTANTE

    while (true)
    {
        cout << "Cuantos dias se trabajo? (1-30): ";
        cin >> dias;

        if (dias >= 1 && dias <= 30)
        {
            break;
        }
        else
        {
            cout << "Error, ingrese un valor entre 1 y 30" << endl;
            cout << "\n";
            continue;
        }
    }

    p = new int[dias]; // iMPORTANTE

    for (int i = 0; i < dias; i++)
    {
        cout << "\n";
        cout << "Ingrese el total recaudado en el día " << i + 1 << ": ";
        cin >> p[i];
        total += p[i];
    }

    cout << "\n";
    cout << "Se trabajó un total de " << dias << " dias y se recaudó un total de $" << total << endl;

    delete[] p; // IMPORTANTE

    return 0;
}