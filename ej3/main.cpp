#include "Numero.hpp"
#include <string>
#include <iostream>

using namespace std;

int main(){
    //int opcion;

    Numero* a= new Entero(5);
    Numero* b = new Entero(5);


    Numero* suma= a-> suma(*b);
    Numero* resta= a-> resta(*b);
    Numero* mult= a-> multiplicacion(*b);
    
    cout<< "SUMA: " << suma->toString()<< endl;
    cout<< "RESTA: " << resta->toString()<< endl;
    cout<< "MULTIPLICACION: " << mult->toString()<< endl;
    
    delete a;
    delete b;
    delete suma;
    delete resta;
    delete mult;

    return 0;
    }


