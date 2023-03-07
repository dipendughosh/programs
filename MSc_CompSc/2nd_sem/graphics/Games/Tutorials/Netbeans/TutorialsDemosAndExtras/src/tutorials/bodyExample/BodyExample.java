/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package tutorials.bodyExample;

import java.awt.*;
import game.assets.*;
import game.engine.*;

/**
 *
 * @author DG
 */
public class BodyExample extends GameEngine
{
    public BodyExample()
    {
        DisplayMode currentDisplayMode = GraphicsEnvironment.getLocalGraphicsEnvironment().getDefaultScreenDevice().getDisplayMode();
        gameStart(currentDisplayMode.getWidth(),currentDisplayMode.getHeight(),currentDisplayMode.getBitDepth());
    }
    public boolean buildAssetManager()
    {
        //assetManager.loadAssetsFromFile(getClass().getResource("images/Tutorial2Assets.txt"));
        assetManager.addImageAsset("Planet",getClass().getResource("images/Planet.png"));
        assetManager.addImageAsset("Spaceship",getClass().getResource("images/Spaceship.png"));
        return true;
    }    
    protected boolean buildInitialGameLayers()
    {
        BodyExampleLayer bodyExampleLayer = new BodyExampleLayer(this);
        addGameLayer(bodyExampleLayer);
        return true;
    }
    public static void main(String[] args)
    {
        BodyExample instance = new BodyExample();
    }
}
