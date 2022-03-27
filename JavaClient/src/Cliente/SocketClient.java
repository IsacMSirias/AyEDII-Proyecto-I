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


    public void run(){

        try {
            Socket socket = new Socket(Host, PORT);

            input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            output = new PrintWriter(new BufferedWriter(
                    new OutputStreamWriter(socket.getOutputStream())),true);

            output.println(Mensaje);
            System.out.println(input.readLine());
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

            String SaludoServidor = reader.readLine();

            input.read(CharBuffer.wrap(SaludoServidor));


        } catch (IOException e) {
            e.printStackTrace();
        }


    }
    
}
