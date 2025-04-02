#include "Banco.hpp"

int main(){

    cout<<" INICIALIZO PRUEBAS...\n";

    cout<<" ..................CAJA DE AHORRO........................\n";
    Cajadeahorro Micaja(200, "MARTINA");

//inicializo mi cuenta
    Micaja.depositar(50);
    Micaja.mostrar_info();

//prueba de retirar dinero
    cout<<"-------------RETIRO DE DINERO---------------"<<endl;
    cout<<" 1) PRIMER RETIRO. \n";
    Micaja.retirar(50);

    cout<<"-------------------------------------\n"<< endl;

    cout<<" 2) SEGUNDO RETIRO:"<<endl;
    Micaja.retirar(120); 

    cout<<"-------------------------------------\n"<<endl;

    cout<<"--> PIDO INFO SEGUNDA VEZ:"<<endl;
    Micaja.mostrar_info();
    
    cout<<"-------------------------------------\n"<<endl;

    cout<<"--> PIDO INFO POR TERCERA VEZ:"<<endl;
    Micaja.mostrar_info(); //RESTA 20 PESOS POR PEDIR INFO MAS DE DOS VECES

    cout<<"-------------------------------------\n"<<endl;

    cout<<"--> RETIRO DINERO:\n";
    Micaja.retirar(80); //NO SE RETIRA NADA PORQUE NO ALCANZA EL MONTO DE LA CAJA DE AHORRO



    //VERIFICACIONES DE CUENTA CORRIENTE
    cout<<"-------------------------------------\n"<<endl;

    cout<<"...............PRUEBA DE CUENTA CORRIENTE...................\n";
    CuentaCorriente Micorriente(50,"MARTINA", &Micaja);
    Micorriente.mostrar_info();

    cout<<"1) PRIMER RETIRO:\n";
    Micorriente.retirar(10); //muestro que se puede sacar plata de la cuenta corriente
    cout<<"2) SEGUNDO RETIRO:\n";
    Micorriente.retirar(80);  // mestro que lo de la cuenta corrinete no alcanza, le pido a la caja de ahorro

    cout<< "--------------------------------------------------------------\n";
    //CASO CAJA DE AHORRO TAMPOCO TIENE DINERO:
    cout<<"RETIRO DE LA CAJA DE AHORRO.\n";
    Micaja.retirar(30);

    cout<<"-->RETIRO EN CUENTA CORRIENTE:\n";
    Micorriente.retirar(80); // demuestro que la cuenta no podsee mas dinero 

    //verifico estado=0 de la cuenta corriente y estado de la caja de ahorro 
    cout<< "--------------------------------------------------------------\n";
    cout<< "CUENTA EN CERO\n";

    Micaja.mostrar_info(); 
    Micorriente.mostrar_info();
    return 0;
}