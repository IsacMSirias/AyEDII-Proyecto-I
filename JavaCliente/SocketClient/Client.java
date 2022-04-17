package SocketClient;

import java.io.*;
import java.net.Socket;
import java.nio.CharBuffer;

public class Client implements Runnable{

    String Host = "LocalHost";
    int PORT = 8080;
    BufferedReader input;
    static PrintWriter output;
    String Mensaje = "wenas \n";

    
    String Mensaje2 = "Muy wenas";
    String mensajeServidr = "";
    String Pos = "";

    public static int i_cliente;

    public void run(){

        try {
            Socket socket = new Socket(Host, PORT);

            input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            output = new PrintWriter(new BufferedWriter(
                    new OutputStreamWriter(socket.getOutputStream())),true);


            while(true){

                mensajeServidr =  input.readLine();

                System.out.println(mensajeServidr);


            }

        } catch (IOException e) {
            e.printStackTrace();
        }


    }

    public static void sendPosiciones(int i,int j, int i2, int j2){

        output.println(i);
        output.println(j);
        output.println(i2);
        output.println(j2);

    }
    
}
