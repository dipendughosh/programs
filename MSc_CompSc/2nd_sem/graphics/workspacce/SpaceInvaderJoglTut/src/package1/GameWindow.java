package package1;

public interface GameWindow 
{

	public void setTitle(String title);

	public void setResolution(int x, int y);

	public void startRendering();

	public void setGameWindowCallback(GameWindowCallback callback);

	public boolean isKeyPressed(int keyCode);
}