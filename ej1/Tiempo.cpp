#include <iomanip>
#include <iostream>
#include "Tiempo.h"
#include <string>

using namespace std;

//a, constructor sin parametros para q impirma  0h, 0m, 0s a.m.
Tiempo::Tiempo() : hora(0), min(0), seg(0) {}

//constructor con solo la hora
Tiempo::Tiempo(int h) : hora(h), min(0), seg(0) {}

//constructor hora y min
Tiempo::Tiempo(int h, int m) : hora(h), min(m), seg(0) {}

//constructor con hora, min y seg
Tiempo::Tiempo(int h, int m, int s) : hora(h), min(m), seg(s) {}


void Tiempo::mostrar_formato(){
    
}