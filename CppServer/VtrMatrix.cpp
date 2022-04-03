#include <cstdlib>
#include "VtrMatrix.h"
#include <string>
#include "Disck.h"
#include <iostream>

using namespace std;

void VtrMatrix ::Build_Matrix(){

    Disck disco;

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 5; i++)
        {
            this ->tarjeta_Matrix.push_back(disco.get_tarjeta_enDisco(i,j));
        }
        
    }
    

}

tarjeta VtrMatrix ::get_tarjeta_enMemoria(int i, int j){

    for (int ntar  = 0; ntar < 10; i++)
    {
        if (this->tarjeta_Matrix[ntar].pos_i == i && this->tarjeta_Matrix[ntar].pos_j == j) 
        {
            cout <<"objeto encontrado en matrix: ";
            this->tarjeta_Matrix[ntar].print();
            cout <<"retorno el objeto ";
            this->tarjeta_Matrix[ntar].print();
            return this->tarjeta_Matrix[ntar];
        }
        
    }
    
    cout<< "No se encontro el objeto en la matriz" << endl;

    tarjeta tarjeta = reemplazar(i, j);
    return tarjeta;

}

tarjeta VtrMatrix ::reemplazar(int i, int j){
    Disck Disck;

    int ntar = rand()%10;

    cout<< "se elimina la posicion"<< ntar<< endl;

    cout <<"el objeto se elimino";

    this ->tarjeta_Matrix[ntar].print();

    int i = this->tarjeta_Matrix[ntar].pos_i;
    int j = this->tarjeta_Matrix[ntar].pos_j;

    int id = this->tarjeta_Matrix[ntar].id;
    int memory = this->tarjeta_Matrix[ntar].memory;

    Disck.set_tarjeta_enDisco(i, j, id, memory);
    this->tarjeta_Matrix.erase(this->tarjeta_Matrix.begin()+ntar);

    tarjeta tarjeta = Disck.get_tarjeta_enDisco(i, j);
    this->tarjeta_Matrix.push_back(tarjeta);
    cout<<"en nuevo objeto es"<<endl;

    this->tarjeta_Matrix[9].print();
    
    cout<<"matriz actualizada"<<endl;

    this->print_VtrMatrix();

    return tarjeta;

}

void VtrMatrix ::print_VtrMatrix(){
    for (int numtarj = 0; numtarj < 10; numtarj++)
    {
        this->tarjeta_Matrix[numtarj].print();
    }
    
}