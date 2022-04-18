
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
    char buffer1[1024] = {0};
    char buffer2[1024] = {0};
     char buffer3[1024] = {0};
    char buffer4[1024] = {0};
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

    matrix->s_Matrix();


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



        while (1){

            if (turno){

                cout<<"JUGADOR 1"<<endl;

                read(new_socket, buffer1, 1024);
                read(new_socket, buffer2, 1024);
                read(new_socket, buffer3, 1024);
                read(new_socket, buffer4, 1024);

                int i = stoi(buffer1);
                int j = stoi(buffer2);

                int i2 = stoi(buffer3);
                int j2 = stoi(buffer4);

                cout << "primera carta: "<< i << "," <<j<< endl;
                cout << "primera carta: "<< i2 << "," <<j2<< endl;

                 Tarjeta tar1 = matrix->buscar_enMatrix(i,j);

                Tarjeta tar2 =matrix->buscar_enMatrix(i2,j2);

                cout<<tar1.image <<","<<tar2.image<<endl;

                if(tar1.image == tar2.image){
                cout<<"match"<<endl;
                }else{
                    cout<<"No match"<<endl;
                }
                
                
            turno = false;


            }else{
                cout <<"JUGADOR 2"<<endl;

                read(new_socket, buffer1, 1024);
                read(new_socket, buffer2, 1024);
                read(new_socket, buffer3, 1024);
                read(new_socket, buffer4, 1024);

                int i = stoi(buffer1);
                int j = stoi(buffer2);

                int i2 = stoi(buffer3);
                int j2 = stoi(buffer4);

                cout << "primera carta: "<< i << "," <<j<< endl;
                cout << "primera carta: "<< i2 << "," <<j2<< endl;

                 Tarjeta tar1 = matrix->buscar_enMatrix(i,j);

                Tarjeta tar2 =matrix->buscar_enMatrix(i2,j2);

                cout<<tar1.image <<","<<tar2.image<<endl;

                if(tar1.image == tar2.image){
                cout<<"match"<<endl;
                }else{
                    cout<<"No match"<<endl;
                }
                
                
            turno = true;

            }

            

        }





    }

}