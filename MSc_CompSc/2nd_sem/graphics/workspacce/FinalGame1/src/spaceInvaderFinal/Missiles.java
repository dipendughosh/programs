package spaceInvaderFinal;

import java.awt.Point;
import java.awt.event.KeyEvent;

import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;

public class Missiles extends Thread implements SpaceObjects
{
	SpaceInvader parent = null;
	Point position;
	boolean stop = false;
	double tx=0;
	double dx=0;
	double ty=0;
	double DEG2RAD = 3.14285714/180;

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
		gl.glLoadIdentity();
		gl.glTranslated(tx, ty,0);
		gl.glColor3d(1, 1, 1);
		gl.glBegin(GL.GL_POLYGON);
			gl.glVertex3d(0, -0.02, 0);
			gl.glVertex3d(0.007,-0.045,0);
			gl.glVertex3d(-.007,-0.045,0);
		gl.glEnd();
		gl.glColor3d(.35,.6 , .35);
		gl.glBegin(GL.GL_POLYGON);
		for (double i=0; i <= 360; i=i+0.01)
		{
			double degInRad = i*DEG2RAD;
			gl.glVertex3d(Math.cos(degInRad)*0.008,Math.sin(degInRad)*0.026,0);
		}
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
			if(ty>1 || stop)
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
	
	public void stopThread()
	{
		stop = true;
	}
}
