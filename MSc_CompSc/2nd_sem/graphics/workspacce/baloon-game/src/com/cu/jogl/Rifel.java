package com.cu.jogl;

import java.awt.Point;
import java.awt.event.KeyEvent;

import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;

public class Rifel extends Thread implements BGObject
{
	
	private int cCnt = 50;
	
	BaloonGame parent = null;
	
	public BaloonGame getParent() 
	{
		return parent;
	}

	public void setParent(BaloonGame parent) 
	{
		this.parent = parent;
	}

	Point position;
	double ty=0;
	
	@Override
	public void draw(GLAutoDrawable drawable) 
	{
		GL gl = drawable.getGL();
		gl.glColor3d(0, 1, 0);
		gl.glLoadIdentity();
		gl.glTranslated(-.85, ty, 0);
		
		gl.glBegin(GL.GL_POLYGON);		    
			gl.glVertex2d(-.05, .05);			
			gl.glVertex2d(.1, .05);			
			gl.glVertex2d(.1, 0);
			gl.glVertex2d(.01, 0);
			gl.glVertex2d(-.01, -.05);
			gl.glVertex2d(-.1, -.05);
			//gl.glVertex2d(-.1, 0.02);
		gl.glEnd();
	}

	@Override
	public void handleEvent(KeyEvent ke) 
	{
		if(ke.getKeyCode() == KeyEvent.VK_UP)
		{
			if(ty<.9)
				ty += .02;
		}
		else if(ke.getKeyCode() == KeyEvent.VK_DOWN)
		{
			if(ty>-.9)
				ty -= .02;
		}
		else if(ke.getKeyCode() == KeyEvent.VK_SPACE)
		{
			parent.decrementCartooseCount();
			if(parent.getCartooseCount() == 0)
			{
				parent.stopGame();
			}			
			Cartoose c = new Cartoose(ty);
			c.setParent(parent);
			c.start();
			parent.addObject(c);
		}
	}

}
