#pragma once
#include <string>
using namespace std;

//creo la clase
class Tiempo
{

private:
    int hora;
    int min;
    int seg;
    string momento_dia; //am o pm

public:
    Tiempo();
    Tiempo(int h);
    Tiempo(int h, int m);
    Tiempo(int h, int m, int s);
    Tiempo(int h, int m, int s, string am_o_pm);
    void mostrar_formato() ;
};
