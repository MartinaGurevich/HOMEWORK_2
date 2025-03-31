#pragma once
#include <string>
#include <iostream>
using namespace std;

class Numero //escrita como una clase pero no lo es, todos sus metodos son funciones virtuales puras
{
private:
    int numero;
public:
    virtual float suma()=0; //vitual puro , se impleenta en lsa dervadas 
    virtual float resta()=0;
    virtual float multiplicacion()=0;
    virtual  string toString()=0;

};

class Entero: public Numero
{
private:
    /* data */
public:
    Entero: public Numero(/* args */);
    ~Entero: public Numero();
};

Entero: public Numero::Entero: public Numero(/* args */)
{
}

Entero: public Numero::~Entero: public Numero()
{
}

class Real
{
private:
    /* data */
public:
    Real(/* args */);
    ~Real();
};

Real::Real(/* args */)
{
}

Real::~Real()
{
}


class Complejo
{
private:
    /* data */
public:
    Complejo(/* args */);
    ~Complejo();
};

Complejo::Complejo(/* args */)
{
}

Complejo::~Complejo()
{
}


