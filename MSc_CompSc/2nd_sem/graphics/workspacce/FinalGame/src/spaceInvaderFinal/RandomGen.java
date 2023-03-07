/*Class to generate 'Random' numbers and generate 'UFOS' randomly*/
package spaceInvaderFinal;

import spaceInvaderFinal.SpaceInvader;
import spaceInvaderFinal.UFOSup;

public class RandomGen extends Thread 
{
	/*Declare local variables*/
	SpaceInvader parent = null;
	Boolean stopState = false;
	
	/*Initialize variables*/
	public RandomGen(SpaceInvader parent) 
	{
		super();
		this.parent = parent;
	}

	/*Execute the function to create the 'UFOS'*/
	public void run()
	{
		/*For 'game 1' generate 'UFOS' on both left and right halves of the screen*/
		if(parent.r == 0)
		{
			while(true)
			{
				if(stopState)
				{
					break;
				}
				try
				{
					Thread.sleep((long)(Math.random()*1000));
				} 
				catch (InterruptedException e) 
				{				
					e.printStackTrace();
				}
				/*Create 'UFO' for the left half*/
				double pos1 = -1 + Math.random();
				UFOSup u = new UFOSup(pos1);
				u.setParent(parent);
				parent.flag=0;
				parent.addObject(u);
				u.start();
				try
				{
					Thread.sleep(1500);	
				} 
				catch (InterruptedException e) 
				{
					e.printStackTrace();
				}
				
				/*Create 'UFO' for the right half*/
				double pos2 = Math.random();
				UFOSup c = new UFOSup(pos2);
				c.setParent(parent);
				parent.flag=0;
				parent.addObject(c);
				c.start();
				try
				{
					Thread.sleep(1500);
				} 
				catch (InterruptedException e) 
				{	
					e.printStackTrace();
				}
			}
		}
		/*For 'game 2' generate 'UFOS' from both left and right sides of the screen*/
		if(parent.r == 1)
		{
			while(true)
			{
				if(stopState)
				{
					break;
				}
				try
				{
					Thread.sleep((long)(Math.random()*1500));
				} 
				catch (InterruptedException e) 
				{				
					e.printStackTrace();
				}
				/*Create 'UFO' from the left side*/
				double pos3 = Math.random()-.1;
				UFOSleft u1 = new UFOSleft(pos3);
				u1.setParent(parent);
				parent.flag=0;
				parent.addObject(u1);
				u1.start();
				try
				{
					Thread.sleep(1500);
				} 
				catch (InterruptedException e) 
				{
					e.printStackTrace();
				}
				/*Create 'UFO' from the right side*/
				double pos4 = Math.random()-.1;
				UFOSright u2 = new UFOSright(pos4);
				u2.setParent(parent);
				parent.flag=0;
				parent.addObject(u2);
				u2.start();
				try
				{
					Thread.sleep(1500);
				} 
				catch (InterruptedException e) 
				{
					e.printStackTrace();
				}
				if(parent.getLife() <= 1)
				{
					if(parent.getLife()==1)
						parent.decrementLife(0);
					parent.stopGame();
				}	
			}
		}
	}
	
	/*Stop or kill the thread*/
	public void stopThread()
	{
		stopState = true;
	}
}
