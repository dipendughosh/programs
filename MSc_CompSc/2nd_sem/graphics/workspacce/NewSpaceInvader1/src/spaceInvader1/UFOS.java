package spaceInvader1;


import java.awt.event.KeyEvent;

import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.sound.sampled.LineUnavailableException;

public class UFOS extends Thread implements SpaceObjects 
{
	SpaceInvader parent = null;
	boolean stop = false;
	double tx = 0;
	double ty = 1;
	double cx,cy,cz;
	long speed;
	double sx = .2;
	double sy = .2;
	double sz = .2;
	
	
	public  UFOS(double tx) 
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
		speed = (long)(50 * Math.random() + 10);
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
			for(double x= -.04;x<=.05; x = x + 0.01)
			{
				y = Math.abs(Math.sqrt((.05*.05) - (x*x)));
				gl.glVertex2d(x, -y);
			}
			gl.glVertex2d(0.05, 0);
			gl.glVertex2d(0, .15);
			gl.glVertex2d(-.05, 0);
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
			sx += .0055;
			sy += .0055;
			sz += .0055;
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
		if((m.tx>=tx-0.05 &&m.tx<=tx+0.05) && (m.ty>=ty-0.05 &&m.ty<=ty+0.05))
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
