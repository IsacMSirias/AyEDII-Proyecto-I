package Main;

import GUI.*;
import Cliente.SocketClient;

public class Main {
    public static void main(String[] args) {


        SocketClient socketClient = new SocketClient();

        socketClient.run();

        
    }
}
