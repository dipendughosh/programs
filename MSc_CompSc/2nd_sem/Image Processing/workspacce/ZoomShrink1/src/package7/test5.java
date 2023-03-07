package package7;


import java.awt.*;
import java.io.*;

import javax.swing.*;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

public class test5 extends JPanel implements KeyListener
{

    private static final long serialVersionUID = 1L;
	
    BufferedImage imageOld;
	BufferedImage imageZ;
	BufferedImage imageS;

	
	public static int zoomx = 1;
	public static int zoomy = 1;
	/*public static int shrinkx = 1;
	public static int shrinky = 1;*/
	public static int flags = 1;
	public static int flagz = 1;
	public static int flag = 0;
		
    public test5(BufferedImage imageOld) 
	{
    	this.imageOld = imageOld;
	    imageS=imageOld;
	    if(flagz == 1)
	    {
	     	this.imageZ = new BufferedImage(imageOld.getWidth()*zoomx,imageOld.getHeight()*zoomy,BufferedImage.TYPE_INT_RGB);
	    }
	        
	    if(flags == 1)
	    {
	       	this.imageZ = new BufferedImage(imageOld.getWidth()/zoomx,imageOld.getHeight()/zoomy,BufferedImage.TYPE_INT_RGB);
	    }
	}
	    
	public void LoadBuffer()
	{
		imageS=imageZ;
		
	   	if(flagz == 1)
	    {
	   		this.imageZ = new BufferedImage(imageS.getWidth()*zoomx,imageS.getHeight()*zoomy,BufferedImage.TYPE_INT_RGB);
	    }
	        
	    if(flags == 1)
	    {
	      	this.imageZ = new BufferedImage(imageS.getWidth()/zoomx,imageS.getHeight()/zoomy,BufferedImage.TYPE_INT_RGB);
	    }
	}

    protected void paintComponent(Graphics g) 
    {
        super.paintComponent(g);
        int x = 0;
        int y = 0;
        int val = 0;
                     
        if(flag == 0)
        {
        	x=imageOld.getWidth();
        	y=imageOld.getHeight();
        	flag=1;
        	
        	if(flagz == 1)
            {
            	for(int i=0;i<x*zoomx;i++)
            	{
            		for(int j=0;j<y*zoomy;j++)
            		{
            			val = imageOld.getRGB(i/zoomx, j/zoomy);
            			imageZ.setRGB(i, j, val);
            		}	
            	}
            }
            
            if(flags == 1)
            {
            	for(int i=0;i<x/zoomx;i++)
            	{
            		for(int j=0;j<y/zoomy;j++)
            		{
            			val = imageOld.getRGB(i*zoomx, j*zoomy);
            			imageZ.setRGB(i, j, val);
            		}
            	}
            }
        }
        else
        {
        	x=imageS.getWidth();
        	y=imageS.getHeight();
        	
        	if(flagz == 1)
            {
            	for(int i=0;i<x*zoomx;i++)
            	{
            		for(int j=0;j<y*zoomy;j++)
            		{
            			val = imageS.getRGB(i/zoomx, j/zoomy);
            			imageZ.setRGB(i, j, val);
            		}	
            	}
            }
            
            if(flags == 1)
            {
            	for(int i=0;i<x/zoomx;i++)
            	{
            		for(int j=0;j<y/zoomy;j++)
            		{
            			val = imageS.getRGB(i*zoomx, j*zoomy);
            			imageZ.setRGB(i, j, val);
            		}
            	}
            }
        }
        
            
        
        
        g.setColor(Color.magenta);
        g.setFont(new Font("Arial", Font.BOLD, 14));
        g.drawString("Original Image", 18, 18);
        g.drawImage(imageOld, 20,20,this);
        g.drawString("Zooming Image", 228, 128);
        g.drawImage(imageZ, 230,130,this);
        /*g.drawString("Shrinking Image", 18, 128);
        g.drawImage(imageS, 20,130,this);*/
    }

    public static void main(String[] args)
    {
        String path = "E:\\Program\\Programs\\MSc_CompSc\\2nd sem\\Image Processing\\workspacce\\ZoomShrink1\\src\\package7\\5.png";
        BufferedImage image = null;
	        		
		try
	    {
	      	image = ImageIO.read(new File(path));
	    }
	    catch(IOException e)
	    {
	       	System.out.println("Cannot Read File at location :-"+path);
	    }
	        
	    test5 test = new test5(image);
	    JFrame frame = new JFrame("Zooming & Shrinking");
	    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    frame.add(test);
	    frame.setExtendedState(Frame.MAXIMIZED_BOTH);
	    frame.setSize(400,400);
	    frame.setLocation(200,200);
	    frame.addKeyListener(test);
	    frame.setLocationRelativeTo(null);
	    frame.setVisible(true);
    }

	@Override
	public void keyPressed(KeyEvent ke)
	{
		if(ke.getKeyCode() == KeyEvent.VK_PAGE_UP )
		{
			zoomx=zoomx+1;
			zoomy=zoomy+1;
			flagz=1;
			flags=0;
			LoadBuffer();
			repaint();
			System.out.println("up");
		}
		if(ke.getKeyCode() == KeyEvent.VK_PAGE_DOWN )
		{
			/*shrinkx=shrinkx+1;
			shrinky=shrinky+1;*/
			zoomx=zoomx+1;
			zoomy=zoomy+1;
			flagz=0;
			flags=1;
			LoadBuffer();
			repaint();
			System.out.println("down");
		}
	}

	@Override
	public void keyReleased(KeyEvent arg0) 
	{
		
	}

	@Override
	public void keyTyped(KeyEvent arg0) 
	{
	}
}