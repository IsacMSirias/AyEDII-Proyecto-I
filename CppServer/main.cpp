#include <iostream>
#include "Disck.h"
#include "VirtualMatrix.h"
#include "VirtualMatrix.cpp"


int main(){

    VirtualMatrix *matrix = new VirtualMatrix();

    Disck *disck = new Disck();

    matrix->s_Matrix();
    cout<< "............................\n";
    matrix->buscar_enMatrix(2,6);
    cout<< "............................\n";
    matrix->buscar_enMatrix(1,4);



}