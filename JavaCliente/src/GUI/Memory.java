package GUI;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;
import  SocketClient.*;

public class Memory extends JFrame {

    public static int i = Client.i_cliente;
    public static int j;
    public static int rows = 6;
    public static int columns = 6;
    int counter = 0;


    //Buttons and Labels and More!
    public static MemoryButton[][] memButtons = new MemoryButton[rows][columns];
    public static JLabel[][] imgLabel = new JLabel[rows][columns];
    private static JPanel[][] memPanel = new JPanel[rows][columns];

    //Math Stuff
    int[] cards = new int[columns*rows];
    int compareCards = 0;
    int holdCardRow = 0;
    int holdCardColumn= 0;
    boolean isFirst = true;
    int win = 0;

    /**
     Constructor
     Very simple, creates a 2x6 panels in grid Layout
     */

    public  Memory()
    {
        //Math


        // Display a title.
        setTitle("Memory");

        // Specify an action for the close button.
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //Set layout
        setLayout(new GridLayout(rows, columns));

        // Create the memPanelsAdd items buttons to the panel
        for( int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                buildMemPanel(i, j);
                add(memPanel[i][j]);
            }
        }

        //Pack it and show it
        pack();
        setVisible(true);
    }

    /**
     The buildMemPanel method builds the grid for the game Memory
     */

    public void buildMemPanel(int _i, int _j)
    {
        //New Panel
        memPanel[_i][_j] = new JPanel();

        //Set Layout
        memPanel[_i][_j].setLayout(new GridLayout(2,1));

        //Fill with a button
        memButtons[_i][_j] = new MemoryButton(_i, _j, cards[counter], false);
        counter++;

        //Add an actionListener
        memButtons[_i][_j].addActionListener(new FlipListener());
        memButtons[_i][_j].setText("xd");

        //Create the Images
        imgLabel[_i][_j] = new JLabel( new ImageIcon("Card" + 0 + ".jpg"));

        //Set up a border
        memPanel[_i][_j].setBorder(BorderFactory.createTitledBorder(" "));

        //Add them to the panel
        memPanel[_i][_j].add(imgLabel[_i][_j]);
        memPanel[_i][_j].add(memButtons[_i][_j]);
    }

    public class FlipListener implements ActionListener
    {

        public void actionPerformed(ActionEvent e)
        {
            Object obj = e.getSource();
            if(obj instanceof  MemoryButton clicked)
            {
                i  = clicked.getRow();
                j = clicked.getColumn();

              Client.sendPosiciones(i,j);


               //System.out.println(i);



                //ImageIcon tempImg = new ImageIcon("Card" + memButtons[r][c].getImageNumber() + ".jpg");
                //imgLabel[r][c].setIcon(tempImg);

                //This fills a bunch of variables to compare later,
                //turns off the card you pressed, and gets ready for the next flip
                if( isFirst)
                {
                    compareCards = memButtons[i][j].getImageNumber();
                    holdCardRow = memButtons[i][j].getRow();
                    holdCardColumn = memButtons[i][j].getColumn();
                    memButtons[holdCardRow][holdCardColumn].setEnabled(false);
                    isFirst = false;
                }
                else
                {

                    if (compareCards == memButtons[i][j].getImageNumber())
                    {
                        win++;
                        if (win == columns)
                        {
                          //  JOptionPane.showMessageDialog(null, "You win, time to start over!");
                            win = 0;
                            setVisible(false);
                            dispose();
                            new Memory();
                        }
                        else
                        {
                           // JOptionPane.showMessageDialog(null, "You got one!");
                            memButtons[holdCardRow][holdCardColumn].correct = true;
                            memButtons[i][j].correct = true;
                            memButtons[holdCardRow][holdCardColumn].setEnabled(false);
                            memButtons[i][j].setEnabled(false);
                        }
                    }
                    else
                    {
                        //JOptionPane.showMessageDialog(null, "Gah! No good!");
                        memButtons[holdCardRow][holdCardColumn].setEnabled(true);
                       // tempImg = new ImageIcon("Card0.jpg");
                       // imgLabel[holdCardRow][holdCardColumn].setIcon(tempImg);
                       // imgLabel[r][c].setIcon(tempImg);
                    }
                    isFirst = true;
                }
            } //System.out.println(i_string);
        }
    }

    /**
     The MemoryButton knows where it is, if it correct,
     and what img is should display
     */

    public static class MemoryButton extends JButton
    {
        public int x;
        public int y;
        private int imgNum;
        boolean correct;

        public MemoryButton(int _x, int _y, int _imgNum, boolean _correct)
        {
            //super(text);
            this.x = _x;
            this.y = _y;
            this.imgNum = _imgNum;
            this.correct = _correct;
        }

        public int getRow()
        {
            return x;
        }

        public int getColumn()
        {
            return y;
        }
        public int getImageNumber()
        {
            return imgNum;
        }
    }

}
