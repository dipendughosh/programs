package package7;

import java.awt.*;
import java.io.*;

import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.geom.AffineTransform;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;


public class Test7 extends JPanel implements KeyListener
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	BufferedImage imageOld; //describes an image with an accessible image with buffer area.
    BufferedImage imageNew;
    double scale = 1;

	
	public Test7(BufferedImage imageOld) 
    {
        if(scale>=10){
        	int x=(int) (imageOld.getWidth()/scale);
        int y=(int)(imageOld.getHeight()/scale);
		
		this.imageOld = imageOld;
        this.imageNew = new BufferedImage(x, y,BufferedImage.TYPE_INT_RGB);
        //this.imageNew = null;
        }
        else{
        	int x=(int) (imageOld.getWidth()*scale);
            int y=(int)(imageOld.getHeight()*scale);
    		
    		this.imageOld = imageOld;
            this.imageNew = new BufferedImage(x, y,BufferedImage.TYPE_INT_RGB);
            //this.imageNew = null;
        }
        	
    }
        

	protected void paintComponent(Graphics g) //called by the system whn a new window is drawn automaticaaly.
    {
        super.paintComponent(g);
        int x = 0;
        int y = 0;
        int val = 0;
        Graphics2D g2 = (Graphics2D)g;
                
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
        if(scale>=16)
        {
        for(int i=0;i<x;i++)
            {
            	for(int j=0;j<y;j++)
            	{
            		int i1= (int) (i/scale);
            		int j1=(int)(j/scale);
            		
            		val = imageOld.getRGB(i1, j1);//returns the rgb color of pixel at position(x,y)
            		imageNew.setRGB(i1, j1, val);        		
            	}
        }
        }
        
        else
        {
        	for(int i=0;i<x;i++)
            {
            	for(int j=0;j<y;j++)
            	{
            		int i1= (int) (i*scale);
            		int j1=(int)(j*scale);
            		
            		val = imageOld.getRGB(i1, j1);//returns the rgb color of pixel at position(x,y)
            		imageNew.setRGB(i1, j1, val);        		
            	}
        }
        }
        g.drawImage(imageOld, 20,20,this);// draw the original image at the top left corner(0,0)
       
            //int a=(int) (scale*imageOld.getWidth());
            //int b=(int)scale*imageOld.getHeight();
          //this.imageNew = new BufferedImage(a, b,BufferedImage.TYPE_INT_RGB);
            
       // g.drawImage(imageNew,x,y,this);
            
            
            double tx = 0; //translated co ordinate values  
            double ty = 0; // 
            
            try
            {
            	tx=(getWidth() - scale*imageOld.getWidth())/2;
            	System.out.println("tx="+tx);
            }
            catch(Exception e)
            {
            	
            }
            try
            {
            	ty=(getHeight() - scale*imageOld.getHeight())/2;
            	System.out.println("ty="+ty);
            }
            catch(Exception e)
            {
            	
            }
            
            AffineTransform at = AffineTransform.getTranslateInstance(tx,ty); // returns a transformation returning a translation transformation
            at.scale(scale, scale);  //scaling the transformed object 'at'
            g2.drawRenderedImage(imageNew, at);
            
            
            
    }
	
	
	
	

	
	
	
	
 private JSlider getSlider() 
	    {
	        int min = 1, max = 20;  							//min n max values of the slider.
	        final JSlider slider = new JSlider(min, max, 10);	//16 is the initial value of the slider.
	        
	        slider.setMajorTickSpacing(5);
	        slider.setMinorTickSpacing(1);
	        slider.setPaintTicks(true);
	        slider.setSnapToTicks(true);
	        slider.addChangeListener(new ChangeListener() 
	        {
	            public void stateChanged(ChangeEvent e) {
	                int value = slider.getValue();
	                scale = (value)/20.0;
	                revalidate();  // updates the size/layout
	                repaint();     // repaints other components
	            }
	        });
	        return slider;
	    }
	
	public static void main(String[] args)
	{
		String path = "C:\\i.jpg";
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
        
        Test7 test = new Test7(imageOld);        
        JFrame frame = new JFrame("Zooming & Shrinking");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().add(new JScrollPane(test));
        frame.getContentPane().add(test.getSlider(), "Last");
        frame.add(test);
        frame.setSize(400,400);
        frame.setExtendedState(Frame.MAXIMIZED_BOTH);
        frame.setLocation(200,200);
        frame.setSize(400,400);
        frame.setLocation(200,200);
        frame.setVisible(true);        
	}


	@Override
	public void keyPressed(KeyEvent arg0) {
		// TODO Auto-generated method stub
		
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
