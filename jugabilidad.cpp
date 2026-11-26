#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include "jugabilidad.h"

using namespace std;

void jugabilidad(int &maximoPuntaje, string &nombreGanador)
{
    const int VALORES_DADOS = 6;
    const int TAM = 5;
    const int CANTIDAD_TURNOS = 3;
    const int CANTIDAD_JUGADORES = 2;
    //vector para guardar los nombres de los jugadores
    string nombresJugadores[CANTIDAD_JUGADORES];

    int tirada[TAM];

    int puntosJugadores[CANTIDAD_JUGADORES]= {0};

    ///getline() permite ingresar nombres que contienen espacios.

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < CANTIDAD_JUGADORES; i++)
    {
        do{
           cout << "Ingrese el nombre del jugador "
             << i + 1 << ": ";

        getline(cin, nombresJugadores[i]);
        if(nombresJugadores[i].empty()){
            cout <<"El nombre no puede estar vacio" <<endl;
        }

    }while (nombresJugadores[i].empty());

        }



    for (int turno = 1; turno <= CANTIDAD_TURNOS; turno++)
    {
        cout << "\n==============================" << endl;
        cout << "          TURNO #" << turno << endl;
        cout << "==============================" << endl;

        ///determinar quien comienza la ronda.
        int jugadorInicial = (turno - 1) % CANTIDAD_JUGADORES;

        for (int i=0; i < CANTIDAD_JUGADORES; i++)
        {
            int jugador = (jugadorInicial + i)% CANTIDAD_JUGADORES;

            cout << "\n" << nombresJugadores[jugador] << endl;

            generarTiradaDados(tirada, TAM, VALORES_DADOS);

            cout << "\nDados obtenidos:\n" << endl;
            mostrarTiradaDados(tirada, TAM);
            cout << endl;

            int puntosTirada = obtenerPuntosTirada(tirada, TAM);

            cout << "Puntos de la tirada: "
                 << puntosTirada << endl;

            puntosJugadores[jugador] += puntosTirada;

            cout << "Puntaje acumulado: "
                 << puntosJugadores[jugador] << endl;
        }
    }
    cout << "\n==============================" << endl;
    cout << "      RESULTADO FINAL" << endl;
    cout << "==============================" << endl;

    for (int i = 0; i < CANTIDAD_JUGADORES; i++)
    {
        cout << nombresJugadores[i] << ": "
             << puntosJugadores[i] << " puntos" << endl;
    }

   mostrarGanador(puntosJugadores, nombresJugadores);

    maximoPuntaje = obtenerPuntosGanador(puntosJugadores[0], puntosJugadores[1]);

    if(puntosJugadores[0]> puntosJugadores[1]){
        nombreGanador = nombresJugadores[0];
    }
    else if (puntosJugadores[1]> puntosJugadores[0]){
        nombreGanador = nombresJugadores[1];
    }
    else{
        nombreGanador = nombresJugadores[0]+ " y " + nombresJugadores[1];
    }


}

/// Genera un número aleatorio entre 1 y rango
int generarNumeroAleatorio(int rango)
{
    return rand() % rango + 1;
}


/// Genera todos los valores de una tirada
void generarTiradaDados(int vec[], int tam, int rango)
{
    for (int i = 0; i < tam; i++)
    {
        vec[i] = generarNumeroAleatorio(rango);
    }
}


/// Muestra todos los dados
void mostrarTiradaDados(int vec[], int tam)
{
    const string caras[6][5] =
    {
        {
            "+-------+",
            "|       |",
            "|   o   |",
            "|       |",
            "+-------+"
        },
        {
            "+-------+",
            "| o     |",
            "|       |",
            "|     o |",
            "+-------+"
        },
        {
            "+-------+",
            "| o     |",
            "|   o   |",
            "|     o |",
            "+-------+"
        },
        {
            "+-------+",
            "| o   o |",
            "|       |",
            "| o   o |",
            "+-------+"
        },
        {
            "+-------+",
            "| o   o |",
            "|   o   |",
            "| o   o |",
            "+-------+"
        },
        {
            "+-------+",
            "| o   o |",
            "| o   o |",
            "| o   o |",
            "+-------+"
        }
    };

    for (int fila = 0; fila < 5; fila++)
    {
        for (int i = 0; i < tam; i++)
        {
            cout << caras[vec[i] - 1][fila] << " ";
        }

        cout << endl;
    }
}


/// Calcula la suma de los dados
int obtenerPuntosTirada(int vec[], int tam)
{
    int puntos = 0;

    for (int i = 0; i < tam; i++)
    {
        puntos += vec[i];
    }

    return puntos;
}


/// Muestra quién ganó
void mostrarGanador(const int puntosJugadores[],
                    const string nombresJugadores[])
{
    cout << endl;

    if (puntosJugadores[0] > puntosJugadores[1])
    {
        cout << "El ganador es "
             << nombresJugadores[0]
             << " con " << puntosJugadores[0]
             << " puntos." << endl;
    }
    else if (puntosJugadores[1] > puntosJugadores[0])
    {
        cout << "El ganador es "
             << nombresJugadores[1]
             << " con " << puntosJugadores[1]
             << " puntos." << endl;
    }
    else
    {
        cout << "La partida termino en EMPATE con "
             << puntosJugadores[0]
             << " puntos." << endl;
    }
}


/// Devuelve el puntaje más alto de la partida
int obtenerPuntosGanador(int puntosJugador1, int puntosJugador2)
{
    if (puntosJugador1 > puntosJugador2)
    {
        return puntosJugador1;
    }

    return puntosJugador2;
}
