#include "Numero.hpp"
#include <string>
#include <iostream>

using namespace std;

int main(){
    //int opcion;

    unique_ptr<Numero> a= make_unique<Entero> (5);
    unique_ptr<Numero> b = make_unique<Entero>(5);


    unique_ptr<Numero> suma= a-> suma(*b);
    unique_ptr<Numero> resta= a-> resta(*b);
    unique_ptr<Numero> mult= a-> multiplicacion(*b);
    
    cout<< "SUMA: " << suma->toString()<< endl;
    cout<< "RESTA: " << resta->toString()<< endl;
    cout<< "MULTIPLICACION: " << mult->toString()<< endl;


    return 0;
    }


