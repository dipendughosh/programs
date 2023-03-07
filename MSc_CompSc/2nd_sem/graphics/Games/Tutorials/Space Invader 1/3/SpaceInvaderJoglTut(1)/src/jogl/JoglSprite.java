package jogl;

import java.io.IOException;

import javax.media.opengl.GL;

import package1.Sprite;

public class JoglSprite implements Sprite 
{
	private Texture texture;
	private JoglGameWindow window;
	private int width;
	private int height;
	
	public JoglSprite(JoglGameWindow window,String ref) 
	{
		try 
		{
			this.window = window;
			texture = window.getTextureLoader().getTexture(ref);
			
			width = texture.getImageWidth();
			height = texture.getImageHeight();
		}
		catch (IOException e) 
		{
			System.err.println("Unable to load texture: "+ref);
			System.exit(0);
		}
	}
	
	public int getWidth() 
	{
		return texture.getImageWidth();
	}

	public int getHeight() 
	{
		return texture.getImageHeight();
	}

	public void draw(int x, int y) 
	{
	
		GL gl = window.getGL();
	
		gl.glPushMatrix();
		
		texture.bind(gl);		
		gl.glTranslatef(x, y, 0);		
		gl.glColor3f(1,1,1);
		
		gl.glBegin(GL.GL_QUADS);
		{
			gl.glTexCoord2f(0, 0);
			gl.glVertex2f(0, 0);
			gl.glTexCoord2f(0, texture.getHeight());
			gl.glVertex2f(0, height);
			gl.glTexCoord2f(texture.getWidth(), texture.getHeight());
			gl.glVertex2f(width,height);
			gl.glTexCoord2f(texture.getWidth(), 0);
			gl.glVertex2f(width,0);
		}
		gl.glEnd();
		
		gl.glPopMatrix();
	}
}