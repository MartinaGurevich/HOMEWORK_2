#include <iomanip>
#include <iostream>
#include "Tiempo.h"
#include <string>

using namespace std;

//a, constructor sin parametros para q impirma  0h, 0m, 0s a.m.
Tiempo::Tiempo() : hora(0), min(0), seg(0), momento_dia("am") {} //fijarme como puede quedar con 0 la hh

//constructor con solo la hora
Tiempo::Tiempo(int h) : hora(h), min(0), seg(0), momento_dia("am") {}//am

//constructor hora y min
Tiempo::Tiempo(int h, int m) : hora(h), min(m), seg(0), momento_dia("am") {}

//constructor con hora, min y seg
Tiempo::Tiempo(int h, int m, int s) : hora(h), min(m), seg(s), momento_dia("am") {}

//constructor con hora, min y seg y “p.m.”/”a.m.”
Tiempo::Tiempo(int h, int m, int s, string am_pm) : hora(h), min(m), seg(s), momento_dia(am_pm) {}
 
//GETTERS
int Tiempo ::getHora(){return hora; }
int Tiempo ::getMin(){return min; }
int Tiempo ::getSeg(){return seg; }
string Tiempo ::getMomento_dia(){return momento_dia; }

//SETTERS
void Tiempo::setHora(int h){
    h=hora;
}
void Tiempo::setMin(int m){
    m=min;
}
void Tiempo::setSeg(int s){
    s=seg;
}
void Tiempo::setMomento_dia(string am_pm){
    am_pm=momento_dia;
}

void Tiempo::mostrar_formato(){
    // int mostar_hora= hora % 12 ;//pone la hora tipo 13 es 1  !!!!!!!!!!!!!  PREGUNTAR SI LO DE HORA EN FORMATO 24 HS ES PARA LA HORA INDIVIDUAL ... DSP DE PUNTO G
    // if (mostar_hora == 0) {
    //     mostar_hora = 12;
    // } 
    cout<< setfill('0')<< setw(2)<< hora<< "h, "
    <<setw(2)<< min<< "m, "
    <<setw(2)<< seg << "s "
    << momento_dia<< endl;

}

int Pedir_horario(string ingresa_tiempo,int min, int  max){ //verifico que me pase bien los paraemtros 
    int valor;
    cout<< ingresa_tiempo;
    cin >> valor;

    while(valor< min || valor> max){
        cout<<" Horario fuera de rango! \n "<< ingresa_tiempo;
        cin >> valor;
    }
    
    return valor;
}




/*PREGUNTAR
- fijarme como puede quedar con 0 la hh
-PREG SI ESTA BIEN USAR EXIT 
- (H) LO DE HORA EN FORMATO 24 HS ES PARA LA HORA INDIVIDUAL ... DSP DE PUNTO G
- punto (g) tengo q pregutar si queire ingresar hora , hora y m , h, m y s ? o KE 


Como hacerelo : 
Menu : (te lo guardas )
- default  //corregir ue no se ponga por default 
- hora -h , m
-h.m,s
- h, m,s,am/pm


----  se va este menu 
()
manu 2:
- leer hora?
- leer m
leer s
leer am/pm
modif h
midif m
midif s
imprimir hmspm
imprimir de o a 24 hs ()  no se puede 00a, 60 m 60 s
- opcion de que quiero que termine

- valor erroneo , doy la opcionq  termine */