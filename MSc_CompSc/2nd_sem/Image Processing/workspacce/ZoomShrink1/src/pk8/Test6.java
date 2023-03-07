/* Final Zoom n shrink */

package pk8;

import java.awt.*;
import java.io.*;

import javax.swing.*;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;


public class Test6 extends JPanel implements KeyListener
{
	private static final long serialVersionUID = 1L;
	BufferedImage imageOld;
    BufferedImage imageZoom;
    BufferedImage imageShrink;
    
	
	public static int zoom_x = 1;
	public static int zoom_y = 1;
	public static int shrink_x = 1;
	public static int shrink_y = 1;
	public static int flag = 1;
		
	public Test6(BufferedImage imageOld) 
    {
        this.imageOld = imageOld;
        //this.imageZoom = new BufferedImage(zoom_x*imageOld.getWidth(),zoom_y*imageOld.getHeight(),BufferedImage.TYPE_INT_RGB);
        //this.imageShrink = new BufferedImage(imageOld.getWidth()/shrink_x,imageOld.getHeight()/shrink_y,BufferedImage.TYPE_INT_RGB);
        this.imageZoom = imageOld;
       // this.imageShrink=imageOld;
    }
	
	public void LoadBuffer()
	{
		
		if(flag == 1)
        {	
        	this.imageZoom = new BufferedImage(imageOld.getWidth()*zoom_x,imageOld.getHeight()*zoom_y,BufferedImage.TYPE_INT_RGB);
        }
        if (flag == 2)
        {	
        	this.imageZoom = new BufferedImage(imageOld.getWidth()/shrink_x,imageOld.getHeight()/shrink_y,BufferedImage.TYPE_INT_RGB);
        }
		
	}
	
	protected void paintComponent(Graphics g) 
    {
        super.paintComponent(g);
        int x = 0;
        int y = 0;
        int val = 0;
       // Graphics2D g2 = (Graphics2D)g; 
        
        if ( flag == 1)
        {
         x=imageZoom.getWidth();
         y=imageZoom.getHeight();
                        
            for(int i=0;i<x;i++)
            {
            	for(int j=0;j<y;j++)
            	{
            		val = imageOld.getRGB(i/zoom_x, j/zoom_y);
            		imageZoom.setRGB(i, j, val);        		
            	}
            }
        }
        
        if (flag == 2)
        {	
        	x=imageZoom.getWidth();
            y=imageZoom.getHeight();
            
        	for(int i=0;i<x;i++)
            {
            	for(int j=0;j<y;j++)
            	{
            		val = imageOld.getRGB(i*shrink_x, j*shrink_y);
            		imageZoom.setRGB(i, j, val);
            	}
            }
        }
        
        g.drawString("Original Image",20,20);
        g.drawImage(imageOld, 20,30,this);
       // g.drawImage(imageShrink, 20,350,this);
        g.drawString("Changed Image",280,20);
        g.drawImage(imageZoom,280,30,this);
        
        
          
 }
	
	public static void main(String[] args)
	{
		String path = "E:\\Program\\Programs\\MSc_CompSc\\2nd sem\\Image Processing\\workspacce\\ZoomShrink1\\src\\package7\\5.png";
        BufferedImage imageOld = null;
        BufferedImage imageZoom = null;
        		
        try
        {
        	imageOld = ImageIO.read(new File(path));
        	
        }
        catch(IOException e)
        {
        	System.out.println("Cannot Read File at location :-"+path);
        }
        
        Test6 test = new Test6(imageOld);        
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
        
        
}


	@Override
	public void keyPressed(KeyEvent Key) {
		// TODO Auto-generated method stub
		
		if ( Key.getKeyCode()== KeyEvent.VK_LEFT)
		{
			System.out.println("left");
			/*if ( zoom_x == 1)
			{
			zoom_x=2;
	        zoom_y=2;
			}*/
			if(flag==2)
			{
				if(shrink_x>1)
				{
					shrink_x-=1;
					shrink_y-=1;
					flag=2;
				}
				else
				{
					zoom_x+=1;
					zoom_y+=1;
					flag=1;
				}
			}
			else
			{
				zoom_x+=1;
				zoom_y+=1;
			
				flag=1;
			}	
			LoadBuffer();
			repaint();
		}
		
		if ( Key.getKeyCode()== KeyEvent.VK_RIGHT)
		{
			System.out.println("right");
			if(flag==1)
			{
				if(zoom_x>1)
				{
					zoom_x-=1;
					zoom_y-=1;
					flag=1;
					
				}
				else
				{
					shrink_x+=1;
					shrink_y+=1;
					flag=2;
				}
			}
			else
			{
				shrink_x+=1;
				shrink_y+=1;			
				flag=2;
			}
			LoadBuffer();
			repaint();
		}
		
	}


	@Override
	public void keyReleased(KeyEvent arg0) {
		// TODO Auto-generated method stub
		
	}


	@Override
	public void keyTyped(KeyEvent arg0) {
		// TODO Auto-generated method stub
		
	}

}
