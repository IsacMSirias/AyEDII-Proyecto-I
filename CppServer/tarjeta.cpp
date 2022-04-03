#include "tarjeta.h"
#include <string>


tarjeta::tarjeta(int pos_i, int pos_j, int id, int memory){
    
    this->pos_i = pos_i;
    this->pos_j = pos_j;
    this-> id = id;
    this->memory = memory;
}

void tarjeta::obtener_imagen(int id){

    switch (id)
    {
    case 1:

        this->imgprovisional = "Numero1.png";
        break;
    
    case 2:

        this->imgprovisional = "Numero2.png";
        break;
    
    case 3:

        this->imgprovisional = "Numero3.png";
        break;
    
    case 4:

        this->imgprovisional = "Numero4.png";
        break;
    
    case 5:

        this->imgprovisional = "Numero5.png";
        break;
    
    case 6:

        this->imgprovisional = "Numero6.png";
        break;
    
    case 7:

        this->imgprovisional = "Numero7.png";
        break;
    
    case 8:

        this->imgprovisional = "Numero8.png";
        break;
    
    case 9:

        this->imgprovisional = "Numero9.png";
        break;
    
    case 10:

        this->imgprovisional = "Numero10.png";
        break;
    
    case 11:

        this->imgprovisional = "Numero11.png";
        break;
    

    default:

        cout<<"Lo lamento papeh, no hay imagen"<< endl;
        break;
    }


}