#include <iomanip>
#include <iostream>
#include "Tiempo.h"
#include <string>

using namespace std;

//a, constructor sin parametros para q impirma  0h, 0m, 0s a.m.
Tiempo::Tiempo() : hora(0), min(0), seg(0) {} //fijarme como puede quedar con 0 la hh

//constructor con solo la hora
Tiempo::Tiempo(int h) : hora(h), min(0), seg(0) {}

//constructor hora y min
Tiempo::Tiempo(int h, int m) : hora(h), min(m), seg(0) {}

//constructor con hora, min y seg
Tiempo::Tiempo(int h, int m, int s) : hora(h), min(m), seg(s) {}

//constructor con hora, min y seg y “p.m.”/”a.m.”
Tiempo::Tiempo(int h, int m, int s, string am_o_pm) : hora(h), min(m), seg(s), momento_dia(am_o_pm) {}


void Tiempo::mostrar_formato(){
    //string momento_dia;
    // if(hora>= 12){
    //     momento_dia = "p.m.";
    // } else{
    //     momento_dia= "a.m.";
    // }

    if(hora <0 || hora>24 || min <0 || min>60 ||seg<0 || seg>60){
        cout<<"horario fuera de rango \n"; 
        exit(1); //PREG SI ESTA BIEN USAR EXIT , no me deja usar break por??????????????P
    }

    // int mostar_hora= hora % 12 ;//pone la hora tipo 13 es 1  !!!!!!!!!!!!!  PREGUNTAR SI LO DE HORA EN FORMATO 24 HS ES PARA LA HORA INDIVIDUAL ... DSP DE PUNTO G
    // if (mostar_hora == 0) {
    //     mostar_hora = 12;
    // } 
    //tengo q pregutar si queire ingresar hora , hora y m , h, m y s ? o KE 
    
    cout<< setfill('0')<< setw(2)<< hora<< "h, "
    <<setw(2)<< min<< "m, "
    <<setw(2)<< seg << "s "
    << momento_dia<< endl;

}

/*PREGUNTAR
- fijarme como puede quedar con 0 la hh
-PREG SI ESTA BIEN USAR EXIT 
- (H) LO DE HORA EN FORMATO 24 HS ES PARA LA HORA INDIVIDUAL ... DSP DE PUNTO G
- punto (g) tengo q pregutar si queire ingresar hora , hora y m , h, m y s ? o KE 
*/