package package4;

import java.awt.*;
import java.awt.image.*;
import java.awt.image.renderable.*;
import java.awt.Dimension;

import javax.swing.ImageIcon;

public class bookExample 
{
	Image img;
	
	public void init()
	{
		Dimension d;
		img = new ImageIcon(this.getClass().getResource("1.jpg")).getImage();
		int w = img.getWidth(null);
		int h = img.getHeight(null);
		
		
		
	}
}
