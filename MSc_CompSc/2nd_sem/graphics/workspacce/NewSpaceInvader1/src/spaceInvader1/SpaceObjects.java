package spaceInvader1;

import java.awt.event.KeyEvent;

import javax.media.opengl.GLAutoDrawable;

public interface SpaceObjects 
{
	public void setParent(SpaceInvader s);
	public SpaceInvader getParent();
	public void draw(GLAutoDrawable drawable);
	public void handleEvent(KeyEvent ke);
}
