package package1;

public class AlienEntity extends Entity 
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