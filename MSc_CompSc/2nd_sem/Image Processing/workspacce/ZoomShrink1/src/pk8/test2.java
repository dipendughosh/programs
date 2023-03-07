/*Loading and buffering an image and zooming shrinking*/
package package7;

import java.awt.*;
import java.io.*;

import java.awt.event.KeyEvent;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class test2 extends JPanel implements KeyListener
{
	private static final long serialVersionUID = 1L;
	BufferedImage image;
	BufferedImage imag;
	public static int zoomx = 1;
	public static int zoomy = 1;
	public static int shrinkx = 1;
	public static int shrinky = 1;
	public static int flags = 0;
	public static int flagz = 0;
	
	  
	public test2(BufferedImage image) 
	{
		this.image = image;
	             
	    if(flagz == 1)
	    {
	     	this.imag = new BufferedImage(image.getWidth()*zoomx,image.getHeight()*zoomy,BufferedImage.TYPE_INT_RGB);
	    }
	      
	    if(flags == 1)
	    {
	      	this.imag = new BufferedImage(image.getWidth()/shrinkx,image.getHeight()/shrinky,BufferedImage.TYPE_INT_RGB);
	    }
	}

    protected void paintComponent(Graphics g) 
    {
        super.paintComponent(g);
	    int x = 0;
	    int y = 0;
	    int val = 0;
	            
	    x=image.getWidth();
	    y=image.getHeight();
	        
	    if(flagz == 1)
	    {
	     	for(int i=0;i<x*zoomx;i++)
	        {
	          	for(int j=0;j<y*zoomy;j++)
	          	{
	           		val = image.getRGB(i/zoomx, j/zoomy);
	           		imag.setRGB(i, j, val);
	           	}
	        }
	    }
	    if(flags == 1)
	    {
	       	for(int i=0;i<x/shrinkx;i++)
	        {
	           	for(int j=0;j<y/shrinky;j++)
	           	{
	           		val = image.getRGB(i*shrinkx, j*shrinky);
	           		imag.setRGB(i, j, val);
	           	}
	        }
	    }
	    g.drawImage(image, 20,20,this);
	    g.drawImage(imag, 20,120,this);
	}

	public static void main(String[] args)
	{
	    String path = "E:\\Program\\Programs\\MSc_CompSc\\2nd sem\\Image Processing\\workspacce\\ZoomShrink1\\src\\package7\\5.png";
	    BufferedImage image = null;
	    DataInputStream in = new DataInputStream(System.in);
	    int w = 0;
		try
		{
			System.out.println("Enter The Zoom percentage of the Images");
			System.out.print("Enter: ");
			w=Integer.parseInt(in.readLine());
			//w=Float.parseFloat(in.readLine());
			
		}
		catch(Exception E)
		{
		}
		zoomx = w;
		zoomy = w;
			
		shrinkx = w;
		shrinky = w;
		
		
			
	    try
	    {
	      	image = ImageIO.read(new File(path));
	       	//imag = ImageIO.write(imag, "jpg","E:\\a.jpg" );
	    }
	    catch(IOException e)
	    {
	       	System.out.println("Cannot Read File at location :-"+path);
	    }
	    test1 test = new test1(image);
	    JFrame frame = new JFrame("Zooming & Shrinking");
	    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    frame.add(test);
	    frame.setExtendedState(Frame.MAXIMIZED_BOTH);
	    frame.setSize(400,400);
	    frame.setLocation(200,200);
	    frame.setLocationRelativeTo(null);
	    addKeyListener(new KeyInputHandler());
	    frame.setVisible(true);
	}

	@Override
	public void keyPressed(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void keyReleased(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void keyTyped(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}
}