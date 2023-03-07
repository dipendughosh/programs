/*Class to create 'Bullets' for 'game 2'*/
package spaceInvaderFinal;

import java.awt.Point;
import java.awt.event.KeyEvent;
import javax.media.opengl.*;
/*import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;*/

public class Bullets extends Thread implements SpaceObjects
{
	/*Declares local variables for drawing the 'Bullets'
	 *and for their translation*/
	SpaceInvader parent = null;
	Point position;
	double tx=0;
	double ty=0;
	float toggle=0;
	double DEG2RAD = 3.14285714/180;

	/*Initializing the local variables for 
	 *displaying and removing the object from the screen*/
	public Bullets(double tx,double ty) 
	{
		super();
		this.tx = tx;
		this.ty = ty;
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

	/*Function to incorporate key responses to control the objects*/
	@Override
	public void handleEvent(KeyEvent ke) 
	{
	}
	
	/*Function which is used to remove the 'Bullet' if it passes
	 *out without hitting or by hitting the 'Shooter 
	 *Update the translation factor.*/
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
			/*Updating the translation factor*/
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
	
	/*Stop or kill the thread*/
	public void stopThread()
	{
		stop = true;
	}
}
