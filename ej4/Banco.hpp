#pragma once
#include <string>
#include <iostream>
#include<memory>
using namespace std;


class CuentaBancaria
{
protected: //uso protected por el motivo que las clases derivadas pueden tener acceso a estos atributos 
    double balance;
    string titularCuenta;
public:
    
    CuentaBancaria(double balance_inicial, string titular);
    void depositar(double dinero);
    virtual double retirar(double dinero)=0;
    virtual void mostrar_info()=0;

   virtual ~CuentaBancaria()= default;
};

//derivadas

class Cajadeahorro : public CuentaBancaria
{
private:
    int contador_mostrar=0;
public:
    
    Cajadeahorro(double dinero_dispo, string titular);
    void depositar(double dinero); //
    double retirar(double monto) override;
    void mostrar_info() override; //aca se hace el decuento

    ~Cajadeahorro() override = default;
};

class CuentaCorriente: public CuentaBancaria
{
private:
    Cajadeahorro* caja_de_ahorro; //caja de ahorro asociada 
public:

    
    CuentaCorriente(double balance_inicial, string titular, Cajadeahorro* caja);
    
    void depositar(double dinero_ingresado);

    double retirar(double dinero) override;

    void mostrar_info() override;

    friend void aviso(const CuentaCorriente& cuenta);

    ~CuentaCorriente() override= default;
};





