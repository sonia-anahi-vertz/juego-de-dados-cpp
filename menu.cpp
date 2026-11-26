#include <iostream>
#include <limits>
#include <string>
#include "menu.h"
#include "jugabilidad.h"
#include "estadisticas.h"


using namespace std;

void menu(int maximo)
{
    int opcion = 0;
    int maximoPuntaje = 0; ///se tiene que cargar en el juego, entonces se lo paso por  valor a jugabilidad
    string nombreGanador;
    string nombreRecord;

    do
    {
        system("cls");
        opciones();
        ///CREAR UN SWITCH PARA ELEGIR OPCIONES
        cout<<"Ingrese opcion: ";
        while (!(cin >> opcion) || opcion < 1 || opcion > 3)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Opcion invalida. Ingrese una opcion del 1 al 3: ";
            }


        switch (opcion)
        {
        case 1:
        {
            cout<<"Inicia el juego " <<endl;

            jugabilidad(maximoPuntaje, nombreGanador);

            if(maximoPuntaje > maximo){
                maximo = maximoPuntaje;
                nombreRecord = nombreGanador;
            }

        }
        break;
        case 2:
        {

            estadisticas(maximo, nombreRecord);
        }
        break;
        case 3:
        {
            cout<<"gracias por jugar " <<endl;
        }
        return;
        break;

        default:
        {
            cout<<"Opcion invalida" <<endl;
        }
        break;
        }
        system("pause");
    }
    while(true);


}

void opciones()
{
    cout<<"---------------------------" <<endl;
    cout << "====================================" << endl;
    cout << "           JUEGO DE DADOS           " << endl;
    cout << "====================================" << endl;
    cout << endl;
    cout << "        1. Nueva partida" << endl;
    cout << "        2. Estadisticas" << endl;
    cout << "        3. Salir" << endl;
    cout << endl;
    cout << "====================================" << endl;

}
