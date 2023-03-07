package happyFace;

import game.engine.*;
import game.components.*;
import game.assets.*;
import java.awt.Graphics2D;
import java.awt.Color;
import java.awt.Rectangle;
import java.awt.DisplayMode;
import java.awt.event.*;
import java.util.*;


/**
 * HappyFaceBuilderMenuLayer provides a simple loader layer for the 
 * HappyFace builder which display startup progression alongside a 
 * menu permitting screen resolution change.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class HappyFaceBuilderMenuLayer extends GameLayer {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Boolean flags specifying if the users wish to display the resolution
     * menu or start loading the builder assets
     */
    private boolean builderSelectResolution = false;
    private boolean builderStartTriggered = false;

    /**
     * Value keeping track of the load progress
     */
    private int builderStartStep = 0;

    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Construct a new happy face builder menu layer
     */
    public HappyFaceBuilderMenuLayer(GameEngine gameEngine) {
        super("BuilderMenuLayer", gameEngine, 
                gameEngine.screenWidth, gameEngine.screenHeight);

        // Create game object collections for holding the menu buttons
        // and also the available resolution text elements
        addGameObjectCollection("BuilderMenuButtons");
        addGameObjectCollection("AvailableScreenResolutions");

        gameEngine.setMouseCursor("MouseCrosshair", 15, 15);

        buildBuilderMenu();
    }

    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Construct the builder menu
     */
    private void buildBuilderMenu() {
        // Add in the background graphic
        GameObject builderTitle = new GameObject(
                this, gameEngine.screenWidth / 2, gameEngine.screenHeight / 2, 0);
        builderTitle.setRealisation( "BuilderHappyfaceTitle" );
        builderTitle.setName("BuilderTitle");
        addGameObject(builderTitle);

        // Add in the three menu buttons
        
        Button startBuilder = new Button(this, "StartBuilder", "BuilderStart", 
                "BuilderStartMouseover", "BuilderStartClicked", null, null, 
                gameEngine.screenWidth / 2, gameEngine.screenHeight / 2 + 150, 1);
        addGameObject(startBuilder, "BuilderMenuButtons");

        Button exitBuilder = new Button(this, "ExitBuilder", "BuilderExit", 
                "BuilderExitMouseover", "BuilderExitClicked", null, null, 
                gameEngine.screenWidth / 2, gameEngine.screenHeight / 2 + 225, 1);
        addGameObject(exitBuilder, "BuilderMenuButtons");

        Button builderResolution = new Button(this, "BuilderResolution", "BuilderResolution", 
                "BuilderResolutionMouseover", "BuilderResolutionClicked", null, null, 
                gameEngine.screenWidth / 2, gameEngine.screenHeight / 2 + 300, 1);
        addGameObject(builderResolution, "BuilderMenuButtons");
    }

    /**
     * Load the builder assets or test for button interaction
     */
    @Override
    public void update() {
        super.update();

        if (builderStartTriggered) {
            // Load in more assets and update the load progress
            startBuilder();
        } else {
            // Update each button
            GameObjectCollection buttons = getGameObjectCollection("BuilderMenuButtons");
            for (int idx = 0; idx < buttons.size; idx++) {
                buttons.gameObjects[idx].update();
            }
            
            // Exit the builder if requested
            Button exitBuilder = (Button) getGameObject( "ExitBuilder" );
            if (exitBuilder.buttonClicked()) {
                gameEngine.terminateProcess();
            }
            
            // Start loading in assets if requested
            Button startBuilder = (Button) getGameObject( "StartBuilder" );
            if (startBuilder.buttonClicked()) {
                triggerBuilderStart();
            }
            
            // Toggle the display of the builder resolution menu if requested
            Button selectResolution = (Button) getGameObject( "BuilderResolution" );
            if (selectResolution.buttonClicked()) {
                toggleSelectResolution();
            }
            
            // Consider interaction with the resolution menu
            if (builderSelectResolution) {
                considerSelectResolution();
            }
        }
    }

    /**
     * Toggle the construction and removal of the resolution menu that displays
     * available screen resolutions which the builder can be run at
     */
    private void toggleSelectResolution() {
        if (builderSelectResolution == false) {
            builderSelectResolution = true;

            // Create a text element to be used to build buttons for each resolution
            TextElement resolutionText = new game.components.TextElement(this, 
                    (ImageAssetSequence) assetManager.retrieveAsset( "GUIFont" ), 
                    0, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" + 
                    "1234567890`!\"*$%^&*()-+={}[];:'@#~,.<>/\\?           ", "");

            // Create the menu background
            GameObject triggerBackground = new GameObject(this, 
                    gameEngine.screenWidth / 2 + 390, gameEngine.screenHeight / 2 + 150, 3);
            triggerBackground.setName("TriggerBackground");
            triggerBackground.setRealisation("BuilderResolutionBackground");
            addGameObject(triggerBackground);

            // Retrieve each available resolution and create an associated button
            int offsetY = 0;
            DisplayMode[] displayModes = gameEngine.getAvailableDisplayModes();
            for (int idx = 0; idx < displayModes.length; idx++) {
                if (displayModes[idx].getWidth() >= 1024 
                        && displayModes[idx].getHeight() >= 768 
                        && displayModes[idx].getBitDepth() == 32) {

                    String resolutionName = "" + displayModes[idx].getWidth() 
                            + "x" + displayModes[idx].getHeight();

                    if (getGameObject(resolutionName) != null)
                        continue;
                    
                    TextElement resolution = 
                            resolutionText.getMatchingElement(resolutionName);
                    resolution.setName(resolutionName);
                    resolution.setPosition(gameEngine.screenWidth / 2 + 395, 
                            gameEngine.screenHeight / 2 - 70 + offsetY);
                    resolution.setDrawOrder(4);
                    addGameObject(resolution, "AvailableScreenResolutions");

                    offsetY += 40;
                }
            }
        } else {
            builderSelectResolution = false;

            // Remove the menu background
            queueGameObjectToRemove(getGameObject("TriggerBackground"));

            // Remove each resolution toggle button
            GameObjectCollection resolutions 
                    = getGameObjectCollection("AvailableScreenResolutions");
            for (int idx = 0; idx < resolutions.size; idx++) {
                queueGameObjectToRemove(resolutions.gameObjects[idx]);
            }
        }
    }

    /**
     * Consider a change of screen resolution
     */
    private void considerSelectResolution() {
        // Check to see if the mouse has been clicked
        if (inputEvent.mouseClicked(MouseEvent.BUTTON1)) {
            int[] clickLocation = inputEvent.getMouseClickLocation();

            // Test the mouse click against each resolution button
            GameObjectCollection resolutions 
                    = getGameObjectCollection("AvailableScreenResolutions");
            for (int idx = 0; idx < resolutions.size; idx++) {
                Rectangle screenBound = getGameObjectScreenRectangle(
                        resolutions.gameObjects[idx]);
                if (screenBound.x < clickLocation[0] 
                        && screenBound.y < clickLocation[1] 
                        && screenBound.x + screenBound.width > clickLocation[0] 
                        && screenBound.y + screenBound.height > clickLocation[1]) {

                    // If the click falls onto a button, then get the button
                    // name and extract the screen width and height and change
                    // resolution
                    StringTokenizer tokenizer = new StringTokenizer(
                            resolutions.gameObjects[idx].getName(), " x");
                    int screenWidth = Integer.parseInt(tokenizer.nextToken());
                    int screenHeight = Integer.parseInt(tokenizer.nextToken());
                    gameEngine.changeDisplayMode(screenWidth, screenHeight, 32);

                    // Remove the screen resolution menu
                    toggleSelectResolution();

                    // Reposition the various graphical eleemnts
                    GameObject builderTitle = getGameObject("BuilderTitle");
                    builderTitle.setPosition(screenWidth / 2, screenHeight / 2);
                    
                    GameObject startBuilder = getGameObject("StartBuilder");
                    startBuilder.setPosition(screenWidth / 2, screenHeight / 2 + 150);
                    
                    GameObject exitBuilder = getGameObject("ExitBuilder");
                    exitBuilder.setPosition(screenWidth / 2, screenHeight / 2 + 225);

                    GameObject builderResolution = getGameObject("BuilderResolution");
                    builderResolution.setPosition(screenWidth / 2, screenHeight / 2 + 300);
                }
            }
        }
    }

    /**
     * If the builder load start has just been triggered then remove the buttons
     * and display a progress bar and a text element for displaying load info
     */
    private void triggerBuilderStart() {
        builderStartTriggered = true;

        queueGameObjectToRemove(getGameObject("StartBuilder"));
        queueGameObjectToRemove(getGameObject("ExitBuilder"));
        queueGameObjectToRemove(getGameObject("BuilderResolution"));

        Bar progressBar = new Bar(this, "BuilderStartProgressBar", null, "BuilderProgressbar", 7, 
                gameEngine.screenWidth / 2, gameEngine.screenHeight / 2 + 250, 2);
        progressBar.setPoints(0);
        addGameObject(progressBar);

        TextElement progressText = new game.components.TextElement(this, 
                (ImageAssetSequence) assetManager.retrieveAsset( "GUIFontLarge" ), 0, 
                "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" + 
                "1234567890`!\"*$%^&*()-+={}[];:'@#~,.<>/\\?           ", "", 
                gameEngine.screenWidth / 2 - 430, gameEngine.screenHeight / 2 + 250, 3);
        progressText.setName("BuilderProgressText");
        progressText.setAlignment(TextElement.Alignment.Right);
        addGameObject(progressText);
    }

    /**
     * Continue the load process - a block of assets is loaded each update with
     * the progress bar updated to display progress
     */
    private void startBuilder() {
        Bar progressBar = (Bar) getGameObject( "BuilderStartProgressBar" );
        TextElement progressText = (TextElement) getGameObject( "BuilderProgressText" );

        // Load in the next block of assets and update the load progress
        switch (builderStartStep) {
            case 0:
                break;
            case 1:
                progressText.setText("Loading game assets");
                assetManager.loadAssetsFromFile(
                        this.getClass().getResource("images/GameAssets.txt"));
                break;
            case 2:
                progressText.setText("Loading block assets");
                assetManager.loadAssetsFromFile(
                        this.getClass().getResource("images/BlockAssets.txt"));
                break;
            case 3:
                progressText.setText("Loading emoticon assets");
                assetManager.loadAssetsFromFile(
                        this.getClass().getResource("images/EmoticonAssets.txt"));
                break;
            case 4:
                progressText.setText("Loading builder assets");
                assetManager.loadAssetsFromFile(
                        this.getClass().getResource("images/BuilderAssets.txt"));
                break;
            case 5:
                progressText.setText("Loading interactive assets");
                assetManager.loadAssetsFromFile(
                        this.getClass().getResource("images/InteractionAssets.txt"));
                break;
            case 6:
                progressText.setText("Loading decorative assets");
                assetManager.loadAssetsFromFile(
                        this.getClass().getResource("images/DecorativeAssets.txt"));
                break;
            case 7:
                progressText.setText("Loading icon assets");
                assetManager.loadAssetsFromFile(
                        this.getClass().getResource("images/BuilderIcons.txt"));
                break;
            case 8:
                progressText.setText("Loading sound assets");
                assetManager.loadAssetsFromFile(
                        this.getClass().getResource("sounds/SoundAssets.txt"));
                break;
            case 9:
                // Now that all assets have been loaded, create a new level layer
                // to be used to test developed levels and a builder layer 
                // within which to build levels. 
                HappyFaceLevelLayer levelLayer = new HappyFaceLevelLayer(gameEngine);
                levelLayer.setVisibility(GameLayerVisibility.INVISIBLE);
                levelLayer.setActivity(GameLayerActivity.INACTIVE);
                gameEngine.addGameLayer(levelLayer);

                HappyFaceBuilderLayer builderLayer 
                        = new HappyFaceBuilderLayer("BuilderLayer", gameEngine);
                builderLayer.setDrawOrder(0);
                gameEngine.addGameLayer(builderLayer);

                // Remove this game layer
                this.setVisibility(GameLayerVisibility.INVISIBLE);
                this.setActivity(GameLayerActivity.INACTIVE);
                break;
        }

        // Update the graphical elements and tell the game engine not to 
        // skip the next render (i.e. the load from disk is likely to take
        // long that the period of a single update tick).
        if (builderStartStep <= 7)
            progressBar.setPoints(builderStartStep);
        progressBar.update();
        gameEngine.doNotSkipNextRender();
        builderStartStep++;
    }

    /**
     * Draw graphical components and if necessary highlight any screen
     * resolution button mouseovers
     */    
    @Override
    public void draw(Graphics2D graphics2D) {
        Color originalColour = graphics2D.getColor();
        graphics2D.setColor(Color.LIGHT_GRAY);
        graphics2D.fillRect(0, 0, gameEngine.screenWidth, gameEngine.screenHeight);
        graphics2D.setColor(originalColour);

        super.draw(graphics2D);

        if (builderSelectResolution) {
            GameObjectCollection resolutions 
                    = getGameObjectCollection("AvailableScreenResolutions");
            for (int idx = 0; idx < resolutions.size; idx++) {
                Rectangle screenBound 
                        = getGameObjectScreenRectangle(resolutions.gameObjects[idx]);
                if (screenBound.x < inputEvent.mouseXCoordinate 
                        && screenBound.y < inputEvent.mouseYCoordinate 
                        && screenBound.x + screenBound.width > inputEvent.mouseXCoordinate 
                        && screenBound.y + screenBound.height > inputEvent.mouseYCoordinate) {
                    originalColour = graphics2D.getColor();
                    graphics2D.setColor(new Color(0, 0, 255, 50));
                    graphics2D.fillRect(screenBound.x, screenBound.y, 
                            screenBound.width, screenBound.height);
                    graphics2D.setColor(originalColour);
                }
            }
        }
    }
}