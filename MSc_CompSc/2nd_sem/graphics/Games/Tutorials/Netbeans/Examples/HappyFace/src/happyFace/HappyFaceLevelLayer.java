package happyFace;

import game.engine.*;
import game.assets.*;
import game.physics.*;
import game.components.TextElement;
import java.awt.Graphics2D;
import java.awt.Color;
import java.awt.geom.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;

/**
 * HappyFaceLevelLayer provides the core game layer for playing the HappyFace
 * game. Actual game levels extend this level, customising some parameters and
 * providing trigger actions.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.0 $ $Date: 2007/08 $
 */

public class HappyFaceLevelLayer extends CollisionSpace {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Define key bindings for actions specific to the HappyFaceLevelLayer,
     * i.e. keys for zooming in and out, toggle music playback and quitting
     * back to the main menu.
     */
    public static int ZOOM_IN_KEY = KeyEvent.VK_A;
    public static int ZOOM_OUT_KEY = KeyEvent.VK_S;
    public static int TOGGLE_MUSIC = KeyEvent.VK_M;
    public static int QUIT_TO_MENU = KeyEvent.VK_Q;

    /**
     * Define the different draw orders
     */
    public static final int BACKGROUND_DRAW_ORDER = 1;
    public static final int TEXTURE_DRAW_ORDER = 2;
    public static final int ITEM_DRAW_ORDER = 3;
    public static final int EMOTICON_DRAW_ORDER = 4;
    public static final int PLAYER_DRAW_ORDER = 5;
    public static final int EFFECT_DRAW_ORDER = 6;
    public static final int FOREGROUND_DRAW_ORDER = 7;

    /**
     * Define the percentge of the maximum level score
     * that must be gained before an award is issued.
     */
    public static final double GOLD_MEDAL_PERCENTAGE = 1.00;
    public static final double SILVER_MEDAL_PERCENTAGE = 0.80;
    public static final double BRONZE_MEDAL_PERCENTAGE = 0.50;

    /**
     * Define the layer size
     */
    protected static int LAYER_SIZE = 100000;
    
    /**
     * Variables defining the number of triggers alongside a boolean
     * array specifying the trigger is currently fired. A display
     * triggers play, if set, will result in the triggers being
     * displayed.
     */
    protected static int NUM_TRIGGERS = 30;
    protected boolean[] triggers = new boolean[NUM_TRIGGERS];
    private boolean DISPLAY_TRIGGERS = true;

    /**
     * Variables holding the player layer start position, alongside
     * the current player spawn position should they get killed.
     */
    protected double playerStartX, playerStartY;
    protected double playerSpawnX, playerSpawnY;

    /**
     * Level x and y position, alongside the end of level message
     * x and y offset relative to the exit position (i.e. the
     * end of level message can be positioned to avoid overlap,
     * etc.
     */
    protected double levelExitX, levelExitY;
    protected double levelExitMessageXOffset, levelExitMessageYOffset;

    /**
     * Viewport offset relative to the centre of the screen. By
     * varying the offset it is possible to adapt to levels where
     * the user generally moves upwards to downwards in terms of
     * displaying more of the screen.
     */
    protected int viewPortFocusXOffset, viewPortFocusYOffset;

    /**
     * Targets for the level, in terms of the number of emoticons
     * that need to be collected or killed before the player
     * can leave the level.
     */
    protected int targetNumEmoticonsToCollect;
    protected int targetNumEmoticonsToKill;
    protected int currentNumEmoticonsCollected;
    protected int currentNumEmoticonsKilled;

    /**
     * Level maximum possible score and currently level high score
     */
    protected int levelMaximumScore = 0;
    protected int levelHighScore = 0;
        
    /**
     * Name of the level
     */
    protected String levelName = "";

    /**
     * Flag determining if the level has exited, alongside the 
     * minimum amount of time that the end of level will be 
     * displayed for before the player can trigger a return to
     * the main menu.
     */
    protected boolean levelEnd = false;
    protected int levelEndMinimumTime = 120;

    /**
     * Flag specifying if level has been previously completed, 
     * alongside the highest award granted to the player
     */
    protected boolean levelCompleted = false;
    protected int levelAward = 0;

    /**
     * Default layer background colour
     */
    protected Color backgroundColor = Color.BLACK;

    /**
     * Text elements that can be used to generated both small
     * and large text messages
     */
    protected TextElement messageFont;
    protected TextElement messageFontLarge;
    
