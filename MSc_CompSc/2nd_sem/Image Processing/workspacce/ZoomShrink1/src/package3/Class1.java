package package3;

/*
  <applet code="Class1" width=248 height=146>
  	<param name="img" value="1.jpg">
  </applet>
 */

import java.awt.*;
import java.applet.*;

public class Class1 extends Applet 
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	Image img;
	
	public void init()
	{
		img = getImage(app.html,"1.jpg");
	}
	
	public void paint(Graphics g)
	{
		g.drawImage(img, 0, 0, this);
	}
/*	public Class1()
	{
		
	}

	
	public static void main(String[] args)
	{
		

	}*/

}
