/*Loading and buffering an image and histogram hrk*/
package package4;

import java.awt.*;
import java.io.*;

import javax.swing.*;

import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

public class test2 extends JPanel
{
    private static final long serialVersionUID = 1L;
	BufferedImage image;
	BufferedImage imag;
	BufferedImage eqimag;
	public int flag = 1;
	public int arr1[] = new int[256];
	public int arr3[] = new int[256];
	public float arr2[] = new float[256];//pr
	
    public test2(BufferedImage image) 
    {
        this.image = image;
        this.imag = new BufferedImage(image.getWidth(),image.getHeight(),BufferedImage.TYPE_BYTE_GRAY);
        this.eqimag = new BufferedImage(image.getWidth(),image.getHeight(),BufferedImage.TYPE_BYTE_GRAY);
        for(int i = 0;i<256;i++)
        {
        	arr1[i]=0;
        	arr3[i]=0;
        }
    }

    protected void paintComponent(Graphics g) 
    {
        super.paintComponent(g);
        int x = 0;
        int y = 0;
        int val = 0;
        int v=0;
        int re = 0,ge = 0,bl = 0;
 
        x=image.getWidth();
        y=image.getHeight();
        float s[] = new float[256];
        int org_img_arr[][] = new int[x][y];
     
        for(int i=0;i<256;i++)
    	{
    		s[i]=0;
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
          			org_img_arr[i][j] = re;
        		}
        	}
        	flag=0;
        	       	
        	for(int i=0;i<=256;i++)
        	{
        		try
        		{
        			arr2[i]=(float)arr1[i]/(float)(x*y);
        		}
        		catch(Exception e)
        		{       			
        		}
        	}
        	
        	
        	for (int i=0;i<256;i++)
        	{
        		for (int j=0;j<=i;j++)
        		{
        			s[i]= s[i]+arr2[j];
        		}
        	}
        	
        	for(int i=0;i<x;i++)
        	{
        		for(int j=0;j<y;j++)
        		{
        			v=Math.round(s[org_img_arr[i][j]]*255);
        			re=v<<16;
        			ge=v<<8;
        			bl=v;
        			System.out.println(bl);
        			try
        			{
        				eqimag.setRGB(i, j, (re+ge+bl));
        				arr3[bl]++;
        			}
        			catch(Exception e)
        			{
        			}
        		}
        	}
        	g.drawImage(eqimag, 20, 240, this);
        	
        }
        g.drawImage(eqimag, 20, 240, this);
        for(int i=200,j=0;i<712;j++,i+=2)
        {
        	g.setColor (Color.blue);
        	g.drawLine(i, 900-arr1[j]/5, i, 900);
        }
        for(int i=750,j=0;i<1262;j++,i+=2)
        {
        	g.setColor (Color.green);
        	g.drawLine(i, 900-(int)arr3[j]/5, i, 900);
        }
    }

    public static void main(String[] args)
    {
        String path = "E:\\Program\\Programs\\MSc_CompSc\\2nd sem\\Image Processing\\workspacce\\ZoomShrink1\\src\\package7\\1.bmp";
        BufferedImage image = null;
        try
        {
        	image = ImageIO.read(new File(path));
        }
        catch(IOException e)
        {
        	System.out.println("Cannot Read File at location :-"+path);
        }
        test2 test = new test2(image);
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