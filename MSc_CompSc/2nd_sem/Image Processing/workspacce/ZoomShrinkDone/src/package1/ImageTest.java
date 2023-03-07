package package1;

import java.awt.AlphaComposite;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.io.DataInputStream;
 
public class ImageTest
{
 
	private static int IMG_WIDTH = 100;
	private static int IMG_HEIGHT = 100;
 
	public static void main(String [] args)
	{
		
		DataInputStream in = new DataInputStream(System.in);
		int w = 0;
		int h = 0;
		try
		{
			System.out.println("Enter The output Dimensions of the Images");
			System.out.print("Enter Width: ");
			w=Integer.parseInt(in.readLine());
			System.out.print("Enter Height: ");
			h=Integer.parseInt(in.readLine());
		}
		catch(Exception E)
		{
		}
		IMG_WIDTH = w;
		IMG_HEIGHT = h;
		try
		{
			BufferedImage originalImage = ImageIO.read(new File("E:\\Program\\Programs\\MSc_CompSc\\2nd sem\\Image Processing\\workspacce\\ZoomShrinkDone\\src\\package1\\1.bmp"));
			int type = originalImage.getType() == 0? BufferedImage.TYPE_INT_ARGB : originalImage.getType();
			System.out.println(type);
			
			BufferedImage resizeImageJpg = resizeImage(originalImage, type);
			ImageIO.write(resizeImageJpg, "jpg", new File("E:\\Program\\Programs\\MSc_CompSc\\2nd sem\\Image Processing\\workspacce\\ZoomShrink1\\src\\package7\\mkyong_jpg.jpg")); 
 
			BufferedImage resizeImagePng = resizeImage(originalImage, type);
			ImageIO.write(resizeImagePng, "bmp", new File("E:\\Program\\Programs\\MSc_CompSc\\2nd sem\\Image Processing\\workspacce\\ZoomShrink1\\src\\package7\\mkyong.bmp")); 
 
			BufferedImage resizeImageHintJpg = resizeImageWithHint(originalImage, type);
			ImageIO.write(resizeImageHintJpg, "gif", new File("E:\\Program\\Programs\\MSc_CompSc\\2nd sem\\Image Processing\\workspacce\\ZoomShrink1\\src\\package7\\mkyong_hint.gif")); 
 
			BufferedImage resizeImageHintPng = resizeImageWithHint(originalImage, type);
			ImageIO.write(resizeImageHintPng, "png", new File("E:\\Program\\Programs\\MSc_CompSc\\2nd sem\\Image Processing\\workspacce\\ZoomShrink1\\src\\package7\\mkyong_hint.png")); 
		}
		catch(IOException e)
		{
			System.out.println(e.getMessage());
		}
	}
 
    private static BufferedImage resizeImage(BufferedImage originalImage, int type)
    {
    	BufferedImage resizedImage = new BufferedImage(IMG_WIDTH, IMG_HEIGHT, type);
    	Graphics2D g = resizedImage.createGraphics();
    	g.drawImage(originalImage, 0, 0, IMG_WIDTH, IMG_HEIGHT, null);
    	g.dispose();
    	return resizedImage;
    }
 
    private static BufferedImage resizeImageWithHint(BufferedImage originalImage, int type)
    {
    	BufferedImage resizedImage = new BufferedImage(IMG_WIDTH, IMG_HEIGHT, type);
    	Graphics2D g = resizedImage.createGraphics();
    	g.drawImage(originalImage, 0, 0, IMG_WIDTH, IMG_HEIGHT, null);
    	g.dispose();	
    	g.setComposite(AlphaComposite.Src);
    	
    	g.setRenderingHint(RenderingHints.KEY_INTERPOLATION,RenderingHints.VALUE_INTERPOLATION_BILINEAR);
    	g.setRenderingHint(RenderingHints.KEY_RENDERING,RenderingHints.VALUE_RENDER_QUALITY);
    	g.setRenderingHint(RenderingHints.KEY_ANTIALIASING,RenderingHints.VALUE_ANTIALIAS_ON);
    	return resizedImage;
    }	
}