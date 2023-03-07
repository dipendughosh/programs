/*Class to display the background effect on the screen*/
package spaceInvaderFinal;

import java.awt.event.KeyEvent;
import javax.media.opengl.*;
/*import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;*/

public class Stars extends Thread implements SpaceObjects
{

	private double x,y;
	
	/*Function to draw the objects on the screen*/
	@Override
	public void draw(GLAutoDrawable drawable)
	{
		GL gl = drawable.getGL();
		
		/*For co-ordinate 1*/
		gl.glColor3d(1, 1, 1);
		gl.glLoadIdentity();
		x=Math.random();
		y=Math.random();
		gl.glEnable(GL.GL_POINT_SMOOTH);
		gl.glPointSize(2);
		gl.glBegin(GL.GL_POINTS);		    
			gl.glVertex2d(x, y);			
		gl.glEnd();
		try 
		{
			Thread.sleep(10);
		} 
		catch (InterruptedException e) 
		{
			e.printStackTrace();
		}
		
		/*For co-ordinate 2*/
		gl.glColor3d(1, 1, 1);
		gl.glLoadIdentity();
		x=Math.random();
		y=-1*Math.random();
		gl.glEnable(GL.GL_POINT_SMOOTH);
		gl.glPointSize(2);
		gl.glBegin(GL.GL_POINTS);		    
			gl.glVertex2d(x, y);			
		gl.glEnd();
		try 
		{
			Thread.sleep(10);
		} 
		catch (InterruptedException e) 
		{
			e.printStackTrace();
		}
		
		/*For co-ordinate 3*/
		gl.glColor3d(1, 1, 1);
		gl.glLoadIdentity();
		x=-1*Math.random();
		y=Math.random();
		gl.glEnable(GL.GL_POINT_SMOOTH);
		gl.glPointSize(2);
		gl.glBegin(GL.GL_POINTS);		    
			gl.glVertex2d(x, y);			
		gl.glEnd();
		try 
		{
			Thread.sleep(10);
		} 
		catch (InterruptedException e) 
		{
			e.printStackTrace();
		}

		/*For co-ordinate 4*/
		gl.glColor3d(1, 1, 1);
		gl.glLoadIdentity();
		x=-1*Math.random();
		y=-1*Math.random();
		gl.glEnable(GL.GL_POINT_SMOOTH);
		gl.glPointSize(2);
		gl.glBegin(GL.GL_POINTS);		    
			gl.glVertex2d(x, y);			
		gl.glEnd();
		try 
		{
			Thread.sleep(10);
		} 
		catch (InterruptedException e) 
		{
			e.printStackTrace();
		}
	}
	
	/*Function to return the parent of the object*/
	@Override
	public SpaceInvader getParent()
	{
		return null;
	}

	/*Function to incorporate key responses to control the objects*/
	@Override
	public void handleEvent(KeyEvent ke)
	{
	}

	/*Function to set the parent of the object*/
	@Override
	public void setParent(SpaceInvader s)
	{
	}
}
