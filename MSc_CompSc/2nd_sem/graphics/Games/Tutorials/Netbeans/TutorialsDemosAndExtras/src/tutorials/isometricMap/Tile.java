package tutorials.isometricMap;

import game.assets.*;

/**
 * Individual tile to be displayed within the tilemap
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class Tile {

    ///////////////////////////////////////////////////////////////////////////
    // Class Data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Define if the tile is passable - various other type of tile parameter
     * could also be defined if desired
     */
    public boolean isPassable = true;

    /**
     * Define the tile width and height
     */
    public double tileHeight = 0.0, tileWidth = 0.0;

    /**
     * Define an array of graphical assets representing the different layers
     * to be drawn when the tile is drawn
     */
    public GraphicalAsset[] tileImages = new GraphicalAsset[0];
    
    /**
     * Store a link back to the parent tile map (permitting access to 
     * the parent game layer, etc., etc.
     */
    private IsometricTileMap tileMap;


    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
            
    public Tile( String baseTileType, IsometricTileMap tileMap  ) {
        this.tileMap = tileMap;
        
        // Form the base tile
        setBaseTile( baseTileType );
    }
    
    public void setBaseTile( String baseTileType ) {
        // Based on the specified tile type, setup the initial graphical realisation
        // If the specified tile is impassable, then update the isPassable tile
        // as needed
        
        if( baseTileType.equals( "DesertTile1" ) ) {
            isPassable = true;
            addTileGraphic( "DesertTile1", 0, 0 );
        }
        
        else if( baseTileType.equals( "DesertTile2" ) ) {
            isPassable = true;
            addTileGraphic( "DesertTile2", 0, 0 );
        }
        
        else if( baseTileType.equals( "DesertTile3" ) ) {
            isPassable = true;
            addTileGraphic( "DesertTile3", 0, 0 );
        }
        
        else if( baseTileType.equals( "MountainTile" ) ) {
            isPassable = false;
            addTileGraphic( "MountainTile", 0, 0 );
        }
        
        tileWidth = tileImages[0].width;
        tileHeight = tileImages[0].height;
        
    }
        
    public void addTileOverlay( String tileOverlayType ) {
        // If a specified tile overlay has been specified,
        // then add the tile graphic and if needed update
        // the isPassable flag
        
        if( tileOverlayType.equals( "TreeOverlay" ) ) {
            isPassable = false;
            addTileGraphic( "TreeOverlay", 5, -20 );
        }
        
        else if( tileOverlayType.equals( "RocksOverlay" ) ) {
            addTileGraphic( "RocksOverlay", 0, 0 );
        }
    }
        
    private void addTileGraphic( String assetName, int assetXOffset, int assetYOffset ) {
        GraphicalAsset[] newRealisation = new GraphicalAsset[tileImages.length+1];
        System.arraycopy( tileImages, 0, newRealisation, 0, tileImages.length );
        
        newRealisation[tileImages.length]
                = tileMap.gameLayer.assetManager.retrieveGraphicalAsset(assetName);
        newRealisation[tileImages.length].offsetX = assetXOffset;
        newRealisation[tileImages.length].offsetY = assetYOffset;

        tileImages = newRealisation;
    }
}