package mian;

import GUI.VentanaMenu;
import SocketClient.Client;

public class App {
    public static void main(String[] args) throws Exception {



        
        Client client =  new Client();

        client.run();
        
    }
}
