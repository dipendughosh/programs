/*Class to create 'Missiles'*/
package spaceInvaderFinal;

import java.awt.Point;
import java.awt.event.KeyEvent;
import javax.media.opengl.*;
/*import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;*/

public class Missiles extends Thread implements SpaceObjects
{
	/*Declares local variables for drawing the 'Bullets'
	 *and for their translation*/
	SpaceInvader parent = null;
	Point position;
	boolean stop = false;
	double tx=0;
	double dx=0;
	double ty=0;
	double DEG2RAD = 3.14285714/180;

	/*Initializing the local variables for 
	 *displaying and removing the object from the screen*/
	public Missiles(double tx,double ty,double dx) 
	{
		super();
		this.tx = tx;
		this.ty = ty;
		this.dx = dx;
	}
	
	/*Function to set the parent of the object*/
	@Override
	public void setParent(SpaceInvader s) 
	{		
		this.parent = s;
	}
	
	/*Function to return the parent of the object*/
	@Override
	public SpaceInvader getParent() 
	{
		return parent;
	}

	/*Function to draw the objects on the screen*/
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

	/*Function to incorporate key responses to control the objects*/
	@Override
	public void handleEvent(KeyEvent ke) 
	{
	}
	
	/*Function which is used to remove the 'Missile' if it passes
	 *out without hitting or by hitting the 'UFOS' 
	 *Update the translation factor.*/
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
			/*Updating the translation factor*/
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
	
	/*Stop or kill the thread*/
	public void stopThread()
	{
		stop = true;
	}
}
