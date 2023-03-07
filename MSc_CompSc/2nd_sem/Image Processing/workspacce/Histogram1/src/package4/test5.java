/*Loading and buffering an image and histogram*/
package package4;

import java.awt.*;
import java.io.*;

import javax.swing.*;


import java.awt.image.BufferedImage;


import javax.imageio.ImageIO;

public class test5 extends JPanel
{
    private static final long serialVersionUID = 1L;
	BufferedImage imageOld;
	BufferedImage imageNew;
	BufferedImage imageEq;
	public int flag = 1;
	public int arr1[] = new int[256];
	public int arr2[] = new int[256];
	public float pr[] = new float[256];
	public float ps[] = new float[256];
	
    public test5(BufferedImage imageOld) 
    {
        this.imageOld = imageOld;
        this.imageNew = new BufferedImage(imageOld.getWidth(),imageOld.getHeight(),BufferedImage.TYPE_INT_RGB);
        this.imageEq = new BufferedImage(imageOld.getWidth(),imageOld.getHeight(),BufferedImage.TYPE_INT_RGB);
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
        int w = 0;
        int h = 0;
        int val = 0;
        int v=0;
        int red=0;
        int green=0;
        int blue=0;
        int a=0;
        int re = 0,ge = 0,bl = 0;
        
        FileWriter f = null;
        
             
        w=imageOld.getWidth();
        h=imageOld.getHeight();
        float s[] = new float[256];
        int org_img_arr[][] = new int[w][h];
        int equal_img_arr[][] = new int[w][h];

       
        try
        {
			 f = new FileWriter("test.txt");
		}
        catch (IOException e) 
        {
			e.printStackTrace();
		}
        for(int i=0;i<256;i++)
    	{
    		s[i]=0;
    	}
        
     
        g.drawString("Original Image",20,15);
        g.drawImage(imageOld, 20,20,this);
       
        
        
        if(flag==1)
        {
        	
        	for(int i=0;i<w;i++)
        	{
        		for(int j=0;j<h;j++)
        		{
        			val = imageOld.getRGB(i, j);
        			re = (int)(val >> 16) & 0xFF;
        			ge = (int)(val >> 8) & 0xFF;
          			bl = (int)(val >>0) & 0xFF;
          			v=(int)(re+ge+bl)/3;
          			a=(v<<16)|(v<<8)|(v);
          			imageNew.setRGB(i, j, a);
        		}
        	}
        	
        	 g.drawString("Greyscale Image",280,20);
             g.drawImage(imageNew, 280,25,this);
        	for(int i=0;i<w;i++)
        	{
        		for(int j=0;j<h;j++)
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
        	
        	for(int i=0;i<256;i++)
        	{
        		try
        		{
        			pr[i]=(float)arr1[i]*255/(float)(w*h);
        		}
        		catch(Exception e)
        		{       			
        		}
        	}
        	
        	
        	for (int i=0;i<256;i++)
        	{
        		for (int j=0;j<=i;j++)
        		{
        			s[i]= s[i]+pr[j];
        			//System.out.print(s[i]);
        		}
        	}
        	
        	
        	
        	for(int i=0;i<w;i++)
        	{
        		for(int j=0;j<h;j++)
        		{
        			v=Math.round(s[org_img_arr[i][j]]);
        			red=(v<<16);
        			green=v<<8;
        			blue=v;
        			a=red|green|blue;
        			
        			try
        			{
        				imageEq.setRGB(i, j, a);
        			}
        			catch(Exception e)
        			{
        			}
        			//System.out.print(r);
        			
        		}
        	}
        	
        	g.drawString("Equalized Image",550,20);
        	g.drawImage(imageEq, 550, 25, this);
        	
        	for(int i=0;i<w;i++)
        	{
        		for(int j=0;j<h;j++)
        		{
        			val = imageEq.getRGB(i, j);
        			re = (val >> 16) & 0xFF;
        			ge = (val >> 8) & 0xFF;
          			bl = (val >> 0) & 0xFF;
          			arr2[(re+ge+bl)/3]++;
        		}
        	}
        	 for(int i=0;i<256;i++)
         	{
         		try
         		{
         			ps[i]=(float)arr2[i]*255/(float)(w*h);
         		}
         		catch(Exception e)
         		{       			
         		}
         	}
        }
        
        for(int i = 0;i<256;i++)
        {
        	arr1[i]=arr1[i];
        	       	
        	try 
    		{
				//f.write("arr1["+i+"] = "+arr1[i]+"\n");
				f.write("pr["+i+"] = "+pr[i]+"\n");
				//f.write("s["+i+"] = "+s[i]+"\n");
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
        
        /*g.drawString("Original Histogram:",20,400);
        int l=20;	 	
   	 	for(int i=0;i<=255;i++)
	 	{
	 		g.fillRect(l ,550-(Math.round(pr[i])*2) , 2, (Math.round(pr[i])*2));
	 		l+=4;
	 	}	
	 
	 
	 	//draw the axis
	 	g.setColor(Color.BLUE);
	 	g.drawLine(15,560, l-4, 560); //x axis
	 	g.drawLine(15,560, 15, 420);  // y axis
	 	
	 	g.setColor(Color.BLACK);
	 	g.drawString("Equalized Histogram:",20,675);
	 	int k=20;
 	 	for(int i=0;i<=255;i++)
   	 	{
   	 		g.fillRect(k ,830-(Math.round(ps[i])*2) , 2, (Math.round(ps[i])*2));
        	k+=4;
   	 	}	
   	 
   	 
   	 	//draw the axis
   	 	g.setColor(Color.BLUE);
   	 	g.drawLine(15,840, k-4, 840); //x axis
   	 	g.drawLine(15,840, 15, 700);  // y axis*/
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
   	 	g.setColor(Color.BLACK);
   	 	g.drawString("Scale:",20,900);
   	 	g.drawString("X-Axis: 1 unit= 1 intensity level",20,910);
   	 	g.drawString("Y-Axis: 2 unit= 1 normalized histogram level",20,920);
   	 g.drawString("Greyscale Image",280,20);
     g.drawImage(imageNew, 280,25,this);
     g.drawString("Equalized Image",550,20);
 	g.drawImage(imageEq, 550, 25, this);
    }
 
    public static void main(String[] args)
    {
       // String path = "E:\\Program\\Programs\\MSc_CompSc\\2nd sem\\Image Processing\\workspacce\\ZoomShrink1\\src\\package7\\1.bmp";
    	String path = "E:\\Program\\Programs\\MSc_CompSc\\2nd sem\\Image Processing\\workspacce\\HistogramDone\\src\\package1\\pollen.jpg";
        BufferedImage imageOld = null;
        try
        {
        	imageOld = ImageIO.read(new File(path));
        	//imageNew = ImageIO.write(imageNew, "jpg","E:\\a.jpg" );
        }
        catch(IOException e)
        {
        	System.out.println("Cannot Read File at location :-"+path);
        }
        test5 test = new test5(imageOld);
        JFrame frame = new JFrame("Zooming & Shrinking");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(test);
        frame.setExtendedState(Frame.MAXIMIZED_BOTH);
        frame.setSize(400,400);
        frame.setLocation(200,200);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }

	
}