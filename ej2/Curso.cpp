#include "Curso.h" //incluyo calse estudiante y clase curso
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
//constructores estudiante

Estudiante:: Estudiante(string nombre, int legajo): nombre(nombre), legajo(legajo) {}

//getters
int Estudiante:: getlegajo(){return legajo;}
string Estudiante:: getnombre(){return nombre;}

//agrego datos alumno
void Estudiante:: agregar_cursos_notas(){
    int nota;
    string Materia;
    Lista_cursos_notas.push_back({Materia,nota});
}


//calculo prom geberal de cada uno
float Estudiante:: calcular_prom() const{
    float sumatoria=0;
    for (const auto& par: Lista_cursos_notas){
        sumatoria += par.second; //accedo a la nota
}
    return sumatoria/Lista_cursos_notas.size();
}

//operador < para comparar el nombre 
bool Estudiante:: operator<(const Estudiante& otro_estudiante) const {
    return nombre< otro_estudiante.nombre;
}

// operador << para el cout
ostream & operator << (ostream& os, const Estudiante& e){
    os << "NOMBRE: " <<e.nombre
        <<"--> legajo"<< e.legajo
        <<"--> Promedio: "<<e.calcular_prom();
}


/// //////
Curso::Curso()= default;

void Curso:: inscripcion(shared_ptr<Estudiante> estudiante_nuevo){
    estudiantes.push_back(estudiante_nuevo);
}

void Curso:: desinscripcion(int legajo){
    for (auto e = estudiantes.begin(); e != estudiantes.end(); e++) { //e= iterador
        if ((*e)-> getlegajo() == legajo ){
            cout<< "Estudiante" << (*e)-> getnombre()<< "eliminado/a. \n";
            estudiantes.erase(e);
            
            break;
        }
    }
}

void Curso:: mostar_estudiantes(){
    for (auto e = estudiantes.begin(); e != estudiantes.end(); e++) {
        cout<<"NOMBRE: "<< (*e)->getnombre()<< endl;
        cout<<" --> Legajo: "<< (*e)->getlegajo()<< endl;
        cout<<" --> Promedio: "<< (*e)-> calcular_prom()<< endl;

    }
}

int Curso:: cantidadcurso(){
    int contador=0; // para ver cuantos estudiantes hay
    int lugares_dispo= estudiantes.size()-contador;
   
    for (auto e = estudiantes.begin(); e != estudiantes.end(); e++){  //ver si este for es correcto 
        contador += 1;
    }

        if (contador> 20){
                cout<<" Capacidad del curso completa.";
        }else{
            cout<<"al curso le quedan"<< lugares_dispo<< "lugares disponibles"<<endl; //fijarme si devuekvo contador , o hacer funcion contador quev me devuekva un int
        }
        return 0; //?
}

void Curso:: mostar_ordenAlfabetico(){
    auto copia_lista_estudiantes= estudiantes; // para no modificar la lista original
    
    sort(copia_lista_estudiantes.begin(), copia_lista_estudiantes.end(), [](const auto& est1, const auto& est2){
        return *est1 < *est2;
    });
    
    for (const auto& est: copia_lista_estudiantes){
        cout<< *est<< endl;
    }
}

Curso::~Curso() {}
