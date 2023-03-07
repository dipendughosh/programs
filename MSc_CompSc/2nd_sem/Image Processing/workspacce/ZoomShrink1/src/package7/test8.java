/*Assignment 1:-Zooming and Shrinking of a Digital Image(float)*/
package package7;

/*Import JAVA and JAVAX packages*/
import java.awt.*;
import java.io.*;
import javax.swing.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

/*Declaring the main class that extends JPanel and implements KeyListner*/
public class test8 extends JPanel implements KeyListener
{
	private static final long serialVersionUID = 1L;
	
	/*Declaring BufferImage variables which will store the original image and the modified image*/
	//Stores the original image
	BufferedImage imageOld;	
	//Stores the new image
	BufferedImage imageNew;				
	
	/*Declaring variables which will be used for creating the new image*/
	//Stores the width of the image
	public static int width = 0;
	//Stores the height of the image
	public static int height = 0;
	//Stores the pixel intensity of the image
	public static int val = 0;
	//Zoom factor in the x direction
	public static int zoomx = 1;
	//Zoom factor in the y direction
	public static int zoomy = 1;
	//Shrink factor in the x direction
	public static int shrinkx = 1;
	//Shrink factor in the y direction
	public static int shrinky = 1;
	//Flag to modify the factors for zooming
	public static int flags = 1;
	//Flag to modify the factors for shrinking
	public static int flagz = 1;
	
	/*Constructor to initialize the variables of the class*/
    public test8(BufferedImage imageOld) 
    {
    	//Initialize the original image
        this.imageOld = imageOld;
        //Initialize the new image
        this.imageNew = imageOld;
        
        //Initialize the width of the image
        width=imageOld.getWidth();
        //Initialize the height of the image
        height=imageOld.getHeight();
    }
    
    /*Function to reload the image for repainting the screen*/
    public void LoadBuffer()
	{
    	//Create the buffer space for the new image to be drawn on the screen for zooming
    	if(flagz == 1)
        {
    		try
        	{
    			this.imageNew = new BufferedImage(imageOld.getWidth()*zoomx,imageOld.getHeight()*zoomy,BufferedImage.TYPE_INT_RGB);
        	}
    		catch(Exception e)
    		{
    		}
        }
    	
    	//Create the buffer space for the new image to be drawn on the screen for shrinking        
        if(flags == 1)
        {
        	try
        	{
        		this.imageNew = new BufferedImage(imageOld.getWidth()/shrinkx,imageOld.getHeight()/shrinky,BufferedImage.TYPE_INT_RGB);
        	}
        	catch(Exception e)
        	{
        	}
        }
	}

    /*Function which is called to paint the screen to display the images at regular intervals*/
    protected void paintComponent(Graphics g) 
    {
    	//Passing the graphics display screen components to the superclass function to be displayed on the screen area
        super.paintComponent(g);

        //Calling the function that creates the new image depending on the user's key input
        makeImage();
       
        //Calling the function that draws the images on the screen
        drawImages(g);
    }

    /*Function to create the new image*/
	private void makeImage()
    {
		//Declaring local variables
		int i = 0,j = 0;
		
		//For zooming the image
    	if(flagz == 1)
        {
        	for(i = 0;i < width*zoomx;i++)
        	{
        		for(j = 0;j < height*zoomy;j++)
        		{
        			//Reading the value at particular pixel position in the original image which is close to the pixel position in the new image
        			val = imageOld.getRGB(i/zoomx,j/zoomy);
        			//Mapping the value obtained to the new image
        			imageNew.setRGB(i,j,val);
        		}	
        	}
        }
        
		//For shrinking the image
        if(flags == 1)
        {
        	for(i = 0;i < width/shrinkx;i++)
        	{
        		for(j = 0;j < height/shrinky;j++)
        		{
        			//Reading the value at particular pixel position in the original image which is close to the pixel position in the new image
        			val = imageOld.getRGB(i*shrinkx,j*shrinky);
        			//Mapping the value obtained to the new image
        			imageNew.setRGB(i,j,val);
        		}
        	}
        }	
	}

	/*Function to draw the images on the screen*/
    private void drawImages(Graphics g) 
    {
    	//Setting the color,font,font type and font size for the text to be displayed on the screen  
    	g.setColor(Color.magenta);
        g.setFont(new Font("Arial",Font.BOLD,20));
        
        //Displaying the original image at a particular screen location
        g.drawString("Original Image",18,18);
        g.drawImage(imageOld,20,30,this);

        //Displaying the new image at a particular screen location
        g.drawString("Changeing Image",100+width,20);
        g.drawImage(imageNew,108+width,30,this);
        
        //Setting the color,font,font type and font size for the text to be displayed on the screen  
    	g.setColor(Color.black);
        g.setFont(new Font("Arial",Font.PLAIN,22));
        
        //Displaying the key controls to help the user
        g.drawString("Key Controls",100,900);
        g.drawString("Page UP:- Zoom In",100,920);
        g.drawString("Page DOWN:- Zoom Out",100,940);
    }
    
	/*Function that detects the key pressed*/
	@Override
	public void keyPressed(KeyEvent Key)
	{
		//If PAGE UP key is pressed then for zooming the factors are changed accordingly 
		if(Key.getKeyCode() == KeyEvent.VK_PAGE_UP)
		{
			//Checking if the original image has been shrinked then modify on the new image else on the old image
			if(flags == 1)
			{
				if(shrinkx > 1)
				{
					shrinkx-=1;
					shrinky-=1;
					flags = 1;
					flagz = 0;
				}
				else
				{
					zoomx+=1;
					zoomy+=1;
					flagz = 1;
					flags = 0;
				}
			}
			
			else
			{
				zoomx+=1;
				zoomy+=1;
				flagz = 1;
				flags = 0;
			}	
			LoadBuffer();
			repaint();
		}
		
		//If PAGE DOWN key is pressed then for shrinking the factors are changed accordingly
		if(Key.getKeyCode() == KeyEvent.VK_PAGE_DOWN)
		{
			//Checking if the original image has been zoomed then modify on the new image else on the old image
			if(flagz == 1)
			{
				if(zoomx > 1)
				{
					zoomx-=1;
					zoomy-=1;
					flagz = 1;
					flags = 0;
				}
				else
				{
					shrinkx+=1;
					shrinky+=1;
					flags = 1;
					flagz = 0;
				}
			}
			else
			{
				shrinkx+=1;
				shrinky+=1;			
				flags = 1;
				flagz = 0;
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
	public void keyTyped(KeyEvent Key) 
	{
	}

	/*Main function*/
	public static void main(String[] args)
    {
		//Loading the image path on which the actios of zooming and shrinking will be done
        String path = "C:\\images\\02.png";
		//Creating a local buffer image in which the image will be loaded
        BufferedImage image = null;
        		
        //Loading the image onto the buffer
		try
        {
        	image = ImageIO.read(new File(path));
        }
        catch(IOException e)
        {
        	System.out.println("Cannot Read File at location :-"+path);
        }
        
        //Initializing the class image variable
        test8 obj = new test8(image);
        //Creating the frame on which the image will be displayed
        JFrame frame = new JFrame("Zooming & Shrinking");
        //Setting the default close option
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //Adding the class object to display the image
        frame.add(obj);
        //Maximizing the frame by default
        frame.setExtendedState(Frame.MAXIMIZED_BOTH);
        //Adding the key listener to the frame
        frame.addKeyListener(obj);
        //Setting the visibility of the frame
        frame.setVisible(true);
    }
}