package package7;

import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class KeyInputHandler extends KeyAdapter
{
	public void keyPressed(KeyEvent ke) 
	{
		if(ke.getKeyCode() == KeyEvent.VK_PAGE_UP )
		{
			test2.zoomx=test2.zoomx+1;
			test2.zoomy=test2.zoomy+1;
			test2.flagz=1;
			test2.flags=0;
			update(null);
			repaint();
		}
		if(ke.getKeyCode() == KeyEvent.VK_PAGE_DOWN )
		{
			test2.shrinkx=test2.shrinkx+1;
			test2.shrinky=test2.shrinky+1;
			test2.flagz=0;
			test2.flags=1;
			//update(null);
			repaint();
		}
	} 
	
	public void keyReleased(KeyEvent e)
	{
	}

	public void keyTyped(KeyEvent e) 
	{
	}

}