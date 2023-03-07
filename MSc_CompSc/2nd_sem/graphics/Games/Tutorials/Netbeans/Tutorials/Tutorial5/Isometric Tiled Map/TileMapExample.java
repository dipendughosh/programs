package tutorials.isometricTileMap;

import game.assets.*;
import game.engine.*;

public class TileMapExample extends GameEngine 
{
    // Setup the screen width and screen height
    private static final int SCREEN_WIDTH = 1024;
    private static final int SCREEN_HEIGHT = 768;
        
    public TileMapExample() 
    {
        this.buildAssetManager();    
        
        // Create a new game layer, make it visible/active and add it to the game engine
        TileMapLayer isometricTileMapLayer 
                = new TileMapLayer( "IsometricTileMapa", SCREEN_WIDTH, SCREEN_HEIGHT, this );
        isometricTileMapLayer.setState( GameLayer.GameLayerVisibility.VISIBLE, 
                             GameLayer.GameLayerActivity.ACTIVE );
        this.addGameLayer( isometricTileMapLayer );                
        
        // Start FSEM at specified resolution and start update/render loop
        this.gameStart( SCREEN_WIDTH, SCREEN_HEIGHT, 32 );  
    }
    
    public void buildAssetManager()
    {
        // Load in a desert tile
        assetManager.addImageAsset( "DesertTile1Image", 
                getClass().getResource( "images/DesertTile1.png" ) );        

        // Load in a desert tile
        assetManager.addImageAsset( "DesertTile2Image", 
                getClass().getResource( "images/DesertTile2.png" ) );        

        // Load in a desert tile
        assetManager.addImageAsset( "DesertTile3Image", 
                getClass().getResource( "images/DesertTile3.png" ) );        
        
        // Load in a mountain tile
        assetManager.addImageAsset( "MountainTileImage", 
                getClass().getResource( "images/MountainTile.png" ) );        
        
         // Load in a tree overlay 
       assetManager.addImageAsset( "TreeOverlayImage", 
                getClass().getResource( "images/TreeOverlay.png" ) );                
        
        // Load in a rock overlay
        assetManager.addImageAsset( "RocksOverlayImage", 
                getClass().getResource( "images/RocksOverlay.png" ) );          
        
        // Load in our car image (taken from an old GTA)
        assetManager.addImageAsset( "CarImage", 
                getClass().getResource( "images/Car.png" ) );                                
    }

    public static void main(String[] args) 
    {
        TileMapExample instance = new TileMapExample();
    }               
}
