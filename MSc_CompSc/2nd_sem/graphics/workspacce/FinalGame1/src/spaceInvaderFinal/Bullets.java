package spaceInvaderFinal;

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
	float toggle=0;
	double DEG2RAD = 3.14285714/180;

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
		if(toggle==0)
			toggle=1;
		else
			toggle=0;
		gl.glColor3d(toggle,1,1);
		gl.glLoadIdentity();
		gl.glTranslated(tx, ty, 0);
		gl.glBegin(GL.GL_POLYGON);
			for (double i=0; i <= 360; i=i+0.01)
			{
				double degInRad = i*DEG2RAD;
				gl.glVertex3d(Math.cos(degInRad)*0.0030,Math.sin(degInRad)*0.028,0);
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
			if(ty<-1)
			{
				parent.removeObject(this);
				break;				
			}
			ty -= .1;
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
