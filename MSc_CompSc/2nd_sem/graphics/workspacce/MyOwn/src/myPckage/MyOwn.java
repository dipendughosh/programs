package myPckage;

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

public class MyOwn extends JFrame implements KeyListener,MouseListener,GLEventListener 
{
	double tx = 0;
	double ty = 0;
	double z = 1;
	double rx = 0;
	double ry = 0;
	double f = 2;
		
	public static void main(String[] args)
	{
	//	System.out.println("Hello World");
	/*	DataInputStream in = new DataInputStream(System.in);
		int intNumber=0;
		float floatNumber=0.0f;
		try
		{
			System.out.print("Enter Integer Value: ");
			intNumber=Integer.parseInt(in.readLine());eee
			System.out.print("Enter Float Value: ");
			floatNumber=Float.valueOf(in.readLine()).floatValue();
		}
		catch(Exception E)
		{
		}
		System.out.println("intNumber = "+intNumber);
		System.out.println("floatNumber = "+floatNumber);*/
	//	System.out.println("hi");
		int i =0;
		while(i < 10)
		{
			System.out.println(Math.random());
			i += 1;
		}
		MyOwn frame = new MyOwn();
		frame.setTitle("My Own Frame");
		frame.setSize(800, 600);
		frame.setDefaultCloseOperation(EXIT_ON_CLOSE);
	//	frame.setVisible(true);
		
	//	frame.addKeyListener(frame);
	//	frame.addMouseListener(frame);
		
		GLCanvas canvas = new GLCanvas();
		frame.add(canvas);
		canvas.addGLEventListener(frame);
		
	//	frame.setVisible(true);
		frame.addKeyListener(frame);
		canvas.addMouseListener(frame);
		
		Animator animator = new Animator(canvas);
		animator.start();
		
		frame.setVisible(true);
	}

	@Override
	public void keyPressed(KeyEvent ke) 
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
			ry = ry +.4;
			f = 0;
		}
		else if(ke.getKeyCode() == KeyEvent.VK_3)//Rotate right
		{
			rx = rx + .4;
			ry = ry - .4;
			f = 0;
		}
		else if(ke.getKeyCode() == KeyEvent.VK_7)//Rotate Up
		{
			ry = ry + .4;
			rx = rx + .4;
			f = 1;
		}
		else if(ke.getKeyCode() == KeyEvent.VK_9)//Rotate Down
		{
			ry = ry - .4;
			rx = rx - .4;
			f = 1;
		}
		//System.out.println("Key Pressed is : "+ke.getKeyChar());
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
		
	}

	@Override
	public void display(GLAutoDrawable drawable) 
	{
		GL gl = drawable.getGL();
		gl.glClear(GL.GL_COLOR_BUFFER_BIT);
		gl.glLoadIdentity();
		gl.glClearColor((float) .8, (float) .5, (float) .2, (float) .1);
		gl.glTranslated(tx, 0, 0);
		gl.glTranslated(0, ty, 0);
		if(z > 0 && z < 1)
		{
			gl.glScaled(z, z, 1);
		}
		
		gl.glRotated(rx, .4, 0, 0);
		gl.glRotated(ry, 0, .4, 0);
		
		drawTriangle(gl);
		drawSquare(gl);
		drawRectangle(gl);
		drawCircle(gl);
		
	}

	private void drawCircle(GL gl) 
	{
	
	}

	private void drawRectangle(GL gl) 
	{
		gl.glRectd(.8, -.8, .2, -.2);
		gl.glColor3d(1, 0, 0);
    	gl.glVertex3d(.8, .2, 0);
    	gl.glColor3d(0, 1, 0);
    	gl.glVertex3d(-.8, .2,0);
    	gl.glColor3d(0, 0, 1);
    	gl.glVertex3d(.8, -.2,0);
    	gl.glColor3d(0, 0, 1);
    	gl.glVertex3d(-.8, -.2, 0);
		
	}

	private void drawSquare(GL gl)
	{
		
	}

	private void drawTriangle(GL gl)
	{
		gl.glBegin(GL.GL_TRIANGLES);
	    	gl.glColor3d(1, 0, 0);
	    	gl.glVertex3d(0, .3, 0);
	    	gl.glColor3d(0, 1, 0);
	    	gl.glVertex3d(-.3, -.3,0);
	    	gl.glColor3d(0, 0, 1);
	    	gl.glVertex3d(.3, -.3,0);
	    gl.glEnd();	
		
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
