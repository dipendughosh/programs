package jogl;

import java.awt.BorderLayout;
import java.awt.Frame;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.media.opengl.GLCanvas;
import javax.media.opengl.GLCapabilities;
import javax.media.opengl.GLDrawable;
import javax.media.opengl.GLDrawableFactory;
import javax.media.opengl.GLEventListener;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.*;

import com.sun.opengl.util.Animator;

import package1.GameWindow;
import package1.GameWindowCallback;
import util.Keyboard;

public class JoglGameWindow implements GLEventListener,GameWindow 
{
	private Frame frame;
	private GameWindowCallback callback;
	private int width;
	private int height;
	private GLCanvas canvas;
	private GL gl;
	private TextureLoader textureLoader;
	
	public JoglGameWindow() 
	{
		frame = new Frame();
	}
	
	TextureLoader getTextureLoader() 
	{
		return textureLoader;
	}
	
	GL getGL() 
	{
		return gl;
	}
	
	public void setTitle(String title) 
	{
		frame.setTitle(title);
	}

	public void setResolution(int x, int y) 
	{
		width = x;
		height = y;
	}

	public void startRendering() 
	{
		GLCapabilities caps = new GLCapabilities();
		canvas = new GLCanvas(caps);
		//canvas = GLDrawableFactory.getFactory().createGLCanvas(new GLCapabilities());
		//canvas = new GLCanvas(GLCapabilities());
		canvas.addGLEventListener(this);		
		//canvas.setNoAutoRedrawMode(true);
		canvas.setFocusable(true);

		Keyboard.init(canvas);
		
		Animator animator = new Animator(canvas);
		
		frame.setLayout(new BorderLayout());
		frame.add(canvas);
		frame.setResizable(false);
		canvas.setSize(width, height);
		frame.pack();
		frame.show();
		
		frame.addWindowListener(new WindowAdapter() 
		{
			public void windowClosing(WindowEvent e) 
			{
				if (callback != null) 
				{
					callback.windowClosed();
				}
				else
				{
					System.exit(0);
				}
			}
		}
		);
		
		animator.start();
	}

	public void setGameWindowCallback(GameWindowCallback callback) 
	{
		this.callback = callback;
	}

	public boolean isKeyPressed(int keyCode) 
	{
		return Keyboard.isPressed(keyCode);
	}

	public void init(GLDrawable drawable) 
	{
		gl = canvas.getGL();
		//gl = drawable.getGL();
		
		gl.glEnable(GL.GL_TEXTURE_2D);
		
		gl.glClearColor(0, 0, 0, 0);
		gl.glViewport(0, 0, width, height);
		gl.glDisable(GL.GL_DEPTH_TEST);
		
		textureLoader = new TextureLoader(((GLCanvas) drawable).getGL());
		
		if (callback != null) 
		{
			callback.initialise();
		}
	}

	public void display(GLDrawable drawable) 
	{
	
		gl = canvas.getGL();
		
		gl.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT);
		gl.glMatrixMode(GL.GL_MODELVIEW);
		gl.glLoadIdentity();
		
		if (callback != null) 
		{
			callback.frameRendering();
		}
		
		gl.glFlush();
	}

	public void reshape(GLDrawable drawable, int x, int y, int width, int height) 
	{
		gl = canvas.getGL();
		
		gl.glMatrixMode(GL.GL_PROJECTION);
		gl.glLoadIdentity();

		gl.glOrtho(0, width, height, 0, -1, 1);
	}

	public void displayChanged(GLDrawable drawable, boolean modeChanged, boolean deviceChanged) 
	{
	}

	@Override
	public void display(GLAutoDrawable drawable) 
	{
		// TODO Auto-generated method stub
		
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