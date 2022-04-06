#include "tarjeta.h"
#include <string>




tarjeta::tarjeta(int i, int j, int id, int status){
    
    this->i = i;
    this->j = j;
    this->id = id;
    this->status = status;

}
void tarjeta::get_image(int type){
    switch (type)
    {
    case 1:
        this->img= "Numero1.png";
        break;
    case 2:
        this->img = "Numero2.png";
        break;
    case 3:
        this->img = "Numero3.png";
        break;
    case 4:
        this->img = "Numero4.png";
        break;
    case 5:
        this->img = "Numero5.png";
        break;
    case 6:
        this->img = "Numero6.png";
        break;
    case 7:
        this->img = "Numero7.png";
        break;
    case 8:
        this->img = "Numero8.png";
        break;
    case 9:
        this->img = "Numero9.png";
        break;
    case 10:
        this->img = "Numero10.png";
        break;
    default:
        cout<<"No hay imagen"<<endl;
        break;
    }
}
void tarjeta::print() const{
    std::cout<<this->id<<" "<<this->img<<" "<<this->status<<std::endl;
}
