package happyFace;

import game.engine.*;
import java.awt.*;

/**
 * HappyFaceBuilder is a basic level editor intended to be used
 * to create HappyFace level geomtry. The editor provides a number
 * of tools for creating the level alongside graphical
 * assets. 
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class HappyFaceBuilder extends GameEngine {

    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a HappyFaceBuilder instance.
     * <P>
     * By default the current screen resolution is used to run the game.
     */
    public HappyFaceBuilder() {
        DisplayMode currentDisplayMode = GraphicsEnvironment.
                getLocalGraphicsEnvironment().getDefaultScreenDevice().
                    getDisplayMode();

        gameStart(currentDisplayMode.getWidth(), currentDisplayMode.getHeight(), 
                currentDisplayMode.getBitDepth());
        

        // When zoomed out within the editor the draw rate can be heavily
        // impacted (especially if developing a large level). To ensure
        // responsive reaction under such conditions the update to render 
        // rate is set high.
        this.MAX_NUM_UPDATES_WITHOUT_RENDER = 10;
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new HappyFaceBuilder instance
     */
    public static void main(String[] args) {
        HappyFaceBuilder instance = new HappyFaceBuilder();
    }
        
    /**
     * Load in graphical and sounds assets needed by the loader screen 
     * alongside core assets used widely within the editor
     */ 
    @Override
    protected boolean buildAssetManager() {
        assetManager.loadAssetsFromFile(
                this.getClass().getResource("images/CommonAssets.txt"));
        
        assetManager.loadAssetsFromFile(
                this.getClass().getResource("images/BuilderMenuAssets.txt"));

        return true;
    }

    /**
     * Construct a HappyFaceBuilderMenuLayer instance and add it to the game engine
     */ 
    @Override    
    protected boolean buildInitialGameLayers() {
        HappyFaceBuilderMenuLayer builderMenuLayer 
                = new HappyFaceBuilderMenuLayer(this);
        addGameLayer(builderMenuLayer);

        return true;
    }    

    /**
     * Render the game (game statistics are always shown)
     */
    @Override
    protected void gameRender(Graphics2D graphics2D) {
        super.gameRender(graphics2D);

        this.gameStatisticsRecorder.drawStatistics(graphics2D, 0, 0);
    }
}
