package com.cu.jogl;

import java.awt.Point;
import java.awt.event.KeyEvent;

import javax.media.opengl.GLAutoDrawable;

public interface BGObject 
{	
	public void setParent(BaloonGame b);
	public BaloonGame getParent();
	public void draw(GLAutoDrawable drawable);
	public void handleEvent(KeyEvent ke);
}
