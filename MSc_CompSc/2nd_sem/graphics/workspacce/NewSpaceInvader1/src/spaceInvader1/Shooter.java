package spaceInvader1;

import java.awt.Point;
import java.awt.event.KeyEvent;

import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;

public class Shooter extends Thread implements SpaceObjects 
{
	SpaceInvader parent = null;
	public
	Point position;
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
		gl.glRectd(.05, -.89, -.05, -.98);
		
		gl.glColor3d(.5,.7 , .5);
		gl.glLoadIdentity();
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
		if(ke.getKeyCode() == KeyEvent.VK_RIGHT)
		{
			if(tx<.2)
			{
				tx += .01;
				dx += .0025;
			}
		}
		else if(ke.getKeyCode() == KeyEvent.VK_LEFT)
		{
			if(tx>-.2)
			{	tx -= .01;
				dx -= .0025;
			}
		}
		else if(ke.getKeyCode() == KeyEvent.VK_SPACE)
		{
			Missiles m = new Missiles(tx,ty,dx);
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
	
	public boolean isShooterHit(UFOS u)
	{
		if((u.tx >= tx-0.08 &&u.tx <= tx+0.08) && (u.ty >= ty-0.01 &&u.ty <= ty+0.01))
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
