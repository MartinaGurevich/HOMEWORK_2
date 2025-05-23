#include <iomanip>
#include <iostream>
#include "Tiempo.hpp"
#include <string>

using namespace std;

//a, constructor sin parametros para q impirma  0h, 0m, 0s a.m.
Tiempo::Tiempo() : hora(0), min(0), seg(0), momento_dia("am") {} 

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
    hora= h;
}
void Tiempo::setMin(int m){
    min= m;
}
void Tiempo::setSeg(int s){
    seg=s;
}
void Tiempo::setMomento_dia(string am_pm){
    momento_dia= am_pm;
}


void Tiempo::mostrar_formato(){
    int mostar_hora= hora % 12 ;
    cout<< setfill('0')<< setw(2)<< mostar_hora<< "h, "
    <<setw(2)<< min<< "m, "
    <<setw(2)<< seg << "s "
    << momento_dia<< endl;

}

void Tiempo :: mostar_formato_24(){
    int hora_24= hora;

    if(momento_dia== "p.m." && hora < 12){
        hora_24 += 12;
    } else if (momento_dia == "a.m." && hora == 12) // las 12 del mediodida las cuento como 00 por el motivo que la hora ingresda va de 0 a 23.
    {
        hora_24= 0; //12 del mediodia.
        }

    cout<< setfill('0')<< setw(2)<< hora_24<< "h, "
    <<setw(2)<< min<< "m, "
    <<setw(2)<< seg << "s "<< endl;
    
}

int Pedir_horario(string ingresa_tiempo,int min, int  max){ //verifico que me pase bien los parametros 
    int valor;
    cout<< ingresa_tiempo;
    cin >> valor;

    while(valor< min || valor> max){
        cout<<" Horario fuera de rango! \n "<< ingresa_tiempo;
        cin >> valor;
    }
    
    return valor;
}




