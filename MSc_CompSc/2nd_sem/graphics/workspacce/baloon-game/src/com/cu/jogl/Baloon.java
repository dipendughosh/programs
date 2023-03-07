package com.cu.jogl;

import java.awt.event.KeyEvent;

import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.sound.sampled.LineUnavailableException;

public class Baloon extends Thread implements BGObject 
{

	boolean stop = false;
	
	BaloonGame parent = null;
	
	double tx = 0;
	
	double ty = .9;
	
	double cx,cy,cz;
	long speed;
	
	public BaloonGame getParent() 
	{
		return parent;
	}

	public Baloon(double tx) 
	{
		super();
		this.tx = tx;
		cx = Math.random();
		if(cx==0)cx=.1;
			cy = Math.random();
		if(cy==0)
			cy=.1;
		cz = Math.random();
		if(cz==0)
			cz=.1;
		speed = (long)(40 * Math.random() + 10);
	}

	@Override
	public void draw(GLAutoDrawable drawable) 
	{
		GL gl = drawable.getGL();
		gl.glColor3d(cx, cy, cz);
		gl.glLoadIdentity();
		gl.glTranslated(tx, ty, 0);
		
		//ty -= .02;
		
		gl.glBegin(GL.GL_POLYGON);
		    double y =0;
		    //gl.glVertex2d(-.05, 0);
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
	public void run() 
	{
		while(true)
		{
			if(ty < -.9 || stop)
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
					parent.incrementHitCount();
				}
				break;
			}
			ty -= .02;
			try 
			{
				Thread.sleep(speed);
			}
			catch (InterruptedException e) 
			{
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

	@Override
	public void handleEvent(KeyEvent ke) 
	{
		

	}

	@Override
	public void setParent(BaloonGame b) 
	{		
		this.parent = b;
	}

	public boolean isHitted(Cartoose c)
	{
		if((c.tx>=tx-0.05 &&c.tx<=tx+0.05) && (c.ty>=ty-0.05 &&c.ty<=ty+0.05))
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
