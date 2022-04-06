#include "Disck.h"
#include "Disck.cpp"

int main(){
    
    Disck *disco = new Disck();

    disco->crear_Disco();
    disco->get_tarjeta_enDisco(1,4);
    disco->get_tarjeta_enDisco(1,2);
    disco->get_tarjeta_enDisco(1,1);
    disco->set_tarjeta_enDisco(1,4, 5, 0);
    disco->get_tarjeta_enDisco(1,4);


} 