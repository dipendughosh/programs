package package9;

import java.awt.*;
import java.io.*;

import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

public class ZS extends JPanel
{
	private static final long serialVersionUID = 1L;
	
	BufferedImage imageOld; //describes an image with an accessible image with buffer area.
    BufferedImage imageNew;
    
   	public static int scale_x = 1; // zoom factor for x-cordinate
    public static int scale_y=1;   //zoom factor for y-cordinate
    
   	public static int shrink_x = 1;  //shrink_factor for x-cordinate
	public static int shrink_y = 1;  //shrink_factor for y-cordinate
    int flag=1;                      //to indicate whether we r performing zoom/shrink  
    public static int old_value=5;
    

	
	public ZS(BufferedImage imageOld) 
    {
      
		this.imageOld=imageOld;
		this.imageNew=imageOld;
	
    }
	
	
	
	public void LoadBuffer()
	{
		
		if(flag == 1)
        {	
        	this.imageNew = new BufferedImage(imageOld.getWidth()*scale_x,imageOld.getHeight()*scale_y,BufferedImage.TYPE_INT_RGB);
        }
        if (flag == 2)
        {	
        	this.imageNew = new BufferedImage(imageOld.getWidth()/shrink_x,imageOld.getHeight()/shrink_y,BufferedImage.TYPE_INT_RGB);
        }
		
	}
	
	
        

protected void paintComponent(Graphics g) //called by the system when a new window is drawn automaticaly.
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
        
        if(flag==1)
        {
        for(int i=0;i<x;i++)
         {
          for(int j=0;j<y;j++)
            {
             val = imageOld.getRGB(i/scale_x, j/scale_x);//returns the rgb color of pixel at position(x,y)
              imageNew.setRGB(i, j, val);        		 //set RGB values for the New_Image
            }
          }
         }
        
        if(flag==2)
        {
         for(int i=0;i<x;i++)
           {
            for(int j=0;j<y;j++)
            	{
            		val = imageOld.getRGB(i*shrink_x, j*shrink_y);//returns the rgb color of pixel at position(x,y)
            		imageNew.setRGB(i, j, val);        		
            	}
            }
          }
        
        
        g.drawImage(imageOld, 20,20,this);// draw the original image at position(20,20)
        g.drawImage(imageNew,500,50,this); // draw the new image at position(200,50)
        LoadBuffer();  // load the buffer space for new image
     }
	
	
	
		private JSlider getSlider() 
	    {
	        int min = 1, max = 10;  	//min n max values of the slider.
	        //int old_value=5;
	        final JSlider slider = new JSlider(min, max,5);	//5 is the initial value of the slider.
	        
	        slider.setMajorTickSpacing(1);
	        //slider.setMinorTickSpacing(1);
	        slider.setPaintTicks(true);
	        slider.setSnapToTicks(true);
	        slider.addChangeListener(new ChangeListener()      //slider movement is captured by this event
	        {
	          
	        	public void stateChanged(ChangeEvent e) {
	                int value = slider.getValue();
	                
	                //System.out.println("slider="+value);
	               
	                if(old_value<value)
	                {
	                	if(flag==2)
	        			{
	        				if(shrink_x>1)
	        				{
	        					shrink_x-=1;
	        					shrink_y-=1;
	        					flag=2;
	        					old_value = value;
	        				}
	        				else
	        				{
	        					scale_x+=1;
	        					scale_y+=1;
	        					flag=1;
	        					old_value=value;
	        				}
	        			}
	        			else
	        			{
	        				scale_x+=1;
	        				scale_y+=1;
	        			
	        				flag=1;
	        				old_value=value;
	        			}	
	        			LoadBuffer();
	        			revalidate();
	        			repaint();
	        		
	                }
	                
	                if(value==5)
	                {
	                	scale_x=1;
	                	scale_y=1;
	                	shrink_x=1;
	                	shrink_y=1;
	                	old_value=value;
	                	LoadBuffer();
	        			revalidate();
	        			repaint();
	                }
	                
	                
	                if(old_value>value)
	                {
	                	if(flag==1)
	        			{
	        				if(scale_x>1)
	        				{
	        					scale_x-=1;
	        					scale_y-=1;
	        					flag=1;
	        					old_value=value;
	        				}
	        				else
	        				{
	        					shrink_x+=1;
	        					shrink_y+=1;
	        					flag=2;
	        					old_value=value;
	        				}
	        			}
	        			else
	        			{
	        				shrink_x+=1;
	        				shrink_y+=1;			
	        				flag=2;
	        				old_value=value;
	        			}
	        			LoadBuffer();
	        			revalidate();
	        			repaint();
	                	
	                }
	                
	            }
	        });
	       return slider;
	    }
	
	public static void main(String[] args)
	{
		String path = "C:\\images\\03.jpg";
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
        
        ZS test = new ZS(imageOld);        
        JFrame frame = new JFrame("ZOOMING AND SHRINKING OF A DIGITAL IMAGE");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().add(new JScrollPane(test));
        frame.getContentPane().add(test.getSlider(),"Last");
        frame.add(test);
        frame.setSize(400,400);
        frame.setExtendedState(Frame.MAXIMIZED_BOTH);
        frame.setLocation(200,200);
        frame.setSize(400,400);
        frame.setLocation(200,200);
        frame.setVisible(true);        
	}


}
