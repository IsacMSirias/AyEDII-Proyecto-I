#include <iostream>
#include "Disck.h"
#include "VirtualMatrix.h"
#include "VirtualMatrix.cpp"


int main(){

    VirtualMatrix *matrix = new VirtualMatrix();

    Disck *disck = new Disck();

    matrix->s_Matrix();
    cout<< "............................\n";
    matrix->buscar_enMatrix(2,2);
    cout<< "............................\n";
    matrix->buscar_enMatrix(1,4);


   // cout << disck ->get_tarjeta_enDisco(1,6).image <<"\n";
    //cout<< "............................\n";
   // matrix->buscar_enMatrix(1,6);









}