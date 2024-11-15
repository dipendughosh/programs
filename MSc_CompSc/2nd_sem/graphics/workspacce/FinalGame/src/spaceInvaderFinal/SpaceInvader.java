/*Main class which defines the frame,canvas,displays the panel
 *and calls all other classes to display the other components on the screen*/
package spaceInvaderFinal;

import java.awt.BorderLayout;
import java.awt.Frame;
import java.awt.event.*;
import javax.media.opengl.*;
import javax.sound.sampled.*;
import javax.swing.*;
import java.util.Vector;
/*import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;*/
/*import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.media.opengl.GLCanvas;
import javax.media.opengl.GLEventListener;*/
/*import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.SourceDataLine;*/
/*import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;*/

import com.sun.opengl.util.Animator;

/*Main class which extends JFrame and implements KeyListener, GLEventListener*/
public class SpaceInvader extends JFrame implements KeyListener, GLEventListener
{
	private static final long serialVersionUID = 1L;
	/*Creates vectors of 'SpaceObjects' type to store the screen 
	 *objects present at a particular point of time*/
	private Vector<SpaceObjects> objectSet = new Vector<SpaceObjects>();
	
	/*Creates text areas to display score of the player and life of the shooter*/
	private JTextField score = new JTextField(5);
	private JTextField life = new JTextField(5);
	/*Creates the start button which starts the game*/
	private JButton startBtn = new JButton("Play");
	/*Variable to indicate if the game is being played or game over*/
	private boolean gameStopped = true;
	/*Creates a random object of class 'RandomGen' which is used to 
	 *display the 'UFOS' randomly on the screen*/
	private RandomGen randomGen = null;
	/*Counts the number of 'UFOS' hit before increasing the 
	 *score of the player with the bonus points*/
	private int reset = 0;
	/*Varies the speed with which the 'UFOS' are attacking*/
	public int speed = 20;
	/*Counts the number of 'UFOS' hit before increasing the 
	 *speed of the 'UFOS's arrival*/
	private int speedIncr = 0;
	/*Used to indicate if the shooter has been hit by an
	 *UFO of 'game 1' or by the bullets from the UFOS of 'game 2'*/
	public int flag = 0;
	/*Stores the game which the user chose to play*/
	public static int result = 0;
	/*Stores the game which the user chose to play 
	 *to be accessed by the other classed*/
	public int r = 0;
	/*Indicates when the game is to be stopped*/
	public int stopGame = 0;
	/*Finds the position of the shooter*/
	public double shooterPos = 0;
	/*Giving extra life to the 'Shooter' for 'game 2'*/
	public int shield=0;
	public int shieldOnHit=0;
	
	/*Default constructor*/
	public SpaceInvader()
	{
	}

	/*Main function from which the full game is executed*/
	public static void main(String[] args) 
	{
		/*Displays a 'JOptionPane' for the user to chose the game he wants to play*/
		result = JOptionPane.showOptionDialog(null, "Game1 or Game2?","Space Invader v1.0", JOptionPane.YES_NO_CANCEL_OPTION,JOptionPane.QUESTION_MESSAGE, null, new String[] { "Game 1","Game 2" }, null);
		/*Closes the game if the user chooses the default close button of the 'JOptionPane'*/
		if(result == -1)
		{
			System.exit(0);
		}
		
		/*Creates a frame of 'SpaceInvader' type on which all the 
		 *displaying will be done and the game will be played*/ 
		final SpaceInvader frame = new SpaceInvader();
	
		/*Sets the title,size and the default close option of the frame*/
		frame.setTitle("Space Invader");
		frame.setExtendedState(Frame.MAXIMIZED_BOTH);
		frame.setDefaultCloseOperation(EXIT_ON_CLOSE);
		
		/*Adds a 'Jpanel' on which the score,life and the play button
		 *will be displayed.Displays the names of the fields,
		 *sets the properties of the text areas and gives the default values*/
		JPanel msgPanel = new JPanel();
		msgPanel.add(new JLabel("Life"));
		msgPanel.add(frame.life);
		frame.life.setEditable(false);
		if(result == 0)
		{
			frame.life.setText("25");
		}
		if(result == 1)
		{
			frame.life.setText("20");
		}
		msgPanel.add(new JLabel("Score"));
		msgPanel.add(frame.score);
		frame.score.setEditable(false);
		frame.score.setText("0");
		msgPanel.add(frame.startBtn);
			
		/*Adds the 'KeyListener' class controls on the frame*/
		frame.startBtn.addKeyListener(frame);
		
		/*Adds the 'MouseListener' class controls on the play button*/
		frame.startBtn.addMouseListener(new MouseAdapter()
		{			
			/*Defines what will be done when the play button is clicked*/
			@Override
			public void mouseClicked(MouseEvent arg0) 
			{
				frame.gameStopped = false;
				frame.startBtn.setEnabled(false);
				if(result == 0)
				{
					frame.life.setText("25");
				}
				if(result == 1)
				{
					frame.life.setText("20");
				}
				frame.randomGen = frame.getRandomGen();
				frame.randomGen.start();
				frame.score.setText("0");
			}
		});
		frame.add(msgPanel,BorderLayout.NORTH);
		
		/*Adds a canvas on the frame on which the objects are to drawn using 'JOGL'*/
		GLCanvas canvas = new GLCanvas();
		frame.add(canvas,BorderLayout.CENTER);
		
		/*Adds the 'GLEventListener' class controls on the frame*/
		canvas.addGLEventListener(frame);
		canvas.addKeyListener(frame);
		msgPanel.addKeyListener(frame);
		frame.addKeyListener(frame);

		/*Makes the canvas capable of animating the objects drawn on the screen*/
		Animator animator = new Animator(canvas);
		animator.start();
	
		frame.setVisible(true);		
	}

