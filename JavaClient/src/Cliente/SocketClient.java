package Cliente;

import java.io.*;
import java.net.Socket;
import java.nio.CharBuffer;

public class SocketClient  implements Runnable{

    String Host = "LocalHost";
    int PORT = 8080;
    BufferedReader input;
    PrintWriter output;
    String Mensaje = "wenas";
    String mensajeServidr = "";
    String Pos = "";


    public void run(){

        try {
            Socket socket = new Socket(Host, PORT);

            input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            output = new PrintWriter(new BufferedWriter(
                    new OutputStreamWriter(socket.getOutputStream())),true);

            output.println(Mensaje);
            
            
            mensajeServidr =  input.readLine();

            Pos = input.readLine();




        } catch (IOException e) {
            e.printStackTrace();
        }


    }
    
}
