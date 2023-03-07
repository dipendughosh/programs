package tutorials.topDownScroller;

import game.assets.ImageAssetTile;

import game.physics.*;
import game.engine.*;
import game.geometry.*;

/**
 * Core game layer within the top-down scroller example (i.e. the layer
 * which contains the scroller itself). This layer contains the core game
 * update loop and game logic.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class TopDownScollerLayer extends CollisionSpace {

    ///////////////////////////////////////////////////////////////////////////
    // Class data: Class variables                                           //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Objects at different heights appear to move at different speeds
     * in relation to one another, i.e. cloud scroll past more slowly than
     * the plane and the water/islands scroll past most slowly than the
     * clouds (this gives a better feeling of depth).
     * <P>
     * The following values can be used to determine the strength of parallax
     * effect, i.e. a value of 0.5 means that for every two pixels that a game
     * object moves (parallax value of 1.0) the object with a value of 0.5 will
     * only move 1 pixels.
     */
    private static final double PARALLAX_VALUE_ISLANDS = 0.4;
    private static final double PARALLAX_VALUE_CLOUDS = 0.8;
    private static final double PARALLAX_VALUE_GAMEOBJECTS = 1.0;
    
    /**
     * Height of the game layer (the width is assumed to be equal to
     * the screen width) and the speed (in pixels/update) that the
     * screen scrolls.
     */
    private static final double GAME_HEIGHT = 20000;
    private static final double GAME_SCROLLSPEED = 4.0;
        
    /**
     * Current position within the game (i.e. how far have we scrolled
     * through the layer.
     */
    private double gamePosition = 0;
    
    /**
     * Region (widthxheight) relative and offset from the centre of the 
     * screen within which the player plane will be forced to remain 
     * (using this you can control the region of the screen that the 
     * player is permitted to fly over).
     */
    private double flyRegionOffsetX = 0;
    private double flyRegionOffsetY = 0;
    private double flyRegionWidth = gameEngine.screenWidth - 400;
    private double flyRegionHeight = gameEngine.screenHeight - 300;
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new top down scroller layers (which initialises and starts 
     * the game running).
     *
     * @param  gameEngine GameEngine instance to which this layer is to be added
     */
    public TopDownScollerLayer( GameEngine gameEngine ) {
        super( "TopDownScollerLayer", gameEngine );
        
        // Set the layer width to the width of the screen and the layer
        // height to that specified in the class variable
        width = gameEngine.screenWidth;
        height = GAME_HEIGHT;

        // Set the current layer viewport to the 'bottom' starting point
        // for the scroller
        viewPortLayerX = width/2;
        viewPortLayerY = height - gameEngine.screenHeight/2;
                
        // Add in game object sets for each of the different types of
        // game object (this makes it easier to update the objects
        // during the update phase).
        addGameObjectCollection( "Projectiles" );
        addGameObjectCollection( "Obstacles" );
        
        // Create the various background, etc. objects and the player plane
        createBackground();
        createObstacles();
        createPlayerPlane();
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Layer initialisation                                         //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create the background objects, i.e. water, islands, clouds and obstacles.
     * <P>
     * Note: Islands, clouds and obstacles are created at random throughout the
     * scrollable region. A more structure approach would load the placement
     * positions from a data file to provide each level with a defined layout
     */
    private void createBackground() {
        int NUM_ISLANDS = 20;
        int NUM_CLOUDS = 150;
        
        // Create the background water layer and object object (with the correct 
        // layer draw order, etc. that will hold a game object displaying a 
        // scrolling background. This layer will be sized to be equal to the 
        // screen dimensions as the game won't move, instead the graphical
        // image displayed by the water object will scoll.
        GameLayer waterLayer = new GameLayer( "WaterLayer", this.gameEngine );
        waterLayer.width = gameEngine.screenWidth;
        waterLayer.height = gameEngine.screenHeight;
        
        GameObject backgroundWater = new GameObject( waterLayer );
        backgroundWater.setName( "BackgroundWater" );
        backgroundWater.setRealisation( "BackgroundWater" );
        backgroundWater.setGeometry( 
                new Box( 0, 0, gameEngine.screenWidth, gameEngine.screenHeight));
        backgroundWater.setPosition( waterLayer.width/2, waterLayer.height/2 );
        waterLayer.addGameObject( backgroundWater );                
        
        gameEngine.addGameLayer(waterLayer);
                
        // Create a layer and set of island objects that will be drawn just
        // after the water layer is drawn. The layer is sized to reflect the
        // size of the top most layer scalled by the island parallax value
        GameLayer islandLayer = new GameLayer( "IslandLayer", this.gameEngine );
        islandLayer.width = gameEngine.screenWidth;
        islandLayer.height = GAME_HEIGHT * PARALLAX_VALUE_ISLANDS;
        islandLayer.viewPortLayerY = islandLayer.height - gameEngine.screenHeight/2;
                
        // Randomly create island objects.
        for( int idx = 0; idx < NUM_ISLANDS; idx++ ) {            
            GameObject island = new GameObject( islandLayer );
            island.setRealisationAndGeometry( "Island" );
            
            island.setPosition(
                    island.width/2 +
                    gameEngine.randomiser.nextInt( (int)(islandLayer.width - island.width/2)),
                    island.height/2 +
                    gameEngine.randomiser.nextInt( (int)(islandLayer.height - island.height/2)));            
            islandLayer.addGameObject( island );
        }
        
        gameEngine.addGameLayer(islandLayer);
        islandLayer.setDrawOrder(waterLayer.getDrawOrder()+1);
        
        // Create a layer and set of cloud objects that will be drawn just
        // after the island layer. As with the island layer, the cloud layer
        // is sized to reflect the size of the topmost layer scalled by the
        // cloud parallax value
        GameLayer cloudLayer = new GameLayer( "CloudLayer", this.gameEngine );
        cloudLayer.width = gameEngine.screenWidth;
        cloudLayer.height = GAME_HEIGHT * PARALLAX_VALUE_CLOUDS;
        cloudLayer.viewPortLayerY = cloudLayer.height - gameEngine.screenHeight/2;
                
        // Randomly create cloud objects
        for( int idx = 0; idx < NUM_CLOUDS; idx++ ) {
            GameObject cloud = new GameObject( cloudLayer );
            cloud.setRealisationAndGeometry( "Cloud" + (gameEngine.randomiser.nextInt(2)+1) );
            
            cloud.setPosition(
                    cloud.width/2 +
                    gameEngine.randomiser.nextInt( (int)(cloudLayer.width - cloud.width/2)),
                    cloud.height/2 +
                    gameEngine.randomiser.nextInt( (int)(cloudLayer.height - cloud.height/2)));            
            cloudLayer.addGameObject( cloud );            
        }
        
        gameEngine.addGameLayer(cloudLayer);
        cloudLayer.setDrawOrder(islandLayer.getDrawOrder()+1);
        
        // Set the draw order of this layer (holding the player's plane to
        // be the topmost layer
        this.setDrawOrder(cloudLayer.getDrawOrder()+1);
    }
    
    /**
     * Create a set of barrage ballons within the layer to provide obstacles
     * for the player to avoid
     */
    private void createObstacles() {
        int NUM_OBSTACLES = 40;
        
        for( int idx = 0; idx < NUM_OBSTACLES; idx++ ) {
            Body obstacle = new Body( this );
            obstacle.setRealisationAndGeometry( "BarrageBalloon" );
            obstacle.restitution = 0.25;
            
            obstacle.setPosition(
                    obstacle.width/2 +
                    gameEngine.randomiser.nextInt( (int)(this.width - obstacle.width/2)),
                    obstacle.height/2 +
                    gameEngine.randomiser.nextInt( (int)(this.height - obstacle.height/2)));
            this.addGameObject( obstacle );
        }
    }
        
    /**
     * Create the player plane
     */
    protected void createPlayerPlane() {
        Plane playerPlane = new Plane( this );
        playerPlane.setName("PlayerPlane");
        playerPlane.setPosition(gameEngine.screenWidth/2,
                GAME_HEIGHT -gameEngine.screenHeight/2 );
        addGameObject( playerPlane );
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Game update                                                  //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Central update loop called by the game engine
     */
    public void update() {
                
        updateViewPort();        
        updatePlayerPlane();        
        updateProjectiles();
        
        // It is important that the super.update method is called - for two 
        // reasons: The CollisionSpace update will update game object positions
        // and handle any collisions between objects, whilst the GameLayer
        // update will add and/or remove any queued game objects.
        super.update();        
    }
    
    /**
     * Update the viewport, i.e. scroll the level forward.
     */
    private void updateViewPort() {
        // Don't scroll if we've reached the top of the level
        if( gamePosition + gameEngine.screenHeight > GAME_HEIGHT )
            return;

        // Move this layer forward by the set scroll speed
        gamePosition += GAME_SCROLLSPEED;
        
        // Update the viewport for this layer and the other layers
        // by the correct amount
        viewPortLayerY -= GAME_SCROLLSPEED;        
        gameEngine.getGameLayer("IslandLayer").viewPortLayerY
                -= GAME_SCROLLSPEED *  PARALLAX_VALUE_ISLANDS;        
        gameEngine.getGameLayer("CloudLayer").viewPortLayerY
                -= GAME_SCROLLSPEED *  PARALLAX_VALUE_CLOUDS;

        // Update the bottom layer (which contains the water object)
        // so that it scrolls it's graphical realisation
        GameObject backgroundWater =
                gameEngine.getGameObjectFromLayer("BackgroundWater", "WaterLayer");
        ((ImageAssetTile)backgroundWater.getRealisation(0)).setViewPort(
                gameEngine.screenWidth/2, (int)(viewPortLayerY*PARALLAX_VALUE_ISLANDS) );
        backgroundWater.getRealisation(0).update();
    }
    
    /**
     * Update the player's plane
     */
    private void updatePlayerPlane() {
        // Update the plane movement
        Plane playerPlane = (Plane)getGameObject( "PlayerPlane" );        
        if( playerPlane == null )
            return;
        
        playerPlane.update();
        
        // Ensure the plane remains within the defined movement region
        if( playerPlane.x < viewPortLayerX + flyRegionOffsetX - flyRegionWidth/2 )
            playerPlane.velocityx += 50.0;
        else if( playerPlane.x > viewPortLayerX + flyRegionOffsetX + flyRegionWidth/2 )
            playerPlane.velocityx -= 50.0;
        
        if( playerPlane.y < viewPortLayerY + flyRegionOffsetY - flyRegionHeight/2 ) {
            playerPlane.velocityy += 50.0;
        } else if( playerPlane.y > viewPortLayerY + flyRegionOffsetY + flyRegionHeight/2 ) {
            playerPlane.y = viewPortLayerY + flyRegionOffsetY + flyRegionHeight/2;
        }
    }
    
    /**
     * Update all projectiles
     */
    private void updateProjectiles() {
        GameObjectCollection projectiles = getGameObjectCollection( "Projectiles" );
        for( int idx = 0; idx < projectiles.size; idx++ ) {
            projectiles.gameObjects[idx].update();
        }
    }
}