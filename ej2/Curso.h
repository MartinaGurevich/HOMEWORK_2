#pragma once
#include <string>
#include <vector>
#include <utility>
#include <memory> //uso shared ptr
using namespace std;

class Estudiante
{
private:
    string nombre;
    int legajo; 
    vector<pair<string,float>> Lista_cursos_notas;
    
public:
    
    Estudiante(string nombre, int legajo); //contrsuctor / objerto
    
    string getnombre();
    int getlegajo();

    void agregar_cursos_notas();
    float calcular_prom() const; //prom de todas las materias
    bool operator< (const Estudiante& otro_estudiante) const;

    friend ostream& operator<< (ostream& os, const Estudiante& e); //para que la otra calse pued entrar a nombre de esta
};


class Curso
{
private:
    vector<shared_ptr<Estudiante>> estudiantes;
public:
    Curso();
    Curso(Estudiante);
    void inscripcion(shared_ptr<Estudiante> estudiante_nuevo); //agrego o saco estudiante
    void desinscripcion (int legajo);
    void mostar_estudiantes(); //veo cuantso son en el curso 
    void mostar_ordenAlfabetico();
    int cantidadcurso();
    ~Curso();
};




