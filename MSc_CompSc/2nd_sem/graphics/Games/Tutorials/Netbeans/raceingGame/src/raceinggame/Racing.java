package raceinggame;

import game.engine.*;
//import raceinggame.RacingLayer;

public class Racing extends GameEngine
{
	private static final int SCREEN_WIDTH = 1024;
	private static final int SCREEN_HEIGHT = 768;
	
	public Racing() 
	{
		gameStart( SCREEN_WIDTH, SCREEN_HEIGHT, 32 );
	}
	@Override
	public boolean buildAssetManager() 
	{
		//assetManager.loadAssetsFromFile(this.getClass().getResource("images/RacingAssets.txt"));
		assetManager.addImageAsset("Track",getClass().getResource("images/Track.png"));
		assetManager.addImageAsset("TrackHitRegions",getClass().getResource("images/TrackHitRegions.png"));
		assetManager.addImageAsset("Car",getClass().getResource("images/Car.png"));
		return true;
	}
	@Override
	protected boolean buildInitialGameLayers() 
	{
		RacingLayer racingLayer = new RacingLayer( this );
		addGameLayer( racingLayer );
		return true;
	}
	public static void main(String[] args) 
	{
		Racing instance = new Racing();
	}
}