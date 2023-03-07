package ZoMA;

import game.engine.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.io.*;
import java.net.*;

/**
 * ZoMA (Zen of Mouse Aiming) is a simple game that tests the player's
 * mouse aiming and reaction skills. A total of four tests are provided
 * that measure reaction times, snap shot accuracy, sniper shot accuracy
 * and mouse tracking accuracy. Statistics are maintained for the 
 * averages across all recorded tests for a player profile.
 * <P>
 * Note: Time permitting there is a lot that could be added to ZoMA...
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.0 $ $Date: 2007/08 $
 */

public class ZoMA extends GameEngine {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Collection of ZoMA player profiles 
     */
    private ProfileCollection profileCollection;

    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new ZoMA instance. 
     * <P>
     * Note: if a profile collection cannot be found, then create a new profile
     * collecction.
     * <P>
     * By default the current screen resolution is used to run the game. The
     * game assumes that this will be at least a resolution of 1280x1024 (the
     * game will run at lower resolution, but with image scaling and a warning
     * message appearing).
     */ 
    public ZoMA() {
        DisplayMode currentDisplayMode 
                = GraphicsEnvironment.getLocalGraphicsEnvironment().
                    getDefaultScreenDevice().getDisplayMode();

        try {
            // Attempt to load the profile collection
            ObjectInputStream inputStream = new ObjectInputStream( 
                    new FileInputStream( "Profiles.dat" ) );
            profileCollection = (ProfileCollection) inputStream.readObject();
            inputStream.close();
                        
            // Each profile records the screen dimension (in order to work out
            // the region of a mouse click)
            for (int idx = 0; idx < profileCollection.getNumProfiles(); idx++) {
                profileCollection.getProfile(idx).setScreenDimensions(
                        currentDisplayMode.getWidth(), currentDisplayMode.getHeight());
            }
        } catch (IOException e) {
            // If the profile collection cannot be loaded then create a new collection
            System.out.println("ZoMA: Cannot load \"Profiles.dat\" Creating new profile file.");
            profileCollection = new ProfileCollection();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

        this.gameStart(currentDisplayMode.getWidth(), 
                currentDisplayMode.getHeight(), currentDisplayMode.getBitDepth());
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new ZoMA instance
     */ 
    public static void main(String[] args) {
        // Force OpenGL rendering - i.e. it may not be enabled if started
        // from the JAR. Currently (Sept 2007) under Vista Java needs to use
        // the OpenGL bindings to get any speed - the default D3D is very slow
        System.setProperty("sun.java2d.opengl", "true");

        ZoMA instance = new ZoMA();
    }
    
    /**
     * Load in graphical and sounds assets needed by ZoMA
     */ 
    @Override
    protected boolean buildAssetManager() {
        assetManager.loadAssetsFromFile(
                this.getClass().getResource("images/ZoMACoreAssets.txt"));
        return true;
    }

    /**
     * Construct a ZoMAMenuLayer instance and add it to the game engine
     */ 
    @Override
    protected boolean buildInitialGameLayers() {
        ZoMAMenuLayer zoMAMenuLayer = new ZoMAMenuLayer(this, profileCollection);
        addGameLayer(zoMAMenuLayer);
        return true;
    }
    
    /**
     * Define global input event processing
     */ 
    @Override
    protected void considerInput() {
        // If a test is running and the ESCAPE key is pressed, then return
        // to the main menu, otherwise exit the game
        if (inputEvent.keyTyped(KeyEvent.VK_ESCAPE)) {
            if (gameLayers.containsKey("ZoMAGameLayer")) {
                GameLayer zomaMenu = getGameLayer("ZoMAMenuLayer");
                zomaMenu.setActivity(GameLayer.GameLayerActivity.ACTIVE);
                zomaMenu.setVisibility(GameLayer.GameLayerVisibility.VISIBLE);
                removeGameLayer("ZoMAGameLayer");
            } else {
                this.running = false;
            }
        }

        // Invoke the default game engine consider input handler
        super.considerInput();
    }

    /**
     * Define game shot down actions
     */ 
    @Override
    protected void gameShutdownActions() {
        super.gameShutdownActions();

        // Save the ZoMA player profiles on game exit
        try {
            ObjectOutputStream outputStream = new ObjectOutputStream(
                    new FileOutputStream("Profiles.dat" ) );            
            outputStream.writeObject(profileCollection);
            outputStream.close();
        } catch (IOException e) {
            System.out.println("ZoMA: Cannot write \"Profiles.dat\"");
        }
    }
}