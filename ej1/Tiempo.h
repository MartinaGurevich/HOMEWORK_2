#pragma once
#include <string>

//creo la clase
class Tiempo
{

private:
    int hora;
    int min;
    int seg;

public:
    Tiempo();
    Tiempo(int h);
    Tiempo(int h, int m);
    Tiempo(int h, int m, int s);
    void mostrar_formato() ;
};
