package spaceInvader2;

import java.awt.Point;
import java.awt.event.KeyEvent;

import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;

public class Bullets extends Thread implements SpaceObjects
{
	SpaceInvader parent = null;
	Point position;
	double tx=0;
	double ty=0;

	public Bullets(double tx,double ty) 
	{
		super();
		this.tx = tx;
		this.ty = ty;
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
		gl.glColor3d(.5, .5, .5);
		gl.glLoadIdentity();
		gl.glTranslated(tx, ty, 0);
		gl.glEnable(GL.GL_POINT_SMOOTH);
		gl.glPointSize(5);
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
			if(ty<-1)
			{
				parent.removeObject(this);
				break;				
			}
			ty -= .02;
			try 
			{
				Thread.sleep(100);
			}
			catch (Exception e) 
			{
			}
		}
	}
}
