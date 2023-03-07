package happyFace;

import game.engine.*;
import java.awt.*;

/**
 * HappyFace is a platform game revolving around the rescue of
 * 'unhappy' emoticons for their overly happy captors. One
 * strong aspect of the gameplay rests upon the ability to
 * destroy and break defined level geometry. A number of example
 * levels are provided.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class HappyFace extends GameEngine {

    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a HappyFace instance.
     * <P>
     * By default the current screen resolution is used to run the game.
     */
    public HappyFace() {
        DisplayMode currentDisplayMode = GraphicsEnvironment.
                getLocalGraphicsEnvironment().getDefaultScreenDevice().
                    getDisplayMode();

        gameStart(currentDisplayMode.getWidth(), currentDisplayMode.getHeight(), 
                currentDisplayMode.getBitDepth());
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new HappyFace instance
     */
    public static void main(String[] args) {
        // Force OpenGL rendering - i.e. it may not be enabled if started
        // from the JAR. Currently (Sept 2007) under Vista Java needs to use
        // the OpenGL bindings to get any speed - the default D3D is very slow
        System.setProperty("sun.java2d.opengl", "true");        
          
        HappyFace instance = new HappyFace();
    }

    /**
     * Load in graphical and sounds assets needed by the loader screen
     */ 
    @Override
    protected boolean buildAssetManager() {
        assetManager.loadAssetsFromFile(
                this.getClass().getResource("images/LoaderAssets.txt"));

        return true;
    }

    /**
     * Construct a HappyFaceLoaderLayer instance and add it to the game engine
     */ 
    @Override
    protected boolean buildInitialGameLayers() {
        HappyFaceLoaderLayer happyFaceLoaderLayer = new HappyFaceLoaderLayer(this);
        addGameLayer(happyFaceLoaderLayer);

        return true;
    }
}
