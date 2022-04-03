#include "Disck.h"
#include <string>
#include "tarjeta.h"
#include <iostream>
#include <cstdlib>

using namespace std;

fstream archDisc;

struct tarjetaTemp
{
    int i, j, id, memory;
};


void Disck::cargarDisco(){
    int ntarj = 1;
    for (int i = 1; i <= 6; i++){
        for (int j = 1; j<=5; j++){
            if (ntarj > 3){
                ntarj = 1;
                set_tarjeta_enDisco(i,j,ntarj,0);
                ntarj+=1;
            }else{
                set_tarjeta_enDisco(i,j,ntarj,0);
                ntarj+=1;
            } 
        }
    }  
}




tarjeta Disck::get_tarjeta_enDisco(int i , int j){

    archDisc.open("Disck.txt", ios::in | ios::out | ios::binary);

        archDisc.seekg((i-1)*(4)*sizeof(tarjetaTemp) + (j-1)*sizeof(tarjetaTemp), ios::beg);
        char *buffer = (char*) malloc(sizeof(tarjetaTemp));
        archDisc.read(buffer, sizeof(tarjetaTemp));

                tarjetaTemp* tarjetatemp = (tarjetaTemp*) buffer;

                tarjeta new_tarjeta  = tarjeta(tarjetatemp-> i, tarjetatemp->j, tarjetatemp->id, tarjetatemp->memory);

                // cout<<"Estoy despues de card"<<endl;
                new_tarjeta.obtener_imagen(tarjetatemp->id);
                // cout<<"Estoy despues de get image"<<endl;
                cout<<"La tarjeta que estaba en el disco es: ";
                new_tarjeta.print();
                archDisc.close();
                free(buffer);
                buffer = NULL;

                return new_tarjeta;


}

void Disck::set_tarjeta_enDisco(int i, int j, int id, int memory){
    // cout<<"Estoy en set card"<<endl;
    
    tarjetaTemp tarj;
    tarj.i = i;
    tarj.j = j;
    tarj.id = id;
    tarj.memory = memory;
    archDisc.open("Disck.txt", ios::in | ios::out | ios::binary);
    //if(file.is_open()){
        // cout<<"EStoy en setCard"<<endl;
        archDisc.seekg(((i-1)*(4)*sizeof(tarjetaTemp)+(j-1)*sizeof(tarjetaTemp)),ios::beg);
        archDisc.write((char*)&tarj, sizeof(tarjetaTemp));
        archDisc.close();

}