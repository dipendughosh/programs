package package1;

import java.awt.Canvas;
import java.awt.event.KeyEvent;
import java.util.ArrayList;

import javax.swing.JOptionPane;

public class Game extends Canvas implements GameWindowCallback 
{
	private ArrayList entities = new ArrayList();
	private ArrayList removeList = new ArrayList();
	private Entity ship;
	private double moveSpeed = 300;
	private long lastFire = 0;
	private long firingInterval = 500;
	private int alienCount;

	private Sprite message;
	private boolean waitingForKeyPress = true;
	private boolean logicRequiredThisLoop = false;

	private long lastLoopTime = System.currentTimeMillis();
	private GameWindow window;
	private boolean fireHasBeenReleased = false;

	private Sprite pressAnyKey;
	private Sprite youWin;
	private Sprite gotYou;

	private long lastFpsTime = 0;
	private int fps;

	private String windowTitle = "Space Invaders 103 - Version (0.3)";

	public Game(int renderingType) 
	{
		ResourceFactory.get().setRenderingType(renderingType);
		window = ResourceFactory.get().getGameWindow();

		window.setResolution(800, 600);
		window.setGameWindowCallback(this);
		window.setTitle(windowTitle);
	}

	public void startRendering() 
	{
		window.startRendering();
	}

	public void initialise() 
	{
		gotYou = ResourceFactory.get().getSprite("sprites/gotyou.gif");
		pressAnyKey = ResourceFactory.get().getSprite("sprites/pressanykey.gif");
		youWin = ResourceFactory.get().getSprite("sprites/youwin.gif");

		message = pressAnyKey;

		startGame();
	}

	private void startGame() 
	{
		entities.clear();
		initEntities();
	}

	private void initEntities() 
	{
		ship = new Entity.ShipEntity(this, "sprites/ship.gif", 370, 550);
		entities.add(ship);

		alienCount = 0;
		for (int row = 0; row < 5; row++) 
		{
			for (int x = 0; x < 12; x++) 
			{
				Entity alien = new Entity.AlienEntity(this, 100 + (x * 50),(50) + row * 30);
				entities.add(alien);
				alienCount++;
			}
		}
	}

	public void updateLogic() 
	{
		logicRequiredThisLoop = true;
	}

	public void removeEntity(Entity entity) 
	{
		removeList.add(entity);
	}

	public void notifyDeath() 
	{
		message = gotYou;
		waitingForKeyPress = true;
	}

	public void notifyWin() 
	{
		message = youWin;
		waitingForKeyPress = true;
	}

	public void notifyAlienKilled() 
	{
		alienCount--;

		if (alienCount == 0) 
		{
			notifyWin();
		}

		for (int i = 0; i < entities.size(); i++) 
		{
			Entity entity = (Entity) entities.get(i);

			if (entity instanceof Entity.AlienEntity) 
			{
				entity.setHorizontalMovement(entity.getHorizontalMovement() * 1.02);
			}
		}
	}

	public void tryToFire() 
	{
		if (System.currentTimeMillis() - lastFire < firingInterval) 
		{
			return;
		}

		lastFire = System.currentTimeMillis();
		Entity.ShotEntity shot = new Entity.ShotEntity(this, "sprites/shot.gif",ship.getX() + 10, ship.getY() - 30);
		entities.add(shot);
	}

	public void frameRendering() 
	{
		try 
		{
			Thread.sleep(10);
		}
		catch (Exception e)
		{
		}
		long delta = System.currentTimeMillis() - lastLoopTime;
		lastLoopTime = System.currentTimeMillis();
		lastFpsTime += delta;
		fps++;

		if (lastFpsTime >= 1000) 
		{
			window.setTitle(windowTitle + " (FPS: " + fps + ")");
			lastFpsTime = 0;
			fps = 0;
		}

		if (!waitingForKeyPress) 
		{
			for (int i = 0; i < entities.size(); i++) 
			{
				Entity entity = (Entity) entities.get(i);

				entity.move(delta);
			}
		}

		for (int i = 0; i < entities.size(); i++) 
		{
			Entity entity = (Entity) entities.get(i);

			entity.draw();
		}

		for (int p = 0; p < entities.size(); p++) 
		{
			for (int s = p + 1; s < entities.size(); s++) 
			{
				Entity me = (Entity) entities.get(p);
				Entity him = (Entity) entities.get(s);

				if (me.collidesWith(him)) 
				{
					me.collidedWith(him);
					him.collidedWith(me);
				}
			}
		}

		entities.removeAll(removeList);
		removeList.clear();

		if (logicRequiredThisLoop) 
		{
			for (int i = 0; i < entities.size(); i++) 
			{
				Entity entity = (Entity) entities.get(i);
				entity.doLogic();
			}

			logicRequiredThisLoop = false;
		}

		if (waitingForKeyPress) 
		{
			message.draw(325, 250);
		}

		ship.setHorizontalMovement(0);

		boolean leftPressed = window.isKeyPressed(KeyEvent.VK_LEFT);
		boolean rightPressed = window.isKeyPressed(KeyEvent.VK_RIGHT);
		boolean firePressed = window.isKeyPressed(KeyEvent.VK_SPACE);

		if (!waitingForKeyPress) 
		{
			if ((leftPressed) && (!rightPressed)) 
			{
				ship.setHorizontalMovement(-moveSpeed);
			}
			else if ((rightPressed) && (!leftPressed)) 
			{
				ship.setHorizontalMovement(moveSpeed);
			}

			if (firePressed) 
			{
				tryToFire();
			}
		} 
		else
		{
			if (!firePressed) 
			{
				fireHasBeenReleased = true;
			}
			if ((firePressed) && (fireHasBeenReleased)) 
			{
				waitingForKeyPress = false;
				fireHasBeenReleased = false;
				startGame();
			}
		}

		if (window.isKeyPressed(KeyEvent.VK_ESCAPE)) 
		{
			System.exit(0);
		}
	}

	public void windowClosed() 
	{
		System.exit(0);
	}

	public static void main(String argv[]) 
	{
		int result = JOptionPane.showOptionDialog(null, "Java2D or OpenGL?","Java2D or OpenGL?", JOptionPane.YES_NO_CANCEL_OPTION,JOptionPane.QUESTION_MESSAGE, null, new String[] { "Java2D","OpenGL" }, null);

		if (result == 0) 
		{
			Game g = new Game(ResourceFactory.JAVA2D);
			g.startRendering();
		}
		else if (result == 1) 
		{
			Game g = new Game(ResourceFactory.OPENGL_JOGL);
			g.startRendering();
		}
	}
}
