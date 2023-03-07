package java2D;

import java.awt.Image;

import package1.Sprite;

public class Java2DSprite implements Sprite 
{
	private Image image;
	private Java2DGameWindow window;

	public Java2DSprite(Java2DGameWindow window, Image image) 
	{
		this.image = image;
		this.window = window;
	}

	public int getWidth() 
	{
		return image.getWidth(null);
	}

	public int getHeight() 
	{
		return image.getHeight(null);
	}

	public void draw(int x, int y) 
	{
		window.getDrawGraphics().drawImage(image, x, y, null);
	}
}
