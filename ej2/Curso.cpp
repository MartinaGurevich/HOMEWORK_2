#include "Curso.hpp" //incluyo calse estudiante y clase curso
#include <algorithm>

//constructores estudiante


//ESTUDIANTE
Estudiante:: Estudiante(string nombre, int legajo): nombre(nombre), legajo(legajo) {}

//getters
int Estudiante:: getlegajo(){return legajo;}
string Estudiante:: getnombre(){return nombre;}

//agrego datos alumno
void Estudiante:: agregar_cursos_notas(string materia, float nota){
    for (auto& curso_nota: Lista_cursos_notas){
        if(curso_nota.first == materia){
            curso_nota.second= nota; //actualizo nota si ya existe
            return;
        }
    }
    //si no existe la agrego
    Lista_cursos_notas.push_back({materia,nota});
}


//calculo prom general de cada uno
float Estudiante:: calcular_prom() const{
    float sumatoria=0;
    for (const auto& par: Lista_cursos_notas){
        sumatoria += par.second; //accedo a la nota
}
   
   return Lista_cursos_notas.empty() ? 0: sumatoria/Lista_cursos_notas.size();
}


//operador < para comparar el nombre 
bool Estudiante:: operator<(const Estudiante& otro_estudiante) const {
    return nombre< otro_estudiante.nombre;
}

// operador << para el cout
ostream & operator << (ostream& os, const Estudiante& e){
    os << "NOMBRE: " <<e.nombre
        <<"--> Legajo: "<< e.legajo
        <<"--> Promedio: "<<e.calcular_prom();
    return os;
}


// CURSO
Curso::Curso(const string& nombre_cur): nombre_curso(nombre_cur) {}

string Curso:: get_nombre_mat() const{
    return nombre_curso;
}

void Curso:: inscripcion(shared_ptr<Estudiante> estudiante_nuevo){
    if (estudiantes.size() >= 20){
        cout<<"Este curso esta completo.\n";
        return;
    }

    estudiantes.push_back(estudiante_nuevo);
    estudiante_nuevo ->agregar_cursos_notas(nombre_curso,-1); //-1 por default
}

void Curso:: desinscripcion(int legajo){
    for (auto e = estudiantes.begin(); e != estudiantes.end(); ++e) { //e= iterador
        if ((*e)-> getlegajo() == legajo ){
            cout<< "Estudiante -" << (*e)-> getnombre()<< " - desinscripto/a. \n";
            estudiantes.erase(e);
            return;
        }
    }
    cout<<"legajo no encontrado. \n ";
}

void Curso:: mostrar_estudiantes(){
    if (estudiantes.empty()){
        cout<<"No hay estudiantes inscriptos"<< endl;
        return;
    }

    cout<<"LISTA DE ESTUDIANTES: \n"<< endl;

    for(const auto& est : estudiantes){
        if(est){
            cout <<*est<<"\n";
        }
    }
}

shared_ptr<Estudiante> Curso:: buscar_estudiante(int legajo){
    for(auto& e: estudiantes){
        if (e-> getlegajo()== legajo){
            return e; //aca ya me lo corta 
        }
    }
    return nullptr;
}

int Curso:: cantidadcurso(){

    int cantidad= estudiantes.size();


    if (cantidad >= 20){
            cout<<" Capacidad del curso completa.\n";
    }else{
        cout<<"Todavia hay "<< (20- cantidad)<<" lugares disponibles en el curso."<<endl; 
    }
    return cantidad; 
}

void Curso:: mostrar_ordenAlfabetico(){
    auto copia_lista_estudiantes= estudiantes; // para no modificar la lista original
    
    sort(copia_lista_estudiantes.begin(), copia_lista_estudiantes.end(), [](const shared_ptr<Estudiante>& est1, const shared_ptr<Estudiante>& est2){
        return *est1 < *est2;
    });
    
    for (const auto& est: copia_lista_estudiantes){
        if(est){
            cout<< *est<< endl;
        }
    }
}

Curso::~Curso() {}
