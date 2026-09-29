#include <iostream>
#include <cstdlib>
using namespace std;

void Limpiar()
{
#if defined(_WIN32)
    system("cls");
#elif defined(_linux) // ← Corregido: __linux_ (dos guiones bajos)
    system("clear");
#else
    std::cout << "Sistema operativo: Desconocido" << std::endl;
#endif
}

void Pausa()
{
#if defined(_WIN32)
    std::cout << "\nPresione Enter para continuar..." << std::endl;
    system("pause");
#elif defined(_linux_)
    std::cout << "\nPresione Enter para continuar..." << std::endl;
    cin.get();
    cin.ignore(100, '\n');
#else
    std::cout << "Sistema operativo: Desconocido" << std::endl;
#endif
}

int main()
{
    return 0;
}