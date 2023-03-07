package package1;

import java.awt.Rectangle;

public abstract class Entity 
{
	protected double x;
	protected double y;
	protected Sprite sprite;
	protected double dx;
	protected double dy;
	private Rectangle me = new Rectangle();
	private Rectangle him = new Rectangle();

	public Entity(String ref, int x, int y) 
	{
		this.sprite = ResourceFactory.get().getSprite(ref);
		this.x = x;
		this.y = y;
	}

	public void move(long delta) 
	{
		x += (delta * dx) / 1000;
		y += (delta * dy) / 1000;
	}

	public void setHorizontalMovement(double dx) 
	{
		this.dx = dx;
	}

	public void setVerticalMovement(double dy) 
	{
		this.dy = dy;
	}

	public double getHorizontalMovement() 
	{
		return dx;
	}

	public double getVerticalMovement() 
	{
		return dy;
	}

	public void draw() 
	{
		sprite.draw((int) x, (int) y);
	}

	public void doLogic() 
	{
	}

	public int getX() 
	{
		return (int) x;
	}

	public int getY() 
	{
		return (int) y;
	}

	public boolean collidesWith(Entity other) 
	{
		me.setBounds((int) x, (int) y, sprite.getWidth(), sprite.getHeight());
		him.setBounds((int) other.x, (int) other.y, other.sprite.getWidth(),other.sprite.getHeight());

		return me.intersects(him);
	}

	public abstract void collidedWith(Entity other);
	
	//Ship Entity
	public static class ShipEntity extends Entity 
	{
		private Game game;

		public ShipEntity(Game game, String ref, int x, int y) 
		{
			super(ref, x, y);

			this.game = game;
		}

		public void move(long delta) 
		{
			if ((dx < 0) && (x < 10)) 
			{
				return;
			}
			if ((dx > 0) && (x > 750)) 
			{
				return;
			}

			super.move(delta);
		}

		public void collidedWith(Entity other) 
		{
			if (other instanceof AlienEntity) 
			{
				game.notifyDeath();
			}
		}
	}

	//Alien Entity
	public static class AlienEntity extends Entity 
	{
		private double moveSpeed = 75;
		private Game game;
		private Sprite[] frames = new Sprite[4];
		private long lastFrameChange;
		private long frameDuration = 250;
		private int frameNumber;

		public AlienEntity(Game game, int x, int y) 
		{
			super("sprites/alien.gif", x, y);

			frames[0] = sprite;
			frames[1] = ResourceFactory.get().getSprite("sprites/alien2.gif");
			frames[2] = sprite;
			frames[3] = ResourceFactory.get().getSprite("sprites/alien3.gif");

			this.game = game;
			dx = -moveSpeed;
		}

		public void move(long delta) 
		{
			lastFrameChange += delta;

			if (lastFrameChange > frameDuration) 
			{
				lastFrameChange = 0;

				frameNumber++;
				if (frameNumber >= frames.length) 
				{
					frameNumber = 0;
				}

				sprite = frames[frameNumber];
			}

			if ((dx < 0) && (x < 10)) 
			{
				game.updateLogic();
			}
			if ((dx > 0) && (x > 750)) 
			{
				game.updateLogic();
			}

			super.move(delta);
		}

		public void doLogic() 
		{
			dx = -dx;
			y += 10;

			if (y > 570) 
			{
				game.notifyDeath();
			}
		}

		public void collidedWith(Entity other) 
		{
		}
	}
	
	//Shot Entity
	public static class ShotEntity extends Entity 
	{
		private double moveSpeed = -300;
		private Game game;
		private boolean used = false;

		public ShotEntity(Game game, String sprite, int x, int y) 
		{
			super(sprite, x, y);

			this.game = game;

			dy = moveSpeed;
		}

		public void move(long delta) 
		{
			super.move(delta);

			if (y < -100) 
			{
				game.removeEntity(this);
			}
		}

		public void collidedWith(Entity other) 
		{
			if (used) 
			{
				return;
			}

			if (other instanceof AlienEntity) 
			{
				game.removeEntity(this);
				game.removeEntity(other);

				game.notifyAlienKilled();
				used = true;
			}
		}
	}
}