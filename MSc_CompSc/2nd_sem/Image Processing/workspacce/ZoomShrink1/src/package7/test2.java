/*Loading and buffering an image and zooming shrinking*/

package package7;

import java.awt.*;
import java.io.*;

import javax.swing.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

public class test2 extends JPanel implements KeyListener
{
    private static final long serialVersionUID = 1L;
	
    BufferedImage imageOld;
	BufferedImage imageZ;
	
	public static int zoomx = 1;
	public static int zoomy = 1;
	public static int shrinkx = 1;
	public static int shrinky = 1;
	public static int flags = 1;
	public static int flagz = 1;
		
    public test2(BufferedImage imageOld) 
    {
    	this.imageOld = imageOld;
        this.imageZ = imageOld;
    }
    
    public void LoadBuffer()
	{
    	if(flagz == 1)
        {	
        	this.imageZ = new BufferedImage(imageOld.getWidth()*zoomx,imageOld.getHeight()*zoomy,BufferedImage.TYPE_INT_RGB);
        }
        if (flags == 1)
        {	
        	this.imageZ = new BufferedImage(imageOld.getWidth()/shrinkx,imageOld.getHeight()/shrinky,BufferedImage.TYPE_INT_RGB);
        }
	}

    protected void paintComponent(Graphics g) 
    {
        super.paintComponent(g);
        int x = 0;
        int y = 0;
        int val = 0;
                     
        x=imageZ.getWidth();
    	y=imageZ.getHeight();
            
        if(flagz == 1)
        {
        	for(int i=0;i<x;i++)
            {
            	for(int j=0;j<y;j++)
            	{
            		val = imageOld.getRGB(i/zoomx, j/zoomy);
            		imageZ.setRGB(i, j, val);        		
            	}
            }
        }
        
        if(flags == 1)
        {
        	for(int i=0;i<x;i++)
            {
            	for(int j=0;j<y;j++)
            	{
            		val = imageOld.getRGB(i*shrinkx, j*shrinky);
            		imageZ.setRGB(i, j, val);
            	}
            }
        }
        
        g.setColor(Color.magenta);
        g.setFont(new Font("Arial", Font.BOLD, 14));
        g.drawString("Original Image",20,20);
        g.drawImage(imageOld, 20,30,this);
        g.drawString("Changed Image",280,20);
        g.drawImage(imageZ,280,30,this);
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
        
        test2 test = new test2(imageOld);
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
	public void keyPressed(KeyEvent Key)
	{
		if ( Key.getKeyCode()== KeyEvent.VK_PAGE_UP)
		{
			//System.out.println("left");
			
			if(flags==1)
			{
				if(shrinkx>1)
				{
					shrinkx-=1;
					shrinky-=1;
					flags=1;
					flagz=0;
				}
				else
				{
					zoomx+=1;
					zoomy+=1;
					flagz=1;
					flags=0;
				}
			}
			else
			{
				zoomx+=1;
				zoomy+=1;
				flagz=1;
				flags=0;
			}	
			LoadBuffer();
			repaint();
		}
		
		if ( Key.getKeyCode()== KeyEvent.VK_PAGE_DOWN)
		{
			//System.out.println("right");
			if(flagz==1)
			{
				if(zoomx>1)
				{
					zoomx-=1;
					zoomy-=1;
					flagz=1;
					flags=0;
				}
				else
				{
					shrinkx+=1;
					shrinky+=1;
					flags=1;
					flagz=0;
				}
			}
			else
			{
				shrinkx+=1;
				shrinky+=1;			
				flags=1;
				flagz=0;
			}
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