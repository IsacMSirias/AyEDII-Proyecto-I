package SocketClient;

import java.io.*;
import java.net.Socket;

import GUI.VentanaMenu;


/**
 * Esta clase maneja la el flujo de datos por medio de sockets del cliente
 */

public class Client implements Runnable{

      /**
     * host por el cual se va a conectar el cliente
     */
    String Host = "LocalHost";
       /**
     * Puerto por el cual se va a conectar el cliente
     */
    int PORT = 8080;
      /**
     * el buffer que se recibe por parte del servidor
     */
    BufferedReader input;
      /**
     * el output por donde se mandan las peticiones del cliente
     */
    static PrintWriter output;
    
      /**
     * almacena los nombres de los jugadores que se le enviaran al servidor
     */

    String nombreJugador1 = VentanaMenu.Jugador1;
    String nombreJugador2 = VentanaMenu.Jugador2;
    public static int i_cliente;

      /**
     * metodo por el cual se inicia la conexion del cliente con el servidor
     */

    public void run(){

        try {

            
            Socket socket = new Socket(Host, PORT);

            input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            output = new PrintWriter(new BufferedWriter(
                    new OutputStreamWriter(socket.getOutputStream())),true);


                    output.println(nombreJugador1);
                    output.println(nombreJugador2);

        } catch (IOException e) {
            e.printStackTrace();
        }


    }

      /**
     * Metodo que envia las posiciones de los botones de la matriz grafica al servidor 
     */

    public static void sendPosiciones(int i,int j, int i2, int j2){

        output.println(i);
        output.println(j);
        output.println(i2);
        output.println(j2);

    }
    
}
