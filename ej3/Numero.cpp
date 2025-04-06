#include "Numero.hpp"
#include <string>
#include <memory>

void imprimir_operaciones(const unique_ptr<Numero>& a,const unique_ptr<Numero>& b){
    auto suma= a-> suma(*b);
    auto resta= a-> resta(*b);
    auto mult= a-> multiplicacion(*b);

    cout<< "SUMA DE " << suma->toString()<< endl;
    cout<< "RESTA DE " << resta->toString()<< endl;
    cout<< "MULTIPLICACION DE " << mult->toString()<< endl;
}
 
//constructores de entero 
Entero:: Entero(int v): valor(v){} 
Entero::~Entero()= default;

unique_ptr<Numero> Entero::suma(const Numero& otro_num){
    const Entero* ent= dynamic_cast<const Entero*> (&otro_num); //convierto otro_num en tipo entero
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
    return make_unique<Entero>(this-> valor * ent->valor);  
}


string Entero:: toString(){
    return "Entero: " + to_string(valor);
}


//constructores de Real
Real:: Real(float v): valor_real(v){} 
Real::~Real()= default;

unique_ptr<Numero> Real::suma(const Numero& otro_num){
    const Real* re= dynamic_cast<const Real*> (&otro_num); //conviento otro_num en tipo real
    if(!re){
        throw invalid_argument("el numero no es un real.");
    }
    return make_unique<Real>(this-> valor_real+  re->valor_real); 
}

unique_ptr<Numero> Real::resta(const Numero& otro_num){
    const Real* re= dynamic_cast<const Real*> (&otro_num); //conviento otro_num en tipo real
    if(!re){
        throw invalid_argument("el numero no es un real.");
    }
    return make_unique<Real>(this-> valor_real -   re->valor_real); 
}

unique_ptr<Numero> Real::multiplicacion(const Numero& otro_num){
    const Real* re= dynamic_cast<const Real*> (&otro_num); //conviento otro_num en tipo real
    if(!re){
        throw invalid_argument("el numero no es un real.");
    }
    return make_unique<Real>(this-> valor_real *  re->valor_real); 
}

string Real:: toString(){
    return "Real: " + to_string(valor_real);
}

//comlejo
Complejo:: Complejo(float r, float i): parte_real(r), parte_imaginaria(i){}
Complejo::~Complejo()= default;

unique_ptr<Numero> Complejo::suma(const Numero& otro_num){
    const Complejo* comp= dynamic_cast<const Complejo*> (&otro_num); //conviento otro_num en tipo complejo
    if(!comp){
        throw invalid_argument("el numero no es un complejo.");
    }
    return make_unique<Complejo> (
        this-> parte_real +  comp->parte_real,
        this-> parte_imaginaria + comp->parte_imaginaria); 
}

unique_ptr<Numero> Complejo::resta(const Numero& otro_num){
    const Complejo* comp= dynamic_cast<const Complejo*> (&otro_num); //conviento otro_num en tipo complejo
    if(!comp){
        throw invalid_argument("el numero no es un complejo.");
    }
    return make_unique<Complejo> (
        this-> parte_real -  comp->parte_real,
        this-> parte_imaginaria - comp->parte_imaginaria); 
}

unique_ptr<Numero> Complejo::multiplicacion(const Numero& otro_num){
    const Complejo* comp= dynamic_cast<const Complejo*> (&otro_num); //conviento otro_num en tipo complejo
    if(!comp){
        throw invalid_argument("el numero no es un complejo.");
    }
    float real = this-> parte_real * comp->parte_real - this->parte_imaginaria * comp->parte_imaginaria;
    float imag = this-> parte_real * comp->parte_imaginaria + this->parte_imaginaria * comp->parte_real;
    return make_unique <Complejo> (real,imag);
}

string Complejo:: toString(){
    return "complejo: " + to_string(parte_real) + "+" + to_string(parte_imaginaria) + "i";
}