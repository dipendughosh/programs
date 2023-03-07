package spaceInvaderFinal;

import spaceInvaderFinal.SpaceInvader;
import spaceInvaderFinal.UFOSup;


public class RandomGen extends Thread 
{

	SpaceInvader parent = null;
	Boolean stopState = false;
	
	public RandomGen(SpaceInvader parent) 
	{
		super();
		this.parent = parent;
	}

	public void run()
	{
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
				double pos = -1 + Math.random();
				UFOSup u = new UFOSup(pos);
				u.setParent(parent);
				parent.flag=0;
				parent.addObject(u);
				u.start();
				try
				{
					Thread.sleep(250);
				} 
				catch (InterruptedException e) 
				{
					e.printStackTrace();
				}
				pos = Math.random();
				UFOSup c = new UFOSup(pos);
				c.setParent(parent);
				parent.addObject(c);
				c.start();
				try
				{
					Thread.sleep(250);
				} 
				catch (InterruptedException e) 
				{	
					e.printStackTrace();
				}
			}
		}
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
				double pos1 = Math.random()-.1;
				UFOSleft u1 = new UFOSleft(pos1);
				u1.setParent(parent);
				parent.flag=0;
				parent.addObject(u1);
				u1.start();
				try
				{
					Thread.sleep(500);
				} 
				catch (InterruptedException e) 
				{
					e.printStackTrace();
				}
				double pos2 = Math.random()-.1;
				UFOSright u2 = new UFOSright(pos2);
				u2.setParent(parent);
				parent.flag=0;
				parent.addObject(u2);
				u2.start();
				try
				{
					Thread.sleep(500);
				} 
				catch (InterruptedException e) 
				{
					e.printStackTrace();
				}
				if(parent.getLife() <= 1)
				{
					if(parent.getLife()==1)
					{
						parent.decrementLife(0);
					}
					parent.stopGame();
				}	
			}
		}
	}
	
	public void stopThread()
	{
		stopState = true;
	}
}
