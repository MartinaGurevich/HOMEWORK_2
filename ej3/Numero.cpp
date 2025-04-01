#include "Numero.hpp"
#include <string>
#include <memory>

 
//constructores de entero 
Entero:: Entero(int v): valor(v){} 
Entero::~Entero()= default;

unique_ptr<Numero> Entero::suma(const Numero& otro_num){
    const Entero* ent= dynamic_cast<const Entero*> (&otro_num); //conviento otro_num en tipo entero
    if(!ent){
        throw invalid_argument("el numero no es un int.");
    }
    return make_unique<Entero>(this-> valor+ ent->valor); 
}
unique_ptr<Numero> Entero:: resta(const Numero& otro_num){
    const Entero* ent= dynamic_cast<const Entero*> (&otro_num); //conviento otro_num en tipo entero
    if(!ent){
        throw invalid_argument("el numero no es un int.");
    }
    return make_unique <Entero>(this-> valor- ent->valor); 
}

unique_ptr<Numero> Entero:: multiplicacion(const Numero& otro_num){
    const Entero* ent= dynamic_cast<const Entero*> (&otro_num); //conviento otro_num en tipo entero
    if(!ent){
        throw invalid_argument("el numero no es un int.");
    }
    return make_unique<Entero>(this-> valor * ent->valor);  //CORREGIR ESTO 
}


string Entero:: toString(){
    return "Entero: " + to_string(valor);
}



