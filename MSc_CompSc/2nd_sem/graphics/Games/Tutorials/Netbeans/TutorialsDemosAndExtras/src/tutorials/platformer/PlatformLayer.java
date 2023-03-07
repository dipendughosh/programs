package tutorials.platformer;

import game.assets.*;
import game.engine.*;
import game.physics.*;
import game.geometry.*;

import java.awt.event.KeyEvent;

/**
 * Platform layer
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class PlatformLayer extends CollisionSpace {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * This value represents the strength of gravity. Gravity is basically
     * a downwards accelerative force and each update tick the collision
     * space will increase the download velocity  so that the velocity
     * increased by GRAVITY_STRENGTH pixels over a period of one second
     */
    public static final double GRAVITY_STRENGTH = 800.0;
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a platform layer
     *
     * @param gameEngine GameEngine instance to which the layer belongs
     */    
    public PlatformLayer( GameEngine gameEngine ) {
        super( "PlatformLayer", gameEngine );
        
        // Define the width of this level as 10000 pixels - this can be made
        // longer or shorter as needed
        width = 10000;
        
        // By default, make the height of the layer equal to the height of the
        // screen - although you can change this to be higher (or smaller)
        // if desired.
        height = gameEngine.screenHeight;
        
        // Set the gravitational strength 
        setGravity(0, GRAVITY_STRENGTH );
                
        // To facilitate the update process two game object collections are
        // defined: one containing all the balls and another containing all
        // the platforms. Other game object sets can be added if needed.
        // For example, if we had collectable objects, lots of 'enemy'
        // sprites, etc. they would be prime candidates to place inside a
        // game object collections which provide a handy means of processing
        // all related objects
        addGameObjectCollection( "Platforms" );
        addGameObjectCollection( "Balls" );
        
        // Create the level. This comprises of creating the background, the
        // various platforms and the character. Ball sprites are created
        // on demand (i.e. there are none at the start of the level). Other
        // possibilities here would be to create collectable objects, enemies,
        // etc.
        createBackground();
        createPlatforms();
        createCharacter();             
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create the background cave wall.
     */
    private void createBackground() {
        // The background is created as a new game layer that has a lower draw
        // order than this layer (i.e. the background layer will be drawn
        // before this layer is drawn). The background layer is sized
        // to be the same size as the screen and contains only one game object
        // that displays the background image ribbon. During the update tick
        // of this layer, the viewport of the background image ribbon will
        // be shifted to reflect any changes in the player's position,
        // i.e. as the player moves the background also moves.
        
        // Create the background layer - give it as name as we will want to
        // retreive this layer later within the update tick. The background
        // layer is sized to reflect the dimensions of the screen
        GameLayer backgroundLayer = new GameLayer( "BackgroundLayer", this.gameEngine );
        backgroundLayer.width = gameEngine.screenWidth;
        backgroundLayer.height = gameEngine.screenHeight;
                
        // Create a new background object containing the image ribbon. The
        // created object is constructed as belonging to the background layer
        // and is positioned in the middle of the background layer
        GameObject background = new GameObject( backgroundLayer );
        background.setName("Background");
        background.setPosition( backgroundLayer.width/2, backgroundLayer.height/2 );
        
        ImageAssetRibbon backgroundAsset
                = (ImageAssetRibbon)assetManager.retrieveGraphicalAsset("Background");
        background.setRealisation(backgroundAsset);
        background.setGeometry( new Box( 0, 0, 1024, 768));
        
        // Add the background game object to the background layer and the layer
        // to the game engine
        backgroundLayer.addGameObject(background);
        gameEngine.addGameLayer(backgroundLayer);
        
        // Finally change the draw order of this game layer so that it is
        // drawn after the background layer
        setDrawOrder(backgroundLayer.getDrawOrder()+1);
    }
    
    /**
     * Create the platforms that comprise this level.
     * <P>
     * IMPORTANT: In this method I've basically used a number of for loops
     * to create various platform structure (the level is not particularly
     * complex, nor do I have multiple types of tiles). A much better approach
     * would be to construct the level from some form of map description.
     * The map could be tile based, or it could contain precise descriptions, e.g.
     * PlatformType1, XLoc = 2345, YLoc, 345. The advantage of doing this
     * is that you can have multiple level descriptions all constructed
     * using the same method. 
     */
    private void createPlatforms() {
        // Each layer has a platform along the bottom of the screen. This prevents
        // objects from falling 'below' the screen (or bouncing off the side of the
        // game layer) and gives the game a more appropriate graphical feel (the
        // player is always walking on something).
        double groundOffset = 0;
        while( groundOffset < this.width ) {
            createPlatform( groundOffset,
                    this.height - assetManager.retrieveGraphicalAssetArchetype("Platform").height );
            groundOffset += assetManager.retrieveGraphicalAssetArchetype("Platform").width;
        }
        
        // The following for loops create various block structures. This is done
        // to provide a few example platform structures within the demo.
        // However, as indicated within the method header - you would really
        // want to use something a tad more generic in terms of building the
        // level.
        for( int idx = 0; idx < 8; idx++ )
            createPlatform( 300 + 150 * idx, this.height - 50 * (idx+1) );
        
        for( int idx = 0; idx < 8; idx++ )
            createPlatform( 2500 - 150 * idx, this.height - 50 * (idx+1) );
        
        for( int idx = 0; idx < 5; idx++ )
            createPlatform( 3500 - 400 * (idx%2), this.height - 100 * (idx+1) );
        
        for( int idx = 0; idx < 10; idx++ )
            createPlatform( 4500 + 150 * idx, this.height - 50 * (idx+1) );
        
        for( int idx = 0; idx < 12; idx++ )
            createPlatform( 6000, this.height - 50 * (idx+1) );
        
        for( int idx = 0; idx < 12; idx++ )
            createPlatform( 7200, this.height - 50 * (idx+1) );
        
    }
    
    /**
     * Create an individual platform at the specified location
     *
     * @param x double x location at which the platform should be created
     * @param y double y location at which the platform should be created
     */
    private void createPlatform( double x, double y ) {
        // Create a new Body object to hold the platform. A Body instance
        // is created as we wish to include the platform within the physics
        // update tick. By default all created bodies have infinite mass,
        // i.e. they are unmovable - however, we explictly set the mass
        // to the 'infinite' amount just to be explicit
        Body platform = new Body( this );
        platform.setRealisationAndGeometry("Platform");
        platform.setPosition(x, y);
        platform.setMass( Double.MAX_VALUE );
        
        // Add the created platform to the layer (and into the relevant
        // game object collection
        addGameObject( platform, "Platforms" );
    }
    
    /**
     * Create the specified number of balls at the specified location.
     * <P>
     * Note: This also a bit of a random method - balls were added
     * into the code to illustrate how large number of simple sprite
     * objects would be effected by gravity. Be default, the balls
     * are created at the top of the game layer centered around the
     * players location in the layer.
     *
     * @param numExtraBalls integer number of balls to be created
     * @param xLocation double x location at which balls will be created
     */
    private void createBalls( int numExtraBalls ) {
        double playerXLocation = getGameObject( "Sonic" ).x;
        
        for( int ballIdx = 0; ballIdx < numExtraBalls; ballIdx++ ) {
            String ballAsset = "Ball" + (gameEngine.randomiser.nextInt(5)+1);
            
            Body ball = new Body( this );
            ball.setRealisation(ballAsset);
            ball.setGeometry( new Circle( 0, 0,
                    assetManager.retrieveGraphicalAssetArchetype(ballAsset).width/2 ) );
            ball.setPosition( playerXLocation - gameEngine.screenWidth/2 +
                    gameEngine.randomiser.nextInt(gameEngine.screenWidth),
                    -gameEngine.randomiser.nextInt(300) );
            ball.setMass( 10.0 );
            ball.restitution = 0.75;
                        
            // Add the ball to the ball game object set
            addGameObject( ball, "Balls" );
        }
    }
    
    /**
     * Create the player's Sonic sprite
     */
    private void createCharacter() {
        SonicSprite sonic = new SonicSprite( this );
        sonic.setPosition( 0, gameEngine.screenHeight - sonic.height - 200 );
        addGameObject( sonic );
    }
    
    
    /**
     * Layer update method
     * <P>
     * This method is where all of the action happens in terms of updating
     * objects.
     */
    @Override
    public void update() {
        // Call the update method of the CollisionSpace layer to execute
        // the physics tick
        super.update();                
                
        // Check to see if the user wishes to add in some extra balls
        checkForLayerInput();
        
        // Update the view port to take into account any player movement
        updateViewPort();
        
        // Update game objects
        updateGameObjects();        
    }
        
    /**
     * Check if the player wishes to create more balls
     */
    private void checkForLayerInput() {
        if( inputEvent.keyTyped( KeyEvent.VK_1 ) )
            createBalls( 1 );
        else if( inputEvent.keyTyped( KeyEvent.VK_2 ) )
            createBalls( 10 );
        else if( inputEvent.keyTyped( KeyEvent.VK_3 ) )
            createBalls( 100 );
    }
        
    /**
     * Update the viewport to ensure it moves as the player moves.
     */
    private void updateViewPort() {
        GameObject sonic = getGameObject( "Sonic" );

        // The GameLayer class provides a useful method that can be call to 
        // center the layer viewport on a particular object
//        centerViewportOnGameObject(sonic,
//                0.0, 0.0, gameEngine.screenWidth/2.0, gameEngine.screenHeight/2.0);
        centerViewportOnGameObject(sonic,
                0.0, 0.0, 0.0, 0.0);
        
        // Update the ribbon viewport of the background object of the
        // background layer to reflect any change in the player's position
        GameObject background =
                gameEngine.getGameObjectFromLayer("Background", "BackgroundLayer");
        ((ImageAssetRibbon)background.getRealisation(0)).setViewPort(
                (int)viewPortLayerX, 0 );
        background.getRealisation(0).update();
    }
        
    /**
     * Update all game objects.
     * <P>
     * Note: For this game there is no layer AI and the CollisionSpace update
     * handles all the movemenet update and collision resolution, i.e. all that
     * is left for this method to do is to update the player sprite.
     */
    private void updateGameObjects() {
        GameObject sonic = getGameObject( "Sonic" );
        sonic.update();
        GameObjectUtilities.reboundIfGameLayerExited(sonic);
    }
}