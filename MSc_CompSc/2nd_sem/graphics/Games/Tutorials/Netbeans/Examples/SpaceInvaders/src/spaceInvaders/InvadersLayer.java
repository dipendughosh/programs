package spaceInvaders;

import game.assets.ImageAssetRibbon;
import game.engine.*;
import java.awt.Graphics2D;
import java.awt.Color;
import java.awt.event.KeyEvent;
import java.util.*;

/**
 * Core game layer within the space invaders game (i.e. the layer which contains
 * the game itself). This layer contains the core game update loop and game logic.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2006/08 $
 */

public class InvadersLayer extends GameLayer {

    ///////////////////////////////////////////////////////////////////////////
    // Class data:                                                           //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Variables which define the minimum speed for the alien army (when all the
     * aliens are on the screen) and the maximum speed (approached as the number
     * of alien remaining decreases). This models the increase in speed of the
     * original space invaders game.
     */
    private static double ALIEN_ARMY_MAX_SPEED = 4.0;
    private static double ALIEN_ARMY_MIN_SPEED = 2.0;

    /**
     * Variables which define the base fire probability for a level and the
     * maximum fire probability, approached as the number of aliens within
     * the army decreases. The numbers represent a 1-in chance that an
     * alien ship will fire per update turn, i.e. a value of 500 with a ups
     * of 60 means each alien will fire once every 8ish seconds.
     */
    private static int ALIEN_ARMY_BASE_FIRE_LIKELIHOOD = 500;
    private static int ALIEN_ARMY_MAX_FIRE_LIKELIHOOD = 20;

    /**
     * 1-in chance of the alien mothership appearing per update turn.
     * Only one mothership can be on the screen at any time.
     */
    private static int MOTHERSHIP_APPEAR_LIKELIHOOD = 350;

    /**
     * Width and height of the alien army (in terms of the number
     * of alien ships)
     */
    private static final int ALIEN_ARMY_WIDTH = 8;
    private static final int ALIEN_ARMY_HEIGHT = 6;

    /**
     * Variables that determine how much the alien army comes down the
     * screen once it hits the side. The total drop in terms of pixels
     * is ALIEN_Y_DROP_INCREMENT * ALIEN_Y_DROP_NUMBER, i.e.
     * ALIEN_Y_DROP_INCREMENT determine how much the aliens come down
     * per update and ALIEN_Y_DROP_NUMBER determine the number of
     * game updates for which the aliens will move down.
     */
    private static final double ALIEN_Y_DROP_INCREMENT = 2.0;
    private static final double ALIEN_Y_DROP_NUMBER = 10.0;

    /**
     * Number of player bases included within the game (bases will be
     * equally spaced across the screen). It is recommended that an
     * off number of bases be used to ensure a base is placed in the
     * middle of the screen (thereby providing a 'safe' spot for the
     * player ship to respawn once destroyed).
     */
    private static final int NUMBER_OF_BASES = 3;

    /**
     * Transitional variables that determine the current movement pattern
     * of the alien army. alienShipXVelDirection specifies if the army
     * is moving in a positive or a negative x-direction. alienShipXVel
     * specifies the number of pixels moved in an update (Note: as the speed
     * is an integer, it enforces a minimum speed upon the game (i.e.
     * number of pixels / second) additionally, going to a value of 2 will
     * double this speed. This is a simple approach, and not an ideal
     * approach. We will explore fractional speeds in the next case study).
     * alienShipTotalNumberYDrop is used to record if the alien army
     * is currently moving down the screen and alienShipFireLikelihood
     * record the current 1-in chance of each ship firing a missile per update.
     */
    private double alienShipXVelDirection = 1;
    private double alienShipXVel = 1;
    private int alienShipTotalNumberYDrop = 0;
    private int alienShipFireLikelihood = ALIEN_ARMY_BASE_FIRE_LIKELIHOOD;

    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new invaders layers (which initialises and starts the game
     * running).
     *
     * @param  gameEngine GameEngine instance to which this layer is to be added
     */
    public InvadersLayer(GameEngine gameEngine) {
        super("InvadersLayer", gameEngine);

        // Set the width and height of this layer to that of the full screen
        width = gameEngine.screenWidth;
        height = gameEngine.screenHeight;

        // Create a total of four game object sets to hold common object
        // collections, i.e. bases, alien ships/missiles and explosions. Created
        // as such, each game object set provides a ready means of iterating
        // over all game objects with a common purpose.
        addGameObjectCollection("Bases");
        addGameObjectCollection("AlienShips");
        addGameObjectCollection("AlienMissiles");
        addGameObjectCollection("Explosions");

        // Create the background objects to be used within the game
        createBackgroundObjects();

        // Create the requested number of bases equally spaced across the screen
        for (int baseIdx = 0; baseIdx < NUMBER_OF_BASES; baseIdx++) {
            Base base = new Base(this, 0, 0);
            base.x = (gameEngine.screenWidth / (NUMBER_OF_BASES + 1)) * (baseIdx + 1);
            base.y = gameEngine.screenHeight - base.height / 2 - 10;
            addGameObject(base, "Bases");
        }

        // Create the initial alien army (separate the army into two groupings
        // with the upper half using one type of graphical realisation and
        // the bottom half a different realisation.
        for (int widthIdx = 0; widthIdx < ALIEN_ARMY_WIDTH; widthIdx++) {
            for (int heightIdx = 0; heightIdx < ALIEN_ARMY_HEIGHT; heightIdx++) {
                AlienShip alienShip = new AlienShip(
                        this, heightIdx * 2 < ALIEN_ARMY_HEIGHT ? 0 : 1, 0, 0);
                alienShip.x = widthIdx * (alienShip.width + 15) + 50;
                alienShip.y = heightIdx * (alienShip.height + 5) + 100;
                addGameObject(alienShip, "AlienShips");
            }
        }
        // Add in the player ship
        addGameObject(new PlayerShip(this, width / 2, height - 15));

        // Create the overlay objects, e.g. score, etc.
        createOverlayObjects();
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods: Layer initialisation                                         //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create background objects (i.e. scrolling sky and fixed mountains)
     */
    private void createBackgroundObjects() {
        GameObject backgroundSky = new GameObject(this);
        backgroundSky.setName("BackgroundSky");
        backgroundSky.setRealisationAndGeometry("BackgroundSky");
        backgroundSky.x = this.width / 2;
        backgroundSky.y = backgroundSky.height / 2;
        backgroundSky.setDrawOrder(0);
        addGameObject(backgroundSky);

        GameObject backgroundMountains = new GameObject(this);
        backgroundMountains.setRealisationAndGeometry("BackgroundMountains");
        backgroundMountains.x = this.width / 2;
        backgroundMountains.y = this.height - backgroundMountains.height / 2;
        backgroundMountains.setDrawOrder(1);
        addGameObject(backgroundMountains);
    }

    /**
     * Create overlay objects (i.e. lifes and score)
     */
    private void createOverlayObjects() {
        Lifes lifes = new Lifes(this, 0, 0);
        lifes.x = lifes.width / 2;
        lifes.y = lifes.height / 2;
        addGameObject(lifes);

        Score score = new Score(this, 0, 0);
        score.x = this.width - score.width / 2;
        score.y = score.height / 2;
        addGameObject(score);
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods: Game update                                                  //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Central update loop called by the game engine
     */
    @Override
    public void update() {
        // Scroll the background if needed
        updateBackground();

        // Update the player ship and any fired missiles
        updatePlayerShip();
        updatePlayerMissile();

        // Update the alien ships and any fired missiles
        updateMothership();
        updateAlienShips();
        updateAlienMissiles();

        // Update the score if needed
        updateScore();

        // Update any on-screen explosions
        updateExplosions();

        // If any game objects were queued to be either added or
        // removed then do so by calling the inherited update method
        super.update();
    }

    /**
     * Update the background, i.e. every other update tick scroll the background
     * sky 1 pixel to the left.
     */
    private void updateBackground() {
        if ((gameEngine.updateCounter) % 2 == 0) {
            GameObject backgroundSky = getGameObject("BackgroundSky");
            ((ImageAssetRibbon) backgroundSky.getRealisation(0)).moveViewPortLeft(1);
        }
    }

    /**
     * Update the playership, i.e. consider the current input state and update
     * the player ship accordingly
     */
    private void updatePlayerShip() {
        // We may not have a player ship on screen if it has been destroyed
        if (gameObjects.containsKey("PlayerShip") == false)
            return;

        PlayerShip playerShip = (PlayerShip) getGameObject("PlayerShip");

        if (gameEngine.inputEvent.keyPressed[KeyEvent.VK_LEFT]) {
            playerShip.x -= playerShip.xVel;
            if (playerShip.x - playerShip.width / 2 < 0 ) {
                playerShip.x = playerShip.width / 2;
            }
        }

        if (gameEngine.inputEvent.keyPressed[KeyEvent.VK_RIGHT]) {
            playerShip.x += playerShip.xVel;
            if (playerShip.x + playerShip.width / 2 > this.width) {
                playerShip.x = this.width - playerShip.width / 2;
            }
        }

        if (gameEngine.inputEvent.keyPressed[KeyEvent.VK_SPACE]) {
            // As with the original game of space invaders, we only fire a missile
            // when we don't have any other missiles on screen. I'm unsure if this
            // was an intended design aspect of the original space invaders, but
            // it is a good mechanism as it means every shot counts and missing a
            // shot incurs a small penalty (i.e. the player can't fire until the
            // missile has left the screen).
            if ( getGameObject("PlayerMissile") == null ) {
                queueGameObjectToAdd(new PlayerMissile(this, 
                        playerShip.x, playerShip.y - playerShip.height / 2));
            }
        }
    }

    /**
     * Update the player missile if it currently exists
     */
    private void updatePlayerMissile() {
        // Return if no player missile currently exists within the layer
        if (getGameObject("PlayerMissile") == null)
            return;

        PlayerMissile playerMissile = (PlayerMissile) getGameObject("PlayerMissile");
        playerMissile.y += playerMissile.yVel;

        playerMissile.getRealisation(0).update();

        if (playerMissile.y + playerMissile.height / 2 < 0) {
            // Delete the missile as soon as it leaves the screen
            queueGameObjectToRemove(playerMissile);
        } else {
            // Iterate over all the current alien ships and determine if the player
            // missile has hit the alien ships (in which case, increase the player's
            // score, create an explosion effect and queue both the alien ship and
            // player missile for removal. If no more no aliens exist following
            // a missile hit, then finish the level.
            // Note: As it is possible for a player missile to 'hit' more than one
            // alien ship, i.e. it may have a vertical overlap touching upon two
            // ships, each missile is limited to only removing a single alien ship.
            GameObjectCollection alienShips = getGameObjectCollection("AlienShips");
            for (int idx = 0; idx < alienShips.size; idx++) {
                AlienShip alienShip = (AlienShip) alienShips.gameObjects[idx];
                if (!playerMissile.hasAlreadyHit() && 
                        GameObjectCollider.isIntersection(playerMissile, alienShip)) {
                    addScore(alienShip.score);

                    queueGameObjectToAdd(new Explosion(
                            this, alienShip.x, alienShip.y), "Explosions");
                    queueGameObjectToRemove(alienShip);
                    queueGameObjectToRemove(playerMissile);

                    playerMissile.recordHasHit();

                    if (gameObjectCollections.get("AlienShips").size() == 1) {
                        allAliensDestroyed();
                    }
                }
            }

            // Iterate over all bases and determine if the missile has hit a base
            // in which case the base should be eroded and the missile destroyed.
            // Note: It is possible for a missile to pass through a base object
            // without actually hitting anything, i.e. all of the base in the
            // missile's path has already been destroyed.
            GameObjectCollection bases = getGameObjectCollection("Bases");
            for (int idx = 0; idx < bases.size; idx++) {
                Base base = (Base) bases.gameObjects[idx];
                if (GameObjectCollider.isIntersection(playerMissile, base)) {
                    if (base.erodeBase(playerMissile)) {
                        queueGameObjectToRemove(playerMissile);
                    }
                }
            }

            // Test to see if the player missile has hit the alien mothership.
            // If it has, then increase the player's score, add an explosion and remove
            // both the mothership and the missile.
            // Note: within the case study the mothership sound effect is not
            // encapsulated within the mothership object (it probably should be). Because
            // of this, we also have to remember to stop the siren sound alert used
            // by the mothership.
            if (getGameObject("MotherShip") != null) {
                MotherShip motherShip = (MotherShip) getGameObject("MotherShip");
                if (GameObjectCollider.isIntersection(playerMissile, motherShip)) {
                    addScore(motherShip.score);

                    queueGameObjectToAdd(new Explosion(
                            this, motherShip.x, motherShip.y), "Explosions");
                    queueGameObjectToRemove(motherShip);
                    queueGameObjectToRemove(playerMissile);

                    assetManager.retrieveSoundAssetArchetype("MothershipSfx").stop();
                }
            }
        }
    }

    /**
     * Update the alien mothership, in particular, determine if the mothership should
     * appear if it is not already on screen or determine if the mothership should
     * be removed if it has just left the screen.
     */
    private void updateMothership() {
        if (getGameObject("MotherShip") != null) {
            MotherShip motherShip = (MotherShip) getGameObject("MotherShip");
            motherShip.x += motherShip.xVel;

            motherShip.getRealisation(0).update();

            if (motherShip.x + motherShip.width / 2 < 0 
                    || motherShip.x - motherShip.width / 2 > this.width) {
                queueGameObjectToRemove(motherShip);
                assetManager.retrieveSoundAssetArchetype("MothershipSfx").stop();
            }
        } else {
            if (gameEngine.randomiser.nextInt(MOTHERSHIP_APPEAR_LIKELIHOOD) == 0) {
                queueGameObjectToAdd(new MotherShip(this));
                assetManager.retrieveSoundAssetArchetype("MothershipSfx").play();
            }
        }
    }

    /**
     * Update the alien ship army, in particular update the movement and fire
     * probabilities (i.e. as the number of ships decrease, remaining ships move
     * faster and fire more often). Also update the position of the alien ships
     * and determine if they will fire a missile. Finally, check to see if any
     * alien ship has collided with the player ship, in which case it's game
     * over for the player.
     * Note: OK, the functionality here does differ somewhat from the original
     * game as we're not worrying about eroding the bases when the alienship 
     * 'hits' them. This is left as an exercise for the reader (what a great
     * way of offloading laziness on my behalf!).
     */
    private void updateAlienShips() {
        // If the alien army is currently not moving down the screen, then
        // check to see if any alien has 'hit' the side of the screen.
        boolean alienShipSideHit = false;
        if (alienShipTotalNumberYDrop == 0) {
            GameObjectCollection alienShips = this.getGameObjectCollection("AlienShips");
            for (int idx = 0; idx < alienShips.size; idx++) {
                AlienShip alienShip = (AlienShip) alienShips.gameObjects[idx];
                if (alienShip.x - alienShip.width / 2 < 0 
                        || alienShip.x + alienShip.width / 2 >= this.width) {
                    alienShipSideHit = true;
                }
            }
        }

        // If the alien army has just hit the side or are currently moving down
        // the screen then update the relevant variables. If the alien army has
        // reached of the bottom of their downward movement, then get them moving
        // left or right again.
        if (alienShipSideHit || alienShipTotalNumberYDrop > 0) {
            alienShipTotalNumberYDrop++;

            if (alienShipTotalNumberYDrop >= ALIEN_Y_DROP_NUMBER) {
                alienShipXVelDirection = -alienShipXVelDirection;
                alienShipTotalNumberYDrop = 0;
            }
        }

        // Update the current alien army movement and fire probabilities to make
        // the level more challenging as the number of aliens is reduced.
        if (gameObjectCollections.get("AlienShips").size() > 0) {
            double alienShipRatio = (double) ((ALIEN_ARMY_WIDTH*ALIEN_ARMY_HEIGHT-1) 
                                    - (gameObjectCollections.get( "AlienShips" ).size()-1)) 
                                        / (double) (ALIEN_ARMY_WIDTH*ALIEN_ARMY_HEIGHT-1);

            alienShipXVel = ALIEN_ARMY_MIN_SPEED + 
                    ((ALIEN_ARMY_MAX_SPEED - ALIEN_ARMY_MIN_SPEED) * alienShipRatio);

            alienShipFireLikelihood = ALIEN_ARMY_BASE_FIRE_LIKELIHOOD - (int) 
                    ((ALIEN_ARMY_BASE_FIRE_LIKELIHOOD - ALIEN_ARMY_MAX_FIRE_LIKELIHOOD) 
                        * alienShipRatio);
        }

        // Update the x and y position of each alien ship and consider if they
        // will fire a new missile or have hit with the player ship.
        PlayerShip playerShip = (PlayerShip) getGameObject("PlayerShip");
        GameObjectCollection alienShips = getGameObjectCollection("AlienShips");
        for (int idx = 0; idx < alienShips.size; idx++) {
            AlienShip alienShip = (AlienShip) alienShips.gameObjects[idx];

            alienShip.getRealisation(0).update();

            if (alienShipTotalNumberYDrop > 0) {
                alienShip.y += ALIEN_Y_DROP_INCREMENT;
            } else {
                alienShip.x += alienShipXVel * alienShipXVelDirection;
            }
            
            if (gameEngine.randomiser.nextInt(alienShipFireLikelihood) == 0) {
                queueGameObjectToAdd(new AlienMissile(
                        this, alienShip.x, alienShip.y), "AlienMissiles");
            }

            if (playerShip != null 
                    && GameObjectCollider.isIntersection(alienShip, playerShip)) {
                Lifes lifes = (Lifes) getGameObject("Lifes");
                while (lifes.getNumberOfLifes() > 0) {
                    lifes.decrementLifes();
                }
                playerShipDestroyed();
            }
        }
    }

    /**
     * Update the alien missiles, in particular determine if the missile has left
     * the screen, hit a base, or hit the player. In all cases the missile will be
     * destroyed.
     */
    private void updateAlienMissiles() {
        PlayerShip playerShip = (PlayerShip) getGameObject( "PlayerShip" );
        GameObjectCollection alienMissiles = getGameObjectCollection("AlienMissiles");
        for (int idx = 0; idx < alienMissiles.size; idx++) {
            AlienMissile alienMissile = (AlienMissile) alienMissiles.gameObjects[idx];
            alienMissile.y += alienMissile.yVel;

            if (alienMissile.y - alienMissile.height / 2 > this.height) {
                queueGameObjectToRemove(alienMissile);
            } else {
                if (playerShip != null 
                        && GameObjectCollider.isIntersection(alienMissile, playerShip)) {
                    queueGameObjectToRemove(alienMissile);
                    playerShipDestroyed();
                }

                GameObjectCollection bases = getGameObjectCollection("Bases");
                for (int baseIdx = 0; baseIdx < bases.size; baseIdx++) {
                    Base base = (Base) bases.gameObjects[baseIdx];
                    if (GameObjectCollider.isIntersection(alienMissile, base)) {
                        if (base.erodeBase(alienMissile)) {
                            queueGameObjectToRemove(alienMissile);
                        }
                    }
                }
            }
        }
    }

    /**
     * Update the animation of any on-screen explosions
     */
    private void updateExplosions() {
        GameObjectCollection explosions = getGameObjectCollection("Explosions");
        for (int explosionIdx = 0; explosionIdx < explosions.size; explosionIdx++) {
            explosions.gameObjects[explosionIdx].getRealisation(0).update();
        }
    }

    /**
     * Update the player's score
     */
    private void updateScore() {
        ((Score) getGameObject("Score")).update();
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods: Update support                                               //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Add the specified amount to the player's score
     *
     * @param scoreToAdd integer score to add
     */
    private void addScore(int scoreToAdd) {
        Score score = (Score) getGameObject("Score");
        score.addScore(scoreToAdd);
    }

    /**
     * Carry out and consider the destruction of the player ship. In particular
     * the player ship is queued to be removed, an explosion effect is
     * introduced, the number of lives is decreased and an on-screen message
     * is shown.
     * <P>
     * Important: This method relies on the fact that this layer is an
     * observer of game object events. In this particular case, the added
     * splash message (either informing the player of the number of lives
     * remaining or that the game is over) will be caught by this observer
     * and appropriate follow-on action instigated.
     *
     * @see public void update( Observable observableObject, Object message )
     */
    private void playerShipDestroyed() {
        PlayerShip playerShip = (PlayerShip) getGameObject("PlayerShip");
        queueGameObjectToRemove(playerShip);

        for (int idx = 0; idx < 10; idx++) {
            queueGameObjectToAdd(new Explosion(this, 
                    playerShip.x - new Random().nextInt(50) + 25, 
                    playerShip.y - new Random().nextInt(100) + 50), "Explosions");
        }

        Lifes lifes = (Lifes) getGameObject("Lifes");
        lifes.decrementLifes();

        String splashMessageText;
        if (lifes.getNumberOfLifes() == 0) {
            splashMessageText = "Game over!";
        } else {
            splashMessageText = lifes.getNumberOfLifes() + " ship" 
                    + (lifes.getNumberOfLifes() > 1 ? "s" : "") + " remaining...";
        }

        SplashMessage splashMessage = new SplashMessage(splashMessageText, 0, 3000, this);
        splashMessage.addObserver(this);
        queueGameObjectToAdd(splashMessage);
    }

    /**
     * Carry out actions appropriate to the destruction of the complete
     * alien army.
     * <P>
     * Important: This method relies on the fact that this layer is an
     * observer of game object events. In this particular case, the added
     * splash message will be caught by this observer and appropriate
     * follow-on action instigated.
     *
     * @see public void update( Observable observableObject, Object message )
     */
    private void allAliensDestroyed() {
        SplashMessage splashMessage = new SplashMessage("Next level...", 5500, 2000, this);
        queueGameObjectToAdd(splashMessage);

        splashMessage = new SplashMessage("Next level...", 5500, 2000, this);
        splashMessage.addObserver(this);
        queueGameObjectToAdd(splashMessage);

        // Remove the player ship once all the aliens have been destroyed.
        // The reason for this is to avoid a situation where the player
        // destroys all ships but is shortly thereafter destroyed by one
        // of the remaining alien missiles.
        queueGameObjectToRemove(gameObjects.get("PlayerShip"));
    }

    /**
     * Once the 'game over', 'ship destroyed' or 'next level' messages
     * have disappeared then take appropriate (and corresponding) action.
     *
     * @param observableObject object this is being observed (splash message)
     * @param message String message from the observed object
     */
    @Override
    public void update(Observable observableObject, Object message) {
        if (((String) message).compareTo("SplashMessageTimeCompleted") == 0) {
            if (gameObjectCollections.get("AlienShips").size() == 0) {
                initialiseNextLevel();
            } else {
                Lifes lifes = (Lifes) this.gameObjects.get( "Lifes" );
                if (lifes.getNumberOfLifes() > 0) {
                    queueGameObjectToAdd(
                            new PlayerShip(this, this.width / 2, this.height - 15));
                } else {
                    // If the game is over, then ensure that the mothership alarm
                    // does not continue to play. Admittedly this is an issue that
                    // if a layer is set to inactive and invisible any looping
                    // sound clips will continue to play.
                    assetManager.retrieveSoundAssetArchetype("MothershipSfx").stop();

                    gameEngine.getGameLayer("TitleLayer").
                            setState(GameLayer.GameLayerVisibility.VISIBLE, 
                                GameLayer.GameLayerActivity.ACTIVE);
                    this.setState(GameLayer.GameLayerVisibility.INVISIBLE, 
                                GameLayer.GameLayerActivity.INACTIVE);
                }
            }
        }
    }

    /**
     * Initialise the next level, upping the base and max fire likelihoods,
     * resetting the number of lives, reforming the base, and adding in a
     * player ship and alien army.
     */
    private void initialiseNextLevel() {
        ALIEN_ARMY_BASE_FIRE_LIKELIHOOD /= 2;
        if (ALIEN_ARMY_BASE_FIRE_LIKELIHOOD < 1)
            ALIEN_ARMY_BASE_FIRE_LIKELIHOOD = 1;

        ALIEN_ARMY_MAX_FIRE_LIKELIHOOD /= 2;
        if (ALIEN_ARMY_MAX_FIRE_LIKELIHOOD < 1)
            ALIEN_ARMY_MAX_FIRE_LIKELIHOOD = 1;
        
        Lifes lifes = (Lifes) getGameObject("Lifes");
        lifes.resetNumberOfLifes();

        queueGameObjectToAdd(new PlayerShip(this, width / 2, height - 15));

        GameObjectCollection bases = getGameObjectCollection("Bases");
        for (int idx = 0; idx < bases.size; idx++) {
            ((Base) (bases.gameObjects[idx])).reformBase();
        }
        
        for (int widthIdx = 0; widthIdx < ALIEN_ARMY_WIDTH; widthIdx++) {
            for (int heightIdx = 0; heightIdx < ALIEN_ARMY_HEIGHT; heightIdx++) {
                AlienShip alienShip = new AlienShip(
                        this, heightIdx * 2 < ALIEN_ARMY_HEIGHT ? 0 : 1, 0, 0);
                alienShip.x = widthIdx * (alienShip.width + 15) + 50;
                alienShip.y = heightIdx * (alienShip.height + 5) + 100;
                queueGameObjectToAdd(alienShip, "AlienShips");
            }
        }
    }
    
    /**
     * Draw the space invaders layer by clearing the screen to black and then
     * calling the inherited draw method that will draw all game objects
     * added to this layer
     */
    @Override
    public void draw(Graphics2D graphics2D) {
        Color originalColour = graphics2D.getColor();
        graphics2D.setColor(Color.BLACK);
        graphics2D.fillRect(0, 0, (int)width, (int)height);
        graphics2D.setColor(originalColour);

        super.draw(graphics2D);
    }    
}