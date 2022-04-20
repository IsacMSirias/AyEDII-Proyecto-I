package GUI;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import  SocketClient.*;

public class Memory extends JFrame {

    public static int i = Client.i_cliente;
    public static int j;
    public static int rows = 6;
    public static int columns = 6;
    int counter = 0;


    public static MemoryButton[][] memButtons = new MemoryButton[rows][columns];
    public static JLabel[][] imgLabel = new JLabel[rows][columns];
    private static JPanel[][] memPanel = new JPanel[rows][columns];

    int[] cards = new int[columns*rows];
    int compareCards = 0;
    int holdCardRow = 0;
    int holdCardColumn= 0;
    boolean isFirst = true;
    int win = 0;


    public  Memory()
    {
        
        setTitle("M e m o r y");

       
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


        setLayout(new GridLayout(rows, columns));

      
        for( int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                buildMemPanel(i, j);
                add(memPanel[i][j]);
            }
        }

        pack();
        setVisible(true);
    }

  

    public void buildMemPanel(int _i, int _j)
    {
      
        memPanel[_i][_j] = new JPanel();

       
        memPanel[_i][_j].setLayout(new GridLayout(2,1));

        memButtons[_i][_j] = new MemoryButton(_i, _j, cards[counter], false);
        counter++;

        
        memButtons[_i][_j].addActionListener(new FlipListener());
        memButtons[_i][_j].setText("voltear");

       
        imgLabel[_i][_j] = new JLabel( new ImageIcon("Tarjeta" + 0 + ".jpg"));

        
        memPanel[_i][_j].setBorder(BorderFactory.createTitledBorder(" "));

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
                   
                    holdCardRow = memButtons[i][j].getRow();
                    holdCardColumn = memButtons[i][j].getColumn();
           
                    isFirst = false;
                }
                else
                {
                   
                    System.out.println(holdCardRow +", "+ holdCardColumn);
                    System.out.println(i +", "+ j);

                   Client.sendPosiciones(holdCardRow,holdCardColumn, i,j);


                  
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
