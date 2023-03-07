/*Loading and buffering an image and histogram*/
package package4;

import java.awt.*;
import java.io.*;

import javax.swing.*;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

public class test1 extends JPanel
{
    private static final long serialVersionUID = 1L;
	BufferedImage image;
	BufferedImage imag;
	public int flag = 1;
	public int arr1[] = new int[256];
	//public int arr2[] = new int[256];
	
    public test1(BufferedImage image) 
    {
        this.image = image;
        this.imag = new BufferedImage(image.getWidth(),image.getHeight(),BufferedImage.TYPE_BYTE_GRAY);
        for(int i = 0;i<256;i++)
        {
        	arr1[i]=0;
        }
        /*for(int i = 0;i<256;i++)
        {
        	arr2[i]=0;
        }*/
    }

    protected void paintComponent(Graphics g) 
    {
        super.paintComponent(g);
        int x = 0;
        int y = 0;
        int val = 0;
        int re = 0,ge = 0,bl = 0;
        FileWriter f = null;
             
        x=image.getWidth();
        y=image.getHeight();
       
        try
        {
			 f = new FileWriter("test.txt");
		}
        catch (IOException e) 
        {
			e.printStackTrace();
		}
        
        for(int i=0;i<x;i++)
        {
          	for(int j=0;j<y;j++)
          	{
           		val = image.getRGB(i, j);
           		imag.setRGB((int)i, (int)j, val);
           	}
        }
        g.drawImage(image, 20,20,this);
        g.drawImage(imag, 20,120,this);
        
        if(flag==1)
        {
        	for(int i=0;i<x;i++)
        	{
        		for(int j=0;j<y;j++)
        		{
        			val = imag.getRGB(i, j);
        			re = (val & 0x00ff0000) >> 16;
        			ge = (val & 0x0000ff00) >> 8;
          			bl = val & 0x000000ff;
          			arr1[(re+ge+bl)/3]++;
        		}
        	}
        	flag=0;
        }
        for(int i = 0;i<256;i++)
        {
        	arr1[i]=arr1[i];
        	       	
        	try 
    		{
				f.write("arr1["+i+"] = "+arr1[i]+"\n");
				//f.write("arr2["+i+"] = "+arr2[i]+"\n");
			}
    		catch (IOException e) 
    		{
				e.printStackTrace();
			}
        }
        
        try
        {
			f.close();
		}
        catch (IOException e) 
        {
			e.printStackTrace();
		}
        for(int i=200,j=0;i<712;j++,i+=2)
        {
        	g.setColor (Color.blue);
        	g.drawLine(i, 900-arr1[j]/5, i, 900);
        }
        /*for(int i=750,j=0;i<1262;j++,i+=2)
        {
        	g.setColor (Color.green);
        	g.drawLine(i, 900-arr1[j]/5, i, 900);
        }*/
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
        test1 test = new test1(image);
        JFrame frame = new JFrame("Histogram");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(test);
        frame.setExtendedState(Frame.MAXIMIZED_BOTH);
        frame.setSize(400,400);
        frame.setLocation(200,200);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
        
    }
}