package trialGame1;

import java.awt.Frame;
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

public class trialGame1 extends JFrame implements KeyListener,MouseListener,GLEventListener
{
	double tx = 0;
	/*double ty = 0;
	double z = 1;
	double rx = 0;
	double ry = 0;
	double f = 2;*/
	
	public static void main(String[] args) 
	{
		trialGame1 frame = new trialGame1();
		frame.setTitle("My Own Frame");
		frame.setSize(800, 600);
		frame.setExtendedState(Frame.MAXIMIZED_BOTH);
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
		if(ke.getKeyCode() == KeyEvent.VK_RIGHT && tx <= .8)//Move Right
		{
			tx = tx + .02;
		}
		else if(ke.getKeyCode() == KeyEvent.VK_LEFT && tx >= -.8)//Move Left
		{
			tx = tx - .02;
		}
		if(ke.getKeyCode() == KeyEvent.VK_ESCAPE) 
    	{
			System.exit(0);
    	}
	}

	@Override
	public void keyReleased(KeyEvent arg0) 
	{
		// TODO Auto-generated method stub
		
	}

	@Override
	public void keyTyped(KeyEvent arg0) 
	{
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseClicked(MouseEvent arg0) 
	{
		// TODO Auto-generated method stub
		
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
		drawBlocks(gl);
		
		gl.glLoadIdentity();
		drawBlock(gl);
		
		gl.glLoadIdentity();
		if(tx >= -.8 && tx <= .8)
		{
			gl.glTranslated(tx, 0, 0);
		//	System.out.println(tx);
		}
		drawRect(gl);
		
	}
	
	

	private void drawBlock(GL gl)
	{
		gl.glColor3d(.5, .4, .8);
		//gl.glRectd(.05, -.75, -.05, -.85);
		gl.glColor3d(1, 1, 1);
		
	}

	private void drawBlocks(GL gl)
	{
		double i,j;
		for(i = -.9 ; i < .8 ; i += .1 )
		{
			for(j = .9 ; j >= 0 ; j -= .1 )
			{
				gl.glRectd(i, j, i+.09, j-.09);
			}
		}
		
	}

	private void drawRect(GL gl)
	{
		if(tx >= -.8 && tx <= .8)
		{
			gl.glRectd(.2, -.85, -.2, -.9);
		}
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
