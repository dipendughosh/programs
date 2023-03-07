package tutorials.isometricMap;

import game.engine.*;

/**
 * Example isometric tile game
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class TileMap extends GameEngine {

    private static final int SCREEN_WIDTH = 1024;
    private static final int SCREEN_HEIGHT = 768;
    
    public TileMap() {
        gameStart( SCREEN_WIDTH, SCREEN_HEIGHT, 32 );
    }
    
    @Override
    public boolean buildAssetManager() {
        assetManager.loadAssetsFromFile(
                getClass().getResource("images/TileMap.txt"));
        
        return true;
    }
    
    @Override
    protected boolean buildInitialGameLayers() {
        TileMapLayer isometricTileMapLayer 
                = new TileMapLayer( this, "maps/ExampleMap.txt" );
        addGameLayer( isometricTileMapLayer );
        
        return true;
    }
    
    public static void main(String[] args) {
        TileMap instance = new TileMap();
    }
}
