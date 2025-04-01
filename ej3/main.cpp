#include "Numero.hpp"
#include <string>
#include <iostream>

using namespace std;

int main(){
    //entero
    cout<<"---------------------OPERACIONES DE ENTEROS------------------------"<<endl;
    unique_ptr<Numero> a_ent= make_unique<Entero> (5);
    unique_ptr<Numero> b_ent = make_unique<Entero>(5);
    imprimir_operaciones(a_ent,b_ent);


    //real 
    cout<<"---------------------OPERACIONES DE REALES------------------------"<<endl;

    unique_ptr<Numero> a_real= make_unique<Real> (5.9);
    unique_ptr<Numero> b_real = make_unique<Real>(5.3);
    imprimir_operaciones(a_real,b_real);

    cout<<"---------------------OPERACIONES DE COMPLEJOS------------------------"<<endl;
    unique_ptr<Numero> a_complejo= make_unique<Complejo >(5,2);
    unique_ptr<Numero> b_complejo= make_unique<Complejo >(2,6);
    
    unique_ptr<Numero> suma= a_complejo-> suma(*b_complejo);
    unique_ptr<Numero> resta= a_complejo-> resta(*b_complejo);
    unique_ptr<Numero> mult= a_complejo-> multiplicacion(*b_complejo);

    cout<< "SUMA DE " << suma->toString()<< endl;
    cout<< "RESTA DE " << resta->toString()<< endl;
    cout<< "MULTIPLICACION DE " << mult->toString()<< endl;

    return 0;
}


