//working
package package5;

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Test2 extends JPanel {

   Image castle;
   Dimension size;
   BufferedImage image;

    public Test2(String path)  throws IOException 
    {
        size = new Dimension();
        castle = new ImageIcon(this.getClass().getResource(path)).getImage();
        
        size.width = castle.getWidth(this)+100;
        size.height = castle.getHeight(this)+100;
/*        String path = "1.jpg";
        image = ImageIO.read(new File(path));*/

        setPreferredSize(size);
    }
    void init()
    {
    	/*castle = new ImageIcon(this.getClass().getResource("1.jpg")).getImage();
    	size = new Dimension();
        // castle = new ImageIcon(this.getClass().getResource("1.jpg")).getImage();
        size.width = castle.getWidth(this)+100;
        size.height = castle.getHeight(this)+100;
        setPreferredSize(size);*/
    	
    }
    public void paint(Graphics g)
    {

        Graphics2D g2d = (Graphics2D) g;

        g2d.drawImage(castle, 10, 10, this);
    }

    public static void main(String[] args)
    {

        JFrame frame = new JFrame("Red Rock");
        frame.setSize(800,600);
        try
        {
        	frame.add(new Test2("1.jpg"));
        }
        catch(IOException e)
        {
        	
        }
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}
