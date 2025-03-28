#include "Tiempo.h"
#include<iostream>
#include <string>
using namespace std; 

int main(){
    
    Tiempo t;
    cout<<">> hora aún sin parametros:  ";
    t.mostrar_formato(); //se inicializa sin parametros

    int h;
    cout<< ">> ingrese hora: ";
    cin >> h;
    
    Tiempo t1(h);
    t1.mostrar_formato();
    
    int m;
    cout<< ">> ingrese min: ";
    cin >> m;

    Tiempo t2(h,m);
    t2.mostrar_formato();

    int s;
    cout<< ">> ingrese seg: ";
    cin >> s;

    Tiempo t3(h,m,s);
    //cout<<"horario ingresado: " ;
    t3.mostrar_formato();

    string am_o_pm;
    cout<<">> ingrese p.m. / a.m.: ";
    cin >> am_o_pm;

    Tiempo t4(h,m,s, am_o_pm);
    t4.mostrar_formato();

    return 0;
}


