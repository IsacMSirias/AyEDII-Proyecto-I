#include "Disck.h"
#include <string>

#include <iostream>
#include <cstdlib>

using namespace std;

fstream archDisck;



Disck::Disck(){

    crear_Disco();

}

void Disck::crear_Disco(){

}
Tarjeta Disck::get_tarjeta_enDisco(int i, int j){

    archDisck.open("disco", ios::in | ios::out | ios::binary);


    archDisck.seekg((i-1)*(4)*sizeof(Tarjeta)+(j-1)*sizeof(Tarjeta), ios::beg);
    char *buffer = (char*) malloc(sizeof(Tarjeta));
    archDisck.read(buffer, sizeof(Tarjeta));

    Tarjeta* tarj = (Tarjeta*) buffer;

    Tarjeta tarjeta = *tarj;


    //cout<< "............................\n";

    //cout<<"La tarjeta en disco es : ";

    //cout << tarj->i <<","<< tarj->j <<" "<<","<<tarj->image<<   endl;
    archDisck.close();
    free(buffer);
    buffer = nullptr;

    return tarjeta;

}

void Disck::set_tarjeta_enDisco(int i, int j, const char* image){

    Tarjeta tarjeta;
    tarjeta.i = i;
    tarjeta.j = j;
    tarjeta.image = image;

    archDisck.open("disco", ios::in | ios::out | ios::binary);

    archDisck.seekg(((i-1)*(4)*sizeof(Tarjeta)+(j-1)*sizeof(Tarjeta)),ios::beg);
    archDisck.write((char*)&tarjeta, sizeof(Tarjeta));
    archDisck.close();



}

