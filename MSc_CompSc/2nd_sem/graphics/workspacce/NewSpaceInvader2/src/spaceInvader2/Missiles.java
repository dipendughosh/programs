package spaceInvader2;

import java.awt.Point;
import java.awt.event.KeyEvent;

import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;

public class Missiles extends Thread implements SpaceObjects
{
	SpaceInvader parent = null;
	Point position;
	double tx=0;
	double dx=0;
	double ty=0;

	public Missiles(double tx,double ty,double dx) 
	{
		super();
		this.tx = tx;
		this.ty = ty;
		this.dx = dx;
	}
	
	@Override
	public void setParent(SpaceInvader s) 
	{		
		this.parent = s;
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
		gl.glColor3d(1, 0, 0);
		gl.glLoadIdentity();
		gl.glTranslated(tx, ty, 0);
		gl.glEnable(GL.GL_POINT_SMOOTH);
		gl.glPointSize(8);
		gl.glBegin(GL.GL_POINTS);		    
			gl.glVertex2d(0, 0);			
		gl.glEnd();
	}

	@Override
	public void handleEvent(KeyEvent ke) 
	{
	}
	
	@Override
	public void run()
	{
		while(true)
		{
			if(ty>.9)
			{
				parent.removeObject(this);
				break;				
			}
			ty += .02;
			tx += dx;
			try 
			{
				if(tx > -.15 && tx < .15)
					Thread.sleep(20);
				else
					Thread.sleep(50);
			}
			catch (Exception e) 
			{
			}
		}
	}
}
