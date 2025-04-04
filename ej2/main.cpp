#include "Curso.hpp"
#include<iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std; 
//guarfdarme materia y estudiante y crear curso antes q 
//string curso[]; //por estudiante hay una lista de cursos. 

int main(){
    int opcion=-1; 
    Curso curso;

    while(opcion!=0){
        cout<<"MENU DE OPCIONES:"<<endl;
        cout<<"¿Que desea hacer? : "<<endl;
        cout<<"0-Salir."<<endl;
        cout<<"1-Inscribir estudiante a un  curso" <<endl; //opcion a que curso quiere iknsrcbir ,
        cout<<"2-Ingresar notas del alumno "<< endl;
        cout<<"3-Desinscribir estudiante al curso" <<endl;
        cout<<"4-Ver si un estudiante esta inscripto (por legajo) "<<endl;
        cout<<"5-ver si el curso esta completo. "<<endl;
        cout<<"6- Imprimir nombres alfabeticamente "<<endl;
        cout<< "Opción: ";
        cin>> opcion;

  

        string nombre, materia;
        int promedio, legajo, nota;

        switch (opcion){

            case 0:
                cout<<"saliendo..."<< endl;
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

                cout<<"A que curso lo desea inscribir?: " ; //ESTOOOOO
                cin>> curso; //FIJARESE STOOOOO

                //muestro lista de como queda con el nuevo 
                curso.mostrar_estudiantes(); //aca igual, quieor q me muestre toda la lista
                break;
            }

            case 2:{

                cout<< "Ingrese legajo del alumno: ";

                cin>> legajo;
                cin.ignore();



                auto estudiante= curso.buscar_estudiante(legajo);
                if (estudiante== nullptr){
                    cout<<"estudiante no encontrado." << endl;
                    break;
                }


                cout<< "Ingrese materia: "; //
                cin.ignore();
                getline(cin,materia);
            
                cout<< "Ingrese nota de la materia: ";
                cin>> nota;

                estudiante-> agregar_cursos_notas(materia, nota);

                cout<<"------------notas cargadas exitosamente------------------ \n";

                curso.mostrar_estudiantes();
                break;

            }


            case 3:{
                cout<< "A quien desea desinscribir del curso ?:";
                cin.ignore();
                getline(cin,nombre);

                cout<< "Ingrese el legajo de "<<nombre<<":";
                cin >> legajo;

                //borro estudante
                curso.desinscripcion(legajo);
                curso.mostrar_estudiantes(); //ver porque me muestra el ultimo nada mas 

                break;
            }

            case 4:
            {

                cout<< "Ingrese legajo del alumno: ";
                cin>> legajo;

                auto estudiante= curso.buscar_estudiante(legajo);

                if(estudiante != nullptr){
                    cout<<"el estudiante << "<< estudiante->getnombre()<< ">> pertenece al curso.\n";
                }else{
                    cout<< "el estudiante no pertenece al curso\n.";
                }
                break;
            }
            case 5:{
                curso.cantidadcurso();
                break;
            }
            case 6:{
                curso.mostar_ordenAlfabetico();
                break;
            }


            default:
                break;
            }
        }
}
