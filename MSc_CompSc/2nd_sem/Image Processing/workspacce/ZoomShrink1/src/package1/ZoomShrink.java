package package1;

import java.awt.*;
import java.awt.event.*;
import java.awt.geom.AffineTransform;
import java.awt.image.BufferedImage;
import java.io.*;
import javax.swing.*;
public class ZoomShrink  {
    
	private JScrollPane getContent()
	{
		Image orig = loadImage();
		BufferedImage scaled = null;
		try
		{
			scaled = getScaledImage(orig, 0.50);
		}
		catch (Exception e)
		{
			
		}
		JPanel panel = new JPanel(new GridBagLayout());
		GridBagConstraints gbc = new GridBagConstraints();
		gbc.insets = new Insets(5,5,5,5);
		gbc.weightx = 1.0;
		try
		{
			panel.add(new JLabel(new ImageIcon(orig)), gbc);
			panel.add(new JLabel(new ImageIcon(scaled)), gbc);
		}
		catch (Exception e)
		{
			
		}
		return new JScrollPane(panel);
	}

	private Image loadImage() 
	{
		String path = "packages.images/1.jpg";
		InputStream is = getClass().getResourceAsStream(path);
		ImageIcon icon;
		Image image = null;
		int status = 0;
		byte[] imageData = null;
		try
		{
			imageData = readData(is);
			icon = new ImageIcon(imageData);
			image = icon.getImage();
			status = icon.getImageLoadStatus();
		}
		catch (Exception e)
		{
			
		}
		//ImageIcon icon = new ImageIcon(imageData);
		//Image image = icon.getImage();
		// ImageIcon does not let you know if the image was not
		// successfully loaded so you must ask it for feedback.
		//int status = icon.getImageLoadStatus();
		String result = "";
		switch(status) 
		{
			case MediaTracker.ABORTED:
				result = "ABORTED";
				break;
			case MediaTracker.ERRORED:
				result = "ERRORED";
				break;
			case MediaTracker.COMPLETE:
				result = "COMPLETE";
				break;
			default:
				result = "unexpected loadingStatus: " + status;
		}
		System.out.println("Loading status for \"" + path + "\": " + result);
		return image;
	}
	
	private byte[] readData(InputStream is) throws Exception 
	{
		ByteArrayOutputStream baos = new ByteArrayOutputStream();
		try
		{
			byte[] buffer = new byte[4096];
			int len, count = 0;
			try
			{
				while((len = is.read(buffer)) != -1) 
				{	
					baos.write(buffer, 0, len);
					count += len;
				}
				is.close();
				System.out.println("image size = " + count);
			}
			catch (Exception e) 
			{
				throw e;
			}
		}
		catch(IOException e1) 
		{
			System.out.println("read error: " + e1.getMessage());
		}
		return baos.toByteArray();
	}

	private BufferedImage getScaledImage(Image image, double scale) 
	{
		int w = 0;
		int h = 0;
		try
		{
			w = (int)(scale*image.getWidth(null));
			h = (int)(scale*image.getHeight(null));
		}
		catch (Exception e)
		{
			
		}
		int type = BufferedImage.TYPE_INT_RGB;
		BufferedImage out = new BufferedImage(w, h, type);
		Graphics2D g2 = out.createGraphics();
		AffineTransform at = AffineTransform.getScaleInstance(scale, scale);
		g2.drawImage(image, at, null);
		g2.dispose();
		return out;
	}
	
	public static void main(String[] args) 
	{
		JFrame f = new JFrame();
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.getContentPane().add(new ZoomShrink().getContent());
		f.setSize(400,400);
		f.setLocation(200,200);
		f.setVisible(true);
	}
}