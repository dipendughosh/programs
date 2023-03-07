/*Assignment 2:- Histogram Equalization of a Digital Image*/
package package1;

/*Import JAVA and JAVAX packages*/
import java.awt.*;
import java.io.*;
import javax.swing.*;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

/*Declaring the main class that extends JPanel*/
public class Histogram extends JPanel
{
    private static final long serialVersionUID = 1L;
    
    /*Declaring BufferImage variables which will store the original image and the modified images*/
	//Stores the original image
	BufferedImage imageOld;
	//Stores the gray style image
	BufferedImage imageNew;
	//Stores the new image equalized image
	BufferedImage imageEq;
	
	/*Declaring variables which will be used for creating the new image*/
	//Stores the width of the image
	public static int width = 0;
	//Stores the height of the image
	public static int height = 0;
	//Stores the pixel intensity of the image
	public static int val = 0;
	//Used to calculate the histogram only once 
	public int flag = 1;
	//Stores the number of pixels of the original image with the intensities equal to the index of the array 
	public int arr1[] = new int[256];
	//Stores the number of pixels of the equalized image with the intensities equal to the index of the array
	public int arr2[] = new int[256];
	//Stores the original histogram values
	public float pr[] = new float[256];
	//Stores the equalized histogram values
	public float ps[] = new float[256];
	
	/*Constructor to initialize the variables of the class*/
    public Histogram(BufferedImage imageOld) 
    {
    	//Initialize the original image
        this.imageOld = imageOld;
        
        //Initialize the width of the image
        width=imageOld.getWidth();
        //Initialize the height of the image
        height=imageOld.getHeight();
        
        //Create the buffer space for the new image to be drawn on the screen for in gray style
        this.imageNew = new BufferedImage(imageOld.getWidth(),imageOld.getHeight(),BufferedImage.TYPE_INT_RGB);
        //Create the buffer space for the equalized image to be drawn on the screen
        this.imageEq = new BufferedImage(imageOld.getWidth(),imageOld.getHeight(),BufferedImage.TYPE_INT_RGB);
        
        //Initializes the array which stores the intensity values of the original gray style image
        for(int i = 0;i < 256;i++)
        {
        	arr1[i] = 0;
        }

        //Initializes the array which stores the intensity values of the equalized gray style image
        for(int i = 0;i < 256;i++)
        {
        	arr2[i] = 0;
        }
    }

    /*Function which is called to paint the screen to display the images at regular intervals*/
    protected void paintComponent(Graphics g) 
    {
    	//Passing the graphics display screen components to the superclass function to be displayed on the screen area
        super.paintComponent(g);

        //Calling the function that creates the gray style image from the original image and then equalizes the image and creates the original and the equalized histogram
        makeHistogram();
        
        //Calling the function that draws the images on the screen
        drawImage(g);
        
        //Calling the function that draws the histograms on the screen
        drawHistogram(g);
    }
 
    /*Function to create the create the gray image and then calculate the histograms*/
    private void makeHistogram()
    {
    	//Declaring local variables
    	int i = 0,j = 0;
        int v = 0;
        int valu = 0;
        int re = 0,ge = 0,bl = 0;
        float s[] = new float[256];
        int org_img_arr[][] = new int[width][height];
        
        //Initializing array to be used to calculate the histogram
        for(i = 0;i < 256;i++)
    	{
    		s[i] = 0;
    	}
        
        //Calculating the histograms only once and also creating the images only once
        if(flag == 1)
        {
        	//Creating the gray scale image
           	for(i = 0;i < width;i++)
        	{
        		for(j = 0;j < height;j++)
        		{
        			//Extracting the pixel intensity at a particular point
        			val = imageOld.getRGB(i,j);
        			re = (int)(val >> 16) & 0xFF;
        			ge = (int)(val >> 8) & 0xFF;
          			bl = (int)(val >>0) & 0xFF;
          			v = (re+ge+bl)/3;
          			valu = (v<<16)|(v<<8)|(v);
          			//Creating the image
          			imageNew.setRGB(i,j,valu);
        		}
        	}
        	
           	//Creating the intensity map and storing the pixel intensities 
        	for(i = 0;i < width;i++)
        	{
        		for(j = 0;j < height;j++)
        		{
        			//Extracting the pixel intensity at a particular point
        			val = imageNew.getRGB(i,j);
        			re = (val >> 16) & 0xFF;
        			ge = (val >> 8) & 0xFF;
          			bl = (val >> 0) & 0xFF;
          			//Calculating the n for each k of the original image
          			arr1[(re+ge+bl)/3]++;
          			//Creates the intensity map array
          			org_img_arr[i][j] = (re+ge+bl)/3;
        		}
        	}
        	
        	flag = 0;
        	
        	//Calculating the original histogram of the original image
        	for(i = 0;i < 256;i++)
        	{
        		try
        		{
        			pr[i] = (float)arr1[i]*255/(float)(width*height);
        		}
        		catch(Exception e)
        		{       			
        		}
        	}
        	
        	//Calculating temporary values for the equalized image 
        	for (i = 0;i < 256;i++)
        	{
        		for (j = 0;j <= i;j++)
        		{
        			s[i] = s[i] + pr[j];
        		}
        	}
        	
        	//Creating the equalized image
        	for(i = 0;i < width;i++)
        	{
        		for(j = 0;j < height;j++)
        		{
        			//Extracting the equalized pixel of the equalized image
        			v = Math.round(s[org_img_arr[i][j]]);
        			re = (v<<16);
        			ge = v<<8;
        			bl = v;
        			valu = re|ge|bl;
        			
        			try
        			{
        				imageEq.setRGB(i,j,valu);
        			}
        			catch(Exception e)
        			{
        			}
        		}
        	}
        	
        	//Storing the pixel intensities 
        	for(i = 0;i < width;i++)
        	{
        		for(j = 0;j < height;j++)
        		{
        			//Extracting the pixel intensity at a particular point
        			val = imageEq.getRGB(i,j);
        			re = (val >> 16) & 0xFF;
        			ge = (val >> 8) & 0xFF;
          			bl = (val >> 0) & 0xFF;
          			//Calculating the n for each k of the equalized image
          			arr2[(re+ge+bl)/3]++;
        		}
        	}
        	
        	//Calculating the equalized histogram of the equalized image
        	for(i = 0;i < 256;i++)
         	{
         		try
         		{
         			ps[i] = (float)arr2[i]*255/(float)(width*height);
         		}
         		catch(Exception e)
         		{       			
         		}
         	}
        }
    }

