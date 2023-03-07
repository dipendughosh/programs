package tutorials.platformer;

import game.engine.*;

import java.awt.*;
import java.awt.event.KeyEvent;

/**
 * Example platform game
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class Platformer extends GameEngine {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /***
     * Define the default screen width and height the game will run at
     */
    private static final int SCREEN_WIDTH = 1024;
    private static final int SCREEN_HEIGHT = 768;
    
    /**
     * Flag determining if overlap help should be displayed on the screen
     * when the game is running.
     */
    private boolean displayHelpOverlay = false;
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    public Platformer() {
        gameStart( SCREEN_WIDTH, SCREEN_HEIGHT, 32 );
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
        assetManager.loadAssetsFromFile(
                getClass().getResource("images/PlatformerAssets.txt"));
        return true;
    }
    
    /**
     * Construct a platform layer instance and add it to the game engine
     */
    @Override
    protected boolean buildInitialGameLayers() {
        PlatformLayer platformLayer = new PlatformLayer( this );
        addGameLayer( platformLayer );

        return true;
    }
    
    /**
     * Define global input event processing
     */
    @Override
    protected void considerInput() {
        // Invoke the default game engine consider input handler
        super.considerInput();
        
        // Toggle the display of the help overlay
        if( inputEvent.keyTyped(KeyEvent.VK_H) )
            displayHelpOverlay = !displayHelpOverlay;
    }
    
    /**
     * Extend the default game render to include a help overlay if requested
     *
     * @param  graphics2D Graphics context on which to render the game
     */
    @Override
    protected void gameRender( Graphics2D graphics2D ) {
        Color originalColour = graphics2D.getColor();
        graphics2D.setColor( Color.black );
        graphics2D.fillRect( 0, 0, screenWidth, screenHeight );
        graphics2D.setColor( originalColour );
        
        // Call the game engine gameRender method to render all visible game layers
        super.gameRender( graphics2D );
        
        graphics2D.setFont( new Font( "MONOSPACED", Font.BOLD, 12 ) );
        graphics2D.setColor( Color.white );
        
        // Display game exit information
        graphics2D.drawString( "ESC - Quit : H - help", 10, 10 );
        
        if( displayHelpOverlay ) {
            graphics2D.drawString( "Right Arrow - Move right", 10, 30 );
            graphics2D.drawString( "Left Arrow - Move left", 10, 45 );
            graphics2D.drawString( "Up Arrow - Move up", 10, 60 );
            graphics2D.drawString( "Down Arrow - Move down", 10, 75 );
            graphics2D.drawString( "Space - Jump", 10, 90 );
            
            graphics2D.drawString( "1 - Spawn 1 Ball", 10, 120 );
            graphics2D.drawString( "2 - Spawn 10 Balls", 10, 135 );
            graphics2D.drawString( "3 - Spawn 100 Balls", 10, 150 );
        }
    }
    
    public static void main(String[] args) {
        Platformer instance = new Platformer();
    }    
}