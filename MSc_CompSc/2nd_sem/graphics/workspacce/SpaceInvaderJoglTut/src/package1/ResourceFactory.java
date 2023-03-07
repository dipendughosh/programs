package package1;

import java2D.Java2DGameWindow;
import java2D.Java2DSprite;
import jogl.JoglGameWindow;
import jogl.TextureLoader;

public class ResourceFactory 
{
	private static final ResourceFactory single = new ResourceFactory();

	public static ResourceFactory get() 
	{
		return single;
	}

	public static final int JAVA2D = 1;
	public static final int OPENGL_JOGL = 2;

	private int renderingType = JAVA2D;
	private GameWindow window;

	private ResourceFactory() 
	{
	}

	public void setRenderingType(int renderingType) 
	{
		if ((renderingType != JAVA2D) && (renderingType != OPENGL_JOGL)) 
		{
			throw new RuntimeException("Unknown rendering type specified: "
					+ renderingType);
		}

		if (window != null) 
		{
			throw new RuntimeException("Attempt to change rendering method at game runtime");
		}

		this.renderingType = renderingType;
	}

	public GameWindow getGameWindow() 
	{
		if (window == null) 
		{
			switch (renderingType) 
			{
				case JAVA2D: 
				{
					window = new Java2DGameWindow();
					break;
				}
				case OPENGL_JOGL: 
				{
					window = new JoglGameWindow();
					break;
				}
			}
		}

		return window;
	}

	public Sprite getSprite(String ref) 
	{
		if (window == null) 
		{
			throw new RuntimeException("Attempt to retrieve sprite before game window was created");
		}

		switch (renderingType) 
		{
			case JAVA2D: 
			{
				return Java2DSprite.Java2DSpriteStore.get().getSprite((Java2DGameWindow) window,ref);
			}
			case OPENGL_JOGL: 
			{
				return new TextureLoader.JoglSprite((JoglGameWindow) window, ref);
			}
		}

		throw new RuntimeException("Unknown rendering type: " + renderingType);
	}
}