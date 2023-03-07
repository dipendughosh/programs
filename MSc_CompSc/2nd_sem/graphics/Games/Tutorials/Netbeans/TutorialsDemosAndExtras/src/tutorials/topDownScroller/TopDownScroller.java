package tutorials.topDownScroller;

import game.engine.GameEngine;

import java.awt.*;
import java.awt.event.KeyEvent;

/**
 * Example top down scroller.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 *
 * @see GameEngine
 */
public class TopDownScroller extends GameEngine {
    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /***
     * Define the default screen width and height the game will run at
     */
    private static final int SCREEN_WIDTH = 1024;
    private static final int SCREEN_HEIGHT = 768;
    
    private boolean displayHelpOverlay = false;
    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create and start new instance of space box
     */
    public TopDownScroller() {
        this.gameStart( SCREEN_WIDTH, SCREEN_HEIGHT, 32 );
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
    public boolean buildAssetManager() {
        assetManager.loadAssetsFromFile(
                this.getClass().getResource("images/TopDownScrollerAssets.txt"));
        return true;
    }
        
    /**
     * Build initial game layers
     */
    @Override
    protected boolean buildInitialGameLayers() {
        TopDownScollerLayer spaceLayer = new TopDownScollerLayer( this );
        addGameLayer( spaceLayer );
        
        return true;
    }
    
    /**
     * Define a global input event manager to handle game wide input events
     */
    @Override
    protected void considerInput() {
        // Invoke the default game engine consider input handler
        super.considerInput();
        
        // Toggle the display of the help overlay
        if( this.inputEvent.keyTyped(KeyEvent.VK_H) )
            this.displayHelpOverlay = !this.displayHelpOverlay;
    }
    
    /**
     * Extend the default game render to include a game statistics report and/or
     * help overlay if requested
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
        graphics2D.setColor( Color.YELLOW );
        
        // Display game exit information
        graphics2D.drawString( "ESC - Quit : H - help", 10, 10 );
        
        if( this.displayHelpOverlay == true ) {
            graphics2D.drawString( "Right Arrow - Move right", 10, 30 );
            graphics2D.drawString( "Left Arrow - Move left", 10, 45 );
            graphics2D.drawString( "Up Arrow - Move forward", 10, 60 );
            graphics2D.drawString( "Down Arrow - Move backwards", 10, 75 );
            graphics2D.drawString( "Space - Fire", 10, 90 );
        }
    }
    
        
    public static void main(String[] args) {
        TopDownScroller instance = new TopDownScroller();
    }    
}