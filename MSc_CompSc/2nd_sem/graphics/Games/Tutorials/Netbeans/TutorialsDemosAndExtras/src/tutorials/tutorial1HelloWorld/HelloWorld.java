package tutorials.tutorial1HelloWorld;

import game.engine.*;

public class HelloWorld extends GameEngine {
    
    public HelloWorld() {
        gameStart(1024, 768, 32);
    }
    
    protected boolean buildAssetManager() {
        assetManager.addImageAsset("HelloWorldAsset",
                getClass().getResource("images/HelloWorld.png"));
        
        return true;
    }
    
    protected boolean buildInitialGameLayers() {
        HelloWorldLayer helloWorldLayer = new HelloWorldLayer(this);
        addGameLayer(helloWorldLayer);
        
        return true;
    }
    
    public static void main(String[] args) {
        HelloWorld instance = new HelloWorld();
    }
}
