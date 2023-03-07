package spaceInvader2;

import spaceInvader2.SpaceInvader;
import spaceInvader2.UFOS1;
import spaceInvader2.UFOS2;


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
				Thread.sleep((long)(Math.random()*1500));
			} 
			catch (InterruptedException e) 
			{				
				e.printStackTrace();
			}
			double pos1 = Math.random()-.1;
			UFOS1 u1 = new UFOS1(pos1);
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
			UFOS2 u2 = new UFOS2(pos2);
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
			if(parent.getLife() < 1)
			{
				parent.stopGame();
			}	
		}
	}
	
	public void stopThread()
	{
		stopState = true;
	}
}
