package tutorials.isometricMap;

import game.assets.*;
import game.engine.*;

import game.geometry.*;

import java.io.*;
import java.util.*;
import java.awt.*;

/**
 * Core isometric tile map that contains and displays the set of tiles
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class IsometricTileMap extends GameObject {

    ///////////////////////////////////////////////////////////////////////////
    // Class Data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Define the map width and height in terms of number of tiles wide and
     * number of tiles high (i.e. in tiles, not pixels)
     */
    public int mapWidth;
    public int mapHeight;

    /**
     * Define the default tile width and height of each tile
     */
    public int tileWidth;
    public int tileHeight;

    /**
     * Define a two dimensional array of Tile objects. Each tile represents a
     * basic, non-moving, element of the map
     */
    public Tile tiles[][];
    
    /**
     * Define a collection of Unit objects - units can be things like players,
     * characters, etc. that can move about the map. Each unit is stored
     * within a hashmap with the key constructed to represent the current 
     * location of the unit on the map. A number of different ways of storing 
     * units could have been used - a hashmap was selected here as it provides
     * a quick means of asking if any object can be found on a particilar
     * tile. An alternative would be to provide another two dimension
     * collection of contains that can hold units (e.g. the tile class
     * could be extended to be capable of holding tile units).
     */
    public HashMap<Integer, Unit> units = new HashMap<Integer, Unit>();
    
    /**
     * Define the unit that will provide the layer focal point (i.e. the
     * viewport of the gameLayer this tile map belongs to will be updated
     * to focus on the specified (normally player) unit.
     */
    public Unit focalUnit = null;

    /**
     * Define the game layer to which this tile map belongs - storing the 
     * game layer provides access to the layer itself (and via the layer,
     * the game engine, asset manager, etc.).
     */
    public GameLayer gameLayer;

    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
        
    public IsometricTileMap( GameLayer gameLayer, String mapFile ) {
        super( gameLayer );        
        this.gameLayer = gameLayer;
        
        // Load in the map that represents this level
        constructMap( mapFile );        
        
        // Add units to the map - this could also be something that is 
        // loaded from a data file
        addUnits();
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Convert the specified x, y map location into a unique hash value
     * that can be stored to add/retrieve units from the unit hash map.
     * <P>
     * Note: Multiplying the mapX by 65536 basically shifts the binary mapX 
     * value by 16 bits, i.e. the following will provide unit hash maps
     * as long as the map size does not exceed 65536x65536
     */
    public int convertPositionToHash( int mapX, int mapY ) {
        return mapX * 65536 + mapY;
    }
    
    /**
     * Based on the specified hash value determine the map x location 
     * (i.e. using integer maths, divide the hash by 65536 which effectively
     * returns the mapX to its original value and discards the mapY value).
     */
    public int getMapXFromHash( int hash ) {
        return hash / 65536;
    }
    
    /**
     * Based on the specified hash value determine the map y location 
     * (i.e. using integer maths, mod the hash by 65536 which effectively
     * discards the mapX component and returns the mapY value).
     */
    public int getMapYFromHash( int hash ) {
        return hash % 65536;
    }
    
        
    /**
     * Construct the map based on the specified map file
     */    
    public void constructMap( String mapName ) {
        try {
            // Open the specified map name (relative to the class file).
            BufferedReader bufferedReader
                    = new BufferedReader( new InputStreamReader(
                    this.getClass().getResource( mapName ).openStream() ) );
            
            // Read in the first two lines that must contain the tile width and height
            tileWidth = Integer.parseInt( bufferedReader.readLine() );
            tileHeight = Integer.parseInt( bufferedReader.readLine() );
            
            // Read in the next two lines which contain the width and height of
            // the map in terms of number of tiles
            mapWidth = Integer.parseInt( bufferedReader.readLine() );
            mapHeight = Integer.parseInt( bufferedReader.readLine() );
            
            // Create a new map obejct
            tiles = new Tile[mapWidth][mapHeight];
            
            // Read in the types of tile to be created for the map
            for( int rowIdx = 0; rowIdx < mapHeight; rowIdx++ ) {
                // Read in each row and create a StringTokenzier object
                // to parse through the line and extract the individual
                // words (i.e. tile names)
                String rowData = bufferedReader.readLine();
                StringTokenizer tokenizer = new StringTokenizer( rowData );
                
                // Use the string tokenizer to specify the type of tile to be created
                for( int colIdx = 0; colIdx < mapWidth; colIdx++ )
                    tiles[colIdx][rowIdx] = new Tile( tokenizer.nextToken(), this );
            }
            
            // Now that the base tile type has been loaded, load in each tile overlay
            while( bufferedReader.ready() ) {
                // Again use a StringTokenizer to pull out each bit of the tile
                StringTokenizer tokenizer
                        = new StringTokenizer( bufferedReader.readLine() );
                
                // The first two parameters specify the col and row offset
                int colIdx = Integer.parseInt( tokenizer.nextToken() );
                int rowIdx = Integer.parseInt( tokenizer.nextToken() );
                
                // The next word specifies the type of tile overlay to add
                String tileOverlayType = tokenizer.nextToken();
                
                // Add the specified tile overlay to the specific tile
                tiles[colIdx][rowIdx].addTileOverlay( tileOverlayType );
            }
        } catch( IOException e ) {
            System.out.println( "Error: Can't read from: " + mapName );
        }
        
        // Now that the map has been loaded up the width and height
        // of this GameObjectGraphical. As we are using an isometric
        // map, the width and height calculation is shown
        setGeometry( new Box( 0, 0,
                mapWidth * tileWidth + tileWidth/2,
                mapHeight * tileHeight/2 + tileHeight/2 ) );
    }
    
    /**
     * Add units to the map, at the moment only one unit is added. This could
     * obviously be extended
     */
    private void addUnits() {
        Unit archer = new Unit( "Archer", 5, 5, this );

        int positionHash = convertPositionToHash( 5, 5 );        
        units.put(positionHash, archer);
        
        focalUnit = archer;
    }
    
    
    @Override
    public void update() {
        // Update each unit
        for( Integer positionHash : units.keySet() )
            units.get(positionHash).update();

        // Ensure that the specified focus unit remains in the layer viewport
        if( focalUnit != null ) {
            gameLayer.centerViewportOnPosition(
                    (this.x - this.width/2) + focalUnit.mapX * tileWidth,
                    (this.y - this.height/2) + focalUnit.mapY * tileHeight/2,
                    gameLayer.gameEngine.screenWidth/4, gameLayer.gameEngine.screenHeight/4  );
        }        
    }
    
    /**
     * Move the specified map unit from the old map x,y to the new map x,y
     */
    public void moveUnit( Unit unit, int oldMapX, int oldMapY, int newMapX, int newMapY ) {
        units.remove(convertPositionToHash(oldMapX,oldMapY));
        units.put(convertPositionToHash(newMapX,newMapY), unit);
    }
    
    /**
     * Draw the tile map to the screen
     */
    @Override
    public void draw( Graphics2D graphics2D, int drawX, int drawY ) {
        // Draw each tile in the tile array
        for( int rowIdx = 0; rowIdx < mapHeight; rowIdx++ )
            for( int colIdx = 0; colIdx < mapWidth; colIdx++ ) {
            // Work out the tile x position based on the specified
            // x draw location. If needed (as this is an isometric
            // tile map, ship every odd row by half a tile across
            int tileDrawX = drawX + colIdx * tileWidth - (int)width/2;
            if( rowIdx % 2 == 1 )
                tileDrawX += tileWidth/2;
            
            // Work out the tile y position bassed on the specified
            // y draw location. 
            int tileDrawY = drawY + rowIdx * tileHeight/2 - (int)height/2;
            
            // Check to see if the tile we are drawing is larger than the 
            // specifid default tile height (this is OK, it basicallly means 
            // we have a higher tile than normal). If so, then reposition the 
            // y draw position so that the bottom of the tile is drawn at the 
            // correct location. To be generic this test should also be applied
            // to the width of the tile (i.e. to account for any tiles that
            // are wider than normal).
            int tileDrawYDrop = 0;
            if( tiles[colIdx][rowIdx].tileHeight > tileHeight )
                tileDrawYDrop = (int)((tiles[colIdx][rowIdx].tileHeight - tileHeight));
            
            // Draw the tile at the calculated position. Before the tile is drawn
            // a test is made to see if the tile falls within the screen region -
            // any tiles that lie outside of the screen are not drawn. Actually 
            // to be 100% precise this code should really check to see if the 
            // tile ties within the on-screen viewport of the layer (which could
            // be smaller than the screen size). To be fully generic the code
            // should also take into account the draw scale factor, i.e. thereby
            // permitting the tile map to be zoomed in and out
            GraphicalAsset[] tileImages = tiles[colIdx][rowIdx].tileImages;
            for( int imageIdx = 0; imageIdx < tileImages.length; imageIdx++ ) {
                if( (tileDrawX + tileImages[imageIdx].width/2) >= 0
                        && (tileDrawX - tileImages[imageIdx].width < gameEngine.screenWidth)
                        && (tileDrawY + tileImages[imageIdx].height/2 >= 0)
                        && (tileDrawY - tileImages[imageIdx].height/2 < gameEngine.screenWidth) )
                    tileImages[imageIdx].draw(graphics2D,
                            tileDrawX + (int)tileImages[imageIdx].offsetX,
                            tileDrawY + (int)tileImages[imageIdx].offsetY - tileDrawYDrop );
            }
            
            // Now that the tile has been drawn, if there are any units on the tile, then
            // draw them to the screen.
            int positionHash = convertPositionToHash(colIdx, rowIdx);
            if( units.containsKey( positionHash ) ) {
                Unit unit = units.get(positionHash);
                if( (tileDrawX + unit.image.width/2) >= 0
                        && (tileDrawX - unit.image.width < gameEngine.screenWidth)
                        && (tileDrawY + unit.image.height/2 >= 0)
                        && (tileDrawY - unit.image.height/2 < gameEngine.screenWidth) )
                    unit.image.draw(graphics2D,
                        tileDrawX+tileWidth/2-(int)unit.width/2, tileDrawY-tileHeight/3 );
            }
        }
    }
    
    /**
     * As a bonus method - it's not used within this example program - the following
     * method will check if a specified gameobject is at a valid map location. 
     * This method would be used in situations where units are not added to the 
     * tile map, but rather are separate entities that are drawn on-top of the map
     */
    public boolean isAtValidLocation( GameObject gameObject ) {
        // Work out the tile row start and end position on which the specified game
        // object rests.
        int tileRowStartLocation = (int)(gameObject.y - (this.y - this.height/2)) / (tileHeight/2);
        int tileRowEndLocation = (int)(gameObject.y + gameObject.height/2
                - (this.y - this.height/2) ) / (tileHeight/2);
        
        // Work out the col start and end position on which the specified game
        // object rests. Actually, this test could be made more tighter in terms
        // of removing some unecessary comparisons in certain conditions. However,
        // for the perspective of this tutorial, the following is simple, works
        // and is nearly optimal.
        int tileColStartLocation = (int)(gameObject.x - gameObject.width/2
                - tileWidth/2 - (this.x - this.width/2)) / tileWidth;
        int tileColEndLocation = (int)(gameObject.x + gameObject.width/2
                + tileWidth/2 - (this.x - this.width/2)) / tileWidth;
        
        // Consider each tile to see if the specified game object is resting on it
        for( int colIdx = tileColStartLocation; colIdx <= tileColEndLocation; colIdx++ )
            for( int rowIdx = tileRowStartLocation; rowIdx <= tileRowEndLocation; rowIdx++ )
                if( tiles[colIdx][rowIdx].isPassable == false ) {
            // If any time is impassable then return false;
            // If needed, the following if could also be added
            // if( gameObject.intersects( isometricTileMap[colIdx][rowIdx] ) )
            // Which would permit a more exact comparison using boundingg regions
            // should they be added to the tile objects.
            return false;
                }
        
        return true;
    }
}
