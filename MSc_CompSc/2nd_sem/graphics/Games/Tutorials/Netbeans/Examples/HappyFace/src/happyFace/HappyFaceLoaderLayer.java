package happyFace;

import game.engine.*;
import game.components.*;
import java.awt.Graphics2D;
import java.awt.Color;

/**
 * HappyFaceLoaderLayer provides a simple loader screen for the happy
 * face game, providing a progress bar that is updated as the game is
 * loaded
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.0 $ $Date: 2007/08 $
 */

public class HappyFaceLoaderLayer extends GameLayer {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Integer used to track the load progress
     */
    private int loaderProgress = 0;


    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Build a new happy face loader
     */
    public HappyFaceLoaderLayer(GameEngine gameEngine) {
        super("BuilderMenuLayer", 
                gameEngine, gameEngine.screenWidth, gameEngine.screenHeight);

        buildLoaderMenu();
    }

   
    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////
     
    /**
     * Add a loading background title and create a progress bar to report
     * the load progress
     */
    private void buildLoaderMenu() {
        GameObject loaderTitle = new GameObject(
                this, gameEngine.screenWidth / 2, gameEngine.screenHeight / 2, 0);
        loaderTitle.setRealisation(
                assetManager.retrieveGraphicalAsset("HappyFaceLoaderBackground"));
        addGameObject(loaderTitle);

        Bar progressBar = new Bar( this, "HappyFaceLoaderProgressBar", 
                "LoadProgressBarBorder", "LoadProgressBarInner", 6, 
                gameEngine.screenWidth / 2 + 140, gameEngine.screenHeight / 2 + 310, 2);
        progressBar.setPoints(0);
        progressBar.setInnerAssetOffset(-6.0, -8.0);
        addGameObject(progressBar);
    }

    /**
     * Update the loader - loading in more assets, updating the progress bar
     * and, once the load is completed, creating a main menu layer
     */
    @Override
    public void update() {
        super.update();

        switch (loaderProgress) {
            case 0:
                break;
            case 1:
                assetManager.loadAssetsFromFile(
                        this.getClass().getResource("images/CommonAssets.txt"));
                break;
            case 2:
                assetManager.loadAssetsFromFile(
                        this.getClass().getResource("images/GameAssets.txt"));
                break;
            case 3:
                assetManager.loadAssetsFromFile(
                        this.getClass().getResource("images/EmoticonAssets.txt"));
                break;
            case 4:
                assetManager.loadAssetsFromFile(
                        this.getClass().getResource("images/InteractionAssets.txt"));
                break;
            case 5:
                assetManager.loadAssetsFromFile(
                        this.getClass().getResource("images/DecorativeAssets.txt"));
                break;
            case 6:
                assetManager.loadAssetsFromFile(
                        this.getClass().getResource("images/BlockAssets.txt"));
                break;
            case 7:
                assetManager.loadAssetsFromFile(
                        this.getClass().getResource("images/MenuAssets.txt"));
                break;
            case 8:
                assetManager.loadAssetsFromFile(
                        this.getClass().getResource("sounds/SoundAssets.txt"));
                break;
            case 9:
                HappyFaceMenuLayer happyFaceMenuLayer 
                        = new HappyFaceMenuLayer(gameEngine);
                gameEngine.addGameLayer(happyFaceMenuLayer);
                gameEngine.removeGameLayer(this.gameLayerName);
                break;
        }

        // Update the progress bar
        Bar progressBar = (Bar) getGameObject( "HappyFaceLoaderProgressBar" );
        if (loaderProgress <= 6) progressBar.setPoints(loaderProgress);
        progressBar.update();
        
        // Ensure the game engine does not skip the next frame
        gameEngine.doNotSkipNextRender();
        
        loaderProgress++;
    }

    /**
     * Display the loader
     */
    @Override
    public void draw(Graphics2D graphics2D) {        
        Color originalColour = graphics2D.getColor();
        graphics2D.setColor(new Color(200, 200, 0, 255));
        graphics2D.fillRect(0, 0, gameEngine.screenWidth, gameEngine.screenHeight);
        graphics2D.setColor(originalColour);

        super.draw(graphics2D);
    }
}