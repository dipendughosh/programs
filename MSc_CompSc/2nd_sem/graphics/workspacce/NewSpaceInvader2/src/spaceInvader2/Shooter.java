package spaceInvader2;

import java.awt.Point;
import java.awt.event.KeyEvent;

import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;

public class Shooter extends Thread implements SpaceObjects 
{
	SpaceInvader parent = null;
	public
	Point position;
	double ttx=0;
	double tx=0;
	double dx=0;
	double ty=-.75;
	double rx = 0;
	boolean stop = false;
		
	@Override
	public void setParent(SpaceInvader parent) 
	{
		this.parent = parent;
	}

	@Override
	public SpaceInvader getParent() 
	{
		return parent;
	}
		
	@Override
	public void draw(GLAutoDrawable drawable) 
	{
		GL gl = drawable.getGL();
		
		gl.glColor3d(.3, .4, .7);
		gl.glLoadIdentity();
		gl.glTranslated(ttx, 0, 0);
		gl.glRectd(.05, -.89, -.05, -.98);
		
		gl.glColor3d(.5,.7 , .5);
		gl.glLoadIdentity();
		gl.glTranslated(ttx, 0, 0);
		gl.glBegin(GL.GL_TRIANGLES);
			gl.glVertex3d(0.025, -0.89, 0);
    		gl.glVertex3d(-0.025, -0.89,0);
    		gl.glVertex3d(tx,-0.75,0);
    	gl.glEnd();	
    }

	@Override
	public void handleEvent(KeyEvent ke) 
	{
		if(ke.getKeyCode() == KeyEvent.VK_ESCAPE)
			System.exit(0);
		if(ke.getKeyCode() == KeyEvent.VK_UP)
		{
			if(tx<.2)
			{
				tx += .01;
				dx += .0025;
			}
		}
		if(ke.getKeyCode() == KeyEvent.VK_DOWN)
		{
			if(tx>-.2)
			{	
				tx -= .01;
				dx -= .0025;
			}
		}
		if(ke.getKeyCode() == KeyEvent.VK_RIGHT)
		{
			if(ttx<.7)
			{
				ttx += .01;
			}
		}
		if(ke.getKeyCode() == KeyEvent.VK_LEFT)
		{
			if(ttx>-.7)
			{	
				ttx -= .01;
			}
		}
		if(ke.getKeyCode() == KeyEvent.VK_SPACE)
		{
			Missiles m = new Missiles(tx+ttx,ty,dx);
			m.setParent(parent);
			m.start();
			try 
			{
				Thread.sleep(40);
			}
			catch (InterruptedException e) 
			{
				e.printStackTrace();
			}
			parent.addObject(m);
		}
	}
	
	public boolean isShooterHit(Bullets b)
	{
		if((b.tx >= tx+ttx-0.09 &&b.tx <= tx+ttx+0.09) && (b.ty >= ty-0.01 &&b.ty <= ty+0.01))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	public void stopThread()
	{
		stop = true;
	}
}
