package spaceInvader2;

import java.awt.event.KeyEvent;

import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.sound.sampled.LineUnavailableException;

public class UFOS2 extends Thread implements SpaceObjects 
{
	SpaceInvader parent = null;
	boolean stop = false;
	double tx = 1;
	double ty = 0;
	double cx,cy,cz;
	long speed;
	double sx = .8;
	double sy = .8;
	double sz = .8;
	
	
	public UFOS2(double ty) 
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
			double y1 =0;
			for(double x1= -.04;x1<=.05; x1 = x1 + 0.01)
			{
				y1 = Math.abs(Math.sqrt((.05*.05) - (x1*x1)));
				gl.glVertex2d(x1, -y1);
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
			if(tx < -1 || stop)
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
					if(parent.flag != 1)
						parent.incrementHitCount();
				}
				break;
			}
			tx -= .02;
			try 
			{
				Thread.sleep(speed*parent.speed);
			}
			catch (InterruptedException e) 
			{
				e.printStackTrace();
			}
			if(tx<-.05 || tx>.05)
			{
				if((int)(tx*9)%4 == 0 )
				{
					Bullets b = new Bullets(tx,ty);
					b.setParent(parent);
					b.start();
					parent.addObject(b);
				}
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
