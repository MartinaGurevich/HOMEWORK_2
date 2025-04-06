#pragma once
#include <string>
#include <vector>
#include <utility>
#include<iostream>
#include <memory> //uso shared ptr
using namespace std;

class Estudiante
{
private:
    string nombre;
    int legajo; 
    vector<pair<string,float>> Lista_cursos_notas; //lista de cursos con su nota final
    
public:
    
    Estudiante(string nombre, int legajo); 
    
    string getnombre();
    int getlegajo();

    void agregar_cursos_notas(string materia, float nota);
    float calcular_prom() const; //prom de todas las materias, lo uso para inscribir con nota -1(defaualt)
    bool operator< (const Estudiante& otro_estudiante) const;

    friend ostream& operator<< (ostream& os, const Estudiante& e); //para que la otra clase pueda entrar a nombre de est
};


class Curso
{
private:
    string nombre_curso;
    vector<shared_ptr<Estudiante>> estudiantes;
public:
    Curso(const string& nombre_mat);
    string get_nombre_mat() const; 
    //Curso(Estudiante);
    void inscripcion(shared_ptr<Estudiante> estudiante_nuevo); //agrego o saco estudiante
    void desinscripcion (int legajo);
    void mostrar_estudiantes(); 
    shared_ptr <Estudiante> buscar_estudiante(int legajo);
    void mostrar_ordenAlfabetico();
    int cantidadcurso();

    
    /*Esta es una shallow copy del objeto curso. Se copian los punteros compartidos (shared_ptr) a los estudinates,
    por lo tanto el curso original y el curso copiado apuntan a los mismos objetos Estudiante en memoria.
    Uso shared_ptr y permito una shallow copy porque los estuidnates pueden estar inscriptos en 
    muchas materias.*/
    Curso(const Curso& otro)= default;//es mi constructor de copia.

    ~Curso();
};


/*RESPUETA  LA PREGUNTA C: 
la relacion existente entre estudiantes y cursos es de ASOCIACION ya que ambos interactuan sin una fuerte dependencia entre ellos.
No existe un Ownership. */