    /*Function to draw the images on the screen*/
    private void drawImage(Graphics g) 
    {
    	//Setting the color,font,font type and font size for the text to be displayed on the screen
    	g.setColor(Color.magenta);
        g.setFont(new Font("Arial",Font.BOLD, 4));
        
        //Displaying the original image at a particular screen location
    	g.drawString("Original Image",18,18);
        g.drawImage(imageOld,20,20,this);
        
        //Displaying the new gray style image at a particular screen location
   	 	g.drawString("Greyscale Image",98+width, 18);
   	 	g.drawImage(imageNew,100+width,20,this);
   	 	
   	 	//Displaying the equalized image at a particular screen location
   	 	g.drawString("Output Image",196+2*width, 18);
   	 	g.drawImage(imageEq,200+2*width,20,this);
	}

    /*Function to plot the histograms on the screen*/
	private void drawHistogram(Graphics g)
    {
		int i = 0,j = 0;
    	
		//Setting the color,font,font type and font size for the text to be displayed on the screen
    	g.setFont(new Font("Times New Roman",Font.PLAIN,14));
    	
    	//Setting the color and drawing the x and y axis for the original histogram on the screen
    	g.setColor(Color.BLUE);
    	g.fillRect(97,801,520,2);
    	g.fillRect(97,350,2,452);
	 	
    	//Labeling
	 	g.setColor(Color.BLACK);
    	g.drawString("Original Histogram:",250,840);
    	
    	//Drawing the original histogram
        for(i = 0,j = 100;i <= 255;i++,j+=2)
	 	{
   	 		g.drawLine(j,800-(int)pr[i]*5,j,800);
	 	}	
	 
        //Setting the color and drawing the x and y axis for the equalized histogram on the screen
        g.setColor(Color.BLUE);
    	g.fillRect(727,801,520,2);
    	g.fillRect(727,350,2,452);
    	
    	//Labeling
    	g.setColor(Color.BLACK);
    	g.drawString("Equalized Histogram:",880,840);
	 	
    	//Drawing the equalized histogram
	 	for(i = 0,j = 730;i <= 255;i++,j+=2)
   	 	{
	 		g.drawLine(j,800-(int)ps[i]*5,j,800);
   	 	}	
   	 
	 	//Displaying the scale used
 	   	g.setColor(Color.DARK_GRAY);
   	 	g.drawString("Scale:",520,900);
   	 	g.drawString("X-Axis: 1 unit= 1 intensity level",520,920);
   	 	g.drawString("Y-Axis: 5 unit= 1 normalized histogram level",520,940);
    }

	/*Main function*/
	public static void main(String[] args)
    {
		//Loading the image path on which the actios of zooming and shrinking will be done
		String path = "D:\\Programs\\Program\\Programs\\MSc_CompSc\\2nd sem\\Image Processing\\workspacce\\HistogramDone\\src\\package1\\pollen.jpg";
		//Creating a local buffer image in which the image will be loaded
		BufferedImage imageOld = null;
		
		//Loading the image onto the buffer
        try
        {
        	imageOld = ImageIO.read(new File(path));
        }
        catch(IOException e)
        {
        	System.out.println("Cannot Read File at location :-"+path);
        }
        
        //Initializing the class image variable
        Histogram obj = new Histogram(imageOld);
        //Creating the frame on which the image will be displayed
        JFrame frame = new JFrame("Histogram");
        //Setting the default close option
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //Adding the class object to display the image
        frame.add(obj);
        //Maximizing the frame by default
        frame.setExtendedState(Frame.MAXIMIZED_BOTH);
        //Setting the visibility of the frame
        frame.setVisible(true);
    }
}