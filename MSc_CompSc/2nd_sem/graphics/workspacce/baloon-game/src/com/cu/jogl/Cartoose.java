package com.cu.jogl;

import java.awt.Point;
import java.awt.event.KeyEvent;

import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;

public class Cartoose extends Thread implements BGObject
{
	Point position;
	double tx=-.7;
	double ty=0;
	
    BaloonGame parent = null;
	
	public BaloonGame getParent() 
	{
		return parent;
	}


	public Cartoose(double ty) 
	{
		super();
		this.ty = ty;
	}

	@Override
	public void draw(GLAutoDrawable drawable) 
	{
		GL gl = drawable.getGL();
		gl.glColor3d(1, 0, 0);
		gl.glLoadIdentity();
		gl.glTranslated(tx, ty, 0);
		gl.glEnable(GL.GL_POINT_SMOOTH);
		gl.glPointSize(8);
		gl.glBegin(GL.GL_POINTS);		    
			gl.glVertex2d(0, 0);			
		gl.glEnd();
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
	
	public void run()
	{
		while(true)
		{
			if(tx>.9)
			{
				parent.removeObject(this);
				break;				
			}
			tx += .02;
			try 
			{
				Thread.sleep(20);
			}
			catch (Exception e) 
			{
				
			}
		}
	}

}
