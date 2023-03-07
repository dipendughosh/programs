package spaceInvaders;

import game.engine.GameEngine;
import game.engine.GameLayer;
import java.awt.*;
import java.awt.event.KeyEvent;

/**
 * Space invaders game. Once created this object will run a variant of
 * the classic space invaders game using FSEM
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2006/08 $
 *
 * @see GameEngine
 */
public class SpaceInvaders extends GameEngine {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /***
     * Define the default screen width and height the game will run at
     */
    private static final int SCREEN_WIDTH = 1024;
    private static final int SCREEN_HEIGHT = 768;


    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create and start new game of space invaders
     */
    public SpaceInvaders() {
        // Start the game engine
        gameStart(SCREEN_WIDTH, SCREEN_HEIGHT, 32);
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Attempt to load all the graphical and sound assets required by the game.
     * Loaded assets are added to the game engine's asset manager.
     *
     * @return boolean true if all assets could be loaded, otherwise false
     */    
    @Override
    public boolean buildAssetManager() {
        // If the assets were to be retrieved in a manner that was likely
        // to take more than a couple of seconds, it would be necessary
        // to ensure that this step informs the user of load progress.
        
        // Load in graphical assets                  //
        assetManager.loadAssetsFromFile(
                this.getClass().getResource("images/ImageAssets.txt"));

        // Sound assets                              //
        assetManager.loadAssetsFromFile(
                this.getClass().getResource("sounds/SoundAssets.txt"));

        return true;
    }

    /**
     * Construct an TitleLayer provided the player with information on the game
     */ 
    @Override
    protected boolean buildInitialGameLayers() {
        // Create, add and make visible/active a title layer introducing
        // the game to the user
        TitleLayer titleLayer = new TitleLayer(this, SCREEN_WIDTH, SCREEN_HEIGHT);
        titleLayer.setState(
                GameLayer.GameLayerVisibility.VISIBLE, GameLayer.GameLayerActivity.ACTIVE);
        this.addGameLayer(titleLayer);

        return true;
    }    
    
    /**
     * Define a global input event manager to handle game wide input events
     */
    @Override
    protected void considerInput() {
        // Invoke the default game engine consider input handler
        super.considerInput();

        // Toggle the pausing of the invaders game update (if running)
        if (this.inputEvent.keyTyped(KeyEvent.VK_P) 
                && this.gameLayers.containsKey("InvadersLayer")) {
            GameLayer invadersLayer = this.gameLayers.get("InvadersLayer");
            if (invadersLayer.getVisibility() == GameLayer.GameLayerVisibility.VISIBLE) {
                if (invadersLayer.getActivity() == GameLayer.GameLayerActivity.ACTIVE) {
                    invadersLayer.setActivity(GameLayer.GameLayerActivity.INACTIVE);
                } else {
                    invadersLayer.setActivity(GameLayer.GameLayerActivity.ACTIVE);
                }
            }
        }
    }

    public static void main(String[] args) {
        // Force OpenGL rendering - i.e. it may not be enabled if started
        // from the JAR. Currently (Sept 2007) under Vista Java needs to use
        // the OpenGL bindings to get any speed - the default D3D is very slow
        System.setProperty("sun.java2d.opengl", "true");             
        
        SpaceInvaders instance = new SpaceInvaders();
    }
}
