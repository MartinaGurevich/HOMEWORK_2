#include "Banco.hpp"
#include <string>
#include <memory>

using namespace std;

//constructor caja ed ahorrod
Cajadeahorro::Cajadeahorro(double dinero_dispo): CuentaBancaria(dinero_dispo, "nombre") {}

double Cajadeahorro:: retirar( double monto_retirar){
    

    if(monto_retirar> balance){
        cout<<"monto supera el balance de la caja de ahorro."<<endl;
        return 0;
    }else{
        balance-= monto_retirar;
        cout<<"Usted ha retirado $"<< monto_retirar <<"exitosamente"<< endl;
        return monto_retirar;
    }
}

void Cajadeahorro:: mostrar_info(){
    contador_mostrar++;

    cout<< "INFO DEL USUARIO:\n ";
    cout<<"Nombre del Titular: "<<titularCuenta<< endl;
    cout<<"Balance dispnible: $"<< balance<< endl;
    cout<<"Tipo de cuenta: CAJA DE AHORRO" <<endl;

    if(contador_mostrar >2){
        cout<<"Se descuentan $20 por pedir dos veces la info."<<endl;

        balance-=20;
    }

}


//cuenta corrinete 

//constructor 
CuentaCorriente:: CuentaCorriente (double balance_inicial, string titular, Cajadeahorro* caja)
: CuentaBancaria(balance_inicial,titular), caja_de_ahorro(caja) {}

double CuentaCorriente:: retirar(double monto){
    if(balance >= monto){
        balance -=monto;
        cout<< "Usted ha retirado : $"<< monto <<" desde la Cuenta Corriente" << endl;
        return monto;
    }else{
        double faltante= monto- balance;
        double Retirar_de_caja= caja_de_ahorro-> retirar(faltante);
    

        if(Retirar_de_caja>0){
            double total_retitado= balance + Retirar_de_caja; //lo que quedaba de la cuenta corriente mas lo q logre sacar de la caja de ahorro.
            balance= 0;  //porque saque la plata q le quedaba
            cout<<"Usted ah retirado $ "<< total_retitado<<"desde la Cuenta Corriente y Caja de Ahorro."<<endl;
            return total_retitado;

            }else{
                aviso(*this);//friend
                return 0;
            }
        }
    

    }

//funcion friend

void aviso(const CuentaCorriente& cuenta){
    cout<<"la Cuenta de ahorro y la caja de Ahorro asociada no tienen fondos suficientes."<<endl;
}





