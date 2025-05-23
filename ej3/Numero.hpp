#pragma once
#include <string>
#include <iostream>
#include<memory>
using namespace std; 

class Numero //escrita como una clase pero no lo es, todos sus metodos son funciones virtuales puras
{
public:
    virtual unique_ptr<Numero> suma(const Numero& otro_num)=0; //vitual puro , se implementa en las derivadas 
    virtual unique_ptr<Numero> resta(const Numero& otro_num)=0; //uso puntreo para q la clase derivada toma la direcc del num y devuelva lo q necesita
    virtual unique_ptr<Numero> multiplicacion(const Numero& otro_num)=0;
    virtual  string toString()=0;

    virtual ~Numero()= default; //destruccion vrtual

};

class Entero: public Numero
{
private:
    int valor;
public:
    Entero(int v);

    unique_ptr<Numero> suma(const Numero& otro_num) override;
    unique_ptr<Numero> resta(const Numero& otro_num) override;
    unique_ptr<Numero> multiplicacion(const Numero& otro_num) override;
    string toString () override;

    ~Entero() override; //el metodo va a ser sobreescrito

};


class Real: public Numero
{
private:
    float valor_real;
public:
    Real(float valor_real);

    unique_ptr<Numero> suma(const Numero& otro_num) override;
    unique_ptr<Numero> resta(const Numero& otro_num) override;
    unique_ptr<Numero> multiplicacion(const Numero& otro_num) override;

    string toString () override;
    ~Real() override;
};


class Complejo: public Numero
{
private:
    float parte_real;
    float parte_imaginaria;

public:
    Complejo(float real, float imaginario);
    
    
    unique_ptr<Numero> suma(const Numero& otro_num) override;
    unique_ptr<Numero> resta(const Numero& otro_num) override;
    unique_ptr<Numero> multiplicacion(const Numero& otro_num) override;

    string toString () override;
    
    ~Complejo() override;
};


//funcion para imprimir 

void imprimir_operaciones(const unique_ptr<Numero>& a,const unique_ptr<Numero>& b);




