package spaceInvader2;

import java.awt.BorderLayout;
import java.awt.Frame;
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


public class SpaceInvader extends JFrame implements KeyListener, GLEventListener
{
	private static final long serialVersionUID = 1L;
	private Vector<SpaceObjects> objectSet = new Vector<SpaceObjects>();
	private Vector<SpaceObjects> listenerSet = new Vector<SpaceObjects>();
	private JTextField hCntTxt = new JTextField(5);
	private JTextField cCntTxt = new JTextField(5);
	private JButton startBtn = new JButton("Play");
	private boolean gameStopped = true;
	private RandomGen randomGen = null;
	private int reset = 0;
	public int speed = 10;
	private int speedIncr = 0;
	public int flag = 0;
		
	public SpaceInvader()
	{
	}

	public static void main(String[] args) 
	{
		final SpaceInvader frame = new SpaceInvader();
	
		frame.setTitle("Space Invader");
		frame.setSize(800,600);
		frame.setExtendedState(Frame.MAXIMIZED_BOTH);
		frame.setDefaultCloseOperation(EXIT_ON_CLOSE);
	
		JPanel msgPanel = new JPanel();
		msgPanel.add(new JLabel("Life"));
		msgPanel.add(frame.cCntTxt);
		frame.cCntTxt.setEditable(false);
		frame.cCntTxt.setText("30");
		msgPanel.add(new JLabel("Score"));
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
				frame.cCntTxt.setText("30");
				frame.hCntTxt.setText("0");
				frame.randomGen = frame.getRandomGen();
				frame.randomGen.start();
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

	protected RandomGen getRandomGen() 
	{		
		return new RandomGen(this);
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
					SpaceObjects o = objectSet.get(i);
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
			for (SpaceObjects object : objectSet) 
			{
				if(object instanceof Missiles)
				{
					for (SpaceObjects object1 : objectSet) 
					{
						if((object1 instanceof UFOS1) &&  ((UFOS1)object1).isHitted((Missiles)object))
						{
							((UFOS1)object1).stopThread();
						}
					}
				}
				object.draw(drawable);				
			}
			for (SpaceObjects object : objectSet) 
			{
				if(object instanceof Missiles)
				{
					for (SpaceObjects object1 : objectSet) 
					{
						if((object1 instanceof UFOS2) &&  ((UFOS2)object1).isHitted((Missiles)object))
						{
							((UFOS2)object1).stopThread();
						}
					}
				}
			}
			if(flag == 0)
			{
				for (SpaceObjects object : objectSet) 
				{
					if(object instanceof Shooter)
					{
						for (SpaceObjects object1 : objectSet) 
						{
							if((object1 instanceof Bullets) &&  ((Shooter)object).isShooterHit((Bullets)object1))
							{
								decrementLife();
								flag=1;
							}
						}
					}
				}
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
		Shooter shooter = new Shooter();
		shooter.setParent(this);	    		
		objectSet.add(shooter);
		listenerSet.add(shooter);
		Stars stars= new Stars();
		stars.setParent(this);	    		
		objectSet.add(stars);
	}
	
	@Override
	public void reshape(GLAutoDrawable drawable, int x, int y, int width,int height) 
	{
		
	}

	public void addObject(SpaceObjects o)
	{
			synchronized (this) 
			{	
				objectSet.add(o);
			}		
	}
	
	public void removeObject(SpaceObjects o)
	{
		synchronized (this) 
		{
			objectSet.remove(o);
		}
		
	}
	
/*	public void addListener(BGObject o)
	{
		synchronized (this) 
		{
			listenerSet.add(o);
		}
	}*/
	
	public void stopGame()
	{
		randomGen.stopThread();
		gameStopped = true;
		startBtn.setEnabled(true);
	}
	
	public void incrementHitCount()
	{
		try
		{
			hCntTxt.setText(String.valueOf(Integer.parseInt(hCntTxt.getText())+1));
		}
		catch (Exception e)
		{			
		}
		reset += 1;
		speedIncr += 1;
		if(reset > 15)
		{
			if(Integer.parseInt(cCntTxt.getText()) < 28)
			{	cCntTxt.setText(String.valueOf(Integer.parseInt(cCntTxt.getText())+2));
				reset=0;
			}
		}
		if(speedIncr > 15)
		{
			if(speed > 10)
			{
				speed -= 10;
				speedIncr = 0;
			}
			else if(speed >= 4)
			{
				speed -= 3;
				speedIncr = 0;
			}
		}
	}
	
	public void decrementLife()
	{
		cCntTxt.setText(String.valueOf(Integer.parseInt(cCntTxt.getText())-1));
	}
	
	public int getLife()
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