	/*Function to draw the objects on the canvas created*/
	protected RandomGen getRandomGen() 
	{		
		/*Returns an object of 'RandomGen' class onto the given frame to draw the objects*/
		return new RandomGen(this);
	}

	/*Functions used to control the 'Shooter' and its shooting and 
	 *the movement of the shooter's nozle*/
	@Override
	public void keyPressed(KeyEvent ke) 
	{
		/*If 'game 1' is chosen the the objects present on the
		 *screen are extracted one by one and their key handlers are called*/
		if(result == 0)
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
		/*If 'game 2' is chosen the the objects present on the
		 *screen are extracted one by one and their key handlers are called*/
		if(result == 1)
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
	}
	
	@Override
	public void keyReleased(KeyEvent arg0) 
	{		
	}

	@Override
	public void keyTyped(KeyEvent ke) 
	{
	}

	/*Displays all the objects to be displayed 
	 *on the screen by calling their respective 'draw' functions*/
	@Override
	public void display(GLAutoDrawable drawable) 
	{	
		/*For 'game 1'*/
		if(result == 0)
		{	
			GL gl = drawable.getGL();
			gl.glClear(GL.GL_COLOR_BUFFER_BIT);
			/*Checks if any of the 'Missiles' launched by the 'Shooter' has 
			 *hit any of the 'UFOS'.If hit is ensured then the 'UFO' and the
			 *'Missile' is erased from the canvas and score is increased*/
			synchronized (this) 
			{
				for (SpaceObjects object1 : objectSet) 
				{
					if(object1 instanceof Missiles)
					{
						for (SpaceObjects object2 : objectSet) 
						{
							if((object2 instanceof UFOSup) &&  ((UFOSup)object2).isHitted((Missiles)object1))
							{
								((UFOSup)object2).stopThread();
								((Missiles)object1).stopThread();
							}
						}
					}
					/*Calls the draw function of all the class*/
					object1.draw(drawable);				
				}
				/*Checks if any of the 'UFOS' has hit the 'Shooter' or not. 
				 *If yes,then the life of the 'Shooter' is decreased*/
				if(flag == 0)
				{
					for (SpaceObjects object1 : objectSet) 
					{
						if(object1 instanceof Shooter)
						{
							for (SpaceObjects object2 : objectSet) 
							{
								if((object2 instanceof UFOSup) &&  ((Shooter)object1).isShooterHit((UFOSup)object2))
								{
									((UFOSup)object2).stopThread();
									decrementLife(1);
									flag=1;
								}
							}
						}
					}
				}
			}
		}
		/*For 'game 2'*/
		if(result == 1)
		{
			GL gl = drawable.getGL();
			gl.glClear(GL.GL_COLOR_BUFFER_BIT);
			/*Checks if any of the 'Missiles' launched by the 'Shooter' has 
			 *hit any of the 'UFOS' from the left.If hit is ensured then the 'UFO' and the
			 *'Missile' is erased from the canvas and score is increased*/
			synchronized (this) 
			{
				for (SpaceObjects object : objectSet) 
				{
					if(object instanceof Missiles)
					{
						for (SpaceObjects object1 : objectSet) 
						{
							if((object1 instanceof UFOSleft) &&  ((UFOSleft)object1).isHitted((Missiles)object))
							{
								((UFOSleft)object1).stopThread();
								((Missiles)object).stopThread();
							}
						}
					}
					object.draw(drawable);				
				}
				/*Checks if any of the 'Missiles' launched by the 'Shooter' has 
				 *hit any of the 'UFOS' from the right.If hit is ensured then the 'UFO' and the
				 *'Missile' is erased from the canvas and score is increased*/
				for (SpaceObjects object : objectSet) 
				{
					if(object instanceof Missiles)
					{
						for (SpaceObjects object1 : objectSet) 
						{
							if((object1 instanceof UFOSright) &&  ((UFOSright)object1).isHitted((Missiles)object))
							{
								((UFOSright)object1).stopThread();
								((Missiles)object).stopThread();
							}
						}
					}
				}
				/*Checks if any of the 'UFOS's 'Bullets' have hit the 'Shooter' or not. 
				 *If yes,then the life of the 'Shooter' is decreased*/
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
									decrementLife(0);
									flag=1;
								}
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

	/*Called automatically as the program is executed*/
	@Override
	public void init(GLAutoDrawable drawable) 
	{
		/*Displays the 'Shooter' on the screen and the background effect of the screen*/
		r=result;
		Shooter shooter = new Shooter();
		shooter.setParent(this);	    		
		objectSet.add(shooter);
		Stars stars= new Stars();
		stars.setParent(this);	    		
		objectSet.add(stars);
	}
	
	@Override
	public void reshape(GLAutoDrawable drawable, int x, int y, int width,int height) 
	{
	}
	
	/*Function to add objects on the screen*/
	public void addObject(SpaceObjects o)
	{
		synchronized (this) 
		{	
			objectSet.add(o);
		}		
	}
	
	/*Function to remove objects from the screen*/
	public void removeObject(SpaceObjects o)
	{
		synchronized (this) 
		{
			objectSet.remove(o);
		}
	}
	
	/*Function to stop the game and enable the 'Play' button once again 
	 *for retry.Also it provides a choice for the user to 'Play Again' or to 'Exit'*/
	public void stopGame()
	{
			
		randomGen.stopThread();
		gameStopped = true;
		startBtn.setEnabled(true);

		if(stopGame == 0)
		{
			stopGame = 1;
			result = JOptionPane.showOptionDialog(null, "Game Over!!!Score ::-"+score.getText(),"Message", JOptionPane.YES_NO_CANCEL_OPTION,JOptionPane.QUESTION_MESSAGE, null, new String[] { "OK","EXIT" }, 5);
			if(result == 1)
			{
				System.exit(0);
			}
			if(result == -1)
			{
				System.exit(0);
			}
		}
	}
	
	/*Function to increment the score when an 'UFO' is hit 
	 *and give the bonus point when 15 'UFOS' have been hit simultaneously*/
	public void incrementHitCount()
	{
		/*Increment score and display in the score area*/
		try
		{
			score.setText(String.valueOf(Integer.parseInt(score.getText())+1));
		}
		catch (Exception e)
		{			
		}
		/*Increment the counters for giving bonus point and increase speed*/
		reset += 1;
		speedIncr += 1;
		if(reset > 15)
		{
			try
			{
				/*For 'game 1' increase life by 3*/
				if(Integer.parseInt(life.getText()) < 22 && result == 0)
				{	life.setText(String.valueOf(Integer.parseInt(life.getText())+3));
					reset=0;
				}
				/*For 'game 2' increase life by 2*/
				shield=1;
				if(Integer.parseInt(life.getText()) < 18 && result == 1)
				{	life.setText(String.valueOf(Integer.parseInt(life.getText())+2));
					reset=0;
				}
			}
			catch (Exception e)
			{
			}
		}
		/*Increase the speed of 'UFO' travel*/
		if(speedIncr > 15)
		{
			if(speed > 10)
			{
				speed -= 10;
				speedIncr = 0;
			}
		}
	}
	
	/*Decrement Life when the 'UFOS' are not hit by the 'Shooter's 'Misssiles'
	 *or when the 'Shooter' is hit
	 *by 'UFOS' or when the 'Shooter' is hit by 'Bullets' from the 'UFOS'*/
	public void decrementLife(int f)
	{
		if(result == 0)
		{
			/*'Shooter' hit by 'UFOS'*/
			if(Integer.parseInt(life.getText()) > 0 && f==1)
			{
				life.setText(String.valueOf(Integer.parseInt(life.getText())-5));
				if(Integer.parseInt(life.getText()) < 0)
					life.setText("0");
			}
			/*'UFOS' which have not been destroyed and passes unharmed*/
			else if(Integer.parseInt(life.getText()) > 0 && f == 2)
			{
				life.setText(String.valueOf(Integer.parseInt(life.getText())-1));
				if(Integer.parseInt(life.getText()) < 0)
					life.setText("0");
			}
		}
		/*'Shooter' hit by 'Bullets'*/
		if(result == 1)
		{
			if(shield==1 && shieldOnHit<=5)
			{	
				shieldOnHit++;
			}
			else
			{
				shield=0;
				shieldOnHit=0;
				
				life.setText(String.valueOf(Integer.parseInt(life.getText())-1));
				if(Integer.parseInt(life.getText()) < 0)
				life.setText("0");
			}
		}
	}
	
	/*To return the lives left of the 'Shooter'*/
	public int getLife()
	{
		int x = 0;
		try
		{
			x = Integer.parseInt(life.getText());
		}
		catch (Exception e)
		{
		}
		return x;
	}
	
	/*Generate tones at different occasions*/
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