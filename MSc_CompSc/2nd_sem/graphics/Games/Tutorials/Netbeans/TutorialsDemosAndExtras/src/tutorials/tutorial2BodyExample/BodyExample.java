package tutorials.tutorial2BodyExample;

import game.engine.*;
import java.awt.*;

public class BodyExample extends GameEngine {
    
    public BodyExample() {
        DisplayMode currentDisplayMode =
                GraphicsEnvironment.getLocalGraphicsEnvironment().
                getDefaultScreenDevice().getDisplayMode();
        
        gameStart(currentDisplayMode.getWidth(),
                currentDisplayMode.getHeight(), currentDisplayMode.getBitDepth());
    }
    
    public boolean buildAssetManager() {
        assetManager.loadAssetsFromFile(
                getClass().getResource("images/Tutorial2Assets.txt"));
        
        return true;
    }
    
    protected boolean buildInitialGameLayers() {
        BodyExampleLayer bodyExampleLayer = new BodyExampleLayer(this);
        addGameLayer(bodyExampleLayer);
        
        return true;
    }
    
    public static void main(String[] args) {
        BodyExample instance = new BodyExample();
    }
}
