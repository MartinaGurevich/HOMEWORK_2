#include "Tiempo.h"
#include<iostream>
#include <string>
#include <iomanip>
using namespace std; 

int main(){

    
    int opcion;

    cout<<"¿Que desea ingresar? : "<<endl;
    cout<<"PRIMER MENU:"<<endl;
    cout<<"0-Hora incializada en 0"<<endl;
    cout<<"1-Solo Hora"<<endl;
    cout<<"2-Solo Hora y min "<<endl;
    cout<<"3-Solo Hora , min , seg "<<endl;
    cout<<"4- Todo junto(Hora , min , seg y a.m./p.m.) "<<endl;
    cout<< "Opción: ";
    cin>> opcion;

    Tiempo t; //var ddentro de la opcion.

    int h,m,s, nueva_hora, nuevo_min, nuevo_seg;
    string am_pm, nuevo_momento;
    

    switch (opcion)
    {
        case 0:
            t= Tiempo();
            break;
        case 1:
            h= Pedir_horario(">> Ingrese la hora: ",0,23);
            t= Tiempo(h);
            break;
        case 2:
            h= Pedir_horario(">> Ingrese la hora: ",0,23);
            m= Pedir_horario(">> Ingrese los minutos: ",0,59);
            t= Tiempo(h,m);
            break;
        case 3:
            h= Pedir_horario(">> Ingrese la hora: ",0,23);
            m= Pedir_horario(">> Ingrese los minutos: ",0,59);
            s= Pedir_horario(">> Ingrese los segundos: ",0,59);
            t= Tiempo(h,m,s);
            break;
        case 4:
            h= Pedir_horario(">> Ingrese la hora: ",0,23);
            m= Pedir_horario(">> Ingrese los minutos: ",0,59);
            s= Pedir_horario(">> Ingrese los segundos: ",0,59);
            cout<<">> Ingrese a.m./ p.m.: ";
            cin>>am_pm;
            t= Tiempo(h,m,s,am_pm);
            break;
        default:
            cout<<" opcion invalida. \n";
            return 1;
    }

    t.mostrar_formato();


    cout<< "----------------------------------SEGUNDO MENU-----------------------------------------\n";
    //menu 2       
    int eleccion= -1;
    while(eleccion!=0){
        cout<<"¿Que desea leer o cambiar? : "<<endl;
        
        cout<<"0- Salir."<<endl;
        cout<<"1- Ver solo la hora"<<endl;
        cout<<"2- Ver solo minutos"<<endl;
        cout<<"3- Ver solo segundos "<<endl;
        cout<<"4- Ver si se trata de a.m / p.m "<<endl;
        cout<<"5- Ver todo junto "<<endl;
        cout<<"6- Modificar hora "<<endl;
        cout<<"7- Modificar minutos "<<endl;
        cout<<"8- Modificar segundos "<<endl;
        cout<<"9- Modificar a.m / p.m "<<endl;
        cout<<"10- Ver hora en formato de hora 0 a 24 "<< endl;
        cout<< "Opción: ";
        cin>> eleccion;


        switch (eleccion) 
        {   case 0: 
                break;
            case 1:
                cout<<"La hora es: " <<t.getHora()<< "h"<< endl;
                break;
            case 2:
                cout<<"Los min son: " <<t.getMin()<< "m"<< endl;
                break;
            case 3:
                cout<<"Los seg son: " <<t.getSeg()<< "s"<< endl;
                break;
            case 4:
                cout<<"El momento del dia es: " <<t.getMomento_dia()<< endl;
                break;
            case 5:
                t.mostrar_formato();                
                break;
            case 6:
                nueva_hora= Pedir_horario("modifique hora:",0,23);
                t.setHora(nueva_hora);
                cout<< "Hora actualizada: ";
                cout<< setfill('0')<< setw(2)<<nueva_hora<< "h"<< endl;
                break;
            case 7:
                nuevo_min= Pedir_horario("modifique min:",0,59);
                t.setMin(nuevo_min);
                cout<< "Min actualizado: ";
                cout<< setfill('0')<< setw(2)<<nuevo_min<< "m"<< endl;
                break;
            case 8:
                nuevo_seg= Pedir_horario("modifique seg:",0,59);
                t.setSeg(nuevo_seg);
                cout<< "Min actualizado: ";
                cout<< setfill('0')<< setw(2)<<nuevo_seg<< "s"<< endl;
                break;
            case 9:
                cout<<"Modifique am/pm:";
                cin>> nuevo_momento;
                t.setMomento_dia(nuevo_momento);
                cout<< "Momento actualizado: ";
                cout<<nuevo_momento<< endl;
                break;
            case 10:
                t.mostar_formato_24();
                break;

            default:
                cout<<" opcion invalida. \n";
                return 1;
            }
    }
    return 0;
}



