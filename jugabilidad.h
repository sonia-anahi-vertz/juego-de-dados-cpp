#ifndef JUGABILIDAD_H_INCLUDED
#define JUGABILIDAD_H_INCLUDED
#include <string>

void jugabilidad(int &maximoPuntaje, std::string &nombreGanador); ///es por & por que es una funcion void que no tiene retorno

int generarNumeroAleatorio(int rango);

///lanzar dados y guardarlo en un vector
void generarTiradaDados(int vec[], int tam, int rango);

///genero una funcion para mostrar las tiradas de dados
void mostrarTiradaDados(int vec[], int tam);

///funcion para sumar los dados, los puntos de los dados estan guardados en el vector, para obtener los puntos necesito pasarle el vector
int obtenerPuntosTirada(int vec[], int t);

///FUNCION PARA MOSTAR EL GANADOR
void mostrarGanador(const int puntosJugadores[],
                    const std::string nombresJugadores[]);

///funcion para los puntos del ganador
int obtenerPuntosGanador(int jugador1, int jugador2);

#endif // JUGABILIDAD_H_INCLUDED
