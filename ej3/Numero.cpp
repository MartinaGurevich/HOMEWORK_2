#include "Numero.hpp"
#include <string>
 
//constructores de entero 
Entero:: Entero(int v): valor(v){} 
Entero::~Entero()= default;

Numero* Entero::suma(const Numero& otro_num){
    const Entero* ent= dynamic_cast<const Entero*> (&otro_num); //conviento otro_num en tipo entero
    if(!ent){
        throw invalid_argument("el numero no es un int.");
    }
    return new Entero(this-> valor+ ent->valor); 
}

Numero* Entero:: resta(const Numero& otro_num){
    const Entero* ent= dynamic_cast<const Entero*> (&otro_num); //conviento otro_num en tipo entero
    if(!ent){
        throw invalid_argument("el numero no es un int.");
    }
    return new Entero(this-> valor- ent->valor); 
}

Numero* Entero:: multiplicacion(const Numero& otro_num){
    const Entero* ent= dynamic_cast<const Entero*> (&otro_num); //conviento otro_num en tipo entero
    if(!ent){
        throw invalid_argument("el numero no es un int.");
    }
    return new Entero(this-> valor * ent->valor); 
}


string Entero:: toString(){
    return "Entero: " + to_string(valor);
}



