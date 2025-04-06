#include "Banco.hpp"
#include <string>
#include <memory>

using namespace std;

//INSTANCIO cuenta bancaria
CuentaBancaria:: CuentaBancaria(double balance_inicial, string titular): balance(balance_inicial), titularCuenta(titular) {} //tengoq ue dejar esto sino me tira error 
   

//constructor caja ed ahorrod
Cajadeahorro::Cajadeahorro(double dinero_dispo, string titular): CuentaBancaria(dinero_dispo, titular) {}

//ingreso dinero en  caja de ahorro 
void Cajadeahorro:: depositar(double dinero_ingresado){
     balance+= dinero_ingresado;
}
double Cajadeahorro:: retirar( double monto_retirar){
    

    if(monto_retirar> balance){
        cout<<"ERROR! Monto supera el balance de la caja de ahorro."<<endl;
        cout<<"Su balance actual es: $"<<balance<<"\n"<<endl;
        return 0;
    }else{
        balance-= monto_retirar;
        cout<<"Usted ha retirado $"<< monto_retirar <<" exitosamente de la Caja de Ahorro."<< endl;
        return monto_retirar;
    }
    return 0;
}

void Cajadeahorro:: mostrar_info(){
    contador_mostrar++;

    if(contador_mostrar >2){
        cout<<"¡Se descuentan $20 por pedir mas de dos veces la info! "<<endl;

        balance-=20;
    }

    cout<<"INFO DEL USUARIO: "<<endl;
    cout<<"Nombre del Titular: "<<titularCuenta<< endl;
    cout<<"Balance dispnible: $"<< balance<< endl;
    cout<<"Tipo de cuenta: CAJA DE AHORRO" <<endl;


}


//cuenta corrinete 

//constructor 
CuentaCorriente:: CuentaCorriente (double balance_inicial, string titular, Cajadeahorro* caja)
: CuentaBancaria(balance_inicial,titular), caja_de_ahorro(caja) {}

//ingreso deinero en cuegta corriente
void CuentaCorriente:: depositar(double dinero_ingresado){
    balance+= dinero_ingresado;
}

void CuentaCorriente:: mostrar_info(){

    cout<<"INFO DEL USUARIO: "<<endl;
    cout<<"Nombre del Titular: "<<titularCuenta<< endl;
    cout<<"Balance dispnible: $"<< balance<< endl;
    cout<<"Tipo de cuenta: CUENTA CORRIENTE" <<endl;

}

double CuentaCorriente:: retirar(double monto){
    if(balance >= monto){
        balance -=monto;
        cout<< "Usted ha retirado : $"<< monto <<" desde la Cuenta Corriente" << endl;
        return monto;
    }else{
        double faltante= monto - balance;
        double Retirar_de_caja= caja_de_ahorro-> retirar(faltante);
    

        if( Retirar_de_caja >= faltante){
            double total_retitado= balance + Retirar_de_caja; //lo que quedaba de la cuenta corriente mas lo q logre sacar de la caja de ahorro.
             //porque saque la plata q le quedaba
            cout<<"Usted ha retirado en total $"<< total_retitado<<" de la Cuenta Corriente y Caja de Ahorro."<<endl;
            balance= 0; 
            return total_retitado;

            }else{
                cout<<"No fue posible retirar $"<<faltante<< "de la caja de ahorro."<<endl;
                aviso(*this);//friend
                return 0;
            }
        }
    

    }

//funcion friend

void aviso(const CuentaCorriente& cuenta){
    cout<<"la Cuenta de ahorro y la caja de Ahorro asociada no tienen fondos suficientes."<<endl;
}





