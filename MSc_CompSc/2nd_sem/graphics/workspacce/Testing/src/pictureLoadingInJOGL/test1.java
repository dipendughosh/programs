package pictureLoadingInJOGL;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.media.opengl.GLCanvas;
import javax.media.opengl.GLEventListener;
import javax.swing.JFrame;
import javax.swing.JLabel;

import com.sun.opengl.util.Animator;

//import java.io.DataInputStream;

public class test1 extends JFrame implements GLEventListener 
{
	/*double tx = 0;
	double ty = 0;
	double z = 1;
	double rx = 0;
	double ry = 0;
	double f = 2;*/
		
	public static void main(String[] args)
	{
	
		test1 frame = new test1();
		frame.setTitle("My Own Frame");
		frame.setSize(800, 600);
		frame.setDefaultCloseOperation(EXIT_ON_CLOSE);
		GLCanvas canvas = new GLCanvas();
		frame.add(canvas);
		canvas.addGLEventListener(frame);
		/*frame.addKeyListener(frame);
		canvas.addMouseListener(frame);*/
		Animator animator = new Animator(canvas);
		animator.start();
		frame.setVisible(true);
	}
	// load a 256x256 RGB .RAW file as a texture
	/*GLuint LoadTextureRAW( const char * "pictureLoadingInJOGL/images/ship.gif", int wrap )
	{
		GLuint texture;
		int width, height;
		BYTE  data;
		FILE  file;
		// 		open texture data
		file = fopen( "pictureLoadingInJOGL/images/ship.gif", "rb" );
		if ( file == NULL ) return 0;
		// 	allocate buffer
		width = 256;
		height = 256;
		data = malloc( width * height * 3 );
		// read texture data
		fread( data, width * height * 3, 1, file );
		fclose( file );
		// allocate a texture name
		glGenTextures( 1, texture );
		// select our current texture
		glBindTexture( GL_TEXTURE_2D, texture );
		// select modulate to mix texture with color for shading
		glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
		// when texture area is small, bilinear filter the closest mipmap
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
		// when texture area is large, bilinear filter the first mipmap
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		// 	if wrap is true, the texture wraps over at the edges (repeat)
		// 	... false, the texture ends at the edges (clamp)
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,wrap ? GL_REPEAT : GL_CLAMP );
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,wrap ? GL_REPEAT : GL_CLAMP );
		// 	build our texture mipmaps
		gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
		// free buffer
		free( data );
		return texture;
	}
	/*@Override
	/*public void keyPressed(KeyEvent ke) 
	{
		if(ke.getKeyCode() == KeyEvent.VK_UP)//Move up
		{
			ty = ty + .02;
		}
		else if(ke.getKeyCode() == KeyEvent.VK_DOWN)//Move Down
		{
			ty = ty - .02;
		}
		else if(ke.getKeyCode() == KeyEvent.VK_RIGHT)//Move Right
		{
			tx = tx + .02;
		}
		else if(ke.getKeyCode() == KeyEvent.VK_LEFT)//Move Left
		{
			tx = tx - .02;
		}
		else if(ke.getKeyCode() == KeyEvent.VK_ADD)//Zoom Out
		{
			z = z + .02;
		}
		else if(ke.getKeyCode() == KeyEvent.VK_SUBTRACT)//Zoom In
		{
			z = z - .02;
		}
		else if(ke.getKeyCode() == KeyEvent.VK_1)//Rotate Left
		{
			rx = rx - .4;
			f = 0;
		}
		else if(ke.getKeyCode() == KeyEvent.VK_3)//Rotate right
		{
			rx = rx + .4;
			f = 0;
		}
		else if(ke.getKeyCode() == KeyEvent.VK_7)//Rotate Up
		{
			ry = ry + .4;
			f = 1;
		}
		else if(ke.getKeyCode() == KeyEvent.VK_9)//Rotate Down
		{
			ry = ry - .4;
			f = 1;
		}
	}

	@Override
	public void keyReleased(KeyEvent arg0) 
	{
		// TODO Auto-generated method stub
	}

	@Override
	public void keyTyped(KeyEvent ke) 
	{
		//System.out.println("Key Typed is : "+ke.getKeyChar());
	}

	@Override
	public void mouseClicked(MouseEvent mo)
	{
		//System.out.println("Clicked is : "+mo.getButton());
		System.out.println("x = "+mo.getX()+" y = "+mo.getY());
		
	}

	@Override
	public void mouseEntered(MouseEvent arg0)
	{
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseExited(MouseEvent arg0) 
	{
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mousePressed(MouseEvent arg0) 
	{
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseReleased(MouseEvent arg0) 
	{
		// TODO Auto-generated method stub
		
	}*/

	@Override
	public void display(GLAutoDrawable drawable) 
	{
		GL gl = drawable.getGL();
		gl.glClear(GL.GL_COLOR_BUFFER_BIT);
		//gl.glLoadIdentity();
		gl.glClearColor(0, 0, 0, 0);
		/*gl.glTranslated(tx, 0, 0);
		gl.glTranslated(0, ty, 0);
		if(z > 0 && z < 1)
		{
			gl.glScaled(z, z, 1);
		}
		
		gl.glRotated(rx, .4, 0, 0);
		gl.glRotated(ry, 0, .4, 0);*/
		
	}

	private void drawCircle(GL gl) 
	{
	
	}

	@Override
	public void displayChanged(GLAutoDrawable drawable, boolean modeChanged,boolean deviceChanged) 
	{
		// TODO Auto-generated method stub
		
	}

	@Override
	public void init(GLAutoDrawable drawable) 
	{
		// TODO Auto-generated method stub
		
	}

	@Override
	public void reshape(GLAutoDrawable drawable, int x, int y, int width,int height) 
	{
		// TODO Auto-generated method stub
		
	}
}
