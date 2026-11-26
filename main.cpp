#include <iostream>
#include <ctime>
#include "menu.h"

using namespace std;

int main()
{
    // Inicializar la semilla de numeros aleatorios.
    srand (time(nullptr));

    // Inicializar el puntaje maximo.
    int maximo=0;

    // Ejecutar el menu principal.
    menu(maximo);

    return 0;
}
