/*Class to create the 'UFOS' from the top in 'game 1'*/
package spaceInvaderFinal;

import java.awt.event.KeyEvent;
import javax.media.opengl.*;
/*import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;*/
import javax.sound.sampled.LineUnavailableException;

public class UFOSup extends Thread implements SpaceObjects 
{
	/*Declares local variables for drawing the 'UFOS',for their scaling,
	 *for their translation and their speed*/
	SpaceInvader parent = null;
	boolean stop = false;
	double tx = 0;
	double ty = 1;
	double cx,cy,cz;
	double dx,dy,dz;
	long speed;
	double sx = .25;
	double sy = .25;
	double sz = .25;
	double DEG2RAD = 3.14285714/180;
	
	/*Initializing the local variables for 
	 *displaying and removing the object from the screen*/
	public  UFOSup(double tx) 
	{
		super();
		this.tx = tx;
		cx = Math.random();
		if(cx==0)
			cx=.1;
		cy = Math.random();
		if(cy==0)
			cy=.1;
		cz = Math.random();
		if(cz==0)
			cz=.1;
		dx = Math.random();
		if(dx==0)
			dx=.1;
		dy = Math.random();
		if(dy==0)
			dy=.1;
		dz = Math.random();
		if(dz==0)
			dz=.1;
		speed = (long)(60 * Math.random() + 20);
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
		cx = Math.random();
		if(cx==0)
			cx=.1;
		cy = Math.random();
		if(cy==0)
			cy=.1;
		cz = Math.random();
		if(cz==0)
			cz=.1;
		dx = Math.random();
		if(dx==0)
			dx=.1;
		dy = Math.random();
		if(dy==0)
			dy=.1;
		dz = Math.random();
		if(dz==0)
			dz=.1;
		
		GL gl = drawable.getGL();

		
		gl.glLoadIdentity();
		gl.glTranslated(tx, ty, 0);
		gl.glScaled(sx, sy, sz);
		gl.glColor3d(cx, cy, cz);
		gl.glBegin(GL.GL_POLYGON);
			for (double i=0; i <= 180; i=i+0.1)
		    {
		       double degInRad = i*DEG2RAD;
		       gl.glVertex3d(Math.cos(degInRad)*0.05,Math.sin(degInRad)*0.04,0);
		    }
		gl.glEnd();
		gl.glColor3d(dx, dy, dz);
		gl.glBegin(GL.GL_POLYGON);	
			for (double i=180; i <= 360; i=i+0.1)
		    {
		       double degInRad = i*DEG2RAD;
		       gl.glVertex3d(Math.cos(degInRad)*0.1,Math.sin(degInRad)*0.05,0);
		    }
		gl.glEnd();
	}
	
	/*Function to incorporate key responses to control the objects*/
	@Override
	public void handleEvent(KeyEvent ke) 
	{
	}
	
	/*Function which is used to remove the 'UFO' if it is hit by a 'Missile'.
	 *Update the translation and scaling factor.*/
	@Override
	public void run() 
	{
		while(true)
		{
			if(ty < -1 || stop)
			{
				parent.removeObject(this);
				if(parent.getLife() == 0)
				{
					parent.stopGame();
				}			
				/*Decrement life if a 'UFO' passes unharmed till the end and survives*/
				if(ty < -1)
					parent.decrementLife(2);
				if(stop)
				{
					try 
					{
						parent.generateTone(500, 100, 60, true);
					}
					catch (LineUnavailableException e) 
					{						
						e.printStackTrace();
					}
					/*Increment score if a 'UFO' is hit*/
					if(parent.flag != 1)
						parent.incrementHitCount();
				}
				break;
			}
			/*Updating the translation and scaling factors of the 'UFOS'*/
			ty -= .02;
			sx += .005;
			sy += .005;
			sz += .005;
			try 
			{
				Thread.sleep(speed*parent.speed);
			}
			catch (InterruptedException e) 
			{
				e.printStackTrace();
			}
		}
	}

	/*Function to check if the 'UFO' has been hit by a 'Missile'*/
	public boolean isHitted(Missiles m)
	{
		if((m.tx>=tx-0.04 &&m.tx<=tx+0.04) && (m.ty>=ty-0.04 &&m.ty<=ty+0.04))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	/*Stop or kill the thread*/
	public void stopThread()
	{
		stop = true;
	}
}
