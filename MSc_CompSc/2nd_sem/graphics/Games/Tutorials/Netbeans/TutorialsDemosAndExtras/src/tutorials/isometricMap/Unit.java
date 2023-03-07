package tutorials.isometricMap;

import game.assets.*;
import game.engine.*;
import java.awt.event.*;

/**
 * Example unit that can be added to isometric tile map objects
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class Unit {
    
    ///////////////////////////////////////////////////////////////////////////
    // Class Data                                                            //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Store the type of unit
     */
    public String type;
    
    /**
     * Store the current map x and y of this unit
     */
    public int mapX, mapY;
    
    /**
     * Store the width and height of this unit
     */
    public double width = 0.0, height = 0.0;
    
    /**
     * Store the graphical asset to be used to represent this unit
     */
    public GraphicalAsset image;
    
    /**
     * Store a link back to the parent tile map (permitting access to 
     * the parent game layer, etc., etc.
     */    
    private IsometricTileMap tileMap;
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
        
    public Unit( String type, int mapX, int mapY, IsometricTileMap tileMap ) {
        this.tileMap = tileMap;
        
        this.mapX = mapX;
        this.mapY = mapY;
        
        setType( type );
    }
        
    public void setType( String type ) {
        // Based on the specified unit type, setup the initial graphical realisation
        // etc - currently only one type of unit is supported
        
        if( type.equals( "Archer" ) ) {
            image = tileMap.gameLayer.assetManager.retrieveGraphicalAsset( "Archer");
        }
        
        width = image.width;
        height = image.height;
    }
    
    public void update() {
        GameInputEventManager inputEvent = tileMap.gameLayer.inputEvent;
        
        int newMapX = mapX, newMapY = mapY;
        
        // The following code makes an assumption that the map will be 
        // surrounded by impassable tiles - a reasonable assumptiopn - however, 
        // if players can walk to the edge of the world, then the code will
        // need to be updated to provide array range checks
        
        if( inputEvent.keyTyped(KeyEvent.VK_UP) ) {
            if( tileMap.tiles[mapX+(mapY%2==1?1:0)][mapY-1].isPassable ) {
                newMapX += (mapY%2==1 ? 1 : 0);
                newMapY--;
            }
        } else if( inputEvent.keyTyped(KeyEvent.VK_DOWN)) {
            if( tileMap.tiles[mapX-(mapY%2==0?1:0)][mapY+1].isPassable ) {
                newMapX -=(mapY%2==0?1:0);
                newMapY++;
            }
        } if( inputEvent.keyTyped(KeyEvent.VK_LEFT) ) {
            if( tileMap.tiles[mapX-(mapY%2==0?1:0)][mapY-1].isPassable ) {
                newMapX -= (mapY%2==0?1:0);
                newMapY--;
            }
        } else if( inputEvent.keyTyped(KeyEvent.VK_RIGHT)) {
            if( tileMap.tiles[mapX+(mapY%2==1?1:0)][mapY+1].isPassable ) {
                newMapX += (mapY%2==1?1:0);
                newMapY++;
            }
        }
        
        // If the unit can move to a new tile, then ask the map to update
        // the position of the unit and store the new unit location
        if( newMapX != mapX || newMapY != mapY ) {
            tileMap.moveUnit(this, mapX, mapY, newMapX, newMapY);
            mapX = newMapX;
            mapY = newMapY;
        }
    }
}
