//ishan
package package4;

import java.awt.*;
import java.io.*;

import javax.swing.*;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;
import java.awt.image.PixelGrabber;
import java.awt.image.Raster;

import javax.imageio.ImageIO;

public class test3 extends JPanel
{
    private static final long serialVersionUID = 1L;
	BufferedImage image;
	BufferedImage imag;
	public int flag = 1;
	public int arr1[][] = new int[256][256];
	public double arr1d[] = new double[256];  
	public double HISTQarrd[] = new double[256];
	
    public test3(BufferedImage image) 
    {
        this.image = image;
        this.imag = new BufferedImage(image.getWidth(),image.getHeight(),BufferedImage.TYPE_BYTE_GRAY);
        for(int i = 0;i<256;i++)
        {
        	for(int j = 0 ; j < 256 ; j++)
        	{
        		arr1[i][j]=0;
        	}
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
        int c=0;
        
        x=image.getWidth();
        y=image.getHeight();
               
        for(int i=0;i<x;i++)
        {
          	for(int j=0;j<y;j++)
          	{
           		val = image.getRGB(i, j);
           		imag.setRGB((int)i, (int)j, val);
           	}
        }
        g.drawImage(image, 20,20,this);
        g.drawImage(imag, 20,250,this);
        
       
       /* for(int i=400;i<656;i++)
        {
        	g.setColor (Color.blue);
        	g.drawLine(i, 900-arr1[i-400]/10, i, 900);
        }
        for(int i=700;i<956;i++)
        {
        	g.setColor (Color.green);
        	g.drawLine(i, 900-arr2[i-700]/10, i, 900);
        }*/
    }
        
    public void pixelinten()
    {
    	Raster rast;
    	int val;
    	double vald;
    	int Evald=0;
    	int s =0;
    	int MAX_INTNSTY=0;
    	double T=0.0;
    	int x=image.getWidth();
        int y=image.getHeight();
        int MN = x*y;
        FileWriter f = null;
        FileWriter f1 = null;
        
		try {
			f = new FileWriter("test.txt");
			f1 = new FileWriter("testEQ.txt");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	
    	for(int i=0;i<x;i++)
    	{
    		for(int j=0;j<y;j++)
    		{
    			byte pix[] = new byte[1];
    			imag.getRaster().getDataElements(i, j, pix);
    			val=pix[0];
    			if (val < 0)
    				val=val * -1 ;
    			arr1[val][1]+=1;
    			
    		}
    	}	
    	for(int i = 0;i<256;i++)
       {    		
    		s=s+arr1[i][1];
    		vald=(double)arr1[i][1]/MN;
    		Math.ceil(vald);
    		arr1d[i]=vald;
    		
    		System.out.println("arr1[" + i + "]"+arr1[i][1]+" "+ arr1[i][2]);
    		
    		if(arr1[i][1] != 0)
    		{
    			MAX_INTNSTY=i;
    		}
    		try {
				f.write("arr1[" + i + "]"+ "=" +arr1[i][1]+ " => " + arr1d[i] + "\n");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
        }
    	try{
			f.close();
		}catch (IOException e){
			e.printStackTrace();}
		
    	System.out.println("Sum= "+s+"  MAX_I" + MAX_INTNSTY );
    	
    	
    	for(int l = 0 ; l <=MAX_INTNSTY ; l++)
    	{
    		for(int k=0 ; k<=l; k++)
    		{
    			T = T + arr1d[k];
    		}
    		HISTQarrd[l]=T;
    		T=0;
    	
    			try {
    			f1.write("HISTQarrd[" + l + "]"+ "=" +HISTQarrd[l]+ " => " + Evald + "\n");
    			} catch (IOException e) {
    			// 	TODO Auto-generated catch block
    			e.printStackTrace();}
    			
    	}	
    	try{
			f1.close();
		}catch (IOException e){
			e.printStackTrace();}
}
    
	public static void main(String[] args){
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
        test3 test = new test3(image);
        JFrame frame = new JFrame("Histogram");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(test);
        frame.setExtendedState(Frame.MAXIMIZED_BOTH);
        frame.setSize(400,400);
        frame.setLocation(200,200);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
        
        test.pixelinten();        
    }

	
}