    /**
     * Variables that should be overloaded by extending layers
     * to specify the layer save file name, alongside the 
     * background sound asset and associated 8-bit volume.
     */
    protected String levelDataFileName = null;
    protected String backgroundMusicAssetName = null;
    protected int backgroundMusicVolume = 127;

    /**
     * Variable specifying if debug mode is currently on
     * (i.e. the player can teleport around, create bombs, etc.).
     */
    protected boolean debugMode = false;


    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new level layer
     */     
    public HappyFaceLevelLayer(GameEngine gameEngine) {
        super("LevelLayer", gameEngine, LAYER_SIZE, LAYER_SIZE);

        viewPortFocusXOffset = 0; viewPortFocusYOffset = 0;

        // Set up agressaggressive at rest parameters, i.e. a set of
        // relaxed conditions will be used when determining if
        // a body is at rest. This will help on levels where at
        // lot of bodies can be created (through explosions)
        // in terms of quickly reducing the cost of maintaining
        // arbiters.
        STATIONARY_VELOCITY_THRESHOLD = 15.0;
        STATIONARY_MOVEMENT_THRESHOLD = 10.0;
        STATIONARY_ROTATION_THRESHOLD = 0.05;
        STATIONARY_TICK_THRESHOLD = 50;

        // Define maximum travel and rotational velocities. This is 
        // needed to restrict movement speed (which helps with ensuring
        // appropriate collision resolution) given the strong gravitational
        // attraction.
        MAXIMUM_TRAVEL_VELOCITYX = 800.0;
        MAXIMUM_TRAVEL_VELOCITYY = 800.0;
        MAXIMUM_ANGULAR_VELOCITY = 25.0;
                
        // Add in the game object collections used within the layer
        addGameObjectCollection("Explosions");
        addGameObjectCollection("Emoticons");
        addGameObjectCollection("InteractingBodies");
        addGameObjectCollection("DecorativeAnimations");
        addGameObjectCollection("CollectableBodies");
        addGameObjectCollection("Triggers");

        // Create base text elements for creating textual messages
        messageFont = new game.components.TextElement(this, 
                (ImageAssetSequence) assetManager.retrieveAsset( "GUIFont" ), 0, 
                "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" + 
                "1234567890`!\"*$%^&*()-+={}[];:'@#~,.<>/\\?           ", "");

        messageFontLarge = new game.components.TextElement(this, (ImageAssetSequence) 
                assetManager.retrieveAsset( "GUIFontLarge" ), 0, 
                "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" + 
                "1234567890`!\"*$%^&*()-+={}[];:'@#~,.<>/\\?           ", "");

        // Define the gravitational strength
        this.setGravity(0.0, 800.0);
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Set/Get                                                      //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Set the level name to that specified
     */
    public void setLevelName(String levelName) {
        this.levelName = levelName;
    }

    /**
     * Return the level name
     */
    public String getLevelName() {
        return levelName;
    }
    
    /**
     * Set the level high score to that specified
     */
    public void setLevelHighScore(int levelHighScore) {
        this.levelHighScore = levelHighScore;
    }

    /**
     * Return the level high score
     */    
    public int getLevelHighScore() {
        return levelHighScore;
    }

    /**
     * Return true if the level has been previously completed
     */    
    public boolean getLevelCompleted() {
        return levelCompleted;
    }

    /**
     * Return the award, if any, given to the level
     */
    public int getLevelAward() {
        return levelAward;
    }

    /**
     * Specify if triggers are visually displayed or not
     */
    public void setDisplayTriggers(boolean displayTriggers) {
        DISPLAY_TRIGGERS = displayTriggers;
        GameObjectCollection triggerObjects = this.getGameObjectCollection("Triggers");
        for (int idx = 0; idx < triggerObjects.size; idx++) {
            ((Trigger) triggerObjects.gameObjects[idx]).setDisplayTrigger(displayTriggers);
        }
    }
    
    /**
     * Specify if the debug mode is on or off
     */
    public void setDebugMode(boolean debugMode) {
        this.debugMode = debugMode;

        if (debugMode) {
            gameEngine.setMouseCursor("MouseCrosshair", 15, 15);
            inputEvent.resetInputEvents();
        } else {
            gameEngine.setMouseCursor(null, 0, 0);
        }
    }
    
    /**
     * Place the player spawn at the specified location
     */
    public void placePlayerSpawnAtLocation(double x, double y) {
        playerSpawnX = x;
        playerSpawnY = y;
    }

    /**
     * Place the level exit at the specified location
     */
    public void placeLevelExitAtLocation(double x, double y) {
        GameObject levelExit = new GameObject(this);
        levelExit.setRealisationAndGeometry("LevelExit");
        levelExit.setPosition(x, y);
        levelExit.setDrawOrder(ITEM_DRAW_ORDER);
        levelExit.canIntersectOtherGraphicalObjects = false;
        addGameObject(levelExit);

        levelExitX = x;
        levelExitY = y;
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: State change                                                 //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Whenever this layer enters the visible state enable the level layer GUI
     */
    @Override
    protected void enterVisibleState() {
        super.enterInvisibleState();
        if (gameEngine.gameLayers.containsKey("LevelLayerGUI")) {
            gameEngine.getGameLayer("LevelLayerGUI").
                    setVisibility(GameLayer.GameLayerVisibility.VISIBLE);
        }
    }

    /**
     * Whenever this layer enters an invisible state hide the level layer GUI
     */
    @Override
    protected void enterInvisibleState() {
        super.enterInvisibleState();
        if (gameEngine.gameLayers.containsKey("LevelLayerGUI")) {
            gameEngine.getGameLayer("LevelLayerGUI").setVisibility(GameLayer.GameLayerVisibility.INVISIBLE);
        }
    }

    /**
     * Whenever this layer enters the active state activate the level layer GUI
     */
    @Override
    protected void enterActiveState() {
        super.enterActiveState();
        if (gameEngine.gameLayers.containsKey("LevelLayerGUI")) {
            gameEngine.getGameLayer("LevelLayerGUI").setActivity(GameLayer.GameLayerActivity.ACTIVE);
        }
    }

    /**
     * Whenever this layer enters an inactive state unactivate the level layer GUI
     */
    @Override
    protected void enterInactiveState() {
        super.enterInactiveState();
        if (gameEngine.gameLayers.containsKey("LevelLayerGUI")) {
            gameEngine.getGameLayer("LevelLayerGUI").setActivity(GameLayer.GameLayerActivity.INACTIVE);
        }
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods: Update                                                       //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Update the game state by check for user input and updating all 
     * interactive objects.
     */
    @Override
    public void update() {
        // Update the position, state, etc. of all objects and arbiters
        super.update();

        // If the level has ended then set the viewport and check if the
        // users wishes to return to the main menu
        if (levelEnd) {
            viewPortLayerX = levelExitX; viewPortLayerY = levelExitY;
            if (--levelEndMinimumTime <= 0) {
                if (levelEndMinimumTime == 0) {
                    // If the level minimum end time has just ellapsed, then
                    // clear any pending input events (i.e. waiting for the
                    // user's next input before returning
                    inputEvent.resetInputEvents();
                } else if (inputEvent.newKeyTyped()) {
                    quitLevel();
                }
            }
            return;
        }

        // Update all explosions
        GameObjectCollection explosions 
                = this.getGameObjectCollection("Explosions");
        for (int idx = 0; idx < explosions.size; idx++) 
            explosions.gameObjects[idx].update();

        // Update all emoticons
        GameObjectCollection emoticons 
                = this.getGameObjectCollection("Emoticons");
        for (int idx = 0; idx < emoticons.size; idx++) 
            emoticons.gameObjects[idx].update();

        // Update all interactive bodies
        GameObjectCollection interactingBodies 
                = this.getGameObjectCollection("InteractingBodies");
        for (int idx = 0; idx < interactingBodies.size; idx++)
            interactingBodies.gameObjects[idx].update();

        // Update all decorative animations
        GameObjectCollection decorativeAnimations 
                = this.getGameObjectCollection("DecorativeAnimations");
        for (int idx = 0; idx < decorativeAnimations.size; idx++)
            decorativeAnimations.gameObjects[idx].graphicalRealisation[0].update();

        // Update all collectable bodies
        GameObjectCollection collectableBodies 
                = this.getGameObjectCollection("CollectableBodies");
        for (int idx = 0; idx < collectableBodies.size; idx++)
            collectableBodies.gameObjects[idx].update();

        // Check if the player is in contact with another emoticon and, if so,
        // trigger appropriate action
        checkForPlayerToEmoticonCollision();

        // Consider layer specific input from the player 
        considerInput();

        if (getGameObject("Player") != null) {
            GameObject player = getGameObject("Player");

            // Update the player object, considering user input
            player.update();

            // Move and scale the viewport if needed. If the game is in 
            // debug mode then the scale factor is not restricted
            moveAndScaleViewportOnMouseInteraction();
            if (!debugMode) {
                if (drawScaleFactor < 0.5 * (gameEngine.screenWidth / 1920.0)) {
                    drawScaleFactor = 0.5 * (gameEngine.screenWidth / 1920.0);
                } else if (drawScaleFactor > 1.5) {
                    drawScaleFactor = 1.5;
                }
            }

            // Ensure the viewport remains centered on the player
            centerViewportOnGameObject(player, 
                    viewPortFocusXOffset, viewPortFocusYOffset, 
                    gameEngine.screenWidth / 4.0, gameEngine.screenHeight / 2.0);

            // Test each trigger to determine if an update is needed
            GameObjectCollection triggerObjects = this.getGameObjectCollection("Triggers");
            for (int idx = 0; idx < triggerObjects.size; idx++) {
                if (((Trigger) triggerObjects.gameObjects[idx]).isTriggeredBy(player)) {
                    if (triggers[idx] == false) {
                        // If the player has just entered into the trigger, then
                        // fire the trigger
                        triggers[idx] = true;
                        fireTrigger((Trigger) triggerObjects.gameObjects[idx]);
                    } else {
                        // If the player remains within the trigger, then
                        // continue firing the trigger
                        continueTrigger((Trigger) triggerObjects.gameObjects[idx]);
                    }
                } else if (triggers[idx] == true) {
                    // If the player has left the trigger, then cancel it
                    cancelTrigger((Trigger) triggerObjects.gameObjects[idx]);
                    triggers[idx] = false;
                }
            }

            // Every 1/2 second, check to see if the player has managed to reach
            // the level exit with the exit conditions met
            if (gameEngine.updateCounter % 30 == 0) {
                if (Math.abs(player.x - levelExitX) < 100 
                        && Math.abs(player.y - levelExitY) < 100 
                        && currentNumEmoticonsCollected >= targetNumEmoticonsToCollect 
                        && currentNumEmoticonsKilled >= targetNumEmoticonsToKill) {
                    exitLevel(true);
                    levelEnd = true;
                }
            }
        }
    }

    /**
     * Fire the specified trigger.
     * <P>
     * Note: It is intended that this method is overloaded within extending
     * classes to provide level specified behaviour
     */    
    protected void fireTrigger(Trigger trigger) { }

    /**
     * Continue the specified trigger.
     * <P>
     * Note: It is intended that this method is overloaded within extending
     * classes to provide level specified behaviour
     */    
    protected void continueTrigger(Trigger trigger) { }

    /**
     * Cancel the specified trigger.
     * <P>
     * Note: It is intended that this method is overloaded within extending
     * classes to provide level specified behaviour
     */    
    protected void cancelTrigger(Trigger trigger) { }

    /**
     * Consider layer specific player input
     */
    protected void considerInput() {
        // Zoom in or out if requested
        if (inputEvent.keyPressed[ZOOM_IN_KEY]) {
            drawScaleFactor *= 1.02;
        } else if (inputEvent.keyPressed[ZOOM_OUT_KEY]) {
            drawScaleFactor /= 1.02;
        }
        
        // Quit to the main menu, toggle debug mode or music playback
        // if requested        
        if (inputEvent.keyTyped(QUIT_TO_MENU)) {
            quitLevel();
        } else if (inputEvent.keyPressed[KeyEvent.VK_CONTROL] 
                && inputEvent.keyTyped(KeyEvent.VK_D)) {
            setDebugMode(!debugMode);
        } else if (inputEvent.keyTyped(TOGGLE_MUSIC)) {
            if (backgroundMusicAssetName != null) {
                MidiAsset backgroundMusic = (MidiAsset) assetManager
                        .retrieveAssetArchetype( backgroundMusicAssetName );
                if (backgroundMusic.getVolume() == 0) {
                    backgroundMusic.setVolume(backgroundMusicVolume);
                } else {
                    backgroundMusic.setVolume(0);
                }
            }
        }

        if (debugMode) {
            // If in debug mode and the LMB is clicked, then create
            // a large bomb at the player's location
            if (this.inputEvent.mouseClicked(MouseEvent.BUTTON1)) {
                GameObject player = getGameObject("Player");
                if (player == null)
                    return;

                ExplodingBody explosion = new ExplodingBody(this, 
                        player.x, player.y - player.height, 10, 
                        ExplodingBody.ExplosionBody.LargeBomb, 
                        ExplodingBody.ExplosionType.Large, 0.0, 0.0);
                explosion.igniteFuse();
                this.queueGameObjectToAdd(explosion, "Explosions");
            }

            // If in debug mode and the RMB is clicked, then teleport
            // the player to that location
            if (this.inputEvent.mouseClicked(MouseEvent.BUTTON3)) {
                placePlayerSpawnAtLocation(
                        getLayerPositionFromScreenX(inputEvent.mouseXCoordinate), 
                        getLayerPositionFromScreenY(inputEvent.mouseYCoordinate));
                spawnPlayer();
            }
        }
    }

    /**
     * Check for player collision with other emoticons and initiate 
     * appropriate action
     */
    protected void checkForPlayerToEmoticonCollision() {
        GameObject playerGameObject = getGameObject("Player");
        if (playerGameObject == null) 
            return;

        GameObjectCollection emoticons = getGameObjectCollection("Emoticons");
        for (int idx = 0; idx < emoticons.size; idx++) {
            Emoticon emoticon = (Emoticon) emoticons.gameObjects[idx];

            // If needed, ensure that the emoticon can intersect the player    
            boolean etheralEmoticon = false;
            if( !emoticon.emoticonDead && !emoticon.emoticonRelease &&
                    emoticon.canIntersectOtherGraphicalObjects == false ) {
                etheralEmoticon = true;
                emoticon.canIntersectOtherGraphicalObjects = true;
            }
            
            if (GameObjectCollider.isIntersection(playerGameObject, emoticons.gameObjects[idx])) {
                EmoticonPlayer player = (EmoticonPlayer) playerGameObject;

                // If the player has collided with a happy emoticon, then test
                // if the player has hit the other emoticon (is above it)
                // or if the emoticon has hit the player. Update the health
                // of the hit object and if killed take appropriate action
                if (emoticon.isHappyEmoticon()) {
                    if (player.y + player.height / 4.0 < emoticon.y) {
                        if( player.canAttack() ) {
                            assetManager.retrieveSoundAssetArchetype(
                                    emoticon.getHitSoundEffect()).play();

                            emoticon.subHealth(player.collisionDamage);
                            if (emoticon.health <= 0) {
                                emoticon.triggerEmoticonDeath();
                            }
                            
                            player.hasAttacked();
                        }                        
                    } else {
                        if( emoticon.canAttack() ) {
                            assetManager.retrieveSoundAssetArchetype(
                                    player.getHitSoundEffect()).play();

                            player.subHealth(emoticon.collisionDamage);
                            if (player.health <= 0) {
                                player.triggerEmoticonDeath();
                            }                        
                            
                            emoticon.hasAttacked();
                        }
                    }
                    
                    // Invert the velocity if it an etheral emoticon, i.e.
                    // move it away from the player, otherwise it will
                    // likely remain in contact with the player
                    if( etheralEmoticon) {
                        emoticon.velocityx = -2.0*emoticon.velocityx;
                        emoticon.velocityy = -2.0*emoticon.velocityy;
                    }                    
                // If an unhappy emoticon has been touched then free it
                } else {                    
                    emoticon.triggerEmoticonRelease();
                    assetManager.retrieveSoundAssetArchetype("EmoticonRescue").play();
                    currentNumEmoticonsCollected++;
                }
            }
            
            if( etheralEmoticon )
                emoticon.canIntersectOtherGraphicalObjects = false;            
        }
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods: Layer actions                                                //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Setup the level ready for play. This method should be called every time
     * the level is started
     */    
    public void setupLevel() {
        // Clear any queued input
        gameEngine.inputEvent.resetInputEvents();
        
        // If specified, play the background music
        if( backgroundMusicAssetName != null )
            ((MidiAsset)assetManager.
                    retrieveAssetArchetype( backgroundMusicAssetName )).play();
        
        // If level data has been specified, then load it
        if( levelDataFileName != null )
            loadState( getClass().getResource( levelDataFileName ) );

        // Do not display triggers by default
        setDisplayTriggers( false );
        
        // Change the volume of the background music playback if needed.
        // Note: It is important that this change is here. Whenever MIDI 
        // playback starts it takes a small amount of time needed to
        // start the sequencers, etc. Before playback has started, any
        // attempt to change the volume will have no effect. Because of the
        // above, a volume change is only permitted following the load of
        // the level data (which should, I hope, introduce a sufficiently
        // long delay to permit playback to start).        
        if( backgroundMusicAssetName != null )
            ((MidiAsset)assetManager.retrieveAssetArchetype( backgroundMusicAssetName ))
            .setVolume( backgroundMusicVolume );
        
        // If a level layer GUI has not already been added, create and add
        // the level GUI 
        if( gameEngine.gameLayers.containsKey( "LevelLayerGUI" ) == false ) {
            HappyFaceLevelLayerGUI levelLayerGUI 
                    = new HappyFaceLevelLayerGUI( gameEngine );
            levelLayerGUI.setDrawOrder( getDrawOrder()+1 );
            gameEngine.addGameLayer( levelLayerGUI );
        }

        // If game object collections do not exist, then add them
        if( !gameObjectCollections.containsKey( "Explosions" ) )
            addGameObjectCollection( "Explosions" );
        if( !gameObjectCollections.containsKey( "Emoticons" ) )
            addGameObjectCollection( "Emoticons" );
        if( !gameObjectCollections.containsKey( "InteractingBodies" ) )
            addGameObjectCollection( "InteractingBodies" );
        if( !gameObjectCollections.containsKey( "DecorativeAnimations" ) )
            addGameObjectCollection( "DecorativeAnimations" );
        if( !gameObjectCollections.containsKey( "CollectableBodies" ) )
            addGameObjectCollection( "CollectableBodies" );
        if( !gameObjectCollections.containsKey( "Triggers" ) )
            addGameObjectCollection( "Triggers" );
        
        // Initially set the player spawn location to the level start location
        playerSpawnX = playerStartX;
        playerSpawnY = playerStartY;

        // Reset the level exit offset and level end flag and count down time
        levelExitMessageXOffset = 0.0;
        levelExitMessageYOffset = 0.0;        
        levelEnd = false;
        levelEndMinimumTime = 120;

        // Reset the number of killed and collected emoticons
        currentNumEmoticonsCollected = 0;
        currentNumEmoticonsKilled = 0;

        // Reset each of the triggers
        for( int idx = 0; idx < triggers.length; idx++ )
            triggers[idx] = false;
    }

    /**
     * Load in the level data from the specified file
     */
    protected void loadState(URL loadFilename) {
        try {
            ObjectInputStream inputFile 
                    = new ObjectInputStream(loadFilename.openStream());

            // Clear existing layer of all bodies
            this.removeAllBodiesAndJoints();

            // Reset the level maximum score (this will be updated as
            // objects containing a score are loaded)
            levelMaximumScore = 0;

            int numBodiesToLoad = inputFile.readInt();
            for (int bodyIdx = 0; bodyIdx < numBodiesToLoad; bodyIdx++) {
                // Load in the next game object
                GameObject loadedObject 
                        = GameObjectSerialiser.loadGameObject(inputFile, this);

                // Based on the game object collection that the loaded game
                // object belongs to add the game object to the appropriate
                // game object collection for the level
                if (loadedObject.getGameObjectCollection().
                        gameObjectCollectionName.compareTo("StaticObjects") == 0) {
                    if (loadedObject.graphicalRealisation[0] instanceof ImageAssetSequence) {
                        addGameObject(loadedObject, "DecorativeAnimations");
                    } else {
                        addGameObject(loadedObject);
                    }
                } else if (loadedObject.getGameObjectCollection().
                        gameObjectCollectionName.compareTo("InteractiveObjects") == 0) {
                    if (loadedObject instanceof Emoticon) {
                        addGameObject(loadedObject, "Emoticons");
                        levelMaximumScore += ((Emoticon) loadedObject).getPoints();
                    } else if (loadedObject instanceof InteractingBody) {
                        addGameObject(loadedObject, "InteractingBodies");
                    } else if (loadedObject instanceof CollectableBody) {
                        addGameObject(loadedObject, "CollectableBodies");
                        levelMaximumScore += ((CollectableBody) loadedObject).getPoints();
                    } else {
                        addGameObject(loadedObject);
                    }
                } else {
                    throw new IllegalStateException(
                            "LevelLayer.loadState: Unknown collection type");
                }
            }

            // Load in any joints
            int numJointsToLoad = inputFile.readInt();
            for (int jointIdx = 0; jointIdx < numJointsToLoad; jointIdx++) 
                GameObjectSerialiser.loadJointIntoLayer(inputFile, this);

            // Load in any triggers
            int numTriggersToLoad = inputFile.readInt();
            for (int triggerIdx = 0; triggerIdx < numTriggersToLoad; triggerIdx++) {
                GameObject trigger = GameObjectSerialiser.loadGameObject(inputFile, this);
                ((Trigger) trigger).setDisplayTrigger(DISPLAY_TRIGGERS);
                addGameObject(trigger);
            }

            // Load in the playe start position if needed
            if (inputFile.readBoolean() == true) {
                playerStartX = inputFile.readDouble();
                playerStartY = inputFile.readDouble();
                placePlayerSpawnAtLocation(playerStartX, playerStartY);
                spawnPlayer();
            }

            // Load in the level exit position if needed
            if (inputFile.readBoolean() == true) {
                placeLevelExitAtLocation(inputFile.readDouble(), inputFile.readDouble());
            }
            
            inputFile.close();
        } catch (IOException ioException) {
            System.err.println("Error loading from file: " + ioException.toString());
            ioException.printStackTrace();
        }
    }

    /**
     * Spawn the player
     */
    public void spawnPlayer() {
        Emoticon player = (Emoticon) getGameObject( "Player" );

        if (player != null) {
            player.x = playerSpawnX;
            player.y = playerSpawnY;
        } else {
            player = new EmoticonPlayer(
                    this, "EmoticonDevil", playerSpawnX, playerSpawnY, 3);
            player.setName("Player");
            queueGameObjectToAdd(player);
        }

        viewPortLayerX = player.x;
        viewPortLayerY = player.y;
    }

    /**
     * Consider the death of the player, i.e. spawning the player or 
     * exiting the level
     */    
    public void considerPlayerDeath() {
        EmoticonPlayer player = (EmoticonPlayer) getGameObject( "Player" );

        if (player.numPlayerLifes > 0) {
            spawnPlayer();
        } else {
            exitLevel(false);
        }
    }

    /**
     * Setup the level exit display - showing the score, success, and any 
     * high score/associated medal
     */
    protected void exitLevel(boolean levelCompleted) {
        EmoticonPlayer player = (EmoticonPlayer) getGameObject( "Player" );

        // If this is the first time this level has been completed, then
        // update the level completed flag
        if (this.levelCompleted == false && levelCompleted == true) 
            this.levelCompleted = true;

        // Remove the player, reset the scale factor and set the viewport
        // to the level exit location
        queueGameObjectToRemove(player);
        drawScaleFactor = 1.0;
        viewPortLayerX = levelExitX;
        viewPortLayerY = levelExitY;
        validateViewPort();
        
        double displayX = getLayerPositionFromScreenX(gameEngine.screenWidth / 2);
        double displayY = getLayerPositionFromScreenY(gameEngine.screenHeight / 2);

        // Display a success message
        int offsetY = (int) levelExitMessageYOffset;
        if (levelCompleted) {
            offsetY += addLargeMessage("GameOverMessage", 
                    "Level Completed", displayX + levelExitMessageXOffset, displayY + offsetY);
        } else {
            offsetY += addLargeMessage("GameOverMessage", 
                    "Game Over", displayX + levelExitMessageXOffset, displayY + offsetY);
        }
        offsetY += 40;

        // If the level has been completed then display the score (and any 
        // associated medal)
        if (levelCompleted) {
            if ((double) player.getScore() / (double) levelMaximumScore 
                    >= GOLD_MEDAL_PERCENTAGE) {
                GameObject goldMedal = new GameObject(
                        this, displayX + levelExitMessageXOffset + 350, 
                        displayY + offsetY - 170.0, FOREGROUND_DRAW_ORDER);
                goldMedal.setRealisationAndGeometry("GoldMedal");
                queueGameObjectToAdd(goldMedal);
                levelAward = 3;
            } else if ((double) player.getScore() / (double) levelMaximumScore 
                    >= SILVER_MEDAL_PERCENTAGE) {
                GameObject silverMedal = new GameObject(
                        this, displayX + levelExitMessageXOffset + 350, 
                        displayY + offsetY - 170.0, FOREGROUND_DRAW_ORDER);
                silverMedal.setRealisationAndGeometry("SilverMedal");
                queueGameObjectToAdd(silverMedal);
                if (levelAward < 2) {
                    levelAward = 2;
                }
            } else if ((double) player.getScore() / (double) levelMaximumScore >= 
                    BRONZE_MEDAL_PERCENTAGE) {
                GameObject bronzeMedal = new GameObject(
                        this, displayX + levelExitMessageXOffset + 350, 
                        displayY + offsetY - 170.0, FOREGROUND_DRAW_ORDER);
                bronzeMedal.setRealisationAndGeometry("BronzeMedal");
                queueGameObjectToAdd(bronzeMedal);
                if (levelAward < 1) {
                    levelAward = 1;
                }
            }

            // Display a high score message
            if (player.getScore() > levelHighScore) {
                levelHighScore = player.getScore();
                offsetY += addLargeMessage("HighScoreMessage1", 
                        "Welcome done! New high score", 
                        displayX + levelExitMessageXOffset, displayY + offsetY);
            } else {
                offsetY += addLargeMessage("HighScoreMessage1", 
                        "Previous best of " + levelHighScore + " unbeaten", 
                        displayX + levelExitMessageXOffset, displayY + offsetY);
            }
        }

        // Display the score
        offsetY += addLargeMessage("GameOverScore", "Score " + 
                player.getScore() + " of a maximum " + levelMaximumScore, 
                displayX + levelExitMessageXOffset, displayY + offsetY);

        // Display a game object message
        addMessage("GameOverReturn", "<Press any key to continue>", 
                displayX + levelExitMessageXOffset, displayY + offsetY);

        levelEnd = true;
    }

    /**
     * Quit this level, hiding it and return to an appropriate menu layer
     */
    protected void quitLevel() {
        removeAllGameObjects();

        this.setVisibility(HappyFaceLevelLayer.GameLayerVisibility.INVISIBLE);
        this.setActivity(HappyFaceLevelLayer.GameLayerActivity.INACTIVE);

        if (gameEngine.gameLayers.containsKey("BuilderControlLayer")) {
            GameLayer builderControlLayer = gameEngine.getGameLayer("BuilderControlLayer");
            builderControlLayer.setVisibility(HappyFaceLevelLayer.GameLayerVisibility.VISIBLE);
            builderControlLayer.setActivity(HappyFaceLevelLayer.GameLayerActivity.ACTIVE);

            GameLayer builderLayer = gameEngine.getGameLayer("BuilderLayer");
            builderLayer.setVisibility(HappyFaceLevelLayer.GameLayerVisibility.VISIBLE);
            builderLayer.setActivity(HappyFaceLevelLayer.GameLayerActivity.ACTIVE);

            ((HappyFaceBuilderLayer) builderLayer).initialiseBuilderReturn();
        } else {
            GameLayer menuLayer = gameEngine.getGameLayer("HappyFaceMenuLayer");
            menuLayer.setVisibility(HappyFaceLevelLayer.GameLayerVisibility.VISIBLE);
            menuLayer.setActivity(HappyFaceLevelLayer.GameLayerActivity.ACTIVE);

            gameEngine.removeGameLayer(this.gameLayerName);
        }
    }        
    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Miscellaneous                                                //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create and add the specified message at the specified location
     */
    protected int addMessage(String messageName, 
            String messageText, double x, double y) {
        TextElement message = messageFont.getMatchingElement(messageText);
        message.setName(messageName);
        message.setPosition(x, y);
        message.setDrawOrder(100);
        queueGameObjectToAdd(message);
        return (int) message.height;
    }

    /**
     * Create and add the specified large message at the specified location
     */
    protected int addLargeMessage(String messageName, 
            String messageText, double x, double y) {
        TextElement message = messageFontLarge.getMatchingElement(messageText);
        message.setName(messageName);
        message.setPosition(x, y);
        message.setDrawOrder(100);
        queueGameObjectToAdd(message);
        return (int) message.height;
    }

    /**
     * Draw the level layer
     */
    @Override
    public void draw(Graphics2D graphics2D) {
        Color originalColour = graphics2D.getColor();
        graphics2D.setColor(backgroundColor);
        graphics2D.fillRect(0, 0, gameEngine.screenWidth, gameEngine.screenHeight);
        graphics2D.setColor(originalColour);

        super.draw(graphics2D);
    }
    
    /**
     * This method is automatically called whenever a body within the layer
     * is broken. If the broken body is not an emoticon then a check is
     * made to see what broken and into how many pieces. An appropriate
     * sound effect is then played.
     * 
     */    
    @Override
    protected void bodyBrokenOrDestroyed(Body body, int resultantBodies) {
        if (body instanceof Emoticon == false) {
            if (body.graphicalRealisation.length > 0 
                    && body.graphicalRealisation[0].getAssetName().indexOf("Edging") >= 0) {
                assetManager.retrieveSoundAssetArchetype(
                        "EdgeCrack" + (gameEngine.randomiser.nextInt(3) + 1)).play();
            } else {
                int numSmallCrackSounds = (resultantBodies % 10) / 2;
                int numLargeCrackSounds = (resultantBodies % 20) / 5;

                if (numSmallCrackSounds == 0 && numLargeCrackSounds == 0) {
                    numSmallCrackSounds = 1;
                }
                for (int idx = 0; idx < numSmallCrackSounds; idx++) {
                    assetManager.retrieveSoundAssetArchetype(
                            "RockCrackLarge" + (gameEngine.randomiser.nextInt(8) + 1)).play();
                }
                for (int idx = 0; idx < numLargeCrackSounds; idx++) {
                    assetManager.retrieveSoundAssetArchetype(
                            "RockCrackSmall" + (gameEngine.randomiser.nextInt(8) + 1)).play();
                }
            }
        }
    }
}