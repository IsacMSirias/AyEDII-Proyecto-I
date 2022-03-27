package SocketClient;

import java.io.*;
import java.net.Socket;
import java.nio.CharBuffer;

public class Client implements Runnable{

    String Host = "LocalHost";
    int PORT = 8080;
    BufferedReader input;
    PrintWriter output;
    String Mensaje = "wenas \n";

    
    String Mensaje2 = "Muy wenas";
    String mensajeServidr = "";
    String Pos = "";


    public void run(){

        try {
            Socket socket = new Socket(Host, PORT);

            input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            output = new PrintWriter(new BufferedWriter(
                    new OutputStreamWriter(socket.getOutputStream())),true);



            output.println(Mensaje);
            

            output.println(Mensaje2);
            
            
            mensajeServidr =  input.readLine();

            System.out.println(mensajeServidr);

            Pos = input.readLine();
            System.out.println(Pos);

    

        } catch (IOException e) {
            e.printStackTrace();
        }


    }
    
}