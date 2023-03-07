package tutorials.isometricMap;

import game.engine.*;
import java.awt.*;

/**
 * Tile map layer
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class TileMapLayer extends GameLayer {

    public TileMapLayer( GameEngine gameEngine, String mapFile ) {
        super( "TileMapLayer", gameEngine );
        
        // Create the map using the specified map file
        createMap( mapFile );
    }
    
    private void createMap( String mapFile ) {
        // Create a new isometric object and give it a name for ease of recall later
        IsometricTileMap isometricTileMap = new IsometricTileMap( this, mapFile );
        isometricTileMap.setName( "TileMap" );
        
        // Now that we've loaded in the map we can determine how big the map is
        // and from this determine the width and height of the game layer
        double mapWidth = isometricTileMap.width;
        double mapHeight = isometricTileMap.height;

        // Ensure the layer size is large enough to store the tile map
        if( width <  mapWidth ) width = mapWidth;
        if( height  <  mapHeight ) height = mapHeight;
        
        // Position the tile object within the game layer 
        isometricTileMap.x = mapWidth/2;
        isometricTileMap.y = mapHeight/2;
        
        addGameObject( isometricTileMap );
    }

    @Override
    public void update() {
        IsometricTileMap isometricTileMap = (IsometricTileMap)getGameObject( "TileMap" );
        isometricTileMap.update();        
    }
    
    @Override
    public void draw( Graphics2D graphics2D ) {        
        Color originalColour = graphics2D.getColor();
        graphics2D.setColor( Color.black );
        graphics2D.fillRect( 0, 0, gameEngine.screenWidth, gameEngine.screenHeight );
        graphics2D.setColor( originalColour );
        
        super.draw( graphics2D );        
    }    
}