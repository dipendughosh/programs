package spaceInvaderFinal;

import java.awt.event.KeyEvent;

import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;

public class Stars extends Thread implements SpaceObjects
{

	private double x,y;
	@Override
	public void draw(GLAutoDrawable drawable)
	{
		GL gl = drawable.getGL();
		
		gl.glColor3d(1, 1, 1);
		gl.glLoadIdentity();
		x=Math.random();
		y=Math.random();
		gl.glEnable(GL.GL_POINT_SMOOTH);
		gl.glPointSize(2);
		gl.glBegin(GL.GL_POINTS);		    
			gl.glVertex2d(x, y);			
		gl.glEnd();
		try 
		{
			Thread.sleep(10);
		} 
		catch (InterruptedException e) 
		{
			e.printStackTrace();
		}
		
		gl.glColor3d(1, 1, 1);
		gl.glLoadIdentity();
		x=Math.random();
		y=-1*Math.random();
		gl.glEnable(GL.GL_POINT_SMOOTH);
		gl.glPointSize(2);
		gl.glBegin(GL.GL_POINTS);		    
			gl.glVertex2d(x, y);			
		gl.glEnd();
		try 
		{
			Thread.sleep(10);
		} 
		catch (InterruptedException e) 
		{
			e.printStackTrace();
		}
		
		gl.glColor3d(1, 1, 1);
		gl.glLoadIdentity();
		x=-1*Math.random();
		y=Math.random();
		gl.glEnable(GL.GL_POINT_SMOOTH);
		gl.glPointSize(2);
		gl.glBegin(GL.GL_POINTS);		    
			gl.glVertex2d(x, y);			
		gl.glEnd();
		try 
		{
			Thread.sleep(10);
		} 
		catch (InterruptedException e) 
		{
			e.printStackTrace();
		}

		gl.glColor3d(1, 1, 1);
		gl.glLoadIdentity();
		x=-1*Math.random();
		y=-1*Math.random();
		gl.glEnable(GL.GL_POINT_SMOOTH);
		gl.glPointSize(2);
		gl.glBegin(GL.GL_POINTS);		    
			gl.glVertex2d(x, y);			
		gl.glEnd();
		try 
		{
			Thread.sleep(10);
		} 
		catch (InterruptedException e) 
		{
			e.printStackTrace();
		}
	}

	@Override
	public SpaceInvader getParent()
	{
		return null;
	}

	@Override
	public void handleEvent(KeyEvent ke)
	{
	}

	@Override
	public void setParent(SpaceInvader s)
	{
	}
}
