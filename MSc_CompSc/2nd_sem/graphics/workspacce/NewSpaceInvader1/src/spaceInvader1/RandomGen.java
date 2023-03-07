package spaceInvader1;

import spaceInvader1.SpaceInvader;
import spaceInvader1.UFOS;


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
			UFOS u = new UFOS(pos);
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
			UFOS c = new UFOS(pos);
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
	
	public void stopThread()
	{
		stopState = true;
	}
}
