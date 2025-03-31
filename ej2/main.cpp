#include "Curso.h"
#include<iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std; 

int main(){
    int opcion; 

  
    cout<<"MENU DE OPCIONES:"<<endl;
    cout<<"¿Que desea hacer? : "<<endl;
    cout<<"0-Salir."<<endl;
    cout<<"1-Inscribir estudiante al curso" <<endl;
    cout<<"2-Desinscribir estudiante al curso" <<endl;
    cout<<"3-Ver si un estudiante esta inscripto (por legajo) "<<endl;
    cout<<"4-ver si el curso esta completo. "<<endl;
    cout<<"5- Imprimir nombres alfabeticamente "<<endl;
    cout<< "Opción: ";
    cin>> opcion;

    Curso curso;

    string nombre, materia;
    int promedio, legajo;

    switch (opcion){

        case 0:
            break;
        case 1:{
            cout<< "A quien desea inscribir al curso ?:";
            cin.ignore();
            getline(cin,nombre); // el nombre puede tener espacios
            
            cout<< "Ingrese el legajo de "<<nombre<<":";
            cin >> legajo;

            //creo estudiante con shared ptr

            auto nuevo_estudiante_ptr = make_shared<Estudiante> (nombre, legajo);
            curso.inscripcion(nuevo_estudiante_ptr);
            break;
        }
        default:
            break;
        }
}
