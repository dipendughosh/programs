package com.cu.jogl;

import java.awt.BorderLayout;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.Vector;
import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.media.opengl.GLCanvas;
import javax.media.opengl.GLEventListener;
import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.SourceDataLine;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import com.sun.opengl.util.Animator;

public class BaloonGame extends JFrame implements KeyListener, GLEventListener
{


	private Vector<BGObject> objectSet = new Vector<BGObject>();
	private Vector<BGObject> listenerSet = new Vector<BGObject>();
	private JTextField hCntTxt = new JTextField(5);
	private JTextField cCntTxt = new JTextField(5);
	private JButton startBtn = new JButton("Start");
	private boolean gameStopped = true;
	private Randomise randomiser = null;

	public static void main(String[] args) 
	{
		final BaloonGame frame = new BaloonGame();
		
		frame.setTitle("Baloon...");
		frame.setSize(450,450);
		frame.setDefaultCloseOperation(EXIT_ON_CLOSE);
		
		JPanel msgPanel = new JPanel();
		msgPanel.add(new JLabel("Cartoose Remaining"));
		msgPanel.add(frame.cCntTxt);
		frame.cCntTxt.setEditable(false);
		frame.cCntTxt.setText("50");
		msgPanel.add(new JLabel("Hit Count"));
		msgPanel.add(frame.hCntTxt);
		frame.hCntTxt.setEditable(false);
		frame.hCntTxt.setText("0");
		msgPanel.add(frame.startBtn);
				
		frame.startBtn.addKeyListener(frame);
		
		frame.startBtn.addMouseListener(new MouseAdapter()
		{			
			@Override
			public void mouseClicked(MouseEvent arg0) 
			{
				frame.gameStopped = false;
				frame.startBtn.setEnabled(false);
				frame.cCntTxt.setText("50");
				frame.hCntTxt.setText("0");
				frame.randomiser = frame.getRandomiser();
				frame.randomiser.start();
			}
		});
		frame.add(msgPanel,BorderLayout.NORTH);
		
		GLCanvas canvas = new GLCanvas();
		frame.add(canvas,BorderLayout.CENTER);
						
		canvas.addGLEventListener(frame);

		canvas.addKeyListener(frame);
		msgPanel.addKeyListener(frame);
		frame.addKeyListener(frame);
		
		Animator animator = new Animator(canvas);
		animator.start();
		
		frame.setVisible(true);				
	}

	protected Randomise getRandomiser() 
	{		
		return new Randomise(this);
	}

	@Override
	public void keyPressed(KeyEvent ke) 
	{
		if(!gameStopped)
		{
			synchronized (this) 
			{
				for (int i = 0; i < objectSet.size(); i++) 
				{
					BGObject o = objectSet.get(i);
					o.handleEvent(ke);
				}
			}
		}
	}

	@Override
	public void keyReleased(KeyEvent arg0) 
	{		
	}

	@Override
	public void keyTyped(KeyEvent ke) 
	{
	}

	@Override
	public void display(GLAutoDrawable drawable) 
	{	
		GL gl = drawable.getGL();
		gl.glClear(GL.GL_COLOR_BUFFER_BIT);
		synchronized (this) 
		{
			for (BGObject object : objectSet) 
			{
				if(object instanceof Cartoose)
				{
					for (BGObject object1 : objectSet) 
					{
						if((object1 instanceof Baloon) &&  ((Baloon)object1).isHitted((Cartoose)object))
						{
							((Baloon)object1).stopThread();
						}
					}
				}
				object.draw(drawable);				
			}
		}		
	}


	@Override
	public void displayChanged(GLAutoDrawable drawable, boolean modeChanged,boolean deviceChanged) 
	{		
	}

	@Override
	public void init(GLAutoDrawable drawable) 
	{
		Rifel rifel = new Rifel();
	    rifel.setParent(this);	    		
		objectSet.add(rifel);
		listenerSet.add(rifel);
	}

	@Override
	public void reshape(GLAutoDrawable drawable, int x, int y, int width,int height) 
	{
		
	}

	public void addObject(BGObject o)
	{
			synchronized (this) 
			{
				objectSet.add(o);
			}		
	}
	
	public void removeObject(BGObject o)
	{
		synchronized (this) 
		{
			objectSet.remove(o);
		}
	
	}
	
	public void addListener(BGObject o)
	{
		synchronized (this) 
		{
			listenerSet.add(o);
		}
	}
	
	public void stopGame()
	{
		randomiser.stopThread();
		gameStopped = true;
		startBtn.setEnabled(true);		
	}
	
	public void incrementHitCount()
	{
		hCntTxt.setText(String.valueOf(Integer.parseInt(hCntTxt.getText())+1));
	}
	
	public void decrementCartooseCount()
	{
		cCntTxt.setText(String.valueOf(Integer.parseInt(cCntTxt.getText())-1));
	}
	
	public int getCartooseCount()
	{
		return Integer.parseInt(cCntTxt.getText());
	}
	
	public void generateTone(int hz,int msecs, int volume, boolean addHarmonic)throws LineUnavailableException 
	{
	 
	    float frequency = 44100;
	    byte[] buf;
	    AudioFormat af;
	    if (addHarmonic) 
	    {
	      buf = new byte[2];
	      af = new AudioFormat(frequency,8,2,true,false);
	    }
	    else 
	    {
	      buf = new byte[1];
	      af = new AudioFormat(frequency,8,1,true,false);
	    }
	    SourceDataLine sdl = AudioSystem.getSourceDataLine(af);
	    sdl = AudioSystem.getSourceDataLine(af);
	    sdl.open(af);
	    sdl.start();
	    for(int i=0; i<msecs*frequency/1000; i++)
	    {
	      double angle = i/(frequency/hz)*2.0*Math.PI;
	      buf[0]=(byte)(Math.sin(angle)*volume);
	 
	      if(addHarmonic) 
	      {
	        double angle2 = (i)/(frequency/hz)*2.0*Math.PI;
	        buf[1]=(byte)(Math.sin(2*angle2)*volume*0.6);
	        sdl.write(buf,0,2);
	      }
	      else 
	      {
	        sdl.write(buf,0,1);
	      }
	    }
	    sdl.drain();
	    sdl.stop();
	    sdl.close();
	}
	
}
