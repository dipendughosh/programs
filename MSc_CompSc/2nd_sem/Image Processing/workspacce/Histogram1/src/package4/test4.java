/*Loading and buffering an image and histogram*/
package package4;

import java.awt.*;
import java.io.*;
import javax.swing.*;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

public class test4 extends JPanel
{
    private static final long serialVersionUID = 1L;
    
	BufferedImage imageOld;
	BufferedImage imageNew;
	BufferedImage imageEq;
	
	public static int width = 0;
	public static int height = 0;
	public static int val = 0;
	public int flag = 1;
	public int arr1[] = new int[256];
	public int arr2[] = new int[256];
	public float pr[] = new float[256];
	public float ps[] = new float[256];
	
    public test4(BufferedImage imageOld) 
    {
        this.imageOld = imageOld;
        
        width=imageOld.getWidth();
        height=imageOld.getHeight();
        
        this.imageNew = new BufferedImage(imageOld.getWidth(),imageOld.getHeight(),BufferedImage.TYPE_BYTE_GRAY);
        this.imageEq = new BufferedImage(imageOld.getWidth(),imageOld.getHeight(),BufferedImage.TYPE_BYTE_GRAY);
        
        for(int i = 0;i<256;i++)
        {
        	arr1[i]=0;
        }
        
        for(int i = 0;i<256;i++)
        {
        	arr2[i]=0;
        }
    }

    protected void paintComponent(Graphics g) 
    {
        super.paintComponent(g);
        
        makeHistogram();
        
        drawHistogram(g);
        
        drawImage(g);
        

    }
 
    private void drawImage(Graphics g) 
    {
    	g.setColor(Color.magenta);
        g.setFont(new Font("Arial", Font.BOLD, 14));
    	g.drawString("Original Image", 18, 18);
        g.drawImage(imageOld, 20,20,this);
   	 	g.drawString("Greyscale Image",98+width, 18);
   	 	g.drawImage(imageNew, 100+width,20,this);
   	 	g.drawString("Output Image",196+2*width, 18);
   	 	g.drawImage(imageEq, 200+2*width,20,this);
		
	}

	private void drawHistogram(Graphics g)
    {
    	int i = 0,j = 0;
    	
    	g.setFont(new Font("Times New Roman", Font.PLAIN, 14));
    	
    	g.setColor(Color.BLUE);
    	g.fillRect(97,801,520,2);
    	g.fillRect(97,350,2,452);
	 		 	
	 	g.setColor(Color.BLACK);
    	g.drawString("Original Histogram:",250,840);
    	
        for(i=0,j=100;i<=255;i++,j+=2)
	 	{
   	 		g.drawLine(j ,800-(int)pr[i]*5 , j, 800);
	 	}	
	 
        g.setColor(Color.BLUE);
    	g.fillRect(727,801,520,2);
    	g.fillRect(727,350,2,452);
    	
    	g.setColor(Color.BLACK);
    	g.drawString("Equalized Histogram:",880,840);
	 	
	 	for(i=0,j=730;i<=255;i++,j+=2)
   	 	{
	 		g.drawLine(j ,800-(int)ps[i]*5 , j, 800);
   	 	}	
   	 
 	   	g.setColor(Color.DARK_GRAY);
   	 	g.drawString("Scale:",520,900);
   	 	g.drawString("X-Axis: 1 unit= 1 intensity level",520,920);
   	 	g.drawString("Y-Axis: 2 unit= 1 normalized histogram level",520,940);
    }

	private void makeHistogram()
    {
    	int i = 0,j = 0;
        int v=0;
        int valu=0;
        int re = 0,ge = 0,bl = 0;
        float s[] = new float[256];
        int org_img_arr[][] = new int[width][height];
        
        for(i=0;i<256;i++)
    	{
    		s[i]=0;
    	}
        
        if(flag==1)
        {
        	
        	for(i=0;i<width;i++)
        	{
        		for(j=0;j<height;j++)
        		{
        			val = imageOld.getRGB(i, j);
        			re = (int)(val >> 16) & 0xFF;
        			ge = (int)(val >> 8) & 0xFF;
          			bl = (int)(val >>0) & 0xFF;
          			v=(int)(re+ge+bl)/3;
          			valu=(v<<16)|(v<<8)|(v);
          			imageNew.setRGB(i, j, valu);
        		}
        	}
        	
        	 
        	for(i=0;i<width;i++)
        	{
        		for(j=0;j<height;j++)
        		{
        			val = imageNew.getRGB(i, j);
        			re = (val >> 16) & 0xFF;
        			ge = (val >> 8) & 0xFF;
          			bl = (val >> 0) & 0xFF;
          			arr1[(re+ge+bl)/3]++;
          			org_img_arr[i][j] = (re+ge+bl)/3;
        		}
        	}
        	flag=0;
        	
        	for(i=0;i<256;i++)
        	{
        		try
        		{
        			pr[i]=(float)arr1[i]*255/(float)(width*height);
        		}
        		catch(Exception e)
        		{       			
        		}
        	}
        	
        	
        	for (i=0;i<256;i++)
        	{
        		for (j=0;j<=i;j++)
        		{
        			s[i]= s[i]+pr[j];
        			//System.out.print(s[i]);
        		}
        	}
        	
        	
        	
        	for(i=0;i<width;i++)
        	{
        		for(j=0;j<height;j++)
        		{
        			v=Math.round(s[org_img_arr[i][j]]);
        			re=(v<<16);
        			ge=v<<8;
        			bl=v;
        			valu=re|ge|bl;
        			
        			try
        			{
        				imageEq.setRGB(i, j, valu);
        			}
        			catch(Exception e)
        			{
        			}
        			//System.out.print(r);
        			
        		}
        	}
        	
        	
        	for(i=0;i<width;i++)
        	{
        		for(j=0;j<height;j++)
        		{
        			val = imageEq.getRGB(i, j);
        			re = (val >> 16) & 0xFF;
        			ge = (val >> 8) & 0xFF;
          			bl = (val >> 0) & 0xFF;
          			arr2[(re+ge+bl)/3]++;
        		}
        	}
        	 for(i=0;i<256;i++)
         	{
         		try
         		{
         			ps[i]=(float)arr2[i]*255/(float)(width*height);
         		}
         		catch(Exception e)
         		{       			
         		}
         	}
        }
    }

	public static void main(String[] args)
    {
        String path = "E:\\Program\\Programs\\MSc_CompSc\\2nd sem\\Image Processing\\workspacce\\ZoomShrink1\\src\\package7\\1.bmp";
        BufferedImage imageOld = null;
        try
        {
        	imageOld = ImageIO.read(new File(path));
        }
        catch(IOException e)
        {
        	System.out.println("Cannot Read File at location :-"+path);
        }
        test4 test = new test4(imageOld);
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