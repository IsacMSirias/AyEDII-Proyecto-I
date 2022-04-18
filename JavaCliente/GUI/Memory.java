package GUI;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import  SocketClient.*;

public class Memory extends JFrame {

    public static int i = Client.i_cliente;
    public static int j;
    public static int rows = 7;
    public static int columns = 7;
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
        for( int i = 1; i < rows; i++)
        {
            for (int j = 1; j < columns; j++)
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

              
                if( isFirst)
                {
                    //compareCards = memButtons[i][j].getImageNumber();
                    holdCardRow = memButtons[i][j].getRow();
                    holdCardColumn = memButtons[i][j].getColumn();
                    //memButtons[holdCardRow][holdCardColumn].setEnabled(false);
                    isFirst = false;
                }
                else
                {
                   
                    System.out.println(holdCardRow +", "+ holdCardColumn);
                    System.out.println(i +", "+ j);

                    Client.sendPosiciones(holdCardRow,holdCardColumn, i,j);


                    if (compareCards == memButtons[i][j].getImageNumber())
                    {
                        win++;
                        if (win == columns)
                        {
                            win = 0;   
                        }
                        else
                        {
            
                            //memButtons[holdCardRow][holdCardColumn].setEnabled(false);
                           // memButtons[i][j].setEnabled(false);
                        }
                    }
                    else
                    {
             
                        memButtons[holdCardRow][holdCardColumn].setEnabled(true);
                      
                    }
                    isFirst = true;
                }
            } 
        }
    }


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
