#include "Curso.hpp" //incluyo calse estudiante y clase curso
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
//constructores estudiante

Estudiante:: Estudiante(string nombre, int legajo): nombre(nombre), legajo(legajo) {}

//getters
int Estudiante:: getlegajo(){return legajo;}
string Estudiante:: getnombre(){return nombre;}

//creo el curso para el alumno 
void Estudiante::crear_curso(int legajo){ //
   int nombre_materia;
    vector<string> materia= // fijarse como hacer, yo quiero que cada estudiante tenga su lista de cursos, antes de inscribirlo debe haber una instancia de cracion de curso patra que el est se pueda inscrubir 

}

//agrego datos alumno
void Estudiante:: agregar_cursos_notas(string materia, float nota){
    Lista_cursos_notas.push_back({materia,nota});
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
    return os;
}


/// //////
Curso::Curso()= default;

void Curso:: inscripcion(shared_ptr<Estudiante> estudiante_nuevo){
    estudiantes.push_back(estudiante_nuevo);
}

void Curso:: desinscripcion(int legajo){
    for (auto e = estudiantes.begin(); e != estudiantes.end(); e++) { //e= iterador
        if ((*e)-> getlegajo() == legajo ){
            cout<< "Estudiante -" << (*e)-> getnombre()<< " - eliminado/a. \n";
            estudiantes.erase(e);
            
            break;
        }
    }
}

void Curso:: mostrar_estudiantes(){
    if (estudiantes.empty()){
        cout<<"no hay estudiantes"<< endl;
        return;
    }
    cout<<"LISTA DE ESTUDIANTES: \n"<< endl;
    for (auto e = estudiantes.begin(); e != estudiantes.end(); ++e) {
        cout<<"NOMBRE: "<< (*e)->getnombre()<< endl;
        cout<<" --> Legajo: "<< (*e)->getlegajo()<< endl;
        cout<<" --> Promedio: "<< (*e)-> calcular_prom()<< endl;

    }
}

shared_ptr<Estudiante> Curso:: buscar_estudiante(int legajo){
    for(auto& e: estudiantes){
        if (e-> getlegajo()== legajo){
            //cout<<"el estudinate esta en el curso.\n";
            return e; //aca ya me lo corta 
        }
    }
    return nullptr;
}

int Curso:: cantidadcurso(){
    int contador=1; // para ver cuantos estudiantes hay
   
    for (auto e = estudiantes.begin(); e != estudiantes.end(); e++){  //ver si este for es correcto 
        contador += 1;
    }

        if (contador> 20){
                cout<<" Capacidad del curso completa.\n";
        }else{
            cout<<"Todavia hay lugares disponibles en el curso."<<endl; //fijarme si devuekvo contador , o hacer funcion contador quev me devuekva un int
        }
        return 0; //?
}

void Curso:: mostar_ordenAlfabetico(){
    auto copia_lista_estudiantes= estudiantes; // para no modificar la lista original
    
    sort(copia_lista_estudiantes.begin(), copia_lista_estudiantes.end(), [](const auto& est1, const auto& est2){
        return *est1 < *est2;
    });
    
    for (const auto& est: copia_lista_estudiantes){
        if(est){
            cout<< *est<< endl;
        }
    }
}

Curso::~Curso() {}
