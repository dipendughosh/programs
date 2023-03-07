package spaceInvaderFinal;


import java.awt.event.KeyEvent;

import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.sound.sampled.LineUnavailableException;

public class UFOSup extends Thread implements SpaceObjects 
{
	SpaceInvader parent = null;
	boolean stop = false;
	double tx = 0;
	double ty = 1;
	double cx,cy,cz;
	long speed;
	double sx = .25;
	double sy = .25;
	double sz = .25;
	double DEG2RAD = 3.14285714/180;
	
	
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
		speed = (long)(60 * Math.random() + 20);
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

		gl.glColor3d(cx, cy, cz);
		gl.glLoadIdentity();
		gl.glTranslated(tx, ty, 0);
		gl.glScaled(sx, sy, sz);
		gl.glBegin(GL.GL_POLYGON);
		double y =0;
			for (double i=0; i <= 180; i=i+0.1)
		    {
		       double degInRad = i*DEG2RAD;
		       gl.glVertex3d(Math.cos(degInRad)*0.05,Math.sin(degInRad)*0.04,0);
		    }
		gl.glEnd();
		gl.glBegin(GL.GL_POLYGON);	
			for (double i=180; i <= 360; i=i+0.1)
		    {
		       double degInRad = i*DEG2RAD;
		       gl.glVertex3d(Math.cos(degInRad)*0.1,Math.sin(degInRad)*0.05,0);
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
			if(ty < -1 || stop)
			{
				parent.removeObject(this);
				if(parent.getLife() == 0)
				{
					parent.stopGame();
				}			
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
					if(parent.flag != 1)
						parent.incrementHitCount();
				}
				break;
			}
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
	
	public void stopThread()
	{
		stop = true;
	}
}
