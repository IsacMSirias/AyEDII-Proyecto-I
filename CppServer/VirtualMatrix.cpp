#include "VirtualMatrix.h"

/**
 * @brief Contructor que crea a la matriz
 */

VirtualMatrix::VirtualMatrix() {
    crear_Matrix(rows, cols);

}

/**
 * @brief metodo que se encarga de crear el archivo en donde se almacenan todas las cartas
 * 
 */

void VirtualMatrix::crear_Disco() {
    archDisck = fstream("disco", ios::in | ios::out | ios::binary);
    if (!archDisck.good()) {
        ofstream newFile("disco");
        newFile.close();
        archDisck = fstream("disco", ios::in | ios::out | ios::binary);
    }
}

/**
 * @brief Crea la matriz completa de objetos tarjeta 
 * 
 * @param rows 
 * @param cols 
 */

void VirtualMatrix::crear_Matrix(int rows, int cols) {

    crear_Disco();

    vector <const char*> Vector_tarjetas = s_Tarjetas();
    Tarjeta matrix[rows][cols];
    int nTarjs = 0;
    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            matrix[i][j].i = i;
            matrix[i][j].j= j;

            matrix[i][j].image = Vector_tarjetas[nTarjs];

            nTarjs++;
        }
    }

    archDisck.write((char*) &matrix, sizeof(Tarjeta[rows][cols]));
}


/**
 * @brief realiza un random a todas las imagenes que contiene el vector de tarjetas
 * 
 * @return shuffle_Tarjetas devuelve el vector de chars revuelto
 */
vector <const char*> VirtualMatrix::s_Tarjetas() {
    vector <const char*> Tarjetas = {"N1","N2","N3","N4","N5","N6",
                                    "N1","N2","N3","N4","N5","N6",
                                    "N1","N2","N3","N4","N5","N6",
                                    "N1","N2","N3","N4","N5","N6",
                                    "N1","N2","N3","N4","N5","N6",
                                    "N1","N2","N3","N4","N5","N6"};

    vector <const char*> shuffle_Tarjetas;

    while (!Tarjetas.empty())
    {
        size_t rand_i = rand()%Tarjetas.size();
        shuffle_Tarjetas.push_back(Tarjetas[rand_i]);
        Tarjetas.erase(Tarjetas.begin() + rand_i);
    }

    return shuffle_Tarjetas;
}



/**
 * @brief metodo que le hace un shuffle a la matriz en memoria 
 * 
 */
void VirtualMatrix::s_Matrix() {

    enMatrix.clear();

    srand(time(0));
    for (int i = 0; i < TarjTotales/3; i++)
    {
        size_t new_i = rand()%rows;
        size_t new_j = rand()%cols;

            enMatrix.push_back(check_Disco(new_i, new_j));
    }
    //print_matrix();
}


/**
 * @brief imprime la matrix en consola para poder tener un mejor manejo del flujo del codigo  
 * 
 */

void VirtualMatrix::print_matrix(){

    int limit = this->enMatrix.size();
    for(int n = 0; n < limit ; n++){
        this->enMatrix[n].print_Tarjeta();
    }

}

/**
 * @brief Imprime las tarjetas que ya no se pueden usar en el juego
 * 
 */
void VirtualMatrix::print_fuera_de_martix(){

    int limit = this->fuera_de_Matrix.size();
    for(int n = 0; n < limit ; n++){
        this->fuera_de_Matrix[n].print_Tarjeta();
    }

}

/**
 * @brief Busca la tarjeta solicitada en matriz, si no la encuentra en matriz, llama al metodo reempazar
 * @param i
 * @param j 
 * @return reemplazar(i,j)
 */

Tarjeta VirtualMatrix::buscar_enMatrix(int i, int j) {

    Disck disck;
    for (size_t n = 0; n < enMatrix.size(); n++){
        if (enMatrix[n].i == i)
        {
            if (enMatrix[n].j == j)
            {
                Hit +=1;
                
                return enMatrix[n];

            }
        }

    }
    Fault += 1;
    return reemplazar(i,j);
}

/**
 * @brief cheeckea el disco para poder hacer un random de todas las tarjetas
 * @param i
 * @param j 
 * @return tarjeta 
 */

