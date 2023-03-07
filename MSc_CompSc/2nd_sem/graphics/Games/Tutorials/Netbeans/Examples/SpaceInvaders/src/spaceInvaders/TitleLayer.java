package spaceInvaders;

import game.assets.*;
import game.engine.*;

import java.awt.*;
import java.awt.event.KeyEvent;
import java.util.*;

/**
 * TitleLayer object holding the intro screen and presenting the user with 
 * information on how to play the game.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2006/08 $
 */
public class TitleLayer extends GameLayer
{
    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a suitable object to hold a number of DrawnAssetMessage graphical 
     * assets that will be used by this layer. This approach differs from 
     * the notion of assigning assets to objects and then rendering game objects.
     * The reason why an array list of drawn asset messages was used within this
     * layer is for the simple reason that it provided the more straightforward 
     * means of accomplishing what needed to be done - i.e. displaying various
     * items of textual information.
     */
    private ArrayList<DrawnAssetMessage> screenText; 
            

    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Create a new title layer
     *
     * @param  gameEngine GameEngine instance to which this layer will be added
     * @param  screenWidth target width of this layer 
     * @param  screenHeight target height of this layer 
     */                     
    public TitleLayer( GameEngine gameEngine, int screenWidth, int screenHeight )
    {
        super( "TitleLayer", gameEngine );        

        this.width = screenWidth;      
        this.height = screenHeight;

        // Get the assets to be used by this layer
        buildTitleAssets();
    }   

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Retrieve, build and store the assets used by this layer
     */                             
    private void buildTitleAssets()
    {
        // Add in the title background tile
        GameObject titleBackground = new GameObject(this, width/2, height/2, 0 );
        titleBackground.setName("TitleBackground");
        titleBackground.setRealisationAndGeometry("TiledInvaderBackground");
        addGameObject(titleBackground);        
        
        // Add the three graphical images that are used
        GameObject spaceInvadersScreenshot = new GameObject(this, 800, 240, 1 );
        spaceInvadersScreenshot.setRealisation("SpaceInvadersScreenshot");
        addGameObject(spaceInvadersScreenshot);        
                
        GameObject spaceInvadersArcadeMachine = new GameObject(this, 150, 635, 1 );
        spaceInvadersArcadeMachine.setRealisation("SpaceInvadersArcadeMachine");
        addGameObject(spaceInvadersArcadeMachine);          

        GameObject spaceInvadersTitle = new GameObject(this, 350, 240, 1 );
        spaceInvadersTitle.setRealisation("SpaceInvadersTitle");
        addGameObject(spaceInvadersTitle);      
        
        // Build up the various items of text that are displayed on the screen
        screenText = new ArrayList<DrawnAssetMessage>();        
        Font textFontHeader = new Font( "SANS_SERIF", Font.BOLD, 18 );
        Font textFontLarge = new Font( "SANS_SERIF", Font.BOLD, 40 );
        Font textFont = new Font( "SANS_SERIF", Font.BOLD, 16 );
        Color textColor = Color.white;

        DrawnAssetMessage text = new DrawnAssetMessage( "",
                "CSC217 Games Programming", textFontHeader, textColor );
        text.offsetX = 30; text.offsetY = 20; screenText.add( text );
        
        text = new DrawnAssetMessage( "", "Case Study", textFontHeader, textColor );
        text.offsetX = 900; text.offsetY = 20; screenText.add( text );

        text = new DrawnAssetMessage( "", "Philip Hanna", textFontHeader, textColor );
        text.offsetX = 900; text.offsetY = 740; screenText.add( text );

        text = new DrawnAssetMessage( "", "Controls:", textFontLarge, Color.RED, 2, Color.WHITE );
        text.offsetX = 240; text.offsetY = 525; screenText.add( text );
        
        text = new DrawnAssetMessage( "", "Move right:", textFont, textColor );
        text.offsetX = 250; text.offsetY = 580; screenText.add( text );

        text = new DrawnAssetMessage( "", "Right Arrow", textFont, textColor );
        text.offsetX = 380; text.offsetY = 580; screenText.add( text );
        
        text = new DrawnAssetMessage( "", "Move left:", textFont, textColor );
        text.offsetX = 250; text.offsetY = 605; screenText.add( text );

        text = new DrawnAssetMessage( "", "Left Arrow", textFont, textColor );
        text.offsetX = 380; text.offsetY = 605; screenText.add( text );

        text = new DrawnAssetMessage( "", "Fire:", textFont, textColor );
        text.offsetX = 250; text.offsetY = 630; screenText.add( text );

        text = new DrawnAssetMessage( "", "Spacebar", textFont, textColor );
        text.offsetX = 380; text.offsetY = 630; screenText.add( text );

        text = new DrawnAssetMessage( "", "Start game:", textFont, textColor );
        text.offsetX = 250; text.offsetY = 655; screenText.add( text );

        text = new DrawnAssetMessage( "", "S", textFont, textColor );
        text.offsetX = 380; text.offsetY = 655; screenText.add( text );

        text = new DrawnAssetMessage( "", "Pause game:", textFont, textColor );
        text.offsetX = 250; text.offsetY = 680; screenText.add( text );

        text = new DrawnAssetMessage( "", "P", textFont, textColor );
        text.offsetX = 380; text.offsetY = 680; screenText.add( text );
        
        text = new DrawnAssetMessage( "", "Game info:", textFont, textColor );
        text.offsetX = 250; text.offsetY = 705; screenText.add( text );

        text = new DrawnAssetMessage( "", "CTRL-I", textFont, textColor );
        text.offsetX = 380; text.offsetY = 705; screenText.add( text );

        text = new DrawnAssetMessage( "", "Exit game:", textFont, textColor );
        text.offsetX = 250; text.offsetY = 730; screenText.add( text );

        text = new DrawnAssetMessage( "", "Escape", textFont, textColor );
        text.offsetX = 380; text.offsetY = 730; screenText.add( text );
    }
        
