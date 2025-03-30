#pragma once
#include <string>
using namespace std;

//creo la clase
class Tiempo
{

private:
    int hora= 0;
    int min= 0;
    int seg= 0;
    string momento_dia= "am"; //am o pm

public:
    Tiempo();
    Tiempo(int h);
    Tiempo(int h, int m);
    Tiempo(int h, int m, int s);
    Tiempo(int h, int m, int s, string am_pm);
    void mostrar_formato() ;
    void mostar_formato_24();

    //getters para agarrar la opcion q quiero
    int getHora();
    int getMin();
    int getSeg();
    string getMomento_dia();

    //setters para modificar
    void setHora(int h);
    void setMin( int m);
    void setSeg(int s);
    void setMomento_dia( string am_pm);
};

int Pedir_horario(string ingresa_tiempo, int max, int min);
