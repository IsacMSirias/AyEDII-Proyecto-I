#include <iostream>
#include "Disck.h"
#include "VirtualMatrix.h"
#include "VirtualMatrix.cpp"


int main(){

    VirtualMatrix *matrix = new VirtualMatrix();

    Disck *disck = new Disck();

    matrix->s_Matrix();
    matrix->print_matrix();
    cout<< "............................\n";
    //matrix->buscar_enMatrix(1,4);
    //cout<< "............................\n";
    //matrix->buscar_enMatrix(5,3);
     //cout<< "............................\n";
    //disck ->get_tarjeta_enDisco(5,3);
    cout<<"el vector tiene" <<": "<<matrix->enMatrix.size()<< "  Tarjetas"<<endl;

    matrix->print_matrix();


 



}