    /**
     * Update the title layer
     */         
    @Override
    public void update()
    {
        ImageAssetTile tiledInvaderBackground 
                = (ImageAssetTile)getGameObject("TitleBackground").graphicalRealisation[0];
        
        // Give the background a wavy (sinusoidal) motion
        double radianTicker = Math.PI * (double)(gameEngine.updateCounter) / 180.0;
        tiledInvaderBackground.moveViewPortRight( (int)(8.0 * Math.sin(radianTicker) ) );
        tiledInvaderBackground.moveViewPortUp( 4 );

        // Determine if the users wishes to play space invaders
        if( this.gameEngine.inputEvent.keyTyped(KeyEvent.VK_S) )
        {
            if( this.gameEngine.gameLayers.containsKey( "InvadersLayer" ) == true )
                this.gameEngine.removeGameLayer( "InvadersLayer" );                
            
            InvadersLayer invadersLayer = new InvadersLayer( this.gameEngine );
            invadersLayer.setState( 
                    GameLayer.GameLayerVisibility.VISIBLE, GameLayer.GameLayerActivity.ACTIVE );
            this.gameEngine.addGameLayer( invadersLayer );

            this.setState( 
                    GameLayer.GameLayerVisibility.INVISIBLE, GameLayer.GameLayerActivity.INACTIVE );            
        }
    }
    
    /**
     * Draw the title layer
     *
     * @param  graphics2D Graphics2D context to which to render
     */                                     
    @Override
    public void draw( Graphics2D graphics2D )
    {
        if( gameLayerVisibility == GameLayerVisibility.INVISIBLE )
            return;

        // Call the draw super constructor to draw all added graphical objects
        super.draw(graphics2D);

        // Draw each created message
        for( DrawnAssetMessage text : screenText )
            text.draw( graphics2D, (int)text.offsetX, (int)text.offsetY );
    }        
}