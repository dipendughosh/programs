/*Class to create the 'Shooter' and display it in the screen*/
package spaceInvaderFinal;

import java.awt.Point;
import java.awt.event.KeyEvent;
import javax.media.opengl.*;
/*import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;*/

public class Shooter extends Thread implements SpaceObjects 
{
	/*Declares local variables for drawing the 'Shooter',
	 *for its translation and position*/
	SpaceInvader parent = null;
	public
	Point position;
	double ttx=0;
	double tx=0;
	double dx=0;
	double ty=-.75;
	double rx = 0;
	boolean stop = false;
	double rotationAngle=0;
	double tyaxis=0.01;
		
	/*Function to set the parent of the object*/
	@Override
	public void setParent(SpaceInvader parent) 
	{
		this.parent = parent;
	}

	/*Function to return the parent of the object*/
	@Override
	public SpaceInvader getParent() 
	{
		return parent;
	}
		
	/*Function to draw the objects on the screen*/
	@Override
	public void draw(GLAutoDrawable drawable) 
	{
		if(parent.r == 0)
		{
			GL gl = drawable.getGL();
		
			/* 	Creation Of the shooter object Graphical Design For Game 1 */
			
			/* Gun */	
				gl.glLoadIdentity();
				gl.glEnable(GL.GL_SMOOTH);
				gl.glBegin(GL.GL_POLYGON);
					gl.glColor3d(.5,.7 , .5);
					gl.glEnable(GL.GL_SMOOTH);
					gl.glVertex3d(tx+0.004,-0.76, 0);
					gl.glEnable(GL.GL_SMOOTH);
					gl.glVertex3d(0.004, -0.79, 0);
					gl.glEnable(GL.GL_SMOOTH);
		    		gl.glVertex3d(-0.004, -0.79,0);
		    		gl.glEnable(GL.GL_SMOOTH);
		    		gl.glVertex3d(tx+(-0.004),-0.76,0);
		    	gl.glEnd();
						
				/* LEFT Side wing */	
				gl.glColor3d(.8, .1, .1);
				gl.glLoadIdentity();
				gl.glRotated(rotationAngle, 0, 0, 0);
				gl.glBegin(GL.GL_POLYGON);
					gl.glVertex3d(-.03, -0.88, 0);
					gl.glVertex3d(-.05, -0.88, 0);
					gl.glVertex3d(-.05, -0.83, 0);
					gl.glVertex3d(-.045, -0.83, 0);
					gl.glVertex3d(-.045, -0.86, 0);
					gl.glVertex3d(-.015, -0.86, 0);
				gl.glEnd();
			
			/* RIGHT Side wing */
				gl.glColor3d(.8, .1, .1);
				gl.glLoadIdentity();
				gl.glRotated(rotationAngle, 0, 0, 0);
				gl.glBegin(GL.GL_POLYGON);
					gl.glVertex3d(.03, -0.88, 0);
					gl.glVertex3d(.05, -0.88, 0);
					gl.glVertex3d(.05, -0.83, 0);
					gl.glVertex3d(.045, -0.83, 0);
					gl.glVertex3d(.045, -0.86, 0);
					gl.glVertex3d(.015, -0.86, 0);
				gl.glEnd();
				
			/*Shooter BODY */	
				gl.glColor3d(.9, .9, .9);
				gl.glLoadIdentity();
				gl.glRotated(rotationAngle, 0, 0, 0);
				gl.glBegin(GL.GL_POLYGON);
					gl.glVertex3d(0, -0.78, 0);
					gl.glVertex3d(0.03, -0.881,0); //Base of the ship triangle
					gl.glVertex3d(-.03,-0.881,0);  //Base of the ship triangle	
				gl.glEnd();
				
			/* FUEL Boosters */	
				gl.glColor3d(.9, .9, .9);
				gl.glLoadIdentity();
				gl.glRotated(rotationAngle, 0, 0, 0);
				gl.glRectd(.03, -.881, .019, -.90);
				gl.glRectd(-.03, -.881, -.019, -.90);
			
			/*RIGHT Fuel Burn Flames */
				gl.glColor3d(.9,.35,.0);
				gl.glLoadIdentity();
				gl.glRotated(rotationAngle, 0, 0, 0);
				gl.glBegin(GL.GL_POLYGON);				
					gl.glVertex3d(.03, -0.90, 0);
					gl.glVertex3d(.025, -0.94, 0);
					gl.glVertex3d(.019, -0.90, 0);
				gl.glEnd();
				
			/*LEFT Fuel Burn Flames */
				gl.glColor3d(.9,.35,.0);
				gl.glLoadIdentity();
				gl.glRotated(rotationAngle, 0, 0, 0);
				gl.glBegin(GL.GL_POLYGON);				
					gl.glVertex3d(-.03, -0.90, 0);
					gl.glVertex3d(-.025, -0.94, 0);
					gl.glVertex3d(-.019, -0.90, 0);
				gl.glEnd();
		}
		
		if(parent.r == 1)
		{
			GL gl = drawable.getGL();
			
			/* 	Creation Of the shooter object Graphical Design For Game 2 */
			
			/* Gun */	
				gl.glLoadIdentity();
				gl.glTranslated(ttx, 0, 0);
				gl.glEnable(GL.GL_SMOOTH);
				gl.glBegin(GL.GL_POLYGON);
					gl.glColor3d(.5,.7 , .5);
					gl.glEnable(GL.GL_SMOOTH);
					gl.glVertex3d(tx+0.004,-0.76, 0);
					gl.glEnable(GL.GL_SMOOTH);
					gl.glVertex3d(0.004, -0.79, 0);
					gl.glEnable(GL.GL_SMOOTH);
		    		gl.glVertex3d(-0.004, -0.79,0);
		    		gl.glEnable(GL.GL_SMOOTH);
		    		gl.glVertex3d(tx+(-0.004),-0.76,0);
				gl.glEnd();
			
				/* LEFT Side wing */	
				gl.glColor3d(.8, .1, .1);
				gl.glLoadIdentity();
				gl.glTranslated(ttx, 0, 0);
				gl.glBegin(GL.GL_POLYGON);
					gl.glVertex3d(-.03, -0.88, 0);
					gl.glVertex3d(-.05, -0.88, 0);
					gl.glVertex3d(-.05, -0.83, 0);
					gl.glVertex3d(-.045, -0.83, 0);
					gl.glVertex3d(-.045, -0.86, 0);
					gl.glVertex3d(-.015, -0.86, 0);
				gl.glEnd();
			
			/* RIGHT Side wing */
				gl.glColor3d(.8, .1, .1);
				gl.glLoadIdentity();
				gl.glTranslated(ttx, 0, 0);
				gl.glBegin(GL.GL_POLYGON);
					gl.glVertex3d(.03, -0.88, 0);
					gl.glVertex3d(.05, -0.88, 0);
					gl.glVertex3d(.05, -0.83, 0);
					gl.glVertex3d(.045, -0.83, 0);
					gl.glVertex3d(.045, -0.86, 0);
					gl.glVertex3d(.015, -0.86, 0);
				gl.glEnd();
				
			/*Shooter BODY */	
				if(parent.shield==1)
				{
					gl.glColor3d(0, 1, 1);
				}
				else
				{
					gl.glColor3d(.9, .9, .9);
				}
				gl.glLoadIdentity();
				gl.glTranslated(ttx, 0, 0);
				gl.glBegin(GL.GL_POLYGON);
					gl.glVertex3d(0, -0.78, 0);
					gl.glVertex3d(0.03, -0.881,0); //Base of the ship triangle
					gl.glVertex3d(-.03,-0.881,0);  //Base of the ship triangle	
				gl.glEnd();
				
			/* FUEL Boosters */	
				gl.glColor3d(.9, .9, .9);
				gl.glLoadIdentity();
				gl.glTranslated(ttx, 0, 0);
				gl.glRectd(.03, -.881, .019, -.90);
				gl.glRectd(-.03, -.881, -.019, -.90);
			
			/*RIGHT Fuel Burn Flames */
				gl.glColor3d(.9,.35,.0);
				gl.glLoadIdentity();
				gl.glTranslated(ttx, 0, 0);
				gl.glBegin(GL.GL_POLYGON);				
					gl.glVertex3d(.03, -0.90, 0);
					gl.glVertex3d(.025, -0.94, 0);
					gl.glVertex3d(.019, -0.90, 0);
				gl.glEnd();
				
			/*LEFT Fuel Burn Flames */
				gl.glColor3d(.9,.35,.0);
				gl.glLoadIdentity();
				gl.glTranslated(ttx, 0, 0);
				gl.glBegin(GL.GL_POLYGON);				
					gl.glVertex3d(-.03, -0.90, 0);
					gl.glVertex3d(-.025, -0.94, 0);
					gl.glVertex3d(-.019, -0.90, 0);
				gl.glEnd();	
		}
    }

