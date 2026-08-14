#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "spanish");

    /*
    int numero = 5;
    int *p = &numero;

    cout << "Numero: " << numero << endl;
    cout << "Puntero: " << p << endl;

    stack
    heap
    */

    /*
    int tam;
    int *p = NULL; // NULLptr

    cout << "Ingrese el tamaño del arreglo: ";
    cin >> tam;
    p = new int[tam];

    for (int i = 0; i < tam; i++)
    {
        p[i] = i + 1;
        cout << p[i] << endl;
    }

    delete[] p;
    */

    /*
    int arr[5]{};

        cout << &arr[0] << endl;
        cout << &arr[1] << endl;
        cout << &arr[2] << endl;
        cout << &arr[3] << endl;
        cout << &arr[4] << endl;

    int var = 8;

    cout << var << endl;
    cout << sizeof(var) << endl;
    */

    char arr[5]{'a', 'b', 'c', 'd', 'e'};
    char l = 'a';
    string s = "Hola";

    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;
    cout << arr[3] << endl;
    cout << arr[4] << endl;

    cout << sizeof(arr) << endl;

    return 0;
}