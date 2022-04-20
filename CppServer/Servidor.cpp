
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#include "VirtualMatrix.h"
#include "VirtualMatrix.cpp"

#define PORT 8080
int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address{};
    int opt = 1;
    int addrlen = sizeof(address);

    char pos_i [1024] = {0};
    char pos_j[1024] = {0};

    char pos_i2[1024] = {0};
    char pos_j2[1024] = {0};


    char _pos_i [1024] = {0};
    char _pos_j[1024] = {0};

    char _pos_i2[1024] = {0};
    char _pos_j2[1024] = {0};

    char Jugador_1[1024] = {0};
    char Jugador_2[1024] = {0};

    bool turno = true;


    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *) &address,
             sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }


    VirtualMatrix *matrix = new VirtualMatrix();

    cout<<"---------matrix en memoria----------"<<endl;

    matrix->s_Matrix();
    matrix->print_matrix();
    srand(time(0));
    int turnoran = rand()%7;
    cout<<turnoran<<endl;

    while (1) {

        if (listen(server_fd, 3) < 0) {
            perror("listen");
            exit(EXIT_FAILURE);
        }
        if ((new_socket = accept(server_fd, (struct sockaddr *) &address,
                                 (socklen_t *) &addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }


        read(new_socket, Jugador_1, 1024);
        read(new_socket, Jugador_2, 1024);

       

       

        if (turnoran%2 == 0){
             
             while (1){

                if (turno){

                    cout<<"-------------------------"<<endl;

                    cout<<"JUGADOR 1: "<<Jugador_2<<endl;
                    cout<<"\n";

                    read(new_socket, pos_i, 1024);
                    read(new_socket, pos_j, 1024);
                    read(new_socket, pos_i2, 1024);
                    read(new_socket, pos_j2, 1024);

                    int i = stoi(pos_i);
                    int j = stoi(pos_j);

                    int i2 = stoi(pos_i2);
                    int j2 = stoi(pos_j2);

                    cout << "primera carta: "<< i << "," <<j<< endl;
                    cout << "segunda carta: "<< i2 << "," <<j2<< endl;

                    cout<<"\n";

                    Tarjeta tar1 = matrix->buscar_enMatrix(i,j);

                    Tarjeta tar2 =matrix->buscar_enMatrix(i2,j2);

                    cout<<"Las imagenes respectivas son: "<<tar1.image <<","<<tar2.image<<endl;
                    cout<<"\n";

                    matrix->match(tar1,tar2);
                    cout<<"\n";


                    cout<<"Ya no se pueden usar las siguientes tarjetas"<<endl;
                    
                    matrix->print_fuera_de_martix();
                    
                    turno = false;


                }else{

                    cout<<"-------------------------"<<endl;
                    cout<<"JUGADOR 2: "<<Jugador_1<<endl;

                    cout<<"\n";

                    read(new_socket, _pos_i, 1024);
                    read(new_socket, _pos_j, 1024);
                    read(new_socket, _pos_i2, 1024);
                    read(new_socket, _pos_j2, 1024);

                    int _i = stoi(_pos_i);
                    int _j = stoi(_pos_j);

                    int _i2 = stoi(_pos_i2);
                    int _j2 = stoi(_pos_j2);

                    cout << "primera carta: "<< _i << "," <<_j<< endl;
                    cout << "primera carta: "<< _i2 << "," <<_j2<< endl;
                    cout<<"\n";

                    Tarjeta _tar1 = matrix->buscar_enMatrix(_i,_j);

                    Tarjeta _tar2 =matrix->buscar_enMatrix(_i2,_j2);
                    cout<<"\n";

                    cout<<"Las imagenes respectivas son: "<<_tar1.image <<","<<_tar2.image<<endl;
                    cout<<"\n";

                    matrix->match(_tar1, _tar2);
                    cout<<"\n";


                    cout<<"Ya no se pueden usar las siguientes tarjetas"<<endl;
                    
                    matrix->print_fuera_de_martix();


                    
                    turno = true;

                }

             }

        }else{

             while (1){

                if (turno){

                    cout<<"-------------------------"<<endl;

                    cout<<"JUGADOR 1: "<<Jugador_1<<endl;

                    cout<<"\n";

                    read(new_socket, pos_i, 1024);
                    read(new_socket, pos_j, 1024);
                    read(new_socket, pos_i2, 1024);
                    read(new_socket, pos_j2, 1024);

                    int i = stoi(pos_i);
                    int j = stoi(pos_j);

                    int i2 = stoi(pos_i2);
                    int j2 = stoi(pos_j2);

                    cout << "primera carta: "<< i << "," <<j<< endl;
                    cout << "primera carta: "<< i2 << "," <<j2<< endl;
                     cout<<"\n";

                    Tarjeta tar1 = matrix->buscar_enMatrix(i,j);

                    Tarjeta tar2 =matrix->buscar_enMatrix(i2,j2);

                    cout<<"Las imagenes respectivas son: "<<tar1.image <<","<<tar2.image<<endl;
                     cout<<"\n";

                    matrix->match(tar1, tar2);
                    cout<<"\n";


                    cout<<"Ya no se pueden usar las siguientes tarjetas"<<endl;
                    
                    matrix->print_fuera_de_martix();
                    
                    
                turno = false;


                }else{

                    cout<<"-------------------------"<<endl;
                    cout<<"JUGADOR 2: "<<Jugador_2<<endl;
                     cout<<"\n";

                    read(new_socket, _pos_i, 1024);
                    read(new_socket, _pos_j, 1024);
                    read(new_socket, _pos_i2, 1024);
                    read(new_socket, _pos_j2, 1024);

                    int _i = stoi(_pos_i);
                    int _j = stoi(_pos_j);

                    int _i2 = stoi(_pos_i2);
                    int _j2 = stoi(_pos_j2);

                    cout << "primera carta: "<< _i << "," <<_j<< endl;
                    cout << "primera carta: "<< _i2 << "," <<_j2<< endl;
                     cout<<"\n";

                    Tarjeta _tar1 = matrix->buscar_enMatrix(_i,_j);

                    Tarjeta _tar2 =matrix->buscar_enMatrix(_i2,_j2);

                    cout<<"Las imagenes respectivas son: "<<_tar1.image <<","<<_tar2.image<<endl;

                    matrix->match(_tar1,_tar2);
                    cout<<"\n";

                    cout<<"Ya no se pueden usar las siguientes tarjetas"<<endl;
                    
                    matrix->print_fuera_de_martix();
                    
                    
                turno = true;

                }

            }

        }       
       
    }

}