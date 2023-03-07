/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package tutorials.helloWorld;

import game.assets.*;
import game.engine.*;
/**
 *
 * @author DG
 */
public class HelloWorld extends GameEngine
{
    HelloWorld()
    {
        gameStart( 1024, 768, 32 );
    }

    public boolean buildAssetManager()
    {
        assetManager.addImageAsset("HelloWorldAsset",getClass().getResource("images/HelloWorld.png"));
        return true;
    }
    protected boolean buildInitialGameLayers()
    {
        HelloWorldLayer helloWorldLayer = new HelloWorldLayer(this);
        addGameLayer(helloWorldLayer);
        return true;
    }
    public static void main(String[] args)
    {
        HelloWorld instance = new HelloWorld();
    }
}



