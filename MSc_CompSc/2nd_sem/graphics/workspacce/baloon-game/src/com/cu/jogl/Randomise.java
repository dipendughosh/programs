package com.cu.jogl;

import java.util.Random;

public class Randomise extends Thread 
{

	BaloonGame parent = null;
	
	Boolean stopState = false;
	
	public Randomise(BaloonGame parent) 
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
			double pos = Math.random();
			Baloon b = new Baloon(pos);
			b.setParent(parent);
			parent.addObject(b);
			b.start();
		}
	}
	
	public void stopThread()
	{
		stopState = true;
	}
}
