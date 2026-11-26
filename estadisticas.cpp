#include <iostream>
#include "estadisticas.h"


using namespace std;

void estadisticas(int &maximo, const string &nombreRecord )
{
    cout<<"==================================" <<endl;
    cout<<"          ESTADISTICAS            " <<endl;
    cout<<"==================================" <<endl;

    if (maximo==0){
        cout<<"Todavia no se registraron partidas. " <<endl;
    }
    else{
        cout <<"Jugador con mayor puntaje:"
        <<nombreRecord << endl;

        cout << "Record de puntos: "
            <<maximo << endl;
    }


   cout<<"==================================" <<endl;
}
