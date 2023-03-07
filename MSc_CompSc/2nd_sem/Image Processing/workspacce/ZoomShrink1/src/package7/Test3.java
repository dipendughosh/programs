package package7;

import java.awt.*;
import java.io.*;

import javax.swing.*;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;


public class Test3 extends JPanel implements KeyListener
{
	private static final long serialVersionUID = 1L;
	BufferedImage imageOld;
    BufferedImage imageNew;
    BufferedImage imageTemp;
	
	public static int scale_x = 1;
	public static int scale_y = 1;
	
	public static int flag = 1;
		
	public Test3(BufferedImage imageOld) 
    {
        this.imageOld = imageOld;
        this.imageTemp= imageOld;
        this.imageNew = new BufferedImage(scale_x*imageOld.getWidth(),scale_y*imageOld.getHeight(),BufferedImage.TYPE_INT_RGB);
    }
	
	public void LoadBuffer()
	{
		imageTemp=imageNew;
		
		if(flag == 1)
        {
        	this.imageNew = new BufferedImage(scale_x*imageTemp.getWidth(),scale_y*imageTemp.getHeight(),BufferedImage.TYPE_INT_RGB);
        }
        if (flag == 2)
        {	
        	this.imageNew = new BufferedImage( imageTemp.getWidth()/scale_x,imageTemp.getHeight()/scale_y,BufferedImage.TYPE_INT_RGB);
        }
		
	}
	
	protected void paintComponent(Graphics g) 
    {
        super.paintComponent(g);
        int x = 0;
        int y = 0;
        int val = 0;
                
        try
        {
        	x=imageNew.getWidth();
        }
        catch(Exception e)
        {
        }
        try
        {
        	y=imageNew.getHeight();
        }
        catch(Exception e)
        {
        }
        
        if ( flag == 1)
        {	
            for(int i=0;i<x;i++)
            {
            	for(int j=0;j<y;j++)
            	{
            		val = imageTemp.getRGB(i/scale_x, j/scale_y);
            		imageNew.setRGB(i, j, val);        		
            	}
            }
        }
        
        if (flag == 2)
        {
        	for(int i=0;i<x;i++)
            {
            	for(int j=0;j<y;j++)
            	{
            		val = imageTemp.getRGB(i*scale_x, j*scale_y);
            		imageNew.setRGB(i, j, val);
            	}
            }
        }
        
     	g.drawImage(imageOld, 20,20,this);
        g.drawImage(imageNew, 20,120,this);
        
          
	}
	
	public static void main(String[] args)
	{
		String path = "E:\\Program\\Programs\\MSc_CompSc\\2nd sem\\Image Processing\\workspacce\\ZoomShrink1\\src\\package7\\5.png";
        BufferedImage imageOld = null;
        BufferedImage imageNew = null;
        		
        try
        {
        	imageOld = ImageIO.read(new File(path));
        }
        catch(IOException e)
        {
        	System.out.println("Cannot Read File at location :-"+path);
        }
        
        Test3 test = new Test3(imageOld);        
        JFrame frame = new JFrame("Zooming & Shrinking");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(test);
        frame.setSize(400,400);
        frame.setExtendedState(Frame.MAXIMIZED_BOTH);
        frame.setLocation(200,200);
        frame.setSize(400,400);
        frame.setLocation(200,200);
        frame.setVisible(true);   
        frame.addKeyListener(test);
        /*flag=1;
        test.LoadBuffer();*/
        scale_x=2;
        scale_y=2;
        
	}


	@Override
	public void keyPressed(KeyEvent Key)
	{
		if ( Key.getKeyCode()== KeyEvent.VK_LEFT)
		{
			System.out.println("left");
			/*scale_x+=1;
			scale_y+=1;*/
			flag=1;
			LoadBuffer();
			repaint();
		}
		
		if ( Key.getKeyCode()== KeyEvent.VK_RIGHT)
		{
			System.out.println("right");
			
			/*scale_x-=1;
			scale_y-=1;*/
			
			/*if(scale_x == 0 && scale_y == 0)
			{
				imageTemp=imageOld;
				scale_x=1;
				scale_y=1;
			}	
			
			if(scale_x < 0)
				scale_x=scale_x * -1;
			if(scale_y < 0)
				scale_y=scale_y * -1;*/
			
			flag=2;
			LoadBuffer();
			repaint();
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
