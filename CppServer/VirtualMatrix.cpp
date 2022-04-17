#include "VirtualMatrix.h"
#include "Disck.h"
#include "Disck.cpp"
VirtualMatrix::VirtualMatrix() {
    crear_Matrix(rows, cols);
    s_Matrix();
}

void VirtualMatrix::crear_Disco() {
    archDisck = fstream("disco", ios::in | ios::out | ios::binary);
    if (!archDisck.good()) {
        ofstream newFile("disco");
        newFile.close();
        archDisck = fstream("disco", ios::in | ios::out | ios::binary);
    }
}

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

vector <const char*> VirtualMatrix::s_Tarjetas() {
    vector <const char*> Tarjetas = {"N1","N2","N3","N4","N5","N6",
                                     "N7","N8","N9","N10","N11","N12",
                                     "N1","N2","N3","N4","N5","N6",
                                     "N7","N8","N9","10N","N11","N12",
                                     "N1","N2","N3","N4","N5","N6",
                                     "N7","N8", "N9", "N10", "N11", "N12"};

    vector <const char*> shuffle_Tarjetas;

    while (!Tarjetas.empty())
    {
        size_t rand_index = rand()%Tarjetas.size();
        shuffle_Tarjetas.push_back(Tarjetas[rand_index]);
        Tarjetas.erase(Tarjetas.begin() + rand_index);
    }

    return shuffle_Tarjetas;
}

void VirtualMatrix::s_Matrix() {

    enMatrix.clear();
    for (int i = 0; i < TarjTotales/3; i++)
    {
        size_t new_i = rand()%rows;
        size_t new_j = rand()%cols;

            enMatrix.push_back(check_Disco(new_i, new_j));

            cout << enMatrix[i].i <<","<< enMatrix[i].j <<" "<< enMatrix[i].image << endl;
    }
}

Tarjeta VirtualMatrix::buscar_enMatrix(int i, int j) {

    Disck disck;
    for (auto & ntarjs : enMatrix){
        if (ntarjs.i == i)
        {
            if (ntarjs.j == j)
            {
                Hit +=1;
                cout << "pageHits: "<< Hit << endl;

                cout<< "............................\n";

                cout<<"La tarjeta en matrix es"<< endl;
                cout << enMatrix[i].i <<","<< enMatrix[i].j <<" "<< enMatrix[i].image << endl;

                return enMatrix[i];

            }
        }
    }
    Fault += 1;
    cout << "pageFaults: " << Fault << endl;
    return disck.get_tarjeta_enDisco(i, j);
}

Tarjeta VirtualMatrix::check_Disco(int i, int j) {

    Tarjeta tarjeta;

        archDisck.seekg((16)*cols*(i)+16*(j), ios::beg);
        archDisck.read((char*) &tarjeta, sizeof(Tarjeta));

    return tarjeta;
}