	/*Function to incorporate key responses to control the objects*/
	@Override
	public void handleEvent(KeyEvent ke) 
	{
		if(ke.getKeyCode() == KeyEvent.VK_ESCAPE)
			System.exit(0);
		if(parent.r ==0 )
		{	
			/*Translate to the right*/
			if(ke.getKeyCode() == KeyEvent.VK_RIGHT)
			{
				if(tx<.2)
				{
					tx += .01;
					dx += .0025;
					tyaxis += .01;
					rotationAngle+=1;
				}
			}
			/*Translate to the left*/
			if(ke.getKeyCode() == KeyEvent.VK_LEFT)
			{
				if(tx>-.2)
				{	tx -= .01;
					dx -= .0025;
					rotationAngle-=1;
				}
			}
			/*Fire missiles*/
			if(ke.getKeyCode() == KeyEvent.VK_SPACE)
			{
				Missiles m = new Missiles(tx,ty,dx);
				m.setParent(parent);
				m.start();
				try 
				{
					Thread.sleep(40);
				}
				catch (InterruptedException e) 
				{
					e.printStackTrace();
				}
				parent.addObject(m);
			}
		}
		
		if(parent.r == 1)
		{	/*Rotate the nozle to the right fire in a particular direction*/
			if(ke.getKeyCode() == KeyEvent.VK_UP)
			{
				if(tx<.2)
				{
					tx += .01;
					dx += .0025;
				}
			}
			/*Rotate the nozle to the left fire in a particular direction*/
			if(ke.getKeyCode() == KeyEvent.VK_DOWN)
			{
				if(tx>-.2)
				{	
					tx -= .01;
					dx -= .0025;
					tyaxis += .01;
				}
			}
			/*Translate to the right*/
			if(ke.getKeyCode() == KeyEvent.VK_RIGHT)
			{
				if(ttx<.8)
				{
					ttx += .01;
				}
			}
			/*Translate to the left*/
			if(ke.getKeyCode() == KeyEvent.VK_LEFT)
			{
				if(ttx>-.8)
				{	
					ttx -= .01;
				}
			}
			/*Fire missiles*/
			if(ke.getKeyCode() == KeyEvent.VK_SPACE)
			{
				Missiles m = new Missiles(tx+ttx,ty,dx);
				m.setParent(parent);
				m.start();
				try 
				{
					Thread.sleep(40);
				}
				catch (InterruptedException e) 
				{
					e.printStackTrace();
				}
				parent.addObject(m);
			}
			parent.shooterPos=ttx;
		}
	}
	
	/*Function to check if the 'Shooter' is hit by a 'UFO' or not*/
	public boolean isShooterHit(UFOSup u)
	{
		if((u.tx >= tx+ttx-0.05 &&u.tx <= tx-ttx+0.05) && (u.ty >= ty-0.01 &&u.ty <= ty+0.01))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	/*Function to check if the 'Shooter' is hit by a 'Bullet' or not*/
	public boolean isShooterHit(Bullets b)
	{
		if((b.tx >= tx+ttx-0.1 &&b.tx <= tx+ttx+0.1) && (b.ty >= ty-0.01 &&b.ty <= ty+0.01))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	/*Stop or kill the thread*/
	public void stopThread()
	{
		stop = true;
	}
}
