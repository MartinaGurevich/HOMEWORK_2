#include "Curso.hpp"
#include<iostream>
#include <memory>
#include <vector>

using namespace std; 


int main(){
    
    vector<shared_ptr<Curso>> cursos; //lista de cursos por est
    vector<shared_ptr<Estudiante>> estudiantes;

    int opcion=-1; 
  

    while(opcion!=0){
        cout<<"MENU DE OPCIONES:"<<endl;
        cout<<"¿Que desea hacer? : "<<endl;
        cout<<"0-Salir."<<endl;
        cout<<"1-Crear nuevo curso."<< endl;
        cout<<"2-Inscribir estudiante" <<endl; //opcion a que curso quiere iknsrcbir ,
        cout<<"3-Desinscribir estudiante" <<endl;
        cout<<"4-Cargar nota del estudiante "<< endl;
        cout<<"5-Ver si un estudiante esta inscripto (por legajo) "<<endl;
        cout<<"6-ver si el curso esta completo. "<<endl;
        cout<<"7- Imprimir nombres alfabeticamente "<<endl;
        cout<< "Opción: ";
        cin>> opcion;
        cin.ignore();

  

        string nombre, materia;
        int legajo;
        float nota;

        switch (opcion){

            case 0:
                cout<<"saliendo..."<< endl;
                break;
            case 1:{
                cout<< "Nombre del curso: ";
                getline(cin, materia);
                cursos.push_back(make_shared<Curso>(materia));
                cout<<"Curso creado: " <<materia<< endl;
                break; 
            }


            case 2:{ //inscribo alumno

                cout<<"Nombre del alumno:";
                getline(cin,nombre);
                cout<<"Legajo : ";
                cin>> legajo; cin.ignore();

                shared_ptr<Estudiante> est= nullptr;
                for (auto& e: estudiantes){
                    if(e-> getlegajo()== legajo){
                        est= e;
                        break;
                    }
                }

                if (!est){
                    est= make_shared<Estudiante> (nombre, legajo);
                    estudiantes.push_back(est);
                }

                cout<<"¿En que curso desea inscribirlo?:";
                getline(cin, materia);

                bool curso_encontrado= false;

                for(auto& c: cursos){
                    if(c ->get_nombre_mat()== materia){
                        c-> inscripcion(est);
                        curso_encontrado=true; 
                        break;
                    }
                }
                if(!curso_encontrado){
                    cout<<"Curso no encontrado. Creelo antes de la inscripcion. \n";
                    
                }
                break;
            }



            case 3:{ //desinscribir est

                cout<< "Ingrese el legajo:";
                cin >> legajo; cin.ignore();
                
                cout<<"Nombre del curso: ";
                getline(cin, materia);

                for(auto& c: cursos){
                    if(c ->get_nombre_mat()== materia) {
                        c-> desinscripcion(legajo);
                        break;
                    }
                }
                break;
            }

            case 4: {//cargo nota
                cout<< "legajo del estudiante:";
                cin >> legajo; cin.ignore();
                cout<<"Nombre del curso: ";
                getline(cin, materia);
                cout<< "Nota final del curso: ";
                cin >> nota;

                
                for(auto& est: estudiantes){
                    if(est ->getlegajo()== legajo){
                        est-> agregar_cursos_notas(materia, nota);
                        cout<<"Nota actualizada"<<endl;
                        break;
                    }
                }
                break;
            }
        
            case 5:{
                cout<<"Nombre del curso:";
                getline(cin, materia);

                for(auto& c: cursos){
                    if(c ->get_nombre_mat()== materia){
                        c-> mostrar_estudiantes();
                        break;
                    }
                }
                break;
            }
            case 6:{
                cout<<"Nombre del curso:";
                getline(cin, materia);

                for(auto& c: cursos){
                    if(c-> get_nombre_mat()== materia){
                        if(c->cantidadcurso())
                            cout<<"curso completo. \n";
                        else
                            cout<< "curso con vacantes. \n";
                        
                        break;
                    }
                }
                break;
            }

            case 7:{
                cout<<"Nombre del curso";
                getline(cin,materia);
                
                for(auto& c: cursos){
                    if(c ->get_nombre_mat()== materia){
                        c-> mostrar_ordenAlfabetico();
                        break;
                    }
                }
                break;

            }

            default:
            cout<< "Opcion invalida. \n";
     
            }
        }

        return 0;
}
