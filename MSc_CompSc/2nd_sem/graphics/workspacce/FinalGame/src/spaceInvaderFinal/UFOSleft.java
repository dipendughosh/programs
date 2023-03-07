/*Class to create the 'UFOS' from the left in 'game 2'*/
package spaceInvaderFinal;

import java.awt.event.KeyEvent;
import javax.media.opengl.*;
/*import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;*/
import javax.sound.sampled.LineUnavailableException;

public class UFOSleft extends Thread implements SpaceObjects 
{
	/*Declares local variables for drawing the 'UFOS',for their scaling,
	 *for their translation and their speed*/
	SpaceInvader parent = null;
	boolean stop = false;
	double tx = -1;
	double ty = 0;
	double cx,cy,cz;
	double dx,dy,dz;
	long speed;
	double sx = .4;
	double sy = .4;
	double sz = .4;
	double DEG2RAD = 3.14285714/180; 
	
	/*Initializing the local variables for 
	 *displaying and removing the object from the screen*/
	public UFOSleft(double ty) 
	{
		super();
		this.ty = ty;
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
		speed = (long)(40 * Math.random() + 10);
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
	 *Update the translation factor.Fire 'Bullets' on the 'Shooter' when the
	 *'UFO' is on top of the 'Shooter'*/
	@Override
	public void run() 
	{
		while(true)
		{
			if(tx > 1 || stop)
			{
				parent.removeObject(this);
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
					/*Increment score if a 'UFO' is hit by a 'Missile*/
					if(parent.flag != 1)
						parent.incrementHitCount();
				}
				break;
			}
			/*Updating the translation factor*/
			tx += .02;
			try 
			{
				Thread.sleep(speed*parent.speed);
			}
			catch (InterruptedException e) 
			{
				e.printStackTrace();
			}
			/*Firing 'Bullets' if the 'UFO' is in the hitting range of the 'Shooter'*/
			if(parent.shooterPos > tx-.1 && parent.shooterPos < tx+.1)
			{
				/*Creates a 'Bullet' type object and adds it on the canvas*/
				Bullets b = new Bullets(tx,ty);
				b.setParent(parent);
				b.start();
				parent.addObject(b);
				try 
				{
					Thread.sleep(1000);
				}
				catch (InterruptedException e) 
				{
					e.printStackTrace();
				}
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
