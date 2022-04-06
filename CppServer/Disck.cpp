#include "Disck.h"
#include <string>
#include "tarjeta.h"
#include <iostream>
#include <cstdlib>

using namespace std;

fstream archDisck;

struct Tarjeta
{
    int i, j, id, status;
};


void Disck::crear_Disco(){
    int n = 1;
    for (int i = 1; i <= 6; i++){
        for (int j = 1; j<=6; j++){
            if (n > 10){
                n = 1;
                set_tarjeta_enDisco(i,j,n,0);
                n+=1;
            }else{
                set_tarjeta_enDisco(i,j,n,0);
                n+=1;
            }
        }
    }
}
tarjeta Disck::get_tarjeta_enDisco(int i, int j){
 
    archDisck.open("disck.txt", ios::in | ios::out | ios::binary);

       
        archDisck.seekg((i-1)*(4)*sizeof(Tarjeta)+(j-1)*sizeof(Tarjeta), ios::beg);
        char *buffer = (char*) malloc(sizeof(Tarjeta));
        archDisck.read(buffer, sizeof(Tarjeta));

        Tarjeta* tarj = (Tarjeta*) buffer;
        tarjeta new_tarj = tarjeta(tarj->i, tarj->j, tarj->id, tarj->status);
        
            new_tarj.get_image(tarj->id);
   
            cout<<"La tarjeta en disco es : ";
            new_tarj.print();
            archDisck.close();
            free(buffer);
            buffer = NULL;

            return new_tarj;
         
}

void Disck::set_tarjeta_enDisco(int i, int j, int id, int status){
  
    Tarjeta tarjeta;
    tarjeta.i = i;
    tarjeta.j = j;
    tarjeta.id = id;
    tarjeta.status = status;

        archDisck.open("disck.txt", ios::in | ios::out | ios::binary);
    
            archDisck.seekg(((i-1)*(4)*sizeof(Tarjeta)+(j-1)*sizeof(Tarjeta)),ios::beg);
            archDisck.write((char*)&tarjeta, sizeof(Tarjeta));
            archDisck.close();

    

}

