/*Interface for the objects which are to be displayed on the screen*/
package spaceInvaderFinal;

import java.awt.event.KeyEvent;

import javax.media.opengl.GLAutoDrawable;

public interface SpaceObjects 
{
	/*Function to set the parent of the object*/
	public void setParent(SpaceInvader s);
	/*Function to return the parent of the object*/
	public SpaceInvader getParent();
	/*Function to draw the objects on the screen*/
	public void draw(GLAutoDrawable drawable);
	/*Function to incorporate key responses to control the objects*/
	public void handleEvent(KeyEvent ke);
}