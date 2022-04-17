package GUI;


import javax.swing.*;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import SocketClient.Client;

public class VentanaMenu implements ActionListener{

    JFrame vMenu = new JFrame();

    JLabel NombreJugador = new JLabel();
    JLabel NombreJugador2 = new JLabel();
    JLabel Titulo = new JLabel();

    JTextField Usertxtbox = new JTextField();
    JTextField Usertxtbox2 = new JTextField();



    public static String Jugador1 = "";

    public static String Jugador2 = "";



    JButton BotonJugar = new JButton("J U G A R");
    JButton BotonAbout = new JButton("Creditos");



    public VentanaMenu() {

        vMenu.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        vMenu.setTitle("M E M O R Y   G A M E");
        vMenu.setResizable(false);

        Titulo.setText("MEMORY GAME ");
        Titulo.setBounds(85, 10, 350, 100);
        Titulo.setFont(new Font("cooper black", 0, 40));

        NombreJugador.setText("Ingrese el nombre del jugador 1:");
        NombreJugador.setBounds(45, 100, 250, 50);
        NombreJugador.setFont(new Font("cooper black", 0, 15));


        NombreJugador2.setText("Ingrese el nombre del jugador 2:");
        NombreJugador2.setBounds(45, 150, 250, 50);
        NombreJugador2.setFont(new Font("cooper black", 0, 15));


        Usertxtbox.setBounds(290, 112, 150, 25);
        Usertxtbox.setFont(new Font("cooper black", 0, 15));

        Usertxtbox2.setBounds(290, 162, 150, 25);
        Usertxtbox2.setFont(new Font("cooper black", 0, 15));


        BotonJugar.setFocusable(false);
        BotonJugar.addActionListener(this);
        BotonJugar.setBounds(140, 400, 200, 40);




        BotonAbout.setFocusable(false);
        BotonAbout.addActionListener(this);
        BotonAbout.setBounds(85, 450, 150, 40);



        vMenu.setSize(500, 600);
        vMenu.setLayout(null);
        vMenu.setVisible(true);
        vMenu.add(BotonJugar);
        vMenu.add(NombreJugador);
        vMenu.add(NombreJugador2);
        vMenu.add(Titulo);
        vMenu.add(Usertxtbox);
        vMenu.add(Usertxtbox2);
        vMenu.setLocationRelativeTo(null);

    }



    /**
     * Metodo que hace que los botones de la pantalla principal sean funcionales.
     * @param e Corresponde a la escucha de los drivers del clickeo del mouse.
     */

    @Override
    public void actionPerformed(ActionEvent e) {

        if (e.getSource() == BotonJugar) {

            Jugador1 = Usertxtbox.getText();
            Jugador2 = Usertxtbox2.getText();
            new Memory();
            Client client =  new Client();
            new Thread(client).start();

        }

    }

    
}
