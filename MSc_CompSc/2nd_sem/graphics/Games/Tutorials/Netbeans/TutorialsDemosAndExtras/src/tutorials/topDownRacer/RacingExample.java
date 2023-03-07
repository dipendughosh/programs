package tutorials.topDownRacer;

import game.engine.*;

/**
 * Racing car example
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class RacingExample extends GameEngine {

    private static final int SCREEN_WIDTH = 1024;
    private static final int SCREEN_HEIGHT = 768;
    
    public RacingExample() {
        gameStart( SCREEN_WIDTH, SCREEN_HEIGHT, 32 );
    }
        
    @Override
    public boolean buildAssetManager() {
        assetManager.loadAssetsFromFile(
                this.getClass().getResource("images/RacingAssets.txt"));
        return true;
    }
    
    @Override
    protected boolean buildInitialGameLayers() {
        RacingExampleLayer racingLayer = new RacingExampleLayer( this );
        addGameLayer( racingLayer );
        
        return true;
    }
    
    public static void main(String[] args) {
        RacingExample instance = new RacingExample();
    }
}