Tarjeta VirtualMatrix::check_Disco(int i, int j) {

    Tarjeta tarjeta;

        archDisck.seekg((16)*cols*(i)+16*(j), ios::beg);
        archDisck.read((char*) &tarjeta, sizeof(Tarjeta));

    return tarjeta;
}



/**
 * @brief remplaza una tarjeta al azar de la matriz por la posision i, j en disco seleccionada por el usuario
 * @param i
 * @param j 
 * @return tarjeta 
 */

Tarjeta VirtualMatrix :: reemplazar(int i, int j){

    Disck disck;

    srand(time(0));

    if (this-> enMatrix.size() > 0){

        int ntar = rand()%this->enMatrix.size();

        int temp_i = this->enMatrix[ntar].i;
        int temp_j = this->enMatrix[ntar].j;
        const char* temp_image = this-> enMatrix[ntar].image;

        disck.set_tarjeta_enDisco(temp_i, temp_j, temp_image);

        this->enMatrix.erase(this->enMatrix.begin()+ntar);
        

    }

    Tarjeta tarjeta = disck.get_tarjeta_enDisco(i,j);
    this->enMatrix.push_back(tarjeta);

    return tarjeta;
}


/**
 * @brief Elimina una tarjeta de matrix
 * @param i
 * @param j 
 */

void VirtualMatrix::eliminar_tarjeta(Tarjeta tar){

    Disck disc;

    int total_tarjs = this->enMatrix.size();

    for(int n = 0; n < total_tarjs; n++){

        if(enMatrix[n].i == tar.i){

            if(enMatrix[n].j == tar.j){
                
                enMatrix.erase(enMatrix.begin()+n);

            }
        
        }

    }
     
}

/**
 * @brief Este metodo hace varias cosas, pero para explicar si comportamiento, toma dos tarjetas y compara sus imagenes para ver 
 * si son iguales, si son iguales elimina alguna de las dos tarjetas si es que se encuentran en memoria y la almacena en las 
 * tarjetas que ya no se pueden usar, en el caso de que se realice el match, la matriz vuelve a hacer Shuffle.
 * @param tar1
 * @param tar2
 */


void VirtualMatrix::match(Tarjeta tar1, Tarjeta tar2){

    int total_tarjs = this->enMatrix.size();

    if(tar1.image == tar2.image){

        cout<<"Se encontro un par de tarjetas"<<endl;
        cout<<"\n";

        for(int n = 0; n < total_tarjs; n++){

            if(enMatrix[n].i == tar1.i){

                if(enMatrix[n].j == tar1.j){
                    
                    this->eliminar_tarjeta(tar1);
                    this->fuera_de_Matrix.push_back(tar1);
                    TarjTotales -=1;

                }
            
            }
        }

        for(int n = 0; n < total_tarjs; n++){

            if(enMatrix[n].i == tar2.i){

                if(enMatrix[n].j == tar2.j){
                    
                    this ->eliminar_tarjeta(tar2);
                    this->fuera_de_Matrix.push_back(tar2);
                    TarjTotales -=1;


                }
            
            }

         }   

    this->s_Matrix();
    cout<<"----Nueva Matrix en Memoria-----"<<endl;
    this->print_matrix();
    
    }else{
    cout<<"No se encontro una pareja de cartas"<<endl;
    cout<<"\n";

    }
    
}

/**
 * @brief metodo que obtiene el numero de tarjetas totales que se encuentran en memoria
 * @return retorna el numero de tarjetas totales 
 */

int VirtualMatrix::get_tarjetas_totales(){
   
    return this->TarjTotales;

}
int VirtualMatrix::get_pageHits(){
   
    return this->Hit;

}

int VirtualMatrix::get_pageFaults(){
   
    return this->Fault;

}



/**
 * @brief metodo que indica si dos tarjetas hicieron match o no 
 * @param tar1
 * @param tar2
 * @return bool que indica si se realizo o no un match 
 */

bool VirtualMatrix:: es_match(Tarjeta tar1, Tarjeta tar2){

    if(tar1.image == tar2.image){
        return true;
    }else{
        return false;
    }
}




